// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     geo_package/CLASS.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <ostream>
#include <random>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Geometry>

#include <sym/ops/group_ops.h>
#include <sym/ops/lie_group_ops.h>
#include <sym/ops/storage_ops.h>
#include <sym/util/epsilon.h>

namespace sym {

/**
 * Autogenerated C++ implementation of `symforce.geo.rot3.Rot3`.
 *
 * Group of three-dimensional orthogonal matrices with determinant ``+1``, representing
 * rotations in 3D space. Backed by a quaternion with (x, y, z, w) storage.
 */
template <typename ScalarType>
class Rot3 {
 public:
  // Typedefs
  using Scalar = ScalarType;
  using Self = Rot3<Scalar>;
  using DataVec = Eigen::Matrix<Scalar, 4, 1>;
  using TangentVec = Eigen::Matrix<Scalar, 3, 1>;
  using SelfJacobian = Eigen::Matrix<Scalar, 3, 3>;

  /**
   * Construct from data vec
   *
   * @param normalize Project to the manifold on construction.  This ensures numerical stability as
   *     this constructor is called after each codegen operation.  Constructing from a normalized
   *     vector may be faster, e.g. with `FromStorage`.
   */
  explicit Rot3(const DataVec& data, const bool normalize = true)
      : data_(normalize ? data.normalized() : data) {}

  // Default construct to identity
  Rot3() : Rot3(GroupOps<Self>::Identity()) {}

  // Access underlying storage as const
  inline const DataVec& Data() const {
    return data_;
  }

  // Matrix type aliases
  using Vector3 = Eigen::Matrix<Scalar, 3, 1>;

  // --------------------------------------------------------------------------
  // Handwritten methods included from "custom_methods/rot3.h.jinja"
  // --------------------------------------------------------------------------

  // Quaternion

  Eigen::Quaternion<Scalar> Quaternion() const {
    return Eigen::Quaternion<Scalar>(data_.data());
  }

  explicit Rot3(const Eigen::Quaternion<Scalar>& q) : Rot3(q.coeffs()) {}

  static Rot3 FromQuaternion(const Eigen::Quaternion<Scalar>& q) {
    return Rot3(q);
  }

  // Angle-axis

  Eigen::AngleAxis<Scalar> AngleAxis() const {
    return Eigen::AngleAxis<Scalar>(Quaternion());
  }

  explicit Rot3(const Eigen::AngleAxis<Scalar>& aa) : Rot3(Eigen::Quaternion<Scalar>(aa)) {}

  static Rot3 FromAngleAxis(const Eigen::AngleAxis<Scalar>& aa) {
    return Rot3(aa);
  }

  static Rot3 FromAngleAxis(const Scalar angle, const Vector3& axis) {
    return Rot3(Eigen::AngleAxis<Scalar>(angle, axis));
  }

  // Rotation matrix

  // Note: ToRotationMatrix is autogenerated below

  static Rot3 FromRotationMatrix(const Eigen::Matrix<Scalar, 3, 3>& mat) {
    return Rot3(Eigen::Quaternion<Scalar>(mat));
  }

  // Generate a random element in SO3
  template <typename Generator>
  static Rot3 Random(Generator& gen) {
    std::uniform_real_distribution<Scalar> dist(0.0, 1.0);
    // This cannot be combined into RandomFromUniformSamples(dist(gen), dist(gen), dist(gen)),
    // because the standard does not guarantee evaluation order of arguments,
    // meaning that we would get different results on different compilers.
    const auto dist0 = dist(gen);
    const auto dist1 = dist(gen);
    const auto dist2 = dist(gen);
    return RandomFromUniformSamples(dist0, dist1, dist2);
  }

  // Flip the quaternion if needed to give a positive real part (w).
  // This can be useful for comparing rotations where double cover is an issue.
  Rot3 ToPositiveReal() const {
    if (Data()[3] < 0) {
      return Rot3(-Data());
    } else {
      return Rot3(Data());
    }
  }

  // --------------------------------------------------------------------------
  // Custom generated methods
  // --------------------------------------------------------------------------

  /**
   * Left-multiplication. Either rotation concatenation or point transform.
   */
  const Vector3 ComposeWithPoint(const Vector3& right) const;

  /**
   * Returns the norm of the tangent vector corresponding to this rotation
   *
   * This is equal to the angle that should be rotated through to get this Rot3, in radians.
   * Using this function directly is usually more efficient than computing the norm of the
   * tangent vector, both in symbolic and generated code; by default, symbolic APIs will not
   * automatically simplify to this
   */
  const Scalar ToTangentNorm(const Scalar epsilon) const;

  /**
   * Converts to a rotation matrix
   */
  const Eigen::Matrix<Scalar, 3, 3> ToRotationMatrix() const;

  /**
   * Generate a random element of SO3 from three variables uniformly sampled in [0, 1].
   */
  const static sym::Rot3<Scalar> RandomFromUniformSamples(const Scalar u1, const Scalar u2,
                                                          const Scalar u3);

  /**
   * Compute the yaw, pitch, and roll Euler angles in radians of this rotation
   *
   * Euler angles are subject to gimbal lock: https://en.wikipedia.org/wiki/Gimbal_lock
   *
   * This means that when the pitch is close to +/- pi/2, the yaw and roll angles are not
   * uniquely defined, so the returned values are not unique in this case.
   *
   * Returns:
   *     Scalar: Yaw angle [radians]
   *     Scalar: Pitch angle [radians]
   *     Scalar: Roll angle [radians]
   */
  const Vector3 ToYawPitchRoll() const;

