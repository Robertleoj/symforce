# -----------------------------------------------------------------------------
# This file was autogenerated by symforce from template:
#     ops/CLASS/lie_group_ops.py.jinja
# Do NOT modify by hand.
# -----------------------------------------------------------------------------

import math
import typing as T

import numpy

import sym  # pylint: disable=useless-suppression,unused-import


class LieGroupOps(object):
    """
    Python LieGroupOps implementation for :py:class:`symforce.cam.orthographic_camera_cal.OrthographicCameraCal`.
    """

    @staticmethod
    def from_tangent(vec, epsilon):
        # type: (numpy.ndarray, float) -> sym.OrthographicCameraCal

        # Total ops: 0

        # Input arrays
        if vec.shape == (4,):
            vec = vec.reshape((4, 1))
        elif vec.shape != (4, 1):
            raise IndexError(
                "vec is expected to have shape (4, 1) or (4,); instead had shape {}".format(
                    vec.shape
                )
            )

        # Intermediate terms (0)

        # Output terms
        _res = [0.0] * 4
        _res[0] = vec[0, 0]
        _res[1] = vec[1, 0]
        _res[2] = vec[2, 0]
        _res[3] = vec[3, 0]
        return sym.OrthographicCameraCal.from_storage(_res)

    @staticmethod
    def to_tangent(a, epsilon):
        # type: (sym.OrthographicCameraCal, float) -> numpy.ndarray

        # Total ops: 0

        # Input arrays
        _a = a.data

        # Intermediate terms (0)

        # Output terms
        _res = numpy.zeros(4)
        _res[0] = _a[0]
        _res[1] = _a[1]
        _res[2] = _a[2]
        _res[3] = _a[3]
        return _res

    @staticmethod
    def retract(a, vec, epsilon):
        # type: (sym.OrthographicCameraCal, numpy.ndarray, float) -> sym.OrthographicCameraCal

        # Total ops: 4

        # Input arrays
        _a = a.data
        if vec.shape == (4,):
            vec = vec.reshape((4, 1))
        elif vec.shape != (4, 1):
            raise IndexError(
                "vec is expected to have shape (4, 1) or (4,); instead had shape {}".format(
                    vec.shape
                )
            )

        # Intermediate terms (0)

        # Output terms
        _res = [0.0] * 4
        _res[0] = _a[0] + vec[0, 0]
        _res[1] = _a[1] + vec[1, 0]
        _res[2] = _a[2] + vec[2, 0]
        _res[3] = _a[3] + vec[3, 0]
        return sym.OrthographicCameraCal.from_storage(_res)

    @staticmethod
    def local_coordinates(a, b, epsilon):
        # type: (sym.OrthographicCameraCal, sym.OrthographicCameraCal, float) -> numpy.ndarray

        # Total ops: 4

        # Input arrays
        _a = a.data
        _b = b.data

        # Intermediate terms (0)

        # Output terms
        _res = numpy.zeros(4)
        _res[0] = -_a[0] + _b[0]
        _res[1] = -_a[1] + _b[1]
        _res[2] = -_a[2] + _b[2]
        _res[3] = -_a[3] + _b[3]
        return _res

    @staticmethod
    def interpolate(a, b, alpha, epsilon):
        # type: (sym.OrthographicCameraCal, sym.OrthographicCameraCal, float, float) -> sym.OrthographicCameraCal

        # Total ops: 12

        # Input arrays
        _a = a.data
        _b = b.data

        # Intermediate terms (0)

        # Output terms
        _res = [0.0] * 4
        _res[0] = _a[0] + alpha * (-_a[0] + _b[0])
        _res[1] = _a[1] + alpha * (-_a[1] + _b[1])
        _res[2] = _a[2] + alpha * (-_a[2] + _b[2])
        _res[3] = _a[3] + alpha * (-_a[3] + _b[3])
        return sym.OrthographicCameraCal.from_storage(_res)
