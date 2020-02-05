//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PI_UDP_Recieve.h
//
// Code generated for Simulink model 'PI_UDP_Recieve'.
//
// Model version                  : 1.43
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Wed Feb  5 14:39:07 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_PI_UDP_Recieve_h_
#define RTW_HEADER_PI_UDP_Recieve_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef PI_UDP_Recieve_COMMON_INCLUDES_
# define PI_UDP_Recieve_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_SPI.h"
#include "MW_SPI_Helper.h"
#include "slros_initialize.h"
#endif                                 // PI_UDP_Recieve_COMMON_INCLUDES_

#include "PI_UDP_Recieve_types.h"

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

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

// Block signals (default storage)
typedef struct {
  SL_Bus_PI_UDP_Recieve_geometry_msgs_Twist In1;// '<S7>/In1'
  SL_Bus_PI_UDP_Recieve_geometry_msgs_Twist b_varargout_2;
  uint8_T rdDataRaw[14];
  uint8_T wrDataRaw[14];
  real32_T Left_right;                 // '<S2>/1-D Lookup Table9'
  real32_T Up_Down;                    // '<S2>/1-D Lookup Table1'
  real32_T Up_Down_h;                  // '<Root>/1-D Lookup Table7'
  real32_T uDLookupTable1;             // '<Root>/1-D Lookup Table1'
  real32_T Left_right_c;               // '<Root>/1-D Lookup Table2'
  real32_T Up_Down_n;                  // '<Root>/1-D Lookup Table3'
  real32_T Constant2;                  // '<Root>/Constant2'
  real32_T DataTypeConversion1;        // '<S3>/Data Type Conversion1'
  real32_T DataTypeConversion2;        // '<S3>/Data Type Conversion2'
  real32_T DataTypeConversion3;        // '<S3>/Data Type Conversion3'
  real32_T DataTypeConversion4;        // '<S3>/Data Type Conversion4'
  real32_T DataTypeConversion5;        // '<S3>/Data Type Conversion5'
  real32_T DataTypeConversion6;        // '<S3>/Data Type Conversion6'
  uint16_T SPIMasterTransfer[7];       // '<Root>/SPI Master Transfer'
  uint8_T Output;                      // '<S1>/Output'
} B_PI_UDP_Recieve_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  codertarget_raspi_internal_SP_T obj; // '<Root>/SPI Master Transfer'
  ros_slros_internal_block_Subs_T obj_c;// '<S4>/SourceBlock'
  uint8_T Output_DSTATE;               // '<S1>/Output'
  int8_T EnabledSubsystem_SubsysRanBC; // '<S4>/Enabled Subsystem'
  int8_T GetRosMessage_SubsysRanBC;    // '<Root>/GetRosMessage'
} DW_PI_UDP_Recieve_T;

// Zero-crossing (trigger) state
typedef struct {
  ZCSigState GetRosMessage_Trig_ZCE;   // '<Root>/GetRosMessage'
} PrevZCX_PI_UDP_Recieve_T;

// Parameters (default storage)
struct P_PI_UDP_Recieve_T_ {
  uint8_T CounterLimited_uplimit;      // Mask Parameter: CounterLimited_uplimit
                                          //  Referenced by: '<S6>/FixPt Switch'

  SL_Bus_PI_UDP_Recieve_geometry_msgs_Twist Out1_Y0;// Computed Parameter: Out1_Y0
                                                       //  Referenced by: '<S7>/Out1'

  SL_Bus_PI_UDP_Recieve_geometry_msgs_Twist Constant_Value;// Computed Parameter: Constant_Value
                                                              //  Referenced by: '<S4>/Constant'

  real32_T Lx_Y0;                      // Computed Parameter: Lx_Y0
                                          //  Referenced by: '<S3>/Lx'

  real32_T Ly_Y0;                      // Computed Parameter: Ly_Y0
                                          //  Referenced by: '<S3>/Ly '

  real32_T Lz_Y0;                      // Computed Parameter: Lz_Y0
                                          //  Referenced by: '<S3>/Lz'

  real32_T Ax_Y0;                      // Computed Parameter: Ax_Y0
                                          //  Referenced by: '<S3>/Ax'

  real32_T Ay_Y0;                      // Computed Parameter: Ay_Y0
                                          //  Referenced by: '<S3>/Ay '

  real32_T Az_Y0;                      // Computed Parameter: Az_Y0
                                          //  Referenced by: '<S3>/Az '

  real32_T Gain7_Gain;                 // Computed Parameter: Gain7_Gain
                                          //  Referenced by: '<Root>/Gain7'

  real32_T uDLookupTable9_tableData[5];
                                 // Computed Parameter: uDLookupTable9_tableData
                                    //  Referenced by: '<S2>/1-D Lookup Table9'

  real32_T uDLookupTable9_bp01Data[5];
                                  // Computed Parameter: uDLookupTable9_bp01Data
                                     //  Referenced by: '<S2>/1-D Lookup Table9'

  real32_T Gain8_Gain;                 // Computed Parameter: Gain8_Gain
                                          //  Referenced by: '<Root>/Gain8'

  real32_T uDLookupTable1_tableData[5];
                                 // Computed Parameter: uDLookupTable1_tableData
                                    //  Referenced by: '<S2>/1-D Lookup Table1'

