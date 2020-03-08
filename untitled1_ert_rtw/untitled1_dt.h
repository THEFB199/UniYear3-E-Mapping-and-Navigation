//
//  untitled1_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "untitled1".
//
//  Model version              : 1.0
//  Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
//  C++ source code generated on : Tue Feb 25 12:27:41 2020
//
//  Target selection: ert.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex
//  Code generation objectives: Unspecified
//  Validation result: Not run


#include "ext_types.h"

// data type size table
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(codertarget_linux_blocks_SDLV_T)
};

// data type name table
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "codertarget_linux_blocks_SDLV_T"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&untitled1_B.V4L2VideoCapture_o1[0]), 3, 0, 480000 },

  { (char_T *)(&untitled1_B.V4L2VideoCapture_o2[0]), 3, 0, 480000 },

  { (char_T *)(&untitled1_B.Output), 3, 0, 1 }
  ,

  { (char_T *)(&untitled1_DW.obj), 14, 0, 1 },

  { (char_T *)(&untitled1_DW.Output_DSTATE), 3, 0, 1 }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&untitled1_P.CounterLimited_uplimit), 3, 0, 4 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

// [EOF] untitled1_dt.h
