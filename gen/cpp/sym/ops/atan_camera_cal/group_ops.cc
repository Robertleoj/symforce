// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     ops/CLASS/group_ops.cc.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include <sym/atan_camera_cal.h>
#include <sym/ops/atan_camera_cal/group_ops.h>

namespace sym {

/**
 *
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: <lambda>
 *
 * Outputs:
 *     res: ATANCameraCal
 */
template <typename Scalar>
sym::ATANCameraCal<Scalar> GroupOps<ATANCameraCal<Scalar>>::Identity() {
  // Total ops: 0

  // Input arrays

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 5, 1> _res;

  _res[0] = 0;
  _res[1] = 0;
  _res[2] = 0;
  _res[3] = 0;
  _res[4] = 0;

  return sym::ATANCameraCal<Scalar>(_res, /* normalize */ false);
}

/**
 *
 * Inverse of the element a.
 *
 * Returns:
 *     Element: b such that a @ b = identity
 */
template <typename Scalar>
sym::ATANCameraCal<Scalar> GroupOps<ATANCameraCal<Scalar>>::Inverse(
    const sym::ATANCameraCal<Scalar>& a) {
  // Total ops: 5

  // Input arrays
  const Eigen::Matrix<Scalar, 5, 1>& _a = a.Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 5, 1> _res;

  _res[0] = -_a[0];
  _res[1] = -_a[1];
  _res[2] = -_a[2];
  _res[3] = -_a[3];
  _res[4] = -_a[4];

  return sym::ATANCameraCal<Scalar>(_res);
}

/**
 *
 * Composition of two elements in the group.
 *
 * Returns:
 *     Element: a @ b
 */
template <typename Scalar>
sym::ATANCameraCal<Scalar> GroupOps<ATANCameraCal<Scalar>>::Compose(
    const sym::ATANCameraCal<Scalar>& a, const sym::ATANCameraCal<Scalar>& b) {
  // Total ops: 5

  // Input arrays
  const Eigen::Matrix<Scalar, 5, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 5, 1>& _b = b.Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 5, 1> _res;

  _res[0] = _a[0] + _b[0];
  _res[1] = _a[1] + _b[1];
  _res[2] = _a[2] + _b[2];
  _res[3] = _a[3] + _b[3];
  _res[4] = _a[4] + _b[4];

  return sym::ATANCameraCal<Scalar>(_res);
}

/**
 *
 * Returns the element that when composed with a produces b. For vector spaces it is b - a.
 *
 * Implementation is simply ``compose(inverse(a), b)``.
 *
 * Returns:
 *     Element: c such that a @ c = b
 */
template <typename Scalar>
sym::ATANCameraCal<Scalar> GroupOps<ATANCameraCal<Scalar>>::Between(
    const sym::ATANCameraCal<Scalar>& a, const sym::ATANCameraCal<Scalar>& b) {
  // Total ops: 5

  // Input arrays
  const Eigen::Matrix<Scalar, 5, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 5, 1>& _b = b.Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 5, 1> _res;

  _res[0] = -_a[0] + _b[0];
  _res[1] = -_a[1] + _b[1];
  _res[2] = -_a[2] + _b[2];
  _res[3] = -_a[3] + _b[3];
  _res[4] = -_a[4] + _b[4];

  return sym::ATANCameraCal<Scalar>(_res);
}

/**
 *
 * Inverse of the element a.
 *
 * Returns:
 *     Element: b such that a @ b = identity
 *     res_D_a: (5x5) jacobian of res (5) wrt arg a (5)
 */
template <typename Scalar>
sym::ATANCameraCal<Scalar> GroupOps<ATANCameraCal<Scalar>>::InverseWithJacobian(
    const sym::ATANCameraCal<Scalar>& a, SelfJacobian* const res_D_a) {
  // Total ops: 5

  // Input arrays
  const Eigen::Matrix<Scalar, 5, 1>& _a = a.Data();

  // Intermediate terms (0)

  // Output terms (2)
  Eigen::Matrix<Scalar, 5, 1> _res;

  _res[0] = -_a[0];
  _res[1] = -_a[1];
  _res[2] = -_a[2];
  _res[3] = -_a[3];
  _res[4] = -_a[4];

  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 5, 5>& _res_D_a = (*res_D_a);

    _res_D_a.setZero();

    _res_D_a(0, 0) = -1;
    _res_D_a(1, 1) = -1;
    _res_D_a(2, 2) = -1;
    _res_D_a(3, 3) = -1;
    _res_D_a(4, 4) = -1;
  }

