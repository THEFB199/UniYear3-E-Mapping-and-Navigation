//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PIROSNav.h
//
// Code generated for Simulink model 'PIROSNav'.
//
// Model version                  : 1.62
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Fri Feb  7 11:21:02 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_PIROSNav_h_
#define RTW_HEADER_PIROSNav_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef PIROSNav_COMMON_INCLUDES_
# define PIROSNav_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_I2C.h"
#include "slros_initialize.h"
#include "MW_SPI.h"
#include "MW_SPI_Helper.h"
#endif                                 // PIROSNav_COMMON_INCLUDES_

#include "PIROSNav_types.h"

// Shared type includes
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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
  c_fusion_internal_coder_ahrsf_T FUSE;
  SL_Bus_PIROSNav_sensor_msgs_Joy In1; // '<S19>/In1'
  SL_Bus_PIROSNav_sensor_msgs_Joy b_varargout_2;
  real_T Qw[144];
  real_T Ppost[144];
  real_T H[72];
  real_T K[72];
  real_T H_m[72];
  real_T y[36];
  real_T A[36];
  real_T xe_post[12];
  real_T b[9];
  real_T Rprior[9];
  real_T h1[9];
  real_T dv[9];
  real_T x[9];
  real_T h[9];
  real_T ze[6];
  SL_Bus_PIROSNav_geometry_msgs_Twist In1_h;// '<S18>/In1'
  SL_Bus_PIROSNav_geometry_msgs_Twist b_varargout_2_c;
  real_T psquared[4];
  real32_T DeadZone[8];                // '<S14>/Dead Zone'
  c_matlabshared_rotations_inte_T q;
  real_T a[3];
  real_T LSM9DS1IMUSensor_o2[3];       // '<S6>/LSM9DS1 IMU Sensor'
  real_T LSM9DS1IMUSensor_o1[3];       // '<S6>/LSM9DS1 IMU Sensor'
  real_T a_k[3];
  real_T gravityAccelMeas[3];
  real_T y_c[3];
  real_T Rprior_b[3];
  real_T Reast[3];
  real_T deltaAng[3];
  char_T cv[17];
  char_T cv1[16];
  uint8_T b_RegisterValue[16];
  uint8_T output_raw[16];
  uint8_T rdDataRaw[14];
  uint8_T wrDataRaw[14];
  uint16_T b_x[7];
  boolean_T b_p[9];
  uint32_T PinNameLoc;
  MW_SPI_Mode_type ClockModeValue;
  MW_SPI_FirstBitTransfer_Type MsbFirstTransferLoc;
  uint64m_T r;
  uint64m_T r1;
  uint64m_T r2;
  uint64m_T r3;
  uint64m_T r4;
  uint64m_T r5;
  uint64m_T r6;
  uint64m_T r7;
  real_T out;                          // '<S6>/MATLAB Function2'
  real_T out_p;                        // '<S6>/MATLAB Function1'
  real_T orientation2;                 // '<S6>/MATLAB Function'
  real_T LPS25HPressureSensor_o1;      // '<S6>/LPS25H Pressure Sensor'
  real_T LPS25HPressureSensor_o2;      // '<S6>/LPS25H Pressure Sensor'
  real_T HTS221HumiditySensor_o1;      // '<S6>/HTS221 Humidity Sensor'
  real_T HTS221HumiditySensor_o2;      // '<S6>/HTS221 Humidity Sensor'
  real_T orientation_a;
  real_T orientation_d;
  real_T n;
  real_T rtb_Gain1_idx_0;
  real_T rtb_Gain1_idx_1;
  real_T smax;
  real_T gyroOffsetErr_idx_0;
  real_T gyroOffsetErr_idx_1;
  real_T gyroOffsetErr_idx_2;
  real_T linAccelErr_idx_0;
  real_T linAccelErr_idx_2;
  real_T assign_temp_a;
  real_T assign_temp_b;
  real_T assign_temp_c;
  real_T assign_temp_d;
  real_T theta;
  real_T ac2;
  real_T ad2;
  real_T bc2;
  real_T bd2;
  real_T cd2;
  real_T aasq;
  real_T pd;
  real_T scale;
  real_T absxk;
  int16_T b_RegisterValue_c[3];
  uint8_T output_raw_f[6];
  int8_T ipiv[6];
  real32_T uDLookupTable9;             // '<S3>/1-D Lookup Table9'
  real32_T uDLookupTable1;             // '<S3>/1-D Lookup Table1'
  real32_T uDLookupTable1_b[4];        // '<S14>/1-D Lookup Table1'
  real32_T OutportBufferForUpDownL;
  real32_T DataTypeConversion1;        // '<S4>/Data Type Conversion1'
  real32_T DataTypeConversion2;        // '<S4>/Data Type Conversion2'
  real32_T DataTypeConversion3;        // '<S4>/Data Type Conversion3'
  real32_T DataTypeConversion4;        // '<S4>/Data Type Conversion4'
  real32_T DataTypeConversion5;        // '<S4>/Data Type Conversion5'
  real32_T DataTypeConversion6;        // '<S4>/Data Type Conversion6'
  uint16_T SPIMasterTransfer[7];       // '<S9>/SPI Master Transfer'
  real32_T SquareRoot;                 // '<S1>/Square Root'
  int32_T i;
  int32_T y_tmp;
  int32_T j;
  fusion_internal_frames_NED_PI_T lobj_1;
  uint8_T Output;                      // '<S2>/Output'
  boolean_T SourceBlock_o1;            // '<S8>/SourceBlock'
  boolean_T SourceBlock_o1_a;          // '<S7>/SourceBlock'
} B_PIROSNav_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  raspi_internal_lsm9ds1Block_P_T obj; // '<S6>/LSM9DS1 IMU Sensor'
  raspi_internal_hts221Block_PI_T obj_d;// '<S6>/HTS221 Humidity Sensor'
  raspi_internal_lps25hBlock_PI_T obj_do;// '<S6>/LPS25H Pressure Sensor'
  codertarget_raspi_internal_SP_T obj_n;// '<S9>/SPI Master Transfer'
  ros_slros_internal_block_Subs_T obj_j;// '<S8>/SourceBlock'
  ros_slros_internal_block_Subs_T obj_no;// '<S7>/SourceBlock'
  uint8_T Output_DSTATE;               // '<S2>/Output'
  int8_T EnabledSubsystem_SubsysRanBC; // '<S8>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_b;// '<S7>/Enabled Subsystem'
  int8_T GetRosMessage1_SubsysRanBC;   // '<Root>/GetRosMessage1'
  int8_T GetRosMessage_SubsysRanBC;    // '<Root>/GetRosMessage'
} DW_PIROSNav_T;

