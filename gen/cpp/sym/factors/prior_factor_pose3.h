// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Core>

#include <sym/pose3.h>

namespace sym {

/**
 * Residual that penalizes the difference between a value and prior (desired / measured value).
 *
 * In vector space terms that would be:
 *     prior - value
 *
 * In lie group terms:
 *     to_tangent(compose(inverse(value), prior))
 *
 * Args:
 *     sqrt_info: Square root information matrix to whiten residual. This can be computed from
 *                a covariance matrix as the cholesky decomposition of the inverse. In the case
 *                of a diagonal it will contain 1/sigma values. Must match the tangent dim.
 *     jacobian: (6x6) jacobian of res wrt arg value (6)
 *     hessian: (6x6) Gauss-Newton hessian for arg value (6)
 *     rhs: (6x1) Gauss-Newton rhs for arg value (6)
 */
template <typename Scalar>
void PriorFactorPose3(const sym::Pose3<Scalar>& value, const sym::Pose3<Scalar>& prior,
                      const Eigen::Matrix<Scalar, 6, 6>& sqrt_info, const Scalar epsilon,
                      Eigen::Matrix<Scalar, 6, 1>* const res = nullptr,
                      Eigen::Matrix<Scalar, 6, 6>* const jacobian = nullptr,
                      Eigen::Matrix<Scalar, 6, 6>* const hessian = nullptr,
                      Eigen::Matrix<Scalar, 6, 1>* const rhs = nullptr) {
  // Total ops: 826

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _value = value.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _prior = prior.Data();

  // Intermediate terms (132)
  const Scalar _tmp0 = _prior[2] * _value[3];
  const Scalar _tmp1 = _prior[1] * _value[0];
  const Scalar _tmp2 = _prior[0] * _value[1];
  const Scalar _tmp3 = _prior[3] * _value[2];
  const Scalar _tmp4 = -_tmp0 + _tmp1 - _tmp2 + _tmp3;
  const Scalar _tmp5 = _prior[3] * _value[3];
  const Scalar _tmp6 = _prior[2] * _value[2];
  const Scalar _tmp7 = _prior[1] * _value[1];
  const Scalar _tmp8 = _prior[0] * _value[0];
  const Scalar _tmp9 = -_tmp6 - _tmp7 - _tmp8;
  const Scalar _tmp10 = _tmp5 - _tmp9;
  const Scalar _tmp11 = 2 * std::min<Scalar>(0, (((_tmp10) > 0) - ((_tmp10) < 0))) + 1;
  const Scalar _tmp12 = 2 * _tmp11;
  const Scalar _tmp13 = 1 - epsilon;
  const Scalar _tmp14 = std::min<Scalar>(_tmp13, std::fabs(_tmp10));
  const Scalar _tmp15 = std::acos(_tmp14) / std::sqrt(Scalar(1 - std::pow(_tmp14, Scalar(2))));
  const Scalar _tmp16 = _tmp12 * _tmp15;
  const Scalar _tmp17 = _tmp16 * _tmp4;
  const Scalar _tmp18 = -_prior[6] + _value[6];
  const Scalar _tmp19 = -_prior[5] + _value[5];
  const Scalar _tmp20 = -_prior[4] + _value[4];
  const Scalar _tmp21 = _prior[2] * _value[0];
  const Scalar _tmp22 = _prior[1] * _value[3];
  const Scalar _tmp23 = _prior[0] * _value[2];
  const Scalar _tmp24 = _prior[3] * _value[1];
  const Scalar _tmp25 = -_tmp21 - _tmp22 + _tmp23 + _tmp24;
  const Scalar _tmp26 = _tmp16 * _tmp25;
  const Scalar _tmp27 = _prior[2] * _value[1];
  const Scalar _tmp28 = _prior[1] * _value[2];
  const Scalar _tmp29 = _prior[0] * _value[3];
  const Scalar _tmp30 = _prior[3] * _value[0];
  const Scalar _tmp31 = _tmp27 - _tmp28 - _tmp29 + _tmp30;
  const Scalar _tmp32 = _tmp16 * _tmp31;
  const Scalar _tmp33 = _tmp17 * sqrt_info(0, 2) + _tmp18 * sqrt_info(0, 5) +
                        _tmp19 * sqrt_info(0, 4) + _tmp20 * sqrt_info(0, 3) +
                        _tmp26 * sqrt_info(0, 1) + _tmp32 * sqrt_info(0, 0);
  const Scalar _tmp34 = _tmp17 * sqrt_info(1, 2) + _tmp18 * sqrt_info(1, 5) +
                        _tmp19 * sqrt_info(1, 4) + _tmp20 * sqrt_info(1, 3) +
                        _tmp26 * sqrt_info(1, 1) + _tmp32 * sqrt_info(1, 0);
  const Scalar _tmp35 = _tmp17 * sqrt_info(2, 2) + _tmp18 * sqrt_info(2, 5) +
                        _tmp19 * sqrt_info(2, 4) + _tmp20 * sqrt_info(2, 3) +
                        _tmp26 * sqrt_info(2, 1) + _tmp32 * sqrt_info(2, 0);
  const Scalar _tmp36 = _tmp17 * sqrt_info(3, 2) + _tmp18 * sqrt_info(3, 5) +
                        _tmp19 * sqrt_info(3, 4) + _tmp20 * sqrt_info(3, 3) +
                        _tmp26 * sqrt_info(3, 1) + _tmp32 * sqrt_info(3, 0);
  const Scalar _tmp37 = _tmp31 * sqrt_info(4, 0);
  const Scalar _tmp38 = _tmp16 * _tmp37 + _tmp17 * sqrt_info(4, 2) + _tmp18 * sqrt_info(4, 5) +
                        _tmp19 * sqrt_info(4, 4) + _tmp20 * sqrt_info(4, 3) +
                        _tmp26 * sqrt_info(4, 1);
  const Scalar _tmp39 = _tmp12 * sqrt_info(5, 2);
  const Scalar _tmp40 = _tmp15 * _tmp39 * _tmp4 + _tmp18 * sqrt_info(5, 5) +
                        _tmp19 * sqrt_info(5, 4) + _tmp20 * sqrt_info(5, 3) +
                        _tmp26 * sqrt_info(5, 1) + _tmp32 * sqrt_info(5, 0);
  const Scalar _tmp41 = (Scalar(1) / Scalar(2)) * _tmp27;
  const Scalar _tmp42 = (Scalar(1) / Scalar(2)) * _tmp28;
  const Scalar _tmp43 = (Scalar(1) / Scalar(2)) * _tmp29;
  const Scalar _tmp44 = (Scalar(1) / Scalar(2)) * _tmp30;
  const Scalar _tmp45 = _tmp41 - _tmp42 - _tmp43 + _tmp44;
  const Scalar _tmp46 = std::fabs(_tmp5 + _tmp6 + _tmp7 + _tmp8);
  const Scalar _tmp47 = std::min<Scalar>(_tmp13, _tmp46);
  const Scalar _tmp48 = 1 - std::pow(_tmp47, Scalar(2));
  const Scalar _tmp49 = _tmp11 * ((((_tmp13 - _tmp46) > 0) - ((_tmp13 - _tmp46) < 0)) + 1) *
                        (((-_tmp5 + _tmp9) > 0) - ((-_tmp5 + _tmp9) < 0));
  const Scalar _tmp50 = _tmp49 / _tmp48;
  const Scalar _tmp51 = _tmp45 * _tmp50;
  const Scalar _tmp52 = _tmp31 * _tmp51;
  const Scalar _tmp53 = std::acos(_tmp47);
  const Scalar _tmp54 = _tmp45 * _tmp53;
  const Scalar _tmp55 = _tmp47 * _tmp49 / (_tmp48 * std::sqrt(_tmp48));
  const Scalar _tmp56 = _tmp31 * _tmp55;
  const Scalar _tmp57 = _tmp56 * sqrt_info(0, 0);
  const Scalar _tmp58 = (Scalar(1) / Scalar(2)) * _tmp21;
  const Scalar _tmp59 = (Scalar(1) / Scalar(2)) * _tmp22;
  const Scalar _tmp60 = (Scalar(1) / Scalar(2)) * _tmp23;
  const Scalar _tmp61 = (Scalar(1) / Scalar(2)) * _tmp24;
  const Scalar _tmp62 = _tmp58 + _tmp59 - _tmp60 - _tmp61;
  const Scalar _tmp63 = std::pow(_tmp48, Scalar(Scalar(-1) / Scalar(2)));
  const Scalar _tmp64 = _tmp12 * _tmp63;
  const Scalar _tmp65 = _tmp53 * _tmp64;
  const Scalar _tmp66 = _tmp62 * _tmp65;
  const Scalar _tmp67 = _tmp25 * _tmp51;
  const Scalar _tmp68 = (Scalar(1) / Scalar(2)) * _tmp5 + (Scalar(1) / Scalar(2)) * _tmp6 +
                        (Scalar(1) / Scalar(2)) * _tmp7 + (Scalar(1) / Scalar(2)) * _tmp8;
  const Scalar _tmp69 = _tmp65 * _tmp68;
  const Scalar _tmp70 = _tmp54 * _tmp55;
  const Scalar _tmp71 = _tmp25 * sqrt_info(0, 1);
  const Scalar _tmp72 = _tmp4 * _tmp70;
  const Scalar _tmp73 = _tmp4 * _tmp51;
  const Scalar _tmp74 = (Scalar(1) / Scalar(2)) * _tmp0;
  const Scalar _tmp75 = (Scalar(1) / Scalar(2)) * _tmp1;
  const Scalar _tmp76 = (Scalar(1) / Scalar(2)) * _tmp2;
  const Scalar _tmp77 = (Scalar(1) / Scalar(2)) * _tmp3;
  const Scalar _tmp78 = -_tmp74 + _tmp75 - _tmp76 + _tmp77;
  const Scalar _tmp79 = _tmp65 * _tmp78;
  const Scalar _tmp80 = -_tmp52 * sqrt_info(0, 0) + _tmp54 * _tmp57 + _tmp66 * sqrt_info(0, 2) -
                        _tmp67 * sqrt_info(0, 1) + _tmp69 * sqrt_info(0, 0) + _tmp70 * _tmp71 +
                        _tmp72 * sqrt_info(0, 2) - _tmp73 * sqrt_info(0, 2) +
                        _tmp79 * sqrt_info(0, 1);
  const Scalar _tmp81 = _tmp31 * sqrt_info(1, 0);
  const Scalar _tmp82 = _tmp25 * sqrt_info(1, 1);
  const Scalar _tmp83 = -_tmp51 * _tmp81 + _tmp66 * sqrt_info(1, 2) - _tmp67 * sqrt_info(1, 1) +
                        _tmp69 * sqrt_info(1, 0) + _tmp70 * _tmp81 + _tmp70 * _tmp82 +
                        _tmp72 * sqrt_info(1, 2) - _tmp73 * sqrt_info(1, 2) +
                        _tmp79 * sqrt_info(1, 1);
  const Scalar _tmp84 = _tmp56 * sqrt_info(2, 0);
  const Scalar _tmp85 = _tmp25 * sqrt_info(2, 1);
  const Scalar _tmp86 = -_tmp52 * sqrt_info(2, 0) + _tmp54 * _tmp84 + _tmp66 * sqrt_info(2, 2) -
                        _tmp67 * sqrt_info(2, 1) + _tmp69 * sqrt_info(2, 0) + _tmp70 * _tmp85 +
                        _tmp72 * sqrt_info(2, 2) - _tmp73 * sqrt_info(2, 2) +
                        _tmp79 * sqrt_info(2, 1);
  const Scalar _tmp87 = _tmp56 * sqrt_info(3, 0);
  const Scalar _tmp88 = _tmp25 * sqrt_info(3, 1);
  const Scalar _tmp89 = -_tmp52 * sqrt_info(3, 0) + _tmp54 * _tmp87 + _tmp66 * sqrt_info(3, 2) -
                        _tmp67 * sqrt_info(3, 1) + _tmp69 * sqrt_info(3, 0) + _tmp70 * _tmp88 +
                        _tmp72 * sqrt_info(3, 2) - _tmp73 * sqrt_info(3, 2) +
                        _tmp79 * sqrt_info(3, 1);
  const Scalar _tmp90 = _tmp25 * sqrt_info(4, 1);
  const Scalar _tmp91 = -_tmp37 * _tmp51 + _tmp37 * _tmp70 - _tmp51 * _tmp90 +
                        _tmp66 * sqrt_info(4, 2) + _tmp69 * sqrt_info(4, 0) + _tmp70 * _tmp90 +
                        _tmp72 * sqrt_info(4, 2) - _tmp73 * sqrt_info(4, 2) +
                        _tmp79 * sqrt_info(4, 1);
  const Scalar _tmp92 = _tmp56 * sqrt_info(5, 0);
  const Scalar _tmp93 = _tmp39 * _tmp63;
  const Scalar _tmp94 = _tmp53 * _tmp93;
  const Scalar _tmp95 = _tmp25 * sqrt_info(5, 1);
  const Scalar _tmp96 = -_tmp51 * _tmp95 - _tmp52 * sqrt_info(5, 0) + _tmp54 * _tmp92 +
                        _tmp62 * _tmp94 + _tmp69 * sqrt_info(5, 0) + _tmp70 * _tmp95 +
                        _tmp72 * sqrt_info(5, 2) - _tmp73 * sqrt_info(5, 2) +
                        _tmp79 * sqrt_info(5, 1);
  const Scalar _tmp97 = -_tmp58 - _tmp59 + _tmp60 + _tmp61;
  const Scalar _tmp98 = _tmp50 * _tmp97;
  const Scalar _tmp99 = _tmp31 * _tmp98;
  const Scalar _tmp100 = _tmp25 * _tmp98;
  const Scalar _tmp101 = _tmp4 * _tmp98;
  const Scalar _tmp102 = _tmp53 * _tmp97;
  const Scalar _tmp103 = _tmp102 * _tmp55;
  const Scalar _tmp104 = _tmp103 * _tmp4;
  const Scalar _tmp105 = _tmp102 * _tmp56;
  const Scalar _tmp106 = _tmp54 * _tmp64;
  const Scalar _tmp107 = _tmp65 * (_tmp74 - _tmp75 + _tmp76 - _tmp77);
  const Scalar _tmp108 = -_tmp100 * sqrt_info(0, 1) - _tmp101 * sqrt_info(0, 2) + _tmp103 * _tmp71 +
                         _tmp104 * sqrt_info(0, 2) + _tmp105 * sqrt_info(0, 0) +
                         _tmp106 * sqrt_info(0, 2) + _tmp107 * sqrt_info(0, 0) +
                         _tmp69 * sqrt_info(0, 1) - _tmp99 * sqrt_info(0, 0);
  const Scalar _tmp109 = -_tmp101 * sqrt_info(1, 2) + _tmp103 * _tmp81 + _tmp103 * _tmp82 +
                         _tmp104 * sqrt_info(1, 2) + _tmp106 * sqrt_info(1, 2) +
                         _tmp107 * sqrt_info(1, 0) + _tmp69 * sqrt_info(1, 1) - _tmp81 * _tmp98 -
                         _tmp82 * _tmp98;
  const Scalar _tmp110 = -_tmp100 * sqrt_info(2, 1) - _tmp101 * sqrt_info(2, 2) + _tmp103 * _tmp85 +
                         _tmp104 * sqrt_info(2, 2) + _tmp105 * sqrt_info(2, 0) +
                         _tmp106 * sqrt_info(2, 2) + _tmp107 * sqrt_info(2, 0) +
                         _tmp69 * sqrt_info(2, 1) - _tmp99 * sqrt_info(2, 0);
  const Scalar _tmp111 = -_tmp100 * sqrt_info(3, 1) - _tmp101 * sqrt_info(3, 2) + _tmp102 * _tmp87 +
                         _tmp103 * _tmp88 + _tmp104 * sqrt_info(3, 2) + _tmp106 * sqrt_info(3, 2) +
                         _tmp107 * sqrt_info(3, 0) + _tmp69 * sqrt_info(3, 1) -
                         _tmp99 * sqrt_info(3, 0);
  const Scalar _tmp112 = _tmp97 * sqrt_info(4, 0);
  const Scalar _tmp113 = _tmp112 * _tmp31;
  const Scalar _tmp114 = _tmp53 * _tmp55;
  const Scalar _tmp115 = -_tmp101 * sqrt_info(4, 2) + _tmp103 * _tmp90 + _tmp104 * sqrt_info(4, 2) +
                         _tmp106 * sqrt_info(4, 2) + _tmp107 * sqrt_info(4, 0) + _tmp113 * _tmp114 -
                         _tmp113 * _tmp50 + _tmp69 * sqrt_info(4, 1) - _tmp90 * _tmp98;
  const Scalar _tmp116 = -_tmp101 * sqrt_info(5, 2) + _tmp103 * _tmp95 + _tmp104 * sqrt_info(5, 2) +
                         _tmp105 * sqrt_info(5, 0) + _tmp107 * sqrt_info(5, 0) + _tmp54 * _tmp93 +
                         _tmp69 * sqrt_info(5, 1) - _tmp95 * _tmp98 - _tmp99 * sqrt_info(5, 0);
  const Scalar _tmp117 = _tmp114 * _tmp78;
  const Scalar _tmp118 = _tmp50 * _tmp78;
  const Scalar _tmp119 = _tmp118 * _tmp31;
  const Scalar _tmp120 = _tmp118 * _tmp25;
  const Scalar _tmp121 = _tmp118 * _tmp4;
  const Scalar _tmp122 = _tmp65 * (-_tmp41 + _tmp42 + _tmp43 - _tmp44);
  const Scalar _tmp123 = _tmp65 * _tmp97;
  const Scalar _tmp124 = _tmp53 * _tmp78;
  const Scalar _tmp125 = _tmp117 * _tmp4;
  const Scalar _tmp126 = _tmp117 * _tmp71 - _tmp119 * sqrt_info(0, 0) - _tmp120 * sqrt_info(0, 1) -
                         _tmp121 * sqrt_info(0, 2) + _tmp122 * sqrt_info(0, 1) +
                         _tmp123 * sqrt_info(0, 0) + _tmp124 * _tmp57 + _tmp125 * sqrt_info(0, 2) +
                         _tmp69 * sqrt_info(0, 2);
  const Scalar _tmp127 = _tmp117 * _tmp81 + _tmp117 * _tmp82 - _tmp118 * _tmp81 - _tmp118 * _tmp82 -
                         _tmp121 * sqrt_info(1, 2) + _tmp122 * sqrt_info(1, 1) +
                         _tmp123 * sqrt_info(1, 0) + _tmp125 * sqrt_info(1, 2) +
                         _tmp69 * sqrt_info(1, 2);
  const Scalar _tmp128 = _tmp117 * _tmp85 - _tmp119 * sqrt_info(2, 0) - _tmp120 * sqrt_info(2, 1) -
                         _tmp121 * sqrt_info(2, 2) + _tmp122 * sqrt_info(2, 1) +
                         _tmp123 * sqrt_info(2, 0) + _tmp124 * _tmp84 + _tmp125 * sqrt_info(2, 2) +
                         _tmp69 * sqrt_info(2, 2);
  const Scalar _tmp129 = _tmp117 * _tmp88 - _tmp119 * sqrt_info(3, 0) - _tmp120 * sqrt_info(3, 1) -
                         _tmp121 * sqrt_info(3, 2) + _tmp122 * sqrt_info(3, 1) +
                         _tmp123 * sqrt_info(3, 0) + _tmp124 * _tmp87 + _tmp125 * sqrt_info(3, 2) +
                         _tmp69 * sqrt_info(3, 2);
  const Scalar _tmp130 = _tmp112 * _tmp65 + _tmp117 * _tmp37 + _tmp117 * _tmp90 - _tmp118 * _tmp37 -
                         _tmp118 * _tmp90 - _tmp121 * sqrt_info(4, 2) + _tmp122 * sqrt_info(4, 1) +
                         _tmp125 * sqrt_info(4, 2) + _tmp69 * sqrt_info(4, 2);
  const Scalar _tmp131 = _tmp117 * _tmp95 - _tmp118 * _tmp95 - _tmp119 * sqrt_info(5, 0) -
                         _tmp121 * sqrt_info(5, 2) + _tmp122 * sqrt_info(5, 1) +
                         _tmp123 * sqrt_info(5, 0) + _tmp124 * _tmp92 + _tmp125 * sqrt_info(5, 2) +
                         _tmp68 * _tmp94;

  // Output terms (4)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 6, 1>& _res = (*res);

    _res(0, 0) = _tmp33;
    _res(1, 0) = _tmp34;
    _res(2, 0) = _tmp35;
    _res(3, 0) = _tmp36;
    _res(4, 0) = _tmp38;
    _res(5, 0) = _tmp40;
  }

