// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cam_package/CLASS.cc.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include <sym/linear_camera_cal.h>

// Camera operation implementations
namespace sym {

template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> LinearCameraCal<Scalar>::FocalLength() const {
  // Total ops: 0

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _self = Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 2, 1> _focal_length;

  _focal_length(0, 0) = _self[0];
  _focal_length(1, 0) = _self[1];

  return _focal_length;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> LinearCameraCal<Scalar>::PrincipalPoint() const {
  // Total ops: 0

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _self = Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 2, 1> _principal_point;

  _principal_point(0, 0) = _self[2];
  _principal_point(1, 0) = _self[3];

  return _principal_point;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> LinearCameraCal<Scalar>::PixelFromCameraPoint(
    const Eigen::Matrix<Scalar, 3, 1>& point, const Scalar epsilon, Scalar* const is_valid) const {
  // Total ops: 10

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _self = Data();

  // Intermediate terms (1)
  const Scalar _tmp0 = Scalar(1.0) / (std::max<Scalar>(epsilon, point(2, 0)));

  // Output terms (2)
  Eigen::Matrix<Scalar, 2, 1> _pixel;

  _pixel(0, 0) = _self[0] * _tmp0 * point(0, 0) + _self[2];
  _pixel(1, 0) = _self[1] * _tmp0 * point(1, 0) + _self[3];

  if (is_valid != nullptr) {
    Scalar& _is_valid = (*is_valid);

    _is_valid = std::max<Scalar>(0, (((point(2, 0)) > 0) - ((point(2, 0)) < 0)));
  }

  return _pixel;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> LinearCameraCal<Scalar>::PixelFromCameraPointWithJacobians(
    const Eigen::Matrix<Scalar, 3, 1>& point, const Scalar epsilon, Scalar* const is_valid,
    Eigen::Matrix<Scalar, 2, 4>* const pixel_D_cal,
    Eigen::Matrix<Scalar, 2, 3>* const pixel_D_point) const {
  // Total ops: 24

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _self = Data();

  // Intermediate terms (5)
  const Scalar _tmp0 = std::max<Scalar>(epsilon, point(2, 0));
  const Scalar _tmp1 = Scalar(1.0) / (_tmp0);
  const Scalar _tmp2 = _tmp1 * point(0, 0);
  const Scalar _tmp3 = _tmp1 * point(1, 0);
  const Scalar _tmp4 = (Scalar(1) / Scalar(2)) *
                       ((((-epsilon + point(2, 0)) > 0) - ((-epsilon + point(2, 0)) < 0)) + 1) /
                       std::pow(_tmp0, Scalar(2));

  // Output terms (4)
  Eigen::Matrix<Scalar, 2, 1> _pixel;

  _pixel(0, 0) = _self[0] * _tmp2 + _self[2];
  _pixel(1, 0) = _self[1] * _tmp3 + _self[3];

  if (is_valid != nullptr) {
    Scalar& _is_valid = (*is_valid);

    _is_valid = std::max<Scalar>(0, (((point(2, 0)) > 0) - ((point(2, 0)) < 0)));
  }

  if (pixel_D_cal != nullptr) {
    Eigen::Matrix<Scalar, 2, 4>& _pixel_D_cal = (*pixel_D_cal);

    _pixel_D_cal(0, 0) = _tmp2;
    _pixel_D_cal(1, 0) = 0;
    _pixel_D_cal(0, 1) = 0;
    _pixel_D_cal(1, 1) = _tmp3;
    _pixel_D_cal(0, 2) = 1;
    _pixel_D_cal(1, 2) = 0;
    _pixel_D_cal(0, 3) = 0;
    _pixel_D_cal(1, 3) = 1;
  }

  if (pixel_D_point != nullptr) {
    Eigen::Matrix<Scalar, 2, 3>& _pixel_D_point = (*pixel_D_point);

    _pixel_D_point(0, 0) = _self[0] * _tmp1;
    _pixel_D_point(1, 0) = 0;
    _pixel_D_point(0, 1) = 0;
    _pixel_D_point(1, 1) = _self[1] * _tmp1;
    _pixel_D_point(0, 2) = -_self[0] * _tmp4 * point(0, 0);
    _pixel_D_point(1, 2) = -_self[1] * _tmp4 * point(1, 0);
  }

  return _pixel;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 3, 1> LinearCameraCal<Scalar>::CameraRayFromPixel(
    const Eigen::Matrix<Scalar, 2, 1>& pixel, const Scalar epsilon, Scalar* const is_valid) const {
  // Total ops: 4

  // Unused inputs
  (void)epsilon;

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _self = Data();

  // Intermediate terms (0)

  // Output terms (2)
  Eigen::Matrix<Scalar, 3, 1> _camera_ray;

  _camera_ray(0, 0) = (-_self[2] + pixel(0, 0)) / _self[0];
  _camera_ray(1, 0) = (-_self[3] + pixel(1, 0)) / _self[1];
  _camera_ray(2, 0) = 1;

  if (is_valid != nullptr) {
    Scalar& _is_valid = (*is_valid);

    _is_valid = 1;
  }

  return _camera_ray;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 3, 1> LinearCameraCal<Scalar>::CameraRayFromPixelWithJacobians(
    const Eigen::Matrix<Scalar, 2, 1>& pixel, const Scalar epsilon, Scalar* const is_valid,
    Eigen::Matrix<Scalar, 3, 4>* const point_D_cal,
    Eigen::Matrix<Scalar, 3, 2>* const point_D_pixel) const {
  // Total ops: 14

  // Unused inputs
  (void)epsilon;

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _self = Data();

  // Intermediate terms (4)
  const Scalar _tmp0 = -_self[2] + pixel(0, 0);
  const Scalar _tmp1 = Scalar(1.0) / (_self[0]);
  const Scalar _tmp2 = -_self[3] + pixel(1, 0);
  const Scalar _tmp3 = Scalar(1.0) / (_self[1]);

  // Output terms (4)
  Eigen::Matrix<Scalar, 3, 1> _camera_ray;

  _camera_ray(0, 0) = _tmp0 * _tmp1;
  _camera_ray(1, 0) = _tmp2 * _tmp3;
  _camera_ray(2, 0) = 1;

  if (is_valid != nullptr) {
    Scalar& _is_valid = (*is_valid);

    _is_valid = 1;
  }

  if (point_D_cal != nullptr) {
    Eigen::Matrix<Scalar, 3, 4>& _point_D_cal = (*point_D_cal);

    _point_D_cal.setZero();

    _point_D_cal(0, 0) = -_tmp0 / std::pow(_self[0], Scalar(2));
    _point_D_cal(1, 1) = -_tmp2 / std::pow(_self[1], Scalar(2));
    _point_D_cal(0, 2) = -_tmp1;
    _point_D_cal(1, 3) = -_tmp3;
  }

  if (point_D_pixel != nullptr) {
    Eigen::Matrix<Scalar, 3, 2>& _point_D_pixel = (*point_D_pixel);

    _point_D_pixel.setZero();

    _point_D_pixel(0, 0) = _tmp1;
    _point_D_pixel(1, 1) = _tmp3;
  }

  return _camera_ray;
}

// Print implementations
std::ostream& operator<<(std::ostream& os, const LinearCameraCald& a) {
  const Eigen::IOFormat fmt(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n", "[", "]");
  os << "<LinearCameraCald " << a.Data().transpose().format(fmt) << ">";
  return os;
}

std::ostream& operator<<(std::ostream& os, const LinearCameraCalf& a) {
  const Eigen::IOFormat fmt(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n", "[", "]");
  os << "<LinearCameraCalf " << a.Data().transpose().format(fmt) << ">";
  return os;
}

}  // namespace sym

// Concept implementations for this class
#include "./ops/linear_camera_cal/storage_ops.h"

// Explicit instantiation
template class sym::LinearCameraCal<double>;
template class sym::LinearCameraCal<float>;