// Parameters (default storage)
struct P_PIROSNav_T_ {
  uint8_T CounterLimited_uplimit;      // Mask Parameter: CounterLimited_uplimit
                                          //  Referenced by: '<S11>/FixPt Switch'

  SL_Bus_PIROSNav_sensor_msgs_Joy Out1_Y0;// Computed Parameter: Out1_Y0
                                             //  Referenced by: '<S19>/Out1'

  SL_Bus_PIROSNav_sensor_msgs_Joy Constant_Value;// Computed Parameter: Constant_Value
                                                    //  Referenced by: '<S8>/Constant'

  SL_Bus_PIROSNav_geometry_msgs_Twist Out1_Y0_a;// Computed Parameter: Out1_Y0_a
                                                   //  Referenced by: '<S18>/Out1'

  SL_Bus_PIROSNav_geometry_msgs_Twist Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                          //  Referenced by: '<S7>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S1>/Constant1'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S1>/Constant2'

  real_T Gain1_Gain;                   // Expression: 100
                                          //  Referenced by: '<S1>/Gain1'

  real_T uDLookupTable9_bp01Data[5];   // Expression: [-100,-50,0,50,100]
                                          //  Referenced by: '<S3>/1-D Lookup Table9'

  real_T uDLookupTable1_bp01Data[5];   // Expression: [-100,-50,0,50,100]
                                          //  Referenced by: '<S3>/1-D Lookup Table1'

  real32_T Constant2_Value_d;          // Computed Parameter: Constant2_Value_d
                                          //  Referenced by: '<Root>/Constant2'

  real32_T Constant_Value_b;           // Computed Parameter: Constant_Value_b
                                          //  Referenced by: '<Root>/Constant'

  real32_T Switch2_Threshold;          // Computed Parameter: Switch2_Threshold
                                          //  Referenced by: '<S1>/Switch2'

  real32_T Switch1_Threshold;          // Computed Parameter: Switch1_Threshold
                                          //  Referenced by: '<S1>/Switch1'

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
                                          //  Referenced by: '<S14>/Dead Zone'

  real32_T DeadZone_End;               // Computed Parameter: DeadZone_End
                                          //  Referenced by: '<S14>/Dead Zone'

  real32_T uDLookupTable1_tableData[3];
                                 // Computed Parameter: uDLookupTable1_tableData
                                    //  Referenced by: '<S14>/1-D Lookup Table1'

