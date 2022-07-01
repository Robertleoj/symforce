// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     backends/cpp/templates/geo_package/ops/matrix/storage_ops.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <cassert>
#include <random>

#include <Eigen/Dense>

#include <lcmtypes/sym/type_t.hpp>

#include "../storage_ops.h"

namespace sym {

/**
 * C++ StorageOps implementation for fixed size matrices.
 */
template <typename ScalarType, int Rows, int Cols>
struct StorageOps<Eigen::Matrix<ScalarType, Rows, Cols>> {
  using Scalar = ScalarType;
  using T = Eigen::Matrix<Scalar, Rows, Cols>;
  static_assert(std::is_floating_point<ScalarType>::value, "");

  static constexpr int32_t StorageDim() {
    return Rows * Cols;
  }

  static void ToStorage(const T& a, ScalarType* out) {
    assert(out != nullptr);
    std::copy_n(a.data(), a.size(), out);
  }

  static T FromStorage(const ScalarType* data) {
    assert(data != nullptr);
    return Eigen::Map<const T>(data);
  }

  static constexpr type_t TypeEnum() {
    if (Rows == 1 && Cols == 1) {
      return type_t::VECTOR1;
    } else if (Rows == 2 && Cols == 1) {
      return type_t::VECTOR2;
    } else if (Rows == 3 && Cols == 1) {
      return type_t::VECTOR3;
    } else if (Rows == 4 && Cols == 1) {
      return type_t::VECTOR4;
    } else if (Rows == 5 && Cols == 1) {
      return type_t::VECTOR5;
    } else if (Rows == 6 && Cols == 1) {
      return type_t::VECTOR6;
    } else if (Rows == 7 && Cols == 1) {
      return type_t::VECTOR7;
    } else if (Rows == 8 && Cols == 1) {
      return type_t::VECTOR8;
    } else if (Rows == 9 && Cols == 1) {
      return type_t::VECTOR9;
    } else if (Rows == 1 && Cols == 2) {
      return type_t::MATRIX12;
    } else if (Rows == 1 && Cols == 3) {
      return type_t::MATRIX13;
    } else if (Rows == 1 && Cols == 4) {
      return type_t::MATRIX14;
    } else if (Rows == 1 && Cols == 5) {
      return type_t::MATRIX15;
    } else if (Rows == 1 && Cols == 6) {
      return type_t::MATRIX16;
    } else if (Rows == 1 && Cols == 7) {
      return type_t::MATRIX17;
    } else if (Rows == 1 && Cols == 8) {
      return type_t::MATRIX18;
    } else if (Rows == 1 && Cols == 9) {
      return type_t::MATRIX19;
    } else if (Rows == 2 && Cols == 2) {
      return type_t::MATRIX22;
    } else if (Rows == 2 && Cols == 3) {
      return type_t::MATRIX23;
    } else if (Rows == 2 && Cols == 4) {
      return type_t::MATRIX24;
    } else if (Rows == 2 && Cols == 5) {
      return type_t::MATRIX25;
    } else if (Rows == 2 && Cols == 6) {
      return type_t::MATRIX26;
    } else if (Rows == 2 && Cols == 7) {
      return type_t::MATRIX27;
    } else if (Rows == 2 && Cols == 8) {
      return type_t::MATRIX28;
    } else if (Rows == 2 && Cols == 9) {
      return type_t::MATRIX29;
    } else if (Rows == 3 && Cols == 2) {
      return type_t::MATRIX32;
    } else if (Rows == 3 && Cols == 3) {
      return type_t::MATRIX33;
    } else if (Rows == 3 && Cols == 4) {
      return type_t::MATRIX34;
    } else if (Rows == 3 && Cols == 5) {
      return type_t::MATRIX35;
    } else if (Rows == 3 && Cols == 6) {
      return type_t::MATRIX36;
    } else if (Rows == 3 && Cols == 7) {
      return type_t::MATRIX37;
    } else if (Rows == 3 && Cols == 8) {
      return type_t::MATRIX38;
    } else if (Rows == 3 && Cols == 9) {
      return type_t::MATRIX39;
    } else if (Rows == 4 && Cols == 2) {
      return type_t::MATRIX42;
    } else if (Rows == 4 && Cols == 3) {
      return type_t::MATRIX43;
    } else if (Rows == 4 && Cols == 4) {
      return type_t::MATRIX44;
    } else if (Rows == 4 && Cols == 5) {
      return type_t::MATRIX45;
    } else if (Rows == 4 && Cols == 6) {
      return type_t::MATRIX46;
    } else if (Rows == 4 && Cols == 7) {
      return type_t::MATRIX47;
    } else if (Rows == 4 && Cols == 8) {
      return type_t::MATRIX48;
    } else if (Rows == 4 && Cols == 9) {
      return type_t::MATRIX49;
    } else if (Rows == 5 && Cols == 2) {
      return type_t::MATRIX52;
    } else if (Rows == 5 && Cols == 3) {
      return type_t::MATRIX53;
    } else if (Rows == 5 && Cols == 4) {
      return type_t::MATRIX54;
    } else if (Rows == 5 && Cols == 5) {
      return type_t::MATRIX55;
    } else if (Rows == 5 && Cols == 6) {
      return type_t::MATRIX56;
    } else if (Rows == 5 && Cols == 7) {
      return type_t::MATRIX57;
    } else if (Rows == 5 && Cols == 8) {
      return type_t::MATRIX58;
    } else if (Rows == 5 && Cols == 9) {
      return type_t::MATRIX59;
    } else if (Rows == 6 && Cols == 2) {
      return type_t::MATRIX62;
    } else if (Rows == 6 && Cols == 3) {
      return type_t::MATRIX63;
    } else if (Rows == 6 && Cols == 4) {
      return type_t::MATRIX64;
    } else if (Rows == 6 && Cols == 5) {
      return type_t::MATRIX65;
    } else if (Rows == 6 && Cols == 6) {
      return type_t::MATRIX66;
    } else if (Rows == 6 && Cols == 7) {
      return type_t::MATRIX67;
    } else if (Rows == 6 && Cols == 8) {
      return type_t::MATRIX68;
    } else if (Rows == 6 && Cols == 9) {
      return type_t::MATRIX69;
    } else if (Rows == 7 && Cols == 2) {
      return type_t::MATRIX72;
    } else if (Rows == 7 && Cols == 3) {
      return type_t::MATRIX73;
    } else if (Rows == 7 && Cols == 4) {
      return type_t::MATRIX74;
    } else if (Rows == 7 && Cols == 5) {
      return type_t::MATRIX75;
    } else if (Rows == 7 && Cols == 6) {
      return type_t::MATRIX76;
    } else if (Rows == 7 && Cols == 7) {
      return type_t::MATRIX77;
    } else if (Rows == 7 && Cols == 8) {
      return type_t::MATRIX78;
    } else if (Rows == 7 && Cols == 9) {
      return type_t::MATRIX79;
    } else if (Rows == 8 && Cols == 2) {
      return type_t::MATRIX82;
    } else if (Rows == 8 && Cols == 3) {
      return type_t::MATRIX83;
    } else if (Rows == 8 && Cols == 4) {
      return type_t::MATRIX84;
    } else if (Rows == 8 && Cols == 5) {
      return type_t::MATRIX85;
    } else if (Rows == 8 && Cols == 6) {
      return type_t::MATRIX86;
    } else if (Rows == 8 && Cols == 7) {
      return type_t::MATRIX87;
    } else if (Rows == 8 && Cols == 8) {
      return type_t::MATRIX88;
    } else if (Rows == 8 && Cols == 9) {
      return type_t::MATRIX89;
    } else if (Rows == 9 && Cols == 2) {
      return type_t::MATRIX92;
    } else if (Rows == 9 && Cols == 3) {
      return type_t::MATRIX93;
    } else if (Rows == 9 && Cols == 4) {
      return type_t::MATRIX94;
    } else if (Rows == 9 && Cols == 5) {
      return type_t::MATRIX95;
    } else if (Rows == 9 && Cols == 6) {
      return type_t::MATRIX96;
    } else if (Rows == 9 && Cols == 7) {
      return type_t::MATRIX97;
    } else if (Rows == 9 && Cols == 8) {
      return type_t::MATRIX98;
    } else if (Rows == 9 && Cols == 9) {
      return type_t::MATRIX99;
    } else {
      return type_t::INVALID;
    }
  }

