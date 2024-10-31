// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Core>

#include <sym/unit3.h>

namespace sym {

/**
 * Residual that penalizes the difference between between(a, b) and a_T_b.
 *
 * In vector space terms that would be:
 *     (b - a) - a_T_b
 *
 * In lie group terms:
 *     local_coordinates(a_T_b, between(a, b))
 *     to_tangent(compose(inverse(a_T_b), compose(inverse(a), b)))
 *
 * Args:
 *     sqrt_info: Square root information matrix to whiten residual. This can be computed from
 *                a covariance matrix as the cholesky decomposition of the inverse. In the case
 *                of a diagonal it will contain 1/sigma values. Must match the tangent dim.
 *     jacobian: (2x4) jacobian of res wrt args a (2), b (2)
 *     hessian: (4x4) Gauss-Newton hessian for args a (2), b (2)
 *     rhs: (4x1) Gauss-Newton rhs for args a (2), b (2)
 */
template <typename Scalar>
void BetweenFactorUnit3(const sym::Unit3<Scalar>& a, const sym::Unit3<Scalar>& b,
                        const sym::Unit3<Scalar>& a_T_b,
                        const Eigen::Matrix<Scalar, 2, 2>& sqrt_info, const Scalar epsilon,
                        Eigen::Matrix<Scalar, 2, 1>* const res = nullptr,
                        Eigen::Matrix<Scalar, 2, 4>* const jacobian = nullptr,
                        Eigen::Matrix<Scalar, 4, 4>* const hessian = nullptr,
                        Eigen::Matrix<Scalar, 4, 1>* const rhs = nullptr) {
  // Total ops: 338

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _b = b.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _a_T_b = a_T_b.Data();

  // Intermediate terms (120)
  const Scalar _tmp0 = _a[3] * _b[3];
  const Scalar _tmp1 = _a[2] * _b[2];
  const Scalar _tmp2 = _a[0] * _b[0];
  const Scalar _tmp3 = _a[1] * _b[1];
  const Scalar _tmp4 = _tmp0 + _tmp1 + _tmp2 + _tmp3;
  const Scalar _tmp5 = _a_T_b[3] * _tmp4;
  const Scalar _tmp6 = _a[3] * _b[1];
  const Scalar _tmp7 = _a[2] * _b[0];
  const Scalar _tmp8 = _a[0] * _b[2];
  const Scalar _tmp9 = _a[1] * _b[3];
  const Scalar _tmp10 = _tmp6 - _tmp7 + _tmp8 - _tmp9;
  const Scalar _tmp11 = _a_T_b[1] * _tmp10;
  const Scalar _tmp12 = _a[3] * _b[0];
  const Scalar _tmp13 = _a[2] * _b[1];
  const Scalar _tmp14 = _a[0] * _b[3];
  const Scalar _tmp15 = _a[1] * _b[2];
  const Scalar _tmp16 = _tmp12 + _tmp13 - _tmp14 - _tmp15;
  const Scalar _tmp17 = _a_T_b[0] * _tmp16;
  const Scalar _tmp18 = _a[3] * _b[2];
  const Scalar _tmp19 = _a[2] * _b[3];
  const Scalar _tmp20 = _a[0] * _b[1];
  const Scalar _tmp21 = _a[1] * _b[0];
  const Scalar _tmp22 = _tmp18 - _tmp19 - _tmp20 + _tmp21;
  const Scalar _tmp23 = _a_T_b[2] * _tmp22;
  const Scalar _tmp24 = _tmp11 + _tmp17 + _tmp23 + _tmp5;
  const Scalar _tmp25 = 2 * std::min<Scalar>(0, (((_tmp24) > 0) - ((_tmp24) < 0))) + 1;
  const Scalar _tmp26 = 2 * _tmp25;
  const Scalar _tmp27 = _tmp26 * sqrt_info(0, 0);
  const Scalar _tmp28 =
      _a_T_b[0] * _tmp22 - _a_T_b[1] * _tmp4 - _a_T_b[2] * _tmp16 + _a_T_b[3] * _tmp10;
  const Scalar _tmp29 = 1 - epsilon;
  const Scalar _tmp30 = std::min<Scalar>(_tmp29, std::fabs(_tmp24));
  const Scalar _tmp31 = std::acos(_tmp30) / std::sqrt(Scalar(1 - std::pow(_tmp30, Scalar(2))));
  const Scalar _tmp32 = _tmp28 * _tmp31;
  const Scalar _tmp33 = _tmp26 * sqrt_info(0, 1);
  const Scalar _tmp34 =
      -_a_T_b[0] * _tmp4 - _a_T_b[1] * _tmp22 + _a_T_b[2] * _tmp10 + _a_T_b[3] * _tmp16;
  const Scalar _tmp35 = _tmp31 * _tmp34;
  const Scalar _tmp36 = _tmp27 * _tmp32 - _tmp33 * _tmp35;
  const Scalar _tmp37 = _tmp26 * sqrt_info(1, 1);
  const Scalar _tmp38 = _tmp26 * sqrt_info(1, 0);
  const Scalar _tmp39 = _tmp32 * _tmp38 - _tmp35 * _tmp37;
  const Scalar _tmp40 = (Scalar(1) / Scalar(2)) * _tmp0;
  const Scalar _tmp41 = (Scalar(1) / Scalar(2)) * _tmp1;
  const Scalar _tmp42 = (Scalar(1) / Scalar(2)) * _tmp2;
  const Scalar _tmp43 = (Scalar(1) / Scalar(2)) * _tmp3;
  const Scalar _tmp44 = -_tmp40 - _tmp41 - _tmp42 - _tmp43;
  const Scalar _tmp45 = (Scalar(1) / Scalar(2)) * _tmp6;
  const Scalar _tmp46 = (Scalar(1) / Scalar(2)) * _tmp7;
  const Scalar _tmp47 = (Scalar(1) / Scalar(2)) * _tmp8;
  const Scalar _tmp48 = (Scalar(1) / Scalar(2)) * _tmp9;
  const Scalar _tmp49 = _tmp45 - _tmp46 + _tmp47 - _tmp48;
  const Scalar _tmp50 = -Scalar(1) / Scalar(2) * _tmp18 + (Scalar(1) / Scalar(2)) * _tmp19 +
                        (Scalar(1) / Scalar(2)) * _tmp20 - Scalar(1) / Scalar(2) * _tmp21;
  const Scalar _tmp51 = (Scalar(1) / Scalar(2)) * _tmp12;
  const Scalar _tmp52 = (Scalar(1) / Scalar(2)) * _tmp13;
  const Scalar _tmp53 = (Scalar(1) / Scalar(2)) * _tmp14;
  const Scalar _tmp54 = (Scalar(1) / Scalar(2)) * _tmp15;
  const Scalar _tmp55 = _tmp51 + _tmp52 - _tmp53 - _tmp54;
  const Scalar _tmp56 = _a_T_b[0] * _tmp50 + _a_T_b[2] * _tmp55;
  const Scalar _tmp57 = _a_T_b[1] * _tmp44 + _a_T_b[3] * _tmp49 + _tmp56;
  const Scalar _tmp58 = _tmp11 + _tmp17 + _tmp23 + _tmp5;
  const Scalar _tmp59 = std::fabs(_tmp58);
  const Scalar _tmp60 = std::min<Scalar>(_tmp29, _tmp59);
  const Scalar _tmp61 = 1 - std::pow(_tmp60, Scalar(2));
  const Scalar _tmp62 = _tmp25 * ((((_tmp29 - _tmp59) > 0) - ((_tmp29 - _tmp59) < 0)) + 1) *
                        (((_tmp58) > 0) - ((_tmp58) < 0));
  const Scalar _tmp63 = _tmp62 / _tmp61;
  const Scalar _tmp64 = _tmp28 * _tmp63;
  const Scalar _tmp65 = _tmp57 * _tmp64;
  const Scalar _tmp66 = std::acos(_tmp60);
  const Scalar _tmp67 = _tmp60 * _tmp62 * _tmp66 / (_tmp61 * std::sqrt(_tmp61));
  const Scalar _tmp68 = _tmp34 * _tmp67;
  const Scalar _tmp69 = _tmp68 * sqrt_info(0, 1);
  const Scalar _tmp70 = _tmp34 * _tmp63;
  const Scalar _tmp71 = _tmp70 * sqrt_info(0, 1);
  const Scalar _tmp72 = _tmp28 * _tmp67;
  const Scalar _tmp73 = _tmp72 * sqrt_info(0, 0);
  const Scalar _tmp74 = _a_T_b[2] * _tmp44;
  const Scalar _tmp75 = _a_T_b[0] * _tmp49;
  const Scalar _tmp76 = _a_T_b[3] * _tmp50;
  const Scalar _tmp77 = -_a_T_b[1] * _tmp55;
  const Scalar _tmp78 = _tmp76 + _tmp77;
  const Scalar _tmp79 = _tmp74 - _tmp75 + _tmp78;
  const Scalar _tmp80 = _tmp66 / std::sqrt(_tmp61);
  const Scalar _tmp81 = _tmp33 * _tmp80;
  const Scalar _tmp82 = _a_T_b[2] * _tmp50;
  const Scalar _tmp83 = _a_T_b[0] * _tmp55;
  const Scalar _tmp84 = -_tmp82 + _tmp83;
  const Scalar _tmp85 = -_a_T_b[1] * _tmp49;
  const Scalar _tmp86 = _a_T_b[3] * _tmp44 + _tmp85;
  const Scalar _tmp87 = _tmp84 + _tmp86;
  const Scalar _tmp88 = _tmp27 * _tmp80;
  const Scalar _tmp89 = -_tmp57 * _tmp69 + _tmp57 * _tmp71 + _tmp57 * _tmp73 -
                        _tmp65 * sqrt_info(0, 0) - _tmp79 * _tmp81 + _tmp87 * _tmp88;
  const Scalar _tmp90 = _tmp38 * _tmp80;
  const Scalar _tmp91 = _tmp72 * sqrt_info(1, 0);
  const Scalar _tmp92 = _tmp37 * _tmp80;
  const Scalar _tmp93 = _tmp68 * sqrt_info(1, 1);
  const Scalar _tmp94 = _tmp70 * sqrt_info(1, 1);
  const Scalar _tmp95 = _tmp57 * _tmp91 - _tmp57 * _tmp93 + _tmp57 * _tmp94 -
                        _tmp65 * sqrt_info(1, 0) - _tmp79 * _tmp92 + _tmp87 * _tmp90;
  const Scalar _tmp96 = _tmp40 + _tmp41 + _tmp42 + _tmp43;
  const Scalar _tmp97 = -_tmp51 - _tmp52 + _tmp53 + _tmp54;
  const Scalar _tmp98 = _a_T_b[1] * _tmp50 + _a_T_b[2] * _tmp49;
  const Scalar _tmp99 = _a_T_b[0] * _tmp96 + _a_T_b[3] * _tmp97 + _tmp98;
  const Scalar _tmp100 = _tmp64 * sqrt_info(0, 0);
  const Scalar _tmp101 = _a_T_b[2] * _tmp96;
  const Scalar _tmp102 = _tmp75 + _tmp76;
  const Scalar _tmp103 = -_a_T_b[1] * _tmp97 - _tmp101 + _tmp102;
  const Scalar _tmp104 = _a_T_b[3] * _tmp96;
  const Scalar _tmp105 = -_a_T_b[0] * _tmp97 + _tmp104 + _tmp82 + _tmp85;
  const Scalar _tmp106 = -_tmp100 * _tmp99 + _tmp103 * _tmp88 - _tmp105 * _tmp81 - _tmp69 * _tmp99 +
                         _tmp71 * _tmp99 + _tmp73 * _tmp99;
  const Scalar _tmp107 = _tmp64 * sqrt_info(1, 0);
  const Scalar _tmp108 = _tmp103 * _tmp90 - _tmp105 * _tmp92 - _tmp107 * _tmp99 + _tmp91 * _tmp99 -
                         _tmp93 * _tmp99 + _tmp94 * _tmp99;
  const Scalar _tmp109 = -_tmp45 + _tmp46 - _tmp47 + _tmp48;
  const Scalar _tmp110 = -_a_T_b[0] * _tmp109 + _tmp101 + _tmp78;
  const Scalar _tmp111 = _a_T_b[1] * _tmp96 + _a_T_b[3] * _tmp109 + _tmp56;
  const Scalar _tmp112 = -_a_T_b[1] * _tmp109 + _tmp104 + _tmp84;
  const Scalar _tmp113 = -_tmp100 * _tmp111 - _tmp110 * _tmp81 - _tmp111 * _tmp69 +
                         _tmp111 * _tmp71 + _tmp111 * _tmp73 + _tmp112 * _tmp88;
  const Scalar _tmp114 = -_tmp107 * _tmp111 - _tmp110 * _tmp92 + _tmp111 * _tmp91 -
                         _tmp111 * _tmp93 + _tmp111 * _tmp94 + _tmp112 * _tmp90;
  const Scalar _tmp115 = _tmp82 - _tmp83 + _tmp86;
  const Scalar _tmp116 = _a_T_b[0] * _tmp44 + _a_T_b[3] * _tmp55 + _tmp98;
  const Scalar _tmp117 = _tmp102 - _tmp74 + _tmp77;
  const Scalar _tmp118 = -_tmp100 * _tmp116 - _tmp115 * _tmp81 - _tmp116 * _tmp69 +
                         _tmp116 * _tmp71 + _tmp116 * _tmp73 + _tmp117 * _tmp88;
  const Scalar _tmp119 = -_tmp107 * _tmp116 - _tmp115 * _tmp92 + _tmp116 * _tmp91 -
                         _tmp116 * _tmp93 + _tmp116 * _tmp94 + _tmp117 * _tmp90;

  // Output terms (4)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 2, 1>& _res = (*res);

    _res(0, 0) = _tmp36;
    _res(1, 0) = _tmp39;
  }

