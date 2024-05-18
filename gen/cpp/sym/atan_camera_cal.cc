// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cam_package/CLASS.cc.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include <sym/atan_camera_cal.h>

// Camera operation implementations
namespace sym {

template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> ATANCameraCal<Scalar>::FocalLength() const {
  // Total ops: 0

  // Input arrays
  const Eigen::Matrix<Scalar, 5, 1>& _self = Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 2, 1> _focal_length;

  _focal_length(0, 0) = _self[0];
  _focal_length(1, 0) = _self[1];

  return _focal_length;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> ATANCameraCal<Scalar>::PrincipalPoint() const {
  // Total ops: 0

  // Input arrays
  const Eigen::Matrix<Scalar, 5, 1>& _self = Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 2, 1> _principal_point;

  _principal_point(0, 0) = _self[2];
  _principal_point(1, 0) = _self[3];

  return _principal_point;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> ATANCameraCal<Scalar>::PixelFromCameraPoint(
    const Eigen::Matrix<Scalar, 3, 1>& point, const Scalar epsilon, Scalar* const is_valid) const {
  // Total ops: 25

  // Input arrays
  const Eigen::Matrix<Scalar, 5, 1>& _self = Data();

  // Intermediate terms (4)
  const Scalar _tmp0 = std::max<Scalar>(epsilon, point(2, 0));
  const Scalar _tmp1 = std::pow(_tmp0, Scalar(-2));
  const Scalar _tmp2 = std::sqrt(Scalar(_tmp1 * std::pow(point(0, 0), Scalar(2)) +
                                        _tmp1 * std::pow(point(1, 0), Scalar(2)) + epsilon));
  const Scalar _tmp3 =
      std::atan(2 * _tmp2 * std::tan(Scalar(0.5) * _self[4])) / (_self[4] * _tmp0 * _tmp2);

  // Output terms (2)
  Eigen::Matrix<Scalar, 2, 1> _pixel;

  _pixel(0, 0) = _self[0] * _tmp3 * point(0, 0) + _self[2];
  _pixel(1, 0) = _self[1] * _tmp3 * point(1, 0) + _self[3];

  if (is_valid != nullptr) {
    Scalar& _is_valid = (*is_valid);

    _is_valid = std::max<Scalar>(0, (((point(2, 0)) > 0) - ((point(2, 0)) < 0)));
  }

  return _pixel;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> ATANCameraCal<Scalar>::PixelFromCameraPointWithJacobians(
    const Eigen::Matrix<Scalar, 3, 1>& point, const Scalar epsilon, Scalar* const is_valid,
    Eigen::Matrix<Scalar, 2, 5>* const pixel_D_cal,
    Eigen::Matrix<Scalar, 2, 3>* const pixel_D_point) const {
  // Total ops: 113

  // Input arrays
  const Eigen::Matrix<Scalar, 5, 1>& _self = Data();

  // Intermediate terms (46)
  const Scalar _tmp0 = Scalar(0.5) * _self[4];
  const Scalar _tmp1 = std::tan(_tmp0);
  const Scalar _tmp2 = std::pow(point(1, 0), Scalar(2));
  const Scalar _tmp3 = std::max<Scalar>(epsilon, point(2, 0));
  const Scalar _tmp4 = std::pow(_tmp3, Scalar(-2));
  const Scalar _tmp5 = std::pow(point(0, 0), Scalar(2));
  const Scalar _tmp6 = _tmp2 * _tmp4 + _tmp4 * _tmp5 + epsilon;
  const Scalar _tmp7 = std::sqrt(_tmp6);
  const Scalar _tmp8 = 2 * _tmp7;
  const Scalar _tmp9 = std::atan(_tmp1 * _tmp8);
  const Scalar _tmp10 = Scalar(1.0) / (_tmp7);
  const Scalar _tmp11 = Scalar(1.0) / (_self[4]);
  const Scalar _tmp12 = Scalar(1.0) / (_tmp3);
  const Scalar _tmp13 = _tmp11 * _tmp12;
  const Scalar _tmp14 = _tmp10 * _tmp13;
  const Scalar _tmp15 = _tmp14 * _tmp9;
  const Scalar _tmp16 = _self[0] * _tmp15;
  const Scalar _tmp17 = _self[1] * _tmp15;
  const Scalar _tmp18 = std::tan(_tmp0);
  const Scalar _tmp19 = std::atan(_tmp18 * _tmp8);
  const Scalar _tmp20 = _tmp14 * _tmp19;
  const Scalar _tmp21 = _self[0] * point(0, 0);
  const Scalar _tmp22 = _tmp10 * _tmp21;
  const Scalar _tmp23 = _tmp12 * _tmp19 / std::pow(_self[4], Scalar(2));
  const Scalar _tmp24 = std::pow(_tmp18, Scalar(2));
  const Scalar _tmp25 = 4 * _tmp6;
  const Scalar _tmp26 = Scalar(1.0) * (_tmp24 + 1) / (_tmp24 * _tmp25 + 1);
  const Scalar _tmp27 = _tmp13 * _tmp21;
  const Scalar _tmp28 = _self[1] * point(1, 0);
  const Scalar _tmp29 = _tmp10 * _tmp28;
  const Scalar _tmp30 = _tmp13 * _tmp28;
  const Scalar _tmp31 = _self[0] * _tmp5;
  const Scalar _tmp32 = std::pow(_tmp3, Scalar(-3));
  const Scalar _tmp33 = _tmp11 * _tmp32;
  const Scalar _tmp34 = _tmp1 / (_tmp6 * (std::pow(_tmp1, Scalar(2)) * _tmp25 + 1));
  const Scalar _tmp35 = 2 * _tmp33 * _tmp34;
  const Scalar _tmp36 = _tmp9 / (_tmp6 * std::sqrt(_tmp6));
  const Scalar _tmp37 = _tmp33 * _tmp36;
  const Scalar _tmp38 = _self[1] * _tmp37;
  const Scalar _tmp39 = _tmp21 * point(1, 0);
  const Scalar _tmp40 = (((-epsilon + point(2, 0)) > 0) - ((-epsilon + point(2, 0)) < 0)) + 1;
  const Scalar _tmp41 = _tmp32 * _tmp40;
  const Scalar _tmp42 = -_tmp2 * _tmp41 - _tmp41 * _tmp5;
  const Scalar _tmp43 = _tmp34 * _tmp42;
  const Scalar _tmp44 = (Scalar(1) / Scalar(2)) * _tmp36 * _tmp42;
  const Scalar _tmp45 = (Scalar(1) / Scalar(2)) * _tmp11 * _tmp4 * _tmp40 * _tmp9;

  // Output terms (4)
  Eigen::Matrix<Scalar, 2, 1> _pixel;

  _pixel(0, 0) = _self[2] + _tmp16 * point(0, 0);
  _pixel(1, 0) = _self[3] + _tmp17 * point(1, 0);

  if (is_valid != nullptr) {
    Scalar& _is_valid = (*is_valid);

    _is_valid = std::max<Scalar>(0, (((point(2, 0)) > 0) - ((point(2, 0)) < 0)));
  }

  if (pixel_D_cal != nullptr) {
    Eigen::Matrix<Scalar, 2, 5>& _pixel_D_cal = (*pixel_D_cal);

    _pixel_D_cal(0, 0) = _tmp20 * point(0, 0);
    _pixel_D_cal(1, 0) = 0;
    _pixel_D_cal(0, 1) = 0;
    _pixel_D_cal(1, 1) = _tmp20 * point(1, 0);
    _pixel_D_cal(0, 2) = 1;
    _pixel_D_cal(1, 2) = 0;
    _pixel_D_cal(0, 3) = 0;
    _pixel_D_cal(1, 3) = 1;
    _pixel_D_cal(0, 4) = -_tmp22 * _tmp23 + _tmp26 * _tmp27;
    _pixel_D_cal(1, 4) = -_tmp23 * _tmp29 + _tmp26 * _tmp30;
  }

  if (pixel_D_point != nullptr) {
    Eigen::Matrix<Scalar, 2, 3>& _pixel_D_point = (*pixel_D_point);

    _pixel_D_point(0, 0) = _tmp16 + _tmp31 * _tmp35 - _tmp31 * _tmp37;
    _pixel_D_point(1, 0) = _tmp28 * _tmp35 * point(0, 0) - _tmp38 * point(0, 0) * point(1, 0);
    _pixel_D_point(0, 1) = _tmp35 * _tmp39 - _tmp37 * _tmp39;
    _pixel_D_point(1, 1) = _self[1] * _tmp2 * _tmp35 + _tmp17 - _tmp2 * _tmp38;
    _pixel_D_point(0, 2) = -_tmp22 * _tmp45 + _tmp27 * _tmp43 - _tmp27 * _tmp44;
    _pixel_D_point(1, 2) = -_tmp29 * _tmp45 + _tmp30 * _tmp43 - _tmp30 * _tmp44;
  }

  return _pixel;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 3, 1> ATANCameraCal<Scalar>::CameraRayFromPixel(
    const Eigen::Matrix<Scalar, 2, 1>& pixel, const Scalar epsilon, Scalar* const is_valid) const {
  // Total ops: 27

  // Input arrays
  const Eigen::Matrix<Scalar, 5, 1>& _self = Data();

  // Intermediate terms (5)
  const Scalar _tmp0 = -_self[2] + pixel(0, 0);
  const Scalar _tmp1 = -_self[3] + pixel(1, 0);
  const Scalar _tmp2 =
      std::sqrt(Scalar(epsilon + std::pow(_tmp1, Scalar(2)) / std::pow(_self[1], Scalar(2)) +
                       std::pow(_tmp0, Scalar(2)) / std::pow(_self[0], Scalar(2))));
  const Scalar _tmp3 = _self[4] * _tmp2;
  const Scalar _tmp4 =
      (Scalar(1) / Scalar(2)) * std::tan(_tmp3) / (_tmp2 * std::tan(Scalar(0.5) * _self[4]));

  // Output terms (2)
  Eigen::Matrix<Scalar, 3, 1> _camera_ray;

  _camera_ray(0, 0) = _tmp0 * _tmp4 / _self[0];
  _camera_ray(1, 0) = _tmp1 * _tmp4 / _self[1];
  _camera_ray(2, 0) = 1;

  if (is_valid != nullptr) {
    Scalar& _is_valid = (*is_valid);

    _is_valid = std::max<Scalar>(0, (((-std::fabs(_tmp3) + Scalar(M_PI_2)) > 0) -
                                     ((-std::fabs(_tmp3) + Scalar(M_PI_2)) < 0)));
  }

  return _camera_ray;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 3, 1> ATANCameraCal<Scalar>::CameraRayFromPixelWithJacobians(
    const Eigen::Matrix<Scalar, 2, 1>& pixel, const Scalar epsilon, Scalar* const is_valid,
    Eigen::Matrix<Scalar, 3, 5>* const point_D_cal,
    Eigen::Matrix<Scalar, 3, 2>* const point_D_pixel) const {
  // Total ops: 133

  // Input arrays
  const Eigen::Matrix<Scalar, 5, 1>& _self = Data();

  // Intermediate terms (54)
  const Scalar _tmp0 = -_self[2] + pixel(0, 0);
  const Scalar _tmp1 = -_self[3] + pixel(1, 0);
  const Scalar _tmp2 = std::pow(_tmp1, Scalar(2));
  const Scalar _tmp3 = std::pow(_self[1], Scalar(-2));
  const Scalar _tmp4 = std::pow(_tmp0, Scalar(2));
  const Scalar _tmp5 = std::pow(_self[0], Scalar(-2));
  const Scalar _tmp6 = _tmp2 * _tmp3 + _tmp4 * _tmp5 + epsilon;
  const Scalar _tmp7 = std::sqrt(_tmp6);
  const Scalar _tmp8 = _self[4] * _tmp7;
  const Scalar _tmp9 = std::tan(_tmp8);
  const Scalar _tmp10 = _tmp9 / _tmp7;
  const Scalar _tmp11 = Scalar(0.5) * _self[4];
  const Scalar _tmp12 = Scalar(1.0) / (std::tan(_tmp11));
  const Scalar _tmp13 = Scalar(1.0) / (_self[0]);
  const Scalar _tmp14 = (Scalar(1) / Scalar(2)) * _tmp13;
  const Scalar _tmp15 = _tmp12 * _tmp14;
  const Scalar _tmp16 = _tmp10 * _tmp15;
  const Scalar _tmp17 = Scalar(1.0) / (_self[1]);
  const Scalar _tmp18 = (Scalar(1) / Scalar(2)) * _tmp17;
  const Scalar _tmp19 = _tmp1 * _tmp18;
  const Scalar _tmp20 = _tmp10 * _tmp12;
  const Scalar _tmp21 = [&]() {
    const Scalar base = _tmp0;
    return base * base * base;
  }() / std::pow(_self[0], Scalar(4));
  const Scalar _tmp22 = std::tan(_tmp11);
  const Scalar _tmp23 = Scalar(1.0) / (_tmp22);
  const Scalar _tmp24 = std::pow(_tmp9, Scalar(2)) + 1;
  const Scalar _tmp25 = _tmp23 * _tmp24;
  const Scalar _tmp26 = _self[4] / _tmp6;
  const Scalar _tmp27 = (Scalar(1) / Scalar(2)) * _tmp26;
  const Scalar _tmp28 = _tmp25 * _tmp27;
  const Scalar _tmp29 = _tmp9 / (_tmp6 * std::sqrt(_tmp6));
  const Scalar _tmp30 = (Scalar(1) / Scalar(2)) * _tmp29;
  const Scalar _tmp31 = _tmp23 * _tmp30;
  const Scalar _tmp32 = _tmp10 * _tmp23;
  const Scalar _tmp33 = (Scalar(1) / Scalar(2)) * _tmp32;
  const Scalar _tmp34 = _tmp0 * _tmp5;
  const Scalar _tmp35 = _tmp4 / [&]() {
    const Scalar base = _self[0];
    return base * base * base;
  }();
  const Scalar _tmp36 = _tmp19 * _tmp25;
  const Scalar _tmp37 = _tmp26 * _tmp36;
  const Scalar _tmp38 = _tmp23 * _tmp29;
  const Scalar _tmp39 = _tmp19 * _tmp38;
  const Scalar _tmp40 = _tmp2 / [&]() {
    const Scalar base = _self[1];
    return base * base * base;
  }();
  const Scalar _tmp41 = _tmp0 * _tmp14;
  const Scalar _tmp42 = _tmp25 * _tmp41;
  const Scalar _tmp43 = _tmp26 * _tmp42;
  const Scalar _tmp44 = _tmp38 * _tmp41;
  const Scalar _tmp45 = [&]() {
    const Scalar base = _tmp1;
    return base * base * base;
  }() / std::pow(_self[1], Scalar(4));
  const Scalar _tmp46 = _tmp1 * _tmp3;
  const Scalar _tmp47 = std::pow(_tmp22, Scalar(2));
  const Scalar _tmp48 = Scalar(0.25) * _tmp10 * (_tmp47 + 1) / _tmp47;
  const Scalar _tmp49 = _tmp12 * _tmp30;
  const Scalar _tmp50 = _tmp12 * _tmp24;
  const Scalar _tmp51 = _tmp27 * _tmp50;
  const Scalar _tmp52 = _tmp19 * _tmp34;
  const Scalar _tmp53 = _tmp0 * _tmp15 * _tmp46;

  // Output terms (4)
  Eigen::Matrix<Scalar, 3, 1> _camera_ray;

  _camera_ray(0, 0) = _tmp0 * _tmp16;
  _camera_ray(1, 0) = _tmp19 * _tmp20;
  _camera_ray(2, 0) = 1;

  if (is_valid != nullptr) {
    Scalar& _is_valid = (*is_valid);

    _is_valid = std::max<Scalar>(0, (((-std::fabs(_tmp8) + Scalar(M_PI_2)) > 0) -
                                     ((-std::fabs(_tmp8) + Scalar(M_PI_2)) < 0)));
  }

  if (point_D_cal != nullptr) {
    Eigen::Matrix<Scalar, 3, 5>& _point_D_cal = (*point_D_cal);

    _point_D_cal(0, 0) = -_tmp21 * _tmp28 + _tmp21 * _tmp31 - _tmp33 * _tmp34;
    _point_D_cal(1, 0) = -_tmp35 * _tmp37 + _tmp35 * _tmp39;
    _point_D_cal(2, 0) = 0;
    _point_D_cal(0, 1) = -_tmp40 * _tmp43 + _tmp40 * _tmp44;
    _point_D_cal(1, 1) = -_tmp28 * _tmp45 + _tmp31 * _tmp45 - _tmp33 * _tmp46;
    _point_D_cal(2, 1) = 0;
    _point_D_cal(0, 2) = -_tmp14 * _tmp32 - _tmp28 * _tmp35 + _tmp31 * _tmp35;
    _point_D_cal(1, 2) = -_tmp34 * _tmp37 + _tmp34 * _tmp39;
    _point_D_cal(2, 2) = 0;
    _point_D_cal(0, 3) = -_tmp43 * _tmp46 + _tmp44 * _tmp46;
    _point_D_cal(1, 3) = -_tmp18 * _tmp32 - _tmp28 * _tmp40 + _tmp31 * _tmp40;
    _point_D_cal(2, 3) = 0;
    _point_D_cal(0, 4) = -_tmp0 * _tmp13 * _tmp48 + _tmp42;
    _point_D_cal(1, 4) = -_tmp1 * _tmp17 * _tmp48 + _tmp36;
    _point_D_cal(2, 4) = 0;
  }

  if (point_D_pixel != nullptr) {
    Eigen::Matrix<Scalar, 3, 2>& _point_D_pixel = (*point_D_pixel);

    _point_D_pixel(0, 0) = _tmp16 - _tmp35 * _tmp49 + _tmp35 * _tmp51;
    _point_D_pixel(1, 0) = -_tmp12 * _tmp29 * _tmp52 + _tmp26 * _tmp50 * _tmp52;
    _point_D_pixel(2, 0) = 0;
    _point_D_pixel(0, 1) = _tmp24 * _tmp26 * _tmp53 - _tmp29 * _tmp53;
    _point_D_pixel(1, 1) = _tmp18 * _tmp20 - _tmp40 * _tmp49 + _tmp40 * _tmp51;
    _point_D_pixel(2, 1) = 0;
  }

  return _camera_ray;
}

// Print implementations
std::ostream& operator<<(std::ostream& os, const ATANCameraCald& a) {
  const Eigen::IOFormat fmt(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n", "[", "]");
  os << "<ATANCameraCald " << a.Data().transpose().format(fmt) << ">";
  return os;
}

std::ostream& operator<<(std::ostream& os, const ATANCameraCalf& a) {
  const Eigen::IOFormat fmt(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n", "[", "]");
  os << "<ATANCameraCalf " << a.Data().transpose().format(fmt) << ">";
  return os;
}

}  // namespace sym

// Concept implementations for this class
#include "./ops/atan_camera_cal/storage_ops.h"

// Explicit instantiation
template class sym::ATANCameraCal<double>;
template class sym::ATANCameraCal<float>;
