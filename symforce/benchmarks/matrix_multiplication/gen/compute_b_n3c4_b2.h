// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     backends/cpp/templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once


#include <Eigen/Dense>
#include <Eigen/Sparse>



namespace sym {


/**
* This function was autogenerated. Do not modify by hand.
*
* Args:
*     x0: Scalar
*     x1: Scalar
*     x2: Scalar
*     x3: Scalar
*     x4: Scalar
*
* Outputs:
*     result: Matrix20_15
*/
template <typename Scalar>
Eigen::SparseMatrix<Scalar> ComputeBN3C4B2(const Scalar x0, const Scalar x1, const Scalar x2, const Scalar x3, const Scalar x4) {

    // Total ops: 134

    // Input arrays

    // Intermediate terms (19)
    const Scalar _tmp0 = Scalar(1.0) / (x3);
    const Scalar _tmp1 = Scalar(1.0) / (x4);
    const Scalar _tmp2 = std::pow(x1, Scalar(2));
    const Scalar _tmp3 = x0 + x3;
    const Scalar _tmp4 = x4 - 2;
    const Scalar _tmp5 = 2*x4;
    const Scalar _tmp6 = _tmp5 + x0;
    const Scalar _tmp7 = -_tmp5;
    const Scalar _tmp8 = x1 + 1;
    const Scalar _tmp9 = x0*x2;
    const Scalar _tmp10 = 4*x2;
    const Scalar _tmp11 = x0 + x1;
    const Scalar _tmp12 = 2*x2;
    const Scalar _tmp13 = x1*x4;
    const Scalar _tmp14 = -x3;
    const Scalar _tmp15 = -x4;
    const Scalar _tmp16 = 2*x0;
    const Scalar _tmp17 = x2 + x3;
    const Scalar _tmp18 = 2*x1;

    // Output terms (1)
    static constexpr int kRows_result = 20;
    static constexpr int kCols_result = 15;
    static constexpr int kNumNonZero_result = 56;
    static constexpr int kColPtrs_result[] = {0, 4, 8, 12, 16, 20, 23, 27, 30, 34, 37, 40, 44, 48, 52, 56};
    static constexpr int kRowIndices_result[] = {9, 15, 18, 19, 8, 14, 17, 19, 7, 13, 16, 19, 6, 12, 17, 18, 5, 11, 16, 18, 10, 16, 17, 3, 12, 14, 15, 2, 13, 15, 1, 10, 13, 14, 10, 11, 12, 3, 6, 9, 2, 5, 7, 9, 1, 4, 7, 8, 0, 4, 5, 6, 0, 1, 2, 3};
    Scalar result_empty_value_ptr[56];
    Eigen::SparseMatrix<Scalar> result = Eigen::Map<const Eigen::SparseMatrix<Scalar>>(
        kRows_result,
        kCols_result,
        kNumNonZero_result,
        kColPtrs_result,
        kRowIndices_result,
        result_empty_value_ptr
    );
    Scalar* result_value_ptr = result.valuePtr();


    result_value_ptr[0] = -Scalar(1)/Scalar(2)*_tmp0*x4;
    result_value_ptr[1] = -_tmp0*_tmp1*x0;
    result_value_ptr[2] = _tmp2*_tmp3;
    result_value_ptr[3] = -std::pow(x2, Scalar(2))*(x2 - x3/_tmp4);
    result_value_ptr[4] = _tmp6 + 4;
    result_value_ptr[5] = x3*(_tmp7 + _tmp8);
    result_value_ptr[6] = -Scalar(1)/Scalar(2)*_tmp1*_tmp9;
    result_value_ptr[7] = 3 - x4;
    result_value_ptr[8] = _tmp10;
    result_value_ptr[9] = (4*x0 + x3)/x2;
    result_value_ptr[10] = -x0*(2*std::pow(x3, Scalar(2)) + 4);
    result_value_ptr[11] = -x4*(_tmp5 + 2);
    result_value_ptr[12] = _tmp11*x4;
    result_value_ptr[13] = x1 + 4;
    result_value_ptr[14] = _tmp12 - x1 + 4;
    result_value_ptr[15] = _tmp6 + 1;
    result_value_ptr[16] = -_tmp13;
    result_value_ptr[17] = _tmp12*x1;
    result_value_ptr[18] = _tmp3 - x2*x4;
    result_value_ptr[19] = -x0*(x0 + 2);
    result_value_ptr[20] = -_tmp4;
    result_value_ptr[21] = -_tmp12 - _tmp14 - x4;
    result_value_ptr[22] = _tmp3 + x1 - 1;
    result_value_ptr[23] = -x3*(_tmp15 + x0) - 2;
    result_value_ptr[24] = _tmp16 + std::pow(x4, Scalar(2));
    result_value_ptr[25] = -x0*(x0 - 2) - x4;
    result_value_ptr[26] = -_tmp8*x3;
    result_value_ptr[27] = -x0*x1*(x2 + x4);
    result_value_ptr[28] = (Scalar(1)/Scalar(4))*x1 + x3;
    result_value_ptr[29] = 2*_tmp0/x1;
    result_value_ptr[30] = -x2*(_tmp14 + x1*x2) + 2;
    result_value_ptr[31] = -_tmp12 - 2;
    result_value_ptr[32] = Scalar(2.0);
    result_value_ptr[33] = -x3*(x2 + Scalar(1.0) / (x0));
    result_value_ptr[34] = -x2;
    result_value_ptr[35] = _tmp17*(x1 - 2);
    result_value_ptr[36] = -_tmp14 - x0 - 3;
    result_value_ptr[37] = -x0*x3*x4*(_tmp15 + x1);
    result_value_ptr[38] = _tmp13*(x2 - 2);
    result_value_ptr[39] = _tmp11 + _tmp15;
    result_value_ptr[40] = 1 - x4;
    result_value_ptr[41] = _tmp0*(_tmp12 - _tmp16 + _tmp5);
    result_value_ptr[42] = -_tmp5*x0;
    result_value_ptr[43] = Scalar(2.0)*x3 + Scalar(-4.0);
    result_value_ptr[44] = 2*_tmp2*(x4 + 1);
    result_value_ptr[45] = _tmp7;
    result_value_ptr[46] = _tmp5 + 8;
    result_value_ptr[47] = _tmp4 + x2;
    result_value_ptr[48] = 5 - x1;
    result_value_ptr[49] = _tmp10 - x0 + 4;
    result_value_ptr[50] = _tmp18;
    result_value_ptr[51] = _tmp18 + 1;
    result_value_ptr[52] = x3 - 1;
    result_value_ptr[53] = -_tmp13*[&]() { const Scalar base = x3; return base * base * base; }();
    result_value_ptr[54] = x1;
    result_value_ptr[55] = _tmp17 + _tmp9 - 2;

    return result;
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