  if (jacobian != nullptr) {
    Eigen::Matrix<Scalar, 2, 4>& _jacobian = (*jacobian);

    _jacobian(0, 0) = _tmp89;
    _jacobian(1, 0) = _tmp95;
    _jacobian(0, 1) = _tmp106;
    _jacobian(1, 1) = _tmp108;
    _jacobian(0, 2) = _tmp113;
    _jacobian(1, 2) = _tmp114;
    _jacobian(0, 3) = _tmp118;
    _jacobian(1, 3) = _tmp119;
  }

  if (hessian != nullptr) {
    Eigen::Matrix<Scalar, 4, 4>& _hessian = (*hessian);

    _hessian(0, 0) = std::pow(_tmp89, Scalar(2)) + std::pow(_tmp95, Scalar(2));
    _hessian(1, 0) = _tmp106 * _tmp89 + _tmp108 * _tmp95;
    _hessian(2, 0) = _tmp113 * _tmp89 + _tmp114 * _tmp95;
    _hessian(3, 0) = _tmp118 * _tmp89 + _tmp119 * _tmp95;
    _hessian(0, 1) = 0;
    _hessian(1, 1) = std::pow(_tmp106, Scalar(2)) + std::pow(_tmp108, Scalar(2));
    _hessian(2, 1) = _tmp106 * _tmp113 + _tmp108 * _tmp114;
    _hessian(3, 1) = _tmp106 * _tmp118 + _tmp108 * _tmp119;
    _hessian(0, 2) = 0;
    _hessian(1, 2) = 0;
    _hessian(2, 2) = std::pow(_tmp113, Scalar(2)) + std::pow(_tmp114, Scalar(2));
    _hessian(3, 2) = _tmp113 * _tmp118 + _tmp114 * _tmp119;
    _hessian(0, 3) = 0;
    _hessian(1, 3) = 0;
    _hessian(2, 3) = 0;
    _hessian(3, 3) = std::pow(_tmp118, Scalar(2)) + std::pow(_tmp119, Scalar(2));
  }

  if (rhs != nullptr) {
    Eigen::Matrix<Scalar, 4, 1>& _rhs = (*rhs);

    _rhs(0, 0) = _tmp36 * _tmp89 + _tmp39 * _tmp95;
    _rhs(1, 0) = _tmp106 * _tmp36 + _tmp108 * _tmp39;
    _rhs(2, 0) = _tmp113 * _tmp36 + _tmp114 * _tmp39;
    _rhs(3, 0) = _tmp118 * _tmp36 + _tmp119 * _tmp39;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
