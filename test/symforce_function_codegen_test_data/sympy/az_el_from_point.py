# -----------------------------------------------------------------------------
# This file was autogenerated by symforce from template:
#     function/FUNCTION.py.jinja
# Do NOT modify by hand.
# -----------------------------------------------------------------------------

# pylint: disable=too-many-locals,too-many-lines,too-many-statements,unused-argument,unused-import

import math
import typing as T

import numpy

import sym


def az_el_from_point(nav_T_cam, nav_t_point, epsilon):
    # type: (sym.Pose3, numpy.ndarray, float) -> numpy.ndarray
    """
    Transform a nav point into azimuth / elevation angles in the
    camera frame.

    Args:
        nav_T_cam (sf.Pose3): camera pose in the world
        nav_t_point (sf.Matrix): nav point
        epsilon (Scalar): small number to avoid singularities

    Returns:
        sf.Matrix: (azimuth, elevation)
    """

    # Total ops: 91

    # Input arrays
    _nav_T_cam = nav_T_cam.data
    if nav_t_point.shape == (3,):
        nav_t_point = nav_t_point.reshape((3, 1))
    elif nav_t_point.shape != (3, 1):
        raise IndexError(
            "nav_t_point is expected to have shape (3, 1) or (3,); instead had shape {}".format(
                nav_t_point.shape
            )
        )

    # Intermediate terms (23)
    _tmp0 = 2 * _nav_T_cam[3]
    _tmp1 = _nav_T_cam[2] * _tmp0
    _tmp2 = 2 * _nav_T_cam[0] * _nav_T_cam[1] - _tmp1
    _tmp3 = _nav_T_cam[0] * _tmp0
    _tmp4 = 2 * _nav_T_cam[1]
    _tmp5 = _nav_T_cam[2] * _tmp4 + _tmp3
    _tmp6 = 2 * _nav_T_cam[0] ** 2
    _tmp7 = 2 * _nav_T_cam[2] ** 2 - 1
    _tmp8 = -_tmp6 - _tmp7
    _tmp9 = (
        -_nav_T_cam[4] * _tmp2
        - _nav_T_cam[5] * _tmp8
        - _nav_T_cam[6] * _tmp5
        + _tmp2 * nav_t_point[0, 0]
        + _tmp5 * nav_t_point[2, 0]
        + _tmp8 * nav_t_point[1, 0]
    )
    _tmp10 = _nav_T_cam[0] * _tmp4 + _tmp1
    _tmp11 = _nav_T_cam[1] * _tmp0
    _tmp12 = 2 * _nav_T_cam[0] * _nav_T_cam[2] - _tmp11
    _tmp13 = _nav_T_cam[5] * _tmp10
    _tmp14 = _nav_T_cam[6] * _tmp12
    _tmp15 = 2 * _nav_T_cam[1] ** 2
    _tmp16 = -_tmp15 - _tmp7
    _tmp17 = _nav_T_cam[4] * _tmp16
    _tmp18 = (
        _tmp10 * nav_t_point[1, 0]
        + _tmp12 * nav_t_point[2, 0]
        - _tmp13
        - _tmp14
        + _tmp16 * nav_t_point[0, 0]
        - _tmp17
    )
    _tmp19 = 2 * _nav_T_cam[0] * _nav_T_cam[2] + _tmp11
    _tmp20 = 2 * _nav_T_cam[1] * _nav_T_cam[2] - _tmp3
    _tmp21 = -_tmp15 - _tmp6 + 1
    _tmp22 = (
        -_nav_T_cam[4] * _tmp19
        - _nav_T_cam[5] * _tmp20
        - _nav_T_cam[6] * _tmp21
        + _tmp19 * nav_t_point[0, 0]
        + _tmp20 * nav_t_point[1, 0]
        + _tmp21 * nav_t_point[2, 0]
    )

    # Output terms
    _res = numpy.zeros(2)
    _res[0] = math.atan2(
        _tmp9,
        _tmp10 * nav_t_point[1, 0]
        + _tmp12 * nav_t_point[2, 0]
        - _tmp13
        - _tmp14
        + _tmp16 * nav_t_point[0, 0]
        - _tmp17
        + epsilon * ((0.0 if _tmp18 == 0 else math.copysign(1, _tmp18)) + 0.5),
    )
    _res[1] = (
        -math.acos(_tmp22 / math.sqrt(_tmp18 ** 2 + _tmp22 ** 2 + _tmp9 ** 2 + epsilon))
        + (1.0 / 2.0) * math.pi
    )
    return _res
