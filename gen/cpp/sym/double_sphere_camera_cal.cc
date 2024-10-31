// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cam_package/CLASS.cc.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include <sym/double_sphere_camera_cal.h>

// Camera operation implementations
namespace sym {

template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> DoubleSphereCameraCal<Scalar>::FocalLength() const {
  // Total ops: 0

  // Input arrays
  const Eigen::Matrix<Scalar, 6, 1>& _self = Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 2, 1> _focal_length;

  _focal_length(0, 0) = _self[0];
  _focal_length(1, 0) = _self[1];

  return _focal_length;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> DoubleSphereCameraCal<Scalar>::PrincipalPoint() const {
  // Total ops: 0

  // Input arrays
  const Eigen::Matrix<Scalar, 6, 1>& _self = Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 2, 1> _principal_point;

  _principal_point(0, 0) = _self[2];
  _principal_point(1, 0) = _self[3];

  return _principal_point;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> DoubleSphereCameraCal<Scalar>::PixelFromCameraPoint(
    const Eigen::Matrix<Scalar, 3, 1>& point, const Scalar epsilon, Scalar* const is_valid) const {
  // Total ops: 73

  // Input arrays
  const Eigen::Matrix<Scalar, 6, 1>& _self = Data();

  // Intermediate terms (13)
  const Scalar _tmp0 = std::pow(epsilon, Scalar(2)) + std::pow(point(0, 0), Scalar(2)) +
                       std::pow(point(1, 0), Scalar(2));
  const Scalar _tmp1 = std::sqrt(Scalar(_tmp0 + std::pow(point(2, 0), Scalar(2))));
  const Scalar _tmp2 = _self[4] * _tmp1 + point(2, 0);
  const Scalar _tmp3 =
      std::min<Scalar>(0, (((_self[5] + Scalar(-0.5)) > 0) - ((_self[5] + Scalar(-0.5)) < 0)));
  const Scalar _tmp4 = 2 * _tmp3;
  const Scalar _tmp5 = _self[5] - epsilon * (_tmp4 + 1);
  const Scalar _tmp6 = -_tmp5;
  const Scalar _tmp7 =
      Scalar(1.0) /
      (std::max<Scalar>(
          epsilon,
          _tmp2 * (_tmp6 + 1) + _tmp5 * std::sqrt(Scalar(_tmp0 + std::pow(_tmp2, Scalar(2))))));
  const Scalar _tmp8 = _tmp3 + _tmp5;
  const Scalar _tmp9 = (Scalar(1) / Scalar(2)) * _tmp4 + _tmp6 + 1;
  const Scalar _tmp10 = std::pow(_self[4], Scalar(2));
  const Scalar _tmp11 = std::pow(_tmp9, Scalar(2)) / std::pow(_tmp8, Scalar(2));
  const Scalar _tmp12 = _tmp10 * _tmp11 - _tmp10 + 1;

  // Output terms (2)
  Eigen::Matrix<Scalar, 2, 1> _pixel;

  _pixel(0, 0) = _self[0] * _tmp7 * point(0, 0) + _self[2];
  _pixel(1, 0) = _self[1] * _tmp7 * point(1, 0) + _self[3];

  if (is_valid != nullptr) {
    Scalar& _is_valid = (*is_valid);

    _is_valid = std::max<Scalar>(
        0, std::min<Scalar>(
               std::max<Scalar>(-(((_self[4] - 1) > 0) - ((_self[4] - 1) < 0)),
                                1 - std::max<Scalar>(0, -(((_self[4] * point(2, 0) + _tmp1) > 0) -
                                                          ((_self[4] * point(2, 0) + _tmp1) < 0)))),
               std::max<Scalar>(
                   -(((_tmp12) > 0) - ((_tmp12) < 0)),
                   1 - std::max<Scalar>(0, -(((-_tmp1 * (_self[4] * _tmp11 - _self[4] -
                                                         _tmp9 *
                                                             std::sqrt(Scalar(std::max<Scalar>(
                                                                 _tmp12, std::sqrt(epsilon)))) /
                                                             _tmp8) +
                                               point(2, 0)) > 0) -
                                             ((-_tmp1 * (_self[4] * _tmp11 - _self[4] -
                                                         _tmp9 *
                                                             std::sqrt(Scalar(std::max<Scalar>(
                                                                 _tmp12, std::sqrt(epsilon)))) /
                                                             _tmp8) +
                                               point(2, 0)) < 0))))));
  }

  return _pixel;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> DoubleSphereCameraCal<Scalar>::PixelFromCameraPointWithJacobians(
    const Eigen::Matrix<Scalar, 3, 1>& point, const Scalar epsilon, Scalar* const is_valid,
    Eigen::Matrix<Scalar, 2, 6>* const pixel_D_cal,
    Eigen::Matrix<Scalar, 2, 3>* const pixel_D_point) const {
  // Total ops: 134

  // Input arrays
  const Eigen::Matrix<Scalar, 6, 1>& _self = Data();

  // Intermediate terms (40)
  const Scalar _tmp0 = std::pow(epsilon, Scalar(2)) + std::pow(point(0, 0), Scalar(2)) +
                       std::pow(point(1, 0), Scalar(2));
  const Scalar _tmp1 = std::sqrt(Scalar(_tmp0 + std::pow(point(2, 0), Scalar(2))));
  const Scalar _tmp2 = _self[4] * _tmp1 + point(2, 0);
  const Scalar _tmp3 =
      std::min<Scalar>(0, (((_self[5] + Scalar(-0.5)) > 0) - ((_self[5] + Scalar(-0.5)) < 0)));
  const Scalar _tmp4 = 2 * _tmp3;
  const Scalar _tmp5 = _self[5] - epsilon * (_tmp4 + 1);
  const Scalar _tmp6 = -_tmp5;
  const Scalar _tmp7 = _tmp6 + 1;
  const Scalar _tmp8 = std::sqrt(Scalar(_tmp0 + std::pow(_tmp2, Scalar(2))));
  const Scalar _tmp9 = _tmp2 * _tmp7 + _tmp5 * _tmp8;
  const Scalar _tmp10 = std::max<Scalar>(_tmp9, epsilon);
  const Scalar _tmp11 = Scalar(1.0) / (_tmp10);
  const Scalar _tmp12 = _self[0] * _tmp11;
  const Scalar _tmp13 = _self[1] * _tmp11;
  const Scalar _tmp14 = _self[4] * point(2, 0);
  const Scalar _tmp15 = _tmp3 + _tmp5;
  const Scalar _tmp16 = (Scalar(1) / Scalar(2)) * _tmp4 + _tmp6 + 1;
  const Scalar _tmp17 = std::pow(_self[4], Scalar(2));
  const Scalar _tmp18 = std::pow(_tmp16, Scalar(2)) / std::pow(_tmp15, Scalar(2));
  const Scalar _tmp19 = _tmp17 * _tmp18 - _tmp17 + 1;
  const Scalar _tmp20 = _tmp5 / _tmp8;
  const Scalar _tmp21 = _tmp2 * _tmp20;
  const Scalar _tmp22 = _tmp1 * _tmp21 + _tmp1 * _tmp7;
  const Scalar _tmp23 = (Scalar(1) / Scalar(2)) *
                        ((((_tmp9 - epsilon) > 0) - ((_tmp9 - epsilon) < 0)) + 1) /
                        std::pow(_tmp10, Scalar(2));
  const Scalar _tmp24 = _self[0] * point(0, 0);
  const Scalar _tmp25 = _tmp23 * _tmp24;
  const Scalar _tmp26 = _self[1] * point(1, 0);
  const Scalar _tmp27 = _tmp23 * _tmp26;
  const Scalar _tmp28 = -_tmp2 + _tmp8;
  const Scalar _tmp29 = Scalar(1.0) / (_tmp1);
  const Scalar _tmp30 = _self[4] * _tmp29;
  const Scalar _tmp31 = _tmp30 * _tmp7;
  const Scalar _tmp32 = 2 * point(0, 0);
  const Scalar _tmp33 = _tmp2 * _tmp30;
  const Scalar _tmp34 = (Scalar(1) / Scalar(2)) * _tmp20;
  const Scalar _tmp35 = _tmp23 * (_tmp31 * point(0, 0) + _tmp34 * (_tmp32 * _tmp33 + _tmp32));
  const Scalar _tmp36 = 2 * point(1, 0);
  const Scalar _tmp37 = _tmp31 * point(1, 0) + _tmp34 * (_tmp33 * _tmp36 + _tmp36);
  const Scalar _tmp38 = _tmp14 * _tmp29 + 1;
  const Scalar _tmp39 = _tmp21 * _tmp38 + _tmp38 * _tmp7;

  // Output terms (4)
  Eigen::Matrix<Scalar, 2, 1> _pixel;

  _pixel(0, 0) = _self[2] + _tmp12 * point(0, 0);
  _pixel(1, 0) = _self[3] + _tmp13 * point(1, 0);

  if (is_valid != nullptr) {
    Scalar& _is_valid = (*is_valid);

    _is_valid = std::max<Scalar>(
        0, std::min<Scalar>(
               std::max<Scalar>(
                   -(((_self[4] - 1) > 0) - ((_self[4] - 1) < 0)),
                   1 - std::max<Scalar>(0, -(((_tmp1 + _tmp14) > 0) - ((_tmp1 + _tmp14) < 0)))),
               std::max<Scalar>(
                   -(((_tmp19) > 0) - ((_tmp19) < 0)),
                   1 - std::max<Scalar>(
                           0, -(((-_tmp1 *
                                      (_self[4] * _tmp18 - _self[4] -
                                       _tmp16 *
                                           std::sqrt(Scalar(
                                               std::max<Scalar>(_tmp19, std::sqrt(epsilon)))) /
                                           _tmp15) +
                                  point(2, 0)) > 0) -
                                ((-_tmp1 *
                                      (_self[4] * _tmp18 - _self[4] -
                                       _tmp16 *
                                           std::sqrt(Scalar(
                                               std::max<Scalar>(_tmp19, std::sqrt(epsilon)))) /
                                           _tmp15) +
                                  point(2, 0)) < 0))))));
  }

  if (pixel_D_cal != nullptr) {
    Eigen::Matrix<Scalar, 2, 6>& _pixel_D_cal = (*pixel_D_cal);

    _pixel_D_cal(0, 0) = _tmp11 * point(0, 0);
    _pixel_D_cal(1, 0) = 0;
    _pixel_D_cal(0, 1) = 0;
    _pixel_D_cal(1, 1) = _tmp11 * point(1, 0);
    _pixel_D_cal(0, 2) = 1;
    _pixel_D_cal(1, 2) = 0;
    _pixel_D_cal(0, 3) = 0;
    _pixel_D_cal(1, 3) = 1;
    _pixel_D_cal(0, 4) = -_tmp22 * _tmp25;
    _pixel_D_cal(1, 4) = -_tmp22 * _tmp27;
    _pixel_D_cal(0, 5) = -_tmp25 * _tmp28;
    _pixel_D_cal(1, 5) = -_tmp27 * _tmp28;
  }

  if (pixel_D_point != nullptr) {
    Eigen::Matrix<Scalar, 2, 3>& _pixel_D_point = (*pixel_D_point);

    _pixel_D_point(0, 0) = _tmp12 - _tmp24 * _tmp35;
    _pixel_D_point(1, 0) = -_tmp26 * _tmp35;
    _pixel_D_point(0, 1) = -_tmp25 * _tmp37;
    _pixel_D_point(1, 1) = _tmp13 - _tmp27 * _tmp37;
    _pixel_D_point(0, 2) = -_tmp25 * _tmp39;
    _pixel_D_point(1, 2) = -_tmp27 * _tmp39;
  }

  return _pixel;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 3, 1> DoubleSphereCameraCal<Scalar>::CameraRayFromPixel(
    const Eigen::Matrix<Scalar, 2, 1>& pixel, const Scalar epsilon, Scalar* const is_valid) const {
  // Total ops: 62

  // Input arrays
  const Eigen::Matrix<Scalar, 6, 1>& _self = Data();

  // Intermediate terms (12)
  const Scalar _tmp0 = -_self[2] + pixel(0, 0);
  const Scalar _tmp1 = -_self[3] + pixel(1, 0);
  const Scalar _tmp2 = std::pow(_tmp1, Scalar(2)) / std::pow(_self[1], Scalar(2)) +
                       std::pow(_tmp0, Scalar(2)) / std::pow(_self[0], Scalar(2));
  const Scalar _tmp3 = -_tmp2 * (2 * _self[5] - 1) + 1;
  const Scalar _tmp4 =
      _self[5] * std::sqrt(Scalar(std::max<Scalar>(_tmp3, epsilon))) - _self[5] + 1;
  const Scalar _tmp5 =
      _tmp4 + epsilon * (2 * std::min<Scalar>(0, (((_tmp4) > 0) - ((_tmp4) < 0))) + 1);
  const Scalar _tmp6 = -std::pow(_self[5], Scalar(2)) * _tmp2 + 1;
  const Scalar _tmp7 = _tmp6 / _tmp5;
  const Scalar _tmp8 = std::pow(_tmp6, Scalar(2)) / std::pow(_tmp5, Scalar(2));
  const Scalar _tmp9 = _tmp2 * (1 - std::pow(_self[4], Scalar(2))) + _tmp8;
  const Scalar _tmp10 = _tmp2 + _tmp8;
  const Scalar _tmp11 =
      (_self[4] * _tmp7 + std::sqrt(Scalar(std::max<Scalar>(_tmp9, epsilon)))) /
      (_tmp10 + epsilon * (2 * std::min<Scalar>(0, (((_tmp10) > 0) - ((_tmp10) < 0))) + 1));

  // Output terms (2)
  Eigen::Matrix<Scalar, 3, 1> _camera_ray;

  _camera_ray(0, 0) = _tmp0 * _tmp11 / _self[0];
  _camera_ray(1, 0) = _tmp1 * _tmp11 / _self[1];
  _camera_ray(2, 0) = -_self[4] + _tmp11 * _tmp7;

  if (is_valid != nullptr) {
    Scalar& _is_valid = (*is_valid);

    _is_valid = std::min<Scalar>(1 - std::max<Scalar>(0, -(((_tmp3) > 0) - ((_tmp3) < 0))),
                                 1 - std::max<Scalar>(0, -(((_tmp9) > 0) - ((_tmp9) < 0))));
  }

  return _camera_ray;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 3, 1> DoubleSphereCameraCal<Scalar>::CameraRayFromPixelWithJacobians(
    const Eigen::Matrix<Scalar, 2, 1>& pixel, const Scalar epsilon, Scalar* const is_valid,
    Eigen::Matrix<Scalar, 3, 6>* const point_D_cal,
    Eigen::Matrix<Scalar, 3, 2>* const point_D_pixel) const {
  // Total ops: 298

  // Input arrays
  const Eigen::Matrix<Scalar, 6, 1>& _self = Data();

  // Intermediate terms (117)
  const Scalar _tmp0 = -_self[2] + pixel(0, 0);
  const Scalar _tmp1 = Scalar(1.0) / (_self[0]);
  const Scalar _tmp2 = std::pow(_tmp0, Scalar(2));
  const Scalar _tmp3 = std::pow(_self[0], Scalar(-2));
  const Scalar _tmp4 = -_self[3] + pixel(1, 0);
  const Scalar _tmp5 = std::pow(_tmp4, Scalar(2));
  const Scalar _tmp6 = std::pow(_self[1], Scalar(-2));
  const Scalar _tmp7 = _tmp2 * _tmp3 + _tmp5 * _tmp6;
  const Scalar _tmp8 = 2 * _self[5];
  const Scalar _tmp9 = _tmp8 - 1;
  const Scalar _tmp10 = -_tmp7 * _tmp9 + 1;
  const Scalar _tmp11 = std::sqrt(Scalar(std::max<Scalar>(_tmp10, epsilon)));
  const Scalar _tmp12 = _self[5] * _tmp11 - _self[5] + 1;
  const Scalar _tmp13 =
      _tmp12 + epsilon * (2 * std::min<Scalar>(0, (((_tmp12) > 0) - ((_tmp12) < 0))) + 1);
  const Scalar _tmp14 = Scalar(1.0) / (_tmp13);
  const Scalar _tmp15 = std::pow(_self[5], Scalar(2));
  const Scalar _tmp16 = -_tmp15 * _tmp7 + 1;
  const Scalar _tmp17 = _tmp14 * _tmp16;
  const Scalar _tmp18 = std::pow(_tmp13, Scalar(-2));
  const Scalar _tmp19 = std::pow(_tmp16, Scalar(2));
  const Scalar _tmp20 = _tmp18 * _tmp19;
  const Scalar _tmp21 = 1 - std::pow(_self[4], Scalar(2));
  const Scalar _tmp22 = _tmp20 + _tmp21 * _tmp7;
  const Scalar _tmp23 = std::sqrt(Scalar(std::max<Scalar>(_tmp22, epsilon)));
  const Scalar _tmp24 = _self[4] * _tmp17 + _tmp23;
  const Scalar _tmp25 = _tmp20 + _tmp7;
  const Scalar _tmp26 =
      _tmp25 + epsilon * (2 * std::min<Scalar>(0, (((_tmp25) > 0) - ((_tmp25) < 0))) + 1);
  const Scalar _tmp27 = Scalar(1.0) / (_tmp26);
  const Scalar _tmp28 = _tmp24 * _tmp27;
  const Scalar _tmp29 = _tmp1 * _tmp28;
  const Scalar _tmp30 = Scalar(1.0) / (_self[1]);
  const Scalar _tmp31 = _tmp28 * _tmp30;
  const Scalar _tmp32 = _tmp2 / [&]() {
    const Scalar base = _self[0];
    return base * base * base;
  }();
  const Scalar _tmp33 = 2 * _tmp32;
  const Scalar _tmp34 = _self[5] * _tmp9;
  const Scalar _tmp35 = _tmp19 / [&]() {
    const Scalar base = _tmp13;
    return base * base * base;
  }();
  const Scalar _tmp36 = -epsilon;
  const Scalar _tmp37 = ((((_tmp10 + _tmp36) > 0) - ((_tmp10 + _tmp36) < 0)) + 1) / _tmp11;
  const Scalar _tmp38 = _tmp35 * _tmp37;
  const Scalar _tmp39 = _tmp34 * _tmp38;
  const Scalar _tmp40 = _tmp16 * _tmp18;
  const Scalar _tmp41 = 4 * _tmp40;
  const Scalar _tmp42 = _tmp15 * _tmp41;
  const Scalar _tmp43 = -_tmp32 * _tmp39 + _tmp32 * _tmp42;
  const Scalar _tmp44 = ((((_tmp22 + _tmp36) > 0) - ((_tmp22 + _tmp36) < 0)) + 1) / _tmp23;
  const Scalar _tmp45 = (Scalar(1) / Scalar(4)) * _tmp44;
  const Scalar _tmp46 = (Scalar(1) / Scalar(2)) * _tmp37;
  const Scalar _tmp47 = _tmp40 * _tmp46;
  const Scalar _tmp48 = _self[4] * _tmp47;
  const Scalar _tmp49 = _tmp34 * _tmp48;
  const Scalar _tmp50 = _tmp14 * _tmp15;
  const Scalar _tmp51 = _self[4] * _tmp50;
  const Scalar _tmp52 =
      _tmp27 * (-_tmp32 * _tmp49 + _tmp33 * _tmp51 + _tmp45 * (-_tmp21 * _tmp33 + _tmp43));
  const Scalar _tmp53 = _tmp0 * _tmp1;
  const Scalar _tmp54 = -_tmp33 + _tmp43;
  const Scalar _tmp55 = _tmp24 / std::pow(_tmp26, Scalar(2));
  const Scalar _tmp56 = _tmp53 * _tmp55;
  const Scalar _tmp57 = _tmp0 * _tmp3;
  const Scalar _tmp58 = _tmp28 * _tmp57;
  const Scalar _tmp59 = _tmp30 * _tmp4;
  const Scalar _tmp60 = _tmp55 * _tmp59;
  const Scalar _tmp61 = _tmp28 * _tmp50;
  const Scalar _tmp62 = _tmp17 * _tmp55;
  const Scalar _tmp63 = _tmp34 * _tmp47;
  const Scalar _tmp64 = _tmp5 / [&]() {
    const Scalar base = _self[1];
    return base * base * base;
  }();
  const Scalar _tmp65 = 2 * _tmp64;
  const Scalar _tmp66 = _tmp34 * _tmp64;
  const Scalar _tmp67 = -_tmp38 * _tmp66 + _tmp42 * _tmp64;
  const Scalar _tmp68 = _tmp45 * (-_tmp21 * _tmp65 + _tmp67) - _tmp48 * _tmp66 + _tmp51 * _tmp65;
  const Scalar _tmp69 = _tmp27 * _tmp68;
  const Scalar _tmp70 = -_tmp65 + _tmp67;
  const Scalar _tmp71 = _tmp4 * _tmp6;
  const Scalar _tmp72 = _tmp28 * _tmp71;
  const Scalar _tmp73 = _tmp17 * _tmp27;
  const Scalar _tmp74 = 2 * _tmp57;
  const Scalar _tmp75 = _tmp21 * _tmp74;
  const Scalar _tmp76 = _tmp39 * _tmp57;
  const Scalar _tmp77 = _tmp42 * _tmp57;
  const Scalar _tmp78 = -_tmp76 + _tmp77;
  const Scalar _tmp79 = _tmp49 * _tmp57;
  const Scalar _tmp80 = _tmp51 * _tmp74;
  const Scalar _tmp81 = _tmp45 * (-_tmp75 + _tmp78) - _tmp79 + _tmp80;
  const Scalar _tmp82 = _tmp27 * _tmp81;
  const Scalar _tmp83 = -_tmp74 + _tmp78;
  const Scalar _tmp84 = _tmp61 * _tmp74;
  const Scalar _tmp85 = _tmp58 * _tmp63;
  const Scalar _tmp86 = 2 * _tmp71;
  const Scalar _tmp87 = _tmp39 * _tmp71;
  const Scalar _tmp88 = _tmp42 * _tmp71;
  const Scalar _tmp89 = -_tmp87 + _tmp88;
  const Scalar _tmp90 = -_tmp86 + _tmp89;
  const Scalar _tmp91 = _tmp21 * _tmp86;
  const Scalar _tmp92 = _tmp49 * _tmp71;
  const Scalar _tmp93 = _tmp51 * _tmp86;
  const Scalar _tmp94 = _tmp45 * (_tmp89 - _tmp91) - _tmp92 + _tmp93;
  const Scalar _tmp95 = _tmp27 * _tmp94;
  const Scalar _tmp96 = _tmp61 * _tmp86;
  const Scalar _tmp97 = _tmp63 * _tmp72;
  const Scalar _tmp98 = _self[4] * _tmp7;
  const Scalar _tmp99 = _tmp17 - Scalar(1) / Scalar(2) * _tmp44 * _tmp98;
  const Scalar _tmp100 = _tmp27 * _tmp99;
  const Scalar _tmp101 = _self[5] * _tmp7;
  const Scalar _tmp102 = -_tmp101 * _tmp46 + _tmp11 - 1;
  const Scalar _tmp103 = -_tmp101 * _tmp41 - 2 * _tmp102 * _tmp35;
  const Scalar _tmp104 = _tmp103 * _tmp55;
  const Scalar _tmp105 = _tmp14 * _tmp8;
  const Scalar _tmp106 = _tmp102 * _tmp40;
  const Scalar _tmp107 = -_self[4] * _tmp106 + _tmp103 * _tmp45 - _tmp105 * _tmp98;
  const Scalar _tmp108 = _tmp107 * _tmp27;
  const Scalar _tmp109 = _tmp76 - _tmp77;
  const Scalar _tmp110 = _tmp45 * (_tmp109 + _tmp75) + _tmp79 - _tmp80;
  const Scalar _tmp111 = _tmp110 * _tmp27;
  const Scalar _tmp112 = _tmp109 + _tmp74;
  const Scalar _tmp113 = _tmp87 - _tmp88;
  const Scalar _tmp114 = _tmp113 + _tmp86;
  const Scalar _tmp115 = _tmp45 * (_tmp113 + _tmp91) + _tmp92 - _tmp93;
  const Scalar _tmp116 = _tmp115 * _tmp27;

  // Output terms (4)
  Eigen::Matrix<Scalar, 3, 1> _camera_ray;

  _camera_ray(0, 0) = _tmp0 * _tmp29;
  _camera_ray(1, 0) = _tmp31 * _tmp4;
  _camera_ray(2, 0) = -_self[4] + _tmp17 * _tmp28;

  if (is_valid != nullptr) {
    Scalar& _is_valid = (*is_valid);

    _is_valid = std::min<Scalar>(1 - std::max<Scalar>(0, -(((_tmp10) > 0) - ((_tmp10) < 0))),
                                 1 - std::max<Scalar>(0, -(((_tmp22) > 0) - ((_tmp22) < 0))));
  }

  if (point_D_cal != nullptr) {
    Eigen::Matrix<Scalar, 3, 6>& _point_D_cal = (*point_D_cal);

    _point_D_cal(0, 0) = _tmp52 * _tmp53 - _tmp54 * _tmp56 - _tmp58;
    _point_D_cal(1, 0) = _tmp52 * _tmp59 - _tmp54 * _tmp60;
    _point_D_cal(2, 0) =
        _tmp17 * _tmp52 - _tmp28 * _tmp32 * _tmp63 + _tmp33 * _tmp61 - _tmp54 * _tmp62;
    _point_D_cal(0, 1) = _tmp53 * _tmp69 - _tmp56 * _tmp70;
    _point_D_cal(1, 1) = _tmp59 * _tmp69 - _tmp60 * _tmp70 - _tmp72;
    _point_D_cal(2, 1) =
        -_tmp28 * _tmp47 * _tmp66 + _tmp61 * _tmp65 - _tmp62 * _tmp70 + _tmp68 * _tmp73;
    _point_D_cal(0, 2) = -_tmp29 + _tmp53 * _tmp82 - _tmp56 * _tmp83;
    _point_D_cal(1, 2) = _tmp59 * _tmp82 - _tmp60 * _tmp83;
    _point_D_cal(2, 2) = -_tmp62 * _tmp83 + _tmp73 * _tmp81 + _tmp84 - _tmp85;
    _point_D_cal(0, 3) = _tmp53 * _tmp95 - _tmp56 * _tmp90;
    _point_D_cal(1, 3) = -_tmp31 + _tmp59 * _tmp95 - _tmp60 * _tmp90;
    _point_D_cal(2, 3) = -_tmp62 * _tmp90 + _tmp73 * _tmp94 + _tmp96 - _tmp97;
    _point_D_cal(0, 4) = _tmp100 * _tmp53;
    _point_D_cal(1, 4) = _tmp100 * _tmp59;
    _point_D_cal(2, 4) = _tmp73 * _tmp99 - 1;
    _point_D_cal(0, 5) = -_tmp104 * _tmp53 + _tmp108 * _tmp53;
    _point_D_cal(1, 5) = -_tmp103 * _tmp60 + _tmp108 * _tmp59;
    _point_D_cal(2, 5) =
        -_tmp104 * _tmp17 - _tmp105 * _tmp28 * _tmp7 - _tmp106 * _tmp28 + _tmp107 * _tmp73;
  }

  if (point_D_pixel != nullptr) {
    Eigen::Matrix<Scalar, 3, 2>& _point_D_pixel = (*point_D_pixel);

    _point_D_pixel(0, 0) = _tmp111 * _tmp53 - _tmp112 * _tmp56 + _tmp29;
    _point_D_pixel(1, 0) = _tmp111 * _tmp59 - _tmp112 * _tmp60;
    _point_D_pixel(2, 0) = _tmp110 * _tmp73 - _tmp112 * _tmp62 - _tmp84 + _tmp85;
    _point_D_pixel(0, 1) = -_tmp114 * _tmp56 + _tmp116 * _tmp53;
    _point_D_pixel(1, 1) = -_tmp114 * _tmp60 + _tmp116 * _tmp59 + _tmp31;
    _point_D_pixel(2, 1) = -_tmp114 * _tmp62 + _tmp115 * _tmp73 - _tmp96 + _tmp97;
  }

  return _camera_ray;
}

// Print implementations
std::ostream& operator<<(std::ostream& os, const DoubleSphereCameraCald& a) {
  const Eigen::IOFormat fmt(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n", "[", "]");
  os << "<DoubleSphereCameraCald " << a.Data().transpose().format(fmt) << ">";
  return os;
}

std::ostream& operator<<(std::ostream& os, const DoubleSphereCameraCalf& a) {
  const Eigen::IOFormat fmt(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n", "[", "]");
  os << "<DoubleSphereCameraCalf " << a.Data().transpose().format(fmt) << ">";
  return os;
}

}  // namespace sym

// Concept implementations for this class
#include "./ops/double_sphere_camera_cal/storage_ops.h"

// Explicit instantiation
template class sym::DoubleSphereCameraCal<double>;
template class sym::DoubleSphereCameraCal<float>;
