//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ROSPiNav2.h
//
// Code generated for Simulink model 'ROSPiNav2'.
//
// Model version                  : 1.2
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Fri Feb  7 14:00:01 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ROSPiNav2_h_
#define RTW_HEADER_ROSPiNav2_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef ROSPiNav2_COMMON_INCLUDES_
# define ROSPiNav2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "slros_initialize.h"
#include "MW_SPI.h"
#include "MW_SPI_Helper.h"
#endif                                 // ROSPiNav2_COMMON_INCLUDES_

#include "ROSPiNav2_types.h"

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
  SL_Bus_ROSPiNav2_sensor_msgs_Joy In1;// '<S15>/In1'
  SL_Bus_ROSPiNav2_sensor_msgs_Joy b_varargout_2;
  SL_Bus_ROSPiNav2_geometry_msgs_Twist In1_l;// '<S14>/In1'
  SL_Bus_ROSPiNav2_geometry_msgs_Twist b_varargout_2_m;
  real32_T DeadZone[8];                // '<S13>/Dead Zone'
  char_T cv[17];
  uint8_T rdDataRaw[14];
  uint8_T wrDataRaw[14];
  real32_T uDLookupTable9;             // '<S3>/1-D Lookup Table9'
  real32_T uDLookupTable1;             // '<S3>/1-D Lookup Table1'
  real32_T uDLookupTable1_j[4];        // '<S13>/1-D Lookup Table1'
  real32_T OutportBufferForUpDownL;
  real32_T DataTypeConversion1;        // '<S4>/Data Type Conversion1'
  real32_T DataTypeConversion2;        // '<S4>/Data Type Conversion2'
  real32_T DataTypeConversion3;        // '<S4>/Data Type Conversion3'
  real32_T DataTypeConversion4;        // '<S4>/Data Type Conversion4'
  real32_T DataTypeConversion5;        // '<S4>/Data Type Conversion5'
  real32_T DataTypeConversion6;        // '<S4>/Data Type Conversion6'
  uint16_T SPIMasterTransfer[7];       // '<S8>/SPI Master Transfer'
  uint8_T Output;                      // '<S2>/Output'
  boolean_T SourceBlock_o1;            // '<S7>/SourceBlock'
  boolean_T SourceBlock_o1_g;          // '<S6>/SourceBlock'
} B_ROSPiNav2_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  codertarget_raspi_internal_SP_T obj; // '<S8>/SPI Master Transfer'
  ros_slros_internal_block_Subs_T obj_l;// '<S7>/SourceBlock'
  ros_slros_internal_block_Subs_T obj_e;// '<S6>/SourceBlock'
  uint8_T Output_DSTATE;               // '<S2>/Output'
  int8_T EnabledSubsystem_SubsysRanBC; // '<S7>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_j;// '<S6>/Enabled Subsystem'
  int8_T GetRosMessage1_SubsysRanBC;   // '<Root>/GetRosMessage1'
  int8_T GetRosMessage_SubsysRanBC;    // '<Root>/GetRosMessage'
} DW_ROSPiNav2_T;

// Parameters (default storage)
struct P_ROSPiNav2_T_ {
  uint8_T CounterLimited_uplimit;      // Mask Parameter: CounterLimited_uplimit
                                          //  Referenced by: '<S10>/FixPt Switch'

  SL_Bus_ROSPiNav2_sensor_msgs_Joy Out1_Y0;// Computed Parameter: Out1_Y0
                                              //  Referenced by: '<S15>/Out1'

  SL_Bus_ROSPiNav2_sensor_msgs_Joy Constant_Value;// Computed Parameter: Constant_Value
                                                     //  Referenced by: '<S7>/Constant'

  SL_Bus_ROSPiNav2_geometry_msgs_Twist Out1_Y0_d;// Computed Parameter: Out1_Y0_d
                                                    //  Referenced by: '<S14>/Out1'

  SL_Bus_ROSPiNav2_geometry_msgs_Twist Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                           //  Referenced by: '<S6>/Constant'

