//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PIROSNav.cpp
//
// Code generated for Simulink model 'PIROSNav'.
//
// Model version                  : 1.62
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Fri Feb  7 11:21:02 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "PIROSNav.h"
#include "PIROSNav_private.h"
#include "PIROSNav_dt.h"

// Block signals (default storage)
B_PIROSNav_T PIROSNav_B;

// Block states (default storage)
DW_PIROSNav_T PIROSNav_DW;

// Real-time model
RT_MODEL_PIROSNav_T PIROSNav_M_ = RT_MODEL_PIROSNav_T();
RT_MODEL_PIROSNav_T *const PIROSNav_M = &PIROSNav_M_;

// Forward declaration for local functions
static void PIROSNav_NED_ecompass(const real_T a[3], const real_T m[3], real_T
  R[9]);
static void PIROS_quaternioncg_quaternioncg(const real_T varargin_1[9], real_T
  *obj_a, real_T *obj_b, real_T *obj_c, real_T *obj_d);
static void PIR_quaternioncg_quaternioncg_g(const real_T varargin_1[3], real_T
  *obj_a, real_T *obj_b, real_T *obj_c, real_T *obj_d);
static void PIROSNav_quaternionBase_mtimes(real_T x_a, real_T x_b, real_T x_c,
  real_T x_d, real_T y_a, real_T y_b, real_T y_c, real_T y_d, real_T *o_a,
  real_T *o_b, real_T *o_c, real_T *o_d);
static void IMUFusionCommon_predictOrientat(const
  c_fusion_internal_coder_ahrsf_T *obj, const real_T gfast[3], const real_T
  offset[3], c_matlabshared_rotations_inte_T *qorient);
static void PIROSNav_quaternionBase_rotmat(real_T q_a, real_T q_b, real_T q_c,
  real_T q_d, real_T r[9]);
static void PIRO_IMUFusionCommon_buildHPart(const real_T v[3], real_T h[9]);
static real_T PIROSNav_norm(const real_T x[3]);
static void PIROSNav_quaternionBase_conj(c_matlabshared_rotations_inte_T *q);
static void PIROSNav_quaternionBase_uminus(c_matlabshared_rotations_inte_T *obj);
static void PIROSN_quaternionBase_normalize(c_matlabshared_rotations_inte_T *q);
static void PIROSN_quaternioncg_parenAssign(real_T rhs_a, real_T rhs_b, real_T
  rhs_c, real_T rhs_d, real_T *o_a, real_T *o_b, real_T *o_c, real_T *o_d);
static void PIROSNa_AHRSFilterBase_stepImpl(c_fusion_internal_coder_ahrsf_T *obj,
  const real_T accelIn[3], const real_T gyroIn[3], const real_T magIn[3], real_T
  *orientOut_a, real_T *orientOut_b, real_T *orientOut_c, real_T *orientOut_d);
static void matlabCodegenHandle_matla_imdcl(ros_slros_internal_block_Subs_T *obj);
static void PIROSN_SystemCore_release_imdcl(const
  codertarget_raspi_internal_SP_T *obj);
static void PIROS_SystemCore_delete_imdcl2f(const
  codertarget_raspi_internal_SP_T *obj);
static void matlabCodegenHandle_mat_imdcl2f(codertarget_raspi_internal_SP_T *obj);
static void PIROSNav_SystemCore_release_im(const raspi_internal_lsm9ds1Block_P_T
  *obj);
static void PIROSNav_SystemCore_delete_im(const raspi_internal_lsm9ds1Block_P_T *
  obj);
static void matlabCodegenHandle_matlabCo_im(raspi_internal_lsm9ds1Block_P_T *obj);
static void PIROSNa_SystemCore_release_imdc(g_codertarget_raspi_internal__T *obj);
static void PIROSNav_SystemCore_delete_imdc(g_codertarget_raspi_internal__T *obj);
static void matlabCodegenHandle_matlab_imdc(g_codertarget_raspi_internal__T *obj);
static void PIROSNav_SystemCore_release_imd(f_codertarget_raspi_internal__T *obj);
static void PIROSNav_SystemCore_delete_imd(f_codertarget_raspi_internal__T *obj);
static void matlabCodegenHandle_matlabC_imd(f_codertarget_raspi_internal__T *obj);
static void PIROSNav_SystemCore_release_i(const raspi_internal_lps25hBlock_PI_T *
  obj);
static void PIROSNav_SystemCore_delete_i(const raspi_internal_lps25hBlock_PI_T
  *obj);
static void matlabCodegenHandle_matlabCod_i(raspi_internal_lps25hBlock_PI_T *obj);
static void PIROSNav_SystemCore_release(const raspi_internal_hts221Block_PI_T
  *obj);
static void PIROSNav_SystemCore_delete(const raspi_internal_hts221Block_PI_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(raspi_internal_hts221Block_PI_T *obj);
static raspi_internal_lsm9ds1Block_P_T *PIROS_lsm9ds1Block_lsm9ds1Block
  (raspi_internal_lsm9ds1Block_P_T *obj);
static void PIROSNav_lsm9ds1Block_setupImpl(raspi_internal_lsm9ds1Block_P_T *obj);
static void PIROSNav_SystemCore_setup_i(raspi_internal_lps25hBlock_PI_T *obj);
static void PIROSNav_SystemCore_setup(raspi_internal_hts221Block_PI_T *obj);
static void rate_monotonic_scheduler(void);
real32_T look1_tf_binlcpw(real_T u0, const real_T bp0[], const real32_T table[],
  uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  // Column-major Lookup 1-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear point-slope'
  // Extrapolation method: 'Clip'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Clip'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    // Binary Search
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0;
  }

  // Column-major Interpolation 1-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'portable wrapping'

  return static_cast<real32_T>(((table[iLeft + 1U] - table[iLeft]) * frac)) +
    table[iLeft];
}

real32_T look1_iflf_binlxpw(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T maxIndex)
{
  real32_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  // Column-major Lookup 1-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear point-slope'
  // Extrapolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Linear'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    // Binary Search
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  // Column-major Interpolation 1-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'portable wrapping'

  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

real_T uMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real_T y;
  int32_T i;
  int32_T exp_0;
  y = 0.0;
  exp_0 = e1;
  for (i = 0; i < n1; i++) {
    y += ldexp(static_cast<real_T>(u1[i]), exp_0);
    exp_0 += 32;
  }

  return y;
}

void uMultiWordShl(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T nb;
  int32_T nc;
  int32_T i;
  uint32_T ys;
  uint32_T u1i;
  uint32_T yi;
  uint32_T nr;
  uint32_T nl;
  nb = static_cast<int32_T>((n2 >> 5));
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
  nc = nb > n ? n : nb;
  u1i = 0U;
  for (i = 0; i < nc; i++) {
    y[i] = 0U;
  }

  if (nb < n) {
    nl = n2 - (static_cast<uint32_T>(nb) << 5);
    nb += n1;
    if (nb > n) {
      nb = n;
    }

    nb -= i;
    if (nl > 0U) {
      nr = 32U - nl;
      for (nc = 0; nc < nb; nc++) {
        yi = u1i >> nr;
        u1i = u1[nc];
        y[i] = u1i << nl | yi;
        i++;
      }

      if (i < n) {
        y[i] = u1i >> nr | ys << nl;
        i++;
      }
    } else {
      for (nc = 0; nc < nb; nc++) {
        y[i] = u1[nc];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void uLong2MultiWord(uint32_T u, uint32_T y[], int32_T n)
{
  int32_T i;
  y[0] = u;
  for (i = 1; i < n; i++) {
    y[i] = 0U;
  }
}

void Double2MultiWord(real_T u1, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T currExp;
  int32_T prevExp;
  int32_T msl;
  real_T yn;
  real_T yd;
  boolean_T isNegative;
  uint32_T u1i;
  uint32_T cb;
  isNegative = (u1 < 0.0);
  yn = frexp(u1, &currExp);
  msl = currExp <= 0 ? -1 : div_s32(currExp - 1, 32);
  cb = 1U;
  for (i = msl + 1; i < n; i++) {
    y[i] = 0U;
  }

  yn = isNegative ? -yn : yn;
  prevExp = 32 * msl;
  for (i = msl; i >= 0; i--) {
    yn = ldexp(yn, currExp - prevExp);
    yd = floor(yn);
    yn -= yd;
    if (i < n) {
      y[i] = static_cast<uint32_T>(yd);
    }

    currExp = prevExp;
    prevExp -= 32;
  }

  if (isNegative) {
    for (i = 0; i < n; i++) {
      u1i = ~y[i];
      cb += u1i;
      y[i] = cb;
      cb = (cb < u1i);
    }
  }
}

void MultiWordIor(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int32_T n)
{
  int32_T i;
  for (i = 0; i < n; i++) {
    y[i] = u1[i] | u2[i];
  }
}

int32_T div_s32(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T tempAbsQuotient;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    // Divide by zero handler
  } else {
    tempAbsQuotient = (numerator < 0 ? ~static_cast<uint32_T>(numerator) + 1U :
                       static_cast<uint32_T>(numerator)) / (denominator < 0 ? ~
      static_cast<uint32_T>(denominator) + 1U : static_cast<uint32_T>
      (denominator));
    quotient = (numerator < 0) != (denominator < 0) ? -static_cast<int32_T>
      (tempAbsQuotient) : static_cast<int32_T>(tempAbsQuotient);
  }

  return quotient;
}

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to "remember" which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void PIROSNav_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(PIROSNav_M, 1));
}

//
//   This function updates active task flag for each subrate
// and rate transition flags for tasks that exchange data.
// The function assumes rate-monotonic multitasking scheduler.
// The function must be called at model base rate so that
// the generated code self-manages all its subrates and rate
// transition flags.
//
static void rate_monotonic_scheduler(void)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (PIROSNav_M->Timing.TaskCounters.TID[1])++;
  if ((PIROSNav_M->Timing.TaskCounters.TID[1]) > 9) {// Sample time: [1.0s, 0.0s] 
    PIROSNav_M->Timing.TaskCounters.TID[1] = 0;
  }
}

