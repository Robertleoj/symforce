# -----------------------------------------------------------------------------
# This file was autogenerated by symforce from template:
#     geo_package/CLASS.py.jinja
# Do NOT modify by hand.
# -----------------------------------------------------------------------------

import math
import random
import typing as T

import numpy

from .rot3 import Rot3

# isort: split
from .ops import pose3 as ops


class Pose3(object):
    """
    Autogenerated Python implementation of :py:class:`symforce.geo.pose3.Pose3`.

    Group of three-dimensional rigid body transformations - SO(3) x R3.

    The storage is a quaternion (x, y, z, w) for rotation followed by position (x, y, z).

    The tangent space is 3 elements for rotation followed by 3 elements for translation in the
    non-rotated frame.

    For Lie group enthusiasts: This class is on the PRODUCT manifold.  On this class, the group
    operations (e.g. compose and between) operate as you'd expect for a Pose or SE(3), but the
    manifold operations (e.g. retract and local_coordinates) operate on the product manifold
    SO(3) x R3.  This means that:

    - retract(a, vec) != compose(a, from_tangent(vec))

    - local_coordinates(a, b) != to_tangent(between(a, b))

    - There is no hat operator, because from_tangent/to_tangent is not the matrix exp/log

    If you need a type that has these properties in symbolic expressions, you should use
    :class:`symforce.geo.unsupported.pose3_se3.Pose3_SE3`. There is no runtime equivalent of
    :class:`Pose3_SE3 <symforce.geo.unsupported.pose3_se3.Pose3_SE3>`, see the docstring on that
    class for more information.
    """

    __slots__ = ["data"]

    def __repr__(self):
        # type: () -> str
        return "<{} {}>".format(self.__class__.__name__, self.data)

    # --------------------------------------------------------------------------
    # Handwritten methods included from "custom_methods/pose3.py.jinja"
    # --------------------------------------------------------------------------

    def __init__(self, R=None, t=None):
        # type: (T.Optional[Rot3], T.Union[T.Sequence[float], numpy.ndarray, None]) -> None
        rotation = R if R is not None else Rot3()
        if t is None:
            t = [0.0, 0.0, 0.0]
        if isinstance(t, numpy.ndarray):
            if t.shape in [(3, 1), (1, 3)]:
                t = t.flatten()
            elif t.shape != (3,):
                raise IndexError(
                    "Expected t to be a vector of length 3; instead had shape {}".format(t.shape)
                )
        elif len(t) != 3:
            raise IndexError(
                "Expected t to be a sequence of length 3, was instead length {}.".format(len(t))
            )
        if not isinstance(rotation, Rot3):
            raise ValueError("arg R has type {}; type {} expected".format(type(R), Rot3))

        self.data = rotation.to_storage() + list(t)

    @property
    def R(self):
        # type: () -> Rot3
        """
        Accessor for the rotation component, equivalent to self.rotation()
        """
        return self.rotation()

    @property
    def t(self):
        # type: () -> numpy.ndarray
        """
        Accessor for the position component, equivalent to self.position()
        """
        return self.position()

    def rotation(self):
        # type: () -> Rot3
        return Rot3.from_storage(list(self.rotation_storage()))

    # --------------------------------------------------------------------------
    # Custom generated methods
    # --------------------------------------------------------------------------

    def rotation_storage(self):
        # type: (Pose3) -> numpy.ndarray
        """
        Returns the rotational component of this pose.
        """

        # Total ops: 0

        # Input arrays
        _self = self.data

        # Intermediate terms (0)

        # Output terms
        _res = numpy.zeros(4)
        _res[0] = _self[0]
        _res[1] = _self[1]
        _res[2] = _self[2]
        _res[3] = _self[3]
        return _res

    def position(self):
        # type: (Pose3) -> numpy.ndarray
        """
        Returns the positional component of this pose.
        """

        # Total ops: 0

        # Input arrays
        _self = self.data

        # Intermediate terms (0)

        # Output terms
        _res = numpy.zeros(3)
        _res[0] = _self[4]
        _res[1] = _self[5]
        _res[2] = _self[6]
        return _res

    def compose_with_point(self, right):
        # type: (Pose3, numpy.ndarray) -> numpy.ndarray
        """
        Left-multiply with a compatible quantity.
        """

        # Total ops: 46

        # Input arrays
        _self = self.data
        if right.shape == (3,):
            right = right.reshape((3, 1))
        elif right.shape != (3, 1):
            raise IndexError(
                "right is expected to have shape (3, 1) or (3,); instead had shape {}".format(
                    right.shape
                )
            )

        # Intermediate terms (11)
        _tmp0 = 2 * _self[2] * _self[3]
        _tmp1 = 2 * _self[1]
        _tmp2 = _self[0] * _tmp1
        _tmp3 = -2 * _self[1] ** 2
        _tmp4 = 1 - 2 * _self[2] ** 2
        _tmp5 = 2 * _self[0]
        _tmp6 = _self[2] * _tmp5
        _tmp7 = _self[3] * _tmp1
        _tmp8 = -2 * _self[0] ** 2
        _tmp9 = _self[3] * _tmp5
        _tmp10 = _self[2] * _tmp1

        # Output terms
        _res = numpy.zeros(3)
        _res[0] = (
            _self[4]
            + right[0, 0] * (_tmp3 + _tmp4)
            + right[1, 0] * (-_tmp0 + _tmp2)
            + right[2, 0] * (_tmp6 + _tmp7)
        )
        _res[1] = (
            _self[5]
            + right[0, 0] * (_tmp0 + _tmp2)
            + right[1, 0] * (_tmp4 + _tmp8)
            + right[2, 0] * (_tmp10 - _tmp9)
        )
        _res[2] = (
            _self[6]
            + right[0, 0] * (_tmp6 - _tmp7)
            + right[1, 0] * (_tmp10 + _tmp9)
            + right[2, 0] * (_tmp3 + _tmp8 + 1)
        )
        return _res

    def inverse_compose(self, point):
        # type: (Pose3, numpy.ndarray) -> numpy.ndarray
        """
        Returns ``self.inverse() * point``

        This is more efficient than calling the generated inverse and compose methods separately, if
        doing this for one point.
        """

        # Total ops: 61

        # Input arrays
        _self = self.data
        if point.shape == (3,):
            point = point.reshape((3, 1))
        elif point.shape != (3, 1):
            raise IndexError(
                "point is expected to have shape (3, 1) or (3,); instead had shape {}".format(
                    point.shape
                )
            )

        # Intermediate terms (20)
        _tmp0 = -2 * _self[1] ** 2
        _tmp1 = 1 - 2 * _self[2] ** 2
        _tmp2 = _tmp0 + _tmp1
        _tmp3 = 2 * _self[2]
        _tmp4 = _self[0] * _tmp3
        _tmp5 = 2 * _self[3]
        _tmp6 = _self[1] * _tmp5
        _tmp7 = _tmp4 - _tmp6
        _tmp8 = _self[3] * _tmp3
        _tmp9 = 2 * _self[0] * _self[1]
        _tmp10 = _tmp8 + _tmp9
        _tmp11 = -2 * _self[0] ** 2
        _tmp12 = _tmp1 + _tmp11
        _tmp13 = _self[0] * _tmp5
        _tmp14 = _self[1] * _tmp3
        _tmp15 = _tmp13 + _tmp14
        _tmp16 = -_tmp8 + _tmp9
        _tmp17 = _tmp0 + _tmp11 + 1
        _tmp18 = _tmp4 + _tmp6
        _tmp19 = -_tmp13 + _tmp14

        # Output terms
        _res = numpy.zeros(3)
        _res[0] = (
            -_self[4] * _tmp2
            - _self[5] * _tmp10
            - _self[6] * _tmp7
            + _tmp10 * point[1, 0]
            + _tmp2 * point[0, 0]
            + _tmp7 * point[2, 0]
        )
        _res[1] = (
            -_self[4] * _tmp16
            - _self[5] * _tmp12
            - _self[6] * _tmp15
            + _tmp12 * point[1, 0]
            + _tmp15 * point[2, 0]
            + _tmp16 * point[0, 0]
        )
        _res[2] = (
            -_self[4] * _tmp18
            - _self[5] * _tmp19
            - _self[6] * _tmp17
            + _tmp17 * point[2, 0]
            + _tmp18 * point[0, 0]
            + _tmp19 * point[1, 0]
        )
        return _res

    def to_homogenous_matrix(self):
        # type: (Pose3) -> numpy.ndarray
        """
        4x4 matrix representing this pose transform.
        """

        # Total ops: 28

        # Input arrays
        _self = self.data

        # Intermediate terms (11)
        _tmp0 = -2 * _self[1] ** 2
        _tmp1 = 1 - 2 * _self[2] ** 2
        _tmp2 = 2 * _self[2] * _self[3]
        _tmp3 = 2 * _self[1]
        _tmp4 = _self[0] * _tmp3
        _tmp5 = 2 * _self[0]
        _tmp6 = _self[2] * _tmp5
        _tmp7 = _self[3] * _tmp3
        _tmp8 = -2 * _self[0] ** 2
        _tmp9 = _self[3] * _tmp5
        _tmp10 = _self[2] * _tmp3

        # Output terms
        _res = numpy.zeros((4, 4))
        _res[0, 0] = _tmp0 + _tmp1
        _res[1, 0] = _tmp2 + _tmp4
        _res[2, 0] = _tmp6 - _tmp7
        _res[3, 0] = 0
        _res[0, 1] = -_tmp2 + _tmp4
        _res[1, 1] = _tmp1 + _tmp8
        _res[2, 1] = _tmp10 + _tmp9
        _res[3, 1] = 0
        _res[0, 2] = _tmp6 + _tmp7
        _res[1, 2] = _tmp10 - _tmp9
        _res[2, 2] = _tmp0 + _tmp8 + 1
        _res[3, 2] = 0
        _res[0, 3] = _self[4]
        _res[1, 3] = _self[5]
        _res[2, 3] = _self[6]
        _res[3, 3] = 1
        return _res

    # --------------------------------------------------------------------------
    # StorageOps concept
    # --------------------------------------------------------------------------

    @staticmethod
    def storage_dim():
        # type: () -> int
        return 7

    def to_storage(self):
        # type: () -> T.List[float]
        return list(self.data)

    @classmethod
    def from_storage(cls, vec):
        # type: (T.Sequence[float]) -> Pose3
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
        # type: () -> Pose3
        return ops.GroupOps.identity()

    def inverse(self):
        # type: () -> Pose3
        return ops.GroupOps.inverse(self)

    def compose(self, b):
        # type: (Pose3) -> Pose3
        return ops.GroupOps.compose(self, b)

    def between(self, b):
        # type: (Pose3) -> Pose3
        return ops.GroupOps.between(self, b)

    # --------------------------------------------------------------------------
    # LieGroupOps concept
    # --------------------------------------------------------------------------

    @staticmethod
    def tangent_dim():
        # type: () -> int
        return 6

    @classmethod
    def from_tangent(cls, vec, epsilon=1e-8):
        # type: (numpy.ndarray, float) -> Pose3
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
        # type: (numpy.ndarray, float) -> Pose3
        if len(vec) != self.tangent_dim():
            raise ValueError(
                "Vector dimension ({}) not equal to tangent space dimension ({}).".format(
                    len(vec), self.tangent_dim()
                )
            )
        return ops.LieGroupOps.retract(self, vec, epsilon)

    def local_coordinates(self, b, epsilon=1e-8):
        # type: (Pose3, float) -> numpy.ndarray
        return ops.LieGroupOps.local_coordinates(self, b, epsilon)

    def interpolate(self, b, alpha, epsilon=1e-8):
        # type: (Pose3, float, float) -> Pose3
        return ops.LieGroupOps.interpolate(self, b, alpha, epsilon)

    # --------------------------------------------------------------------------
    # General Helpers
    # --------------------------------------------------------------------------
    def __eq__(self, other):
        # type: (T.Any) -> bool
        if isinstance(other, Pose3):
            return self.data == other.data
        else:
            return False

    @T.overload
    def __mul__(self, other):  # pragma: no cover
        # type: (Pose3) -> Pose3
        pass

    @T.overload
    def __mul__(self, other):  # pragma: no cover
        # type: (numpy.ndarray) -> numpy.ndarray
        pass

    def __mul__(self, other):
        # type: (T.Union[Pose3, numpy.ndarray]) -> T.Union[Pose3, numpy.ndarray]
        if isinstance(other, Pose3):
            return self.compose(other)
        elif isinstance(other, numpy.ndarray) and hasattr(self, "compose_with_point"):
            return getattr(self, "compose_with_point")(other).reshape(other.shape)
        else:
            raise NotImplementedError("Cannot compose {} with {}.".format(type(self), type(other)))
