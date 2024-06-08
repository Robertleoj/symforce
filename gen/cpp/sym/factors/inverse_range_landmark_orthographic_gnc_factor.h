// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Core>

#include <sym/orthographic_camera_cal.h>
#include <sym/pose3.h>

namespace sym {

/**
 * Return the 2dof residual of reprojecting the landmark ray into the target spherical camera and
 * comparing it against the correspondence.
 *
 * The landmark is specified as a camera point in the source camera with an inverse range; this
 * means the landmark is fixed in the source camera and always has residual 0 there (this 0
 * residual is not returned, only the residual in the target camera is returned).
 *
 * The norm of the residual is whitened using the
 * :class:`BarronNoiseModel <symforce.opt.noise_models.BarronNoiseModel>`.  Whitening each
 * component of the reprojection error separately would result in rejecting individual components
 * as outliers. Instead, we minimize the whitened norm of the full reprojection error for each
 * point.  See
 * :meth:`ScalarNoiseModel.whiten_norm <symforce.opt.noise_models.ScalarNoiseModel.whiten_norm>`
 * for more information on this, and
 * :class:`BarronNoiseModel <symforce.opt.noise_models.BarronNoiseModel>` for more information on
 * the noise model.
 *
 * Args:
 *     source_pose: The pose of the source camera
 *     target_pose: The pose of the target camera
 *     target_calibration: The target spherical camera calibration
 *     source_inverse_range: The inverse range of the landmark in the source camera
 *     p_camera_source: The location of the landmark in the source camera coordinate, will be
 *         normalized
 *     target_pixel: The location of the correspondence in the target camera
 *     weight: The weight of the factor
 *     gnc_mu: The mu convexity parameter for the
 *         :class:`BarronNoiseModel <symforce.opt.noise_models.BarronNoiseModel>`
 *     gnc_scale: The scale parameter for the
 *         :class:`BarronNoiseModel <symforce.opt.noise_models.BarronNoiseModel>`
 *     epsilon: Small positive value
 *
 * Outputs:
 *     res: 2dof whiten residual of the reprojection
 *     jacobian: (2x13) jacobian of res wrt args source_pose (6), target_pose (6),
 *               source_inverse_range (1)
 *     hessian: (13x13) Gauss-Newton hessian for args source_pose (6), target_pose (6),
 *              source_inverse_range (1)
 *     rhs: (13x1) Gauss-Newton rhs for args source_pose (6), target_pose (6), source_inverse_range
 *          (1)
 */
template <typename Scalar>
void InverseRangeLandmarkOrthographicGncFactor(
    const sym::Pose3<Scalar>& source_pose, const sym::Pose3<Scalar>& target_pose,
    const sym::OrthographicCameraCal<Scalar>& target_calibration, const Scalar source_inverse_range,
    const Eigen::Matrix<Scalar, 3, 1>& p_camera_source,
    const Eigen::Matrix<Scalar, 2, 1>& target_pixel, const Scalar weight, const Scalar gnc_mu,
    const Scalar gnc_scale, const Scalar epsilon, Eigen::Matrix<Scalar, 2, 1>* const res = nullptr,
    Eigen::Matrix<Scalar, 2, 13>* const jacobian = nullptr,
    Eigen::Matrix<Scalar, 13, 13>* const hessian = nullptr,
    Eigen::Matrix<Scalar, 13, 1>* const rhs = nullptr) {
  // Total ops: 779

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _source_pose = source_pose.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _target_pose = target_pose.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _target_calibration = target_calibration.Data();

  // Intermediate terms (192)
  const Scalar _tmp0 = 2 * _target_pose[2];
  const Scalar _tmp1 = _target_pose[0] * _tmp0;
  const Scalar _tmp2 = 2 * _target_pose[1];
  const Scalar _tmp3 = _target_pose[3] * _tmp2;
  const Scalar _tmp4 = -_tmp3;
  const Scalar _tmp5 = _tmp1 + _tmp4;
  const Scalar _tmp6 = 2 * _source_pose[3];
  const Scalar _tmp7 = _source_pose[0] * _tmp6;
  const Scalar _tmp8 = 2 * _source_pose[1];
  const Scalar _tmp9 = _source_pose[2] * _tmp8;
  const Scalar _tmp10 = _tmp7 + _tmp9;
  const Scalar _tmp11 = std::pow(Scalar(epsilon + std::pow(p_camera_source(0, 0), Scalar(2)) +
                                        std::pow(p_camera_source(1, 0), Scalar(2)) +
                                        std::pow(p_camera_source(2, 0), Scalar(2))),
                                 Scalar(Scalar(-1) / Scalar(2)));
  const Scalar _tmp12 = _tmp11 * p_camera_source(1, 0);
  const Scalar _tmp13 = 2 * _source_pose[0] * _source_pose[2];
  const Scalar _tmp14 = _source_pose[1] * _tmp6;
  const Scalar _tmp15 = -_tmp14;
  const Scalar _tmp16 = _tmp11 * (_tmp13 + _tmp15);
  const Scalar _tmp17 = std::pow(_source_pose[0], Scalar(2));
  const Scalar _tmp18 = -2 * _tmp17;
  const Scalar _tmp19 = std::pow(_source_pose[1], Scalar(2));
  const Scalar _tmp20 = 1 - 2 * _tmp19;
  const Scalar _tmp21 = _tmp11 * p_camera_source(2, 0);
  const Scalar _tmp22 = _source_pose[6] - _target_pose[6];
  const Scalar _tmp23 = _tmp10 * _tmp12 + _tmp16 * p_camera_source(0, 0) +
                        _tmp21 * (_tmp18 + _tmp20) + _tmp22 * source_inverse_range;
  const Scalar _tmp24 = _target_pose[3] * _tmp0;
  const Scalar _tmp25 = _target_pose[0] * _tmp2;
  const Scalar _tmp26 = _tmp24 + _tmp25;
  const Scalar _tmp27 = _source_pose[0] * _tmp8;
  const Scalar _tmp28 = _source_pose[2] * _tmp6;
  const Scalar _tmp29 = _tmp27 + _tmp28;
  const Scalar _tmp30 = _tmp11 * p_camera_source(0, 0);
  const Scalar _tmp31 = -_tmp7;
  const Scalar _tmp32 = _tmp31 + _tmp9;
  const Scalar _tmp33 = std::pow(_source_pose[2], Scalar(2));
  const Scalar _tmp34 = -2 * _tmp33;
  const Scalar _tmp35 = _source_pose[5] - _target_pose[5];
  const Scalar _tmp36 = _tmp12 * (_tmp18 + _tmp34 + 1) + _tmp21 * _tmp32 + _tmp29 * _tmp30 +
                        _tmp35 * source_inverse_range;
  const Scalar _tmp37 = std::pow(_target_pose[1], Scalar(2));
  const Scalar _tmp38 = -2 * _tmp37;
  const Scalar _tmp39 = std::pow(_target_pose[2], Scalar(2));
  const Scalar _tmp40 = -2 * _tmp39;
  const Scalar _tmp41 = _tmp38 + _tmp40 + 1;
  const Scalar _tmp42 = -_tmp28;
  const Scalar _tmp43 = _tmp27 + _tmp42;
  const Scalar _tmp44 = _tmp13 + _tmp14;
  const Scalar _tmp45 = _source_pose[4] - _target_pose[4];
  const Scalar _tmp46 = _tmp12 * _tmp43 + _tmp21 * _tmp44 + _tmp30 * (_tmp20 + _tmp34) +
                        _tmp45 * source_inverse_range;
  const Scalar _tmp47 =
      _target_calibration[0] * (_tmp23 * _tmp5 + _tmp26 * _tmp36 + _tmp41 * _tmp46) +
      _target_calibration[2] - target_pixel(0, 0);
  const Scalar _tmp48 = std::pow(_tmp47, Scalar(2));
  const Scalar _tmp49 = std::pow(_target_pose[0], Scalar(2));
  const Scalar _tmp50 = 1 - 2 * _tmp49;
  const Scalar _tmp51 = _tmp40 + _tmp50;
  const Scalar _tmp52 = _target_pose[2] * _tmp2;
  const Scalar _tmp53 = 2 * _target_pose[0] * _target_pose[3];
  const Scalar _tmp54 = _tmp52 + _tmp53;
  const Scalar _tmp55 = -_tmp24;
  const Scalar _tmp56 = _tmp25 + _tmp55;
  const Scalar _tmp57 = _tmp23 * _tmp54 + _tmp46 * _tmp56;
  const Scalar _tmp58 = _target_calibration[1] * (_tmp36 * _tmp51 + _tmp57) +
                        _target_calibration[3] - target_pixel(1, 0);
  const Scalar _tmp59 = std::pow(_tmp58, Scalar(2));
  const Scalar _tmp60 = _tmp48 + _tmp59 + epsilon;
  const Scalar _tmp61 = std::pow(_tmp60, Scalar(Scalar(-1) / Scalar(2)));
  const Scalar _tmp62 = std::sqrt(weight);
  const Scalar _tmp63 = Scalar(1.0) / (epsilon - gnc_mu + 1);
  const Scalar _tmp64 = epsilon + std::fabs(_tmp63);
  const Scalar _tmp65 = 2 - _tmp63;
  const Scalar _tmp66 =
      _tmp65 + epsilon * (2 * std::min<Scalar>(0, (((_tmp65) > 0) - ((_tmp65) < 0))) + 1);
  const Scalar _tmp67 = std::pow(gnc_scale, Scalar(-2));
  const Scalar _tmp68 = _tmp60 * _tmp67 / _tmp64 + 1;
  const Scalar _tmp69 = (Scalar(1) / Scalar(2)) * _tmp66;
  const Scalar _tmp70 =
      std::sqrt(Scalar(2)) * std::sqrt(Scalar(_tmp64 * (std::pow(_tmp68, _tmp69) - 1) / _tmp66));
  const Scalar _tmp71 = _tmp36 * (_tmp52 - _tmp53) + _tmp46 * (_tmp1 + _tmp3);
  const Scalar _tmp72 = std::max<Scalar>(0, (((_tmp23 * (_tmp38 + _tmp50) + _tmp71) > 0) -
                                             ((_tmp23 * (_tmp38 + _tmp50) + _tmp71) < 0)));
  const Scalar _tmp73 = _tmp62 * _tmp70 * _tmp72;
  const Scalar _tmp74 = _tmp61 * _tmp73;
  const Scalar _tmp75 = _tmp47 * _tmp74;
  const Scalar _tmp76 = _tmp58 * _tmp74;
  const Scalar _tmp77 = std::pow(_source_pose[3], Scalar(2));
  const Scalar _tmp78 = -_tmp77;
  const Scalar _tmp79 = _tmp33 + _tmp78;
  const Scalar _tmp80 = -_tmp19;
  const Scalar _tmp81 = _tmp17 + _tmp80;
  const Scalar _tmp82 = _tmp12 * _tmp32 + _tmp21 * (_tmp79 + _tmp81);
  const Scalar _tmp83 = -_tmp9;
  const Scalar _tmp84 = -_tmp17;
  const Scalar _tmp85 = _tmp12 * (_tmp33 + _tmp77 + _tmp80 + _tmp84) + _tmp21 * (_tmp31 + _tmp83);
  const Scalar _tmp86 = -_tmp27;
  const Scalar _tmp87 = _tmp12 * _tmp44 + _tmp21 * (_tmp28 + _tmp86);
  const Scalar _tmp88 = _tmp26 * _tmp82 + _tmp41 * _tmp87 + _tmp5 * _tmp85;
  const Scalar _tmp89 = 2 * _tmp47;
  const Scalar _tmp90 = _target_calibration[0] * _tmp89;
  const Scalar _tmp91 = _tmp51 * _tmp82 + _tmp54 * _tmp85 + _tmp56 * _tmp87;
  const Scalar _tmp92 = 2 * _tmp58;
  const Scalar _tmp93 = _target_calibration[1] * _tmp92;
  const Scalar _tmp94 = _tmp88 * _tmp90 + _tmp91 * _tmp93;
  const Scalar _tmp95 = (Scalar(1) / Scalar(2)) * _tmp47;
  const Scalar _tmp96 =
      _tmp61 * _tmp62 * _tmp67 * std::pow(_tmp68, Scalar(_tmp69 - 1)) * _tmp72 / _tmp70;
  const Scalar _tmp97 = _tmp95 * _tmp96;
  const Scalar _tmp98 = _target_calibration[0] * _tmp74;
  const Scalar _tmp99 = _tmp73 / (_tmp60 * std::sqrt(_tmp60));
  const Scalar _tmp100 = _tmp95 * _tmp99;
  const Scalar _tmp101 = -_tmp100 * _tmp94 + _tmp88 * _tmp98 + _tmp94 * _tmp97;
  const Scalar _tmp102 = (Scalar(1) / Scalar(2)) * _tmp58;
  const Scalar _tmp103 = _tmp102 * _tmp96;
  const Scalar _tmp104 = _target_calibration[1] * _tmp74;
  const Scalar _tmp105 = _tmp102 * _tmp99;
  const Scalar _tmp106 = _tmp103 * _tmp94 + _tmp104 * _tmp91 - _tmp105 * _tmp94;
  const Scalar _tmp107 = -_tmp13;
  const Scalar _tmp108 = -_tmp33;
  const Scalar _tmp109 = _tmp108 + _tmp77;
  const Scalar _tmp110 = _tmp21 * (_tmp109 + _tmp81) + _tmp30 * (_tmp107 + _tmp15);
  const Scalar _tmp111 =
      _tmp16 * p_camera_source(2, 0) + _tmp30 * (_tmp108 + _tmp17 + _tmp19 + _tmp78);
  const Scalar _tmp112 = _tmp21 * _tmp29 + _tmp30 * (_tmp7 + _tmp83);
  const Scalar _tmp113 =
      _target_calibration[1] * (_tmp110 * _tmp56 + _tmp111 * _tmp54 + _tmp112 * _tmp51);
  const Scalar _tmp114 =
      _target_calibration[0] * (_tmp110 * _tmp41 + _tmp111 * _tmp5 + _tmp112 * _tmp26);
  const Scalar _tmp115 = _tmp113 * _tmp92 + _tmp114 * _tmp89;
  const Scalar _tmp116 = -_tmp100 * _tmp115 + _tmp114 * _tmp74 + _tmp115 * _tmp97;
  const Scalar _tmp117 = _tmp103 * _tmp115 - _tmp105 * _tmp115 + _tmp113 * _tmp74;
  const Scalar _tmp118 = _tmp10 * _tmp30 + _tmp12 * (_tmp107 + _tmp14);
  const Scalar _tmp119 = _tmp19 + _tmp84;
  const Scalar _tmp120 = _tmp12 * (_tmp42 + _tmp86) + _tmp30 * (_tmp109 + _tmp119);
  const Scalar _tmp121 = _tmp12 * (_tmp119 + _tmp79) + _tmp30 * _tmp43;
  const Scalar _tmp122 = _tmp118 * _tmp5 + _tmp120 * _tmp26 + _tmp121 * _tmp41;
  const Scalar _tmp123 = _tmp118 * _tmp54 + _tmp120 * _tmp51 + _tmp121 * _tmp56;
  const Scalar _tmp124 = _tmp122 * _tmp90 + _tmp123 * _tmp93;
  const Scalar _tmp125 = -_tmp100 * _tmp124 + _tmp122 * _tmp98 + _tmp124 * _tmp97;
  const Scalar _tmp126 = _tmp103 * _tmp124 + _tmp104 * _tmp123 - _tmp105 * _tmp124;
  const Scalar _tmp127 = _tmp98 * source_inverse_range;
  const Scalar _tmp128 = _tmp127 * _tmp41;
  const Scalar _tmp129 = _tmp90 * source_inverse_range;
  const Scalar _tmp130 = _tmp129 * _tmp41;
  const Scalar _tmp131 = _tmp93 * source_inverse_range;
  const Scalar _tmp132 = _tmp131 * _tmp56;
  const Scalar _tmp133 = _tmp130 + _tmp132;
  const Scalar _tmp134 = _tmp133 * _tmp99;
  const Scalar _tmp135 = _tmp128 + _tmp133 * _tmp97 - _tmp134 * _tmp95;
  const Scalar _tmp136 = _tmp104 * source_inverse_range;
  const Scalar _tmp137 = _tmp136 * _tmp56;
  const Scalar _tmp138 = -_tmp102 * _tmp134 + _tmp103 * _tmp133 + _tmp137;
  const Scalar _tmp139 = _tmp129 * _tmp26;
  const Scalar _tmp140 = _tmp131 * _tmp51;
  const Scalar _tmp141 = _tmp139 + _tmp140;
  const Scalar _tmp142 = _tmp127 * _tmp26;
  const Scalar _tmp143 = -_tmp100 * _tmp141 + _tmp141 * _tmp97 + _tmp142;
  const Scalar _tmp144 = _tmp136 * _tmp51;
  const Scalar _tmp145 = _tmp103 * _tmp141 - _tmp105 * _tmp141 + _tmp144;
  const Scalar _tmp146 = _tmp129 * _tmp5;
  const Scalar _tmp147 = _tmp131 * _tmp54;
  const Scalar _tmp148 = _tmp146 + _tmp147;
  const Scalar _tmp149 = _tmp127 * _tmp5;
  const Scalar _tmp150 = -_tmp100 * _tmp148 + _tmp148 * _tmp97 + _tmp149;
  const Scalar _tmp151 = _tmp136 * _tmp54;
  const Scalar _tmp152 = _tmp103 * _tmp148 - _tmp105 * _tmp148 + _tmp151;
  const Scalar _tmp153 = _tmp47 * _tmp58;
  const Scalar _tmp154 = -_tmp49;
  const Scalar _tmp155 = std::pow(_target_pose[3], Scalar(2));
  const Scalar _tmp156 = _tmp154 + _tmp155;
  const Scalar _tmp157 = _tmp23 * (_tmp156 - _tmp37 + _tmp39) + _tmp71;
  const Scalar _tmp158 = _target_calibration[1] * _tmp157;
  const Scalar _tmp159 = _tmp158 * _tmp96;
  const Scalar _tmp160 = _tmp158 * _tmp99;
  const Scalar _tmp161 = _tmp153 * _tmp159 - _tmp153 * _tmp160;
  const Scalar _tmp162 = _tmp104 * _tmp157 + _tmp159 * _tmp59 - _tmp160 * _tmp59;
  const Scalar _tmp163 = -_tmp155;
  const Scalar _tmp164 = _tmp37 - _tmp39;
  const Scalar _tmp165 = -_tmp1;
  const Scalar _tmp166 = _tmp23 * (_tmp163 + _tmp164 + _tmp49) + _tmp36 * (-_tmp52 + _tmp53) +
                         _tmp46 * (_tmp165 + _tmp4);
  const Scalar _tmp167 = _target_calibration[0] * _tmp166;
  const Scalar _tmp168 = _tmp167 * _tmp99;
  const Scalar _tmp169 = _tmp167 * _tmp96;
  const Scalar _tmp170 = _tmp166 * _tmp98 - _tmp168 * _tmp48 + _tmp169 * _tmp48;
  const Scalar _tmp171 = -_tmp153 * _tmp168 + _tmp153 * _tmp169;
  const Scalar _tmp172 = _tmp36 * (_tmp156 + _tmp164) + _tmp57;
  const Scalar _tmp173 = _tmp23 * (_tmp165 + _tmp3) + _tmp36 * (-_tmp25 + _tmp55) +
                         _tmp46 * (_tmp154 + _tmp163 + _tmp37 + _tmp39);
  const Scalar _tmp174 = _tmp172 * _tmp90 + _tmp173 * _tmp93;
  const Scalar _tmp175 = -_tmp100 * _tmp174 + _tmp172 * _tmp98 + _tmp174 * _tmp97;
  const Scalar _tmp176 = _tmp103 * _tmp174 + _tmp104 * _tmp173 - _tmp105 * _tmp174;
  const Scalar _tmp177 = -_tmp130 - _tmp132;
  const Scalar _tmp178 = -_tmp100 * _tmp177 - _tmp128 + _tmp177 * _tmp97;
  const Scalar _tmp179 = _tmp102 * _tmp177;
  const Scalar _tmp180 = -_tmp137 + _tmp179 * _tmp96 - _tmp179 * _tmp99;
  const Scalar _tmp181 = -_tmp139 - _tmp140;
  const Scalar _tmp182 = -_tmp100 * _tmp181 - _tmp142 + _tmp181 * _tmp97;
  const Scalar _tmp183 = _tmp103 * _tmp181 - _tmp105 * _tmp181 - _tmp144;
  const Scalar _tmp184 = -_tmp146 - _tmp147;
  const Scalar _tmp185 = -_tmp100 * _tmp184 - _tmp149 + _tmp184 * _tmp97;
  const Scalar _tmp186 = _tmp103 * _tmp184 - _tmp105 * _tmp184 - _tmp151;
  const Scalar _tmp187 = _tmp22 * _tmp5 + _tmp26 * _tmp35 + _tmp41 * _tmp45;
  const Scalar _tmp188 = _tmp22 * _tmp54 + _tmp35 * _tmp51 + _tmp45 * _tmp56;
  const Scalar _tmp189 = _tmp187 * _tmp90 + _tmp188 * _tmp93;
  const Scalar _tmp190 = -_tmp100 * _tmp189 + _tmp187 * _tmp98 + _tmp189 * _tmp97;
  const Scalar _tmp191 = _tmp103 * _tmp189 + _tmp104 * _tmp188 - _tmp105 * _tmp189;

  // Output terms (4)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 2, 1>& _res = (*res);

    _res(0, 0) = _tmp75;
    _res(1, 0) = _tmp76;
  }

