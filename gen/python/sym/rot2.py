# -----------------------------------------------------------------------------
# This file was autogenerated by symforce from template:
#     geo_package/CLASS.py.jinja
# Do NOT modify by hand.
# -----------------------------------------------------------------------------

import math
import typing as T

import numpy

# isort: split
from .ops import rot2 as ops


class Rot2(object):
    """
    Autogenerated Python implementation of <class 'symforce.geo.rot2.Rot2'>.

    Group of two-dimensional orthogonal matrices with determinant +1, representing rotations
    in 2D space. Backed by a complex number.
    """

    __slots__ = ["data"]

    def __repr__(self):
        # type: () -> str
        return "<{} {}>".format(self.__class__.__name__, self.data)

    # --------------------------------------------------------------------------
    # Handwritten methods included from "custom_methods/rot2.py.jinja"
    # --------------------------------------------------------------------------

    def __init__(self, z=None):
        # type: (T.Union[T.Sequence[float], numpy.ndarray]) -> None
        if z is None:
            self.data = ops.GroupOps.identity().data  # type: T.List[float]
        else:
            if isinstance(z, numpy.ndarray):
                if z.shape in [(2, 1), (1, 2)]:
                    z = z.flatten()
                elif z.shape != (2,):
                    raise IndexError(
                        "Expected z to be a vector of length 2; instead had shape {}".format(
                            z.shape
                        )
                    )
            elif len(z) != 2:
                raise IndexError(
                    "Expected z to be a sequence of length 2, was instead length {}.".format(len(z))
                )
            self.data = list(z)

    # --------------------------------------------------------------------------
    # Custom generated methods
    # --------------------------------------------------------------------------

    def compose_with_point(self, right):
        # type: (Rot2, numpy.ndarray) -> numpy.ndarray
        """
        Left-multiplication. Either rotation concatenation or point transform.
        """

        # Total ops: 6

        # Input arrays
        _self = self.data
        if right.shape == (2,):
            right = right.reshape((2, 1))
        elif right.shape != (2, 1):
            raise IndexError(
                "right is expected to have shape (2, 1) or (2,); instead had shape {}".format(
                    right.shape
                )
            )

        # Intermediate terms (0)

        # Output terms
        _res = numpy.zeros(2)
        _res[0] = _self[0] * right[0, 0] - _self[1] * right[1, 0]
        _res[1] = _self[0] * right[1, 0] + _self[1] * right[0, 0]
        return _res

    @staticmethod
    def from_angle(theta):
        # type: (float) -> Rot2
        """
        Create a Rot2 from an angle `theta` in radians

        This is equivalent to from_tangent([theta])
        """

        # Total ops: 2

        # Input arrays

        # Intermediate terms (0)

        # Output terms
        _res = [0.0] * 2
        _res[0] = math.cos(theta)
        _res[1] = math.sin(theta)
        return Rot2.from_storage(_res)

    def to_rotation_matrix(self):
        # type: (Rot2) -> numpy.ndarray
        """
        A matrix representation of this element in the Euclidean space that contains it.
        """

        # Total ops: 1

        # Input arrays
        _self = self.data

        # Intermediate terms (0)

        # Output terms
        _res = numpy.zeros((2, 2))
        _res[0, 0] = _self[0]
        _res[1, 0] = _self[1]
        _res[0, 1] = -_self[1]
        _res[1, 1] = _self[0]
        return _res

    # --------------------------------------------------------------------------
    # StorageOps concept
    # --------------------------------------------------------------------------

    @staticmethod
    def storage_dim():
        # type: () -> int
        return 2

    def to_storage(self):
        # type: () -> T.List[float]
        return list(self.data)

    @classmethod
    def from_storage(cls, vec):
        # type: (T.Sequence[float]) -> Rot2
        instance = cls.__new__(cls)

        if isinstance(vec, list):
            instance.data = vec
        else:
            instance.data = list(vec)

        if len(vec) != cls.storage_dim():
            raise ValueError(
                "{} has storage dim {}, got {}.".format(cls.__name__, cls.storage_dim(), len(vec))
            )

        return instance

    # --------------------------------------------------------------------------
    # GroupOps concept
    # --------------------------------------------------------------------------

    @classmethod
    def identity(cls):
        # type: () -> Rot2
        return ops.GroupOps.identity()

    def inverse(self):
        # type: () -> Rot2
        return ops.GroupOps.inverse(self)

    def compose(self, b):
        # type: (Rot2) -> Rot2
        return ops.GroupOps.compose(self, b)

    def between(self, b):
        # type: (Rot2) -> Rot2
        return ops.GroupOps.between(self, b)

    # --------------------------------------------------------------------------
    # LieGroupOps concept
    # --------------------------------------------------------------------------

    @staticmethod
    def tangent_dim():
        # type: () -> int
        return 1

    @classmethod
    def from_tangent(cls, vec, epsilon=1e-8):
        # type: (numpy.ndarray, float) -> Rot2
        if len(vec) != cls.tangent_dim():
            raise ValueError(
                "Vector dimension ({}) not equal to tangent space dimension ({}).".format(
                    len(vec), cls.tangent_dim()
                )
            )
        return ops.LieGroupOps.from_tangent(vec, epsilon)

    def to_tangent(self, epsilon=1e-8):
        # type: (float) -> numpy.ndarray
        return ops.LieGroupOps.to_tangent(self, epsilon)

    def retract(self, vec, epsilon=1e-8):
        # type: (numpy.ndarray, float) -> Rot2
        if len(vec) != self.tangent_dim():
            raise ValueError(
                "Vector dimension ({}) not equal to tangent space dimension ({}).".format(
                    len(vec), self.tangent_dim()
                )
            )
        return ops.LieGroupOps.retract(self, vec, epsilon)

    def local_coordinates(self, b, epsilon=1e-8):
        # type: (Rot2, float) -> numpy.ndarray
        return ops.LieGroupOps.local_coordinates(self, b, epsilon)

    def interpolate(self, b, alpha, epsilon=1e-8):
        # type: (Rot2, float, float) -> Rot2
        return ops.LieGroupOps.interpolate(self, b, alpha, epsilon)

    # --------------------------------------------------------------------------
    # General Helpers
    # --------------------------------------------------------------------------
    def __eq__(self, other):
        # type: (T.Any) -> bool
        if isinstance(other, Rot2):
            return self.data == other.data
        else:
            return False

    @T.overload
    def __mul__(self, other):  # pragma: no cover
        # type: (Rot2) -> Rot2
        pass

    @T.overload
    def __mul__(self, other):  # pragma: no cover
        # type: (numpy.ndarray) -> numpy.ndarray
        pass

    def __mul__(self, other):
        # type: (T.Union[Rot2, numpy.ndarray]) -> T.Union[Rot2, numpy.ndarray]
        if isinstance(other, Rot2):
            return self.compose(other)
        elif isinstance(other, numpy.ndarray) and hasattr(self, "compose_with_point"):
            return getattr(self, "compose_with_point")(other).reshape(other.shape)
        else:
            raise NotImplementedError("Cannot compose {} with {}.".format(type(self), type(other)))