//
// Output and update for atomic system:
//    '<S6>/MATLAB Function1'
//    '<S6>/MATLAB Function2'
//
void PIROSNav_MATLABFunction1(const real_T rtu_a[3], real_T *rty_out)
{
  *rty_out = (rtu_a[0] * rtu_a[0] + rtu_a[1] * rtu_a[1]) + rtu_a[2] * rtu_a[2];
  *rty_out = sqrt(*rty_out);
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if (static_cast<real32_T>(fabs(static_cast<real_T>(u))) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = static_cast<real32_T>(floor(static_cast<real_T>((u + 0.5F))));
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = static_cast<real32_T>(ceil(static_cast<real_T>((u - 0.5F))));
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void PIROSNav_NED_ecompass(const real_T a[3], const real_T m[3], real_T
  R[9])
{
  boolean_T nanPageIdx;
  boolean_T y[3];
  int32_T xpageoffset;
  int32_T b_i;
  boolean_T exitg1;
  PIROSNav_B.Reast[0] = a[1] * m[2] - a[2] * m[1];
  PIROSNav_B.Reast[1] = a[2] * m[0] - a[0] * m[2];
  PIROSNav_B.Reast[2] = a[0] * m[1] - a[1] * m[0];
  R[6] = a[0];
  R[3] = PIROSNav_B.Reast[0];
  R[7] = a[1];
  R[4] = PIROSNav_B.Reast[1];
  R[8] = a[2];
  R[5] = PIROSNav_B.Reast[2];
  R[0] = PIROSNav_B.Reast[1] * a[2] - PIROSNav_B.Reast[2] * a[1];
  R[1] = PIROSNav_B.Reast[2] * a[0] - PIROSNav_B.Reast[0] * a[2];
  R[2] = PIROSNav_B.Reast[0] * a[1] - PIROSNav_B.Reast[1] * a[0];
  for (b_i = 0; b_i < 9; b_i++) {
    PIROSNav_B.x[b_i] = R[b_i] * R[b_i];
  }

  for (b_i = 0; b_i < 3; b_i++) {
    xpageoffset = b_i * 3;
    PIROSNav_B.Reast[b_i] = PIROSNav_B.x[xpageoffset + 2] +
      (PIROSNav_B.x[xpageoffset + 1] + PIROSNav_B.x[xpageoffset]);
  }

  PIROSNav_B.Reast[0] = sqrt(PIROSNav_B.Reast[0]);
  PIROSNav_B.Reast[1] = sqrt(PIROSNav_B.Reast[1]);
  PIROSNav_B.Reast[2] = sqrt(PIROSNav_B.Reast[2]);
  memcpy(&PIROSNav_B.x[0], &R[0], 9U * sizeof(real_T));
  for (b_i = 0; b_i < 3; b_i++) {
    R[3 * b_i] = PIROSNav_B.x[3 * b_i] / PIROSNav_B.Reast[b_i];
    xpageoffset = 3 * b_i + 1;
    R[xpageoffset] = PIROSNav_B.x[xpageoffset] / PIROSNav_B.Reast[b_i];
    xpageoffset = 3 * b_i + 2;
    R[xpageoffset] = PIROSNav_B.x[xpageoffset] / PIROSNav_B.Reast[b_i];
  }

  for (b_i = 0; b_i < 9; b_i++) {
    PIROSNav_B.b_p[b_i] = rtIsNaN(R[b_i]);
  }

  y[0] = false;
  y[1] = false;
  y[2] = false;
  b_i = 1;
  exitg1 = false;
  while ((!exitg1) && (b_i <= 3)) {
    if (PIROSNav_B.b_p[b_i - 1]) {
      y[0] = true;
      exitg1 = true;
    } else {
      b_i++;
    }
  }

  b_i = 4;
  exitg1 = false;
  while ((!exitg1) && (b_i <= 6)) {
    if (PIROSNav_B.b_p[b_i - 1]) {
      y[1] = true;
      exitg1 = true;
    } else {
      b_i++;
    }
  }

  b_i = 7;
  exitg1 = false;
  while ((!exitg1) && (b_i <= 9)) {
    if (PIROSNav_B.b_p[b_i - 1]) {
      y[2] = true;
      exitg1 = true;
    } else {
      b_i++;
    }
  }

  nanPageIdx = false;
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i < 3)) {
    if (!y[b_i]) {
      b_i++;
    } else {
      nanPageIdx = true;
      exitg1 = true;
    }
  }

  if (nanPageIdx) {
    memset(&R[0], 0, 9U * sizeof(real_T));
    R[0] = 1.0;
    R[4] = 1.0;
    R[8] = 1.0;
  }
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void PIROS_quaternioncg_quaternioncg(const real_T varargin_1[9], real_T
  *obj_a, real_T *obj_b, real_T *obj_c, real_T *obj_d)
{
  int32_T idx;
  int32_T d_k;
  boolean_T exitg1;
  PIROSNav_B.pd = (varargin_1[0] + varargin_1[4]) + varargin_1[8];
  PIROSNav_B.psquared[0] = (PIROSNav_B.pd * 2.0 + 1.0) - PIROSNav_B.pd;
  PIROSNav_B.psquared[1] = (2.0 * varargin_1[0] + 1.0) - PIROSNav_B.pd;
  PIROSNav_B.psquared[2] = (2.0 * varargin_1[4] + 1.0) - PIROSNav_B.pd;
  PIROSNav_B.psquared[3] = (2.0 * varargin_1[8] + 1.0) - PIROSNav_B.pd;
  if (!rtIsNaN(PIROSNav_B.psquared[0])) {
    idx = 1;
  } else {
    idx = 0;
    d_k = 2;
    exitg1 = false;
    while ((!exitg1) && (d_k < 5)) {
      if (!rtIsNaN(PIROSNav_B.psquared[d_k - 1])) {
        idx = d_k;
        exitg1 = true;
      } else {
        d_k++;
      }
    }
  }

  if (idx == 0) {
    PIROSNav_B.pd = PIROSNav_B.psquared[0];
    idx = 1;
  } else {
    PIROSNav_B.pd = PIROSNav_B.psquared[idx - 1];
    for (d_k = idx; d_k + 1 < 5; d_k++) {
      if (PIROSNav_B.pd < PIROSNav_B.psquared[d_k]) {
        PIROSNav_B.pd = PIROSNav_B.psquared[d_k];
        idx = d_k + 1;
      }
    }
  }

  switch (idx) {
   case 1:
    PIROSNav_B.pd = sqrt(PIROSNav_B.pd);
    *obj_a = 0.5 * PIROSNav_B.pd;
    PIROSNav_B.pd = 0.5 / PIROSNav_B.pd;
    *obj_b = (varargin_1[7] - varargin_1[5]) * PIROSNav_B.pd;
    *obj_c = (varargin_1[2] - varargin_1[6]) * PIROSNav_B.pd;
    *obj_d = (varargin_1[3] - varargin_1[1]) * PIROSNav_B.pd;
    break;

   case 2:
    PIROSNav_B.pd = sqrt(PIROSNav_B.pd);
    *obj_b = 0.5 * PIROSNav_B.pd;
    PIROSNav_B.pd = 0.5 / PIROSNav_B.pd;
    *obj_a = (varargin_1[7] - varargin_1[5]) * PIROSNav_B.pd;
    *obj_c = (varargin_1[3] + varargin_1[1]) * PIROSNav_B.pd;
    *obj_d = (varargin_1[2] + varargin_1[6]) * PIROSNav_B.pd;
    break;

   case 3:
    PIROSNav_B.pd = sqrt(PIROSNav_B.pd);
    *obj_c = 0.5 * PIROSNav_B.pd;
    PIROSNav_B.pd = 0.5 / PIROSNav_B.pd;
    *obj_a = (varargin_1[2] - varargin_1[6]) * PIROSNav_B.pd;
    *obj_b = (varargin_1[3] + varargin_1[1]) * PIROSNav_B.pd;
    *obj_d = (varargin_1[7] + varargin_1[5]) * PIROSNav_B.pd;
    break;

   default:
    PIROSNav_B.pd = sqrt(PIROSNav_B.pd);
    *obj_d = 0.5 * PIROSNav_B.pd;
    PIROSNav_B.pd = 0.5 / PIROSNav_B.pd;
    *obj_a = (varargin_1[3] - varargin_1[1]) * PIROSNav_B.pd;
    *obj_b = (varargin_1[2] + varargin_1[6]) * PIROSNav_B.pd;
    *obj_c = (varargin_1[7] + varargin_1[5]) * PIROSNav_B.pd;
    break;
  }

  if (*obj_a < 0.0) {
    *obj_a = -*obj_a;
    *obj_b = -*obj_b;
    *obj_c = -*obj_c;
    *obj_d = -*obj_d;
  }
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void PIR_quaternioncg_quaternioncg_g(const real_T varargin_1[3], real_T
  *obj_a, real_T *obj_b, real_T *obj_c, real_T *obj_d)
{
  real_T st;
  *obj_a = 1.0;
  *obj_b = 0.0;
  *obj_c = 0.0;
  *obj_d = 0.0;
  PIROSNav_B.theta = sqrt((varargin_1[0] * varargin_1[0] + varargin_1[1] *
    varargin_1[1]) + varargin_1[2] * varargin_1[2]);
  st = sin(PIROSNav_B.theta / 2.0);
  if (PIROSNav_B.theta != 0.0) {
    *obj_a = cos(PIROSNav_B.theta / 2.0);
    *obj_b = varargin_1[0] / PIROSNav_B.theta * st;
    *obj_c = varargin_1[1] / PIROSNav_B.theta * st;
    *obj_d = varargin_1[2] / PIROSNav_B.theta * st;
  }
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void PIROSNav_quaternionBase_mtimes(real_T x_a, real_T x_b, real_T x_c,
  real_T x_d, real_T y_a, real_T y_b, real_T y_c, real_T y_d, real_T *o_a,
  real_T *o_b, real_T *o_c, real_T *o_d)
{
  *o_a = ((x_a * y_a - x_b * y_b) - x_c * y_c) - x_d * y_d;
  *o_b = ((x_a * y_b + x_b * y_a) + x_c * y_d) - x_d * y_c;
  *o_c = ((x_a * y_c - x_b * y_d) + x_c * y_a) + x_d * y_b;
  *o_d = ((x_a * y_d + x_b * y_c) - x_c * y_b) + x_d * y_a;
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void IMUFusionCommon_predictOrientat(const
  c_fusion_internal_coder_ahrsf_T *obj, const real_T gfast[3], const real_T
  offset[3], c_matlabshared_rotations_inte_T *qorient)
{
  PIROSNav_B.deltaAng[0] = (gfast[0] - offset[0]) * obj->pSensorPeriod;
  PIROSNav_B.deltaAng[1] = (gfast[1] - offset[1]) * obj->pSensorPeriod;
  PIROSNav_B.deltaAng[2] = (gfast[2] - offset[2]) * obj->pSensorPeriod;
  PIR_quaternioncg_quaternioncg_g(PIROSNav_B.deltaAng, &PIROSNav_B.assign_temp_a,
    &PIROSNav_B.assign_temp_b, &PIROSNav_B.assign_temp_c,
    &PIROSNav_B.assign_temp_d);
  PIROSNav_quaternionBase_mtimes(qorient->a, qorient->b, qorient->c, qorient->d,
    PIROSNav_B.assign_temp_a, PIROSNav_B.assign_temp_b, PIROSNav_B.assign_temp_c,
    PIROSNav_B.assign_temp_d, &qorient->a, &qorient->b, &qorient->c, &qorient->d);
  if (qorient->a < 0.0) {
    qorient->a = -qorient->a;
    qorient->b = -qorient->b;
    qorient->c = -qorient->c;
    qorient->d = -qorient->d;
  }
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void PIROSNav_quaternionBase_rotmat(real_T q_a, real_T q_b, real_T q_c,
  real_T q_d, real_T r[9])
{
  real_T n;
  n = sqrt(((q_a * q_a + q_b * q_b) + q_c * q_c) + q_d * q_d);
  q_a /= n;
  q_b /= n;
  q_c /= n;
  q_d /= n;
  n = q_a * q_b * 2.0;
  PIROSNav_B.ac2 = q_a * q_c * 2.0;
  PIROSNav_B.ad2 = q_a * q_d * 2.0;
  PIROSNav_B.bc2 = q_b * q_c * 2.0;
  PIROSNav_B.bd2 = q_b * q_d * 2.0;
  PIROSNav_B.cd2 = q_c * q_d * 2.0;
  PIROSNav_B.aasq = q_a * q_a * 2.0 - 1.0;
  r[0] = q_b * q_b * 2.0 + PIROSNav_B.aasq;
  r[3] = PIROSNav_B.bc2 + PIROSNav_B.ad2;
  r[6] = PIROSNav_B.bd2 - PIROSNav_B.ac2;
  r[1] = PIROSNav_B.bc2 - PIROSNav_B.ad2;
  r[4] = q_c * q_c * 2.0 + PIROSNav_B.aasq;
  r[7] = PIROSNav_B.cd2 + n;
  r[2] = PIROSNav_B.bd2 + PIROSNav_B.ac2;
  r[5] = PIROSNav_B.cd2 - n;
  r[8] = q_d * q_d * 2.0 + PIROSNav_B.aasq;
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void PIRO_IMUFusionCommon_buildHPart(const real_T v[3], real_T h[9])
{
  int32_T i;
  int32_T h_tmp;
  memset(&h[0], 0, 9U * sizeof(real_T));
  h[3] = v[2];
  h[6] = -v[1];
  h[7] = v[0];
  for (i = 0; i < 3; i++) {
    PIROSNav_B.h[3 * i] = h[3 * i];
    h_tmp = 3 * i + 1;
    PIROSNav_B.h[h_tmp] = h[h_tmp] - h[i + 3];
    h_tmp = 3 * i + 2;
    PIROSNav_B.h[h_tmp] = h[h_tmp] - h[i + 6];
  }

  memcpy(&h[0], &PIROSNav_B.h[0], 9U * sizeof(real_T));
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static real_T PIROSNav_norm(const real_T x[3])
{
  real_T y;
  real_T t;
  PIROSNav_B.scale = 3.3121686421112381E-170;
  PIROSNav_B.absxk = fabs(x[0]);
  if (PIROSNav_B.absxk > 3.3121686421112381E-170) {
    y = 1.0;
    PIROSNav_B.scale = PIROSNav_B.absxk;
  } else {
    t = PIROSNav_B.absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  PIROSNav_B.absxk = fabs(x[1]);
  if (PIROSNav_B.absxk > PIROSNav_B.scale) {
    t = PIROSNav_B.scale / PIROSNav_B.absxk;
    y = y * t * t + 1.0;
    PIROSNav_B.scale = PIROSNav_B.absxk;
  } else {
    t = PIROSNav_B.absxk / PIROSNav_B.scale;
    y += t * t;
  }

  PIROSNav_B.absxk = fabs(x[2]);
  if (PIROSNav_B.absxk > PIROSNav_B.scale) {
    t = PIROSNav_B.scale / PIROSNav_B.absxk;
    y = y * t * t + 1.0;
    PIROSNav_B.scale = PIROSNav_B.absxk;
  } else {
    t = PIROSNav_B.absxk / PIROSNav_B.scale;
    y += t * t;
  }

  return PIROSNav_B.scale * sqrt(y);
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void PIROSNav_quaternionBase_conj(c_matlabshared_rotations_inte_T *q)
{
  q->b = -q->b;
  q->c = -q->c;
  q->d = -q->d;
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void PIROSNav_quaternionBase_uminus(c_matlabshared_rotations_inte_T *obj)
{
  obj->a = -obj->a;
  obj->b = -obj->b;
  obj->c = -obj->c;
  obj->d = -obj->d;
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void PIROSN_quaternionBase_normalize(c_matlabshared_rotations_inte_T *q)
{
  real_T n;
  n = sqrt(((q->a * q->a + q->b * q->b) + q->c * q->c) + q->d * q->d);
  q->a /= n;
  q->b /= n;
  q->c /= n;
  q->d /= n;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void PIROSN_quaternioncg_parenAssign(real_T rhs_a, real_T rhs_b, real_T
  rhs_c, real_T rhs_d, real_T *o_a, real_T *o_b, real_T *o_c, real_T *o_d)
{
  *o_a = rhs_a;
  *o_b = rhs_b;
  *o_c = rhs_c;
  *o_d = rhs_d;
}

// Function for MATLAB Function: '<S6>/MATLAB Function'
static void PIROSNa_AHRSFilterBase_stepImpl(c_fusion_internal_coder_ahrsf_T *obj,
  const real_T accelIn[3], const real_T gyroIn[3], const real_T magIn[3], real_T
  *orientOut_a, real_T *orientOut_b, real_T *orientOut_c, real_T *orientOut_d)
{
  boolean_T isJamming;
  int32_T jAcol;
  int32_T kBcol;
  int32_T ix;
  int32_T b_ix;
  int32_T c_ix;
  int32_T ijA;
  int32_T H_tmp;
  static const int8_T e[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const int8_T f[9] = { -1, 0, 0, 0, -1, 0, 0, 0, -1 };

  if (obj->pFirstTime) {
    obj->pFirstTime = false;
    PIROSNav_NED_ecompass(accelIn, magIn, PIROSNav_B.dv);
    PIROS_quaternioncg_quaternioncg(PIROSNav_B.dv, &obj->pOrientPost.a,
      &obj->pOrientPost.b, &obj->pOrientPost.c, &obj->pOrientPost.d);
  }

  PIROSNav_B.q = obj->pOrientPost;
  IMUFusionCommon_predictOrientat(obj, gyroIn, obj->pGyroOffset, &PIROSNav_B.q);
  obj->pOrientPrior = PIROSNav_B.q;
  PIROSNav_quaternionBase_rotmat(obj->pOrientPrior.a, obj->pOrientPrior.b,
    obj->pOrientPrior.c, obj->pOrientPrior.d, PIROSNav_B.Rprior);
  obj->pLinAccelPrior[0] = obj->LinearAccelerationDecayFactor *
    obj->pLinAccelPost[0];
  PIROSNav_B.gyroOffsetErr_idx_0 = obj->pMagVec[0];
  PIROSNav_B.gravityAccelMeas[0] = (accelIn[0] + obj->pLinAccelPrior[0]) -
    PIROSNav_B.Rprior[6];
  obj->pLinAccelPrior[1] = obj->LinearAccelerationDecayFactor *
    obj->pLinAccelPost[1];
  PIROSNav_B.gyroOffsetErr_idx_1 = obj->pMagVec[1];
  PIROSNav_B.gravityAccelMeas[1] = (accelIn[1] + obj->pLinAccelPrior[1]) -
    PIROSNav_B.Rprior[7];
  obj->pLinAccelPrior[2] = obj->LinearAccelerationDecayFactor *
    obj->pLinAccelPost[2];
  PIROSNav_B.linAccelErr_idx_0 = (accelIn[2] + obj->pLinAccelPrior[2]) -
    PIROSNav_B.Rprior[8];
  PIROSNav_B.gyroOffsetErr_idx_2 = obj->pMagVec[2];
  PIROSNav_B.gravityAccelMeas[2] = PIROSNav_B.linAccelErr_idx_0;
  PIRO_IMUFusionCommon_buildHPart(&PIROSNav_B.Rprior[6], PIROSNav_B.h1);
  for (PIROSNav_B.j = 0; PIROSNav_B.j < 3; PIROSNav_B.j++) {
    PIROSNav_B.smax = PIROSNav_B.h1[3 * PIROSNav_B.j];
    PIROSNav_B.H[6 * PIROSNav_B.j] = PIROSNav_B.smax;
    H_tmp = 6 * (PIROSNav_B.j + 3);
    PIROSNav_B.H[H_tmp] = -PIROSNav_B.smax * obj->pKalmanPeriod;
    b_ix = 6 * (PIROSNav_B.j + 6);
    PIROSNav_B.H[b_ix] = e[3 * PIROSNav_B.j];
    ix = 6 * (PIROSNav_B.j + 9);
    PIROSNav_B.H[ix] = 0.0;
    jAcol = 3 * PIROSNav_B.j + 1;
    PIROSNav_B.H[6 * PIROSNav_B.j + 1] = PIROSNav_B.h1[jAcol];
    PIROSNav_B.H[H_tmp + 1] = -PIROSNav_B.h1[jAcol] * obj->pKalmanPeriod;
    PIROSNav_B.H[b_ix + 1] = e[jAcol];
    PIROSNav_B.H[ix + 1] = 0.0;
    jAcol = 3 * PIROSNav_B.j + 2;
    PIROSNav_B.H[6 * PIROSNav_B.j + 2] = PIROSNav_B.h1[jAcol];
    PIROSNav_B.H[H_tmp + 2] = -PIROSNav_B.h1[jAcol] * obj->pKalmanPeriod;
    PIROSNav_B.H[b_ix + 2] = e[jAcol];
    PIROSNav_B.H[ix + 2] = 0.0;
    PIROSNav_B.Rprior_b[PIROSNav_B.j] = PIROSNav_B.Rprior[PIROSNav_B.j + 6] *
      PIROSNav_B.gyroOffsetErr_idx_2 + (PIROSNav_B.Rprior[PIROSNav_B.j + 3] *
      PIROSNav_B.gyroOffsetErr_idx_1 + PIROSNav_B.Rprior[PIROSNav_B.j] *
      PIROSNav_B.gyroOffsetErr_idx_0);
  }

  PIRO_IMUFusionCommon_buildHPart(PIROSNav_B.Rprior_b, PIROSNav_B.h1);
  for (PIROSNav_B.j = 0; PIROSNav_B.j < 3; PIROSNav_B.j++) {
    PIROSNav_B.smax = PIROSNav_B.h1[3 * PIROSNav_B.j];
    PIROSNav_B.H[6 * PIROSNav_B.j + 3] = PIROSNav_B.smax;
    H_tmp = 6 * (PIROSNav_B.j + 3);
    PIROSNav_B.H[H_tmp + 3] = -PIROSNav_B.smax * obj->pKalmanPeriod;
    b_ix = 6 * (PIROSNav_B.j + 6);
    PIROSNav_B.H[b_ix + 3] = 0.0;
    ix = 6 * (PIROSNav_B.j + 9);
    PIROSNav_B.H[ix + 3] = f[3 * PIROSNav_B.j];
    jAcol = 3 * PIROSNav_B.j + 1;
    PIROSNav_B.H[6 * PIROSNav_B.j + 4] = PIROSNav_B.h1[jAcol];
    PIROSNav_B.H[H_tmp + 4] = -PIROSNav_B.h1[jAcol] * obj->pKalmanPeriod;
    PIROSNav_B.H[b_ix + 4] = 0.0;
    PIROSNav_B.H[ix + 4] = f[jAcol];
    jAcol = 3 * PIROSNav_B.j + 2;
    PIROSNav_B.H[6 * PIROSNav_B.j + 5] = PIROSNav_B.h1[jAcol];
    PIROSNav_B.H[H_tmp + 5] = -PIROSNav_B.h1[jAcol] * obj->pKalmanPeriod;
    PIROSNav_B.H[b_ix + 5] = 0.0;
    PIROSNav_B.H[ix + 5] = f[jAcol];
  }

  memcpy(&PIROSNav_B.Qw[0], &obj->pQw[0], 144U * sizeof(real_T));
  for (PIROSNav_B.j = 0; PIROSNav_B.j < 12; PIROSNav_B.j++) {
    for (b_ix = 0; b_ix < 6; b_ix++) {
      H_tmp = b_ix + 6 * PIROSNav_B.j;
      PIROSNav_B.H_m[H_tmp] = 0.0;
      for (ix = 0; ix < 12; ix++) {
        PIROSNav_B.H_m[H_tmp] += PIROSNav_B.H[6 * ix + b_ix] * obj->pQw[12 *
          PIROSNav_B.j + ix];
      }
    }
  }

  for (PIROSNav_B.j = 0; PIROSNav_B.j < 6; PIROSNav_B.j++) {
    for (b_ix = 0; b_ix < 6; b_ix++) {
      PIROSNav_B.smax = 0.0;
      for (ix = 0; ix < 12; ix++) {
        PIROSNav_B.smax += PIROSNav_B.H_m[6 * ix + b_ix] * PIROSNav_B.H[6 * ix +
          PIROSNav_B.j];
      }

      PIROSNav_B.A[PIROSNav_B.j + 6 * b_ix] = obj->pQv[6 * PIROSNav_B.j + b_ix]
        + PIROSNav_B.smax;
    }

    PIROSNav_B.ipiv[PIROSNav_B.j] = static_cast<int8_T>((PIROSNav_B.j + 1));
  }

  for (PIROSNav_B.j = 0; PIROSNav_B.j < 5; PIROSNav_B.j++) {
    H_tmp = PIROSNav_B.j * 7;
    b_ix = 0;
    ix = H_tmp;
    PIROSNav_B.smax = fabs(PIROSNav_B.A[H_tmp]);
    for (jAcol = 2; jAcol <= 6 - PIROSNav_B.j; jAcol++) {
      ix++;
      PIROSNav_B.linAccelErr_idx_2 = fabs(PIROSNav_B.A[ix]);
      if (PIROSNav_B.linAccelErr_idx_2 > PIROSNav_B.smax) {
        b_ix = jAcol - 1;
        PIROSNav_B.smax = PIROSNav_B.linAccelErr_idx_2;
      }
    }

    if (PIROSNav_B.A[H_tmp + b_ix] != 0.0) {
      if (b_ix != 0) {
        ix = PIROSNav_B.j + b_ix;
        PIROSNav_B.ipiv[PIROSNav_B.j] = static_cast<int8_T>((ix + 1));
        b_ix = PIROSNav_B.j;
        for (jAcol = 0; jAcol < 6; jAcol++) {
          PIROSNav_B.smax = PIROSNav_B.A[b_ix];
          PIROSNav_B.A[b_ix] = PIROSNav_B.A[ix];
          PIROSNav_B.A[ix] = PIROSNav_B.smax;
          b_ix += 6;
          ix += 6;
        }
      }

      b_ix = (H_tmp - PIROSNav_B.j) + 6;
      for (ix = H_tmp + 1; ix < b_ix; ix++) {
        PIROSNav_B.A[ix] /= PIROSNav_B.A[H_tmp];
      }
    }

    b_ix = H_tmp;
    ix = H_tmp + 6;
    for (jAcol = 0; jAcol <= 4 - PIROSNav_B.j; jAcol++) {
      PIROSNav_B.smax = PIROSNav_B.A[ix];
      if (PIROSNav_B.A[ix] != 0.0) {
        c_ix = H_tmp + 1;
        kBcol = (b_ix - PIROSNav_B.j) + 12;
        for (ijA = b_ix + 7; ijA < kBcol; ijA++) {
          PIROSNav_B.A[ijA] += PIROSNav_B.A[c_ix] * -PIROSNav_B.smax;
          c_ix++;
        }
      }

      ix += 6;
      b_ix += 6;
    }
  }

  for (PIROSNav_B.j = 0; PIROSNav_B.j < 12; PIROSNav_B.j++) {
    for (b_ix = 0; b_ix < 6; b_ix++) {
      H_tmp = PIROSNav_B.j + 12 * b_ix;
      PIROSNav_B.K[H_tmp] = 0.0;
      for (ix = 0; ix < 12; ix++) {
        PIROSNav_B.K[H_tmp] += obj->pQw[12 * ix + PIROSNav_B.j] * PIROSNav_B.H[6
          * ix + b_ix];
      }
    }
  }

  for (b_ix = 0; b_ix < 6; b_ix++) {
    ix = 12 * b_ix;
    jAcol = 6 * b_ix;
    for (c_ix = 0; c_ix < b_ix; c_ix++) {
      kBcol = 12 * c_ix;
      PIROSNav_B.j = c_ix + jAcol;
      if (PIROSNav_B.A[PIROSNav_B.j] != 0.0) {
        for (ijA = 0; ijA < 12; ijA++) {
          H_tmp = ijA + ix;
          PIROSNav_B.K[H_tmp] -= PIROSNav_B.A[PIROSNav_B.j] * PIROSNav_B.K[ijA +
            kBcol];
        }
      }
    }

    PIROSNav_B.smax = 1.0 / PIROSNav_B.A[b_ix + jAcol];
    for (PIROSNav_B.j = 0; PIROSNav_B.j < 12; PIROSNav_B.j++) {
      H_tmp = PIROSNav_B.j + ix;
      PIROSNav_B.K[H_tmp] *= PIROSNav_B.smax;
    }
  }

  for (b_ix = 5; b_ix >= 0; b_ix--) {
    ix = 12 * b_ix;
    jAcol = 6 * b_ix - 1;
    for (c_ix = b_ix + 2; c_ix < 7; c_ix++) {
      kBcol = (c_ix - 1) * 12;
      PIROSNav_B.j = c_ix + jAcol;
      if (PIROSNav_B.A[PIROSNav_B.j] != 0.0) {
        for (ijA = 0; ijA < 12; ijA++) {
          H_tmp = ijA + ix;
          PIROSNav_B.K[H_tmp] -= PIROSNav_B.A[PIROSNav_B.j] * PIROSNav_B.K[ijA +
            kBcol];
        }
      }
    }
  }

  for (PIROSNav_B.j = 4; PIROSNav_B.j >= 0; PIROSNav_B.j--) {
    if (PIROSNav_B.j + 1 != PIROSNav_B.ipiv[PIROSNav_B.j]) {
      b_ix = PIROSNav_B.ipiv[PIROSNav_B.j] - 1;
      for (ix = 0; ix < 12; ix++) {
        jAcol = 12 * PIROSNav_B.j + ix;
        PIROSNav_B.smax = PIROSNav_B.K[jAcol];
        H_tmp = 12 * b_ix + ix;
        PIROSNav_B.K[jAcol] = PIROSNav_B.K[H_tmp];
        PIROSNav_B.K[H_tmp] = PIROSNav_B.smax;
      }
    }
  }

  for (PIROSNav_B.j = 0; PIROSNav_B.j < 3; PIROSNav_B.j++) {
    PIROSNav_B.ze[PIROSNav_B.j] = PIROSNav_B.gravityAccelMeas[PIROSNav_B.j];
    PIROSNav_B.ze[PIROSNav_B.j + 3] = magIn[PIROSNav_B.j] -
      ((PIROSNav_B.Rprior[PIROSNav_B.j + 3] * PIROSNav_B.gyroOffsetErr_idx_1 +
        PIROSNav_B.Rprior[PIROSNav_B.j] * PIROSNav_B.gyroOffsetErr_idx_0) +
       PIROSNav_B.Rprior[PIROSNav_B.j + 6] * PIROSNav_B.gyroOffsetErr_idx_2);
  }

  for (PIROSNav_B.j = 0; PIROSNav_B.j < 3; PIROSNav_B.j++) {
    PIROSNav_B.y_c[PIROSNav_B.j] = 0.0;
    for (b_ix = 0; b_ix < 6; b_ix++) {
      PIROSNav_B.y_c[PIROSNav_B.j] += PIROSNav_B.K[(12 * b_ix + PIROSNav_B.j) +
        9] * PIROSNav_B.ze[b_ix];
    }
  }

  PIROSNav_B.gyroOffsetErr_idx_0 = PIROSNav_norm(PIROSNav_B.y_c);
  isJamming = (PIROSNav_B.gyroOffsetErr_idx_0 * PIROSNav_B.gyroOffsetErr_idx_0 >
               obj->ExpectedMagneticFieldStrength *
               obj->ExpectedMagneticFieldStrength * 4.0);
  if (isJamming) {
    for (PIROSNav_B.j = 0; PIROSNav_B.j < 9; PIROSNav_B.j++) {
      PIROSNav_B.Rprior[PIROSNav_B.j] = PIROSNav_B.K[PIROSNav_B.j + 24] *
        PIROSNav_B.linAccelErr_idx_0 + (PIROSNav_B.K[PIROSNav_B.j + 12] *
        PIROSNav_B.gravityAccelMeas[1] + PIROSNav_B.K[PIROSNav_B.j] *
        PIROSNav_B.gravityAccelMeas[0]);
    }

    PIROSNav_B.gravityAccelMeas[0] = PIROSNav_B.Rprior[0];
    PIROSNav_B.gyroOffsetErr_idx_0 = PIROSNav_B.Rprior[3];
    PIROSNav_B.linAccelErr_idx_0 = PIROSNav_B.Rprior[6];
    PIROSNav_B.gravityAccelMeas[1] = PIROSNav_B.Rprior[1];
    PIROSNav_B.gyroOffsetErr_idx_1 = PIROSNav_B.Rprior[4];
    PIROSNav_B.smax = PIROSNav_B.Rprior[7];
    PIROSNav_B.gravityAccelMeas[2] = PIROSNav_B.Rprior[2];
    PIROSNav_B.gyroOffsetErr_idx_2 = PIROSNav_B.Rprior[5];
    PIROSNav_B.linAccelErr_idx_2 = PIROSNav_B.Rprior[8];
  } else {
    for (PIROSNav_B.j = 0; PIROSNav_B.j < 12; PIROSNav_B.j++) {
      PIROSNav_B.xe_post[PIROSNav_B.j] = 0.0;
      for (b_ix = 0; b_ix < 6; b_ix++) {
        PIROSNav_B.xe_post[PIROSNav_B.j] += PIROSNav_B.K[12 * b_ix +
          PIROSNav_B.j] * PIROSNav_B.ze[b_ix];
      }
    }

    PIROSNav_B.gravityAccelMeas[0] = PIROSNav_B.xe_post[0];
    PIROSNav_B.gyroOffsetErr_idx_0 = PIROSNav_B.xe_post[3];
    PIROSNav_B.linAccelErr_idx_0 = PIROSNav_B.xe_post[6];
    PIROSNav_B.gravityAccelMeas[1] = PIROSNav_B.xe_post[1];
    PIROSNav_B.gyroOffsetErr_idx_1 = PIROSNav_B.xe_post[4];
    PIROSNav_B.smax = PIROSNav_B.xe_post[7];
    PIROSNav_B.gravityAccelMeas[2] = PIROSNav_B.xe_post[2];
    PIROSNav_B.gyroOffsetErr_idx_2 = PIROSNav_B.xe_post[5];
    PIROSNav_B.linAccelErr_idx_2 = PIROSNav_B.xe_post[8];
  }

  PIR_quaternioncg_quaternioncg_g(PIROSNav_B.gravityAccelMeas, &PIROSNav_B.q.a,
    &PIROSNav_B.q.b, &PIROSNav_B.q.c, &PIROSNav_B.q.d);
  PIROSNav_quaternionBase_conj(&PIROSNav_B.q);
  PIROSNav_quaternionBase_mtimes(obj->pOrientPrior.a, obj->pOrientPrior.b,
    obj->pOrientPrior.c, obj->pOrientPrior.d, PIROSNav_B.q.a, PIROSNav_B.q.b,
    PIROSNav_B.q.c, PIROSNav_B.q.d, &obj->pOrientPost.a, &obj->pOrientPost.b,
    &obj->pOrientPost.c, &obj->pOrientPost.d);
  if (obj->pOrientPost.a < 0.0) {
    PIROSNav_quaternionBase_uminus(&obj->pOrientPost);
  }

  PIROSN_quaternionBase_normalize(&obj->pOrientPost);
  PIROSNav_quaternionBase_rotmat(obj->pOrientPost.a, obj->pOrientPost.b,
    obj->pOrientPost.c, obj->pOrientPost.d, PIROSNav_B.Rprior);
  obj->pGyroOffset[0] -= PIROSNav_B.gyroOffsetErr_idx_0;
  obj->pLinAccelPost[0] = obj->pLinAccelPrior[0] - PIROSNav_B.linAccelErr_idx_0;
  obj->pGyroOffset[1] -= PIROSNav_B.gyroOffsetErr_idx_1;
  obj->pLinAccelPost[1] = obj->pLinAccelPrior[1] - PIROSNav_B.smax;
  obj->pGyroOffset[2] -= PIROSNav_B.gyroOffsetErr_idx_2;
  obj->pLinAccelPost[2] = obj->pLinAccelPrior[2] - PIROSNav_B.linAccelErr_idx_2;
  if (!isJamming) {
    for (PIROSNav_B.j = 0; PIROSNav_B.j < 3; PIROSNav_B.j++) {
      PIROSNav_B.gravityAccelMeas[PIROSNav_B.j] = obj->pMagVec[PIROSNav_B.j] -
        (PIROSNav_B.Rprior[3 * PIROSNav_B.j + 2] * PIROSNav_B.y_c[2] +
         (PIROSNav_B.Rprior[3 * PIROSNav_B.j + 1] * PIROSNav_B.y_c[1] +
          PIROSNav_B.Rprior[3 * PIROSNav_B.j] * PIROSNav_B.y_c[0]));
    }

    PIROSNav_B.linAccelErr_idx_0 = rt_atan2d_snf(PIROSNav_B.gravityAccelMeas[2],
      PIROSNav_B.gravityAccelMeas[0]);
    if (PIROSNav_B.linAccelErr_idx_0 < -1.5707963267948966) {
      PIROSNav_B.linAccelErr_idx_0 = -1.5707963267948966;
    }

    if (PIROSNav_B.linAccelErr_idx_0 > 1.5707963267948966) {
      PIROSNav_B.linAccelErr_idx_0 = 1.5707963267948966;
    }

    obj->pMagVec[0] = 0.0;
    obj->pMagVec[1] = 0.0;
    obj->pMagVec[2] = 0.0;
    obj->pMagVec[0] = cos(PIROSNav_B.linAccelErr_idx_0);
    obj->pMagVec[2] = sin(PIROSNav_B.linAccelErr_idx_0);
    obj->pMagVec[0] *= obj->ExpectedMagneticFieldStrength;
    obj->pMagVec[1] *= obj->ExpectedMagneticFieldStrength;
    obj->pMagVec[2] *= obj->ExpectedMagneticFieldStrength;
  }

  for (PIROSNav_B.j = 0; PIROSNav_B.j < 12; PIROSNav_B.j++) {
    for (b_ix = 0; b_ix < 6; b_ix++) {
      H_tmp = b_ix + 6 * PIROSNav_B.j;
      PIROSNav_B.H_m[H_tmp] = 0.0;
      for (ix = 0; ix < 12; ix++) {
        PIROSNav_B.H_m[H_tmp] += PIROSNav_B.H[6 * ix + b_ix] * PIROSNav_B.Qw[12 *
          PIROSNav_B.j + ix];
      }
    }
  }

  for (PIROSNav_B.j = 0; PIROSNav_B.j < 12; PIROSNav_B.j++) {
    for (b_ix = 0; b_ix < 12; b_ix++) {
      PIROSNav_B.smax = 0.0;
      for (ix = 0; ix < 6; ix++) {
        PIROSNav_B.smax += PIROSNav_B.K[12 * ix + b_ix] * PIROSNav_B.H_m[6 *
          PIROSNav_B.j + ix];
      }

      H_tmp = 12 * PIROSNav_B.j + b_ix;
      PIROSNav_B.Ppost[H_tmp] = PIROSNav_B.Qw[H_tmp] - PIROSNav_B.smax;
    }
  }

  memset(&PIROSNav_B.Qw[0], 0, 144U * sizeof(real_T));
  PIROSNav_B.gyroOffsetErr_idx_0 = obj->pKalmanPeriod * obj->pKalmanPeriod;
  PIROSNav_B.gyroOffsetErr_idx_1 = obj->GyroscopeDriftNoise +
    obj->GyroscopeNoise;
  PIROSNav_B.gyroOffsetErr_idx_2 = obj->LinearAccelerationDecayFactor *
    obj->LinearAccelerationDecayFactor;
  PIROSNav_B.smax = obj->MagneticDisturbanceDecayFactor *
    obj->MagneticDisturbanceDecayFactor;
  PIROSNav_B.Qw[0] = (PIROSNav_B.Ppost[39] + PIROSNav_B.gyroOffsetErr_idx_1) *
    PIROSNav_B.gyroOffsetErr_idx_0 + PIROSNav_B.Ppost[0];
  PIROSNav_B.Qw[39] = PIROSNav_B.Ppost[39] + obj->GyroscopeDriftNoise;
  PIROSNav_B.linAccelErr_idx_0 = -obj->pKalmanPeriod * PIROSNav_B.Qw[39];
  PIROSNav_B.Qw[3] = PIROSNav_B.linAccelErr_idx_0;
  PIROSNav_B.Qw[36] = PIROSNav_B.linAccelErr_idx_0;
  PIROSNav_B.Qw[78] = PIROSNav_B.gyroOffsetErr_idx_2 * PIROSNav_B.Ppost[78] +
    obj->LinearAccelerationNoise;
  PIROSNav_B.Qw[117] = PIROSNav_B.smax * PIROSNav_B.Ppost[117] +
    obj->MagneticDisturbanceNoise;
  PIROSNav_B.Qw[13] = (PIROSNav_B.Ppost[52] + PIROSNav_B.gyroOffsetErr_idx_1) *
    PIROSNav_B.gyroOffsetErr_idx_0 + PIROSNav_B.Ppost[13];
  PIROSNav_B.Qw[52] = PIROSNav_B.Ppost[52] + obj->GyroscopeDriftNoise;
  PIROSNav_B.linAccelErr_idx_0 = -obj->pKalmanPeriod * PIROSNav_B.Qw[52];
  PIROSNav_B.Qw[16] = PIROSNav_B.linAccelErr_idx_0;
  PIROSNav_B.Qw[49] = PIROSNav_B.linAccelErr_idx_0;
  PIROSNav_B.Qw[91] = PIROSNav_B.gyroOffsetErr_idx_2 * PIROSNav_B.Ppost[91] +
    obj->LinearAccelerationNoise;
  PIROSNav_B.Qw[130] = PIROSNav_B.smax * PIROSNav_B.Ppost[130] +
    obj->MagneticDisturbanceNoise;
  PIROSNav_B.Qw[26] = (PIROSNav_B.Ppost[65] + PIROSNav_B.gyroOffsetErr_idx_1) *
    PIROSNav_B.gyroOffsetErr_idx_0 + PIROSNav_B.Ppost[26];
  PIROSNav_B.Qw[65] = PIROSNav_B.Ppost[65] + obj->GyroscopeDriftNoise;
  PIROSNav_B.linAccelErr_idx_0 = -obj->pKalmanPeriod * PIROSNav_B.Qw[65];
  PIROSNav_B.Qw[29] = PIROSNav_B.linAccelErr_idx_0;
  PIROSNav_B.Qw[62] = PIROSNav_B.linAccelErr_idx_0;
  PIROSNav_B.Qw[104] = PIROSNav_B.gyroOffsetErr_idx_2 * PIROSNav_B.Ppost[104] +
    obj->LinearAccelerationNoise;
  PIROSNav_B.Qw[143] = PIROSNav_B.smax * PIROSNav_B.Ppost[143] +
    obj->MagneticDisturbanceNoise;
  memcpy(&obj->pQw[0], &PIROSNav_B.Qw[0], 144U * sizeof(real_T));
  PIROSN_quaternioncg_parenAssign(obj->pOrientPost.a, obj->pOrientPost.b,
    obj->pOrientPost.c, obj->pOrientPost.d, orientOut_a, orientOut_b,
    orientOut_c, orientOut_d);
}

static void matlabCodegenHandle_matla_imdcl(ros_slros_internal_block_Subs_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void PIROSN_SystemCore_release_imdcl(const
  codertarget_raspi_internal_SP_T *obj)
{
  uint32_T PinNameLoc;
  uint32_T MOSIPinLoc;
  uint32_T MISOPinLoc;
  uint32_T SCKPinLoc;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    PinNameLoc = SPI0_CE0;
    MOSIPinLoc = MW_UNDEFINED_VALUE;
    MISOPinLoc = MW_UNDEFINED_VALUE;
    SCKPinLoc = MW_UNDEFINED_VALUE;
    MW_SPI_Close(obj->MW_SPI_HANDLE, MOSIPinLoc, MISOPinLoc, SCKPinLoc,
                 PinNameLoc);
  }
}

static void PIROS_SystemCore_delete_imdcl2f(const
  codertarget_raspi_internal_SP_T *obj)
{
  PIROSN_SystemCore_release_imdcl(obj);
}

static void matlabCodegenHandle_mat_imdcl2f(codertarget_raspi_internal_SP_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    PIROS_SystemCore_delete_imdcl2f(obj);
  }
}

static void PIROSNav_SystemCore_release_im(const raspi_internal_lsm9ds1Block_P_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_I2C_Close(obj->i2cobj_A_G.MW_I2C_HANDLE);
    MW_I2C_Close(obj->i2cobj_MAG.MW_I2C_HANDLE);
  }
}

static void PIROSNav_SystemCore_delete_im(const raspi_internal_lsm9ds1Block_P_T *
  obj)
{
  PIROSNav_SystemCore_release_im(obj);
}

static void matlabCodegenHandle_matlabCo_im(raspi_internal_lsm9ds1Block_P_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    PIROSNav_SystemCore_delete_im(obj);
  }
}

static void PIROSNa_SystemCore_release_imdc(g_codertarget_raspi_internal__T *obj)
{
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }
}

static void PIROSNav_SystemCore_delete_imdc(g_codertarget_raspi_internal__T *obj)
{
  PIROSNa_SystemCore_release_imdc(obj);
}

static void matlabCodegenHandle_matlab_imdc(g_codertarget_raspi_internal__T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    PIROSNav_SystemCore_delete_imdc(obj);
  }
}

static void PIROSNav_SystemCore_release_imd(f_codertarget_raspi_internal__T *obj)
{
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }
}

static void PIROSNav_SystemCore_delete_imd(f_codertarget_raspi_internal__T *obj)
{
  PIROSNav_SystemCore_release_imd(obj);
}

static void matlabCodegenHandle_matlabC_imd(f_codertarget_raspi_internal__T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    PIROSNav_SystemCore_delete_imd(obj);
  }
}

static void PIROSNav_SystemCore_release_i(const raspi_internal_lps25hBlock_PI_T *
  obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_I2C_Close(obj->MW_I2C_HANDLE);
  }
}

static void PIROSNav_SystemCore_delete_i(const raspi_internal_lps25hBlock_PI_T
  *obj)
{
  PIROSNav_SystemCore_release_i(obj);
}

static void matlabCodegenHandle_matlabCod_i(raspi_internal_lps25hBlock_PI_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    PIROSNav_SystemCore_delete_i(obj);
  }
}

static void PIROSNav_SystemCore_release(const raspi_internal_hts221Block_PI_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_I2C_Close(obj->MW_I2C_HANDLE);
  }
}

static void PIROSNav_SystemCore_delete(const raspi_internal_hts221Block_PI_T
  *obj)
{
  PIROSNav_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(raspi_internal_hts221Block_PI_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    PIROSNav_SystemCore_delete(obj);
  }
}

static raspi_internal_lsm9ds1Block_P_T *PIROS_lsm9ds1Block_lsm9ds1Block
  (raspi_internal_lsm9ds1Block_P_T *obj)
{
  raspi_internal_lsm9ds1Block_P_T *b_obj;
  int32_T i;
  static const int8_T tmp[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  for (i = 0; i < 9; i++) {
    obj->CalGyroA[i] = tmp[i];
  }

  obj->CalGyroB[0] = 0.0;
  obj->CalGyroB[1] = 0.0;
  obj->CalGyroB[2] = 0.0;
  for (i = 0; i < 9; i++) {
    obj->CalAccelA[i] = tmp[i];
  }

  obj->CalAccelB[0] = 0.0;
  obj->CalAccelB[1] = 0.0;
  obj->CalAccelB[2] = 0.0;
  for (i = 0; i < 9; i++) {
    obj->CalMagA[i] = tmp[i];
  }

  obj->CalMagB[0] = 0.0;
  obj->CalMagB[1] = 0.0;
  obj->CalMagB[2] = 0.0;
  obj->isInitialized = 0;
  b_obj = obj;
  obj->i2cobj_A_G.isInitialized = 0;
  obj->i2cobj_A_G.matlabCodegenIsDeleted = false;
  obj->i2cobj_MAG.isInitialized = 0;
  obj->i2cobj_MAG.matlabCodegenIsDeleted = false;
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

static void PIROSNav_lsm9ds1Block_setupImpl(raspi_internal_lsm9ds1Block_P_T *obj)
{
  uint32_T i2cname;
  uint8_T b_SwappedDataBytes[2];
  uint8_T CastedData;
  uint8_T SwappedDataBytes[2];
  i2cname = 1;
  obj->i2cobj_A_G.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  obj->i2cobj_A_G.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj_A_G.MW_I2C_HANDLE, obj->i2cobj_A_G.BusSpeed);
  CastedData = 96U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 16U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 17U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 18U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 56U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 30U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 19U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 56U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 31U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 103U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 32U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 33U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 4U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 34U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                     false, false);
  i2cname = 1;
  obj->i2cobj_MAG.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  obj->i2cobj_MAG.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj_MAG.MW_I2C_HANDLE, obj->i2cobj_MAG.BusSpeed);
  CastedData = 24U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 32U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 33U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 34U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 35U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 36U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes, 2U,
                     false, false);
}

static void PIROSNav_SystemCore_setup_i(raspi_internal_lps25hBlock_PI_T *obj)
{
  uint32_T i2cname;
  uint8_T b_SwappedDataBytes[2];
  real_T tmp;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  i2cname = 1;
  obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  obj->BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->MW_I2C_HANDLE, obj->BusSpeed);
  b_SwappedDataBytes[0] = 32U;
  tmp = rt_roundd_snf(obj->CTRL_REG1_Value + 48.0);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      b_SwappedDataBytes[1] = static_cast<uint8_T>(tmp);
    } else {
      b_SwappedDataBytes[1] = 0U;
    }
  } else {
    b_SwappedDataBytes[1] = MAX_uint8_T;
  }

  MW_I2C_MasterWrite(obj->MW_I2C_HANDLE, 92U, b_SwappedDataBytes, 2U, false,
                     false);
  b_SwappedDataBytes[0] = 16U;
  b_SwappedDataBytes[1] = 5U;
  MW_I2C_MasterWrite(obj->MW_I2C_HANDLE, 92U, b_SwappedDataBytes, 2U, false,
                     false);
  b_SwappedDataBytes[0] = 46U;
  b_SwappedDataBytes[1] = 192U;
  MW_I2C_MasterWrite(obj->MW_I2C_HANDLE, 92U, b_SwappedDataBytes, 2U, false,
                     false);
  b_SwappedDataBytes[0] = 33U;
  b_SwappedDataBytes[1] = 64U;
  MW_I2C_MasterWrite(obj->MW_I2C_HANDLE, 92U, b_SwappedDataBytes, 2U, false,
                     false);
  obj->isSetupComplete = true;
}

