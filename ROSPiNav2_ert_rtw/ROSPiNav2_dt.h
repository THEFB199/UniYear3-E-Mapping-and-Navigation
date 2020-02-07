//
//  ROSPiNav2_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "ROSPiNav2".
//
//  Model version              : 1.2
//  Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
//  C++ source code generated on : Fri Feb  7 14:00:01 2020
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
  sizeof(SL_Bus_ROSPiNav2_geometry_msgs_Vector3),
  sizeof(SL_Bus_ROSPiNav2_geometry_msgs_Twist),
  sizeof(SL_Bus_ROSVariableLengthArrayInfo),
  sizeof(SL_Bus_ROSPiNav2_ros_time_Time),
  sizeof(SL_Bus_ROSPiNav2_std_msgs_Header),
  sizeof(SL_Bus_ROSPiNav2_sensor_msgs_Joy),
  sizeof(ros_slros_internal_block_Subs_T),
  sizeof(codertarget_raspi_internal_SP_T)
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
  "SL_Bus_ROSPiNav2_geometry_msgs_Vector3",
  "SL_Bus_ROSPiNav2_geometry_msgs_Twist",
  "SL_Bus_ROSVariableLengthArrayInfo",
  "SL_Bus_ROSPiNav2_ros_time_Time",
  "SL_Bus_ROSPiNav2_std_msgs_Header",
  "SL_Bus_ROSPiNav2_sensor_msgs_Joy",
  "ros_slros_internal_block_Subs_T",
  "codertarget_raspi_internal_SP_T"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&ROSPiNav2_B.In1), 19, 0, 1 },

  { (char_T *)(&ROSPiNav2_B.In1_l), 15, 0, 1 },

  { (char_T *)(&ROSPiNav2_B.uDLookupTable9), 1, 0, 13 },

  { (char_T *)(&ROSPiNav2_B.SPIMasterTransfer[0]), 5, 0, 7 },

  { (char_T *)(&ROSPiNav2_B.Output), 3, 0, 1 },

  { (char_T *)(&ROSPiNav2_B.SourceBlock_o1), 8, 0, 2 }
  ,

  { (char_T *)(&ROSPiNav2_DW.obj), 21, 0, 1 },

  { (char_T *)(&ROSPiNav2_DW.obj_l), 20, 0, 2 },

  { (char_T *)(&ROSPiNav2_DW.Output_DSTATE), 3, 0, 1 },

  { (char_T *)(&ROSPiNav2_DW.EnabledSubsystem_SubsysRanBC), 2, 0, 4 }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  10U,
  rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&ROSPiNav2_P.CounterLimited_uplimit), 3, 0, 1 },

  { (char_T *)(&ROSPiNav2_P.Out1_Y0), 19, 0, 1 },

  { (char_T *)(&ROSPiNav2_P.Constant_Value), 19, 0, 1 },

  { (char_T *)(&ROSPiNav2_P.Out1_Y0_d), 15, 0, 1 },

  { (char_T *)(&ROSPiNav2_P.Constant_Value_j), 15, 0, 1 },

  { (char_T *)(&ROSPiNav2_P.Constant2_Value), 1, 0, 51 },

  { (char_T *)(&ROSPiNav2_P.Constant_Value_a), 3, 0, 4 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

// [EOF] ROSPiNav2_dt.h
