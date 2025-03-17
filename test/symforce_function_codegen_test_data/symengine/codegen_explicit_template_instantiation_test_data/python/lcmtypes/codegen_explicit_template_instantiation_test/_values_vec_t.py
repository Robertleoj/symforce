# This file automatically generated by skymarshal
# DO NOT MODIFY BY HAND
# fmt: off
# isort: off
# mypy: disallow-untyped-defs

import copy
import typing as T  # pylint: disable=unused-import

from io import BytesIO
import struct
from lcmtypes.eigen_lcm._Vector4d import Vector4d

class values_vec_t(object):
    __slots__: T.List[str] = ["x", "y", "rot", "rot_vec", "scalar_vec", "list_of_lists"]

    def __init__(
        self,
        x: float=0.0,
        y: float=0.0,
        rot: T.Optional[Vector4d]=None,
        rot_vec: T.Optional[T.List[Vector4d]]=None,
        scalar_vec: T.Optional[T.List[float]]=None,
        list_of_lists: T.Optional[T.List[T.List[Vector4d]]]=None,
        _skip_initialize: bool=False,
    ) -> None:
        """ If _skip_initialize is True, all other constructor arguments are ignored """
        if _skip_initialize:
            return
        self.x: float = x
        self.y: float = y
        self.rot: Vector4d = Vector4d._default() if rot is None else rot
        self.rot_vec: T.List[Vector4d] = [ Vector4d._default() for dim0 in range(3) ] if rot_vec is None else rot_vec
        self.scalar_vec: T.List[float] = [ 0.0 for dim0 in range(3) ] if scalar_vec is None else scalar_vec
        self.list_of_lists: T.List[T.List[Vector4d]] = [ [ Vector4d._default() for dim1 in range(3) ] for dim0 in range(3) ] if list_of_lists is None else list_of_lists

    @staticmethod
    def from_all_fields(
        x: float,
        y: float,
        rot: Vector4d,
        rot_vec: T.List[Vector4d],
        scalar_vec: T.List[float],
        list_of_lists: T.List[T.List[Vector4d]],
    ) -> "values_vec_t":
        return values_vec_t(
            x=x,
            y=y,
            rot=rot,
            rot_vec=rot_vec,
            scalar_vec=scalar_vec,
            list_of_lists=list_of_lists,
        )

    @staticmethod
    def _skytype_meta() -> T.Dict[str, str]:
        return dict(
            type="struct",
            package="codegen_explicit_template_instantiation_test",
            name="values_vec_t",
        )

    @classmethod
    def _default(cls) -> "values_vec_t":
        return cls()

    def __repr__(self) -> str:
        return "values_vec_t({})".format(
            ", ".join("{}={}".format(name, repr(getattr(self, name))) for name in self.__slots__))

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, values_vec_t):
            return NotImplemented
        return (
            (self.x==other.x) and
            (self.y==other.y) and
            (self.rot==other.rot) and
            (self.rot_vec==other.rot_vec) and
            (self.scalar_vec==other.scalar_vec) and
            (self.list_of_lists==other.list_of_lists)
        )
    # Disallow hashing for python struct lcmtypes.
    __hash__ = None  # type: ignore[assignment]

    def encode(self) -> bytes:
        buf = BytesIO()
        buf.write(values_vec_t._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf: T.BinaryIO) -> None:
        buf.write(values_vec_t._CACHED_STRUCT_0.pack(self.x, self.y))
        if hasattr(self.rot, '_get_packed_fingerprint'):
            assert self.rot._get_packed_fingerprint() == Vector4d._get_packed_fingerprint()
        else:
            assert self.rot._get_hash_recursive([]) == Vector4d._get_hash_recursive([])
        self.rot._encode_one(buf)
        for i0 in range(3):
            if hasattr(self.rot_vec[i0], '_get_packed_fingerprint'):
                assert self.rot_vec[i0]._get_packed_fingerprint() == Vector4d._get_packed_fingerprint()
            else:
                assert self.rot_vec[i0]._get_hash_recursive([]) == Vector4d._get_hash_recursive([])
            self.rot_vec[i0]._encode_one(buf)
        buf.write(values_vec_t._CACHED_STRUCT_1.pack(*self.scalar_vec[:3]))
        for i0 in range(3):
            for i1 in range(3):
                if hasattr(self.list_of_lists[i0][i1], '_get_packed_fingerprint'):
                    assert self.list_of_lists[i0][i1]._get_packed_fingerprint() == Vector4d._get_packed_fingerprint()
                else:
                    assert self.list_of_lists[i0][i1]._get_hash_recursive([]) == Vector4d._get_hash_recursive([])
                self.list_of_lists[i0][i1]._encode_one(buf)

    @staticmethod
    def decode(data: T.Union[bytes, T.BinaryIO]) -> "values_vec_t":
        # NOTE(eric): This function can technically accept either a BinaryIO or
        # anything that supports the C++ Buffer Protocol,
        # which is unspecifiable in type hints.

        if hasattr(data, "read"):
            # NOTE(eric): mypy isn't able to figure out the hasattr check
            buf = T.cast(T.BinaryIO, data)
        else:
            buf = BytesIO(T.cast(bytes, data))

        if buf.read(8) != values_vec_t._get_packed_fingerprint():
            raise ValueError("Decode error")
        return values_vec_t._decode_one(buf)

    @staticmethod
    def _decode_one(buf: T.BinaryIO) -> "values_vec_t":
        self = values_vec_t(_skip_initialize=True)
        self.x, self.y = values_vec_t._CACHED_STRUCT_0.unpack(buf.read(16))
        self.rot = Vector4d._decode_one(buf)
        self.rot_vec = []
        for i0 in range(3):
            self.rot_vec.append(Vector4d._decode_one(buf))
        self.scalar_vec = list(values_vec_t._CACHED_STRUCT_1.unpack(buf.read(24)))
        self.list_of_lists = []
        for i0 in range(3):
            self.list_of_lists.append ([])
            for i1 in range(3):
                self.list_of_lists[i0].append(Vector4d._decode_one(buf))
        return self

    @staticmethod
    def _get_hash_recursive(parents: T.List[T.Type]) -> int:
        if values_vec_t in parents: return 0
        newparents = parents + [values_vec_t]
        tmphash = (0xe7b60b55c8cf5417+ Vector4d._get_hash_recursive(newparents)+ Vector4d._get_hash_recursive(newparents)+ Vector4d._get_hash_recursive(newparents)) & 0xffffffffffffffff
        tmphash = (((tmphash<<1)&0xffffffffffffffff)  + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash

    _packed_fingerprint: T.Optional[bytes] = None

    @staticmethod
    def _get_packed_fingerprint() -> bytes:
        if values_vec_t._packed_fingerprint is None:
            values_vec_t._packed_fingerprint = struct.pack(">Q", values_vec_t._get_hash_recursive([]))
        return values_vec_t._packed_fingerprint

    def deepcopy(self, **kwargs: T.Any) -> "values_vec_t":
        """
        Deep copy of this LCM type

        Returns a copy w/ members specified by kwargs replaced with new values specified by kwargs.
        """
        result = copy.deepcopy(self)
        for key in kwargs:
            if not hasattr(result, key):
                raise KeyError("Type values_vec_t does not have attribute: " + str(key))
            setattr(result, key, kwargs[key])
        return result

    _CACHED_STRUCT_0 = struct.Struct(">dd")
    _CACHED_STRUCT_1 = struct.Struct(">3d")