  if (jacobian != nullptr) {
    Eigen::Matrix<Scalar, 2, 13>& _jacobian = (*jacobian);

    _jacobian(0, 0) = _tmp101;
    _jacobian(1, 0) = _tmp106;
    _jacobian(0, 1) = _tmp116;
    _jacobian(1, 1) = _tmp117;
    _jacobian(0, 2) = _tmp125;
    _jacobian(1, 2) = _tmp126;
    _jacobian(0, 3) = _tmp135;
    _jacobian(1, 3) = _tmp138;
    _jacobian(0, 4) = _tmp143;
    _jacobian(1, 4) = _tmp145;
    _jacobian(0, 5) = _tmp150;
    _jacobian(1, 5) = _tmp152;
    _jacobian(0, 6) = _tmp161;
    _jacobian(1, 6) = _tmp162;
    _jacobian(0, 7) = _tmp170;
    _jacobian(1, 7) = _tmp171;
    _jacobian(0, 8) = _tmp175;
    _jacobian(1, 8) = _tmp176;
    _jacobian(0, 9) = _tmp178;
    _jacobian(1, 9) = _tmp180;
    _jacobian(0, 10) = _tmp182;
    _jacobian(1, 10) = _tmp183;
    _jacobian(0, 11) = _tmp185;
    _jacobian(1, 11) = _tmp186;
    _jacobian(0, 12) = _tmp190;
    _jacobian(1, 12) = _tmp191;
  }