  /**
   * Construct from yaw, pitch, and roll Euler angles in radians
   */
  const static sym::Rot3<Scalar> FromYawPitchRoll(const Scalar yaw, const Scalar pitch,
                                                  const Scalar roll);

  /**
   * This function was autogenerated from a symbolic function. Do not modify by hand.
   *
   * Symbolic function: <lambda>
   *
   * Args:
   *     ypr: Matrix31
   *
   * Outputs:
   *     res: Rot3
   */
  const static sym::Rot3<Scalar> FromYawPitchRoll(const Vector3& ypr);

  /**
   * Return a rotation that transforms a to b. Both inputs are three-vectors that
   * are expected to be normalized.
   *
   * Reference:
   *     http://lolengine.net/blog/2013/09/18/beautiful-maths-quaternion-from-vectors
   */
  const static sym::Rot3<Scalar> FromTwoUnitVectors(const Vector3& a, const Vector3& b,
                                                    const Scalar epsilon);

  // --------------------------------------------------------------------------
  // StorageOps concept
  // --------------------------------------------------------------------------

  static constexpr int32_t StorageDim() {
    return StorageOps<Self>::StorageDim();
  }

  void ToStorage(Scalar* const vec) const {
    return StorageOps<Self>::ToStorage(*this, vec);
  }

  static Rot3 FromStorage(const Scalar* const vec) {
    return StorageOps<Self>::FromStorage(vec);
  }

  // --------------------------------------------------------------------------
  // GroupOps concept
  // --------------------------------------------------------------------------

  static Self Identity() {
    return GroupOps<Self>::Identity();
  }

  Self Inverse() const {
    return GroupOps<Self>::Inverse(*this);
  }

  Self Compose(const Self& b) const {
    return GroupOps<Self>::Compose(*this, b);
  }

  Vector3 Compose(const Vector3& point) const {
    return ComposeWithPoint(point);
  }

  Self Between(const Self& b) const {
    return GroupOps<Self>::Between(*this, b);
  }

  Self InverseWithJacobian(SelfJacobian* const res_D_a = nullptr) const {
    return GroupOps<Self>::InverseWithJacobian(*this, res_D_a);
  }

  Self ComposeWithJacobians(const Self& b, SelfJacobian* const res_D_a = nullptr,
                            SelfJacobian* const res_D_b = nullptr) const {
    return GroupOps<Self>::ComposeWithJacobians(*this, b, res_D_a, res_D_b);
  }

  Self BetweenWithJacobians(const Self& b, SelfJacobian* const res_D_a = nullptr,
                            SelfJacobian* const res_D_b = nullptr) const {
    return GroupOps<Self>::BetweenWithJacobians(*this, b, res_D_a, res_D_b);
  }

  // Compose shorthand
  template <typename Other>
  auto operator*(const Other& b) const -> decltype(Compose(b)) {
    return Compose(b);
  }

  // --------------------------------------------------------------------------
  // LieGroupOps concept
  // --------------------------------------------------------------------------

  static constexpr int32_t TangentDim() {
    return LieGroupOps<Self>::TangentDim();
  }

  static Self FromTangent(const TangentVec& vec, const Scalar epsilon = kDefaultEpsilon<Scalar>) {
    return LieGroupOps<Self>::FromTangent(vec, epsilon);
  }

  TangentVec ToTangent(const Scalar epsilon = kDefaultEpsilon<Scalar>) const {
    return LieGroupOps<Self>::ToTangent(*this, epsilon);
  }

  Self Retract(const TangentVec& vec, const Scalar epsilon = kDefaultEpsilon<Scalar>) const {
    return LieGroupOps<Self>::Retract(*this, vec, epsilon);
  }

  TangentVec LocalCoordinates(const Self& b, const Scalar epsilon = kDefaultEpsilon<Scalar>) const {
    return LieGroupOps<Self>::LocalCoordinates(*this, b, epsilon);
  }

  Self Interpolate(const Self b, const Scalar alpha,
                   const Scalar epsilon = kDefaultEpsilon<Scalar>) const {
    return LieGroupOps<Self>::Interpolate(*this, b, alpha, epsilon);
  }

  // --------------------------------------------------------------------------
  // General Helpers
  // --------------------------------------------------------------------------

  bool IsApprox(const Self& b, const Scalar tol) const {
    // isApprox is multiplicative so we check the norm for the exact zero case
    // https://eigen.tuxfamily.org/dox/classEigen_1_1DenseBase.html#ae8443357b808cd393be1b51974213f9c
    if (b.Data() == DataVec::Zero()) {
      return Data().norm() < tol;
    }

    return Data().isApprox(b.Data(), tol);
  }

  template <typename ToScalar>
  Rot3<ToScalar> Cast() const {
    return Rot3<ToScalar>(Data().template cast<ToScalar>());
  }

  bool operator==(const Rot3& rhs) const {
    return data_ == rhs.Data();
  }

 protected:
  DataVec data_;
};

// Shorthand for scalar types
using Rot3d = Rot3<double>;
using Rot3f = Rot3<float>;

// Print definitions
std::ostream& operator<<(std::ostream& os, const Rot3<double>& a);
std::ostream& operator<<(std::ostream& os, const Rot3<float>& a);

}  // namespace sym

// Externs to reduce duplicate instantiation
extern template class sym::Rot3<double>;
extern template class sym::Rot3<float>;

// Concept implementations for this class
#include "./ops/rot3/group_ops.h"
#include "./ops/rot3/lie_group_ops.h"
#include "./ops/rot3/storage_ops.h"
