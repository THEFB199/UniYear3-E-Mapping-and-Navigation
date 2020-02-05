//
//  PIROSNavRec_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "PIROSNavRec".
//
//  Model version              : 1.11
//  Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
//  C++ source code generated on : Wed Feb  5 17:15:48 2020
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
  sizeof(SL_Bus_PIROSNavRec_geometry_msgs_Vector3),
  sizeof(SL_Bus_PIROSNavRec_geometry_msgs_Twist),
  sizeof(codertarget_raspi_internal_SP_T),
  sizeof(ros_slros_internal_block_Subs_T)
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
  "SL_Bus_PIROSNavRec_geometry_msgs_Vector3",
  "SL_Bus_PIROSNavRec_geometry_msgs_Twist",
  "codertarget_raspi_internal_SP_T",
  "ros_slros_internal_block_Subs_T"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&PIROSNavRec_B.In1), 15, 0, 1 },

  { (char_T *)(&PIROSNavRec_B.DataTypeConversion1), 1, 0, 6 },

  { (char_T *)(&PIROSNavRec_B.SPIMasterTransfer[0]), 5, 0, 7 },

  { (char_T *)(&PIROSNavRec_B.Output), 3, 0, 1 },

  { (char_T *)(&PIROSNavRec_B.SourceBlock_o1), 8, 0, 1 }
  ,

  { (char_T *)(&PIROSNavRec_DW.obj), 16, 0, 1 },

  { (char_T *)(&PIROSNavRec_DW.obj_n), 17, 0, 1 },

  { (char_T *)(&PIROSNavRec_DW.Output_DSTATE), 3, 0, 1 },

  { (char_T *)(&PIROSNavRec_DW.EnabledSubsystem_SubsysRanBC), 2, 0, 2 }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&PIROSNavRec_P.CounterLimited_uplimit), 3, 0, 1 },

  { (char_T *)(&PIROSNavRec_P.Out1_Y0), 15, 0, 1 },

  { (char_T *)(&PIROSNavRec_P.Constant_Value), 15, 0, 1 },

  { (char_T *)(&PIROSNavRec_P.Gain8_Gain), 1, 0, 34 },

  { (char_T *)(&PIROSNavRec_P.Constant_Value_i), 3, 0, 4 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

// [EOF] PIROSNavRec_dt.h
