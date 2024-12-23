// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.cu.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

namespace sym {

__host__ __device__ void BackendTestFunctionFloat32(
    const float x, const float y, float* const __restrict__ res0, float* const __restrict__ res1,
    float* const __restrict__ res2, float* const __restrict__ res3, float* const __restrict__ res4,
    float* const __restrict__ res5, float* const __restrict__ res6, float* const __restrict__ res7,
    float* const __restrict__ res8, float* const __restrict__ res9, float* const __restrict__ res10,
    float* const __restrict__ res11, float* const __restrict__ res12,
    float* const __restrict__ res13, float* const __restrict__ res14,
    float* const __restrict__ res15, float* const __restrict__ res16,
    float* const __restrict__ res17, float* const __restrict__ res18,
    float* const __restrict__ res19, float* const __restrict__ res20,
    float* const __restrict__ res21, float* const __restrict__ res22,
    float* const __restrict__ res23, float* const __restrict__ res24,
    float* const __restrict__ res25, float* const __restrict__ res26,
    float* const __restrict__ res27, float* const __restrict__ res28,
    float* const __restrict__ res29, float* const __restrict__ res30,
    float* const __restrict__ res31, float* const __restrict__ res32,
    float* const __restrict__ res33, float* const __restrict__ res34,
    float* const __restrict__ res35, float* const __restrict__ res36,
    float* const __restrict__ res37, float* const __restrict__ res38,
    float* const __restrict__ res39, float* const __restrict__ res40,
    float* const __restrict__ res41, float* const __restrict__ res42,
    float* const __restrict__ res43, float* const __restrict__ res44,
    float* const __restrict__ res45, float* const __restrict__ res46,
    float* const __restrict__ res47, float* const __restrict__ res48,
    float* const __restrict__ res49, float* const __restrict__ res50,
    float* const __restrict__ res51, float* const __restrict__ res52,
    float* const __restrict__ res53, float* const __restrict__ res54,
    float* const __restrict__ res55, float* const __restrict__ res56,
    float* const __restrict__ res57) {
  // Total ops: 53

  // Intermediate terms (5)
  const float _tmp0 = M_LN2;
  const float _tmp1 = M_1_PI;
  const float _tmp2 = M_SQRT2;
  const float _tmp3 = sqrtf(x);
  const float _tmp4 = x + y;

  // Output terms (58)
  if (res0 != nullptr) {
    *res0 = 0;
  }

  if (res1 != nullptr) {
    *res1 = 1;
  }

  if (res2 != nullptr) {
    *res2 = 1.0F / 2.0F;
  }

  if (res3 != nullptr) {
    *res3 = 1.6F;
  }

  if (res4 != nullptr) {
    *res4 = 11.0F / 52.0F;
  }

  if (res5 != nullptr) {
    *res5 = M_E;
  }

  if (res6 != nullptr) {
    *res6 = 1.0F / _tmp0;
  }

  if (res7 != nullptr) {
    *res7 = _tmp0;
  }

  if (res8 != nullptr) {
    *res8 = M_LN10;
  }

  if (res9 != nullptr) {
    *res9 = M_PI;
  }

  if (res10 != nullptr) {
    *res10 = M_PI_2;
  }

  if (res11 != nullptr) {
    *res11 = M_PI_4;
  }

  if (res12 != nullptr) {
    *res12 = _tmp1;
  }

  if (res13 != nullptr) {
    *res13 = 2 * _tmp1;
  }

  if (res14 != nullptr) {
    *res14 = M_2_SQRTPI;
  }

  if (res15 != nullptr) {
    *res15 = _tmp2;
  }

  if (res16 != nullptr) {
    *res16 = (1.0F / 2.0F) * _tmp2;
  }

  if (res17 != nullptr) {
    *res17 = fabsf(x);
  }

  if (res18 != nullptr) {
    *res18 = sinf(x);
  }

  if (res19 != nullptr) {
    *res19 = cosf(x);
  }

  if (res20 != nullptr) {
    *res20 = tanf(x);
  }

  if (res21 != nullptr) {
    *res21 = asinf(x);
  }

  if (res22 != nullptr) {
    *res22 = acosf(x);
  }

  if (res23 != nullptr) {
    *res23 = atanf(x);
  }

  if (res24 != nullptr) {
    *res24 = expf(x);
  }

  if (res25 != nullptr) {
    *res25 = logf(x);
  }

  if (res26 != nullptr) {
    *res26 = sinhf(x);
  }

  if (res27 != nullptr) {
    *res27 = coshf(x);
  }

  if (res28 != nullptr) {
    *res28 = tanhf(x);
  }

  if (res29 != nullptr) {
    *res29 = floorf(x);
  }

  if (res30 != nullptr) {
    *res30 = ceilf(x);
  }

  if (res31 != nullptr) {
    *res31 = _tmp3;
  }

  if (res32 != nullptr) {
    *res32 = asinhf(x);
  }

  if (res33 != nullptr) {
    *res33 = acoshf(x);
  }

  if (res34 != nullptr) {
    *res34 = atanhf(x);
  }

  if (res35 != nullptr) {
    *res35 = fmodf(1.0F * x, 5.5F);
  }

  if (res36 != nullptr) {
    *res36 = x + 1;
  }

  if (res37 != nullptr) {
    *res37 = 2 * x;
  }

  if (res38 != nullptr) {
    *res38 = powf(x, 2);
  }

  if (res39 != nullptr) {
    *res39 = powf(x, 3);
  }

  if (res40 != nullptr) {
    *res40 = powf(x, 4);
  }

  if (res41 != nullptr) {
    *res41 = powf(x, 5);
  }

  if (res42 != nullptr) {
    *res42 = _tmp3;
  }

  if (res43 != nullptr) {
    *res43 = powf(x, 3.0F / 2.0F);
  }

  if (res44 != nullptr) {
    *res44 = 0.5F * ((((x) >= 0) - ((x) < 0)) + 1);
  }

  if (res45 != nullptr) {
    *res45 = erfcf(x);
  }

  if (res46 != nullptr) {
    *res46 = lgammaf(x);
  }

  if (res47 != nullptr) {
    *res47 = erff(x);
  }

  if (res48 != nullptr) {
    *res48 = tgammaf(x);
  }

  if (res49 != nullptr) {
    *res49 = atan2f(x, y);
  }

  if (res50 != nullptr) {
    *res50 = fmaxf(x, y);
  }

  if (res51 != nullptr) {
    *res51 = fminf(x, y);
  }

  if (res52 != nullptr) {
    *res52 = fmodf(x, y);
  }

  if (res53 != nullptr) {
    *res53 = _tmp4;
  }

  if (res54 != nullptr) {
    *res54 = x * y;
  }

  if (res55 != nullptr) {
    *res55 = powf(x, y);
  }

  if (res56 != nullptr) {
    *res56 = powf(_tmp4, 2);
  }

  if (res57 != nullptr) {
    *res57 = powf(_tmp4, 3);
  }
}

}  // namespace sym
