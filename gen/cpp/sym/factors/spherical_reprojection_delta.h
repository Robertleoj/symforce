// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Core>

#include <sym/pose3.h>
#include <sym/spherical_camera_cal.h>

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
 *     target_calibration: The target camera calibration
 *     source_inverse_range: The inverse range of the landmark in the source camera
 *     p_camera_source: The location of the landmark in the source camera coordinate, will be
 *         normalized
 *     target_pixel: The location of the correspondence in the target camera
 *     epsilon: Small positive value
 *
 * Outputs:
 *     res: 2dof reprojection delta
 *     valid: is valid projection or not
 */
template <typename Scalar>
void SphericalReprojectionDelta(const sym::Pose3<Scalar>& source_pose,
                                const sym::Pose3<Scalar>& target_pose,
                                const sym::SphericalCameraCal<Scalar>& target_calibration,
                                const Scalar source_inverse_range,
                                const Eigen::Matrix<Scalar, 3, 1>& p_camera_source,
                                const Eigen::Matrix<Scalar, 2, 1>& target_pixel,
                                const Scalar epsilon,
                                Eigen::Matrix<Scalar, 2, 1>* const reprojection_delta = nullptr,
                                Scalar* const is_valid = nullptr) {
  // Total ops: 158

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _source_pose = source_pose.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _target_pose = target_pose.Data();
  const Eigen::Matrix<Scalar, 11, 1>& _target_calibration = target_calibration.Data();

  // Intermediate terms (43)
  const Scalar _tmp0 = -2 * std::pow(_target_pose[0], Scalar(2));
  const Scalar _tmp1 = -2 * std::pow(_target_pose[2], Scalar(2));
  const Scalar _tmp2 = 2 * _source_pose[1];
  const Scalar _tmp3 = _source_pose[0] * _tmp2;
  const Scalar _tmp4 = 2 * _source_pose[3];
  const Scalar _tmp5 = _source_pose[2] * _tmp4;
  const Scalar _tmp6 = std::pow(Scalar(epsilon + std::pow(p_camera_source(0, 0), Scalar(2)) +
                                       std::pow(p_camera_source(1, 0), Scalar(2)) +
                                       std::pow(p_camera_source(2, 0), Scalar(2))),
                                Scalar(Scalar(-1) / Scalar(2)));
  const Scalar _tmp7 = _tmp6 * p_camera_source(0, 0);
  const Scalar _tmp8 = -2 * std::pow(_source_pose[2], Scalar(2));
  const Scalar _tmp9 = -2 * std::pow(_source_pose[0], Scalar(2));
  const Scalar _tmp10 = _tmp6 * p_camera_source(1, 0);
  const Scalar _tmp11 = _source_pose[0] * _tmp4;
  const Scalar _tmp12 = _source_pose[2] * _tmp2;
  const Scalar _tmp13 = _tmp6 * p_camera_source(2, 0);
  const Scalar _tmp14 = _tmp10 * (_tmp8 + _tmp9 + 1) + _tmp13 * (-_tmp11 + _tmp12) +
                        _tmp7 * (_tmp3 + _tmp5) +
                        source_inverse_range * (_source_pose[5] - _target_pose[5]);
  const Scalar _tmp15 = 2 * _target_pose[1];
  const Scalar _tmp16 = _target_pose[2] * _tmp15;
  const Scalar _tmp17 = 2 * _target_pose[0];
  const Scalar _tmp18 = _target_pose[3] * _tmp17;
  const Scalar _tmp19 = 1 - 2 * std::pow(_source_pose[1], Scalar(2));
  const Scalar _tmp20 = 2 * _source_pose[0] * _source_pose[2];
  const Scalar _tmp21 = _source_pose[1] * _tmp4;
  const Scalar _tmp22 = _tmp10 * (_tmp11 + _tmp12) + _tmp13 * (_tmp19 + _tmp9) +
                        _tmp7 * (_tmp20 - _tmp21) +
                        source_inverse_range * (_source_pose[6] - _target_pose[6]);
  const Scalar _tmp23 = 2 * _target_pose[2] * _target_pose[3];
  const Scalar _tmp24 = _target_pose[1] * _tmp17;
  const Scalar _tmp25 = _tmp10 * (_tmp3 - _tmp5) + _tmp13 * (_tmp20 + _tmp21) +
                        _tmp7 * (_tmp19 + _tmp8) +
                        source_inverse_range * (_source_pose[4] - _target_pose[4]);
  const Scalar _tmp26 =
      _tmp14 * (_tmp0 + _tmp1 + 1) + _tmp22 * (_tmp16 + _tmp18) + _tmp25 * (-_tmp23 + _tmp24);
  const Scalar _tmp27 = _target_pose[2] * _tmp17;
  const Scalar _tmp28 = _target_pose[3] * _tmp15;
  const Scalar _tmp29 = 1 - 2 * std::pow(_target_pose[1], Scalar(2));
  const Scalar _tmp30 =
      _tmp14 * (_tmp23 + _tmp24) + _tmp22 * (_tmp27 - _tmp28) + _tmp25 * (_tmp1 + _tmp29);
  const Scalar _tmp31 = std::pow(_tmp30, Scalar(2));
  const Scalar _tmp32 = std::pow(_tmp26, Scalar(2));
  const Scalar _tmp33 = _tmp31 + _tmp32 + epsilon;
  const Scalar _tmp34 = std::sqrt(_tmp33);
  const Scalar _tmp35 = std::atan2(
      _tmp34, _tmp14 * (_tmp16 - _tmp18) + _tmp22 * (_tmp0 + _tmp29) + _tmp25 * (_tmp27 + _tmp28));
  const Scalar _tmp36 = std::min<Scalar>(_tmp35, _target_calibration[4] - epsilon);
  const Scalar _tmp37 = _target_calibration[5] *
                            [&]() {
                              const Scalar base = _tmp36;
                              return base * base * base;
                            }() +
                        _target_calibration[6] * std::pow(_tmp36, Scalar(5)) +
                        _target_calibration[7] * std::pow(_tmp36, Scalar(7)) +
                        _target_calibration[8] * std::pow(_tmp36, Scalar(9)) + _tmp36;
  const Scalar _tmp38 = std::pow(_tmp37, Scalar(2)) / _tmp33;
  const Scalar _tmp39 = 2 * _tmp26 * _tmp30 * _tmp38;
  const Scalar _tmp40 = _tmp32 * _tmp38;
  const Scalar _tmp41 = _tmp31 * _tmp38;
  const Scalar _tmp42 = _tmp37 / _tmp34;

  // Output terms (2)
  if (reprojection_delta != nullptr) {
    Eigen::Matrix<Scalar, 2, 1>& _reprojection_delta = (*reprojection_delta);

    _reprojection_delta(0, 0) =
        _target_calibration[0] *
            (_target_calibration[10] * _tmp39 + _target_calibration[9] * _tmp40 +
             3 * _target_calibration[9] * _tmp41 + _tmp30 * _tmp42) +
        _target_calibration[2] - target_pixel(0, 0);
    _reprojection_delta(1, 0) =
        _target_calibration[1] *
            (3 * _target_calibration[10] * _tmp40 + _target_calibration[10] * _tmp41 +
             _target_calibration[9] * _tmp39 + _tmp26 * _tmp42) +
        _target_calibration[3] - target_pixel(1, 0);
  }

  if (is_valid != nullptr) {
    Scalar& _is_valid = (*is_valid);

    _is_valid = std::max<Scalar>(
        0, (((_target_calibration[4] - _tmp35) > 0) - ((_target_calibration[4] - _tmp35) < 0)));
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
