//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: untitled1.h
//
// Code generated for Simulink model 'untitled1'.
//
// Model version                  : 1.0
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Tue Feb 25 12:27:41 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_untitled1_h_
#define RTW_HEADER_untitled1_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef untitled1_COMMON_INCLUDES_
# define untitled1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_SDL_video_display.h"
#include "v4l2_capture.h"
#endif                                 // untitled1_COMMON_INCLUDES_

#include "untitled1_types.h"

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
  uint8_T V4L2VideoCapture_o1[480000]; // '<Root>/V4L2 Video Capture'
  uint8_T pln1[480000];
  uint8_T V4L2VideoCapture_o2[240000]; // '<Root>/V4L2 Video Capture'
  uint8_T V4L2VideoCapture_o3[240000]; // '<Root>/V4L2 Video Capture'
  uint8_T pln2[240000];
  uint8_T pln3[240000];
  uint8_T Output;                      // '<S1>/Output'
} B_untitled1_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  codertarget_linux_blocks_SDLV_T obj; // '<S2>/MATLAB System'
  uint8_T Output_DSTATE;               // '<S1>/Output'
} DW_untitled1_T;

// Constant parameters (default storage)
typedef struct {
  // Expression: devName
  //  Referenced by: '<Root>/V4L2 Video Capture'

  uint8_T V4L2VideoCapture_p1[12];
} ConstP_untitled1_T;

// Parameters (default storage)
struct P_untitled1_T_ {
  uint8_T CounterLimited_uplimit;      // Mask Parameter: CounterLimited_uplimit
                                          //  Referenced by: '<S4>/FixPt Switch'

  uint8_T Constant_Value;              // Computed Parameter: Constant_Value
                                          //  Referenced by: '<S4>/Constant'

  uint8_T Output_InitialCondition;// Computed Parameter: Output_InitialCondition
                                     //  Referenced by: '<S1>/Output'

  uint8_T FixPtConstant_Value;        // Computed Parameter: FixPtConstant_Value
                                         //  Referenced by: '<S3>/FixPt Constant'

};

// Real-time Model Data Structure
struct tag_RTM_untitled1_T {
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

  extern P_untitled1_T untitled1_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_untitled1_T untitled1_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_untitled1_T untitled1_DW;

// Constant parameters (default storage)
extern const ConstP_untitled1_T untitled1_ConstP;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void untitled1_initialize(void);
  extern void untitled1_step(void);
  extern void untitled1_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_untitled1_T *const untitled1_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S1>/Data Type Propagation' : Unused code path elimination
//  Block '<S3>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S4>/FixPt Data Type Duplicate1' : Unused code path elimination


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
//  '<Root>' : 'untitled1'
//  '<S1>'   : 'untitled1/Counter Limited'
//  '<S2>'   : 'untitled1/SDL Video Display'
//  '<S3>'   : 'untitled1/Counter Limited/Increment Real World'
//  '<S4>'   : 'untitled1/Counter Limited/Wrap To Zero'

#endif                                 // RTW_HEADER_untitled1_h_

//
// File trailer for generated code.
//
// [EOF]
//
