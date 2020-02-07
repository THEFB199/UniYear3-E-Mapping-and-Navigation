//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PIROSNav_types.h
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
#ifndef RTW_HEADER_PIROSNav_types_h_
#define RTW_HEADER_PIROSNav_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_PIROSNav_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_PIROSNav_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_PIROSNav_geometry_msgs_Vector3;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_PIROSNav_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_PIROSNav_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
typedef struct {
  // MsgType=geometry_msgs/Vector3
  SL_Bus_PIROSNav_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_PIROSNav_geometry_msgs_Vector3 Angular;
} SL_Bus_PIROSNav_geometry_msgs_Twist;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_PIROSNav_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_PIROSNav_ros_time_Time_

// MsgType=ros_time/Time
typedef struct {
  real_T Sec;
  real_T Nsec;
} SL_Bus_PIROSNav_ros_time_Time;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_PIROSNav_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_PIROSNav_std_msgs_Header_

// MsgType=std_msgs/Header
typedef struct {
  uint32_T Seq;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;

  // MsgType=ros_time/Time
  SL_Bus_PIROSNav_ros_time_Time Stamp;
} SL_Bus_PIROSNav_std_msgs_Header;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_PIROSNav_sensor_msgs_Joy_
#define DEFINED_TYPEDEF_FOR_SL_Bus_PIROSNav_sensor_msgs_Joy_

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
  SL_Bus_PIROSNav_std_msgs_Header Header;
} SL_Bus_PIROSNav_sensor_msgs_Joy;

#endif

// Custom Type definition for MATLABSystem: '<S9>/SPI Master Transfer'
#include "MW_SVD.h"
#ifndef typedef_d_codertarget_raspi_internal__T
#define typedef_d_codertarget_raspi_internal__T

typedef struct {
  int32_T __dummy;
} d_codertarget_raspi_internal__T;

#endif                                 //typedef_d_codertarget_raspi_internal__T

#ifndef typedef_raspi_internal_hts221Block_PI_T
#define typedef_raspi_internal_hts221Block_PI_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_codertarget_raspi_internal__T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
  real_T T0_degC;
  real_T T1_degC;
  real_T T0_out;
  real_T T1_out;
  real_T H0_rh;
  real_T H1_rh;
  real_T H0_T0_out;
  real_T H1_T0_out;
} raspi_internal_hts221Block_PI_T;

#endif                                 //typedef_raspi_internal_hts221Block_PI_T

#ifndef typedef_raspi_internal_lps25hBlock_PI_T
#define typedef_raspi_internal_lps25hBlock_PI_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_codertarget_raspi_internal__T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
  real_T p_h;
  real_T p_l;
  real_T p_xl;
  int16_T t_h;
  int16_T t_l;
  real_T CTRL_REG1_Value;
} raspi_internal_lps25hBlock_PI_T;

#endif                                 //typedef_raspi_internal_lps25hBlock_PI_T

#ifndef typedef_f_codertarget_raspi_internal__T
#define typedef_f_codertarget_raspi_internal__T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  d_codertarget_raspi_internal__T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
} f_codertarget_raspi_internal__T;

#endif                                 //typedef_f_codertarget_raspi_internal__T

#ifndef typedef_g_codertarget_raspi_internal__T
#define typedef_g_codertarget_raspi_internal__T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  d_codertarget_raspi_internal__T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
} g_codertarget_raspi_internal__T;

#endif                                 //typedef_g_codertarget_raspi_internal__T

// Custom Type definition for MATLAB Function: '<S6>/MATLAB Function'
#ifndef typedef_struct_T_PIROSNav_T
#define typedef_struct_T_PIROSNav_T

typedef struct {
  real_T a;
  real_T b;
  real_T c;
  real_T d;
} struct_T_PIROSNav_T;

#endif                                 //typedef_struct_T_PIROSNav_T

#ifndef typedef_fusion_internal_frames_NED_PI_T
#define typedef_fusion_internal_frames_NED_PI_T

typedef struct {
  int32_T __dummy;
} fusion_internal_frames_NED_PI_T;

#endif                                 //typedef_fusion_internal_frames_NED_PI_T

#ifndef typedef_c_matlabshared_rotations_inte_T
#define typedef_c_matlabshared_rotations_inte_T

typedef struct {
  real_T a;
  real_T b;
  real_T c;
  real_T d;
} c_matlabshared_rotations_inte_T;

#endif                                 //typedef_c_matlabshared_rotations_inte_T

#ifndef typedef_ros_slros_internal_block_Subs_T
#define typedef_ros_slros_internal_block_Subs_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
} ros_slros_internal_block_Subs_T;

#endif                                 //typedef_ros_slros_internal_block_Subs_T

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

#ifndef typedef_raspi_internal_lsm9ds1Block_P_T
#define typedef_raspi_internal_lsm9ds1Block_P_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T CalGyroA[9];
  real_T CalGyroB[3];
  real_T CalAccelA[9];
  real_T CalAccelB[3];
  real_T CalMagA[9];
  real_T CalMagB[3];
  f_codertarget_raspi_internal__T i2cobj_A_G;
  g_codertarget_raspi_internal__T i2cobj_MAG;
} raspi_internal_lsm9ds1Block_P_T;

#endif                                 //typedef_raspi_internal_lsm9ds1Block_P_T

// Custom Type definition for MATLAB Function: '<S6>/MATLAB Function'
#ifndef typedef_cell_wrap_3_PIROSNav_T
#define typedef_cell_wrap_3_PIROSNav_T

typedef struct {
  uint32_T f1[8];
} cell_wrap_3_PIROSNav_T;

#endif                                 //typedef_cell_wrap_3_PIROSNav_T

#ifndef typedef_c_fusion_internal_coder_ahrsf_T
#define typedef_c_fusion_internal_coder_ahrsf_T

typedef struct {
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  cell_wrap_3_PIROSNav_T inputVarSize[3];
  real_T AccelerometerNoise;
  real_T GyroscopeNoise;
  real_T GyroscopeDriftNoise;
  real_T LinearAccelerationNoise;
  real_T LinearAccelerationDecayFactor;
  real_T pQw[144];
  real_T pQv[36];
  c_matlabshared_rotations_inte_T pOrientPost;
  c_matlabshared_rotations_inte_T pOrientPrior;
  boolean_T pFirstTime;
  fusion_internal_frames_NED_PI_T *pRefSys;
  real_T pSensorPeriod;
  real_T pKalmanPeriod;
  real_T pGyroOffset[3];
  real_T pLinAccelPrior[3];
  real_T pLinAccelPost[3];
  real_T pInputPrototype[3];
  real_T MagnetometerNoise;
  real_T MagneticDisturbanceNoise;
  real_T MagneticDisturbanceDecayFactor;
  real_T ExpectedMagneticFieldStrength;
  real_T pMagVec[3];
} c_fusion_internal_coder_ahrsf_T;

#endif                                 //typedef_c_fusion_internal_coder_ahrsf_T

// Parameters (default storage)
typedef struct P_PIROSNav_T_ P_PIROSNav_T;

// Forward declaration for rtModel
typedef struct tag_RTM_PIROSNav_T RT_MODEL_PIROSNav_T;

#endif                                 // RTW_HEADER_PIROSNav_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