  template <typename Generator>
  static T Random(Generator& gen) {
    static_assert(T::RowsAtCompileTime != Eigen::Dynamic, "Size must be known at compile time");
    static_assert(T::ColsAtCompileTime != Eigen::Dynamic, "Size must be known at compile time");

    std::normal_distribution<Scalar> distribution{};
    return T::NullaryExpr([&]() { return distribution(gen); });
  }
};

}  // namespace sym

// Explicit instantiation
extern template struct sym::StorageOps<Eigen::Matrix<double, 1, 1>>;
extern template struct sym::StorageOps<Eigen::Matrix<double, 2, 1>>;
extern template struct sym::StorageOps<Eigen::Matrix<double, 3, 1>>;
extern template struct sym::StorageOps<Eigen::Matrix<double, 4, 1>>;
extern template struct sym::StorageOps<Eigen::Matrix<double, 5, 1>>;
extern template struct sym::StorageOps<Eigen::Matrix<double, 6, 1>>;
extern template struct sym::StorageOps<Eigen::Matrix<double, 7, 1>>;
extern template struct sym::StorageOps<Eigen::Matrix<double, 8, 1>>;
extern template struct sym::StorageOps<Eigen::Matrix<double, 9, 1>>;
extern template struct sym::StorageOps<Eigen::Matrix<double, 2, 2>>;
extern template struct sym::StorageOps<Eigen::Matrix<double, 3, 3>>;
extern template struct sym::StorageOps<Eigen::Matrix<double, 4, 4>>;
extern template struct sym::StorageOps<Eigen::Matrix<double, 5, 5>>;
extern template struct sym::StorageOps<Eigen::Matrix<double, 6, 6>>;
extern template struct sym::StorageOps<Eigen::Matrix<double, 7, 7>>;
extern template struct sym::StorageOps<Eigen::Matrix<double, 8, 8>>;
extern template struct sym::StorageOps<Eigen::Matrix<double, 9, 9>>;
extern template struct sym::StorageOps<Eigen::Matrix<float, 1, 1>>;
extern template struct sym::StorageOps<Eigen::Matrix<float, 2, 1>>;
extern template struct sym::StorageOps<Eigen::Matrix<float, 3, 1>>;
extern template struct sym::StorageOps<Eigen::Matrix<float, 4, 1>>;
extern template struct sym::StorageOps<Eigen::Matrix<float, 5, 1>>;
extern template struct sym::StorageOps<Eigen::Matrix<float, 6, 1>>;
extern template struct sym::StorageOps<Eigen::Matrix<float, 7, 1>>;
extern template struct sym::StorageOps<Eigen::Matrix<float, 8, 1>>;
extern template struct sym::StorageOps<Eigen::Matrix<float, 9, 1>>;
extern template struct sym::StorageOps<Eigen::Matrix<float, 2, 2>>;
extern template struct sym::StorageOps<Eigen::Matrix<float, 3, 3>>;
extern template struct sym::StorageOps<Eigen::Matrix<float, 4, 4>>;
extern template struct sym::StorageOps<Eigen::Matrix<float, 5, 5>>;
extern template struct sym::StorageOps<Eigen::Matrix<float, 6, 6>>;
extern template struct sym::StorageOps<Eigen::Matrix<float, 7, 7>>;
extern template struct sym::StorageOps<Eigen::Matrix<float, 8, 8>>;
extern template struct sym::StorageOps<Eigen::Matrix<float, 9, 9>>;