  real32_T Constant2_Value;            // Computed Parameter: Constant2_Value
                                          //  Referenced by: '<Root>/Constant2'

  real32_T Constant_Value_f;           // Computed Parameter: Constant_Value_f
                                          //  Referenced by: '<Root>/Constant'

  real32_T Lx_Y0;                      // Computed Parameter: Lx_Y0
                                          //  Referenced by: '<S4>/Lx'

  real32_T Ly_Y0;                      // Computed Parameter: Ly_Y0
                                          //  Referenced by: '<S4>/Ly '

  real32_T Lz_Y0;                      // Computed Parameter: Lz_Y0
                                          //  Referenced by: '<S4>/Lz'

  real32_T Ax_Y0;                      // Computed Parameter: Ax_Y0
                                          //  Referenced by: '<S4>/Ax'

  real32_T Ay_Y0;                      // Computed Parameter: Ay_Y0
                                          //  Referenced by: '<S4>/Ay '

  real32_T Az_Y0;                      // Computed Parameter: Az_Y0
                                          //  Referenced by: '<S4>/Az '

  real32_T LeftRightL_Y0;              // Computed Parameter: LeftRightL_Y0
                                          //  Referenced by: '<S5>/LeftRightL'

  real32_T UpDownL_Y0;                 // Computed Parameter: UpDownL_Y0
                                          //  Referenced by: '<S5>/UpDownL'

  real32_T LeftTrigger_Y0;             // Computed Parameter: LeftTrigger_Y0
                                          //  Referenced by: '<S5>/LeftTrigger'

  real32_T LeftRightR_Y0;              // Computed Parameter: LeftRightR_Y0
                                          //  Referenced by: '<S5>/LeftRightR'

  real32_T UpDownR_Y0;                 // Computed Parameter: UpDownR_Y0
                                          //  Referenced by: '<S5>/UpDownR'

  real32_T RightTrigger_Y0;            // Computed Parameter: RightTrigger_Y0
                                          //  Referenced by: '<S5>/RightTrigger'

  real32_T LeftRightDpad_Y0;           // Computed Parameter: LeftRightDpad_Y0
                                          //  Referenced by: '<S5>/LeftRightDpad'

  real32_T UpDownDpad_Y0;              // Computed Parameter: UpDownDpad_Y0
                                          //  Referenced by: '<S5>/UpDownDpad'

  real32_T Buttons_Y0;                 // Computed Parameter: Buttons_Y0
                                          //  Referenced by: '<S5>/Buttons '

  real32_T DeadZone_Start;             // Computed Parameter: DeadZone_Start
                                          //  Referenced by: '<S13>/Dead Zone'

  real32_T DeadZone_End;               // Computed Parameter: DeadZone_End
                                          //  Referenced by: '<S13>/Dead Zone'

  real32_T uDLookupTable1_tableData[3];
                                 // Computed Parameter: uDLookupTable1_tableData
                                    //  Referenced by: '<S13>/1-D Lookup Table1'

  real32_T uDLookupTable1_bp01Data[3];
                                  // Computed Parameter: uDLookupTable1_bp01Data
                                     //  Referenced by: '<S13>/1-D Lookup Table1'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S1>/Gain1'

  real32_T uDLookupTable9_tableData[5];
                                 // Computed Parameter: uDLookupTable9_tableData
                                    //  Referenced by: '<S3>/1-D Lookup Table9'

  real32_T uDLookupTable9_bp01Data[5];
                                  // Computed Parameter: uDLookupTable9_bp01Data
                                     //  Referenced by: '<S3>/1-D Lookup Table9'

  real32_T uDLookupTable1_tableData_b[5];
                               // Computed Parameter: uDLookupTable1_tableData_b
                                  //  Referenced by: '<S3>/1-D Lookup Table1'

  real32_T uDLookupTable1_bp01Data_g[5];
                                // Computed Parameter: uDLookupTable1_bp01Data_g
                                   //  Referenced by: '<S3>/1-D Lookup Table1'

