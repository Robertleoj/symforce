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
 * Return the 2dof residual of reprojecting the landmark into the target camera and comparing
 * against the correspondence in the target camera.
 *
 * The landmark is specified as a pixel in the source camera and an inverse range; this means the
 * landmark is fixed in the source camera and always has residual 0 there (this 0 residual is not
 * returned, only the residual in the target camera is returned).
 *
 * The norm of the residual is whitened using the Barron noise model.  Whitening each component of
 * the reprojection error separately would result in rejecting individual components as outliers.
 * Instead, we minimize the whitened norm of the full reprojection error for each point.  See the
 * docstring for `NoiseModel.whiten_norm` for more information on this, and the docstring of
 * `BarronNoiseModel` for more information on the noise model.
 *
 * Args:
 *     source_pose: The pose of the source camera
 *     source_calibration_storage: The storage vector of the source camera calibration
 *     target_pose: The pose of the target camera
 *     target_calibration_storage: The storage vector of the target camera calibration
 *     source_inverse_range: The inverse range of the landmark in the source camera
 *     source_pixel: The location of the landmark in the source camera
 *     target_pixel: The location of the correspondence in the target camera
 *     weight: The weight of the factor
 *     gnc_mu: The mu convexity parameter for the Barron noise model
 *     gnc_scale: The scale parameter for the Barron noise model
 *     epsilon: Small positive value
 *     camera_model_class: The subclass of CameraCal to use as the camera model
 *
 * Outputs:
 *     res: 2dof residual of the reprojection
 *     jacobian: (2x13) jacobian of res wrt args source_pose (6), target_pose (6),
 *               source_inverse_range (1)
 *     hessian: (13x13) Gauss-Newton hessian for args source_pose (6), target_pose (6),
 *              source_inverse_range (1)
 *     rhs: (13x1) Gauss-Newton rhs for args source_pose (6), target_pose (6), source_inverse_range
 *          (1)
 */
