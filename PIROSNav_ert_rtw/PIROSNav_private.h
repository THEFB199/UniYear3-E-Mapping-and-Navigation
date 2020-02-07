//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PIROSNav_private.h
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
#ifndef RTW_HEADER_PIROSNav_private_h_
#define RTW_HEADER_PIROSNav_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "PIROSNav.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

extern real32_T rt_roundf_snf(real32_T u);
extern real_T rt_roundd_snf(real_T u);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real32_T look1_tf_binlcpw(real_T u0, const real_T bp0[], const real32_T
  table[], uint32_T maxIndex);
extern real32_T look1_iflf_binlxpw(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex);
extern real_T uMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1);
extern void uMultiWordShl(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T
  y[], int32_T n);
extern void uLong2MultiWord(uint32_T u, uint32_T y[], int32_T n);
extern void Double2MultiWord(real_T u1, uint32_T y[], int32_T n);
extern void MultiWordIor(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
  int32_T n);
extern int32_T div_s32(int32_T numerator, int32_T denominator);
extern void PIROSNav_MATLABFunction1(const real_T rtu_a[3], real_T *rty_out);
extern void PIROSNav_step0(void);
extern void PIROSNav_step1(void);

#endif                                 // RTW_HEADER_PIROSNav_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
