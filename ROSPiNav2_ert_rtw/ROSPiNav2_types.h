//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ROSPiNav2_types.h
//
// Code generated for Simulink model 'ROSPiNav2'.
//
// Model version                  : 1.4
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Tue Feb 25 11:49:18 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ROSPiNav2_types_h_
#define RTW_HEADER_ROSPiNav2_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSPiNav2_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSPiNav2_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_ROSPiNav2_geometry_msgs_Vector3;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSPiNav2_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSPiNav2_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
typedef struct {
  // MsgType=geometry_msgs/Vector3
  SL_Bus_ROSPiNav2_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_ROSPiNav2_geometry_msgs_Vector3 Angular;
} SL_Bus_ROSPiNav2_geometry_msgs_Twist;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSPiNav2_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSPiNav2_ros_time_Time_

// MsgType=ros_time/Time
typedef struct {
  real_T Sec;
  real_T Nsec;
} SL_Bus_ROSPiNav2_ros_time_Time;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSPiNav2_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSPiNav2_std_msgs_Header_

// MsgType=std_msgs/Header
typedef struct {
  uint32_T Seq;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;

  // MsgType=ros_time/Time
  SL_Bus_ROSPiNav2_ros_time_Time Stamp;
} SL_Bus_ROSPiNav2_std_msgs_Header;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSPiNav2_sensor_msgs_Joy_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSPiNav2_sensor_msgs_Joy_

// MsgType=sensor_msgs/Joy
typedef struct {
  // IsVarLen=1:VarLenCategory=data:VarLenElem=Axes_SL_Info:TruncateAction=warn
  real32_T Axes[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Axes
  SL_Bus_ROSVariableLengthArrayInfo Axes_SL_Info;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=Buttons_SL_Info:TruncateAction=warn 
  int32_T Buttons[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Buttons
  SL_Bus_ROSVariableLengthArrayInfo Buttons_SL_Info;

  // MsgType=std_msgs/Header
  SL_Bus_ROSPiNav2_std_msgs_Header Header;
} SL_Bus_ROSPiNav2_sensor_msgs_Joy;

#endif

#ifndef typedef_ros_slros_internal_block_Subs_T
#define typedef_ros_slros_internal_block_Subs_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
} ros_slros_internal_block_Subs_T;

#endif                                 //typedef_ros_slros_internal_block_Subs_T

// Custom Type definition for MATLABSystem: '<S8>/SPI Master Transfer'
#include "MW_SVD.h"
#ifndef typedef_d_codertarget_raspi_internal__T
#define typedef_d_codertarget_raspi_internal__T

typedef struct {
  int32_T __dummy;
} d_codertarget_raspi_internal__T;

#endif                                 //typedef_d_codertarget_raspi_internal__T

#ifndef typedef_codertarget_raspi_internal_SP_T
#define typedef_codertarget_raspi_internal_SP_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_codertarget_raspi_internal__T Hw;
  MW_Handle_Type MW_SPI_HANDLE;
} codertarget_raspi_internal_SP_T;

#endif                                 //typedef_codertarget_raspi_internal_SP_T

// Parameters (default storage)
typedef struct P_ROSPiNav2_T_ P_ROSPiNav2_T;

// Forward declaration for rtModel
typedef struct tag_RTM_ROSPiNav2_T RT_MODEL_ROSPiNav2_T;

#endif                                 // RTW_HEADER_ROSPiNav2_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