template <typename Scalar>
void InverseRangeLandmarkEquirectangularReprojectionErrorFactor(
    const sym::Pose3<Scalar>& source_pose,
    const Eigen::Matrix<Scalar, 4, 1>& source_calibration_storage,
    const sym::Pose3<Scalar>& target_pose,
    const Eigen::Matrix<Scalar, 4, 1>& target_calibration_storage,
    const Scalar source_inverse_range, const Eigen::Matrix<Scalar, 2, 1>& source_pixel,
    const Eigen::Matrix<Scalar, 2, 1>& target_pixel, const Scalar weight, const Scalar gnc_mu,
    const Scalar gnc_scale, const Scalar epsilon, Eigen::Matrix<Scalar, 2, 1>* const res = nullptr,
    Eigen::Matrix<Scalar, 2, 13>* const jacobian = nullptr,
    Eigen::Matrix<Scalar, 13, 13>* const hessian = nullptr,
    Eigen::Matrix<Scalar, 13, 1>* const rhs = nullptr) {
  // Total ops: 982

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _source_pose = source_pose.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _target_pose = target_pose.Data();

  // Intermediate terms (257)
  const Scalar _tmp0 = std::pow(_target_pose[2], Scalar(2));
  const Scalar _tmp1 = -2 * _tmp0;
  const Scalar _tmp2 = std::pow(_target_pose[1], Scalar(2));
  const Scalar _tmp3 = 1 - 2 * _tmp2;
  const Scalar _tmp4 = _tmp1 + _tmp3;
  const Scalar _tmp5 = 2 * _source_pose[0] * _source_pose[2];
  const Scalar _tmp6 = 2 * _source_pose[3];
  const Scalar _tmp7 = _source_pose[1] * _tmp6;
  const Scalar _tmp8 = _tmp5 + _tmp7;
  const Scalar _tmp9 =
      (-source_calibration_storage(2, 0) + source_pixel(0, 0)) / source_calibration_storage(0, 0);
  const Scalar _tmp10 = std::cos(_tmp9);
  const Scalar _tmp11 =
      (-source_calibration_storage(3, 0) + source_pixel(1, 0)) / source_calibration_storage(1, 0);
  const Scalar _tmp12 = std::sin(_tmp11);
  const Scalar _tmp13 = std::cos(_tmp11);
  const Scalar _tmp14 = std::pow(_tmp13, Scalar(2));
  const Scalar _tmp15 = std::sin(_tmp9);
  const Scalar _tmp16 =
      std::pow(Scalar(std::pow(_tmp10, Scalar(2)) * _tmp14 + std::pow(_tmp12, Scalar(2)) +
                      _tmp14 * std::pow(_tmp15, Scalar(2))),
               Scalar(Scalar(-1) / Scalar(2)));
  const Scalar _tmp17 = _tmp13 * _tmp16;
  const Scalar _tmp18 = _tmp10 * _tmp17;
  const Scalar _tmp19 = std::pow(_source_pose[2], Scalar(2));
  const Scalar _tmp20 = -2 * _tmp19;
  const Scalar _tmp21 = std::pow(_source_pose[1], Scalar(2));
  const Scalar _tmp22 = -2 * _tmp21;
  const Scalar _tmp23 = _tmp15 * _tmp17;
  const Scalar _tmp24 = 2 * _source_pose[1];
  const Scalar _tmp25 = _source_pose[0] * _tmp24;
  const Scalar _tmp26 = _source_pose[2] * _tmp6;
  const Scalar _tmp27 = -_tmp26;
  const Scalar _tmp28 = _tmp25 + _tmp27;
  const Scalar _tmp29 = _tmp12 * _tmp16;
  const Scalar _tmp30 = _source_pose[4] - _target_pose[4];
  const Scalar _tmp31 = _tmp18 * _tmp8 + _tmp23 * (_tmp20 + _tmp22 + 1) + _tmp28 * _tmp29 +
                        _tmp30 * source_inverse_range;
  const Scalar _tmp32 = 2 * _target_pose[0] * _target_pose[2];
  const Scalar _tmp33 = 2 * _target_pose[1];
  const Scalar _tmp34 = _target_pose[3] * _tmp33;
  const Scalar _tmp35 = -_tmp34;
  const Scalar _tmp36 = _tmp32 + _tmp35;
  const Scalar _tmp37 = _source_pose[0] * _tmp6;
  const Scalar _tmp38 = _source_pose[2] * _tmp24;
  const Scalar _tmp39 = _tmp37 + _tmp38;
  const Scalar _tmp40 = -_tmp7;
  const Scalar _tmp41 = _tmp40 + _tmp5;
  const Scalar _tmp42 = _source_pose[6] - _target_pose[6];
  const Scalar _tmp43 = std::pow(_source_pose[0], Scalar(2));
  const Scalar _tmp44 = 1 - 2 * _tmp43;
  const Scalar _tmp45 = _tmp18 * (_tmp22 + _tmp44) + _tmp23 * _tmp41 + _tmp29 * _tmp39 +
                        _tmp42 * source_inverse_range;
  const Scalar _tmp46 = 2 * _target_pose[3];
  const Scalar _tmp47 = _target_pose[2] * _tmp46;
  const Scalar _tmp48 = _target_pose[0] * _tmp33;
  const Scalar _tmp49 = _tmp47 + _tmp48;
  const Scalar _tmp50 = _tmp25 + _tmp26;
  const Scalar _tmp51 = -_tmp37;
  const Scalar _tmp52 = _tmp38 + _tmp51;
  const Scalar _tmp53 = _source_pose[5] - _target_pose[5];
  const Scalar _tmp54 = _tmp18 * _tmp52 + _tmp23 * _tmp50 + _tmp29 * (_tmp20 + _tmp44) +
                        _tmp53 * source_inverse_range;
  const Scalar _tmp55 = _tmp36 * _tmp45 + _tmp49 * _tmp54;
  const Scalar _tmp56 = _tmp31 * _tmp4 + _tmp55;
  const Scalar _tmp57 = std::pow(_target_pose[0], Scalar(2));
  const Scalar _tmp58 = -2 * _tmp57;
  const Scalar _tmp59 = _tmp3 + _tmp58;
  const Scalar _tmp60 = _tmp32 + _tmp34;
  const Scalar _tmp61 = _target_pose[2] * _tmp33;
  const Scalar _tmp62 = _target_pose[0] * _tmp46;
  const Scalar _tmp63 = -_tmp62;
  const Scalar _tmp64 = _tmp61 + _tmp63;
  const Scalar _tmp65 = _tmp31 * _tmp60 + _tmp54 * _tmp64;
  const Scalar _tmp66 = _tmp45 * _tmp59 + _tmp65;
  const Scalar _tmp67 = _tmp66 + epsilon * ((((_tmp66) > 0) - ((_tmp66) < 0)) + Scalar(0.5));
  const Scalar _tmp68 = target_calibration_storage(0, 0) * std::atan2(_tmp56, _tmp67) +
                        target_calibration_storage(2, 0) - target_pixel(0, 0);
  const Scalar _tmp69 = _tmp1 + _tmp58 + 1;
  const Scalar _tmp70 = _tmp61 + _tmp62;
  const Scalar _tmp71 = -_tmp47;
  const Scalar _tmp72 = _tmp48 + _tmp71;
  const Scalar _tmp73 = _tmp31 * _tmp72 + _tmp45 * _tmp70;
  const Scalar _tmp74 = _tmp54 * _tmp69 + _tmp73;
  const Scalar _tmp75 = std::pow(_tmp56, Scalar(2));
  const Scalar _tmp76 = std::pow(_tmp66, Scalar(2)) + _tmp75;
  const Scalar _tmp77 = _tmp76 + epsilon;
  const Scalar _tmp78 = std::sqrt(_tmp77);
  const Scalar _tmp79 = target_calibration_storage(1, 0) * std::atan2(_tmp74, _tmp78) +
                        target_calibration_storage(3, 0) - target_pixel(1, 0);
  const Scalar _tmp80 = std::pow(_tmp68, Scalar(2)) + std::pow(_tmp79, Scalar(2)) + epsilon;
  const Scalar _tmp81 = std::pow(_tmp80, Scalar(Scalar(-1) / Scalar(2)));
  const Scalar _tmp82 = std::sqrt(weight);
  const Scalar _tmp83 = Scalar(1.0) / (epsilon - gnc_mu + 1);
  const Scalar _tmp84 = epsilon + std::fabs(_tmp83);
  const Scalar _tmp85 = 2 - _tmp83;
  const Scalar _tmp86 =
      _tmp85 + epsilon * (2 * std::min<Scalar>(0, (((_tmp85) > 0) - ((_tmp85) < 0))) + 1);
  const Scalar _tmp87 = std::pow(gnc_scale, Scalar(-2));
  const Scalar _tmp88 = _tmp80 * _tmp87 / _tmp84 + 1;
  const Scalar _tmp89 = (Scalar(1) / Scalar(2)) * _tmp86;
  const Scalar _tmp90 =
      std::sqrt(Scalar(2)) * std::sqrt(Scalar(_tmp84 * (std::pow(_tmp88, _tmp89) - 1) / _tmp86));
  const Scalar _tmp91 = std::pow(_tmp74, Scalar(2)) + _tmp76;
  const Scalar _tmp92 = std::max<Scalar>(0, (((_tmp91) > 0) - ((_tmp91) < 0)));
  const Scalar _tmp93 = std::max<Scalar>(
      0, std::min<Scalar>(
             (((Scalar(M_PI) - std::fabs(_tmp9)) > 0) - ((Scalar(M_PI) - std::fabs(_tmp9)) < 0)),
             (((-std::fabs(_tmp11) + Scalar(M_PI_2)) > 0) -
              ((-std::fabs(_tmp11) + Scalar(M_PI_2)) < 0))));
  const Scalar _tmp94 = _tmp82 * _tmp90 * _tmp92 * _tmp93;
  const Scalar _tmp95 = _tmp81 * _tmp94;
  const Scalar _tmp96 = _tmp68 * _tmp95;
  const Scalar _tmp97 = _tmp79 * _tmp95;
  const Scalar _tmp98 = std::pow(_source_pose[3], Scalar(2));
  const Scalar _tmp99 = -_tmp21;
  const Scalar _tmp100 = _tmp98 + _tmp99;
  const Scalar _tmp101 = -_tmp43;
  const Scalar _tmp102 = _tmp101 + _tmp19;
  const Scalar _tmp103 = -_tmp38;
  const Scalar _tmp104 = _tmp18 * (_tmp103 + _tmp51) + _tmp29 * (_tmp100 + _tmp102);
  const Scalar _tmp105 = -_tmp98;
  const Scalar _tmp106 = _tmp18 * (_tmp105 + _tmp19 + _tmp43 + _tmp99) + _tmp29 * _tmp52;
  const Scalar _tmp107 = -_tmp25;
  const Scalar _tmp108 = _tmp18 * (_tmp107 + _tmp26) + _tmp29 * _tmp8;
  const Scalar _tmp109 = _tmp104 * _tmp59 + _tmp106 * _tmp64 + _tmp108 * _tmp60;
  const Scalar _tmp110 = 2 * _tmp66;
  const Scalar _tmp111 = _tmp104 * _tmp36 + _tmp106 * _tmp49 + _tmp108 * _tmp4;
  const Scalar _tmp112 = 2 * _tmp56;
  const Scalar _tmp113 = _tmp74 / (_tmp77 * std::sqrt(_tmp77));
  const Scalar _tmp114 = (Scalar(1) / Scalar(2)) * _tmp113;
  const Scalar _tmp115 = Scalar(1.0) / (_tmp78);
  const Scalar _tmp116 = -_tmp114 * (_tmp109 * _tmp110 + _tmp111 * _tmp112) +
                         _tmp115 * (_tmp104 * _tmp70 + _tmp106 * _tmp69 + _tmp108 * _tmp72);
  const Scalar _tmp117 = target_calibration_storage(1, 0) / (_tmp91 + epsilon);
  const Scalar _tmp118 = _tmp117 * _tmp79;
  const Scalar _tmp119 = 2 * _tmp118;
  const Scalar _tmp120 = _tmp119 * _tmp77;
  const Scalar _tmp121 = Scalar(1.0) / (_tmp67);
  const Scalar _tmp122 = std::pow(_tmp67, Scalar(2));
  const Scalar _tmp123 = _tmp56 / _tmp122;
  const Scalar _tmp124 = -_tmp109 * _tmp123 + _tmp111 * _tmp121;
  const Scalar _tmp125 = target_calibration_storage(0, 0) / (_tmp122 + _tmp75);
  const Scalar _tmp126 = _tmp125 * _tmp68;
  const Scalar _tmp127 = 2 * _tmp126;
  const Scalar _tmp128 = _tmp122 * _tmp127;
  const Scalar _tmp129 = _tmp116 * _tmp120 + _tmp124 * _tmp128;
  const Scalar _tmp130 = (Scalar(1) / Scalar(2)) * _tmp68;
  const Scalar _tmp131 =
      _tmp81 * _tmp82 * _tmp87 * std::pow(_tmp88, Scalar(_tmp89 - 1)) * _tmp92 * _tmp93 / _tmp90;
  const Scalar _tmp132 = _tmp130 * _tmp131;
  const Scalar _tmp133 = _tmp94 / (_tmp80 * std::sqrt(_tmp80));
  const Scalar _tmp134 = _tmp130 * _tmp133;
  const Scalar _tmp135 = _tmp125 * _tmp95;
  const Scalar _tmp136 = _tmp122 * _tmp135;
  const Scalar _tmp137 = _tmp124 * _tmp136 + _tmp129 * _tmp132 - _tmp129 * _tmp134;
  const Scalar _tmp138 = (Scalar(1) / Scalar(2)) * _tmp79;
  const Scalar _tmp139 = _tmp131 * _tmp138;
  const Scalar _tmp140 = _tmp133 * _tmp138;
  const Scalar _tmp141 = _tmp117 * _tmp95;
  const Scalar _tmp142 = _tmp141 * _tmp77;
  const Scalar _tmp143 = _tmp116 * _tmp142 + _tmp129 * _tmp139 - _tmp129 * _tmp140;
  const Scalar _tmp144 = -_tmp19;
  const Scalar _tmp145 = _tmp144 + _tmp43;
  const Scalar _tmp146 = _tmp105 + _tmp21;
  const Scalar _tmp147 = _tmp18 * _tmp41 + _tmp23 * (_tmp145 + _tmp146);
  const Scalar _tmp148 = _tmp18 * _tmp50 + _tmp23 * (_tmp103 + _tmp37);
  const Scalar _tmp149 = -_tmp5;
  const Scalar _tmp150 = _tmp18 * (_tmp100 + _tmp145) + _tmp23 * (_tmp149 + _tmp40);
  const Scalar _tmp151 = _tmp147 * _tmp36 + _tmp148 * _tmp49 + _tmp150 * _tmp4;
  const Scalar _tmp152 = _tmp147 * _tmp59 + _tmp148 * _tmp64 + _tmp150 * _tmp60;
  const Scalar _tmp153 = _tmp121 * _tmp151 - _tmp123 * _tmp152;
  const Scalar _tmp154 = -_tmp114 * (_tmp110 * _tmp152 + _tmp112 * _tmp151) +
                         _tmp115 * (_tmp147 * _tmp70 + _tmp148 * _tmp69 + _tmp150 * _tmp72);
  const Scalar _tmp155 = _tmp120 * _tmp154 + _tmp128 * _tmp153;
  const Scalar _tmp156 = _tmp132 * _tmp155 - _tmp134 * _tmp155 + _tmp136 * _tmp153;
  const Scalar _tmp157 = _tmp139 * _tmp155 - _tmp140 * _tmp155 + _tmp142 * _tmp154;
  const Scalar _tmp158 = _tmp23 * _tmp39 + _tmp29 * (_tmp149 + _tmp7);
  const Scalar _tmp159 = _tmp23 * _tmp28 + _tmp29 * (_tmp102 + _tmp146);
  const Scalar _tmp160 =
      _tmp23 * (_tmp101 + _tmp144 + _tmp21 + _tmp98) + _tmp29 * (_tmp107 + _tmp27);
  const Scalar _tmp161 = _tmp158 * _tmp59 + _tmp159 * _tmp60 + _tmp160 * _tmp64;
  const Scalar _tmp162 = _tmp158 * _tmp36 + _tmp159 * _tmp4 + _tmp160 * _tmp49;
  const Scalar _tmp163 = -_tmp114 * (_tmp110 * _tmp161 + _tmp112 * _tmp162) +
                         _tmp115 * (_tmp158 * _tmp70 + _tmp159 * _tmp72 + _tmp160 * _tmp69);
  const Scalar _tmp164 = _tmp122 * (_tmp121 * _tmp162 - _tmp123 * _tmp161);
  const Scalar _tmp165 = _tmp120 * _tmp163 + _tmp127 * _tmp164;
  const Scalar _tmp166 = _tmp132 * _tmp165 - _tmp134 * _tmp165 + _tmp135 * _tmp164;
  const Scalar _tmp167 = _tmp139 * _tmp165 - _tmp140 * _tmp165 + _tmp142 * _tmp163;
  const Scalar _tmp168 = _tmp110 * source_inverse_range;
  const Scalar _tmp169 = _tmp168 * _tmp60;
  const Scalar _tmp170 = _tmp112 * source_inverse_range;
  const Scalar _tmp171 = _tmp170 * _tmp4;
  const Scalar _tmp172 = _tmp115 * source_inverse_range;
  const Scalar _tmp173 = _tmp172 * _tmp72;
  const Scalar _tmp174 = -_tmp114 * (_tmp169 + _tmp171) + _tmp173;
  const Scalar _tmp175 = _tmp121 * source_inverse_range;
  const Scalar _tmp176 = _tmp175 * _tmp4;
  const Scalar _tmp177 = _tmp123 * source_inverse_range;
  const Scalar _tmp178 = _tmp177 * _tmp60;
  const Scalar _tmp179 = _tmp176 - _tmp178;
  const Scalar _tmp180 = _tmp120 * _tmp174 + _tmp128 * _tmp179;
  const Scalar _tmp181 = _tmp132 * _tmp180 - _tmp134 * _tmp180 + _tmp136 * _tmp179;
  const Scalar _tmp182 = _tmp139 * _tmp180 - _tmp140 * _tmp180 + _tmp142 * _tmp174;
  const Scalar _tmp183 = _tmp172 * _tmp69;
  const Scalar _tmp184 = _tmp168 * _tmp64;
  const Scalar _tmp185 = _tmp170 * _tmp49;
  const Scalar _tmp186 = -_tmp114 * (_tmp184 + _tmp185) + _tmp183;
  const Scalar _tmp187 = _tmp175 * _tmp49;
  const Scalar _tmp188 = _tmp177 * _tmp64;
  const Scalar _tmp189 = _tmp187 - _tmp188;
  const Scalar _tmp190 = _tmp120 * _tmp186 + _tmp128 * _tmp189;
  const Scalar _tmp191 = _tmp132 * _tmp190 - _tmp134 * _tmp190 + _tmp136 * _tmp189;
  const Scalar _tmp192 = _tmp138 * _tmp190;
  const Scalar _tmp193 = _tmp131 * _tmp192 - _tmp133 * _tmp192 + _tmp142 * _tmp186;
  const Scalar _tmp194 = _tmp170 * _tmp36;
  const Scalar _tmp195 = _tmp168 * _tmp59;
  const Scalar _tmp196 = _tmp172 * _tmp70;
  const Scalar _tmp197 = -_tmp114 * (_tmp194 + _tmp195) + _tmp196;
  const Scalar _tmp198 = _tmp177 * _tmp59;
  const Scalar _tmp199 = _tmp175 * _tmp36;
  const Scalar _tmp200 = -_tmp198 + _tmp199;
  const Scalar _tmp201 = _tmp120 * _tmp197 + _tmp128 * _tmp200;
  const Scalar _tmp202 = _tmp133 * _tmp201;
  const Scalar _tmp203 = -_tmp130 * _tmp202 + _tmp132 * _tmp201 + _tmp136 * _tmp200;
  const Scalar _tmp204 = -_tmp138 * _tmp202 + _tmp139 * _tmp201 + _tmp142 * _tmp197;
  const Scalar _tmp205 = -_tmp61;
  const Scalar _tmp206 = -_tmp48;
  const Scalar _tmp207 = std::pow(_target_pose[3], Scalar(2));
  const Scalar _tmp208 = -_tmp207;
  const Scalar _tmp209 = _tmp208 + _tmp57;
  const Scalar _tmp210 = -_tmp2;
  const Scalar _tmp211 = _tmp0 + _tmp210;
  const Scalar _tmp212 =
      _tmp31 * (_tmp206 + _tmp47) + _tmp45 * (_tmp205 + _tmp63) + _tmp54 * (_tmp209 + _tmp211);
  const Scalar _tmp213 = -_tmp57;
  const Scalar _tmp214 = _tmp207 + _tmp213;
  const Scalar _tmp215 =
      -_tmp113 * _tmp212 * _tmp66 + _tmp115 * (_tmp45 * (_tmp211 + _tmp214) + _tmp65);
  const Scalar _tmp216 = -_tmp112 * _tmp126 * _tmp212 + _tmp120 * _tmp215;
  const Scalar _tmp217 = _tmp132 * _tmp216 - _tmp134 * _tmp216 - _tmp135 * _tmp212 * _tmp56;
  const Scalar _tmp218 = _tmp139 * _tmp216 - _tmp140 * _tmp216 + _tmp142 * _tmp215;
  const Scalar _tmp219 = -_tmp0;
  const Scalar _tmp220 = _tmp2 + _tmp219;
  const Scalar _tmp221 = -_tmp32;
  const Scalar _tmp222 =
      _tmp31 * (_tmp221 + _tmp35) + _tmp45 * (_tmp209 + _tmp220) + _tmp54 * (_tmp205 + _tmp62);
  const Scalar _tmp223 = _tmp31 * (_tmp207 + _tmp210 + _tmp219 + _tmp57) + _tmp55;
  const Scalar _tmp224 = _tmp115 * _tmp74 * (_tmp110 * _tmp223 + _tmp112 * _tmp222);
  const Scalar _tmp225 = _tmp121 * _tmp222 - _tmp123 * _tmp223;
  const Scalar _tmp226 = -_tmp118 * _tmp224 + _tmp128 * _tmp225;
  const Scalar _tmp227 = _tmp132 * _tmp226 - _tmp134 * _tmp226 + _tmp136 * _tmp225;
  const Scalar _tmp228 =
      _tmp139 * _tmp226 - _tmp140 * _tmp226 - Scalar(1) / Scalar(2) * _tmp141 * _tmp224;
  const Scalar _tmp229 = _tmp54 * (_tmp214 + _tmp220) + _tmp73;
  const Scalar _tmp230 = _tmp229 * _tmp67;
  const Scalar _tmp231 = -_tmp113 * _tmp229 * _tmp56 +
                         _tmp115 * (_tmp31 * (_tmp0 + _tmp2 + _tmp208 + _tmp213) +
                                    _tmp45 * (_tmp221 + _tmp34) + _tmp54 * (_tmp206 + _tmp71));
  const Scalar _tmp232 = _tmp120 * _tmp231 + _tmp127 * _tmp230;
  const Scalar _tmp233 = _tmp132 * _tmp232 - _tmp134 * _tmp232 + _tmp135 * _tmp230;
  const Scalar _tmp234 = _tmp139 * _tmp232 - _tmp140 * _tmp232 + _tmp142 * _tmp231;
  const Scalar _tmp235 = -_tmp176 + _tmp178;
  const Scalar _tmp236 = -_tmp114 * (-_tmp169 - _tmp171) - _tmp173;
  const Scalar _tmp237 = _tmp120 * _tmp236 + _tmp128 * _tmp235;
  const Scalar _tmp238 = _tmp132 * _tmp237 - _tmp134 * _tmp237 + _tmp136 * _tmp235;
  const Scalar _tmp239 = _tmp139 * _tmp237 - _tmp140 * _tmp237 + _tmp142 * _tmp236;
  const Scalar _tmp240 = _tmp77 * (-_tmp114 * (-_tmp184 - _tmp185) - _tmp183);
  const Scalar _tmp241 = -_tmp187 + _tmp188;
  const Scalar _tmp242 = _tmp119 * _tmp240 + _tmp128 * _tmp241;
  const Scalar _tmp243 = _tmp132 * _tmp242 - _tmp134 * _tmp242 + _tmp136 * _tmp241;
  const Scalar _tmp244 = _tmp139 * _tmp242 - _tmp140 * _tmp242 + _tmp141 * _tmp240;
  const Scalar _tmp245 = _tmp198 - _tmp199;
  const Scalar _tmp246 = -_tmp114 * (-_tmp194 - _tmp195) - _tmp196;
  const Scalar _tmp247 = _tmp120 * _tmp246 + _tmp128 * _tmp245;
  const Scalar _tmp248 = _tmp132 * _tmp247 - _tmp134 * _tmp247 + _tmp136 * _tmp245;
  const Scalar _tmp249 = _tmp139 * _tmp247 - _tmp140 * _tmp247 + _tmp142 * _tmp246;
  const Scalar _tmp250 = _tmp30 * _tmp4 + _tmp36 * _tmp42 + _tmp49 * _tmp53;
  const Scalar _tmp251 = _tmp30 * _tmp60 + _tmp42 * _tmp59 + _tmp53 * _tmp64;
  const Scalar _tmp252 = -_tmp114 * (_tmp110 * _tmp251 + _tmp112 * _tmp250) +
                         _tmp115 * (_tmp30 * _tmp72 + _tmp42 * _tmp70 + _tmp53 * _tmp69);
  const Scalar _tmp253 = _tmp121 * _tmp250 - _tmp123 * _tmp251;
  const Scalar _tmp254 = _tmp120 * _tmp252 + _tmp128 * _tmp253;
  const Scalar _tmp255 = _tmp132 * _tmp254 - _tmp134 * _tmp254 + _tmp136 * _tmp253;
  const Scalar _tmp256 = _tmp139 * _tmp254 - _tmp140 * _tmp254 + _tmp142 * _tmp252;

  // Output terms (4)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 2, 1>& _res = (*res);

    _res(0, 0) = _tmp96;
    _res(1, 0) = _tmp97;
  }

  if (jacobian != nullptr) {
    Eigen::Matrix<Scalar, 2, 13>& _jacobian = (*jacobian);

    _jacobian(0, 0) = _tmp137;
    _jacobian(1, 0) = _tmp143;
    _jacobian(0, 1) = _tmp156;
    _jacobian(1, 1) = _tmp157;
    _jacobian(0, 2) = _tmp166;
    _jacobian(1, 2) = _tmp167;
    _jacobian(0, 3) = _tmp181;
    _jacobian(1, 3) = _tmp182;
    _jacobian(0, 4) = _tmp191;
    _jacobian(1, 4) = _tmp193;
    _jacobian(0, 5) = _tmp203;
    _jacobian(1, 5) = _tmp204;
    _jacobian(0, 6) = _tmp217;
    _jacobian(1, 6) = _tmp218;
    _jacobian(0, 7) = _tmp227;
    _jacobian(1, 7) = _tmp228;
    _jacobian(0, 8) = _tmp233;
    _jacobian(1, 8) = _tmp234;
    _jacobian(0, 9) = _tmp238;
    _jacobian(1, 9) = _tmp239;
    _jacobian(0, 10) = _tmp243;
    _jacobian(1, 10) = _tmp244;
    _jacobian(0, 11) = _tmp248;
    _jacobian(1, 11) = _tmp249;
    _jacobian(0, 12) = _tmp255;
    _jacobian(1, 12) = _tmp256;
  }

  if (hessian != nullptr) {
    Eigen::Matrix<Scalar, 13, 13>& _hessian = (*hessian);

    _hessian(0, 0) = std::pow(_tmp137, Scalar(2)) + std::pow(_tmp143, Scalar(2));
    _hessian(1, 0) = _tmp137 * _tmp156 + _tmp143 * _tmp157;
    _hessian(2, 0) = _tmp137 * _tmp166 + _tmp143 * _tmp167;
    _hessian(3, 0) = _tmp137 * _tmp181 + _tmp143 * _tmp182;
    _hessian(4, 0) = _tmp137 * _tmp191 + _tmp143 * _tmp193;
    _hessian(5, 0) = _tmp137 * _tmp203 + _tmp143 * _tmp204;
    _hessian(6, 0) = _tmp137 * _tmp217 + _tmp143 * _tmp218;
    _hessian(7, 0) = _tmp137 * _tmp227 + _tmp143 * _tmp228;
    _hessian(8, 0) = _tmp137 * _tmp233 + _tmp143 * _tmp234;
    _hessian(9, 0) = _tmp137 * _tmp238 + _tmp143 * _tmp239;
    _hessian(10, 0) = _tmp137 * _tmp243 + _tmp143 * _tmp244;
    _hessian(11, 0) = _tmp137 * _tmp248 + _tmp143 * _tmp249;
    _hessian(12, 0) = _tmp137 * _tmp255 + _tmp143 * _tmp256;
    _hessian(0, 1) = 0;
    _hessian(1, 1) = std::pow(_tmp156, Scalar(2)) + std::pow(_tmp157, Scalar(2));
    _hessian(2, 1) = _tmp156 * _tmp166 + _tmp157 * _tmp167;
    _hessian(3, 1) = _tmp156 * _tmp181 + _tmp157 * _tmp182;
    _hessian(4, 1) = _tmp156 * _tmp191 + _tmp157 * _tmp193;
    _hessian(5, 1) = _tmp156 * _tmp203 + _tmp157 * _tmp204;
    _hessian(6, 1) = _tmp156 * _tmp217 + _tmp157 * _tmp218;
    _hessian(7, 1) = _tmp156 * _tmp227 + _tmp157 * _tmp228;
    _hessian(8, 1) = _tmp156 * _tmp233 + _tmp157 * _tmp234;
    _hessian(9, 1) = _tmp156 * _tmp238 + _tmp157 * _tmp239;
    _hessian(10, 1) = _tmp156 * _tmp243 + _tmp157 * _tmp244;
    _hessian(11, 1) = _tmp156 * _tmp248 + _tmp157 * _tmp249;
    _hessian(12, 1) = _tmp156 * _tmp255 + _tmp157 * _tmp256;
    _hessian(0, 2) = 0;
    _hessian(1, 2) = 0;
    _hessian(2, 2) = std::pow(_tmp166, Scalar(2)) + std::pow(_tmp167, Scalar(2));
    _hessian(3, 2) = _tmp166 * _tmp181 + _tmp167 * _tmp182;
    _hessian(4, 2) = _tmp166 * _tmp191 + _tmp167 * _tmp193;
    _hessian(5, 2) = _tmp166 * _tmp203 + _tmp167 * _tmp204;
    _hessian(6, 2) = _tmp166 * _tmp217 + _tmp167 * _tmp218;
    _hessian(7, 2) = _tmp166 * _tmp227 + _tmp167 * _tmp228;
    _hessian(8, 2) = _tmp166 * _tmp233 + _tmp167 * _tmp234;
    _hessian(9, 2) = _tmp166 * _tmp238 + _tmp167 * _tmp239;
    _hessian(10, 2) = _tmp166 * _tmp243 + _tmp167 * _tmp244;
    _hessian(11, 2) = _tmp166 * _tmp248 + _tmp167 * _tmp249;
    _hessian(12, 2) = _tmp166 * _tmp255 + _tmp167 * _tmp256;
    _hessian(0, 3) = 0;
    _hessian(1, 3) = 0;
    _hessian(2, 3) = 0;
    _hessian(3, 3) = std::pow(_tmp181, Scalar(2)) + std::pow(_tmp182, Scalar(2));
    _hessian(4, 3) = _tmp181 * _tmp191 + _tmp182 * _tmp193;
    _hessian(5, 3) = _tmp181 * _tmp203 + _tmp182 * _tmp204;
    _hessian(6, 3) = _tmp181 * _tmp217 + _tmp182 * _tmp218;
    _hessian(7, 3) = _tmp181 * _tmp227 + _tmp182 * _tmp228;
    _hessian(8, 3) = _tmp181 * _tmp233 + _tmp182 * _tmp234;
    _hessian(9, 3) = _tmp181 * _tmp238 + _tmp182 * _tmp239;
    _hessian(10, 3) = _tmp181 * _tmp243 + _tmp182 * _tmp244;
    _hessian(11, 3) = _tmp181 * _tmp248 + _tmp182 * _tmp249;
    _hessian(12, 3) = _tmp181 * _tmp255 + _tmp182 * _tmp256;
    _hessian(0, 4) = 0;
    _hessian(1, 4) = 0;
    _hessian(2, 4) = 0;
    _hessian(3, 4) = 0;
    _hessian(4, 4) = std::pow(_tmp191, Scalar(2)) + std::pow(_tmp193, Scalar(2));
    _hessian(5, 4) = _tmp191 * _tmp203 + _tmp193 * _tmp204;
    _hessian(6, 4) = _tmp191 * _tmp217 + _tmp193 * _tmp218;
    _hessian(7, 4) = _tmp191 * _tmp227 + _tmp193 * _tmp228;
    _hessian(8, 4) = _tmp191 * _tmp233 + _tmp193 * _tmp234;
    _hessian(9, 4) = _tmp191 * _tmp238 + _tmp193 * _tmp239;
    _hessian(10, 4) = _tmp191 * _tmp243 + _tmp193 * _tmp244;
    _hessian(11, 4) = _tmp191 * _tmp248 + _tmp193 * _tmp249;
    _hessian(12, 4) = _tmp191 * _tmp255 + _tmp193 * _tmp256;
    _hessian(0, 5) = 0;
    _hessian(1, 5) = 0;
    _hessian(2, 5) = 0;
    _hessian(3, 5) = 0;
    _hessian(4, 5) = 0;
    _hessian(5, 5) = std::pow(_tmp203, Scalar(2)) + std::pow(_tmp204, Scalar(2));
    _hessian(6, 5) = _tmp203 * _tmp217 + _tmp204 * _tmp218;
    _hessian(7, 5) = _tmp203 * _tmp227 + _tmp204 * _tmp228;
    _hessian(8, 5) = _tmp203 * _tmp233 + _tmp204 * _tmp234;
    _hessian(9, 5) = _tmp203 * _tmp238 + _tmp204 * _tmp239;
    _hessian(10, 5) = _tmp203 * _tmp243 + _tmp204 * _tmp244;
    _hessian(11, 5) = _tmp203 * _tmp248 + _tmp204 * _tmp249;
    _hessian(12, 5) = _tmp203 * _tmp255 + _tmp204 * _tmp256;
    _hessian(0, 6) = 0;
    _hessian(1, 6) = 0;
    _hessian(2, 6) = 0;
    _hessian(3, 6) = 0;
    _hessian(4, 6) = 0;
    _hessian(5, 6) = 0;
    _hessian(6, 6) = std::pow(_tmp217, Scalar(2)) + std::pow(_tmp218, Scalar(2));
    _hessian(7, 6) = _tmp217 * _tmp227 + _tmp218 * _tmp228;
    _hessian(8, 6) = _tmp217 * _tmp233 + _tmp218 * _tmp234;
    _hessian(9, 6) = _tmp217 * _tmp238 + _tmp218 * _tmp239;
    _hessian(10, 6) = _tmp217 * _tmp243 + _tmp218 * _tmp244;
    _hessian(11, 6) = _tmp217 * _tmp248 + _tmp218 * _tmp249;
    _hessian(12, 6) = _tmp217 * _tmp255 + _tmp218 * _tmp256;
    _hessian(0, 7) = 0;
    _hessian(1, 7) = 0;
    _hessian(2, 7) = 0;
    _hessian(3, 7) = 0;
    _hessian(4, 7) = 0;
    _hessian(5, 7) = 0;
    _hessian(6, 7) = 0;
    _hessian(7, 7) = std::pow(_tmp227, Scalar(2)) + std::pow(_tmp228, Scalar(2));
    _hessian(8, 7) = _tmp227 * _tmp233 + _tmp228 * _tmp234;
    _hessian(9, 7) = _tmp227 * _tmp238 + _tmp228 * _tmp239;
    _hessian(10, 7) = _tmp227 * _tmp243 + _tmp228 * _tmp244;
    _hessian(11, 7) = _tmp227 * _tmp248 + _tmp228 * _tmp249;
    _hessian(12, 7) = _tmp227 * _tmp255 + _tmp228 * _tmp256;
    _hessian(0, 8) = 0;
    _hessian(1, 8) = 0;
    _hessian(2, 8) = 0;
    _hessian(3, 8) = 0;
    _hessian(4, 8) = 0;
    _hessian(5, 8) = 0;
    _hessian(6, 8) = 0;
    _hessian(7, 8) = 0;
    _hessian(8, 8) = std::pow(_tmp233, Scalar(2)) + std::pow(_tmp234, Scalar(2));
    _hessian(9, 8) = _tmp233 * _tmp238 + _tmp234 * _tmp239;
    _hessian(10, 8) = _tmp233 * _tmp243 + _tmp234 * _tmp244;
    _hessian(11, 8) = _tmp233 * _tmp248 + _tmp234 * _tmp249;
    _hessian(12, 8) = _tmp233 * _tmp255 + _tmp234 * _tmp256;
    _hessian(0, 9) = 0;
    _hessian(1, 9) = 0;
    _hessian(2, 9) = 0;
    _hessian(3, 9) = 0;
    _hessian(4, 9) = 0;
    _hessian(5, 9) = 0;
    _hessian(6, 9) = 0;
    _hessian(7, 9) = 0;
    _hessian(8, 9) = 0;
    _hessian(9, 9) = std::pow(_tmp238, Scalar(2)) + std::pow(_tmp239, Scalar(2));
    _hessian(10, 9) = _tmp238 * _tmp243 + _tmp239 * _tmp244;
    _hessian(11, 9) = _tmp238 * _tmp248 + _tmp239 * _tmp249;
    _hessian(12, 9) = _tmp238 * _tmp255 + _tmp239 * _tmp256;
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
    _hessian(10, 10) = std::pow(_tmp243, Scalar(2)) + std::pow(_tmp244, Scalar(2));
    _hessian(11, 10) = _tmp243 * _tmp248 + _tmp244 * _tmp249;
    _hessian(12, 10) = _tmp243 * _tmp255 + _tmp244 * _tmp256;
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
    _hessian(11, 11) = std::pow(_tmp248, Scalar(2)) + std::pow(_tmp249, Scalar(2));
    _hessian(12, 11) = _tmp248 * _tmp255 + _tmp249 * _tmp256;
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
    _hessian(12, 12) = std::pow(_tmp255, Scalar(2)) + std::pow(_tmp256, Scalar(2));
  }

  if (rhs != nullptr) {
    Eigen::Matrix<Scalar, 13, 1>& _rhs = (*rhs);

    _rhs(0, 0) = _tmp137 * _tmp96 + _tmp143 * _tmp97;
    _rhs(1, 0) = _tmp156 * _tmp96 + _tmp157 * _tmp97;
    _rhs(2, 0) = _tmp166 * _tmp96 + _tmp167 * _tmp97;
    _rhs(3, 0) = _tmp181 * _tmp96 + _tmp182 * _tmp97;
    _rhs(4, 0) = _tmp191 * _tmp96 + _tmp193 * _tmp97;
    _rhs(5, 0) = _tmp203 * _tmp96 + _tmp204 * _tmp97;
    _rhs(6, 0) = _tmp217 * _tmp96 + _tmp218 * _tmp97;
    _rhs(7, 0) = _tmp227 * _tmp96 + _tmp228 * _tmp97;
    _rhs(8, 0) = _tmp233 * _tmp96 + _tmp234 * _tmp97;
    _rhs(9, 0) = _tmp238 * _tmp96 + _tmp239 * _tmp97;
    _rhs(10, 0) = _tmp243 * _tmp96 + _tmp244 * _tmp97;
    _rhs(11, 0) = _tmp248 * _tmp96 + _tmp249 * _tmp97;
    _rhs(12, 0) = _tmp255 * _tmp96 + _tmp256 * _tmp97;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
