// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Core>

#include <sym/atan_camera_cal.h>

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
 *     jacobian: (5x5) jacobian of res wrt arg value (5)
 *     hessian: (5x5) Gauss-Newton hessian for arg value (5)
 *     rhs: (5x1) Gauss-Newton rhs for arg value (5)
 */
template <typename Scalar>
void PriorFactorAtanCameraCal(const sym::ATANCameraCal<Scalar>& value,
                              const sym::ATANCameraCal<Scalar>& prior,
                              const Eigen::Matrix<Scalar, 5, 5>& sqrt_info, const Scalar epsilon,
                              Eigen::Matrix<Scalar, 5, 1>* const res = nullptr,
                              Eigen::Matrix<Scalar, 5, 5>* const jacobian = nullptr,
                              Eigen::Matrix<Scalar, 5, 5>* const hessian = nullptr,
                              Eigen::Matrix<Scalar, 5, 1>* const rhs = nullptr) {
  // Total ops: 230

  // Unused inputs
  (void)epsilon;

  // Input arrays
  const Eigen::Matrix<Scalar, 5, 1>& _value = value.Data();
  const Eigen::Matrix<Scalar, 5, 1>& _prior = prior.Data();

  // Intermediate terms (10)
  const Scalar _tmp0 = -_prior[3] + _value[3];
  const Scalar _tmp1 = -_prior[2] + _value[2];
  const Scalar _tmp2 = -_prior[0] + _value[0];
  const Scalar _tmp3 = -_prior[1] + _value[1];
  const Scalar _tmp4 = -_prior[4] + _value[4];
  const Scalar _tmp5 = _tmp0 * sqrt_info(0, 3) + _tmp1 * sqrt_info(0, 2) + _tmp2 * sqrt_info(0, 0) +
                       _tmp3 * sqrt_info(0, 1) + _tmp4 * sqrt_info(0, 4);
  const Scalar _tmp6 = _tmp0 * sqrt_info(1, 3) + _tmp1 * sqrt_info(1, 2) + _tmp2 * sqrt_info(1, 0) +
                       _tmp3 * sqrt_info(1, 1) + _tmp4 * sqrt_info(1, 4);
  const Scalar _tmp7 = _tmp0 * sqrt_info(2, 3) + _tmp1 * sqrt_info(2, 2) + _tmp2 * sqrt_info(2, 0) +
                       _tmp3 * sqrt_info(2, 1) + _tmp4 * sqrt_info(2, 4);
  const Scalar _tmp8 = _tmp0 * sqrt_info(3, 3) + _tmp1 * sqrt_info(3, 2) + _tmp2 * sqrt_info(3, 0) +
                       _tmp3 * sqrt_info(3, 1) + _tmp4 * sqrt_info(3, 4);
  const Scalar _tmp9 = _tmp0 * sqrt_info(4, 3) + _tmp1 * sqrt_info(4, 2) + _tmp2 * sqrt_info(4, 0) +
                       _tmp3 * sqrt_info(4, 1) + _tmp4 * sqrt_info(4, 4);

  // Output terms (4)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 5, 1>& _res = (*res);

    _res(0, 0) = _tmp5;
    _res(1, 0) = _tmp6;
    _res(2, 0) = _tmp7;
    _res(3, 0) = _tmp8;
    _res(4, 0) = _tmp9;
  }

  if (jacobian != nullptr) {
    Eigen::Matrix<Scalar, 5, 5>& _jacobian = (*jacobian);

    _jacobian(0, 0) = sqrt_info(0, 0);
    _jacobian(1, 0) = sqrt_info(1, 0);
    _jacobian(2, 0) = sqrt_info(2, 0);
    _jacobian(3, 0) = sqrt_info(3, 0);
    _jacobian(4, 0) = sqrt_info(4, 0);
    _jacobian(0, 1) = sqrt_info(0, 1);
    _jacobian(1, 1) = sqrt_info(1, 1);
    _jacobian(2, 1) = sqrt_info(2, 1);
    _jacobian(3, 1) = sqrt_info(3, 1);
    _jacobian(4, 1) = sqrt_info(4, 1);
    _jacobian(0, 2) = sqrt_info(0, 2);
    _jacobian(1, 2) = sqrt_info(1, 2);
    _jacobian(2, 2) = sqrt_info(2, 2);
    _jacobian(3, 2) = sqrt_info(3, 2);
    _jacobian(4, 2) = sqrt_info(4, 2);
    _jacobian(0, 3) = sqrt_info(0, 3);
    _jacobian(1, 3) = sqrt_info(1, 3);
    _jacobian(2, 3) = sqrt_info(2, 3);
    _jacobian(3, 3) = sqrt_info(3, 3);
    _jacobian(4, 3) = sqrt_info(4, 3);
    _jacobian(0, 4) = sqrt_info(0, 4);
    _jacobian(1, 4) = sqrt_info(1, 4);
    _jacobian(2, 4) = sqrt_info(2, 4);
    _jacobian(3, 4) = sqrt_info(3, 4);
    _jacobian(4, 4) = sqrt_info(4, 4);
  }

  if (hessian != nullptr) {
    Eigen::Matrix<Scalar, 5, 5>& _hessian = (*hessian);

    _hessian(0, 0) = std::pow(sqrt_info(0, 0), Scalar(2)) + std::pow(sqrt_info(1, 0), Scalar(2)) +
                     std::pow(sqrt_info(2, 0), Scalar(2)) + std::pow(sqrt_info(3, 0), Scalar(2)) +
                     std::pow(sqrt_info(4, 0), Scalar(2));
    _hessian(1, 0) = sqrt_info(0, 0) * sqrt_info(0, 1) + sqrt_info(1, 0) * sqrt_info(1, 1) +
                     sqrt_info(2, 0) * sqrt_info(2, 1) + sqrt_info(3, 0) * sqrt_info(3, 1) +
                     sqrt_info(4, 0) * sqrt_info(4, 1);
    _hessian(2, 0) = sqrt_info(0, 0) * sqrt_info(0, 2) + sqrt_info(1, 0) * sqrt_info(1, 2) +
                     sqrt_info(2, 0) * sqrt_info(2, 2) + sqrt_info(3, 0) * sqrt_info(3, 2) +
                     sqrt_info(4, 0) * sqrt_info(4, 2);
    _hessian(3, 0) = sqrt_info(0, 0) * sqrt_info(0, 3) + sqrt_info(1, 0) * sqrt_info(1, 3) +
                     sqrt_info(2, 0) * sqrt_info(2, 3) + sqrt_info(3, 0) * sqrt_info(3, 3) +
                     sqrt_info(4, 0) * sqrt_info(4, 3);
    _hessian(4, 0) = sqrt_info(0, 0) * sqrt_info(0, 4) + sqrt_info(1, 0) * sqrt_info(1, 4) +
                     sqrt_info(2, 0) * sqrt_info(2, 4) + sqrt_info(3, 0) * sqrt_info(3, 4) +
                     sqrt_info(4, 0) * sqrt_info(4, 4);
    _hessian(0, 1) = 0;
    _hessian(1, 1) = std::pow(sqrt_info(0, 1), Scalar(2)) + std::pow(sqrt_info(1, 1), Scalar(2)) +
                     std::pow(sqrt_info(2, 1), Scalar(2)) + std::pow(sqrt_info(3, 1), Scalar(2)) +
                     std::pow(sqrt_info(4, 1), Scalar(2));
    _hessian(2, 1) = sqrt_info(0, 1) * sqrt_info(0, 2) + sqrt_info(1, 1) * sqrt_info(1, 2) +
                     sqrt_info(2, 1) * sqrt_info(2, 2) + sqrt_info(3, 1) * sqrt_info(3, 2) +
                     sqrt_info(4, 1) * sqrt_info(4, 2);
    _hessian(3, 1) = sqrt_info(0, 1) * sqrt_info(0, 3) + sqrt_info(1, 1) * sqrt_info(1, 3) +
                     sqrt_info(2, 1) * sqrt_info(2, 3) + sqrt_info(3, 1) * sqrt_info(3, 3) +
                     sqrt_info(4, 1) * sqrt_info(4, 3);
    _hessian(4, 1) = sqrt_info(0, 1) * sqrt_info(0, 4) + sqrt_info(1, 1) * sqrt_info(1, 4) +
                     sqrt_info(2, 1) * sqrt_info(2, 4) + sqrt_info(3, 1) * sqrt_info(3, 4) +
                     sqrt_info(4, 1) * sqrt_info(4, 4);
    _hessian(0, 2) = 0;
    _hessian(1, 2) = 0;
    _hessian(2, 2) = std::pow(sqrt_info(0, 2), Scalar(2)) + std::pow(sqrt_info(1, 2), Scalar(2)) +
                     std::pow(sqrt_info(2, 2), Scalar(2)) + std::pow(sqrt_info(3, 2), Scalar(2)) +
                     std::pow(sqrt_info(4, 2), Scalar(2));
    _hessian(3, 2) = sqrt_info(0, 2) * sqrt_info(0, 3) + sqrt_info(1, 2) * sqrt_info(1, 3) +
                     sqrt_info(2, 2) * sqrt_info(2, 3) + sqrt_info(3, 2) * sqrt_info(3, 3) +
                     sqrt_info(4, 2) * sqrt_info(4, 3);
    _hessian(4, 2) = sqrt_info(0, 2) * sqrt_info(0, 4) + sqrt_info(1, 2) * sqrt_info(1, 4) +
                     sqrt_info(2, 2) * sqrt_info(2, 4) + sqrt_info(3, 2) * sqrt_info(3, 4) +
                     sqrt_info(4, 2) * sqrt_info(4, 4);
    _hessian(0, 3) = 0;
    _hessian(1, 3) = 0;
    _hessian(2, 3) = 0;
    _hessian(3, 3) = std::pow(sqrt_info(0, 3), Scalar(2)) + std::pow(sqrt_info(1, 3), Scalar(2)) +
                     std::pow(sqrt_info(2, 3), Scalar(2)) + std::pow(sqrt_info(3, 3), Scalar(2)) +
                     std::pow(sqrt_info(4, 3), Scalar(2));
    _hessian(4, 3) = sqrt_info(0, 3) * sqrt_info(0, 4) + sqrt_info(1, 3) * sqrt_info(1, 4) +
                     sqrt_info(2, 3) * sqrt_info(2, 4) + sqrt_info(3, 3) * sqrt_info(3, 4) +
                     sqrt_info(4, 3) * sqrt_info(4, 4);
    _hessian(0, 4) = 0;
    _hessian(1, 4) = 0;
    _hessian(2, 4) = 0;
    _hessian(3, 4) = 0;
    _hessian(4, 4) = std::pow(sqrt_info(0, 4), Scalar(2)) + std::pow(sqrt_info(1, 4), Scalar(2)) +
                     std::pow(sqrt_info(2, 4), Scalar(2)) + std::pow(sqrt_info(3, 4), Scalar(2)) +
                     std::pow(sqrt_info(4, 4), Scalar(2));
  }

  if (rhs != nullptr) {
    Eigen::Matrix<Scalar, 5, 1>& _rhs = (*rhs);

    _rhs(0, 0) = _tmp5 * sqrt_info(0, 0) + _tmp6 * sqrt_info(1, 0) + _tmp7 * sqrt_info(2, 0) +
                 _tmp8 * sqrt_info(3, 0) + _tmp9 * sqrt_info(4, 0);
    _rhs(1, 0) = _tmp5 * sqrt_info(0, 1) + _tmp6 * sqrt_info(1, 1) + _tmp7 * sqrt_info(2, 1) +
                 _tmp8 * sqrt_info(3, 1) + _tmp9 * sqrt_info(4, 1);
    _rhs(2, 0) = _tmp5 * sqrt_info(0, 2) + _tmp6 * sqrt_info(1, 2) + _tmp7 * sqrt_info(2, 2) +
                 _tmp8 * sqrt_info(3, 2) + _tmp9 * sqrt_info(4, 2);
    _rhs(3, 0) = _tmp5 * sqrt_info(0, 3) + _tmp6 * sqrt_info(1, 3) + _tmp7 * sqrt_info(2, 3) +
                 _tmp8 * sqrt_info(3, 3) + _tmp9 * sqrt_info(4, 3);
    _rhs(4, 0) = _tmp5 * sqrt_info(0, 4) + _tmp6 * sqrt_info(1, 4) + _tmp7 * sqrt_info(2, 4) +
                 _tmp8 * sqrt_info(3, 4) + _tmp9 * sqrt_info(4, 4);
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