  real32_T Constant5_Value;            // Computed Parameter: Constant5_Value
                                          //  Referenced by: '<Root>/Constant5'

  real32_T Constant4_Value;            // Computed Parameter: Constant4_Value
                                          //  Referenced by: '<Root>/Constant4'

  real32_T Constant3_Value;            // Computed Parameter: Constant3_Value
                                          //  Referenced by: '<Root>/Constant3'

  real32_T Constant1_Value;            // Computed Parameter: Constant1_Value
                                          //  Referenced by: '<Root>/Constant1'

  real32_T EndofData_Value;            // Computed Parameter: EndofData_Value
                                          //  Referenced by: '<S8>/EndofData'

  uint8_T Constant_Value_a;            // Computed Parameter: Constant_Value_a
                                          //  Referenced by: '<S10>/Constant'

  uint8_T ManualSwitch1_CurrentSetting;
                             // Computed Parameter: ManualSwitch1_CurrentSetting
                                //  Referenced by: '<Root>/Manual Switch1'

  uint8_T Output_InitialCondition;// Computed Parameter: Output_InitialCondition
                                     //  Referenced by: '<S2>/Output'

  uint8_T FixPtConstant_Value;        // Computed Parameter: FixPtConstant_Value
                                         //  Referenced by: '<S9>/FixPt Constant'

};

// Real-time Model Data Structure
struct tag_RTM_ROSPiNav2_T {
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

  extern P_ROSPiNav2_T ROSPiNav2_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_ROSPiNav2_T ROSPiNav2_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_ROSPiNav2_T ROSPiNav2_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void ROSPiNav2_initialize(void);
  extern void ROSPiNav2_step(void);
  extern void ROSPiNav2_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_ROSPiNav2_T *const ROSPiNav2_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S1>/Constant1' : Unused code path elimination
//  Block '<S1>/Constant2' : Unused code path elimination
//  Block '<S1>/Magnitude Squared' : Unused code path elimination
//  Block '<S1>/Square Root' : Unused code path elimination
//  Block '<S1>/Switch1' : Unused code path elimination
//  Block '<S1>/Switch2' : Unused code path elimination
//  Block '<S2>/Data Type Propagation' : Unused code path elimination
//  Block '<S9>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S10>/FixPt Data Type Duplicate1' : Unused code path elimination
//  Block '<S5>/Data Type Conversion3' : Unused code path elimination
//  Block '<S13>/Triggers' : Unused code path elimination
//  Block '<S5>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S8>/Rate Transition1' : Eliminated since input and output rates are identical


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
//  '<Root>' : 'ROSPiNav2'
//  '<S1>'   : 'ROSPiNav2/Arbitration'
//  '<S2>'   : 'ROSPiNav2/Counter Limited'
//  '<S3>'   : 'ROSPiNav2/ForwardBack_LeftRight'
//  '<S4>'   : 'ROSPiNav2/GetRosMessage'
//  '<S5>'   : 'ROSPiNav2/GetRosMessage1'
//  '<S6>'   : 'ROSPiNav2/Subscribe'
//  '<S7>'   : 'ROSPiNav2/Subscribe1'
//  '<S8>'   : 'ROSPiNav2/Subsystem'
//  '<S9>'   : 'ROSPiNav2/Counter Limited/Increment Real World'
//  '<S10>'  : 'ROSPiNav2/Counter Limited/Wrap To Zero'
//  '<S11>'  : 'ROSPiNav2/GetRosMessage1/MATLAB Function'
//  '<S12>'  : 'ROSPiNav2/GetRosMessage1/MATLAB Function1'
//  '<S13>'  : 'ROSPiNav2/GetRosMessage1/XboxControllerMappings '
//  '<S14>'  : 'ROSPiNav2/Subscribe/Enabled Subsystem'
//  '<S15>'  : 'ROSPiNav2/Subscribe1/Enabled Subsystem'

#endif                                 // RTW_HEADER_ROSPiNav2_h_

//
// File trailer for generated code.
//
// [EOF]
//
