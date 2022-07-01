// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     backends/cpp/templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Dense>

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
 *     jacobian: (3x6) jacobian of res wrt arg value (6)
 *     hessian: (6x6) Gauss-Newton hessian for arg value (6)
 *     rhs: (6x1) Gauss-Newton rhs for arg value (6)
 */
template <typename Scalar>
void PriorFactorPose3Position(const sym::Pose3<Scalar>& value,
                              const Eigen::Matrix<Scalar, 3, 1>& prior,
                              const Eigen::Matrix<Scalar, 3, 3>& sqrt_info, const Scalar epsilon,
                              Eigen::Matrix<Scalar, 3, 1>* const res = nullptr,
                              Eigen::Matrix<Scalar, 3, 6>* const jacobian = nullptr,
                              Eigen::Matrix<Scalar, 6, 6>* const hessian = nullptr,
                              Eigen::Matrix<Scalar, 6, 1>* const rhs = nullptr) {
  // Total ops: 63

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _value = value.Data();

  // Intermediate terms (6)
  const Scalar _tmp0 = _value[5] - prior(1, 0);
  const Scalar _tmp1 = _value[4] - prior(0, 0);
  const Scalar _tmp2 = _value[6] - prior(2, 0);
  const Scalar _tmp3 = _tmp0 * sqrt_info(0, 1) + _tmp1 * sqrt_info(0, 0) + _tmp2 * sqrt_info(0, 2);
  const Scalar _tmp4 = _tmp0 * sqrt_info(1, 1) + _tmp1 * sqrt_info(1, 0) + _tmp2 * sqrt_info(1, 2);
  const Scalar _tmp5 = _tmp0 * sqrt_info(2, 1) + _tmp1 * sqrt_info(2, 0) + _tmp2 * sqrt_info(2, 2);

  // Output terms (4)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 3, 1>& _res = (*res);

    _res(0, 0) = _tmp3;
    _res(1, 0) = _tmp4;
    _res(2, 0) = _tmp5;
  }

  if (jacobian != nullptr) {
    Eigen::Matrix<Scalar, 3, 6>& _jacobian = (*jacobian);

    _jacobian(0, 0) = 0;
    _jacobian(1, 0) = 0;
    _jacobian(2, 0) = 0;
    _jacobian(0, 1) = 0;
    _jacobian(1, 1) = 0;
    _jacobian(2, 1) = 0;
    _jacobian(0, 2) = 0;
    _jacobian(1, 2) = 0;
    _jacobian(2, 2) = 0;
    _jacobian(0, 3) = sqrt_info(0, 0);
    _jacobian(1, 3) = sqrt_info(1, 0);
    _jacobian(2, 3) = sqrt_info(2, 0);
    _jacobian(0, 4) = sqrt_info(0, 1);
    _jacobian(1, 4) = sqrt_info(1, 1);
    _jacobian(2, 4) = sqrt_info(2, 1);
    _jacobian(0, 5) = sqrt_info(0, 2);
    _jacobian(1, 5) = sqrt_info(1, 2);
    _jacobian(2, 5) = sqrt_info(2, 2);
  }

  if (hessian != nullptr) {
    Eigen::Matrix<Scalar, 6, 6>& _hessian = (*hessian);

    _hessian.setZero();

    _hessian(3, 3) = std::pow(sqrt_info(0, 0), Scalar(2)) + std::pow(sqrt_info(1, 0), Scalar(2)) +
                     std::pow(sqrt_info(2, 0), Scalar(2));
    _hessian(4, 3) = sqrt_info(0, 0) * sqrt_info(0, 1) + sqrt_info(1, 0) * sqrt_info(1, 1) +
                     sqrt_info(2, 0) * sqrt_info(2, 1);
    _hessian(5, 3) = sqrt_info(0, 0) * sqrt_info(0, 2) + sqrt_info(1, 0) * sqrt_info(1, 2) +
                     sqrt_info(2, 0) * sqrt_info(2, 2);
    _hessian(4, 4) = std::pow(sqrt_info(0, 1), Scalar(2)) + std::pow(sqrt_info(1, 1), Scalar(2)) +
                     std::pow(sqrt_info(2, 1), Scalar(2));
    _hessian(5, 4) = sqrt_info(0, 1) * sqrt_info(0, 2) + sqrt_info(1, 1) * sqrt_info(1, 2) +
                     sqrt_info(2, 1) * sqrt_info(2, 2);
    _hessian(5, 5) = std::pow(sqrt_info(0, 2), Scalar(2)) + std::pow(sqrt_info(1, 2), Scalar(2)) +
                     std::pow(sqrt_info(2, 2), Scalar(2));
  }

  if (rhs != nullptr) {
    Eigen::Matrix<Scalar, 6, 1>& _rhs = (*rhs);

    _rhs(0, 0) = 0;
    _rhs(1, 0) = 0;
    _rhs(2, 0) = 0;
    _rhs(3, 0) = _tmp3 * sqrt_info(0, 0) + _tmp4 * sqrt_info(1, 0) + _tmp5 * sqrt_info(2, 0);
    _rhs(4, 0) = _tmp3 * sqrt_info(0, 1) + _tmp4 * sqrt_info(1, 1) + _tmp5 * sqrt_info(2, 1);
    _rhs(5, 0) = _tmp3 * sqrt_info(0, 2) + _tmp4 * sqrt_info(1, 2) + _tmp5 * sqrt_info(2, 2);
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