static void PIROSNav_SystemCore_setup(raspi_internal_hts221Block_PI_T *obj)
{
  uint32_T i2cname;
  int16_T y;
  uint8_T b_SwappedDataBytes[2];
  uint8_T status;
  int32_T i;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  i2cname = 1;
  obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  obj->BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->MW_I2C_HANDLE, obj->BusSpeed);
  b_SwappedDataBytes[0] = 32U;
  b_SwappedDataBytes[1] = 131U;
  MW_I2C_MasterWrite(obj->MW_I2C_HANDLE, 95U, b_SwappedDataBytes, 2U, false,
                     false);
  b_SwappedDataBytes[0] = 16U;
  b_SwappedDataBytes[1] = 27U;
  MW_I2C_MasterWrite(obj->MW_I2C_HANDLE, 95U, b_SwappedDataBytes, 2U, false,
                     false);
  status = 176U;
  status = MW_I2C_MasterWrite(obj->MW_I2C_HANDLE, 95U, &status, 1U, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(obj->MW_I2C_HANDLE, 95U, PIROSNav_B.output_raw, 16U, false,
                      true);
    memcpy((void *)&PIROSNav_B.b_RegisterValue[0], (void *)
           &PIROSNav_B.output_raw[0], (uint32_T)((size_t)16 * sizeof(uint8_T)));
  } else {
    for (i = 0; i < 16; i++) {
      PIROSNav_B.b_RegisterValue[i] = 0U;
    }
  }

  b_SwappedDataBytes[0] = PIROSNav_B.b_RegisterValue[2];
  b_SwappedDataBytes[1] = static_cast<uint8_T>((PIROSNav_B.b_RegisterValue[5] &
    3));
  memcpy((void *)&y, (void *)&b_SwappedDataBytes[0], (uint32_T)((size_t)1 *
          sizeof(int16_T)));
  obj->T0_degC = static_cast<real_T>(y) / 8.0;
  b_SwappedDataBytes[0] = PIROSNav_B.b_RegisterValue[3];
  b_SwappedDataBytes[1] = static_cast<uint8_T>((static_cast<uint32_T>
    ((PIROSNav_B.b_RegisterValue[5] & 12)) >> 2));
  memcpy((void *)&y, (void *)&b_SwappedDataBytes[0], (uint32_T)((size_t)1 *
          sizeof(int16_T)));
  obj->T1_degC = static_cast<real_T>(y) / 8.0;
  b_SwappedDataBytes[0] = PIROSNav_B.b_RegisterValue[12];
  b_SwappedDataBytes[1] = PIROSNav_B.b_RegisterValue[13];
  memcpy((void *)&y, (void *)&b_SwappedDataBytes[0], (uint32_T)((size_t)1 *
          sizeof(int16_T)));
  obj->T0_out = y;
  b_SwappedDataBytes[0] = PIROSNav_B.b_RegisterValue[14];
  b_SwappedDataBytes[1] = PIROSNav_B.b_RegisterValue[15];
  memcpy((void *)&y, (void *)&b_SwappedDataBytes[0], (uint32_T)((size_t)1 *
          sizeof(int16_T)));
  obj->T1_out = y;
  obj->H0_rh = static_cast<real_T>(PIROSNav_B.b_RegisterValue[0]) / 2.0;
  obj->H1_rh = static_cast<real_T>(PIROSNav_B.b_RegisterValue[1]) / 2.0;
  b_SwappedDataBytes[0] = PIROSNav_B.b_RegisterValue[6];
  b_SwappedDataBytes[1] = PIROSNav_B.b_RegisterValue[7];
  memcpy((void *)&y, (void *)&b_SwappedDataBytes[0], (uint32_T)((size_t)1 *
          sizeof(int16_T)));
  obj->H0_T0_out = y;
  b_SwappedDataBytes[0] = PIROSNav_B.b_RegisterValue[10];
  b_SwappedDataBytes[1] = PIROSNav_B.b_RegisterValue[11];
  memcpy((void *)&y, (void *)&b_SwappedDataBytes[0], (uint32_T)((size_t)1 *
          sizeof(int16_T)));
  obj->H1_T0_out = y;
  obj->isSetupComplete = true;
}

