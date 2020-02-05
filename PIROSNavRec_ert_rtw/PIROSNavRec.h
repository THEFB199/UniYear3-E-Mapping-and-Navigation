//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PIROSNavRec.h
//
// Code generated for Simulink model 'PIROSNavRec'.
//
// Model version                  : 1.6
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Wed Feb  5 15:34:15 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_PIROSNavRec_h_
#define RTW_HEADER_PIROSNavRec_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef PIROSNavRec_COMMON_INCLUDES_
# define PIROSNavRec_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_SPI.h"
#include "MW_SPI_Helper.h"
#include "slros_initialize.h"
#endif                                 // PIROSNavRec_COMMON_INCLUDES_

#include "PIROSNavRec_types.h"

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
  SL_Bus_PIROSNavRec_geometry_msgs_Twist In1;// '<S7>/In1'
  SL_Bus_PIROSNavRec_geometry_msgs_Twist b_varargout_2;
  uint8_T rdDataRaw[14];
  uint8_T wrDataRaw[14];
  real32_T DataTypeConversion1;        // '<S3>/Data Type Conversion1'
  real32_T DataTypeConversion2;        // '<S3>/Data Type Conversion2'
  real32_T DataTypeConversion3;        // '<S3>/Data Type Conversion3'
  real32_T DataTypeConversion4;        // '<S3>/Data Type Conversion4'
  real32_T DataTypeConversion5;        // '<S3>/Data Type Conversion5'
  real32_T DataTypeConversion6;        // '<S3>/Data Type Conversion6'
  uint16_T SPIMasterTransfer[7];       // '<Root>/SPI Master Transfer'
  uint8_T Output;                      // '<S1>/Output'
  boolean_T SourceBlock_o1;            // '<S4>/SourceBlock'
} B_PIROSNavRec_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  codertarget_raspi_internal_SP_T obj; // '<Root>/SPI Master Transfer'
  ros_slros_internal_block_Subs_T obj_n;// '<S4>/SourceBlock'
  uint8_T Output_DSTATE;               // '<S1>/Output'
  int8_T EnabledSubsystem_SubsysRanBC; // '<S4>/Enabled Subsystem'
  int8_T GetRosMessage_SubsysRanBC;    // '<Root>/GetRosMessage'
} DW_PIROSNavRec_T;

// Zero-crossing (trigger) state
typedef struct {
  ZCSigState GetRosMessage_Trig_ZCE;   // '<Root>/GetRosMessage'
} PrevZCX_PIROSNavRec_T;

// Parameters (default storage)
struct P_PIROSNavRec_T_ {
  uint8_T CounterLimited_uplimit;      // Mask Parameter: CounterLimited_uplimit
                                          //  Referenced by: '<S6>/FixPt Switch'

  SL_Bus_PIROSNavRec_geometry_msgs_Twist Out1_Y0;// Computed Parameter: Out1_Y0
                                                    //  Referenced by: '<S7>/Out1'

  SL_Bus_PIROSNavRec_geometry_msgs_Twist Constant_Value;// Computed Parameter: Constant_Value
                                                           //  Referenced by: '<S4>/Constant'

  real32_T Constant6_Value;            // Computed Parameter: Constant6_Value
                                          //  Referenced by: '<Root>/Constant6'

  real32_T Gain7_Gain;                 // Computed Parameter: Gain7_Gain
                                          //  Referenced by: '<Root>/Gain7'

  real32_T Gain8_Gain;                 // Computed Parameter: Gain8_Gain
                                          //  Referenced by: '<Root>/Gain8'

  real32_T Constant_Value_b;           // Computed Parameter: Constant_Value_b
                                          //  Referenced by: '<Root>/Constant'

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

  real32_T uDLookupTable9_tableData[5];
                                 // Computed Parameter: uDLookupTable9_tableData
                                    //  Referenced by: '<S2>/1-D Lookup Table9'

  real32_T uDLookupTable9_bp01Data[5];
                                  // Computed Parameter: uDLookupTable9_bp01Data
                                     //  Referenced by: '<S2>/1-D Lookup Table9'

  real32_T uDLookupTable1_tableData[5];
                                 // Computed Parameter: uDLookupTable1_tableData
                                    //  Referenced by: '<S2>/1-D Lookup Table1'

  real32_T uDLookupTable1_bp01Data[5];
                                  // Computed Parameter: uDLookupTable1_bp01Data
                                     //  Referenced by: '<S2>/1-D Lookup Table1'

  real32_T Constant5_Value;            // Computed Parameter: Constant5_Value
                                          //  Referenced by: '<Root>/Constant5'

  real32_T Constant4_Value;            // Computed Parameter: Constant4_Value
                                          //  Referenced by: '<Root>/Constant4'

  real32_T Constant3_Value;            // Computed Parameter: Constant3_Value
                                          //  Referenced by: '<Root>/Constant3'

  real32_T Constant1_Value;            // Computed Parameter: Constant1_Value
                                          //  Referenced by: '<Root>/Constant1'

  real32_T Constant2_Value;            // Computed Parameter: Constant2_Value
                                          //  Referenced by: '<Root>/Constant2'

  uint8_T Constant_Value_i;            // Computed Parameter: Constant_Value_i
                                          //  Referenced by: '<S6>/Constant'

  uint8_T ManualSwitch1_CurrentSetting;
                             // Computed Parameter: ManualSwitch1_CurrentSetting
                                //  Referenced by: '<Root>/Manual Switch1'

  uint8_T ManualSwitch_CurrentSetting;
                              // Computed Parameter: ManualSwitch_CurrentSetting
                                 //  Referenced by: '<Root>/Manual Switch'

  uint8_T Output_InitialCondition;// Computed Parameter: Output_InitialCondition
                                     //  Referenced by: '<S1>/Output'

  uint8_T FixPtConstant_Value;        // Computed Parameter: FixPtConstant_Value
                                         //  Referenced by: '<S5>/FixPt Constant'

};

// Real-time Model Data Structure
struct tag_RTM_PIROSNavRec_T {
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

  extern P_PIROSNavRec_T PIROSNavRec_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_PIROSNavRec_T PIROSNavRec_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_PIROSNavRec_T PIROSNavRec_DW;

// External data declarations for dependent source files

// Zero-crossing (trigger) state
extern PrevZCX_PIROSNavRec_T PIROSNavRec_PrevZCX;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void PIROSNavRec_initialize(void);
  extern void PIROSNavRec_step(void);
  extern void PIROSNavRec_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_PIROSNavRec_T *const PIROSNavRec_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
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
//  '<Root>' : 'PIROSNavRec'
//  '<S1>'   : 'PIROSNavRec/Counter Limited'
//  '<S2>'   : 'PIROSNavRec/ForwardBack_LeftRight'
//  '<S3>'   : 'PIROSNavRec/GetRosMessage'
//  '<S4>'   : 'PIROSNavRec/Subscribe'
//  '<S5>'   : 'PIROSNavRec/Counter Limited/Increment Real World'
//  '<S6>'   : 'PIROSNavRec/Counter Limited/Wrap To Zero'
//  '<S7>'   : 'PIROSNavRec/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_PIROSNavRec_h_

//
// File trailer for generated code.
//
// [EOF]
//