  if (jacobian != nullptr) {
    Eigen::Matrix<Scalar, 6, 6>& _jacobian = (*jacobian);

    _jacobian(0, 0) = _tmp80;
    _jacobian(1, 0) = _tmp83;
    _jacobian(2, 0) = _tmp86;
    _jacobian(3, 0) = _tmp89;
    _jacobian(4, 0) = _tmp91;
    _jacobian(5, 0) = _tmp96;
    _jacobian(0, 1) = _tmp108;
    _jacobian(1, 1) = _tmp109;
    _jacobian(2, 1) = _tmp110;
    _jacobian(3, 1) = _tmp111;
    _jacobian(4, 1) = _tmp115;
    _jacobian(5, 1) = _tmp116;
    _jacobian(0, 2) = _tmp126;
    _jacobian(1, 2) = _tmp127;
    _jacobian(2, 2) = _tmp128;
    _jacobian(3, 2) = _tmp129;
    _jacobian(4, 2) = _tmp130;
    _jacobian(5, 2) = _tmp131;
    _jacobian(0, 3) = sqrt_info(0, 3);
    _jacobian(1, 3) = sqrt_info(1, 3);
    _jacobian(2, 3) = sqrt_info(2, 3);
    _jacobian(3, 3) = sqrt_info(3, 3);
    _jacobian(4, 3) = sqrt_info(4, 3);
    _jacobian(5, 3) = sqrt_info(5, 3);
    _jacobian(0, 4) = sqrt_info(0, 4);
    _jacobian(1, 4) = sqrt_info(1, 4);
    _jacobian(2, 4) = sqrt_info(2, 4);
    _jacobian(3, 4) = sqrt_info(3, 4);
    _jacobian(4, 4) = sqrt_info(4, 4);
    _jacobian(5, 4) = sqrt_info(5, 4);
    _jacobian(0, 5) = sqrt_info(0, 5);
    _jacobian(1, 5) = sqrt_info(1, 5);
    _jacobian(2, 5) = sqrt_info(2, 5);
    _jacobian(3, 5) = sqrt_info(3, 5);
    _jacobian(4, 5) = sqrt_info(4, 5);
    _jacobian(5, 5) = sqrt_info(5, 5);
  }

