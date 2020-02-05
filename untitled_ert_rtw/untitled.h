//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: untitled.h
//
// Code generated for Simulink model 'untitled'.
//
// Model version                  : 1.0
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Wed Feb  5 14:42:24 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_untitled_h_
#define RTW_HEADER_untitled_h_
#include <float.h>
#include <stddef.h>
#ifndef untitled_COMMON_INCLUDES_
# define untitled_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "slros_initialize.h"
#endif                                 // untitled_COMMON_INCLUDES_

#include "untitled_types.h"

// Shared type includes
#include "multiword_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

// Block signals (default storage)
typedef struct {
  SL_Bus_untitled_geometry_msgs_Twist In1;// '<S3>/In1'
  real32_T DataTypeConversion1;        // '<S1>/Data Type Conversion1'
  real32_T DataTypeConversion2;        // '<S1>/Data Type Conversion2'
  real32_T DataTypeConversion3;        // '<S1>/Data Type Conversion3'
  real32_T DataTypeConversion4;        // '<S1>/Data Type Conversion4'
  real32_T DataTypeConversion5;        // '<S1>/Data Type Conversion5'
  real32_T DataTypeConversion6;        // '<S1>/Data Type Conversion6'
} B_untitled_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  ros_slros_internal_block_Subs_T obj; // '<S2>/SourceBlock'
  int8_T EnabledSubsystem_SubsysRanBC; // '<S2>/Enabled Subsystem'
  int8_T GetRosMessage_SubsysRanBC;    // '<Root>/GetRosMessage'
} DW_untitled_T;

// Zero-crossing (trigger) state
typedef struct {
  ZCSigState GetRosMessage_Trig_ZCE;   // '<Root>/GetRosMessage'
} PrevZCX_untitled_T;

// Parameters (default storage)
struct P_untitled_T_ {
  SL_Bus_untitled_geometry_msgs_Twist Out1_Y0;// Computed Parameter: Out1_Y0
                                                 //  Referenced by: '<S3>/Out1'

  SL_Bus_untitled_geometry_msgs_Twist Constant_Value;// Computed Parameter: Constant_Value
                                                        //  Referenced by: '<S2>/Constant'

  real32_T Lx_Y0;                      // Computed Parameter: Lx_Y0
                                          //  Referenced by: '<S1>/Lx'

  real32_T Ly_Y0;                      // Computed Parameter: Ly_Y0
                                          //  Referenced by: '<S1>/Ly '

  real32_T Lz_Y0;                      // Computed Parameter: Lz_Y0
                                          //  Referenced by: '<S1>/Lz'

  real32_T Ax_Y0;                      // Computed Parameter: Ax_Y0
                                          //  Referenced by: '<S1>/Ax'

  real32_T Ay_Y0;                      // Computed Parameter: Ay_Y0
                                          //  Referenced by: '<S1>/Ay '

  real32_T Az_Y0;                      // Computed Parameter: Az_Y0
                                          //  Referenced by: '<S1>/Az '

};

// Real-time Model Data Structure
struct tag_RTM_untitled_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    uint32_T checksums[4];
  } Sizes;

  //
  //  SpecialInfo:
  //  The following substructure contains special information
  //  related to other components that are dependent on RTW.

  struct {
    const void *mappingInfo;
  } SpecialInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_untitled_T untitled_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_untitled_T untitled_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_untitled_T untitled_DW;

// External data declarations for dependent source files

// Zero-crossing (trigger) state
extern PrevZCX_untitled_T untitled_PrevZCX;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void untitled_initialize(void);
  extern void untitled_step(void);
  extern void untitled_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_untitled_T *const untitled_M;

#ifdef __cplusplus

}
#endif

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'untitled'
//  '<S1>'   : 'untitled/GetRosMessage'
//  '<S2>'   : 'untitled/Subscribe'
//  '<S3>'   : 'untitled/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_untitled_h_

//
// File trailer for generated code.
//
// [EOF]
//
