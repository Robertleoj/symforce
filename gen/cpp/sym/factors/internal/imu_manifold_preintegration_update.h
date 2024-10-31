// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Core>

#include <sym/rot3.h>

namespace sym {

/**
 * An internal helper function to update a set of preintegrated IMU measurements with a new pair of
 * gyroscope and accelerometer measurements. Returns the updated preintegrated measurements.
 *
 * NOTE: If you are interested in this function, you should likely be using the
 * ``IntegrateMeasurement`` method of the ``PreintegratedImuMeasurements`` class located in
 * ``symforce/slam/imu_preintegration/preintegrated_imu_measurements.h``.
 *
 * When integrating the first measurement, DR should be the identity, Dv, Dp, covariance, and the
 * derivatives w.r.t. to bias should all be 0.
 *
 * Args:
 *     DR: Preintegrated change in orientation
 *     Dv: Preintegrated change in velocity
 *     Dp: Preintegrated change in position
 *     covariance: Covariance [DR, Dv, Dp] in local coordinates of mean
 *     DR_D_gyro_bias: Derivative of DR w.r.t. gyro_bias
 *     Dv_D_accel_bias: Derivative of Dv w.r.t. accel_bias
 *     Dv_D_gyro_bias: Derivative of Dv w.r.t. gyro_bias
 *     Dp_D_accel_bias: Derivative of Dp w.r.t. accel_bias
 *     Dp_D_gyro_bias: Derivative of Dp w.r.t. gyro_bias
 *     accel_bias: Initial guess for the accelerometer measurement bias
 *     gyro_bias: Initial guess for the gyroscope measurement bias
 *     accel_cov_diagonal: The diagonal of the covariance of the accelerometer measurement
 *     gyro_cov_diagonal: The diagonal of the covariance of the gyroscope measurement
 *     accel_measurement: The accelerometer measurement
 *     gyro_measurement: The gyroscope measurement
 *     dt: The time between the new measurements and the last
 *     epsilon: epsilon for numerical stability
 *
 * Returns:
 *     T.Tuple[sf.Rot3, sf.V3, sf.V3, sf.M99, sf.M33, sf.M33, sf.M33, sf.M33, sf.M33]:
 *         new_DR,
 *         new_Dv,
 *         new_Dp,
 *         new_covariance,
 *         new_DR_D_gyro_bias,
 *         new_Dv_D_accel_bias,
 *         new_Dv_D_gyro_bias,
 *         new_Dp_D_accel_bias
 *         new_Dp_D_gyro_bias,
 */
template <typename Scalar>
void ImuManifoldPreintegrationUpdate(
    const sym::Rot3<Scalar>& DR, const Eigen::Matrix<Scalar, 3, 1>& Dv,
    const Eigen::Matrix<Scalar, 3, 1>& Dp, const Eigen::Matrix<Scalar, 9, 9>& covariance,
    const Eigen::Matrix<Scalar, 3, 3>& DR_D_gyro_bias,
    const Eigen::Matrix<Scalar, 3, 3>& Dv_D_accel_bias,
    const Eigen::Matrix<Scalar, 3, 3>& Dv_D_gyro_bias,
    const Eigen::Matrix<Scalar, 3, 3>& Dp_D_accel_bias,
    const Eigen::Matrix<Scalar, 3, 3>& Dp_D_gyro_bias,
    const Eigen::Matrix<Scalar, 3, 1>& accel_bias, const Eigen::Matrix<Scalar, 3, 1>& gyro_bias,
    const Eigen::Matrix<Scalar, 3, 1>& accel_cov_diagonal,
    const Eigen::Matrix<Scalar, 3, 1>& gyro_cov_diagonal,
    const Eigen::Matrix<Scalar, 3, 1>& accel_measurement,
    const Eigen::Matrix<Scalar, 3, 1>& gyro_measurement, const Scalar dt, const Scalar epsilon,
    sym::Rot3<Scalar>* const new_DR = nullptr, Eigen::Matrix<Scalar, 3, 1>* const new_Dv = nullptr,
    Eigen::Matrix<Scalar, 3, 1>* const new_Dp = nullptr,
    Eigen::Matrix<Scalar, 9, 9>* const new_covariance = nullptr,
    Eigen::Matrix<Scalar, 3, 3>* const new_DR_D_gyro_bias = nullptr,
    Eigen::Matrix<Scalar, 3, 3>* const new_Dv_D_accel_bias = nullptr,
    Eigen::Matrix<Scalar, 3, 3>* const new_Dv_D_gyro_bias = nullptr,
    Eigen::Matrix<Scalar, 3, 3>* const new_Dp_D_accel_bias = nullptr,
    Eigen::Matrix<Scalar, 3, 3>* const new_Dp_D_gyro_bias = nullptr) {
  // Total ops: 1253

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _DR = DR.Data();

  // Intermediate terms (340)
  const Scalar _tmp0 = std::pow(dt, Scalar(2));
  const Scalar _tmp1 = -gyro_bias(2, 0) + gyro_measurement(2, 0);
  const Scalar _tmp2 = _tmp0 * std::pow(_tmp1, Scalar(2));
  const Scalar _tmp3 = -gyro_bias(1, 0) + gyro_measurement(1, 0);
  const Scalar _tmp4 = _tmp0 * std::pow(_tmp3, Scalar(2));
  const Scalar _tmp5 = -gyro_bias(0, 0) + gyro_measurement(0, 0);
  const Scalar _tmp6 = _tmp0 * std::pow(_tmp5, Scalar(2));
  const Scalar _tmp7 = _tmp2 + _tmp4 + _tmp6;
  const Scalar _tmp8 = _tmp7 + std::pow(epsilon, Scalar(2));
  const Scalar _tmp9 = std::sqrt(_tmp8);
  const Scalar _tmp10 = (Scalar(1) / Scalar(2)) * _tmp9;
  const Scalar _tmp11 = std::cos(_tmp10);
  const Scalar _tmp12 = std::sin(_tmp10);
  const Scalar _tmp13 = _tmp12 / _tmp9;
  const Scalar _tmp14 = _tmp13 * dt;
  const Scalar _tmp15 = _tmp14 * _tmp5;
  const Scalar _tmp16 = _tmp14 * _tmp3;
  const Scalar _tmp17 = _tmp1 * dt;
  const Scalar _tmp18 = _tmp13 * _tmp17;
  const Scalar _tmp19 = -2 * std::pow(_DR[2], Scalar(2));
  const Scalar _tmp20 = 1 - 2 * std::pow(_DR[1], Scalar(2));
  const Scalar _tmp21 = _tmp19 + _tmp20;
  const Scalar _tmp22 = -accel_bias(0, 0) + accel_measurement(0, 0);
  const Scalar _tmp23 = 2 * _DR[1];
  const Scalar _tmp24 = _DR[3] * _tmp23;
  const Scalar _tmp25 = 2 * _DR[0];
  const Scalar _tmp26 = _DR[2] * _tmp25;
  const Scalar _tmp27 = _tmp24 + _tmp26;
  const Scalar _tmp28 = -accel_bias(2, 0) + accel_measurement(2, 0);
  const Scalar _tmp29 = _DR[0] * _tmp23;
  const Scalar _tmp30 = 2 * _DR[2] * _DR[3];
  const Scalar _tmp31 = _tmp29 - _tmp30;
  const Scalar _tmp32 = -accel_bias(1, 0) + accel_measurement(1, 0);
  const Scalar _tmp33 = _tmp21 * _tmp22 + _tmp27 * _tmp28 + _tmp31 * _tmp32;
  const Scalar _tmp34 = -2 * std::pow(_DR[0], Scalar(2));
  const Scalar _tmp35 = _tmp19 + _tmp34 + 1;
  const Scalar _tmp36 = _tmp29 + _tmp30;
  const Scalar _tmp37 = _DR[3] * _tmp25;
  const Scalar _tmp38 = _DR[2] * _tmp23;
  const Scalar _tmp39 = -_tmp37 + _tmp38;
  const Scalar _tmp40 = _tmp22 * _tmp36 + _tmp28 * _tmp39 + _tmp32 * _tmp35;
  const Scalar _tmp41 = _tmp20 + _tmp34;
  const Scalar _tmp42 = -_tmp24 + _tmp26;
  const Scalar _tmp43 = _tmp37 + _tmp38;
  const Scalar _tmp44 = _tmp22 * _tmp42 + _tmp28 * _tmp41 + _tmp32 * _tmp43;
  const Scalar _tmp45 = (Scalar(1) / Scalar(2)) * _tmp0;
  const Scalar _tmp46 = 2 * _tmp11;
  const Scalar _tmp47 = _tmp16 * _tmp46;
  const Scalar _tmp48 = 2 * std::pow(_tmp12, Scalar(2)) / _tmp8;
  const Scalar _tmp49 = _tmp0 * _tmp5;
  const Scalar _tmp50 = _tmp48 * _tmp49;
  const Scalar _tmp51 = _tmp1 * _tmp50;
  const Scalar _tmp52 = -_tmp47 + _tmp51;
  const Scalar _tmp53 = _tmp18 * _tmp46;
  const Scalar _tmp54 = _tmp3 * _tmp50;
  const Scalar _tmp55 = _tmp53 + _tmp54;
  const Scalar _tmp56 = -_tmp2 * _tmp48;
  const Scalar _tmp57 = -_tmp4 * _tmp48 + 1;
  const Scalar _tmp58 = _tmp56 + _tmp57;
  const Scalar _tmp59 = _tmp7 + std::sqrt(epsilon);
  const Scalar _tmp60 = std::sqrt(_tmp59);
  const Scalar _tmp61 = (1 - std::cos(_tmp60)) / _tmp59;
  const Scalar _tmp62 = _tmp17 * _tmp61;
  const Scalar _tmp63 = (_tmp60 - std::sin(_tmp60)) / (_tmp59 * std::sqrt(_tmp59));
  const Scalar _tmp64 = _tmp49 * _tmp63;
  const Scalar _tmp65 = _tmp3 * _tmp64;
  const Scalar _tmp66 = _tmp62 + _tmp65;
  const Scalar _tmp67 = dt * gyro_cov_diagonal(1, 0);
  const Scalar _tmp68 = _tmp61 * dt;
  const Scalar _tmp69 = _tmp3 * _tmp68;
  const Scalar _tmp70 = _tmp1 * _tmp64;
  const Scalar _tmp71 = -_tmp69 + _tmp70;
  const Scalar _tmp72 = dt * gyro_cov_diagonal(2, 0);
  const Scalar _tmp73 = -_tmp2;
  const Scalar _tmp74 = -_tmp4;
  const Scalar _tmp75 = _tmp63 * (_tmp73 + _tmp74) + 1;
  const Scalar _tmp76 = dt * gyro_cov_diagonal(0, 0);
  const Scalar _tmp77 = -_tmp53 + _tmp54;
  const Scalar _tmp78 = _tmp15 * _tmp46;
  const Scalar _tmp79 = _tmp0 * _tmp1 * _tmp3;
  const Scalar _tmp80 = _tmp48 * _tmp79;
  const Scalar _tmp81 = _tmp78 + _tmp80;
  const Scalar _tmp82 = -_tmp48 * _tmp6;
  const Scalar _tmp83 = _tmp56 + _tmp82 + 1;
  const Scalar _tmp84 =
      _tmp77 * covariance(1, 0) + _tmp81 * covariance(2, 1) + _tmp83 * covariance(1, 1);
  const Scalar _tmp85 = -_tmp6;
  const Scalar _tmp86 = _tmp63 * (_tmp73 + _tmp85) + 1;
  const Scalar _tmp87 = _tmp86 * dt;
  const Scalar _tmp88 = _tmp66 * gyro_cov_diagonal(1, 0);
  const Scalar _tmp89 =
      _tmp77 * covariance(2, 0) + _tmp81 * covariance(2, 2) + _tmp83 * covariance(2, 1);
  const Scalar _tmp90 =
      _tmp77 * covariance(0, 0) + _tmp81 * covariance(2, 0) + _tmp83 * covariance(1, 0);
  const Scalar _tmp91 = _tmp5 * _tmp68;
  const Scalar _tmp92 = _tmp63 * _tmp79;
  const Scalar _tmp93 = _tmp91 + _tmp92;
  const Scalar _tmp94 = _tmp93 * dt;
  const Scalar _tmp95 = _tmp94 * gyro_cov_diagonal(2, 0);
  const Scalar _tmp96 = _tmp75 * dt;
  const Scalar _tmp97 = -_tmp62 + _tmp65;
  const Scalar _tmp98 = _tmp97 * gyro_cov_diagonal(0, 0);
  const Scalar _tmp99 = _tmp52 * _tmp89 + _tmp55 * _tmp84 + _tmp58 * _tmp90 + _tmp71 * _tmp95 +
                        _tmp87 * _tmp88 + _tmp96 * _tmp98;
  const Scalar _tmp100 = -_tmp78 + _tmp80;
  const Scalar _tmp101 = _tmp47 + _tmp51;
  const Scalar _tmp102 = _tmp57 + _tmp82;
  const Scalar _tmp103 =
      _tmp100 * covariance(2, 1) + _tmp101 * covariance(2, 0) + _tmp102 * covariance(2, 2);
  const Scalar _tmp104 = -_tmp91 + _tmp92;
  const Scalar _tmp105 = _tmp104 * dt;
  const Scalar _tmp106 = _tmp69 + _tmp70;
  const Scalar _tmp107 =
      _tmp100 * covariance(1, 0) + _tmp101 * covariance(0, 0) + _tmp102 * covariance(2, 0);
  const Scalar _tmp108 =
      _tmp100 * covariance(1, 1) + _tmp101 * covariance(1, 0) + _tmp102 * covariance(2, 1);
  const Scalar _tmp109 = _tmp63 * (_tmp74 + _tmp85) + 1;
  const Scalar _tmp110 = _tmp109 * dt;
  const Scalar _tmp111 = _tmp103 * _tmp52 + _tmp105 * _tmp88 +
                         _tmp106 * _tmp96 * gyro_cov_diagonal(0, 0) + _tmp107 * _tmp58 +
                         _tmp108 * _tmp55 + _tmp110 * _tmp71 * gyro_cov_diagonal(2, 0);
  const Scalar _tmp112 = _tmp27 * dt;
  const Scalar _tmp113 = _tmp21 * dt;
  const Scalar _tmp114 = -_tmp112 * _tmp22 + _tmp113 * _tmp28;
  const Scalar _tmp115 = _tmp114 * covariance(2, 1);
  const Scalar _tmp116 = _tmp31 * dt;
  const Scalar _tmp117 = _tmp112 * _tmp32 - _tmp116 * _tmp28;
  const Scalar _tmp118 = _tmp117 * covariance(2, 0);
  const Scalar _tmp119 = -_tmp113 * _tmp32 + _tmp116 * _tmp22;
  const Scalar _tmp120 = _tmp119 * covariance(2, 2);
  const Scalar _tmp121 = _tmp115 + _tmp118 + _tmp120 + covariance(3, 2);
  const Scalar _tmp122 = _tmp114 * covariance(1, 1);
  const Scalar _tmp123 = _tmp117 * covariance(1, 0);
  const Scalar _tmp124 = _tmp119 * covariance(2, 1);
  const Scalar _tmp125 = _tmp122 + _tmp123 + _tmp124 + covariance(3, 1);
  const Scalar _tmp126 = _tmp114 * covariance(1, 0);
  const Scalar _tmp127 = _tmp117 * covariance(0, 0);
  const Scalar _tmp128 = _tmp119 * covariance(2, 0);
  const Scalar _tmp129 = _tmp126 + _tmp127 + _tmp128 + covariance(3, 0);
  const Scalar _tmp130 = _tmp121 * _tmp52 + _tmp125 * _tmp55 + _tmp129 * _tmp58;
  const Scalar _tmp131 = _tmp36 * dt;
  const Scalar _tmp132 = _tmp35 * dt;
  const Scalar _tmp133 = -_tmp131 * _tmp32 + _tmp132 * _tmp22;
  const Scalar _tmp134 = _tmp133 * covariance(2, 2);
  const Scalar _tmp135 = _tmp39 * dt;
  const Scalar _tmp136 = -_tmp132 * _tmp28 + _tmp135 * _tmp32;
  const Scalar _tmp137 = _tmp136 * covariance(2, 0);
  const Scalar _tmp138 = _tmp131 * _tmp28 - _tmp135 * _tmp22;
  const Scalar _tmp139 = _tmp138 * covariance(2, 1);
  const Scalar _tmp140 = _tmp134 + _tmp137 + _tmp139 + covariance(4, 2);
  const Scalar _tmp141 = _tmp133 * covariance(2, 0);
  const Scalar _tmp142 = _tmp136 * covariance(0, 0);
  const Scalar _tmp143 = _tmp138 * covariance(1, 0);
  const Scalar _tmp144 = _tmp141 + _tmp142 + _tmp143 + covariance(4, 0);
  const Scalar _tmp145 = _tmp133 * covariance(2, 1);
  const Scalar _tmp146 = _tmp136 * covariance(1, 0);
  const Scalar _tmp147 = _tmp138 * covariance(1, 1);
  const Scalar _tmp148 = _tmp145 + _tmp146 + _tmp147 + covariance(4, 1);
  const Scalar _tmp149 = _tmp140 * _tmp52 + _tmp144 * _tmp58 + _tmp148 * _tmp55;
  const Scalar _tmp150 = _tmp42 * dt;
  const Scalar _tmp151 = _tmp41 * dt;
  const Scalar _tmp152 = _tmp150 * _tmp28 - _tmp151 * _tmp22;
  const Scalar _tmp153 = _tmp152 * covariance(1, 0);
  const Scalar _tmp154 = _tmp43 * dt;
  const Scalar _tmp155 = _tmp151 * _tmp32 - _tmp154 * _tmp28;
  const Scalar _tmp156 = _tmp155 * covariance(0, 0);
  const Scalar _tmp157 = -_tmp150 * _tmp32 + _tmp154 * _tmp22;
  const Scalar _tmp158 = _tmp157 * covariance(2, 0);
  const Scalar _tmp159 = _tmp153 + _tmp156 + _tmp158 + covariance(5, 0);
  const Scalar _tmp160 = _tmp152 * covariance(2, 1);
  const Scalar _tmp161 = _tmp155 * covariance(2, 0);
  const Scalar _tmp162 = _tmp157 * covariance(2, 2);
  const Scalar _tmp163 = _tmp160 + _tmp161 + _tmp162 + covariance(5, 2);
  const Scalar _tmp164 = _tmp152 * covariance(1, 1);
  const Scalar _tmp165 = _tmp155 * covariance(1, 0);
  const Scalar _tmp166 = _tmp157 * covariance(2, 1);
  const Scalar _tmp167 = _tmp164 + _tmp165 + _tmp166 + covariance(5, 1);
  const Scalar _tmp168 = _tmp159 * _tmp58 + _tmp163 * _tmp52 + _tmp167 * _tmp55;
  const Scalar _tmp169 = (Scalar(1) / Scalar(2)) * dt;
  const Scalar _tmp170 = _tmp122 * _tmp169 + _tmp123 * _tmp169 + _tmp124 * _tmp169 +
                         covariance(3, 1) * dt + covariance(6, 1);
  const Scalar _tmp171 = _tmp115 * _tmp169 + _tmp118 * _tmp169 + _tmp120 * _tmp169 +
                         covariance(3, 2) * dt + covariance(6, 2);
  const Scalar _tmp172 = _tmp126 * _tmp169 + _tmp127 * _tmp169 + _tmp128 * _tmp169 +
                         covariance(3, 0) * dt + covariance(6, 0);
  const Scalar _tmp173 = _tmp170 * _tmp55 + _tmp171 * _tmp52 + _tmp172 * _tmp58;
  const Scalar _tmp174 = covariance(4, 0) * dt;
  const Scalar _tmp175 =
      _tmp141 * _tmp169 + _tmp142 * _tmp169 + _tmp143 * _tmp169 + _tmp174 + covariance(7, 0);
  const Scalar _tmp176 = covariance(4, 1) * dt;
  const Scalar _tmp177 =
      _tmp145 * _tmp169 + _tmp146 * _tmp169 + _tmp147 * _tmp169 + _tmp176 + covariance(7, 1);
  const Scalar _tmp178 = covariance(4, 2) * dt;
  const Scalar _tmp179 =
      _tmp134 * _tmp169 + _tmp137 * _tmp169 + _tmp139 * _tmp169 + _tmp178 + covariance(7, 2);
  const Scalar _tmp180 = _tmp175 * _tmp58 + _tmp177 * _tmp55 + _tmp179 * _tmp52;
  const Scalar _tmp181 = covariance(5, 0) * dt;
  const Scalar _tmp182 =
      _tmp153 * _tmp169 + _tmp156 * _tmp169 + _tmp158 * _tmp169 + _tmp181 + covariance(8, 0);
  const Scalar _tmp183 = covariance(5, 1) * dt;
  const Scalar _tmp184 =
      _tmp164 * _tmp169 + _tmp165 * _tmp169 + _tmp166 * _tmp169 + _tmp183 + covariance(8, 1);
  const Scalar _tmp185 = covariance(5, 2) * dt;
  const Scalar _tmp186 =
      _tmp160 * _tmp169 + _tmp161 * _tmp169 + _tmp162 * _tmp169 + _tmp185 + covariance(8, 2);
  const Scalar _tmp187 = _tmp182 * _tmp58 + _tmp184 * _tmp55 + _tmp186 * _tmp52;
  const Scalar _tmp188 = _tmp106 * dt;
  const Scalar _tmp189 = _tmp103 * _tmp81 + _tmp105 * _tmp86 * gyro_cov_diagonal(1, 0) +
                         _tmp107 * _tmp77 + _tmp108 * _tmp83 + _tmp109 * _tmp95 + _tmp188 * _tmp98;
  const Scalar _tmp190 = _tmp121 * _tmp81 + _tmp125 * _tmp83 + _tmp129 * _tmp77;
  const Scalar _tmp191 = _tmp140 * _tmp81 + _tmp144 * _tmp77 + _tmp148 * _tmp83;
  const Scalar _tmp192 = _tmp159 * _tmp77 + _tmp163 * _tmp81 + _tmp167 * _tmp83;
  const Scalar _tmp193 = _tmp170 * _tmp83 + _tmp171 * _tmp81 + _tmp172 * _tmp77;
  const Scalar _tmp194 = _tmp175 * _tmp77 + _tmp177 * _tmp83 + _tmp179 * _tmp81;
  const Scalar _tmp195 = _tmp182 * _tmp77 + _tmp184 * _tmp83 + _tmp186 * _tmp81;
  const Scalar _tmp196 = _tmp100 * _tmp125 + _tmp101 * _tmp129 + _tmp102 * _tmp121;
  const Scalar _tmp197 = _tmp100 * _tmp148 + _tmp101 * _tmp144 + _tmp102 * _tmp140;
  const Scalar _tmp198 = _tmp100 * _tmp167 + _tmp101 * _tmp159 + _tmp102 * _tmp163;
  const Scalar _tmp199 = _tmp100 * _tmp170 + _tmp101 * _tmp172 + _tmp102 * _tmp171;
  const Scalar _tmp200 = _tmp100 * _tmp177 + _tmp101 * _tmp175 + _tmp102 * _tmp179;
  const Scalar _tmp201 = _tmp100 * _tmp184 + _tmp101 * _tmp182 + _tmp102 * _tmp186;
  const Scalar _tmp202 = _tmp114 * covariance(3, 1);
  const Scalar _tmp203 = std::pow(_tmp31, Scalar(2));
  const Scalar _tmp204 = accel_cov_diagonal(1, 0) * dt;
  const Scalar _tmp205 = std::pow(_tmp27, Scalar(2));
  const Scalar _tmp206 = accel_cov_diagonal(2, 0) * dt;
  const Scalar _tmp207 = std::pow(_tmp21, Scalar(2));
  const Scalar _tmp208 = accel_cov_diagonal(0, 0) * dt;
  const Scalar _tmp209 = _tmp117 * covariance(3, 0);
  const Scalar _tmp210 = _tmp119 * covariance(3, 2);
  const Scalar _tmp211 = _tmp133 * covariance(3, 2);
  const Scalar _tmp212 = _tmp27 * accel_cov_diagonal(2, 0);
  const Scalar _tmp213 = _tmp136 * covariance(3, 0);
  const Scalar _tmp214 = _tmp138 * covariance(3, 1);
  const Scalar _tmp215 = _tmp35 * accel_cov_diagonal(1, 0);
  const Scalar _tmp216 = _tmp131 * accel_cov_diagonal(0, 0);
  const Scalar _tmp217 = _tmp114 * _tmp148 + _tmp116 * _tmp215 + _tmp117 * _tmp144 +
                         _tmp119 * _tmp140 + _tmp135 * _tmp212 + _tmp21 * _tmp216 + _tmp211 +
                         _tmp213 + _tmp214 + covariance(4, 3);
  const Scalar _tmp218 = _tmp21 * accel_cov_diagonal(0, 0);
  const Scalar _tmp219 = _tmp151 * accel_cov_diagonal(2, 0);
  const Scalar _tmp220 = _tmp152 * covariance(3, 1);
  const Scalar _tmp221 = _tmp155 * covariance(3, 0);
  const Scalar _tmp222 = _tmp31 * accel_cov_diagonal(1, 0);
  const Scalar _tmp223 = _tmp157 * covariance(3, 2);
  const Scalar _tmp224 = _tmp114 * _tmp167 + _tmp117 * _tmp159 + _tmp119 * _tmp163 +
                         _tmp150 * _tmp218 + _tmp154 * _tmp222 + _tmp219 * _tmp27 + _tmp220 +
                         _tmp221 + _tmp223 + covariance(5, 3);
  const Scalar _tmp225 = _tmp117 * _tmp172;
  const Scalar _tmp226 = _tmp114 * _tmp170;
  const Scalar _tmp227 = _tmp203 * accel_cov_diagonal(1, 0);
  const Scalar _tmp228 = _tmp205 * accel_cov_diagonal(2, 0);
  const Scalar _tmp229 = _tmp207 * accel_cov_diagonal(0, 0);
  const Scalar _tmp230 = _tmp119 * _tmp171;
  const Scalar _tmp231 = _tmp169 * _tmp202 + _tmp169 * _tmp209 + _tmp169 * _tmp210 +
                         covariance(3, 3) * dt + covariance(6, 3);
  const Scalar _tmp232 = _tmp225 + _tmp226 + _tmp227 * _tmp45 + _tmp228 * _tmp45 +
                         _tmp229 * _tmp45 + _tmp230 + _tmp231;
  const Scalar _tmp233 = _tmp117 * _tmp175;
  const Scalar _tmp234 = _tmp119 * _tmp179;
  const Scalar _tmp235 = _tmp114 * _tmp177;
  const Scalar _tmp236 = covariance(4, 3) * dt;
  const Scalar _tmp237 =
      _tmp169 * _tmp211 + _tmp169 * _tmp213 + _tmp169 * _tmp214 + _tmp236 + covariance(7, 3);
  const Scalar _tmp238 = _tmp39 * _tmp45;
  const Scalar _tmp239 = _tmp31 * _tmp45;
  const Scalar _tmp240 = _tmp21 * _tmp45;
  const Scalar _tmp241 = _tmp36 * accel_cov_diagonal(0, 0);
  const Scalar _tmp242 = _tmp212 * _tmp238 + _tmp215 * _tmp239 + _tmp240 * _tmp241;
  const Scalar _tmp243 = _tmp233 + _tmp234 + _tmp235 + _tmp237 + _tmp242;
  const Scalar _tmp244 = _tmp117 * _tmp182;
  const Scalar _tmp245 = _tmp119 * _tmp186;
  const Scalar _tmp246 = _tmp114 * _tmp184;
  const Scalar _tmp247 = covariance(5, 3) * dt;
  const Scalar _tmp248 =
      _tmp169 * _tmp220 + _tmp169 * _tmp221 + _tmp169 * _tmp223 + _tmp247 + covariance(8, 3);
  const Scalar _tmp249 = _tmp42 * _tmp45;
  const Scalar _tmp250 = _tmp27 * _tmp45;
  const Scalar _tmp251 = _tmp41 * accel_cov_diagonal(2, 0);
  const Scalar _tmp252 = _tmp43 * _tmp45;
  const Scalar _tmp253 = _tmp218 * _tmp249 + _tmp222 * _tmp252 + _tmp250 * _tmp251;
  const Scalar _tmp254 = _tmp244 + _tmp245 + _tmp246 + _tmp248 + _tmp253;
  const Scalar _tmp255 = _tmp133 * covariance(4, 2);
  const Scalar _tmp256 = std::pow(_tmp39, Scalar(2));
  const Scalar _tmp257 = std::pow(_tmp36, Scalar(2));
  const Scalar _tmp258 = std::pow(_tmp35, Scalar(2));
  const Scalar _tmp259 = _tmp136 * covariance(4, 0);
  const Scalar _tmp260 = _tmp138 * covariance(4, 1);
  const Scalar _tmp261 = _tmp152 * covariance(4, 1);
  const Scalar _tmp262 = _tmp155 * covariance(4, 0);
  const Scalar _tmp263 = _tmp157 * covariance(4, 2);
  const Scalar _tmp264 = _tmp133 * _tmp163 + _tmp136 * _tmp159 + _tmp138 * _tmp167 +
                         _tmp154 * _tmp215 + _tmp216 * _tmp42 + _tmp219 * _tmp39 + _tmp261 +
                         _tmp262 + _tmp263 + covariance(5, 4);
  const Scalar _tmp265 = (Scalar(1) / Scalar(2)) * _tmp114;
  const Scalar _tmp266 = (Scalar(1) / Scalar(2)) * _tmp117 * _tmp174 +
                         (Scalar(1) / Scalar(2)) * _tmp119 * _tmp178 + _tmp133 * _tmp171 +
                         _tmp136 * _tmp172 + _tmp138 * _tmp170 + _tmp176 * _tmp265 + _tmp236 +
                         _tmp242 + covariance(6, 4);
  const Scalar _tmp267 = _tmp256 * accel_cov_diagonal(2, 0);
  const Scalar _tmp268 = _tmp136 * _tmp175;
  const Scalar _tmp269 = _tmp257 * accel_cov_diagonal(0, 0);
  const Scalar _tmp270 = _tmp258 * accel_cov_diagonal(1, 0);
  const Scalar _tmp271 = _tmp133 * _tmp179;
  const Scalar _tmp272 = _tmp138 * _tmp177;
  const Scalar _tmp273 = _tmp169 * _tmp255 + _tmp169 * _tmp259 + _tmp169 * _tmp260 +
                         covariance(4, 4) * dt + covariance(7, 4);
  const Scalar _tmp274 = _tmp267 * _tmp45 + _tmp268 + _tmp269 * _tmp45 + _tmp270 * _tmp45 +
                         _tmp271 + _tmp272 + _tmp273;
  const Scalar _tmp275 = _tmp133 * _tmp186;
  const Scalar _tmp276 = _tmp136 * _tmp182;
  const Scalar _tmp277 = _tmp138 * _tmp184;
  const Scalar _tmp278 = covariance(5, 4) * dt;
  const Scalar _tmp279 =
      _tmp169 * _tmp261 + _tmp169 * _tmp262 + _tmp169 * _tmp263 + _tmp278 + covariance(8, 4);
  const Scalar _tmp280 = _tmp215 * _tmp252 + _tmp238 * _tmp251 + _tmp241 * _tmp249;
  const Scalar _tmp281 = _tmp275 + _tmp276 + _tmp277 + _tmp279 + _tmp280;
  const Scalar _tmp282 = std::pow(_tmp43, Scalar(2));
  const Scalar _tmp283 = _tmp152 * covariance(5, 1);
  const Scalar _tmp284 = _tmp155 * covariance(5, 0);
  const Scalar _tmp285 = std::pow(_tmp42, Scalar(2));
  const Scalar _tmp286 = std::pow(_tmp41, Scalar(2));
  const Scalar _tmp287 = _tmp157 * covariance(5, 2);
  const Scalar _tmp288 = (Scalar(1) / Scalar(2)) * _tmp185;
  const Scalar _tmp289 = (Scalar(1) / Scalar(2)) * _tmp181;
  const Scalar _tmp290 = _tmp117 * _tmp289 + _tmp119 * _tmp288 + _tmp152 * _tmp170 +
                         _tmp155 * _tmp172 + _tmp157 * _tmp171 + _tmp183 * _tmp265 + _tmp247 +
                         _tmp253 + covariance(6, 5);
  const Scalar _tmp291 = _tmp133 * _tmp288 + _tmp136 * _tmp289 +
                         (Scalar(1) / Scalar(2)) * _tmp138 * _tmp183 + _tmp152 * _tmp177 +
                         _tmp155 * _tmp175 + _tmp157 * _tmp179 + _tmp278 + _tmp280 +
                         covariance(7, 5);
  const Scalar _tmp292 = _tmp282 * accel_cov_diagonal(1, 0);
  const Scalar _tmp293 = _tmp285 * accel_cov_diagonal(0, 0);
  const Scalar _tmp294 = _tmp286 * accel_cov_diagonal(2, 0);
  const Scalar _tmp295 = _tmp157 * _tmp186;
  const Scalar _tmp296 = _tmp155 * _tmp182;
  const Scalar _tmp297 = _tmp152 * _tmp184;
  const Scalar _tmp298 = _tmp169 * _tmp283 + _tmp169 * _tmp284 + _tmp169 * _tmp287 +
                         covariance(5, 5) * dt + covariance(8, 5);
  const Scalar _tmp299 = _tmp292 * _tmp45 + _tmp293 * _tmp45 + _tmp294 * _tmp45 + _tmp295 +
                         _tmp296 + _tmp297 + _tmp298;
  const Scalar _tmp300 = (Scalar(1) / Scalar(4)) * [&]() {
    const Scalar base = dt;
    return base * base * base;
  }();
  const Scalar _tmp301 = _tmp169 * covariance(6, 1);
  const Scalar _tmp302 = _tmp133 * _tmp169;
  const Scalar _tmp303 = _tmp136 * _tmp169;
  const Scalar _tmp304 = _tmp212 * _tmp300;
  const Scalar _tmp305 = _tmp218 * _tmp300;
  const Scalar _tmp306 = _tmp138 * _tmp301 + _tmp169 * _tmp233 + _tmp169 * _tmp234 +
                         _tmp169 * _tmp235 + _tmp215 * _tmp300 * _tmp31 + _tmp237 * dt +
                         _tmp302 * covariance(6, 2) + _tmp303 * covariance(6, 0) +
                         _tmp304 * _tmp39 + _tmp305 * _tmp36 + covariance(6, 4) * dt +
                         covariance(7, 6);
  const Scalar _tmp307 = _tmp157 * _tmp169;
  const Scalar _tmp308 = _tmp300 * _tmp43;
  const Scalar _tmp309 = _tmp155 * _tmp169;
  const Scalar _tmp310 = _tmp152 * _tmp301 + _tmp169 * _tmp244 + _tmp169 * _tmp245 +
                         _tmp169 * _tmp246 + _tmp222 * _tmp308 + _tmp248 * dt + _tmp304 * _tmp41 +
                         _tmp305 * _tmp42 + _tmp307 * covariance(6, 2) +
                         _tmp309 * covariance(6, 0) + covariance(6, 5) * dt + covariance(8, 6);
  const Scalar _tmp311 = _tmp152 * _tmp169;
  const Scalar _tmp312 = _tmp169 * _tmp275 + _tmp169 * _tmp276 + _tmp169 * _tmp277 +
                         _tmp215 * _tmp308 + _tmp241 * _tmp300 * _tmp42 +
                         _tmp251 * _tmp300 * _tmp39 + _tmp279 * dt + _tmp307 * covariance(7, 2) +
                         _tmp309 * covariance(7, 0) + _tmp311 * covariance(7, 1) +
                         covariance(7, 5) * dt + covariance(8, 7);
  const Scalar _tmp313 = DR_D_gyro_bias(0, 0) * _tmp117;
  const Scalar _tmp314 = DR_D_gyro_bias(2, 0) * _tmp119;
  const Scalar _tmp315 = DR_D_gyro_bias(1, 0) * _tmp114;
  const Scalar _tmp316 = DR_D_gyro_bias(1, 0) * _tmp138;
  const Scalar _tmp317 = DR_D_gyro_bias(2, 0) * _tmp133;
  const Scalar _tmp318 = DR_D_gyro_bias(0, 0) * _tmp136;
  const Scalar _tmp319 = DR_D_gyro_bias(0, 0) * _tmp155;
  const Scalar _tmp320 = DR_D_gyro_bias(2, 0) * _tmp157;
  const Scalar _tmp321 = DR_D_gyro_bias(1, 0) * _tmp152;
  const Scalar _tmp322 = DR_D_gyro_bias(0, 1) * _tmp117;
  const Scalar _tmp323 = DR_D_gyro_bias(2, 1) * _tmp119;
  const Scalar _tmp324 = DR_D_gyro_bias(1, 1) * _tmp114;
  const Scalar _tmp325 = DR_D_gyro_bias(1, 1) * _tmp138;
  const Scalar _tmp326 = DR_D_gyro_bias(2, 1) * _tmp133;
  const Scalar _tmp327 = DR_D_gyro_bias(0, 1) * _tmp136;
  const Scalar _tmp328 = DR_D_gyro_bias(0, 1) * _tmp155;
  const Scalar _tmp329 = DR_D_gyro_bias(2, 1) * _tmp157;
  const Scalar _tmp330 = DR_D_gyro_bias(1, 1) * _tmp152;
  const Scalar _tmp331 = DR_D_gyro_bias(0, 2) * _tmp117;
  const Scalar _tmp332 = DR_D_gyro_bias(2, 2) * _tmp119;
  const Scalar _tmp333 = DR_D_gyro_bias(1, 2) * _tmp114;
  const Scalar _tmp334 = DR_D_gyro_bias(1, 2) * _tmp138;
  const Scalar _tmp335 = DR_D_gyro_bias(2, 2) * _tmp133;
  const Scalar _tmp336 = DR_D_gyro_bias(0, 2) * _tmp136;
  const Scalar _tmp337 = DR_D_gyro_bias(0, 2) * _tmp155;
  const Scalar _tmp338 = DR_D_gyro_bias(2, 2) * _tmp157;
  const Scalar _tmp339 = DR_D_gyro_bias(1, 2) * _tmp152;

  // Output terms (9)
  if (new_DR != nullptr) {
    Eigen::Matrix<Scalar, 4, 1> _new_DR;

    _new_DR[0] = _DR[0] * _tmp11 + _DR[1] * _tmp18 - _DR[2] * _tmp16 + _DR[3] * _tmp15;
    _new_DR[1] = -_DR[0] * _tmp18 + _DR[1] * _tmp11 + _DR[2] * _tmp15 + _DR[3] * _tmp16;
    _new_DR[2] = _DR[0] * _tmp16 - _DR[1] * _tmp15 + _DR[2] * _tmp11 + _DR[3] * _tmp18;
    _new_DR[3] = -_DR[0] * _tmp15 - _DR[1] * _tmp16 - _DR[2] * _tmp18 + _DR[3] * _tmp11;

    *new_DR = sym::Rot3<Scalar>(_new_DR);
  }

  if (new_Dv != nullptr) {
    Eigen::Matrix<Scalar, 3, 1>& _new_Dv = (*new_Dv);

    _new_Dv(0, 0) = Dv(0, 0) + _tmp33 * dt;
    _new_Dv(1, 0) = Dv(1, 0) + _tmp40 * dt;
    _new_Dv(2, 0) = Dv(2, 0) + _tmp44 * dt;
  }

  if (new_Dp != nullptr) {
    Eigen::Matrix<Scalar, 3, 1>& _new_Dp = (*new_Dp);

    _new_Dp(0, 0) = Dp(0, 0) + Dv(0, 0) * dt + _tmp33 * _tmp45;
    _new_Dp(1, 0) = Dp(1, 0) + Dv(1, 0) * dt + _tmp40 * _tmp45;
    _new_Dp(2, 0) = Dp(2, 0) + Dv(2, 0) * dt + _tmp44 * _tmp45;
  }

  if (new_covariance != nullptr) {
    Eigen::Matrix<Scalar, 9, 9>& _new_covariance = (*new_covariance);

    _new_covariance(0, 0) =
        _tmp52 *
            (_tmp52 * covariance(2, 2) + _tmp55 * covariance(2, 1) + _tmp58 * covariance(2, 0)) +
        _tmp55 *
            (_tmp52 * covariance(2, 1) + _tmp55 * covariance(1, 1) + _tmp58 * covariance(1, 0)) +
        _tmp58 *
            (_tmp52 * covariance(2, 0) + _tmp55 * covariance(1, 0) + _tmp58 * covariance(0, 0)) +
        std::pow(_tmp66, Scalar(2)) * _tmp67 + std::pow(_tmp71, Scalar(2)) * _tmp72 +
        std::pow(_tmp75, Scalar(2)) * _tmp76;
    _new_covariance(1, 0) = _tmp99;
    _new_covariance(2, 0) = _tmp111;
    _new_covariance(3, 0) = _tmp130;
    _new_covariance(4, 0) = _tmp149;
    _new_covariance(5, 0) = _tmp168;
    _new_covariance(6, 0) = _tmp173;
    _new_covariance(7, 0) = _tmp180;
    _new_covariance(8, 0) = _tmp187;
    _new_covariance(0, 1) = _tmp99;
    _new_covariance(1, 1) =
        _tmp67 * std::pow(_tmp86, Scalar(2)) + _tmp72 * std::pow(_tmp93, Scalar(2)) +
        _tmp76 * std::pow(_tmp97, Scalar(2)) + _tmp77 * _tmp90 + _tmp81 * _tmp89 + _tmp83 * _tmp84;
    _new_covariance(2, 1) = _tmp189;
    _new_covariance(3, 1) = _tmp190;
    _new_covariance(4, 1) = _tmp191;
    _new_covariance(5, 1) = _tmp192;
    _new_covariance(6, 1) = _tmp193;
    _new_covariance(7, 1) = _tmp194;
    _new_covariance(8, 1) = _tmp195;
    _new_covariance(0, 2) = _tmp111;
    _new_covariance(1, 2) = _tmp189;
    _new_covariance(2, 2) = _tmp100 * _tmp108 + _tmp101 * _tmp107 + _tmp102 * _tmp103 +
                            std::pow(_tmp104, Scalar(2)) * _tmp67 +
                            std::pow(_tmp106, Scalar(2)) * _tmp76 +
                            std::pow(_tmp109, Scalar(2)) * _tmp72;
    _new_covariance(3, 2) = _tmp196;
    _new_covariance(4, 2) = _tmp197;
    _new_covariance(5, 2) = _tmp198;
    _new_covariance(6, 2) = _tmp199;
    _new_covariance(7, 2) = _tmp200;
    _new_covariance(8, 2) = _tmp201;
    _new_covariance(0, 3) = _tmp130;
    _new_covariance(1, 3) = _tmp190;
    _new_covariance(2, 3) = _tmp196;
    _new_covariance(3, 3) = _tmp114 * _tmp125 + _tmp117 * _tmp129 + _tmp119 * _tmp121 + _tmp202 +
                            _tmp203 * _tmp204 + _tmp205 * _tmp206 + _tmp207 * _tmp208 + _tmp209 +
                            _tmp210 + covariance(3, 3);
    _new_covariance(4, 3) = _tmp217;
    _new_covariance(5, 3) = _tmp224;
    _new_covariance(6, 3) = _tmp232;
    _new_covariance(7, 3) = _tmp243;
    _new_covariance(8, 3) = _tmp254;
    _new_covariance(0, 4) = _tmp149;
    _new_covariance(1, 4) = _tmp191;
    _new_covariance(2, 4) = _tmp197;
    _new_covariance(3, 4) = _tmp217;
    _new_covariance(4, 4) = _tmp133 * _tmp140 + _tmp136 * _tmp144 + _tmp138 * _tmp148 +
                            _tmp204 * _tmp258 + _tmp206 * _tmp256 + _tmp208 * _tmp257 + _tmp255 +
                            _tmp259 + _tmp260 + covariance(4, 4);
    _new_covariance(5, 4) = _tmp264;
    _new_covariance(6, 4) = _tmp266;
    _new_covariance(7, 4) = _tmp274;
    _new_covariance(8, 4) = _tmp281;
    _new_covariance(0, 5) = _tmp168;
    _new_covariance(1, 5) = _tmp192;
    _new_covariance(2, 5) = _tmp198;
    _new_covariance(3, 5) = _tmp224;
    _new_covariance(4, 5) = _tmp264;
    _new_covariance(5, 5) = _tmp152 * _tmp167 + _tmp155 * _tmp159 + _tmp157 * _tmp163 +
                            _tmp204 * _tmp282 + _tmp206 * _tmp286 + _tmp208 * _tmp285 + _tmp283 +
                            _tmp284 + _tmp287 + covariance(5, 5);
    _new_covariance(6, 5) = _tmp290;
    _new_covariance(7, 5) = _tmp291;
    _new_covariance(8, 5) = _tmp299;
    _new_covariance(0, 6) = _tmp173;
    _new_covariance(1, 6) = _tmp193;
    _new_covariance(2, 6) = _tmp199;
    _new_covariance(3, 6) = _tmp232;
    _new_covariance(4, 6) = _tmp266;
    _new_covariance(5, 6) = _tmp290;
    _new_covariance(6, 6) = _tmp114 * _tmp301 + _tmp117 * _tmp169 * covariance(6, 0) +
                            _tmp119 * _tmp169 * covariance(6, 2) + _tmp169 * _tmp225 +
                            _tmp169 * _tmp226 + _tmp169 * _tmp230 + _tmp227 * _tmp300 +
                            _tmp228 * _tmp300 + _tmp229 * _tmp300 + _tmp231 * dt +
                            covariance(6, 3) * dt + covariance(6, 6);
    _new_covariance(7, 6) = _tmp306;
    _new_covariance(8, 6) = _tmp310;
    _new_covariance(0, 7) = _tmp180;
    _new_covariance(1, 7) = _tmp194;
    _new_covariance(2, 7) = _tmp200;
    _new_covariance(3, 7) = _tmp243;
    _new_covariance(4, 7) = _tmp274;
    _new_covariance(5, 7) = _tmp291;
    _new_covariance(6, 7) = _tmp306;
    _new_covariance(7, 7) = _tmp138 * _tmp169 * covariance(7, 1) + _tmp169 * _tmp268 +
                            _tmp169 * _tmp271 + _tmp169 * _tmp272 + _tmp267 * _tmp300 +
                            _tmp269 * _tmp300 + _tmp270 * _tmp300 + _tmp273 * dt +
                            _tmp302 * covariance(7, 2) + _tmp303 * covariance(7, 0) +
                            covariance(7, 4) * dt + covariance(7, 7);
    _new_covariance(8, 7) = _tmp312;
    _new_covariance(0, 8) = _tmp187;
    _new_covariance(1, 8) = _tmp195;
    _new_covariance(2, 8) = _tmp201;
    _new_covariance(3, 8) = _tmp254;
    _new_covariance(4, 8) = _tmp281;
    _new_covariance(5, 8) = _tmp299;
    _new_covariance(6, 8) = _tmp310;
    _new_covariance(7, 8) = _tmp312;
    _new_covariance(8, 8) = _tmp169 * _tmp295 + _tmp169 * _tmp296 + _tmp169 * _tmp297 +
                            _tmp292 * _tmp300 + _tmp293 * _tmp300 + _tmp294 * _tmp300 +
                            _tmp298 * dt + _tmp307 * covariance(8, 2) + _tmp309 * covariance(8, 0) +
                            _tmp311 * covariance(8, 1) + covariance(8, 5) * dt + covariance(8, 8);
  }

  if (new_DR_D_gyro_bias != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _new_DR_D_gyro_bias = (*new_DR_D_gyro_bias);

    _new_DR_D_gyro_bias(0, 0) = DR_D_gyro_bias(0, 0) * _tmp58 + DR_D_gyro_bias(1, 0) * _tmp55 +
                                DR_D_gyro_bias(2, 0) * _tmp52 - _tmp96;
    _new_DR_D_gyro_bias(1, 0) = DR_D_gyro_bias(0, 0) * _tmp77 + DR_D_gyro_bias(1, 0) * _tmp83 +
                                DR_D_gyro_bias(2, 0) * _tmp81 - _tmp97 * dt;
    _new_DR_D_gyro_bias(2, 0) = DR_D_gyro_bias(0, 0) * _tmp101 + DR_D_gyro_bias(1, 0) * _tmp100 +
                                DR_D_gyro_bias(2, 0) * _tmp102 - _tmp188;
    _new_DR_D_gyro_bias(0, 1) = DR_D_gyro_bias(0, 1) * _tmp58 + DR_D_gyro_bias(1, 1) * _tmp55 +
                                DR_D_gyro_bias(2, 1) * _tmp52 - _tmp66 * dt;
    _new_DR_D_gyro_bias(1, 1) = DR_D_gyro_bias(0, 1) * _tmp77 + DR_D_gyro_bias(1, 1) * _tmp83 +
                                DR_D_gyro_bias(2, 1) * _tmp81 - _tmp87;
    _new_DR_D_gyro_bias(2, 1) = DR_D_gyro_bias(0, 1) * _tmp101 + DR_D_gyro_bias(1, 1) * _tmp100 +
                                DR_D_gyro_bias(2, 1) * _tmp102 - _tmp105;
    _new_DR_D_gyro_bias(0, 2) = DR_D_gyro_bias(0, 2) * _tmp58 + DR_D_gyro_bias(1, 2) * _tmp55 +
                                DR_D_gyro_bias(2, 2) * _tmp52 - _tmp71 * dt;
    _new_DR_D_gyro_bias(1, 2) = DR_D_gyro_bias(0, 2) * _tmp77 + DR_D_gyro_bias(1, 2) * _tmp83 +
                                DR_D_gyro_bias(2, 2) * _tmp81 - _tmp94;
    _new_DR_D_gyro_bias(2, 2) = DR_D_gyro_bias(0, 2) * _tmp101 + DR_D_gyro_bias(1, 2) * _tmp100 +
                                DR_D_gyro_bias(2, 2) * _tmp102 - _tmp110;
  }

  if (new_Dv_D_accel_bias != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _new_Dv_D_accel_bias = (*new_Dv_D_accel_bias);

    _new_Dv_D_accel_bias(0, 0) = Dv_D_accel_bias(0, 0) - _tmp113;
    _new_Dv_D_accel_bias(1, 0) = Dv_D_accel_bias(1, 0) - _tmp131;
    _new_Dv_D_accel_bias(2, 0) = Dv_D_accel_bias(2, 0) - _tmp150;
    _new_Dv_D_accel_bias(0, 1) = Dv_D_accel_bias(0, 1) - _tmp116;
    _new_Dv_D_accel_bias(1, 1) = Dv_D_accel_bias(1, 1) - _tmp132;
    _new_Dv_D_accel_bias(2, 1) = Dv_D_accel_bias(2, 1) - _tmp154;
    _new_Dv_D_accel_bias(0, 2) = Dv_D_accel_bias(0, 2) - _tmp112;
    _new_Dv_D_accel_bias(1, 2) = Dv_D_accel_bias(1, 2) - _tmp135;
    _new_Dv_D_accel_bias(2, 2) = Dv_D_accel_bias(2, 2) - _tmp151;
  }

  if (new_Dv_D_gyro_bias != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _new_Dv_D_gyro_bias = (*new_Dv_D_gyro_bias);

    _new_Dv_D_gyro_bias(0, 0) = Dv_D_gyro_bias(0, 0) + _tmp313 + _tmp314 + _tmp315;
    _new_Dv_D_gyro_bias(1, 0) = Dv_D_gyro_bias(1, 0) + _tmp316 + _tmp317 + _tmp318;
    _new_Dv_D_gyro_bias(2, 0) = Dv_D_gyro_bias(2, 0) + _tmp319 + _tmp320 + _tmp321;
    _new_Dv_D_gyro_bias(0, 1) = Dv_D_gyro_bias(0, 1) + _tmp322 + _tmp323 + _tmp324;
    _new_Dv_D_gyro_bias(1, 1) = Dv_D_gyro_bias(1, 1) + _tmp325 + _tmp326 + _tmp327;
    _new_Dv_D_gyro_bias(2, 1) = Dv_D_gyro_bias(2, 1) + _tmp328 + _tmp329 + _tmp330;
    _new_Dv_D_gyro_bias(0, 2) = Dv_D_gyro_bias(0, 2) + _tmp331 + _tmp332 + _tmp333;
    _new_Dv_D_gyro_bias(1, 2) = Dv_D_gyro_bias(1, 2) + _tmp334 + _tmp335 + _tmp336;
    _new_Dv_D_gyro_bias(2, 2) = Dv_D_gyro_bias(2, 2) + _tmp337 + _tmp338 + _tmp339;
  }

  if (new_Dp_D_accel_bias != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _new_Dp_D_accel_bias = (*new_Dp_D_accel_bias);

    _new_Dp_D_accel_bias(0, 0) = Dp_D_accel_bias(0, 0) + Dv_D_accel_bias(0, 0) * dt - _tmp240;
    _new_Dp_D_accel_bias(1, 0) =
        Dp_D_accel_bias(1, 0) + Dv_D_accel_bias(1, 0) * dt - _tmp36 * _tmp45;
    _new_Dp_D_accel_bias(2, 0) = Dp_D_accel_bias(2, 0) + Dv_D_accel_bias(2, 0) * dt - _tmp249;
    _new_Dp_D_accel_bias(0, 1) = Dp_D_accel_bias(0, 1) + Dv_D_accel_bias(0, 1) * dt - _tmp239;
    _new_Dp_D_accel_bias(1, 1) =
        Dp_D_accel_bias(1, 1) + Dv_D_accel_bias(1, 1) * dt - _tmp35 * _tmp45;
    _new_Dp_D_accel_bias(2, 1) = Dp_D_accel_bias(2, 1) + Dv_D_accel_bias(2, 1) * dt - _tmp252;
    _new_Dp_D_accel_bias(0, 2) = Dp_D_accel_bias(0, 2) + Dv_D_accel_bias(0, 2) * dt - _tmp250;
    _new_Dp_D_accel_bias(1, 2) = Dp_D_accel_bias(1, 2) + Dv_D_accel_bias(1, 2) * dt - _tmp238;
    _new_Dp_D_accel_bias(2, 2) =
        Dp_D_accel_bias(2, 2) + Dv_D_accel_bias(2, 2) * dt - _tmp41 * _tmp45;
  }

  if (new_Dp_D_gyro_bias != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _new_Dp_D_gyro_bias = (*new_Dp_D_gyro_bias);

    _new_Dp_D_gyro_bias(0, 0) = Dp_D_gyro_bias(0, 0) + Dv_D_gyro_bias(0, 0) * dt +
                                _tmp169 * _tmp313 + _tmp169 * _tmp314 + _tmp169 * _tmp315;
    _new_Dp_D_gyro_bias(1, 0) = Dp_D_gyro_bias(1, 0) + Dv_D_gyro_bias(1, 0) * dt +
                                _tmp169 * _tmp316 + _tmp169 * _tmp317 + _tmp169 * _tmp318;
    _new_Dp_D_gyro_bias(2, 0) = Dp_D_gyro_bias(2, 0) + Dv_D_gyro_bias(2, 0) * dt +
                                _tmp169 * _tmp319 + _tmp169 * _tmp320 + _tmp169 * _tmp321;
    _new_Dp_D_gyro_bias(0, 1) = Dp_D_gyro_bias(0, 1) + Dv_D_gyro_bias(0, 1) * dt +
                                _tmp169 * _tmp322 + _tmp169 * _tmp323 + _tmp169 * _tmp324;
    _new_Dp_D_gyro_bias(1, 1) = Dp_D_gyro_bias(1, 1) + Dv_D_gyro_bias(1, 1) * dt +
                                _tmp169 * _tmp325 + _tmp169 * _tmp326 + _tmp169 * _tmp327;
    _new_Dp_D_gyro_bias(2, 1) = Dp_D_gyro_bias(2, 1) + Dv_D_gyro_bias(2, 1) * dt +
                                _tmp169 * _tmp328 + _tmp169 * _tmp329 + _tmp169 * _tmp330;
    _new_Dp_D_gyro_bias(0, 2) = Dp_D_gyro_bias(0, 2) + Dv_D_gyro_bias(0, 2) * dt +
                                _tmp169 * _tmp331 + _tmp169 * _tmp332 + _tmp169 * _tmp333;
    _new_Dp_D_gyro_bias(1, 2) = Dp_D_gyro_bias(1, 2) + Dv_D_gyro_bias(1, 2) * dt +
                                _tmp169 * _tmp334 + _tmp169 * _tmp335 + _tmp169 * _tmp336;
    _new_Dp_D_gyro_bias(2, 2) = Dp_D_gyro_bias(2, 2) + Dv_D_gyro_bias(2, 2) * dt +
                                _tmp169 * _tmp337 + _tmp169 * _tmp338 + _tmp169 * _tmp339;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