  if (hessian != nullptr) {
    Eigen::Matrix<Scalar, 6, 6>& _hessian = (*hessian);

    _hessian(0, 0) = std::pow(_tmp80, Scalar(2)) + std::pow(_tmp83, Scalar(2)) +
                     std::pow(_tmp86, Scalar(2)) + std::pow(_tmp89, Scalar(2)) +
                     std::pow(_tmp91, Scalar(2)) + std::pow(_tmp96, Scalar(2));
    _hessian(1, 0) = _tmp108 * _tmp80 + _tmp109 * _tmp83 + _tmp110 * _tmp86 + _tmp111 * _tmp89 +
                     _tmp115 * _tmp91 + _tmp116 * _tmp96;
    _hessian(2, 0) = _tmp126 * _tmp80 + _tmp127 * _tmp83 + _tmp128 * _tmp86 + _tmp129 * _tmp89 +
                     _tmp130 * _tmp91 + _tmp131 * _tmp96;
    _hessian(3, 0) = _tmp80 * sqrt_info(0, 3) + _tmp83 * sqrt_info(1, 3) +
                     _tmp86 * sqrt_info(2, 3) + _tmp89 * sqrt_info(3, 3) +
                     _tmp91 * sqrt_info(4, 3) + _tmp96 * sqrt_info(5, 3);
    _hessian(4, 0) = _tmp80 * sqrt_info(0, 4) + _tmp83 * sqrt_info(1, 4) +
                     _tmp86 * sqrt_info(2, 4) + _tmp89 * sqrt_info(3, 4) +
                     _tmp91 * sqrt_info(4, 4) + _tmp96 * sqrt_info(5, 4);
    _hessian(5, 0) = _tmp80 * sqrt_info(0, 5) + _tmp83 * sqrt_info(1, 5) +
                     _tmp86 * sqrt_info(2, 5) + _tmp89 * sqrt_info(3, 5) +
                     _tmp91 * sqrt_info(4, 5) + _tmp96 * sqrt_info(5, 5);
    _hessian(0, 1) = 0;
    _hessian(1, 1) = std::pow(_tmp108, Scalar(2)) + std::pow(_tmp109, Scalar(2)) +
                     std::pow(_tmp110, Scalar(2)) + std::pow(_tmp111, Scalar(2)) +
                     std::pow(_tmp115, Scalar(2)) + std::pow(_tmp116, Scalar(2));
    _hessian(2, 1) = _tmp108 * _tmp126 + _tmp109 * _tmp127 + _tmp110 * _tmp128 + _tmp111 * _tmp129 +
                     _tmp115 * _tmp130 + _tmp116 * _tmp131;
    _hessian(3, 1) = _tmp108 * sqrt_info(0, 3) + _tmp109 * sqrt_info(1, 3) +
                     _tmp110 * sqrt_info(2, 3) + _tmp111 * sqrt_info(3, 3) +
                     _tmp115 * sqrt_info(4, 3) + _tmp116 * sqrt_info(5, 3);
    _hessian(4, 1) = _tmp108 * sqrt_info(0, 4) + _tmp109 * sqrt_info(1, 4) +
                     _tmp110 * sqrt_info(2, 4) + _tmp111 * sqrt_info(3, 4) +
                     _tmp115 * sqrt_info(4, 4) + _tmp116 * sqrt_info(5, 4);
    _hessian(5, 1) = _tmp108 * sqrt_info(0, 5) + _tmp109 * sqrt_info(1, 5) +
                     _tmp110 * sqrt_info(2, 5) + _tmp111 * sqrt_info(3, 5) +
                     _tmp115 * sqrt_info(4, 5) + _tmp116 * sqrt_info(5, 5);
    _hessian(0, 2) = 0;
    _hessian(1, 2) = 0;
    _hessian(2, 2) = std::pow(_tmp126, Scalar(2)) + std::pow(_tmp127, Scalar(2)) +
                     std::pow(_tmp128, Scalar(2)) + std::pow(_tmp129, Scalar(2)) +
                     std::pow(_tmp130, Scalar(2)) + std::pow(_tmp131, Scalar(2));
    _hessian(3, 2) = _tmp126 * sqrt_info(0, 3) + _tmp127 * sqrt_info(1, 3) +
                     _tmp128 * sqrt_info(2, 3) + _tmp129 * sqrt_info(3, 3) +
                     _tmp130 * sqrt_info(4, 3) + _tmp131 * sqrt_info(5, 3);
    _hessian(4, 2) = _tmp126 * sqrt_info(0, 4) + _tmp127 * sqrt_info(1, 4) +
                     _tmp128 * sqrt_info(2, 4) + _tmp129 * sqrt_info(3, 4) +
                     _tmp130 * sqrt_info(4, 4) + _tmp131 * sqrt_info(5, 4);
    _hessian(5, 2) = _tmp126 * sqrt_info(0, 5) + _tmp127 * sqrt_info(1, 5) +
                     _tmp128 * sqrt_info(2, 5) + _tmp129 * sqrt_info(3, 5) +
                     _tmp130 * sqrt_info(4, 5) + _tmp131 * sqrt_info(5, 5);
    _hessian(0, 3) = 0;
    _hessian(1, 3) = 0;
    _hessian(2, 3) = 0;
    _hessian(3, 3) = std::pow(sqrt_info(0, 3), Scalar(2)) + std::pow(sqrt_info(1, 3), Scalar(2)) +
                     std::pow(sqrt_info(2, 3), Scalar(2)) + std::pow(sqrt_info(3, 3), Scalar(2)) +
                     std::pow(sqrt_info(4, 3), Scalar(2)) + std::pow(sqrt_info(5, 3), Scalar(2));
    _hessian(4, 3) = sqrt_info(0, 3) * sqrt_info(0, 4) + sqrt_info(1, 3) * sqrt_info(1, 4) +
                     sqrt_info(2, 3) * sqrt_info(2, 4) + sqrt_info(3, 3) * sqrt_info(3, 4) +
                     sqrt_info(4, 3) * sqrt_info(4, 4) + sqrt_info(5, 3) * sqrt_info(5, 4);
    _hessian(5, 3) = sqrt_info(0, 3) * sqrt_info(0, 5) + sqrt_info(1, 3) * sqrt_info(1, 5) +
                     sqrt_info(2, 3) * sqrt_info(2, 5) + sqrt_info(3, 3) * sqrt_info(3, 5) +
                     sqrt_info(4, 3) * sqrt_info(4, 5) + sqrt_info(5, 3) * sqrt_info(5, 5);
    _hessian(0, 4) = 0;
    _hessian(1, 4) = 0;
    _hessian(2, 4) = 0;
    _hessian(3, 4) = 0;
    _hessian(4, 4) = std::pow(sqrt_info(0, 4), Scalar(2)) + std::pow(sqrt_info(1, 4), Scalar(2)) +
                     std::pow(sqrt_info(2, 4), Scalar(2)) + std::pow(sqrt_info(3, 4), Scalar(2)) +
                     std::pow(sqrt_info(4, 4), Scalar(2)) + std::pow(sqrt_info(5, 4), Scalar(2));
    _hessian(5, 4) = sqrt_info(0, 4) * sqrt_info(0, 5) + sqrt_info(1, 4) * sqrt_info(1, 5) +
                     sqrt_info(2, 4) * sqrt_info(2, 5) + sqrt_info(3, 4) * sqrt_info(3, 5) +
                     sqrt_info(4, 4) * sqrt_info(4, 5) + sqrt_info(5, 4) * sqrt_info(5, 5);
    _hessian(0, 5) = 0;
    _hessian(1, 5) = 0;
    _hessian(2, 5) = 0;
    _hessian(3, 5) = 0;
    _hessian(4, 5) = 0;
    _hessian(5, 5) = std::pow(sqrt_info(0, 5), Scalar(2)) + std::pow(sqrt_info(1, 5), Scalar(2)) +
                     std::pow(sqrt_info(2, 5), Scalar(2)) + std::pow(sqrt_info(3, 5), Scalar(2)) +
                     std::pow(sqrt_info(4, 5), Scalar(2)) + std::pow(sqrt_info(5, 5), Scalar(2));
  }

