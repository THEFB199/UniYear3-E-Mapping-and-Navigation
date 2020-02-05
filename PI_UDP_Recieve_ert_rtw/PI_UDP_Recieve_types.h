//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PI_UDP_Recieve_types.h
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
#ifndef RTW_HEADER_PI_UDP_Recieve_types_h_
#define RTW_HEADER_PI_UDP_Recieve_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_PI_UDP_Recieve_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_PI_UDP_Recieve_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_PI_UDP_Recieve_geometry_msgs_Vector3;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_PI_UDP_Recieve_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_PI_UDP_Recieve_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
typedef struct {
  // MsgType=geometry_msgs/Vector3
  SL_Bus_PI_UDP_Recieve_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_PI_UDP_Recieve_geometry_msgs_Vector3 Angular;
} SL_Bus_PI_UDP_Recieve_geometry_msgs_Twist;

#endif

// Custom Type definition for MATLABSystem: '<Root>/SPI Master Transfer'
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

#ifndef typedef_ros_slros_internal_block_Subs_T
#define typedef_ros_slros_internal_block_Subs_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
} ros_slros_internal_block_Subs_T;

#endif                                 //typedef_ros_slros_internal_block_Subs_T

// Parameters (default storage)
typedef struct P_PI_UDP_Recieve_T_ P_PI_UDP_Recieve_T;

// Forward declaration for rtModel
typedef struct tag_RTM_PI_UDP_Recieve_T RT_MODEL_PI_UDP_Recieve_T;

#endif                                 // RTW_HEADER_PI_UDP_Recieve_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
