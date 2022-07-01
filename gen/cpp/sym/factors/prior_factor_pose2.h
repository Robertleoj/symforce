// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     backends/cpp/templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Dense>

#include <sym/pose2.h>

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
 *     jacobian: (3x3) jacobian of res wrt arg value (3)
 *     hessian: (3x3) Gauss-Newton hessian for arg value (3)
 *     rhs: (3x1) Gauss-Newton rhs for arg value (3)
 */
template <typename Scalar>
void PriorFactorPose2(const sym::Pose2<Scalar>& value, const sym::Pose2<Scalar>& prior,
                      const Eigen::Matrix<Scalar, 3, 3>& sqrt_info, const Scalar epsilon,
                      Eigen::Matrix<Scalar, 3, 1>* const res = nullptr,
                      Eigen::Matrix<Scalar, 3, 3>* const jacobian = nullptr,
                      Eigen::Matrix<Scalar, 3, 3>* const hessian = nullptr,
                      Eigen::Matrix<Scalar, 3, 1>* const rhs = nullptr) {
  // Total ops: 94

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _value = value.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _prior = prior.Data();

  // Intermediate terms (19)
  const Scalar _tmp0 = -_prior[2] + _value[2];
  const Scalar _tmp1 = -_prior[3] + _value[3];
  const Scalar _tmp2 = _prior[0] * _value[1];
  const Scalar _tmp3 = _prior[1] * _value[0];
  const Scalar _tmp4 = _tmp2 - _tmp3;
  const Scalar _tmp5 = _prior[0] * _value[0] + _prior[1] * _value[1];
  const Scalar _tmp6 = _tmp5 + epsilon * ((((_tmp5) > 0) - ((_tmp5) < 0)) + Scalar(0.5));
  const Scalar _tmp7 = std::atan2(_tmp4, _tmp6);
  const Scalar _tmp8 = _tmp0 * sqrt_info(0, 1) + _tmp1 * sqrt_info(0, 2) + _tmp7 * sqrt_info(0, 0);
  const Scalar _tmp9 = _tmp0 * sqrt_info(1, 1) + _tmp1 * sqrt_info(1, 2) + _tmp7 * sqrt_info(1, 0);
  const Scalar _tmp10 = _tmp0 * sqrt_info(2, 1) + _tmp1 * sqrt_info(2, 2) + _tmp7 * sqrt_info(2, 0);
  const Scalar _tmp11 = std::pow(_tmp6, Scalar(2));
  const Scalar _tmp12 = _tmp5 / _tmp6 - _tmp4 * (-_tmp2 + _tmp3) / _tmp11;
  const Scalar _tmp13 = _tmp11 + std::pow(_tmp4, Scalar(2));
  const Scalar _tmp14 = _tmp11 * _tmp12 / _tmp13;
  const Scalar _tmp15 = _tmp14 * sqrt_info(0, 0);
  const Scalar _tmp16 = _tmp14 * sqrt_info(1, 0);
  const Scalar _tmp17 = _tmp14 * sqrt_info(2, 0);
  const Scalar _tmp18 =
      std::pow(_tmp12, Scalar(2)) * std::pow(_tmp6, Scalar(4)) / std::pow(_tmp13, Scalar(2));

  // Output terms (4)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 3, 1>& _res = (*res);

    _res(0, 0) = _tmp8;
    _res(1, 0) = _tmp9;
    _res(2, 0) = _tmp10;
  }

  if (jacobian != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _jacobian = (*jacobian);

    _jacobian(0, 0) = _tmp15;
    _jacobian(1, 0) = _tmp16;
    _jacobian(2, 0) = _tmp17;
    _jacobian(0, 1) = sqrt_info(0, 1);
    _jacobian(1, 1) = sqrt_info(1, 1);
    _jacobian(2, 1) = sqrt_info(2, 1);
    _jacobian(0, 2) = sqrt_info(0, 2);
    _jacobian(1, 2) = sqrt_info(1, 2);
    _jacobian(2, 2) = sqrt_info(2, 2);
  }

  if (hessian != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _hessian = (*hessian);

    _hessian(0, 0) = _tmp18 * std::pow(sqrt_info(0, 0), Scalar(2)) +
                     _tmp18 * std::pow(sqrt_info(1, 0), Scalar(2)) +
                     _tmp18 * std::pow(sqrt_info(2, 0), Scalar(2));
    _hessian(1, 0) = _tmp15 * sqrt_info(0, 1) + _tmp16 * sqrt_info(1, 1) + _tmp17 * sqrt_info(2, 1);
    _hessian(2, 0) = _tmp15 * sqrt_info(0, 2) + _tmp16 * sqrt_info(1, 2) + _tmp17 * sqrt_info(2, 2);
    _hessian(0, 1) = 0;
    _hessian(1, 1) = std::pow(sqrt_info(0, 1), Scalar(2)) + std::pow(sqrt_info(1, 1), Scalar(2)) +
                     std::pow(sqrt_info(2, 1), Scalar(2));
    _hessian(2, 1) = sqrt_info(0, 1) * sqrt_info(0, 2) + sqrt_info(1, 1) * sqrt_info(1, 2) +
                     sqrt_info(2, 1) * sqrt_info(2, 2);
    _hessian(0, 2) = 0;
    _hessian(1, 2) = 0;
    _hessian(2, 2) = std::pow(sqrt_info(0, 2), Scalar(2)) + std::pow(sqrt_info(1, 2), Scalar(2)) +
                     std::pow(sqrt_info(2, 2), Scalar(2));
  }

  if (rhs != nullptr) {
    Eigen::Matrix<Scalar, 3, 1>& _rhs = (*rhs);

    _rhs(0, 0) = _tmp10 * _tmp17 + _tmp15 * _tmp8 + _tmp16 * _tmp9;
    _rhs(1, 0) = _tmp10 * sqrt_info(2, 1) + _tmp8 * sqrt_info(0, 1) + _tmp9 * sqrt_info(1, 1);
    _rhs(2, 0) = _tmp10 * sqrt_info(2, 2) + _tmp8 * sqrt_info(0, 2) + _tmp9 * sqrt_info(1, 2);
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