  if (rhs != nullptr) {
    Eigen::Matrix<Scalar, 6, 1>& _rhs = (*rhs);

    _rhs(0, 0) = _tmp33 * _tmp80 + _tmp34 * _tmp83 + _tmp35 * _tmp86 + _tmp36 * _tmp89 +
                 _tmp38 * _tmp91 + _tmp40 * _tmp96;
    _rhs(1, 0) = _tmp108 * _tmp33 + _tmp109 * _tmp34 + _tmp110 * _tmp35 + _tmp111 * _tmp36 +
                 _tmp115 * _tmp38 + _tmp116 * _tmp40;
    _rhs(2, 0) = _tmp126 * _tmp33 + _tmp127 * _tmp34 + _tmp128 * _tmp35 + _tmp129 * _tmp36 +
                 _tmp130 * _tmp38 + _tmp131 * _tmp40;
    _rhs(3, 0) = _tmp33 * sqrt_info(0, 3) + _tmp34 * sqrt_info(1, 3) + _tmp35 * sqrt_info(2, 3) +
                 _tmp36 * sqrt_info(3, 3) + _tmp38 * sqrt_info(4, 3) + _tmp40 * sqrt_info(5, 3);
    _rhs(4, 0) = _tmp33 * sqrt_info(0, 4) + _tmp34 * sqrt_info(1, 4) + _tmp35 * sqrt_info(2, 4) +
                 _tmp36 * sqrt_info(3, 4) + _tmp38 * sqrt_info(4, 4) + _tmp40 * sqrt_info(5, 4);
    _rhs(5, 0) = _tmp33 * sqrt_info(0, 5) + _tmp34 * sqrt_info(1, 5) + _tmp35 * sqrt_info(2, 5) +
                 _tmp36 * sqrt_info(3, 5) + _tmp38 * sqrt_info(4, 5) + _tmp40 * sqrt_info(5, 5);
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
