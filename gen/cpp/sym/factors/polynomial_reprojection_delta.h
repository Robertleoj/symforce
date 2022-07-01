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
 * Reprojects the landmark ray into the target camera and returns the delta between the
 * correspondence and the reprojection.
 *
 * The landmark is specified as a 3D point or ray (will be normalized) in the source
 * camera; this means the landmark is fixed in the source camera and always has residual 0 there
 * (this 0 residual is not returned, only the residual in the target camera is returned).
 *
 * Args:
 *     source_pose: The pose of the source camera
 *     target_pose: The pose of the target camera
 *     target_calibration_storage: The storage vector of the target camera calibration
 *     source_inverse_range: The inverse range of the landmark in the source camera
 *     p_camera_source: The location of the landmark in the source camera coordinate, will be
 * normalized target_pixel: The location of the correspondence in the target camera epsilon: Small
 * positive value target_camera_model_class: The subclass of CameraCal to use as the target camera
 * model
 *
 * Outputs:
 *     res: 2dof reprojection delta
 *     valid: is valid projection or not
 */
template <typename Scalar>
void PolynomialReprojectionDelta(const sym::Pose3<Scalar>& source_pose,
                                 const sym::Pose3<Scalar>& target_pose,
                                 const Eigen::Matrix<Scalar, 8, 1>& target_calibration_storage,
                                 const Scalar source_inverse_range,
                                 const Eigen::Matrix<Scalar, 3, 1>& p_camera_source,
                                 const Eigen::Matrix<Scalar, 2, 1>& target_pixel,
                                 const Scalar epsilon,
                                 Eigen::Matrix<Scalar, 2, 1>* const reprojection_delta = nullptr,
                                 Scalar* const is_valid = nullptr) {
  // Total ops: 140

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _source_pose = source_pose.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _target_pose = target_pose.Data();

  // Intermediate terms (36)
  const Scalar _tmp0 = 2 * _target_pose[2];
  const Scalar _tmp1 = _target_pose[0] * _tmp0;
  const Scalar _tmp2 = 2 * _target_pose[3];
  const Scalar _tmp3 = _target_pose[1] * _tmp2;
  const Scalar _tmp4 = 2 * _source_pose[0];
  const Scalar _tmp5 = _source_pose[3] * _tmp4;
  const Scalar _tmp6 = 2 * _source_pose[1];
  const Scalar _tmp7 = _source_pose[2] * _tmp6;
  const Scalar _tmp8 = std::pow(Scalar(epsilon + std::pow(p_camera_source(0, 0), Scalar(2)) +
                                       std::pow(p_camera_source(1, 0), Scalar(2)) +
                                       std::pow(p_camera_source(2, 0), Scalar(2))),
                                Scalar(Scalar(-1) / Scalar(2)));
  const Scalar _tmp9 = _tmp8 * p_camera_source(1, 0);
  const Scalar _tmp10 = _source_pose[2] * _tmp4;
  const Scalar _tmp11 = _source_pose[3] * _tmp6;
  const Scalar _tmp12 = _tmp8 * p_camera_source(0, 0);
  const Scalar _tmp13 = -2 * std::pow(_source_pose[0], Scalar(2));
  const Scalar _tmp14 = 1 - 2 * std::pow(_source_pose[1], Scalar(2));
  const Scalar _tmp15 = _tmp8 * p_camera_source(2, 0);
  const Scalar _tmp16 = _tmp12 * (_tmp10 - _tmp11) + _tmp15 * (_tmp13 + _tmp14) +
                        _tmp9 * (_tmp5 + _tmp7) +
                        source_inverse_range * (_source_pose[6] - _target_pose[6]);
  const Scalar _tmp17 = _target_pose[2] * _tmp2;
  const Scalar _tmp18 = 2 * _target_pose[0] * _target_pose[1];
  const Scalar _tmp19 = _source_pose[1] * _tmp4;
  const Scalar _tmp20 = 2 * _source_pose[2] * _source_pose[3];
  const Scalar _tmp21 = -2 * std::pow(_source_pose[2], Scalar(2));
  const Scalar _tmp22 = _tmp12 * (_tmp19 + _tmp20) + _tmp15 * (-_tmp5 + _tmp7) +
                        _tmp9 * (_tmp13 + _tmp21 + 1) +
                        source_inverse_range * (_source_pose[5] - _target_pose[5]);
  const Scalar _tmp23 = -2 * std::pow(_target_pose[2], Scalar(2));
  const Scalar _tmp24 = 1 - 2 * std::pow(_target_pose[1], Scalar(2));
  const Scalar _tmp25 = _tmp12 * (_tmp14 + _tmp21) + _tmp15 * (_tmp10 + _tmp11) +
                        _tmp9 * (_tmp19 - _tmp20) +
                        source_inverse_range * (_source_pose[4] - _target_pose[4]);
  const Scalar _tmp26 =
      _tmp16 * (_tmp1 - _tmp3) + _tmp22 * (_tmp17 + _tmp18) + _tmp25 * (_tmp23 + _tmp24);
  const Scalar _tmp27 = -2 * std::pow(_target_pose[0], Scalar(2));
  const Scalar _tmp28 = _target_pose[1] * _tmp0;
  const Scalar _tmp29 = _target_pose[0] * _tmp2;
  const Scalar _tmp30 =
      _tmp16 * (_tmp24 + _tmp27) + _tmp22 * (_tmp28 - _tmp29) + _tmp25 * (_tmp1 + _tmp3);
  const Scalar _tmp31 = std::max<Scalar>(epsilon, std::fabs(_tmp30));
  const Scalar _tmp32 = std::pow(_tmp31, Scalar(-2));
  const Scalar _tmp33 =
      _tmp16 * (_tmp28 + _tmp29) + _tmp22 * (_tmp23 + _tmp27 + 1) + _tmp25 * (-_tmp17 + _tmp18);
  const Scalar _tmp34 =
      std::pow(_tmp26, Scalar(2)) * _tmp32 + _tmp32 * std::pow(_tmp33, Scalar(2)) + epsilon;
  const Scalar _tmp35 =
      (Scalar(1.0) *
           [&]() {
             const Scalar base = _tmp34;
             return base * base * base;
           }() *
           target_calibration_storage(7, 0) +
       Scalar(1.0) * std::pow(_tmp34, Scalar(2)) * target_calibration_storage(6, 0) +
       Scalar(1.0) * _tmp34 * target_calibration_storage(5, 0) + Scalar(1.0)) /
      _tmp31;

  // Output terms (2)
  if (reprojection_delta != nullptr) {
    Eigen::Matrix<Scalar, 2, 1>& _reprojection_delta = (*reprojection_delta);

    _reprojection_delta(0, 0) = _tmp26 * _tmp35 * target_calibration_storage(0, 0) +
                                target_calibration_storage(2, 0) - target_pixel(0, 0);
    _reprojection_delta(1, 0) = _tmp33 * _tmp35 * target_calibration_storage(1, 0) +
                                target_calibration_storage(3, 0) - target_pixel(1, 0);
  }

  if (is_valid != nullptr) {
    Scalar& _is_valid = (*is_valid);

    _is_valid = std::max<Scalar>(
        0, std::min<Scalar>((((_tmp30) > 0) - ((_tmp30) < 0)),
                            (((-std::sqrt(_tmp34) + target_calibration_storage(4, 0)) > 0) -
                             ((-std::sqrt(_tmp34) + target_calibration_storage(4, 0)) < 0))));
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