  if (hessian != nullptr) {
    Eigen::Matrix<Scalar, 13, 13>& _hessian = (*hessian);

    _hessian(0, 0) = std::pow(_tmp101, Scalar(2)) + std::pow(_tmp106, Scalar(2));
    _hessian(1, 0) = _tmp101 * _tmp116 + _tmp106 * _tmp117;
    _hessian(2, 0) = _tmp101 * _tmp125 + _tmp106 * _tmp126;
    _hessian(3, 0) = _tmp101 * _tmp135 + _tmp106 * _tmp138;
    _hessian(4, 0) = _tmp101 * _tmp143 + _tmp106 * _tmp145;
    _hessian(5, 0) = _tmp101 * _tmp150 + _tmp106 * _tmp152;
    _hessian(6, 0) = _tmp101 * _tmp161 + _tmp106 * _tmp162;
    _hessian(7, 0) = _tmp101 * _tmp170 + _tmp106 * _tmp171;
    _hessian(8, 0) = _tmp101 * _tmp175 + _tmp106 * _tmp176;
    _hessian(9, 0) = _tmp101 * _tmp178 + _tmp106 * _tmp180;
    _hessian(10, 0) = _tmp101 * _tmp182 + _tmp106 * _tmp183;
    _hessian(11, 0) = _tmp101 * _tmp185 + _tmp106 * _tmp186;
    _hessian(12, 0) = _tmp101 * _tmp190 + _tmp106 * _tmp191;
    _hessian(0, 1) = 0;
    _hessian(1, 1) = std::pow(_tmp116, Scalar(2)) + std::pow(_tmp117, Scalar(2));
    _hessian(2, 1) = _tmp116 * _tmp125 + _tmp117 * _tmp126;
    _hessian(3, 1) = _tmp116 * _tmp135 + _tmp117 * _tmp138;
    _hessian(4, 1) = _tmp116 * _tmp143 + _tmp117 * _tmp145;
    _hessian(5, 1) = _tmp116 * _tmp150 + _tmp117 * _tmp152;
    _hessian(6, 1) = _tmp116 * _tmp161 + _tmp117 * _tmp162;
    _hessian(7, 1) = _tmp116 * _tmp170 + _tmp117 * _tmp171;
    _hessian(8, 1) = _tmp116 * _tmp175 + _tmp117 * _tmp176;
    _hessian(9, 1) = _tmp116 * _tmp178 + _tmp117 * _tmp180;
    _hessian(10, 1) = _tmp116 * _tmp182 + _tmp117 * _tmp183;
    _hessian(11, 1) = _tmp116 * _tmp185 + _tmp117 * _tmp186;
    _hessian(12, 1) = _tmp116 * _tmp190 + _tmp117 * _tmp191;
    _hessian(0, 2) = 0;
    _hessian(1, 2) = 0;
    _hessian(2, 2) = std::pow(_tmp125, Scalar(2)) + std::pow(_tmp126, Scalar(2));
    _hessian(3, 2) = _tmp125 * _tmp135 + _tmp126 * _tmp138;
    _hessian(4, 2) = _tmp125 * _tmp143 + _tmp126 * _tmp145;
    _hessian(5, 2) = _tmp125 * _tmp150 + _tmp126 * _tmp152;
    _hessian(6, 2) = _tmp125 * _tmp161 + _tmp126 * _tmp162;
    _hessian(7, 2) = _tmp125 * _tmp170 + _tmp126 * _tmp171;
    _hessian(8, 2) = _tmp125 * _tmp175 + _tmp126 * _tmp176;
    _hessian(9, 2) = _tmp125 * _tmp178 + _tmp126 * _tmp180;
    _hessian(10, 2) = _tmp125 * _tmp182 + _tmp126 * _tmp183;
    _hessian(11, 2) = _tmp125 * _tmp185 + _tmp126 * _tmp186;
    _hessian(12, 2) = _tmp125 * _tmp190 + _tmp126 * _tmp191;
    _hessian(0, 3) = 0;
    _hessian(1, 3) = 0;
    _hessian(2, 3) = 0;
    _hessian(3, 3) = std::pow(_tmp135, Scalar(2)) + std::pow(_tmp138, Scalar(2));
    _hessian(4, 3) = _tmp135 * _tmp143 + _tmp138 * _tmp145;
    _hessian(5, 3) = _tmp135 * _tmp150 + _tmp138 * _tmp152;
    _hessian(6, 3) = _tmp135 * _tmp161 + _tmp138 * _tmp162;
    _hessian(7, 3) = _tmp135 * _tmp170 + _tmp138 * _tmp171;
    _hessian(8, 3) = _tmp135 * _tmp175 + _tmp138 * _tmp176;
    _hessian(9, 3) = _tmp135 * _tmp178 + _tmp138 * _tmp180;
    _hessian(10, 3) = _tmp135 * _tmp182 + _tmp138 * _tmp183;
    _hessian(11, 3) = _tmp135 * _tmp185 + _tmp138 * _tmp186;
    _hessian(12, 3) = _tmp135 * _tmp190 + _tmp138 * _tmp191;
    _hessian(0, 4) = 0;
    _hessian(1, 4) = 0;
    _hessian(2, 4) = 0;
    _hessian(3, 4) = 0;
    _hessian(4, 4) = std::pow(_tmp143, Scalar(2)) + std::pow(_tmp145, Scalar(2));
    _hessian(5, 4) = _tmp143 * _tmp150 + _tmp145 * _tmp152;
    _hessian(6, 4) = _tmp143 * _tmp161 + _tmp145 * _tmp162;
    _hessian(7, 4) = _tmp143 * _tmp170 + _tmp145 * _tmp171;
    _hessian(8, 4) = _tmp143 * _tmp175 + _tmp145 * _tmp176;
    _hessian(9, 4) = _tmp143 * _tmp178 + _tmp145 * _tmp180;
    _hessian(10, 4) = _tmp143 * _tmp182 + _tmp145 * _tmp183;
    _hessian(11, 4) = _tmp143 * _tmp185 + _tmp145 * _tmp186;
    _hessian(12, 4) = _tmp143 * _tmp190 + _tmp145 * _tmp191;
    _hessian(0, 5) = 0;
    _hessian(1, 5) = 0;
    _hessian(2, 5) = 0;
    _hessian(3, 5) = 0;
    _hessian(4, 5) = 0;
    _hessian(5, 5) = std::pow(_tmp150, Scalar(2)) + std::pow(_tmp152, Scalar(2));
    _hessian(6, 5) = _tmp150 * _tmp161 + _tmp152 * _tmp162;
    _hessian(7, 5) = _tmp150 * _tmp170 + _tmp152 * _tmp171;
    _hessian(8, 5) = _tmp150 * _tmp175 + _tmp152 * _tmp176;
    _hessian(9, 5) = _tmp150 * _tmp178 + _tmp152 * _tmp180;
    _hessian(10, 5) = _tmp150 * _tmp182 + _tmp152 * _tmp183;
    _hessian(11, 5) = _tmp150 * _tmp185 + _tmp152 * _tmp186;
    _hessian(12, 5) = _tmp150 * _tmp190 + _tmp152 * _tmp191;
    _hessian(0, 6) = 0;
    _hessian(1, 6) = 0;
    _hessian(2, 6) = 0;
    _hessian(3, 6) = 0;
    _hessian(4, 6) = 0;
    _hessian(5, 6) = 0;
    _hessian(6, 6) = std::pow(_tmp161, Scalar(2)) + std::pow(_tmp162, Scalar(2));
    _hessian(7, 6) = _tmp161 * _tmp170 + _tmp162 * _tmp171;
    _hessian(8, 6) = _tmp161 * _tmp175 + _tmp162 * _tmp176;
    _hessian(9, 6) = _tmp161 * _tmp178 + _tmp162 * _tmp180;
    _hessian(10, 6) = _tmp161 * _tmp182 + _tmp162 * _tmp183;
    _hessian(11, 6) = _tmp161 * _tmp185 + _tmp162 * _tmp186;
    _hessian(12, 6) = _tmp161 * _tmp190 + _tmp162 * _tmp191;
    _hessian(0, 7) = 0;
    _hessian(1, 7) = 0;
    _hessian(2, 7) = 0;
    _hessian(3, 7) = 0;
    _hessian(4, 7) = 0;
    _hessian(5, 7) = 0;
    _hessian(6, 7) = 0;
    _hessian(7, 7) = std::pow(_tmp170, Scalar(2)) + std::pow(_tmp171, Scalar(2));
    _hessian(8, 7) = _tmp170 * _tmp175 + _tmp171 * _tmp176;
    _hessian(9, 7) = _tmp170 * _tmp178 + _tmp171 * _tmp180;
    _hessian(10, 7) = _tmp170 * _tmp182 + _tmp171 * _tmp183;
    _hessian(11, 7) = _tmp170 * _tmp185 + _tmp171 * _tmp186;
    _hessian(12, 7) = _tmp170 * _tmp190 + _tmp171 * _tmp191;
    _hessian(0, 8) = 0;
    _hessian(1, 8) = 0;
    _hessian(2, 8) = 0;
    _hessian(3, 8) = 0;
    _hessian(4, 8) = 0;
    _hessian(5, 8) = 0;
    _hessian(6, 8) = 0;
    _hessian(7, 8) = 0;
    _hessian(8, 8) = std::pow(_tmp175, Scalar(2)) + std::pow(_tmp176, Scalar(2));
    _hessian(9, 8) = _tmp175 * _tmp178 + _tmp176 * _tmp180;
    _hessian(10, 8) = _tmp175 * _tmp182 + _tmp176 * _tmp183;
    _hessian(11, 8) = _tmp175 * _tmp185 + _tmp176 * _tmp186;
    _hessian(12, 8) = _tmp175 * _tmp190 + _tmp176 * _tmp191;
    _hessian(0, 9) = 0;
    _hessian(1, 9) = 0;
    _hessian(2, 9) = 0;
    _hessian(3, 9) = 0;
    _hessian(4, 9) = 0;
    _hessian(5, 9) = 0;
    _hessian(6, 9) = 0;
    _hessian(7, 9) = 0;
    _hessian(8, 9) = 0;
    _hessian(9, 9) = std::pow(_tmp178, Scalar(2)) + std::pow(_tmp180, Scalar(2));
    _hessian(10, 9) = _tmp178 * _tmp182 + _tmp180 * _tmp183;
    _hessian(11, 9) = _tmp178 * _tmp185 + _tmp180 * _tmp186;
    _hessian(12, 9) = _tmp178 * _tmp190 + _tmp180 * _tmp191;
    _hessian(0, 10) = 0;
    _hessian(1, 10) = 0;
    _hessian(2, 10) = 0;
    _hessian(3, 10) = 0;
    _hessian(4, 10) = 0;
    _hessian(5, 10) = 0;
    _hessian(6, 10) = 0;
    _hessian(7, 10) = 0;
    _hessian(8, 10) = 0;
    _hessian(9, 10) = 0;
    _hessian(10, 10) = std::pow(_tmp182, Scalar(2)) + std::pow(_tmp183, Scalar(2));
    _hessian(11, 10) = _tmp182 * _tmp185 + _tmp183 * _tmp186;
    _hessian(12, 10) = _tmp182 * _tmp190 + _tmp183 * _tmp191;
    _hessian(0, 11) = 0;
    _hessian(1, 11) = 0;
    _hessian(2, 11) = 0;
    _hessian(3, 11) = 0;
    _hessian(4, 11) = 0;
    _hessian(5, 11) = 0;
    _hessian(6, 11) = 0;
    _hessian(7, 11) = 0;
    _hessian(8, 11) = 0;
    _hessian(9, 11) = 0;
    _hessian(10, 11) = 0;
    _hessian(11, 11) = std::pow(_tmp185, Scalar(2)) + std::pow(_tmp186, Scalar(2));
    _hessian(12, 11) = _tmp185 * _tmp190 + _tmp186 * _tmp191;
    _hessian(0, 12) = 0;
    _hessian(1, 12) = 0;
    _hessian(2, 12) = 0;
    _hessian(3, 12) = 0;
    _hessian(4, 12) = 0;
    _hessian(5, 12) = 0;
    _hessian(6, 12) = 0;
    _hessian(7, 12) = 0;
    _hessian(8, 12) = 0;
    _hessian(9, 12) = 0;
    _hessian(10, 12) = 0;
    _hessian(11, 12) = 0;
    _hessian(12, 12) = std::pow(_tmp190, Scalar(2)) + std::pow(_tmp191, Scalar(2));
  }

