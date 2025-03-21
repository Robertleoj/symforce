# ----------------------------------------------------------------------------
# SymForce - Copyright 2022, Skydio, Inc.
# This source code is under the Apache 2.0 license found in the LICENSE file.
# ----------------------------------------------------------------------------

from __future__ import annotations

import dataclasses
import enum
import functools
import os
import textwrap
from pathlib import Path

import jinja2
import jinja2.ext

from symforce import logger
from symforce import typing as T
from symforce.codegen import format_util
from symforce.codegen.codegen_config import RenderTemplateConfig

CURRENT_DIR = Path(__file__).parent
LCM_TEMPLATE_DIR = CURRENT_DIR / "lcm_templates"
PYBIND_TEMPLATE_DIR = CURRENT_DIR / "pybind_templates"


class FileType(enum.Enum):
    CPP = enum.auto()
    PYTHON = enum.auto()
    PYTHON_INTERFACE = enum.auto()
    CUDA = enum.auto()
    LCM = enum.auto()
    MAKEFILE = enum.auto()
    TYPESCRIPT = enum.auto()
    TOML = enum.auto()
    RUST = enum.auto()

    @staticmethod
    def from_extension(extension: str) -> FileType:
        if extension in {"c", "cpp", "cxx", "cc", "tcc", "h", "hpp", "hxx", "hh"}:
            return FileType.CPP
        elif extension in {"cu", "cuh"}:
            return FileType.CUDA
        elif extension == "py":
            return FileType.PYTHON
        elif extension == "pyi":
            return FileType.PYTHON_INTERFACE
        elif extension == "lcm":
            return FileType.LCM
        elif extension == "Makefile":
            return FileType.MAKEFILE
        elif extension == "ts":
            return FileType.TYPESCRIPT
        elif extension == "toml":
            return FileType.TOML
        elif extension == "rs":
            return FileType.RUST
        else:
            raise ValueError(f"Could not get FileType from extension {extension}")

    @staticmethod
    def from_template_path(template_path: Path) -> FileType:
        parts = template_path.name.split(".")
        if parts[-1] != "jinja":
            raise ValueError(
                f"template must be of the form path/to/file.ext.jinja, got {template_path}"
            )
        return FileType.from_extension(parts[-2])

    def comment_prefix(self) -> str:
        """
        Return the comment prefix for this file type.
        """
        if self in {FileType.CPP, FileType.CUDA, FileType.LCM, FileType.RUST}:
            return "//"
        elif self in {FileType.PYTHON, FileType.PYTHON_INTERFACE, FileType.TOML}:
            return "#"
        else:
            raise NotImplementedError(f"Unknown comment prefix for {self}")

    def autoformat(
        self,
        file_contents: str,
        template_name: T.Openable,
        output_path: T.Optional[T.Openable] = None,
    ) -> str:
        """
        Format code of this file type.
        """
        # Come up with a fake filename to give to the formatter just for formatting purposes, even
        # if this isn't being written to disk
        if output_path is not None:
            format_filename = os.path.basename(output_path)
        else:
            format_filename = str(template_name).replace(".jinja", "")

        # TODO(hayk): Move up to language-specific config or printer. This is quite an awkward
        # place for auto-format logic, but I thought it was better centralized here than down below
        # hidden in a function. We might want to somehow pass the config through to render a
        # template so we can move things into the backend code. (tag=centralize-language-diffs)
        if self in {FileType.CPP, FileType.CUDA}:
            return format_util.format_cpp(
                file_contents, filename=str(CURRENT_DIR / format_filename)
            )
        elif self in {FileType.PYTHON, FileType.PYTHON_INTERFACE}:
            return format_util.format_py(file_contents, filename=str(CURRENT_DIR / format_filename))
        elif self == FileType.LCM:
            return file_contents
        elif self == FileType.RUST:
            return format_util.format_rust(
                file_contents, filename=str(CURRENT_DIR / format_filename)
            )
        else:
            raise NotImplementedError(f"Unknown autoformatter for {self}")


class RelEnvironment(jinja2.Environment):
    """
    Override ``join_path()`` to enable relative template paths. Modified from the below post.

    https://stackoverflow.com/questions/8512677/how-to-include-a-template-with-relative-path-in-jinja2
    """

    @staticmethod
    def join_path(template: T.Union[jinja2.Template, str], parent: str) -> str:
        return os.path.normpath(os.path.join(os.path.dirname(parent), str(template)))


