//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: multiword_types.h
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

#ifndef MULTIWORD_TYPES_H
#define MULTIWORD_TYPES_H
#include "rtwtypes.h"

//
//  Definitions supporting external data access
typedef int32_T chunk_T;
typedef uint32_T uchunk_T;

//
//  MultiWord supporting definitions
typedef long int long_T;

//
//  MultiWord types
typedef struct {
  uint32_T chunks[2];
} int64m_T;

typedef struct {
  int64m_T re;
  int64m_T im;
} cint64m_T;

typedef struct {
  uint32_T chunks[2];
} uint64m_T;

typedef struct {
  uint64m_T re;
  uint64m_T im;
} cuint64m_T;

#endif                                 // MULTIWORD_TYPES_H

//
// File trailer for generated code.
//
// [EOF]
//