  if (rhs != nullptr) {
    Eigen::Matrix<Scalar, 13, 1>& _rhs = (*rhs);

    _rhs(0, 0) = _tmp101 * _tmp75 + _tmp106 * _tmp76;
    _rhs(1, 0) = _tmp116 * _tmp75 + _tmp117 * _tmp76;
    _rhs(2, 0) = _tmp125 * _tmp75 + _tmp126 * _tmp76;
    _rhs(3, 0) = _tmp135 * _tmp75 + _tmp138 * _tmp76;
    _rhs(4, 0) = _tmp143 * _tmp75 + _tmp145 * _tmp76;
    _rhs(5, 0) = _tmp150 * _tmp75 + _tmp152 * _tmp76;
    _rhs(6, 0) = _tmp161 * _tmp75 + _tmp162 * _tmp76;
    _rhs(7, 0) = _tmp170 * _tmp75 + _tmp171 * _tmp76;
    _rhs(8, 0) = _tmp175 * _tmp75 + _tmp176 * _tmp76;
    _rhs(9, 0) = _tmp178 * _tmp75 + _tmp180 * _tmp76;
    _rhs(10, 0) = _tmp182 * _tmp75 + _tmp183 * _tmp76;
    _rhs(11, 0) = _tmp185 * _tmp75 + _tmp186 * _tmp76;
    _rhs(12, 0) = _tmp190 * _tmp75 + _tmp191 * _tmp76;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
