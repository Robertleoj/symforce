// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     ops/CLASS/group_ops.cc.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include <sym/ops/pose2/group_ops.h>
#include <sym/pose2.h>

namespace sym {

/**
 *
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: <lambda>
 *
 * Args:
 *
 * Outputs:
 *     res: Pose2
 */
template <typename Scalar>
sym::Pose2<Scalar> GroupOps<Pose2<Scalar>>::Identity() {
  // Total ops: 0

  // Input arrays

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = 1;
  _res[1] = 0;
  _res[2] = 0;
  _res[3] = 0;

  return sym::Pose2<Scalar>(_res, /* normalize */ false);
}

/**
 *
 * Inverse of the element a.
 *
 * Returns:
 *     Element: b such that a @ b = identity
 */
template <typename Scalar>
sym::Pose2<Scalar> GroupOps<Pose2<Scalar>>::Inverse(const sym::Pose2<Scalar>& a) {
  // Total ops: 8

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = _a[0];
  _res[1] = -_a[1];
  _res[2] = -_a[0] * _a[2] - _a[1] * _a[3];
  _res[3] = -_a[0] * _a[3] + _a[1] * _a[2];

  return sym::Pose2<Scalar>(_res);
}

/**
 *
 * Composition of two elements in the group.
 *
 * Returns:
 *     Element: a @ b
 */
template <typename Scalar>
sym::Pose2<Scalar> GroupOps<Pose2<Scalar>>::Compose(const sym::Pose2<Scalar>& a,
                                                    const sym::Pose2<Scalar>& b) {
  // Total ops: 14

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _b = b.Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = _a[0] * _b[0] - _a[1] * _b[1];
  _res[1] = _a[0] * _b[1] + _a[1] * _b[0];
  _res[2] = _a[0] * _b[2] - _a[1] * _b[3] + _a[2];
  _res[3] = _a[0] * _b[3] + _a[1] * _b[2] + _a[3];

  return sym::Pose2<Scalar>(_res);
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
sym::Pose2<Scalar> GroupOps<Pose2<Scalar>>::Between(const sym::Pose2<Scalar>& a,
                                                    const sym::Pose2<Scalar>& b) {
  // Total ops: 20

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _b = b.Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = _a[0] * _b[0] + _a[1] * _b[1];
  _res[1] = _a[0] * _b[1] - _a[1] * _b[0];
  _res[2] = -_a[0] * _a[2] + _a[0] * _b[2] - _a[1] * _a[3] + _a[1] * _b[3];
  _res[3] = -_a[0] * _a[3] + _a[0] * _b[3] + _a[1] * _a[2] - _a[1] * _b[2];

  return sym::Pose2<Scalar>(_res);
}

/**
 *
 * Inverse of the element a.
 *
 * Returns:
 *     Element: b such that a @ b = identity
 *     res_D_a: (3x3) jacobian of res (3) wrt arg a (3)
 */
template <typename Scalar>
sym::Pose2<Scalar> GroupOps<Pose2<Scalar>>::InverseWithJacobian(const sym::Pose2<Scalar>& a,
                                                                SelfJacobian* const res_D_a) {
  // Total ops: 14

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();

  // Intermediate terms (5)
  const Scalar _tmp0 = -_a[1];
  const Scalar _tmp1 = _a[0] * _a[2] + _a[1] * _a[3];
  const Scalar _tmp2 = _a[1] * _a[2];
  const Scalar _tmp3 = _a[0] * _a[3];
  const Scalar _tmp4 = -_a[0];

  // Output terms (2)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = _a[0];
  _res[1] = _tmp0;
  _res[2] = -_tmp1;
  _res[3] = _tmp2 - _tmp3;

  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _res_D_a = (*res_D_a);

    _res_D_a(0, 0) = -std::pow(_a[0], Scalar(2)) - std::pow(_a[1], Scalar(2));
    _res_D_a(1, 0) = _tmp2 - _tmp3;
    _res_D_a(2, 0) = _tmp1;
    _res_D_a(0, 1) = 0;
    _res_D_a(1, 1) = _tmp4;
    _res_D_a(2, 1) = _a[1];
    _res_D_a(0, 2) = 0;
    _res_D_a(1, 2) = _tmp0;
    _res_D_a(2, 2) = _tmp4;
  }

  return sym::Pose2<Scalar>(_res);
}

/**
 *
 * Composition of two elements in the group.
 *
 * Returns:
 *     Element: a @ b
 *     res_D_a: (3x3) jacobian of res (3) wrt arg a (3)
 *     res_D_b: (3x3) jacobian of res (3) wrt arg b (3)
 */
template <typename Scalar>
sym::Pose2<Scalar> GroupOps<Pose2<Scalar>>::ComposeWithJacobians(const sym::Pose2<Scalar>& a,
                                                                 const sym::Pose2<Scalar>& b,
                                                                 SelfJacobian* const res_D_a,
                                                                 SelfJacobian* const res_D_b) {
  // Total ops: 22

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _b = b.Data();

  // Intermediate terms (8)
  const Scalar _tmp0 = _a[0] * _b[0] - _a[1] * _b[1];
  const Scalar _tmp1 = _a[1] * _b[0];
  const Scalar _tmp2 = _a[0] * _b[1];
  const Scalar _tmp3 = _tmp1 + _tmp2;
  const Scalar _tmp4 = _a[0] * _b[2] - _a[1] * _b[3];
  const Scalar _tmp5 = _a[1] * _b[2];
  const Scalar _tmp6 = _a[0] * _b[3];
  const Scalar _tmp7 = std::pow(_tmp0, Scalar(2)) - _tmp3 * (-_tmp1 - _tmp2);

  // Output terms (3)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = _tmp0;
  _res[1] = _tmp3;
  _res[2] = _a[2] + _tmp4;
  _res[3] = _a[3] + _tmp5 + _tmp6;

  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _res_D_a = (*res_D_a);

    _res_D_a(0, 0) = _tmp7;
    _res_D_a(1, 0) = -_tmp5 - _tmp6;
    _res_D_a(2, 0) = _tmp4;
    _res_D_a(0, 1) = 0;
    _res_D_a(1, 1) = 1;
    _res_D_a(2, 1) = 0;
    _res_D_a(0, 2) = 0;
    _res_D_a(1, 2) = 0;
    _res_D_a(2, 2) = 1;
  }