  real32_T uDLookupTable1_bp01Data[5];
                                  // Computed Parameter: uDLookupTable1_bp01Data
                                     //  Referenced by: '<S2>/1-D Lookup Table1'

  real32_T Constant4_Value;            // Computed Parameter: Constant4_Value
                                          //  Referenced by: '<Root>/Constant4'

  real32_T Gain6_Gain;                 // Computed Parameter: Gain6_Gain
                                          //  Referenced by: '<Root>/Gain6'

  real32_T uDLookupTable7_tableData[5];
                                 // Computed Parameter: uDLookupTable7_tableData
                                    //  Referenced by: '<Root>/1-D Lookup Table7'

  real32_T uDLookupTable7_bp01Data[5];
                                  // Computed Parameter: uDLookupTable7_bp01Data
                                     //  Referenced by: '<Root>/1-D Lookup Table7'

  real32_T Constant5_Value;            // Computed Parameter: Constant5_Value
                                          //  Referenced by: '<Root>/Constant5'

  real32_T Gain2_Gain;                 // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<Root>/Gain2'

  real32_T uDLookupTable1_tableData_g[5];
                               // Computed Parameter: uDLookupTable1_tableData_g
                                  //  Referenced by: '<Root>/1-D Lookup Table1'

  real32_T uDLookupTable1_bp01Data_b[5];
                                // Computed Parameter: uDLookupTable1_bp01Data_b
                                   //  Referenced by: '<Root>/1-D Lookup Table1'

  real32_T Constant6_Value;            // Computed Parameter: Constant6_Value
                                          //  Referenced by: '<Root>/Constant6'

  real32_T Gain3_Gain;                 // Computed Parameter: Gain3_Gain
                                          //  Referenced by: '<Root>/Gain3'

  real32_T uDLookupTable2_tableData[3];
                                 // Computed Parameter: uDLookupTable2_tableData
                                    //  Referenced by: '<Root>/1-D Lookup Table2'

  real32_T uDLookupTable2_bp01Data[3];
                                  // Computed Parameter: uDLookupTable2_bp01Data
                                     //  Referenced by: '<Root>/1-D Lookup Table2'

  real32_T Constant7_Value;            // Computed Parameter: Constant7_Value
                                          //  Referenced by: '<Root>/Constant7'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<Root>/Gain1'

  real32_T uDLookupTable3_tableData[3];
                                 // Computed Parameter: uDLookupTable3_tableData
                                    //  Referenced by: '<Root>/1-D Lookup Table3'

  real32_T uDLookupTable3_bp01Data[3];
                                  // Computed Parameter: uDLookupTable3_bp01Data
                                     //  Referenced by: '<Root>/1-D Lookup Table3'

  real32_T Constant2_Value;            // Computed Parameter: Constant2_Value
                                          //  Referenced by: '<Root>/Constant2'

  uint8_T Constant_Value_m;            // Computed Parameter: Constant_Value_m
                                          //  Referenced by: '<S6>/Constant'

  uint8_T Output_InitialCondition;// Computed Parameter: Output_InitialCondition
                                     //  Referenced by: '<S1>/Output'

  uint8_T FixPtConstant_Value;        // Computed Parameter: FixPtConstant_Value
                                         //  Referenced by: '<S5>/FixPt Constant'

};

// Real-time Model Data Structure
struct tag_RTM_PI_UDP_Recieve_T {
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
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_PI_UDP_Recieve_T PI_UDP_Recieve_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_PI_UDP_Recieve_T PI_UDP_Recieve_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_PI_UDP_Recieve_T PI_UDP_Recieve_DW;

// External data declarations for dependent source files

// Zero-crossing (trigger) state
extern PrevZCX_PI_UDP_Recieve_T PI_UDP_Recieve_PrevZCX;

// External function called from main
#ifdef __cplusplus

extern "C" {

#endif

  extern void PI_UDP_Recieve_SetEventsForThisBaseStep(boolean_T *eventFlags);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void PI_UDP_Recieve_SetEventsForThisBaseStep(boolean_T *eventFlags);
  extern void PI_UDP_Recieve_initialize(void);
  extern void PI_UDP_Recieve_step(int_T tid);
  extern void PI_UDP_Recieve_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_PI_UDP_Recieve_T *const PI_UDP_Recieve_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Constant1' : Unused code path elimination
//  Block '<Root>/Constant3' : Unused code path elimination
//  Block '<S1>/Data Type Propagation' : Unused code path elimination
//  Block '<S5>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S6>/FixPt Data Type Duplicate1' : Unused code path elimination
//  Block '<Root>/Rate Transition1' : Eliminated since input and output rates are identical


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
//  '<Root>' : 'PI_UDP_Recieve'
//  '<S1>'   : 'PI_UDP_Recieve/Counter Limited'
//  '<S2>'   : 'PI_UDP_Recieve/ForwardBack_LeftRight'
//  '<S3>'   : 'PI_UDP_Recieve/GetRosMessage'
//  '<S4>'   : 'PI_UDP_Recieve/Subscribe'
//  '<S5>'   : 'PI_UDP_Recieve/Counter Limited/Increment Real World'
//  '<S6>'   : 'PI_UDP_Recieve/Counter Limited/Wrap To Zero'
//  '<S7>'   : 'PI_UDP_Recieve/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_PI_UDP_Recieve_h_

//
// File trailer for generated code.
//
// [EOF]
//
