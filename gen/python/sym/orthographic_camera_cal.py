# -----------------------------------------------------------------------------
# This file was autogenerated by symforce from template:
#     cam_package/CLASS.py.jinja
# Do NOT modify by hand.
# -----------------------------------------------------------------------------

import typing as T

import numpy

from .ops import orthographic_camera_cal as ops


class OrthographicCameraCal(object):
    """
    Autogenerated Python implementation of :py:class:`symforce.cam.orthographic_camera_cal.OrthographicCameraCal`.

    Orthographic camera model with four parameters [fx, fy, cx, cy].

    It would be possible to define orthographic cameras with only two parameters [fx, fy] but we
    keep the [cx, cy] parameters for consistency with the CameraCal interface.

    The orthographic camera model can be thought of as a special case of the LinearCameraCal model,
    where (x,y,z) in the camera frame projects to pixel (x * fx + cx, y * fy + cy).
    The z-coordinate of the point is ignored in the projection, except that only points with
    positive z-coordinates are considered valid.

    Because this is a noncentral camera model, the camera_ray_from_pixel function is not implemented.
    """

    __slots__ = ["data"]

    # This is because of an issue where mypy doesn't recognize attributes defined in __slots__
    # See https://github.com/python/mypy/issues/5941
    if T.TYPE_CHECKING:
        data = []  # type: T.List[float]

    def __init__(self, focal_length, principal_point):
        # type: (T.Union[T.Sequence[float], numpy.ndarray], T.Union[T.Sequence[float], numpy.ndarray]) -> None
        self.data = []
        if isinstance(focal_length, numpy.ndarray):
            if focal_length.shape in {(2, 1), (1, 2)}:
                focal_length = focal_length.flatten()
            elif focal_length.shape != (2,):
                raise IndexError(
                    "Expected focal_length to be a vector of length 2; instead had shape {}".format(
                        focal_length.shape
                    )
                )
        elif len(focal_length) != 2:
            raise IndexError(
                "Expected focal_length to be a sequence of length 2, was instead length {}.".format(
                    len(focal_length)
                )
            )
        if isinstance(principal_point, numpy.ndarray):
            if principal_point.shape in {(2, 1), (1, 2)}:
                principal_point = principal_point.flatten()
            elif principal_point.shape != (2,):
                raise IndexError(
                    "Expected principal_point to be a vector of length 2; instead had shape {}".format(
                        principal_point.shape
                    )
                )
        elif len(principal_point) != 2:
            raise IndexError(
                "Expected principal_point to be a sequence of length 2, was instead length {}.".format(
                    len(principal_point)
                )
            )

        self.data.extend(focal_length)
        self.data.extend(principal_point)

    def __repr__(self):
        # type: () -> str
        return "<{} {}>".format(self.__class__.__name__, self.data)

    # --------------------------------------------------------------------------
    # CameraOps
    # --------------------------------------------------------------------------

    def focal_length(self):
        # type: (OrthographicCameraCal) -> numpy.ndarray
        """
        Return the focal length.
        """

        return ops.CameraOps.focal_length(self)

    def principal_point(self):
        # type: (OrthographicCameraCal) -> numpy.ndarray
        """
        Return the principal point.
        """

        return ops.CameraOps.principal_point(self)

    def pixel_from_camera_point(self, point, epsilon):
        # type: (OrthographicCameraCal, numpy.ndarray, float) -> T.Tuple[numpy.ndarray, float]
        """
        Project a 3D point in the camera frame into 2D pixel coordinates.

        Returns:
            pixel: (x, y) coordinate in pixels if valid
            is_valid: 1 if the operation is within bounds else 0
        """

        return ops.CameraOps.pixel_from_camera_point(self, point, epsilon)

    def pixel_from_camera_point_with_jacobians(self, point, epsilon):
        # type: (OrthographicCameraCal, numpy.ndarray, float) -> T.Tuple[numpy.ndarray, float, numpy.ndarray, numpy.ndarray]
        """
        Project a 3D point in the camera frame into 2D pixel coordinates.

        Returns:
            pixel: (x, y) coordinate in pixels if valid
            is_valid: 1 if the operation is within bounds else 0
            pixel_D_cal: Derivative of pixel with respect to intrinsic calibration parameters
            pixel_D_point: Derivative of pixel with respect to point
        """

        return ops.CameraOps.pixel_from_camera_point_with_jacobians(self, point, epsilon)

    # --------------------------------------------------------------------------
    # StorageOps concept
    # --------------------------------------------------------------------------

    @staticmethod
    def storage_dim():
        # type: () -> int
        return 4

    def to_storage(self):
        # type: () -> T.List[float]
        return list(self.data)

    @classmethod
    def from_storage(cls, vec):
        # type: (T.Sequence[float]) -> OrthographicCameraCal
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
    # LieGroupOps concept
    # --------------------------------------------------------------------------

    @staticmethod
    def tangent_dim():
        # type: () -> int
        return 4

    @classmethod
    def from_tangent(cls, vec, epsilon=1e-8):
        # type: (numpy.ndarray, float) -> OrthographicCameraCal
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
        # type: (numpy.ndarray, float) -> OrthographicCameraCal
        if len(vec) != self.tangent_dim():
            raise ValueError(
                "Vector dimension ({}) not equal to tangent space dimension ({}).".format(
                    len(vec), self.tangent_dim()
                )
            )
        return ops.LieGroupOps.retract(self, vec, epsilon)

    def local_coordinates(self, b, epsilon=1e-8):
        # type: (OrthographicCameraCal, float) -> numpy.ndarray
        return ops.LieGroupOps.local_coordinates(self, b, epsilon)

    def interpolate(self, b, alpha, epsilon=1e-8):
        # type: (OrthographicCameraCal, float, float) -> OrthographicCameraCal
        return ops.LieGroupOps.interpolate(self, b, alpha, epsilon)

    # --------------------------------------------------------------------------
    # General Helpers
    # --------------------------------------------------------------------------
    def __eq__(self, other):
        # type: (T.Any) -> bool
        if isinstance(other, OrthographicCameraCal):
            return self.data == other.data
        else:
            return False