  real32_T uDLookupTable1_bp01Data_j[3];
                                // Computed Parameter: uDLookupTable1_bp01Data_j
                                   //  Referenced by: '<S14>/1-D Lookup Table1'

  real32_T uDLookupTable9_tableData[5];
                                 // Computed Parameter: uDLookupTable9_tableData
                                    //  Referenced by: '<S3>/1-D Lookup Table9'

  real32_T uDLookupTable1_tableData_n[5];
                               // Computed Parameter: uDLookupTable1_tableData_n
                                  //  Referenced by: '<S3>/1-D Lookup Table1'

  real32_T Constant5_Value;            // Computed Parameter: Constant5_Value
                                          //  Referenced by: '<Root>/Constant5'

  real32_T Constant4_Value;            // Computed Parameter: Constant4_Value
                                          //  Referenced by: '<Root>/Constant4'

  real32_T Constant3_Value;            // Computed Parameter: Constant3_Value
                                          //  Referenced by: '<Root>/Constant3'

  real32_T Constant1_Value_d;          // Computed Parameter: Constant1_Value_d
                                          //  Referenced by: '<Root>/Constant1'

  real32_T EndofData_Value;            // Computed Parameter: EndofData_Value
                                          //  Referenced by: '<S9>/EndofData'

  uint8_T Constant_Value_i;            // Computed Parameter: Constant_Value_i
                                          //  Referenced by: '<S11>/Constant'

  uint8_T ManualSwitch1_CurrentSetting;
                             // Computed Parameter: ManualSwitch1_CurrentSetting
                                //  Referenced by: '<Root>/Manual Switch1'

  uint8_T Output_InitialCondition;// Computed Parameter: Output_InitialCondition
                                     //  Referenced by: '<S2>/Output'

  uint8_T FixPtConstant_Value;        // Computed Parameter: FixPtConstant_Value
                                         //  Referenced by: '<S10>/FixPt Constant'

};

// Real-time Model Data Structure
struct tag_RTM_PIROSNav_T {
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

  extern P_PIROSNav_T PIROSNav_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_PIROSNav_T PIROSNav_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_PIROSNav_T PIROSNav_DW;

// External function called from main
#ifdef __cplusplus

extern "C" {

#endif

  extern void PIROSNav_SetEventsForThisBaseStep(boolean_T *eventFlags);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void PIROSNav_SetEventsForThisBaseStep(boolean_T *eventFlags);
  extern void PIROSNav_initialize(void);
  extern void PIROSNav_step(int_T tid);
  extern void PIROSNav_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_PIROSNav_T *const PIROSNav_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/Data Type Propagation' : Unused code path elimination
//  Block '<S10>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S11>/FixPt Data Type Duplicate1' : Unused code path elimination
//  Block '<S5>/Data Type Conversion3' : Unused code path elimination
//  Block '<S14>/Triggers' : Unused code path elimination
//  Block '<S5>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S9>/Rate Transition1' : Eliminated since input and output rates are identical


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
//  '<Root>' : 'PIROSNav'
//  '<S1>'   : 'PIROSNav/Arbitration'
//  '<S2>'   : 'PIROSNav/Counter Limited'
//  '<S3>'   : 'PIROSNav/ForwardBack_LeftRight'
//  '<S4>'   : 'PIROSNav/GetRosMessage'
//  '<S5>'   : 'PIROSNav/GetRosMessage1'
//  '<S6>'   : 'PIROSNav/PiSenseHat'
//  '<S7>'   : 'PIROSNav/Subscribe'
//  '<S8>'   : 'PIROSNav/Subscribe1'
//  '<S9>'   : 'PIROSNav/Subsystem'
//  '<S10>'  : 'PIROSNav/Counter Limited/Increment Real World'
//  '<S11>'  : 'PIROSNav/Counter Limited/Wrap To Zero'
//  '<S12>'  : 'PIROSNav/GetRosMessage1/MATLAB Function'
//  '<S13>'  : 'PIROSNav/GetRosMessage1/MATLAB Function1'
//  '<S14>'  : 'PIROSNav/GetRosMessage1/XboxControllerMappings '
//  '<S15>'  : 'PIROSNav/PiSenseHat/MATLAB Function'
//  '<S16>'  : 'PIROSNav/PiSenseHat/MATLAB Function1'
//  '<S17>'  : 'PIROSNav/PiSenseHat/MATLAB Function2'
//  '<S18>'  : 'PIROSNav/Subscribe/Enabled Subsystem'
//  '<S19>'  : 'PIROSNav/Subscribe1/Enabled Subsystem'

#endif                                 // RTW_HEADER_PIROSNav_h_

//
// File trailer for generated code.
//
// [EOF]
//