// Model step function for TID0
void PIROSNav_step0(void)              // Sample time: [0.1s, 0.0s]
{
  static const real_T c[144] = { 6.0923483957341713E-6, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 6.0923483957341713E-6, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 6.0923483957341713E-6, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 7.6154354946677142E-5, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 7.6154354946677142E-5, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 7.6154354946677142E-5,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0096236100000000012, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0096236100000000012, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0096236100000000012, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.6 };

  uint8_T status;
  uint8_T y[2];
  uint16_T y_0;
  uint8_T SwappedDataBytes;
  uint8_T b_RegisterValue[3];
  uint8_T output_raw[2];
  uint8_T output_raw_0[3];
  int16_T y_1;
  int16_T y_2;
  uint16_T b_x;
  static const uint64m_T tmp = { { 0U, 0U }// chunks
  };

  static const uint64m_T tmp_0 = { { MAX_uint32_T, MAX_uint32_T }// chunks
  };

  static const int8_T b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  {                                    // Sample time: [0.1s, 0.0s]
    rate_monotonic_scheduler();
  }

  // Reset subsysRan breadcrumbs
  srClearBC(PIROSNav_DW.GetRosMessage_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(PIROSNav_DW.GetRosMessage1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(PIROSNav_DW.EnabledSubsystem_SubsysRanBC_b);

  // Reset subsysRan breadcrumbs
  srClearBC(PIROSNav_DW.EnabledSubsystem_SubsysRanBC);

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // MATLABSystem: '<S8>/SourceBlock'
  PIROSNav_B.SourceBlock_o1 = Sub_PIROSNav_110.getLatestMessage
    (&PIROSNav_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S19>/Enable'

  if (PIROSNav_B.SourceBlock_o1) {
    // Inport: '<S19>/In1' incorporates:
    //   MATLABSystem: '<S8>/SourceBlock'

    PIROSNav_B.In1 = PIROSNav_B.b_varargout_2;
    srUpdateBC(PIROSNav_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // Outputs for Enabled SubSystem: '<Root>/GetRosMessage1' incorporates:
  //   EnablePort: '<S5>/Enable'

  if (PIROSNav_B.SourceBlock_o1) {
    // DeadZone: '<S14>/Dead Zone' incorporates:
    //   MATLAB Function: '<S5>/MATLAB Function'

    for (PIROSNav_B.i = 0; PIROSNav_B.i < 8; PIROSNav_B.i++) {
      if (PIROSNav_B.In1.Axes[PIROSNav_B.i] > PIROSNav_P.DeadZone_End) {
        PIROSNav_B.DeadZone[PIROSNav_B.i] = PIROSNav_B.In1.Axes[PIROSNav_B.i] -
          PIROSNav_P.DeadZone_End;
      } else if (PIROSNav_B.In1.Axes[PIROSNav_B.i] >= PIROSNav_P.DeadZone_Start)
      {
        PIROSNav_B.DeadZone[PIROSNav_B.i] = 0.0F;
      } else {
        PIROSNav_B.DeadZone[PIROSNav_B.i] = PIROSNav_B.In1.Axes[PIROSNav_B.i] -
          PIROSNav_P.DeadZone_Start;
      }
    }

    // End of DeadZone: '<S14>/Dead Zone'

    // Lookup_n-D: '<S14>/1-D Lookup Table1' incorporates:
    //   SignalConversion generated from: '<S14>/1-D Lookup Table1'

    PIROSNav_B.uDLookupTable1_b[0] = look1_iflf_binlxpw(PIROSNav_B.DeadZone[0],
      PIROSNav_P.uDLookupTable1_bp01Data_j, PIROSNav_P.uDLookupTable1_tableData,
      2U);
    PIROSNav_B.uDLookupTable1_b[1] = look1_iflf_binlxpw(PIROSNav_B.DeadZone[1],
      PIROSNav_P.uDLookupTable1_bp01Data_j, PIROSNav_P.uDLookupTable1_tableData,
      2U);
    PIROSNav_B.uDLookupTable1_b[2] = look1_iflf_binlxpw(PIROSNav_B.DeadZone[3],
      PIROSNav_P.uDLookupTable1_bp01Data_j, PIROSNav_P.uDLookupTable1_tableData,
      2U);
    PIROSNav_B.uDLookupTable1_b[3] = look1_iflf_binlxpw(PIROSNav_B.DeadZone[4],
      PIROSNav_P.uDLookupTable1_bp01Data_j, PIROSNav_P.uDLookupTable1_tableData,
      2U);

    // SignalConversion generated from: '<S5>/UpDownL'
    PIROSNav_B.OutportBufferForUpDownL = PIROSNav_B.uDLookupTable1_b[1];
    srUpdateBC(PIROSNav_DW.GetRosMessage1_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<Root>/GetRosMessage1'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S7>/SourceBlock'
  PIROSNav_B.SourceBlock_o1_a = Sub_PIROSNav_21.getLatestMessage
    (&PIROSNav_B.b_varargout_2_c);

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S18>/Enable'

  if (PIROSNav_B.SourceBlock_o1_a) {
    // Inport: '<S18>/In1' incorporates:
    //   MATLABSystem: '<S7>/SourceBlock'

    PIROSNav_B.In1_h = PIROSNav_B.b_varargout_2_c;
    srUpdateBC(PIROSNav_DW.EnabledSubsystem_SubsysRanBC_b);
  }

  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Outputs for Enabled SubSystem: '<Root>/GetRosMessage' incorporates:
  //   EnablePort: '<S4>/Enable'

  if (PIROSNav_B.SourceBlock_o1_a) {
    // DataTypeConversion: '<S4>/Data Type Conversion1'
    PIROSNav_B.DataTypeConversion1 = static_cast<real32_T>
      (PIROSNav_B.In1_h.Linear.X);

    // DataTypeConversion: '<S4>/Data Type Conversion2'
    PIROSNav_B.DataTypeConversion2 = static_cast<real32_T>
      (PIROSNav_B.In1_h.Angular.Z);

    // DataTypeConversion: '<S4>/Data Type Conversion3'
    PIROSNav_B.DataTypeConversion3 = static_cast<real32_T>
      (PIROSNav_B.In1_h.Linear.Y);

    // DataTypeConversion: '<S4>/Data Type Conversion4'
    PIROSNav_B.DataTypeConversion4 = static_cast<real32_T>
      (PIROSNav_B.In1_h.Linear.Z);

    // DataTypeConversion: '<S4>/Data Type Conversion5'
    PIROSNav_B.DataTypeConversion5 = static_cast<real32_T>
      (PIROSNav_B.In1_h.Angular.X);

    // DataTypeConversion: '<S4>/Data Type Conversion6'
    PIROSNav_B.DataTypeConversion6 = static_cast<real32_T>
      (PIROSNav_B.In1_h.Angular.Y);
    srUpdateBC(PIROSNav_DW.GetRosMessage_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<Root>/GetRosMessage'

  // ManualSwitch: '<Root>/Manual Switch1' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<Root>/Constant2'

  if (PIROSNav_P.ManualSwitch1_CurrentSetting == 1) {
    PIROSNav_B.SquareRoot = PIROSNav_P.Constant_Value_b;
  } else {
    PIROSNav_B.SquareRoot = PIROSNav_P.Constant2_Value_d;
  }

  // End of ManualSwitch: '<Root>/Manual Switch1'

  // Switch: '<S1>/Switch'
  if (PIROSNav_B.SquareRoot != 0.0F) {
    // Sqrt: '<S1>/Square Root' incorporates:
    //   Math: '<S1>/Magnitude Squared'
    //
    //  About '<S1>/Magnitude Squared':
    //   Operator: magnitude^2

    PIROSNav_B.SquareRoot = static_cast<real32_T>(sqrt(static_cast<real_T>
      ((PIROSNav_B.DataTypeConversion2 * PIROSNav_B.DataTypeConversion2))));

    // Switch: '<S1>/Switch2' incorporates:
    //   Constant: '<S1>/Constant2'

    if (PIROSNav_B.SquareRoot >= PIROSNav_P.Switch2_Threshold) {
      PIROSNav_B.rtb_Gain1_idx_0 = PIROSNav_P.Constant2_Value;
    } else {
      PIROSNav_B.rtb_Gain1_idx_0 = PIROSNav_B.DataTypeConversion1;
    }

    // End of Switch: '<S1>/Switch2'

    // Switch: '<S1>/Switch1' incorporates:
    //   Constant: '<S1>/Constant1'

    if (PIROSNav_B.SquareRoot >= PIROSNav_P.Switch1_Threshold) {
      PIROSNav_B.rtb_Gain1_idx_1 = PIROSNav_P.Constant1_Value;
    } else {
      PIROSNav_B.rtb_Gain1_idx_1 = PIROSNav_B.DataTypeConversion2;
    }

    // End of Switch: '<S1>/Switch1'
  } else {
    PIROSNav_B.rtb_Gain1_idx_0 = PIROSNav_B.OutportBufferForUpDownL;
    PIROSNav_B.rtb_Gain1_idx_1 = PIROSNav_B.uDLookupTable1_b[0];
  }

  // End of Switch: '<S1>/Switch'

  // Gain: '<S1>/Gain1'
  PIROSNav_B.rtb_Gain1_idx_0 *= PIROSNav_P.Gain1_Gain;

  // Lookup_n-D: '<S3>/1-D Lookup Table9'
  PIROSNav_B.uDLookupTable9 = look1_tf_binlcpw(PIROSNav_B.rtb_Gain1_idx_0,
    PIROSNav_P.uDLookupTable9_bp01Data, PIROSNav_P.uDLookupTable9_tableData, 4U);

  // Lookup_n-D: '<S3>/1-D Lookup Table1' incorporates:
  //   Gain: '<S1>/Gain1'

  PIROSNav_B.uDLookupTable1 = look1_tf_binlcpw(PIROSNav_P.Gain1_Gain *
    PIROSNav_B.rtb_Gain1_idx_1, PIROSNav_P.uDLookupTable1_bp01Data,
    PIROSNav_P.uDLookupTable1_tableData_n, 4U);

  // DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Constant: '<Root>/Constant3'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<Root>/Constant5'
  //   Constant: '<S9>/EndofData'

  PIROSNav_B.SquareRoot = rt_roundf_snf(PIROSNav_B.uDLookupTable9);
  if (PIROSNav_B.SquareRoot < 65536.0F) {
    if (PIROSNav_B.SquareRoot >= 0.0F) {
      // MATLABSystem: '<S9>/SPI Master Transfer'
      PIROSNav_B.b_x[0] = static_cast<uint16_T>(PIROSNav_B.SquareRoot);
    } else {
      // MATLABSystem: '<S9>/SPI Master Transfer'
      PIROSNav_B.b_x[0] = 0U;
    }
  } else {
    // MATLABSystem: '<S9>/SPI Master Transfer'
    PIROSNav_B.b_x[0] = MAX_uint16_T;
  }

  PIROSNav_B.SquareRoot = rt_roundf_snf(PIROSNav_B.uDLookupTable1);
  if (PIROSNav_B.SquareRoot < 65536.0F) {
    if (PIROSNav_B.SquareRoot >= 0.0F) {
      // MATLABSystem: '<S9>/SPI Master Transfer'
      PIROSNav_B.b_x[1] = static_cast<uint16_T>(PIROSNav_B.SquareRoot);
    } else {
      // MATLABSystem: '<S9>/SPI Master Transfer'
      PIROSNav_B.b_x[1] = 0U;
    }
  } else {
    // MATLABSystem: '<S9>/SPI Master Transfer'
    PIROSNav_B.b_x[1] = MAX_uint16_T;
  }

  PIROSNav_B.SquareRoot = rt_roundf_snf(PIROSNav_P.Constant5_Value);
  if (PIROSNav_B.SquareRoot < 65536.0F) {
    if (PIROSNav_B.SquareRoot >= 0.0F) {
      // MATLABSystem: '<S9>/SPI Master Transfer'
      PIROSNav_B.b_x[2] = static_cast<uint16_T>(PIROSNav_B.SquareRoot);
    } else {
      // MATLABSystem: '<S9>/SPI Master Transfer'
      PIROSNav_B.b_x[2] = 0U;
    }
  } else {
    // MATLABSystem: '<S9>/SPI Master Transfer'
    PIROSNav_B.b_x[2] = MAX_uint16_T;
  }

  PIROSNav_B.SquareRoot = rt_roundf_snf(PIROSNav_P.Constant4_Value);
  if (PIROSNav_B.SquareRoot < 65536.0F) {
    if (PIROSNav_B.SquareRoot >= 0.0F) {
      // MATLABSystem: '<S9>/SPI Master Transfer'
      PIROSNav_B.b_x[3] = static_cast<uint16_T>(PIROSNav_B.SquareRoot);
    } else {
      // MATLABSystem: '<S9>/SPI Master Transfer'
      PIROSNav_B.b_x[3] = 0U;
    }
  } else {
    // MATLABSystem: '<S9>/SPI Master Transfer'
    PIROSNav_B.b_x[3] = MAX_uint16_T;
  }

  PIROSNav_B.SquareRoot = rt_roundf_snf(PIROSNav_P.Constant3_Value);
  if (PIROSNav_B.SquareRoot < 65536.0F) {
    if (PIROSNav_B.SquareRoot >= 0.0F) {
      // MATLABSystem: '<S9>/SPI Master Transfer'
      PIROSNav_B.b_x[4] = static_cast<uint16_T>(PIROSNav_B.SquareRoot);
    } else {
      // MATLABSystem: '<S9>/SPI Master Transfer'
      PIROSNav_B.b_x[4] = 0U;
    }
  } else {
    // MATLABSystem: '<S9>/SPI Master Transfer'
    PIROSNav_B.b_x[4] = MAX_uint16_T;
  }

  PIROSNav_B.SquareRoot = rt_roundf_snf(PIROSNav_P.Constant1_Value_d);
  if (PIROSNav_B.SquareRoot < 65536.0F) {
    if (PIROSNav_B.SquareRoot >= 0.0F) {
      // MATLABSystem: '<S9>/SPI Master Transfer'
      PIROSNav_B.b_x[5] = static_cast<uint16_T>(PIROSNav_B.SquareRoot);
    } else {
      // MATLABSystem: '<S9>/SPI Master Transfer'
      PIROSNav_B.b_x[5] = 0U;
    }
  } else {
    // MATLABSystem: '<S9>/SPI Master Transfer'
    PIROSNav_B.b_x[5] = MAX_uint16_T;
  }

  PIROSNav_B.SquareRoot = rt_roundf_snf(PIROSNav_P.EndofData_Value);
  if (PIROSNav_B.SquareRoot < 65536.0F) {
    if (PIROSNav_B.SquareRoot >= 0.0F) {
      // MATLABSystem: '<S9>/SPI Master Transfer'
      PIROSNav_B.b_x[6] = static_cast<uint16_T>(PIROSNav_B.SquareRoot);
    } else {
      // MATLABSystem: '<S9>/SPI Master Transfer'
      PIROSNav_B.b_x[6] = 0U;
    }
  } else {
    // MATLABSystem: '<S9>/SPI Master Transfer'
    PIROSNav_B.b_x[6] = MAX_uint16_T;
  }

  // End of DataTypeConversion: '<S9>/Data Type Conversion'

  // MATLABSystem: '<S9>/SPI Master Transfer'
  for (PIROSNav_B.i = 0; PIROSNav_B.i < 7; PIROSNav_B.i++) {
    b_x = PIROSNav_B.b_x[PIROSNav_B.i];
    memcpy((void *)&y[0], (void *)&b_x, (uint32_T)((size_t)2 * sizeof(uint8_T)));
    output_raw[0] = y[1];
    output_raw[1] = y[0];
    memcpy((void *)&y_0, (void *)&output_raw[0], (uint32_T)((size_t)1 * sizeof
            (uint16_T)));
    PIROSNav_B.b_x[PIROSNav_B.i] = y_0;
  }

  memcpy((void *)&PIROSNav_B.wrDataRaw[0], (void *)&PIROSNav_B.b_x[0], (uint32_T)
         ((size_t)14 * sizeof(uint8_T)));
  PIROSNav_B.PinNameLoc = SPI0_CE0;
  MW_SPI_SetSlaveSelect(PIROSNav_DW.obj_n.MW_SPI_HANDLE, PIROSNav_B.PinNameLoc,
                        true);
  PIROSNav_B.ClockModeValue = MW_SPI_MODE_0;
  PIROSNav_B.MsbFirstTransferLoc = MW_SPI_MOST_SIGNIFICANT_BIT_FIRST;
  status = MW_SPI_SetFormat(PIROSNav_DW.obj_n.MW_SPI_HANDLE, 8,
    PIROSNav_B.ClockModeValue, PIROSNav_B.MsbFirstTransferLoc);
  if (status == 0) {
    MW_SPI_MasterWriteRead_8bits(PIROSNav_DW.obj_n.MW_SPI_HANDLE,
      PIROSNav_B.wrDataRaw, PIROSNav_B.rdDataRaw, 14U);
  }

  memcpy((void *)&PIROSNav_B.SPIMasterTransfer[0], (void *)
         &PIROSNav_B.rdDataRaw[0], (uint32_T)((size_t)7 * sizeof(uint16_T)));
  for (PIROSNav_B.i = 0; PIROSNav_B.i < 7; PIROSNav_B.i++) {
    b_x = PIROSNav_B.SPIMasterTransfer[PIROSNav_B.i];
    memcpy((void *)&y[0], (void *)&b_x, (uint32_T)((size_t)2 * sizeof(uint8_T)));
    output_raw[0] = y[1];
    output_raw[1] = y[0];
    memcpy((void *)&y_0, (void *)&output_raw[0], (uint32_T)((size_t)1 * sizeof
            (uint16_T)));
    PIROSNav_B.SPIMasterTransfer[PIROSNav_B.i] = y_0;
  }

  // MATLABSystem: '<S6>/LSM9DS1 IMU Sensor'
  status = 24U;
  memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
          sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(PIROSNav_DW.obj.i2cobj_A_G.MW_I2C_HANDLE, 106U,
    &SwappedDataBytes, 1U, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(PIROSNav_DW.obj.i2cobj_A_G.MW_I2C_HANDLE, 106U,
                      PIROSNav_B.output_raw_f, 6U, false, true);
    memcpy((void *)&PIROSNav_B.b_RegisterValue_c[0], (void *)
           &PIROSNav_B.output_raw_f[0], (uint32_T)((size_t)3 * sizeof(int16_T)));
  } else {
    PIROSNav_B.b_RegisterValue_c[0] = 0;
    PIROSNav_B.b_RegisterValue_c[1] = 0;
    PIROSNav_B.b_RegisterValue_c[2] = 0;
  }

  memcpy(&PIROSNav_B.b[0], &PIROSNav_DW.obj.CalGyroA[0], 9U * sizeof(real_T));
  for (PIROSNav_B.i = 0; PIROSNav_B.i < 3; PIROSNav_B.i++) {
    PIROSNav_B.LSM9DS1IMUSensor_o1[PIROSNav_B.i] = ((PIROSNav_B.b[3 *
      PIROSNav_B.i + 1] * static_cast<real_T>(PIROSNav_B.b_RegisterValue_c[1]) +
      PIROSNav_B.b[3 * PIROSNav_B.i] * static_cast<real_T>
      (PIROSNav_B.b_RegisterValue_c[0])) + PIROSNav_B.b[3 * PIROSNav_B.i + 2] *
      static_cast<real_T>(PIROSNav_B.b_RegisterValue_c[2])) +
      PIROSNav_DW.obj.CalGyroB[PIROSNav_B.i];
  }

  status = 40U;
  memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
          sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(PIROSNav_DW.obj.i2cobj_A_G.MW_I2C_HANDLE, 106U,
    &SwappedDataBytes, 1U, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(PIROSNav_DW.obj.i2cobj_A_G.MW_I2C_HANDLE, 106U,
                      PIROSNav_B.output_raw_f, 6U, false, true);
    memcpy((void *)&PIROSNav_B.b_RegisterValue_c[0], (void *)
           &PIROSNav_B.output_raw_f[0], (uint32_T)((size_t)3 * sizeof(int16_T)));
  } else {
    PIROSNav_B.b_RegisterValue_c[0] = 0;
    PIROSNav_B.b_RegisterValue_c[1] = 0;
    PIROSNav_B.b_RegisterValue_c[2] = 0;
  }

  memcpy(&PIROSNav_B.b[0], &PIROSNav_DW.obj.CalAccelA[0], 9U * sizeof(real_T));
  for (PIROSNav_B.i = 0; PIROSNav_B.i < 3; PIROSNav_B.i++) {
    PIROSNav_B.LSM9DS1IMUSensor_o2[PIROSNav_B.i] = ((PIROSNav_B.b[3 *
      PIROSNav_B.i + 1] * static_cast<real_T>(PIROSNav_B.b_RegisterValue_c[1]) +
      PIROSNav_B.b[3 * PIROSNav_B.i] * static_cast<real_T>
      (PIROSNav_B.b_RegisterValue_c[0])) + PIROSNav_B.b[3 * PIROSNav_B.i + 2] *
      static_cast<real_T>(PIROSNav_B.b_RegisterValue_c[2])) +
      PIROSNav_DW.obj.CalAccelB[PIROSNav_B.i];
  }

  status = 40U;
  memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
          sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(PIROSNav_DW.obj.i2cobj_MAG.MW_I2C_HANDLE, 28U,
    &SwappedDataBytes, 1U, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(PIROSNav_DW.obj.i2cobj_MAG.MW_I2C_HANDLE, 28U,
                      PIROSNav_B.output_raw_f, 6U, false, true);
    memcpy((void *)&PIROSNav_B.b_RegisterValue_c[0], (void *)
           &PIROSNav_B.output_raw_f[0], (uint32_T)((size_t)3 * sizeof(int16_T)));
  } else {
    PIROSNav_B.b_RegisterValue_c[0] = 0;
    PIROSNav_B.b_RegisterValue_c[1] = 0;
    PIROSNav_B.b_RegisterValue_c[2] = 0;
  }

  memcpy(&PIROSNav_B.b[0], &PIROSNav_DW.obj.CalMagA[0], 9U * sizeof(real_T));
  for (PIROSNav_B.i = 0; PIROSNav_B.i < 3; PIROSNav_B.i++) {
    PIROSNav_B.a[PIROSNav_B.i] = ((PIROSNav_B.b[3 * PIROSNav_B.i + 1] *
      static_cast<real_T>(PIROSNav_B.b_RegisterValue_c[1]) + PIROSNav_B.b[3 *
      PIROSNav_B.i] * static_cast<real_T>(PIROSNav_B.b_RegisterValue_c[0])) +
      PIROSNav_B.b[3 * PIROSNav_B.i + 2] * static_cast<real_T>
      (PIROSNav_B.b_RegisterValue_c[2])) + PIROSNav_DW.obj.CalMagB[PIROSNav_B.i];
    PIROSNav_B.LSM9DS1IMUSensor_o1[PIROSNav_B.i] =
      PIROSNav_B.LSM9DS1IMUSensor_o1[PIROSNav_B.i] * 245.0 / 32768.0;
    PIROSNav_B.LSM9DS1IMUSensor_o2[PIROSNav_B.i] =
      PIROSNav_B.LSM9DS1IMUSensor_o2[PIROSNav_B.i] * 2.0 / 32768.0;
  }

  // MATLAB Function: '<S6>/MATLAB Function2'
  PIROSNav_MATLABFunction1(PIROSNav_B.LSM9DS1IMUSensor_o1, &PIROSNav_B.out);

  // MATLABSystem: '<S6>/LPS25H Pressure Sensor'
  status = 171U;
  status = MW_I2C_MasterWrite(PIROSNav_DW.obj_do.MW_I2C_HANDLE, 92U, &status, 1U,
    true, false);
  if (0 == status) {
    MW_I2C_MasterRead(PIROSNav_DW.obj_do.MW_I2C_HANDLE, 92U, output_raw, 2U,
                      false, true);
    memcpy((void *)&y[0], (void *)&output_raw[0], (uint32_T)((size_t)2 * sizeof
            (uint8_T)));
  } else {
    y[0] = 0U;
    y[1] = 0U;
  }

  PIROSNav_DW.obj_do.t_l = y[0];
  PIROSNav_DW.obj_do.t_h = static_cast<int16_T>((y[1] << 8));
  status = 168U;
  status = MW_I2C_MasterWrite(PIROSNav_DW.obj_do.MW_I2C_HANDLE, 92U, &status, 1U,
    true, false);
  if (0 == status) {
    MW_I2C_MasterRead(PIROSNav_DW.obj_do.MW_I2C_HANDLE, 92U, output_raw_0, 3U,
                      false, true);
    memcpy((void *)&b_RegisterValue[0], (void *)&output_raw_0[0], (uint32_T)
           ((size_t)3 * sizeof(uint8_T)));
  } else {
    b_RegisterValue[0] = 0U;
    b_RegisterValue[1] = 0U;
    b_RegisterValue[2] = 0U;
  }

  PIROSNav_DW.obj_do.p_xl = b_RegisterValue[0];
  uLong2MultiWord(static_cast<uint32_T>(b_RegisterValue[1]),
                  &PIROSNav_B.r5.chunks[0U], 2);
  uMultiWordShl(&PIROSNav_B.r5.chunks[0U], 2, 8U, &PIROSNav_B.r4.chunks[0U], 2);
  PIROSNav_DW.obj_do.p_l = uMultiWord2Double(&PIROSNav_B.r4.chunks[0U], 2, 0);
  uLong2MultiWord(static_cast<uint32_T>(b_RegisterValue[2]),
                  &PIROSNav_B.r6.chunks[0U], 2);
  uMultiWordShl(&PIROSNav_B.r6.chunks[0U], 2, 16U, &PIROSNav_B.r5.chunks[0U], 2);
  PIROSNav_DW.obj_do.p_h = uMultiWord2Double(&PIROSNav_B.r5.chunks[0U], 2, 0);
  PIROSNav_B.rtb_Gain1_idx_0 = rt_roundd_snf(PIROSNav_DW.obj_do.p_h);
  if (PIROSNav_B.rtb_Gain1_idx_0 < 1.8446744073709552E+19) {
    if (PIROSNav_B.rtb_Gain1_idx_0 >= 0.0) {
      Double2MultiWord(PIROSNav_B.rtb_Gain1_idx_0, &PIROSNav_B.r.chunks[0U], 2);
    } else {
      PIROSNav_B.r = tmp;
    }
  } else {
    PIROSNav_B.r = tmp_0;
  }

  PIROSNav_B.rtb_Gain1_idx_0 = rt_roundd_snf(PIROSNav_DW.obj_do.p_l);
  if (PIROSNav_B.rtb_Gain1_idx_0 < 1.8446744073709552E+19) {
    if (PIROSNav_B.rtb_Gain1_idx_0 >= 0.0) {
      Double2MultiWord(PIROSNav_B.rtb_Gain1_idx_0, &PIROSNav_B.r2.chunks[0U], 2);
    } else {
      PIROSNav_B.r2 = tmp;
    }
  } else {
    PIROSNav_B.r2 = tmp_0;
  }

  PIROSNav_B.rtb_Gain1_idx_0 = rt_roundd_snf(PIROSNav_DW.obj_do.p_xl);
  if (PIROSNav_B.rtb_Gain1_idx_0 < 1.8446744073709552E+19) {
    if (PIROSNav_B.rtb_Gain1_idx_0 >= 0.0) {
      Double2MultiWord(PIROSNav_B.rtb_Gain1_idx_0, &PIROSNav_B.r3.chunks[0U], 2);
    } else {
      PIROSNav_B.r3 = tmp;
    }
  } else {
    PIROSNav_B.r3 = tmp_0;
  }

  MultiWordIor(&PIROSNav_B.r2.chunks[0U], &PIROSNav_B.r3.chunks[0U],
               &PIROSNav_B.r6.chunks[0U], 2);
  PIROSNav_B.rtb_Gain1_idx_0 = rt_roundd_snf(uMultiWord2Double
    (&PIROSNav_B.r6.chunks[0U], 2, 0));
  if (PIROSNav_B.rtb_Gain1_idx_0 < 1.8446744073709552E+19) {
    if (PIROSNav_B.rtb_Gain1_idx_0 >= 0.0) {
      Double2MultiWord(PIROSNav_B.rtb_Gain1_idx_0, &PIROSNav_B.r1.chunks[0U], 2);
    } else {
      PIROSNav_B.r1 = tmp;
    }
  } else {
    PIROSNav_B.r1 = tmp_0;
  }

  MultiWordIor(&PIROSNav_B.r.chunks[0U], &PIROSNav_B.r1.chunks[0U],
               &PIROSNav_B.r7.chunks[0U], 2);
  PIROSNav_B.LPS25HPressureSensor_o1 = uMultiWord2Double(&PIROSNav_B.r7.chunks
    [0U], 2, 0) / 4096.0;
  PIROSNav_B.LPS25HPressureSensor_o2 = static_cast<real_T>
    ((PIROSNav_DW.obj_do.t_h | PIROSNav_DW.obj_do.t_l)) / 480.0 + 42.5;

  // End of MATLABSystem: '<S6>/LPS25H Pressure Sensor'

  // MATLAB Function: '<S6>/MATLAB Function1'
  PIROSNav_MATLABFunction1(PIROSNav_B.LSM9DS1IMUSensor_o2, &PIROSNav_B.out_p);

  // MATLAB Function: '<S6>/MATLAB Function'
  PIROSNav_B.FUSE.MagnetometerNoise = 0.1;
  PIROSNav_B.FUSE.MagneticDisturbanceNoise = 0.5;
  PIROSNav_B.FUSE.MagneticDisturbanceDecayFactor = 0.5;
  PIROSNav_B.FUSE.ExpectedMagneticFieldStrength = 50.0;
  PIROSNav_B.FUSE.AccelerometerNoise = 0.0001924722;
  PIROSNav_B.FUSE.GyroscopeNoise = 9.1385E-5;
  PIROSNav_B.FUSE.GyroscopeDriftNoise = 3.0462E-13;
  PIROSNav_B.FUSE.LinearAccelerationNoise = 0.0096236100000000012;
  PIROSNav_B.FUSE.LinearAccelerationDecayFactor = 0.5;
  PIROSNav_B.FUSE.isInitialized = 1;
  PIROSNav_B.FUSE.pInputPrototype[0] = PIROSNav_B.LSM9DS1IMUSensor_o2[0];
  PIROSNav_B.FUSE.pInputPrototype[1] = PIROSNav_B.LSM9DS1IMUSensor_o2[1];
  PIROSNav_B.FUSE.pInputPrototype[2] = PIROSNav_B.LSM9DS1IMUSensor_o2[2];
  PIROSNav_B.FUSE.pSensorPeriod = 0.01;
  PIROSNav_B.FUSE.pKalmanPeriod = 0.01;
  PIROSNav_B.FUSE.pRefSys = &PIROSNav_B.lobj_1;
  PIROSNav_B.FUSE.TunablePropsChanged = false;
  PIROSNav_B.FUSE.pOrientPost.a = 1.0;
  PIROSNav_B.FUSE.pOrientPost.b = 0.0;
  PIROSNav_B.FUSE.pOrientPost.c = 0.0;
  PIROSNav_B.FUSE.pOrientPost.d = 0.0;
  PIROSNav_B.FUSE.pGyroOffset[0] = 0.0;
  PIROSNav_B.FUSE.pGyroOffset[1] = 0.0;
  PIROSNav_B.FUSE.pMagVec[1] = 0.0;
  PIROSNav_B.FUSE.pGyroOffset[2] = 0.0;
  PIROSNav_B.FUSE.pMagVec[2] = 0.0;
  PIROSNav_B.FUSE.pMagVec[0] = 50.0;
  memset(&PIROSNav_B.y[0], 0, 36U * sizeof(real_T));
  for (PIROSNav_B.i = 0; PIROSNav_B.i < 9; PIROSNav_B.i++) {
    PIROSNav_B.b[PIROSNav_B.i] = b[PIROSNav_B.i];
  }

  for (PIROSNav_B.i = 0; PIROSNav_B.i < 3; PIROSNav_B.i++) {
    PIROSNav_B.rtb_Gain1_idx_0 = PIROSNav_B.b[3 * PIROSNav_B.i];
    PIROSNav_B.y[6 * PIROSNav_B.i] = 0.00981609133850003 *
      PIROSNav_B.rtb_Gain1_idx_0;
    PIROSNav_B.y_tmp = 6 * (PIROSNav_B.i + 3);
    PIROSNav_B.y[PIROSNav_B.y_tmp + 3] = 0.6000000091385 *
      PIROSNav_B.rtb_Gain1_idx_0;
    PIROSNav_B.rtb_Gain1_idx_0 = PIROSNav_B.b[3 * PIROSNav_B.i + 1];
    PIROSNav_B.y[6 * PIROSNav_B.i + 1] = 0.00981609133850003 *
      PIROSNav_B.rtb_Gain1_idx_0;
    PIROSNav_B.y[PIROSNav_B.y_tmp + 4] = 0.6000000091385 *
      PIROSNav_B.rtb_Gain1_idx_0;
    PIROSNav_B.rtb_Gain1_idx_0 = PIROSNav_B.b[3 * PIROSNav_B.i + 2];
    PIROSNav_B.y[6 * PIROSNav_B.i + 2] = 0.00981609133850003 *
      PIROSNav_B.rtb_Gain1_idx_0;
    PIROSNav_B.y[PIROSNav_B.y_tmp + 5] = 0.6000000091385 *
      PIROSNav_B.rtb_Gain1_idx_0;
  }

  memcpy(&PIROSNav_B.FUSE.pQv[0], &PIROSNav_B.y[0], 36U * sizeof(real_T));
  memcpy(&PIROSNav_B.FUSE.pQw[0], &c[0], 144U * sizeof(real_T));
  PIROSNav_B.FUSE.pFirstTime = true;
  PIROSNav_B.FUSE.pLinAccelPost[0] = 0.0;

  // MATLABSystem: '<S6>/LSM9DS1 IMU Sensor'
  PIROSNav_B.a_k[0] = PIROSNav_B.a[0] * 4.0 / 32768.0;

  // MATLAB Function: '<S6>/MATLAB Function'
  PIROSNav_B.FUSE.pLinAccelPost[1] = 0.0;

  // MATLABSystem: '<S6>/LSM9DS1 IMU Sensor'
  PIROSNav_B.a_k[1] = PIROSNav_B.a[1] * 4.0 / 32768.0;

  // MATLAB Function: '<S6>/MATLAB Function'
  PIROSNav_B.FUSE.pLinAccelPost[2] = 0.0;

  // MATLABSystem: '<S6>/LSM9DS1 IMU Sensor'
  PIROSNav_B.a_k[2] = PIROSNav_B.a[2] * 4.0 / 32768.0;

  // MATLAB Function: '<S6>/MATLAB Function'
  PIROSNa_AHRSFilterBase_stepImpl(&PIROSNav_B.FUSE,
    PIROSNav_B.LSM9DS1IMUSensor_o2, PIROSNav_B.LSM9DS1IMUSensor_o1,
    PIROSNav_B.a_k, &PIROSNav_B.orientation_a, &PIROSNav_B.rtb_Gain1_idx_0,
    &PIROSNav_B.rtb_Gain1_idx_1, &PIROSNav_B.orientation_d);
  PIROSNav_B.n = sqrt(((PIROSNav_B.orientation_a * PIROSNav_B.orientation_a +
                        PIROSNav_B.rtb_Gain1_idx_0 * PIROSNav_B.rtb_Gain1_idx_0)
                       + PIROSNav_B.rtb_Gain1_idx_1 * PIROSNav_B.rtb_Gain1_idx_1)
                      + PIROSNav_B.orientation_d * PIROSNav_B.orientation_d);
  PIROSNav_B.orientation_a /= PIROSNav_B.n;
  PIROSNav_B.orientation_d /= PIROSNav_B.n;
  PIROSNav_B.orientation2 = rt_atan2d_snf(PIROSNav_B.rtb_Gain1_idx_0 /
    PIROSNav_B.n * PIROSNav_B.orientation_a * 2.0 + PIROSNav_B.rtb_Gain1_idx_1 /
    PIROSNav_B.n * PIROSNav_B.orientation_d * 2.0, (PIROSNav_B.orientation_a *
    PIROSNav_B.orientation_a * 2.0 - 1.0) + PIROSNav_B.orientation_d *
    PIROSNav_B.orientation_d * 2.0) * 57.295779513082323;

  // MATLABSystem: '<S6>/HTS221 Humidity Sensor'
  status = 170U;
  status = MW_I2C_MasterWrite(PIROSNav_DW.obj_d.MW_I2C_HANDLE, 95U, &status, 1U,
    true, false);
  if (0 == status) {
    MW_I2C_MasterRead(PIROSNav_DW.obj_d.MW_I2C_HANDLE, 95U, output_raw, 2U,
                      false, true);
    memcpy((void *)&y[0], (void *)&output_raw[0], (uint32_T)((size_t)2 * sizeof
            (uint8_T)));
  } else {
    y[0] = 0U;
    y[1] = 0U;
  }

  memcpy((void *)&y_1, (void *)&y[0], (uint32_T)((size_t)1 * sizeof(int16_T)));
  status = 168U;
  status = MW_I2C_MasterWrite(PIROSNav_DW.obj_d.MW_I2C_HANDLE, 95U, &status, 1U,
    true, false);
  if (0 == status) {
    MW_I2C_MasterRead(PIROSNav_DW.obj_d.MW_I2C_HANDLE, 95U, output_raw, 2U,
                      false, true);
    memcpy((void *)&y[0], (void *)&output_raw[0], (uint32_T)((size_t)2 * sizeof
            (uint8_T)));
  } else {
    y[0] = 0U;
    y[1] = 0U;
  }

  memcpy((void *)&y_2, (void *)&y[0], (uint32_T)((size_t)1 * sizeof(int16_T)));
  PIROSNav_B.HTS221HumiditySensor_o1 = (static_cast<real_T>(y_2) -
    PIROSNav_DW.obj_d.H0_T0_out) / (PIROSNav_DW.obj_d.H1_T0_out -
    PIROSNav_DW.obj_d.H0_T0_out) * (PIROSNav_DW.obj_d.H1_rh -
    PIROSNav_DW.obj_d.H0_rh) + PIROSNav_DW.obj_d.H0_rh;
  PIROSNav_B.HTS221HumiditySensor_o2 = (static_cast<real_T>(y_1) -
    PIROSNav_DW.obj_d.T0_out) / (PIROSNav_DW.obj_d.T1_out -
    PIROSNav_DW.obj_d.T0_out) * (PIROSNav_DW.obj_d.T1_degC -
    PIROSNav_DW.obj_d.T0_degC) + PIROSNav_DW.obj_d.T0_degC;

  // End of MATLABSystem: '<S6>/HTS221 Humidity Sensor'

  // External mode
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, (real_T)PIROSNav_M->Timing.taskTime0);

  // signal main to stop simulation
  {                                    // Sample time: [0.1s, 0.0s]
    if ((rtmGetTFinal(PIROSNav_M)!=-1) &&
        !((rtmGetTFinal(PIROSNav_M)-PIROSNav_M->Timing.taskTime0) >
          PIROSNav_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(PIROSNav_M, "Simulation finished");
    }

    if (rtmGetStopRequested(PIROSNav_M)) {
      rtmSetErrorStatus(PIROSNav_M, "Simulation finished");
    }
  }

  // Update absolute time
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  PIROSNav_M->Timing.taskTime0 =
    (++PIROSNav_M->Timing.clockTick0) * PIROSNav_M->Timing.stepSize0;
}

// Model step function for TID1
void PIROSNav_step1(void)              // Sample time: [1.0s, 0.0s]
{
  // UnitDelay: '<S2>/Output'
  PIROSNav_B.Output = PIROSNav_DW.Output_DSTATE;

  // Sum: '<S10>/FixPt Sum1' incorporates:
  //   Constant: '<S10>/FixPt Constant'

  PIROSNav_DW.Output_DSTATE = static_cast<uint8_T>((static_cast<uint32_T>
    (PIROSNav_B.Output) + PIROSNav_P.FixPtConstant_Value));

  // Switch: '<S11>/FixPt Switch' incorporates:
  //   Constant: '<S11>/Constant'
  //   UnitDelay: '<S2>/Output'

  if (PIROSNav_DW.Output_DSTATE > PIROSNav_P.CounterLimited_uplimit) {
    PIROSNav_DW.Output_DSTATE = PIROSNav_P.Constant_Value_i;
  }

  // End of Switch: '<S11>/FixPt Switch'
  rtExtModeUpload(1, (real_T)((PIROSNav_M->Timing.clockTick1) * 1.0));

  // Update absolute time
  // The "clockTick1" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 1.0, which is the step size
  //  of the task. Size of "clockTick1" ensures timer will not overflow during the
  //  application lifespan selected.

  PIROSNav_M->Timing.clockTick1++;
}

// Model step wrapper function for compatibility with a static main program
void PIROSNav_step(int_T tid)
{
  switch (tid) {
   case 0 :
    PIROSNav_step0();
    break;

   case 1 :
    PIROSNav_step1();
    break;

   default :
    break;
  }
}

// Model initialize function
void PIROSNav_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(PIROSNav_M, -1);
  PIROSNav_M->Timing.stepSize0 = 0.1;

  // External mode info
  PIROSNav_M->Sizes.checksums[0] = (1128778858U);
  PIROSNav_M->Sizes.checksums[1] = (1695137512U);
  PIROSNav_M->Sizes.checksums[2] = (1054139331U);
  PIROSNav_M->Sizes.checksums[3] = (3993120574U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[24];
    PIROSNav_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = (sysRanDType *)&PIROSNav_DW.GetRosMessage_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&PIROSNav_DW.GetRosMessage1_SubsysRanBC;
    systemRan[9] = (sysRanDType *)&PIROSNav_DW.GetRosMessage1_SubsysRanBC;
    systemRan[10] = (sysRanDType *)&PIROSNav_DW.GetRosMessage1_SubsysRanBC;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = (sysRanDType *)&PIROSNav_DW.EnabledSubsystem_SubsysRanBC_b;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = (sysRanDType *)&PIROSNav_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PIROSNav_M->extModeInfo,
      &PIROSNav_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PIROSNav_M->extModeInfo, PIROSNav_M->Sizes.checksums);
    rteiSetTPtr(PIROSNav_M->extModeInfo, rtmGetTPtr(PIROSNav_M));
  }

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    PIROSNav_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 25;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;

    // Parameters transition table
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_raspi_internal_SP_T *obj;
    uint32_T SSPinNameLoc;
    uint32_T MOSIPinLoc;
    uint32_T MISOPinLoc;
    uint32_T SCKPinLoc;
    int32_T i;
    static const char_T tmp[15] = { '/', 'X', 'b', 'o', 'x', 'C', 'o', 'n', 't',
      'r', 'o', 'l', 'l', 'e', 'r' };

    static const char_T tmp_0[16] = { '/', 'p', 'l', 'a', 'n', 'n', 'e', 'r',
      '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    // Start for Atomic SubSystem: '<Root>/Subscribe1'
    // Start for MATLABSystem: '<S8>/SourceBlock'
    PIROSNav_DW.obj_j.matlabCodegenIsDeleted = false;
    PIROSNav_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      PIROSNav_B.cv1[i] = tmp[i];
    }

    PIROSNav_B.cv1[15] = '\x00';
    Sub_PIROSNav_110.createSubscriber(PIROSNav_B.cv1, 1);
    PIROSNav_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Subscribe1'

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S7>/SourceBlock'
    PIROSNav_DW.obj_no.matlabCodegenIsDeleted = false;
    PIROSNav_DW.obj_no.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      PIROSNav_B.cv[i] = tmp_0[i];
    }

    PIROSNav_B.cv[16] = '\x00';
    Sub_PIROSNav_21.createSubscriber(PIROSNav_B.cv, 1);
    PIROSNav_DW.obj_no.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // Start for MATLABSystem: '<S9>/SPI Master Transfer'
    PIROSNav_DW.obj_n.matlabCodegenIsDeleted = true;
    PIROSNav_DW.obj_n.isInitialized = 0;
    PIROSNav_DW.obj_n.matlabCodegenIsDeleted = false;
    obj = &PIROSNav_DW.obj_n;
    PIROSNav_DW.obj_n.isSetupComplete = false;
    PIROSNav_DW.obj_n.isInitialized = 1;
    SSPinNameLoc = SPI0_CE0;
    MOSIPinLoc = MW_UNDEFINED_VALUE;
    MISOPinLoc = MW_UNDEFINED_VALUE;
    SCKPinLoc = MW_UNDEFINED_VALUE;
    obj->MW_SPI_HANDLE = MW_SPI_Open(0U, MOSIPinLoc, MISOPinLoc, SCKPinLoc,
      SSPinNameLoc, true, 0);
    MW_SPI_SetBusSpeed(PIROSNav_DW.obj_n.MW_SPI_HANDLE, 500000U);
    PIROSNav_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<S6>/LSM9DS1 IMU Sensor'
    PIROSNav_DW.obj.i2cobj_A_G.matlabCodegenIsDeleted = true;
    PIROSNav_DW.obj.i2cobj_MAG.matlabCodegenIsDeleted = true;
    PIROSNav_DW.obj.matlabCodegenIsDeleted = true;
    PIROS_lsm9ds1Block_lsm9ds1Block(&PIROSNav_DW.obj);
    PIROSNav_DW.obj.isSetupComplete = false;
    PIROSNav_DW.obj.isInitialized = 1;
    PIROSNav_lsm9ds1Block_setupImpl(&PIROSNav_DW.obj);
    PIROSNav_DW.obj.isSetupComplete = true;

    // Start for MATLABSystem: '<S6>/LPS25H Pressure Sensor'
    PIROSNav_DW.obj_do.CTRL_REG1_Value = 128.0;
    PIROSNav_DW.obj_do.isInitialized = 0;
    PIROSNav_DW.obj_do.matlabCodegenIsDeleted = false;
    PIROSNav_SystemCore_setup_i(&PIROSNav_DW.obj_do);

    // Start for MATLABSystem: '<S6>/HTS221 Humidity Sensor'
    PIROSNav_DW.obj_d.isInitialized = 0;
    PIROSNav_DW.obj_d.matlabCodegenIsDeleted = false;
    PIROSNav_SystemCore_setup(&PIROSNav_DW.obj_d);

    // InitializeConditions for UnitDelay: '<S2>/Output'
    PIROSNav_DW.Output_DSTATE = PIROSNav_P.Output_InitialCondition;

    // SystemInitialize for Enabled SubSystem: '<Root>/GetRosMessage'
    // SystemInitialize for Outport: '<S4>/Lx'
    PIROSNav_B.DataTypeConversion1 = PIROSNav_P.Lx_Y0;

    // SystemInitialize for Outport: '<S4>/Ly '
    PIROSNav_B.DataTypeConversion3 = PIROSNav_P.Ly_Y0;

    // SystemInitialize for Outport: '<S4>/Lz'
    PIROSNav_B.DataTypeConversion4 = PIROSNav_P.Lz_Y0;

    // SystemInitialize for Outport: '<S4>/Ax'
    PIROSNav_B.DataTypeConversion5 = PIROSNav_P.Ax_Y0;

    // SystemInitialize for Outport: '<S4>/Ay '
    PIROSNav_B.DataTypeConversion6 = PIROSNav_P.Ay_Y0;

    // SystemInitialize for Outport: '<S4>/Az '
    PIROSNav_B.DataTypeConversion2 = PIROSNav_P.Az_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/GetRosMessage'

    // SystemInitialize for Enabled SubSystem: '<Root>/GetRosMessage1'
    // SystemInitialize for Outport: '<S5>/LeftRightL'
    PIROSNav_B.uDLookupTable1_b[0] = PIROSNav_P.LeftRightL_Y0;

    // SystemInitialize for Outport: '<S5>/UpDownL'
    PIROSNav_B.OutportBufferForUpDownL = PIROSNav_P.UpDownL_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/GetRosMessage1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S18>/Out1'
    PIROSNav_B.In1_h = PIROSNav_P.Out1_Y0_a;

    // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S19>/Out1'
    PIROSNav_B.In1 = PIROSNav_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'
  }
}

// Model terminate function
void PIROSNav_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  matlabCodegenHandle_matla_imdcl(&PIROSNav_DW.obj_j);

  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  matlabCodegenHandle_matla_imdcl(&PIROSNav_DW.obj_no);

  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for MATLABSystem: '<S9>/SPI Master Transfer'
  matlabCodegenHandle_mat_imdcl2f(&PIROSNav_DW.obj_n);

  // Terminate for MATLABSystem: '<S6>/LSM9DS1 IMU Sensor'
  matlabCodegenHandle_matlabCo_im(&PIROSNav_DW.obj);
  matlabCodegenHandle_matlab_imdc(&PIROSNav_DW.obj.i2cobj_MAG);
  matlabCodegenHandle_matlabC_imd(&PIROSNav_DW.obj.i2cobj_A_G);

  // Terminate for MATLABSystem: '<S6>/LPS25H Pressure Sensor'
  matlabCodegenHandle_matlabCod_i(&PIROSNav_DW.obj_do);

  // Terminate for MATLABSystem: '<S6>/HTS221 Humidity Sensor'
  matlabCodegenHandle_matlabCodeg(&PIROSNav_DW.obj_d);
}

//
// File trailer for generated code.
//
// [EOF]
//