  if (res_D_b != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _res_D_b = (*res_D_b);

    _res_D_b(0, 0) = _tmp7;
    _res_D_b(1, 0) = 0;
    _res_D_b(2, 0) = 0;
    _res_D_b(0, 1) = 0;
    _res_D_b(1, 1) = _a[0];
    _res_D_b(2, 1) = _a[1];
    _res_D_b(0, 2) = 0;
    _res_D_b(1, 2) = -_a[1];
    _res_D_b(2, 2) = _a[0];
  }

  return sym::Pose2<Scalar>(_res);
}

/**
 *
 * Returns the element that when composed with a produces b. For vector spaces it is b - a.
 *
 * Implementation is simply ``compose(inverse(a), b)``.
 *
 * Returns:
 *     Element: c such that a @ c = b
 *     res_D_a: (3x3) jacobian of res (3) wrt arg a (3)
 *     res_D_b: (3x3) jacobian of res (3) wrt arg b (3)
 */
template <typename Scalar>
sym::Pose2<Scalar> GroupOps<Pose2<Scalar>>::BetweenWithJacobians(const sym::Pose2<Scalar>& a,
                                                                 const sym::Pose2<Scalar>& b,
                                                                 SelfJacobian* const res_D_a,
                                                                 SelfJacobian* const res_D_b) {
  // Total ops: 35

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _b = b.Data();

  // Intermediate terms (14)
  const Scalar _tmp0 = _a[1] * _b[1];
  const Scalar _tmp1 = _a[0] * _b[0];
  const Scalar _tmp2 = _tmp0 + _tmp1;
  const Scalar _tmp3 = _a[1] * _b[0];
  const Scalar _tmp4 = _a[0] * _b[1];
  const Scalar _tmp5 = -_tmp3 + _tmp4;
  const Scalar _tmp6 = _a[0] * _a[2] + _a[1] * _a[3];
  const Scalar _tmp7 = _a[1] * _b[3];
  const Scalar _tmp8 = _a[0] * _b[2];
  const Scalar _tmp9 = _a[1] * _a[2];
  const Scalar _tmp10 = _a[0] * _a[3];
  const Scalar _tmp11 = _a[0] * _b[3] - _a[1] * _b[2];
  const Scalar _tmp12 = -_a[0];
  const Scalar _tmp13 = -_a[1];

  // Output terms (3)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = _tmp2;
  _res[1] = _tmp5;
  _res[2] = -_tmp6 + _tmp7 + _tmp8;
  _res[3] = -_tmp10 + _tmp11 + _tmp9;

  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _res_D_a = (*res_D_a);

    _res_D_a(0, 0) = _tmp2 * (-_tmp0 - _tmp1) - std::pow(_tmp5, Scalar(2));
    _res_D_a(1, 0) = -_tmp10 + _tmp11 + _tmp9;
    _res_D_a(2, 0) = _tmp6 - _tmp7 - _tmp8;
    _res_D_a(0, 1) = 0;
    _res_D_a(1, 1) = _tmp12;
    _res_D_a(2, 1) = _a[1];
    _res_D_a(0, 2) = 0;
    _res_D_a(1, 2) = _tmp13;
    _res_D_a(2, 2) = _tmp12;
  }

  if (res_D_b != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _res_D_b = (*res_D_b);

    _res_D_b(0, 0) = std::pow(_tmp2, Scalar(2)) - _tmp5 * (_tmp3 - _tmp4);
    _res_D_b(1, 0) = 0;
    _res_D_b(2, 0) = 0;
    _res_D_b(0, 1) = 0;
    _res_D_b(1, 1) = _a[0];
    _res_D_b(2, 1) = _tmp13;
    _res_D_b(0, 2) = 0;
    _res_D_b(1, 2) = _a[1];
    _res_D_b(2, 2) = _a[0];
  }

  return sym::Pose2<Scalar>(_res);
}

}  // namespace sym

// Explicit instantiation
template struct sym::GroupOps<sym::Pose2<double>>;
template struct sym::GroupOps<sym::Pose2<float>>;
