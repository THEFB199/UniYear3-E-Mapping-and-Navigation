//
//  PIROSNav_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "PIROSNav".
//
//  Model version              : 1.62
//  Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
//  C++ source code generated on : Fri Feb  7 11:21:02 2020
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
  sizeof(SL_Bus_PIROSNav_geometry_msgs_Vector3),
  sizeof(SL_Bus_PIROSNav_geometry_msgs_Twist),
  sizeof(SL_Bus_ROSVariableLengthArrayInfo),
  sizeof(SL_Bus_PIROSNav_ros_time_Time),
  sizeof(SL_Bus_PIROSNav_std_msgs_Header),
  sizeof(SL_Bus_PIROSNav_sensor_msgs_Joy),
  sizeof(raspi_internal_hts221Block_PI_T),
  sizeof(raspi_internal_lps25hBlock_PI_T),
  sizeof(raspi_internal_lsm9ds1Block_P_T),
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
  "SL_Bus_PIROSNav_geometry_msgs_Vector3",
  "SL_Bus_PIROSNav_geometry_msgs_Twist",
  "SL_Bus_ROSVariableLengthArrayInfo",
  "SL_Bus_PIROSNav_ros_time_Time",
  "SL_Bus_PIROSNav_std_msgs_Header",
  "SL_Bus_PIROSNav_sensor_msgs_Joy",
  "raspi_internal_hts221Block_PI_T",
  "raspi_internal_lps25hBlock_PI_T",
  "raspi_internal_lsm9ds1Block_P_T",
  "ros_slros_internal_block_Subs_T",
  "codertarget_raspi_internal_SP_T"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&PIROSNav_B.In1), 19, 0, 1 },

  { (char_T *)(&PIROSNav_B.In1_h), 15, 0, 1 },

  { (char_T *)(&PIROSNav_B.out), 0, 0, 7 },

  { (char_T *)(&PIROSNav_B.uDLookupTable9), 1, 0, 13 },

  { (char_T *)(&PIROSNav_B.SPIMasterTransfer[0]), 5, 0, 7 },

  { (char_T *)(&PIROSNav_B.Output), 3, 0, 1 },

  { (char_T *)(&PIROSNav_B.SourceBlock_o1), 8, 0, 2 }
  ,

  { (char_T *)(&PIROSNav_DW.obj), 22, 0, 1 },

  { (char_T *)(&PIROSNav_DW.obj_d), 20, 0, 1 },

  { (char_T *)(&PIROSNav_DW.obj_do), 21, 0, 1 },

  { (char_T *)(&PIROSNav_DW.obj_n), 24, 0, 1 },

  { (char_T *)(&PIROSNav_DW.obj_j), 23, 0, 2 },

  { (char_T *)(&PIROSNav_DW.Output_DSTATE), 3, 0, 1 },

  { (char_T *)(&PIROSNav_DW.EnabledSubsystem_SubsysRanBC), 2, 0, 4 }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  14U,
  rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&PIROSNav_P.CounterLimited_uplimit), 3, 0, 1 },

  { (char_T *)(&PIROSNav_P.Out1_Y0), 19, 0, 1 },

  { (char_T *)(&PIROSNav_P.Constant_Value), 19, 0, 1 },

  { (char_T *)(&PIROSNav_P.Out1_Y0_a), 15, 0, 1 },

  { (char_T *)(&PIROSNav_P.Constant_Value_h), 15, 0, 1 },

  { (char_T *)(&PIROSNav_P.Constant1_Value), 0, 0, 13 },

  { (char_T *)(&PIROSNav_P.Constant2_Value_d), 1, 0, 42 },

  { (char_T *)(&PIROSNav_P.Constant_Value_i), 3, 0, 4 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
  8U,
  rtPTransitions
};

// [EOF] PIROSNav_dt.h
