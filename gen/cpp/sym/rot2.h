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
 * Autogenerated C++ implementation of `symforce.geo.rot2.Rot2`.
 *
 * Group of two-dimensional orthogonal matrices with determinant ``+1``, representing rotations
 * in 2D space. Backed by a complex number.
 */
template <typename ScalarType>
class Rot2 {
 public:
  // Typedefs
  using Scalar = ScalarType;
  using Self = Rot2<Scalar>;
  using DataVec = Eigen::Matrix<Scalar, 2, 1>;
  using TangentVec = Eigen::Matrix<Scalar, 1, 1>;
  using SelfJacobian = Eigen::Matrix<Scalar, 1, 1>;

  /**
   * Construct from data vec
   *
   * @param normalize Project to the manifold on construction.  This ensures numerical stability as
   *     this constructor is called after each codegen operation.  Constructing from a normalized
   *     vector may be faster, e.g. with `FromStorage`.
   */
  explicit Rot2(const DataVec& data, const bool normalize = true)
      : data_(normalize ? data.normalized() : data) {}

  // Default construct to identity
  Rot2() : Rot2(GroupOps<Self>::Identity()) {}

  // Access underlying storage as const
  inline const DataVec& Data() const {
    return data_;
  }

  // Matrix type aliases
  using Vector2 = Eigen::Matrix<Scalar, 2, 1>;

  // --------------------------------------------------------------------------
  // Handwritten methods included from "custom_methods/rot2.h.jinja"
  // --------------------------------------------------------------------------

  // Generate a random element of SO2 from a number u1 in [0, 1]
  static Rot2 RandomFromUniformSamples(const Scalar u1) {
    const Scalar theta = 2 * M_PI * u1;
    return Rot2(Eigen::Matrix<Scalar, 2, 1>(std::cos(theta), std::sin(theta)));
  }

  // Generate a random element in SO2
  template <typename Generator>
  static Rot2 Random(Generator& gen) {
    std::uniform_real_distribution<Scalar> dist(0.0, 1.0);
    return RandomFromUniformSamples(dist(gen));
  }

  // Construct Rot2 representing rotation by angle
  explicit Rot2(const Scalar angle) : Rot2(FromAngle(angle)) {}

  // --------------------------------------------------------------------------
  // Custom generated methods
  // --------------------------------------------------------------------------

  /**
   * Left-multiplication. Either rotation concatenation or point transform.
   */
  const Vector2 ComposeWithPoint(const Vector2& right) const;

  /**
   * Create a Rot2 from an angle ``theta`` in radians
   *
   * This is equivalent to ``from_tangent([theta])``
   */
  const static sym::Rot2<Scalar> FromAngle(const Scalar theta);

  /**
   * A matrix representation of this element in the Euclidean space that contains it.
   */
  const Eigen::Matrix<Scalar, 2, 2> ToRotationMatrix() const;

  /**
   * Create a Rot2 from a 2x2 rotation matrix.
   *
   * Returns the closest Rot2 to the input matrix, by the Frobenius norm.  Will be singular when
   * ``r[0, 0] == -r[1, 1]`` and ``r[0, 1] == r[1, 0]`` are both true.
   *
   * See notebooks/rot2_from_rotation_matrix_derivation.ipynb for the derivation.
   */
  const static sym::Rot2<Scalar> FromRotationMatrix(const Eigen::Matrix<Scalar, 2, 2>& r);

  /**
   * Generate a random element of SO2 from a variable uniformly sampled on [0, 1].
   */
  const static sym::Rot2<Scalar> RandomFromUniformSample(const Scalar u1);

  // --------------------------------------------------------------------------
  // StorageOps concept
  // --------------------------------------------------------------------------

  static constexpr int32_t StorageDim() {
    return StorageOps<Self>::StorageDim();
  }

  void ToStorage(Scalar* const vec) const {
    return StorageOps<Self>::ToStorage(*this, vec);
  }

  static Rot2 FromStorage(const Scalar* const vec) {
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

  Vector2 Compose(const Vector2& point) const {
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
  Rot2<ToScalar> Cast() const {
    return Rot2<ToScalar>(Data().template cast<ToScalar>());
  }

  bool operator==(const Rot2& rhs) const {
    return data_ == rhs.Data();
  }

  bool operator!=(const Rot2& rhs) const {
    return !(*this == rhs);
  }

 protected:
  DataVec data_;
};

// Shorthand for scalar types
using Rot2d = Rot2<double>;
using Rot2f = Rot2<float>;

// Print definitions
std::ostream& operator<<(std::ostream& os, const Rot2<double>& a);
std::ostream& operator<<(std::ostream& os, const Rot2<float>& a);

}  // namespace sym

// Externs to reduce duplicate instantiation
extern template class sym::Rot2<double>;
extern template class sym::Rot2<float>;

// Concept implementations for this class
#include "./ops/rot2/group_ops.h"
#include "./ops/rot2/lie_group_ops.h"
#include "./ops/rot2/storage_ops.h"
