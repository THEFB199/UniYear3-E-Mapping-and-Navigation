//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PI_UDP_Recieve_private.h
//
// Code generated for Simulink model 'PI_UDP_Recieve'.
//
// Model version                  : 1.42
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Wed Feb  5 14:14:41 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_PI_UDP_Recieve_private_h_
#define RTW_HEADER_PI_UDP_Recieve_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "PI_UDP_Recieve.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

extern real32_T rt_roundf_snf(real32_T u);
extern real32_T look1_iflf_binlcpw(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex);
extern void PI_UDP_Recieve_step0(void);
extern void PI_UDP_Recieve_step1(void);
extern void PI_UDP_Recieve_step2(void);

#endif                                 // RTW_HEADER_PI_UDP_Recieve_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