def add_preamble(source: str, name: Path, comment_prefix: str, custom_preamble: str) -> str:
    dashes = "-" * 77
    preamble = (
        custom_preamble
        + textwrap.dedent(
            f"""
            {comment_prefix} {dashes}
            {comment_prefix} This file was autogenerated by symforce from template:
            {comment_prefix}     {name}
            {comment_prefix} Do NOT modify by hand.
            {comment_prefix} {dashes}

            """
        ).lstrip()
    )

    return preamble + source


@functools.lru_cache
def jinja_env(
    template_dir: T.Openable, search_paths: T.Tuple[T.Openable, ...] = ()
) -> RelEnvironment:
    """
    Helper function to cache the Jinja environment, which enables caching of loaded templates
    """
    all_search_paths = [os.fspath(template_dir)]
    all_search_paths.extend((os.fspath(p) for p in search_paths))
    loader = jinja2.FileSystemLoader(searchpath=all_search_paths)
    env = RelEnvironment(
        loader=loader,
        trim_blocks=True,
        lstrip_blocks=True,
        keep_trailing_newline=True,
        undefined=jinja2.StrictUndefined,
    )
    return env


def render_template(
    template_path: T.Openable,
    data: T.Dict[str, T.Any],
    config: RenderTemplateConfig,
    *,
    template_dir: T.Openable,
    output_path: T.Optional[T.Openable] = None,
    search_paths: T.Iterable[T.Openable] = (),
) -> str:
    """
    Boilerplate to render template. Returns the rendered string and optionally writes to file.

    Args:
        template_path: file path of the template to render
        data: dictionary of inputs for template
        config: configuration options for template rendering (see  RenderTemplateConfig for more
                information)
        template_dir: Base directory where templates are found
        output_path: If provided, writes to file
        search_paths: Additional directories jinja should search when resolving imports
    """
    if not isinstance(template_path, Path):
        template_path = Path(template_path)

    if not isinstance(template_dir, Path):
        template_dir = Path(template_dir)

    logger.debug(f"Template  IN <-- {template_dir / template_path}")
    if output_path:
        logger.debug(f"Template OUT --> {output_path}")

    filetype = FileType.from_template_path(Path(template_path))

    template = jinja_env(template_dir, search_paths=tuple(search_paths)).get_template(
        os.fspath(template_path)
    )
    rendered_str = add_preamble(
        str(template.render(**data)),
        template_path,
        comment_prefix=filetype.comment_prefix(),
        custom_preamble=config.custom_preamble,
    )

    if config.autoformat:
        rendered_str = filetype.autoformat(
            file_contents=rendered_str,
            template_name=template_path,
            output_path=output_path,
        )

    if output_path:
        output_path = Path(output_path)
        output_path.parent.mkdir(exist_ok=True, parents=True)
        output_path.write_text(rendered_str)

    return rendered_str


class TemplateList:
    """
    Helper class to keep a list of (template_path, data, config, template_dir, output_path)
    and render all templates in one go.
    """

    @dataclasses.dataclass
    class TemplateListEntry:
        template_path: T.Openable
        data: T.Dict[str, T.Any]
        config: RenderTemplateConfig
        template_dir: T.Openable
        output_path: T.Optional[T.Openable]

    def __init__(self, template_dir: T.Optional[T.Openable] = None) -> None:
        self.items: T.List = []
        self.common_template_dir = template_dir

    def add(
        self,
        template_path: T.Openable,
        data: T.Dict[str, T.Any],
        config: RenderTemplateConfig,
        *,
        template_dir: T.Optional[T.Openable] = None,
        output_path: T.Optional[T.Openable] = None,
    ) -> None:
        if template_dir is None:
            if self.common_template_dir is None:
                raise ValueError(
                    "Argument template_dir must be supplied if the TemplateList was not initialized with a template_dir"
                )
            template_dir = self.common_template_dir

        self.items.append(
            self.TemplateListEntry(
                template_path=template_path,
                data=data,
                config=config,
                template_dir=template_dir,
                output_path=output_path,
            )
        )

    def render(self, search_paths: T.Iterable[T.Openable] = ()) -> T.List[str]:
        rendered_templates = []
        for entry in self.items:
            rendered_templates.append(
                render_template(
                    template_path=entry.template_path,
                    data=entry.data,
                    config=entry.config,
                    template_dir=entry.template_dir,
                    output_path=entry.output_path,
                    search_paths=search_paths,
                )
            )
        return rendered_templates
