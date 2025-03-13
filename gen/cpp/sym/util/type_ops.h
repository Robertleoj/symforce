// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     type_ops.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Core>
#include <Eigen/SparseCore>

// Import all the known types.
#include <lcmtypes/sym/type_t.hpp>

#include <sym/atan_camera_cal.h>
#include <sym/double_sphere_camera_cal.h>
#include <sym/equirectangular_camera_cal.h>
#include <sym/linear_camera_cal.h>
#include <sym/ops/lie_group_ops.h>
#include <sym/ops/storage_ops.h>
#include <sym/orthographic_camera_cal.h>
#include <sym/polynomial_camera_cal.h>
#include <sym/pose2.h>
#include <sym/pose3.h>
#include <sym/rot2.h>
#include <sym/rot3.h>
#include <sym/spherical_camera_cal.h>
#include <sym/unit3.h>
#include <sym/util/typedefs.h>
#include <symforce/opt/assert.h>

namespace sym {

template <typename T>
static constexpr const bool kIsEigenType = std::is_base_of<Eigen::MatrixBase<T>, T>::value;

template <typename T>
static constexpr const bool kIsSparseEigenType =
    std::is_base_of<Eigen::SparseMatrix<typename T::Scalar>, T>::value;

inline bool IsEigenType(const type_t type) {
  switch (type.value) {
    case type_t::VECTOR1:
    case type_t::VECTOR2:
    case type_t::VECTOR3:
    case type_t::VECTOR4:
    case type_t::VECTOR5:
    case type_t::VECTOR6:
    case type_t::VECTOR7:
    case type_t::VECTOR8:
    case type_t::VECTOR9:
    case type_t::VECTORX:
    case type_t::MATRIX12:
    case type_t::MATRIX13:
    case type_t::MATRIX14:
    case type_t::MATRIX15:
    case type_t::MATRIX16:
    case type_t::MATRIX17:
    case type_t::MATRIX18:
    case type_t::MATRIX19:
    case type_t::MATRIX22:
    case type_t::MATRIX23:
    case type_t::MATRIX24:
    case type_t::MATRIX25:
    case type_t::MATRIX26:
    case type_t::MATRIX27:
    case type_t::MATRIX28:
    case type_t::MATRIX29:
    case type_t::MATRIX32:
    case type_t::MATRIX33:
    case type_t::MATRIX34:
    case type_t::MATRIX35:
    case type_t::MATRIX36:
    case type_t::MATRIX37:
    case type_t::MATRIX38:
    case type_t::MATRIX39:
    case type_t::MATRIX42:
    case type_t::MATRIX43:
    case type_t::MATRIX44:
    case type_t::MATRIX45:
    case type_t::MATRIX46:
    case type_t::MATRIX47:
    case type_t::MATRIX48:
    case type_t::MATRIX49:
    case type_t::MATRIX52:
    case type_t::MATRIX53:
    case type_t::MATRIX54:
    case type_t::MATRIX55:
    case type_t::MATRIX56:
    case type_t::MATRIX57:
    case type_t::MATRIX58:
    case type_t::MATRIX59:
    case type_t::MATRIX62:
    case type_t::MATRIX63:
    case type_t::MATRIX64:
    case type_t::MATRIX65:
    case type_t::MATRIX66:
    case type_t::MATRIX67:
    case type_t::MATRIX68:
    case type_t::MATRIX69:
    case type_t::MATRIX72:
    case type_t::MATRIX73:
    case type_t::MATRIX74:
    case type_t::MATRIX75:
    case type_t::MATRIX76:
    case type_t::MATRIX77:
    case type_t::MATRIX78:
    case type_t::MATRIX79:
    case type_t::MATRIX82:
    case type_t::MATRIX83:
    case type_t::MATRIX84:
    case type_t::MATRIX85:
    case type_t::MATRIX86:
    case type_t::MATRIX87:
    case type_t::MATRIX88:
    case type_t::MATRIX89:
    case type_t::MATRIX92:
    case type_t::MATRIX93:
    case type_t::MATRIX94:
    case type_t::MATRIX95:
    case type_t::MATRIX96:
    case type_t::MATRIX97:
    case type_t::MATRIX98:
    case type_t::MATRIX99:
      return true;
    case type_t::ROT2:
    case type_t::ROT3:
    case type_t::POSE2:
    case type_t::POSE3:
    case type_t::UNIT3:
    case type_t::SCALAR:
    case type_t::ATAN_CAMERA_CAL:
    case type_t::DOUBLE_SPHERE_CAMERA_CAL:
    case type_t::EQUIRECTANGULAR_CAMERA_CAL:
    case type_t::LINEAR_CAMERA_CAL:
    case type_t::POLYNOMIAL_CAMERA_CAL:
    case type_t::SPHERICAL_CAMERA_CAL:
    case type_t::ORTHOGRAPHIC_CAMERA_CAL:
    case type_t::DATABUFFER:
    case type_t::PREINTEGRATED_IMU_MEASUREMENTS:
      return false;
    case type_t::INVALID:
      SYM_ASSERT(false, "Invalid type");
  }
  SYM_ASSERT(false, "Unreachable");  // gcc (at least >=5,<=11) does not prove this is unreachable
}

/**
 *  Returns the shape of an Eigen type as a pair of ints (rows, cols)
 */
inline std::pair<int, int> EigenTypeShape(const type_t type) {
  switch (type.value) {
    case type_t::VECTOR1:
      return {1, 1};
    case type_t::VECTOR2:
      return {2, 1};
    case type_t::VECTOR3:
      return {3, 1};
    case type_t::VECTOR4:
      return {4, 1};
    case type_t::VECTOR5:
      return {5, 1};
    case type_t::VECTOR6:
      return {6, 1};
    case type_t::VECTOR7:
      return {7, 1};
    case type_t::VECTOR8:
      return {8, 1};
    case type_t::VECTOR9:
      return {9, 1};
    case type_t::MATRIX12:
      return {1, 2};
    case type_t::MATRIX13:
      return {1, 3};
    case type_t::MATRIX14:
      return {1, 4};
    case type_t::MATRIX15:
      return {1, 5};
    case type_t::MATRIX16:
      return {1, 6};
    case type_t::MATRIX17:
      return {1, 7};
    case type_t::MATRIX18:
      return {1, 8};
    case type_t::MATRIX19:
      return {1, 9};
    case type_t::MATRIX22:
      return {2, 2};
    case type_t::MATRIX23:
      return {2, 3};
    case type_t::MATRIX24:
      return {2, 4};
    case type_t::MATRIX25:
      return {2, 5};
    case type_t::MATRIX26:
      return {2, 6};
    case type_t::MATRIX27:
      return {2, 7};
    case type_t::MATRIX28:
      return {2, 8};
    case type_t::MATRIX29:
      return {2, 9};
    case type_t::MATRIX32:
      return {3, 2};
    case type_t::MATRIX33:
      return {3, 3};
    case type_t::MATRIX34:
      return {3, 4};
    case type_t::MATRIX35:
      return {3, 5};
    case type_t::MATRIX36:
      return {3, 6};
    case type_t::MATRIX37:
      return {3, 7};
    case type_t::MATRIX38:
      return {3, 8};
    case type_t::MATRIX39:
      return {3, 9};
    case type_t::MATRIX42:
      return {4, 2};
    case type_t::MATRIX43:
      return {4, 3};
    case type_t::MATRIX44:
      return {4, 4};
    case type_t::MATRIX45:
      return {4, 5};
    case type_t::MATRIX46:
      return {4, 6};
    case type_t::MATRIX47:
      return {4, 7};
    case type_t::MATRIX48:
      return {4, 8};
    case type_t::MATRIX49:
      return {4, 9};
    case type_t::MATRIX52:
      return {5, 2};
    case type_t::MATRIX53:
      return {5, 3};
    case type_t::MATRIX54:
      return {5, 4};
    case type_t::MATRIX55:
      return {5, 5};
    case type_t::MATRIX56:
      return {5, 6};
    case type_t::MATRIX57:
      return {5, 7};
    case type_t::MATRIX58:
      return {5, 8};
    case type_t::MATRIX59:
      return {5, 9};
    case type_t::MATRIX62:
      return {6, 2};
    case type_t::MATRIX63:
      return {6, 3};
    case type_t::MATRIX64:
      return {6, 4};
    case type_t::MATRIX65:
      return {6, 5};
    case type_t::MATRIX66:
      return {6, 6};
    case type_t::MATRIX67:
      return {6, 7};
    case type_t::MATRIX68:
      return {6, 8};
    case type_t::MATRIX69:
      return {6, 9};
    case type_t::MATRIX72:
      return {7, 2};
    case type_t::MATRIX73:
      return {7, 3};
    case type_t::MATRIX74:
      return {7, 4};
    case type_t::MATRIX75:
      return {7, 5};
    case type_t::MATRIX76:
      return {7, 6};
    case type_t::MATRIX77:
      return {7, 7};
    case type_t::MATRIX78:
      return {7, 8};
    case type_t::MATRIX79:
      return {7, 9};
    case type_t::MATRIX82:
      return {8, 2};
    case type_t::MATRIX83:
      return {8, 3};
    case type_t::MATRIX84:
      return {8, 4};
    case type_t::MATRIX85:
      return {8, 5};
    case type_t::MATRIX86:
      return {8, 6};
    case type_t::MATRIX87:
      return {8, 7};
    case type_t::MATRIX88:
      return {8, 8};
    case type_t::MATRIX89:
      return {8, 9};
    case type_t::MATRIX92:
      return {9, 2};
    case type_t::MATRIX93:
      return {9, 3};
    case type_t::MATRIX94:
      return {9, 4};
    case type_t::MATRIX95:
      return {9, 5};
    case type_t::MATRIX96:
      return {9, 6};
    case type_t::MATRIX97:
      return {9, 7};
    case type_t::MATRIX98:
      return {9, 8};
    case type_t::MATRIX99:
      return {9, 9};
    default:
      SYM_ASSERT(false);
  }
}

/**
 * Helper to handle polymorphism by creating a switch from a runtime type enum to dispatch
 * to the templated method func. Used to perform type-aware operations.
 *
 * Args:
 *   name: Name of the output function (ex: FormatByType)
 *   func: Name of a function template (ex: FormatHelper)
 */
#define BY_TYPE_HELPER(name, func, matrix_func)                      \
  template <typename Scalar, typename... Args>                       \
  auto name(const type_t type, Args&&... args) {                     \
    if (IsEigenType(type)) {                                         \
      return matrix_func<Scalar>(args...);                           \
    }                                                                \
    switch (type.value) {                                            \
      case type_t::ROT2:                                             \
        return func<sym::Rot2<Scalar>>(args...);                     \
      case type_t::ROT3:                                             \
        return func<sym::Rot3<Scalar>>(args...);                     \
      case type_t::POSE2:                                            \
        return func<sym::Pose2<Scalar>>(args...);                    \
      case type_t::POSE3:                                            \
        return func<sym::Pose3<Scalar>>(args...);                    \
      case type_t::UNIT3:                                            \
        return func<sym::Unit3<Scalar>>(args...);                    \
      case type_t::SCALAR:                                           \
        return func<Scalar>(args...);                                \
      case type_t::ATAN_CAMERA_CAL:                                  \
        return func<sym::ATANCameraCal<Scalar>>(args...);            \
      case type_t::DOUBLE_SPHERE_CAMERA_CAL:                         \
        return func<sym::DoubleSphereCameraCal<Scalar>>(args...);    \
      case type_t::EQUIRECTANGULAR_CAMERA_CAL:                       \
        return func<sym::EquirectangularCameraCal<Scalar>>(args...); \
      case type_t::LINEAR_CAMERA_CAL:                                \
        return func<sym::LinearCameraCal<Scalar>>(args...);          \
      case type_t::POLYNOMIAL_CAMERA_CAL:                            \
        return func<sym::PolynomialCameraCal<Scalar>>(args...);      \
      case type_t::SPHERICAL_CAMERA_CAL:                             \
        return func<sym::SphericalCameraCal<Scalar>>(args...);       \
      case type_t::ORTHOGRAPHIC_CAMERA_CAL:                          \
        return func<sym::OrthographicCameraCal<Scalar>>(args...);    \
      default:                                                       \
        SYM_ASSERT(false);                                           \
    }                                                                \
  }

}  // namespace sym