  return sym::ATANCameraCal<Scalar>(_res);
}

/**
 *
 * Composition of two elements in the group.
 *
 * Returns:
 *     Element: a @ b
 *     res_D_a: (5x5) jacobian of res (5) wrt arg a (5)
 *     res_D_b: (5x5) jacobian of res (5) wrt arg b (5)
 */
template <typename Scalar>
sym::ATANCameraCal<Scalar> GroupOps<ATANCameraCal<Scalar>>::ComposeWithJacobians(
    const sym::ATANCameraCal<Scalar>& a, const sym::ATANCameraCal<Scalar>& b,
    SelfJacobian* const res_D_a, SelfJacobian* const res_D_b) {
  // Total ops: 5

  // Input arrays
  const Eigen::Matrix<Scalar, 5, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 5, 1>& _b = b.Data();

  // Intermediate terms (0)

  // Output terms (3)
  Eigen::Matrix<Scalar, 5, 1> _res;

  _res[0] = _a[0] + _b[0];
  _res[1] = _a[1] + _b[1];
  _res[2] = _a[2] + _b[2];
  _res[3] = _a[3] + _b[3];
  _res[4] = _a[4] + _b[4];

  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 5, 5>& _res_D_a = (*res_D_a);

    _res_D_a.setZero();

    _res_D_a(0, 0) = 1;
    _res_D_a(1, 1) = 1;
    _res_D_a(2, 2) = 1;
    _res_D_a(3, 3) = 1;
    _res_D_a(4, 4) = 1;
  }

  if (res_D_b != nullptr) {
    Eigen::Matrix<Scalar, 5, 5>& _res_D_b = (*res_D_b);

    _res_D_b.setZero();

    _res_D_b(0, 0) = 1;
    _res_D_b(1, 1) = 1;
    _res_D_b(2, 2) = 1;
    _res_D_b(3, 3) = 1;
    _res_D_b(4, 4) = 1;
  }

  return sym::ATANCameraCal<Scalar>(_res);
}

/**
 *
 * Returns the element that when composed with a produces b. For vector spaces it is b - a.
 *
 * Implementation is simply ``compose(inverse(a), b)``.
 *
 * Returns:
 *     Element: c such that a @ c = b
 *     res_D_a: (5x5) jacobian of res (5) wrt arg a (5)
 *     res_D_b: (5x5) jacobian of res (5) wrt arg b (5)
 */
template <typename Scalar>
sym::ATANCameraCal<Scalar> GroupOps<ATANCameraCal<Scalar>>::BetweenWithJacobians(
    const sym::ATANCameraCal<Scalar>& a, const sym::ATANCameraCal<Scalar>& b,
    SelfJacobian* const res_D_a, SelfJacobian* const res_D_b) {
  // Total ops: 5

  // Input arrays
  const Eigen::Matrix<Scalar, 5, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 5, 1>& _b = b.Data();

  // Intermediate terms (0)

  // Output terms (3)
  Eigen::Matrix<Scalar, 5, 1> _res;

  _res[0] = -_a[0] + _b[0];
  _res[1] = -_a[1] + _b[1];
  _res[2] = -_a[2] + _b[2];
  _res[3] = -_a[3] + _b[3];
  _res[4] = -_a[4] + _b[4];

  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 5, 5>& _res_D_a = (*res_D_a);

    _res_D_a.setZero();

    _res_D_a(0, 0) = -1;
    _res_D_a(1, 1) = -1;
    _res_D_a(2, 2) = -1;
    _res_D_a(3, 3) = -1;
    _res_D_a(4, 4) = -1;
  }

  if (res_D_b != nullptr) {
    Eigen::Matrix<Scalar, 5, 5>& _res_D_b = (*res_D_b);

    _res_D_b.setZero();

    _res_D_b(0, 0) = 1;
    _res_D_b(1, 1) = 1;
    _res_D_b(2, 2) = 1;
    _res_D_b(3, 3) = 1;
    _res_D_b(4, 4) = 1;
  }

  return sym::ATANCameraCal<Scalar>(_res);
}

}  // namespace sym

// Explicit instantiation
template struct sym::GroupOps<sym::ATANCameraCal<double>>;
template struct sym::GroupOps<sym::ATANCameraCal<float>>;
