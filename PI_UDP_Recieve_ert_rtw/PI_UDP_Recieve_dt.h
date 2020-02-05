//
//  PI_UDP_Recieve_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "PI_UDP_Recieve".
//
//  Model version              : 1.42
//  Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
//  C++ source code generated on : Wed Feb  5 14:14:41 2020
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
  sizeof(SL_Bus_PI_UDP_Recieve_geometry_msgs_Vector3),
  sizeof(SL_Bus_PI_UDP_Recieve_geometry_msgs_Twist),
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
  "SL_Bus_PI_UDP_Recieve_geometry_msgs_Vector3",
  "SL_Bus_PI_UDP_Recieve_geometry_msgs_Twist",
  "codertarget_raspi_internal_SP_T",
  "ros_slros_internal_block_Subs_T"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&PI_UDP_Recieve_B.Left_right), 1, 0, 13 },

  { (char_T *)(&PI_UDP_Recieve_B.UDPReceive_o2), 5, 0, 8 },

  { (char_T *)(&PI_UDP_Recieve_B.Output), 3, 0, 1 }
  ,

  { (char_T *)(&PI_UDP_Recieve_DW.obj), 16, 0, 1 },

  { (char_T *)(&PI_UDP_Recieve_DW.obj_c), 17, 0, 1 },

  { (char_T *)(&PI_UDP_Recieve_DW.UDPReceive_NetworkLib[0]), 0, 0, 137 },

  { (char_T *)(&PI_UDP_Recieve_DW.RateTransition1_Buffer[0]), 5, 0, 7 },

  { (char_T *)(&PI_UDP_Recieve_DW.Output_DSTATE), 3, 0, 1 },

  { (char_T *)(&PI_UDP_Recieve_DW.EnabledSubsystem_SubsysRanBC), 2, 0, 1 }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&PI_UDP_Recieve_P.CounterLimited_uplimit), 3, 0, 1 },

  { (char_T *)(&PI_UDP_Recieve_P.Out1_Y0), 15, 0, 1 },

  { (char_T *)(&PI_UDP_Recieve_P.Constant_Value), 15, 0, 1 },

  { (char_T *)(&PI_UDP_Recieve_P.UDPReceive_Port), 6, 0, 1 },

  { (char_T *)(&PI_UDP_Recieve_P.Gain7_Gain), 1, 0, 59 },

  { (char_T *)(&PI_UDP_Recieve_P.Constant_Value_m), 3, 0, 3 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

// [EOF] PI_UDP_Recieve_dt.h
