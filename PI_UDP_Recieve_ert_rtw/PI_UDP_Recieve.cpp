//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PI_UDP_Recieve.cpp
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
#include "PI_UDP_Recieve.h"
#include "PI_UDP_Recieve_private.h"
#include "PI_UDP_Recieve_dt.h"

// Block signals (default storage)
B_PI_UDP_Recieve_T PI_UDP_Recieve_B;

// Block states (default storage)
DW_PI_UDP_Recieve_T PI_UDP_Recieve_DW;

// Previous zero-crossings (trigger) states
PrevZCX_PI_UDP_Recieve_T PI_UDP_Recieve_PrevZCX;

// Real-time model
RT_MODEL_PI_UDP_Recieve_T PI_UDP_Recieve_M_ = RT_MODEL_PI_UDP_Recieve_T();
RT_MODEL_PI_UDP_Recieve_T *const PI_UDP_Recieve_M = &PI_UDP_Recieve_M_;

// Forward declaration for local functions
static void matlabCodegenHandle_matlabCod_c(ros_slros_internal_block_Subs_T *obj);
static void PI_UDP_Recie_SystemCore_release(const
  codertarget_raspi_internal_SP_T *obj);
static void PI_UDP_Reciev_SystemCore_delete(const
  codertarget_raspi_internal_SP_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_raspi_internal_SP_T *obj);
static void rate_monotonic_scheduler(void);
real32_T look1_iflf_binlcpw(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T maxIndex)
{
  real32_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  // Column-major Lookup 1-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear point-slope'
  // Extrapolation method: 'Clip'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Clip'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
    // Binary Search
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0F;
  }

  // Column-major Interpolation 1-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'portable wrapping'

  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to "remember" which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void PI_UDP_Recieve_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(PI_UDP_Recieve_M, 1));
}

//
//   This function updates active task flag for each subrate
// and rate transition flags for tasks that exchange data.
// The function assumes rate-monotonic multitasking scheduler.
// The function must be called at model base rate so that
// the generated code self-manages all its subrates and rate
// transition flags.
//
static void rate_monotonic_scheduler(void)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (PI_UDP_Recieve_M->Timing.TaskCounters.TID[1])++;
  if ((PI_UDP_Recieve_M->Timing.TaskCounters.TID[1]) > 9) {// Sample time: [1.0s, 0.0s] 
    PI_UDP_Recieve_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if (static_cast<real32_T>(fabs(static_cast<real_T>(u))) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = static_cast<real32_T>(floor(static_cast<real_T>((u + 0.5F))));
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = static_cast<real32_T>(ceil(static_cast<real_T>((u - 0.5F))));
    }
  } else {
    y = u;
  }

  return y;
}

static void matlabCodegenHandle_matlabCod_c(ros_slros_internal_block_Subs_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void PI_UDP_Recie_SystemCore_release(const
  codertarget_raspi_internal_SP_T *obj)
{
  uint32_T PinNameLoc;
  uint32_T MOSIPinLoc;
  uint32_T MISOPinLoc;
  uint32_T SCKPinLoc;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    PinNameLoc = SPI0_CE0;
    MOSIPinLoc = MW_UNDEFINED_VALUE;
    MISOPinLoc = MW_UNDEFINED_VALUE;
    SCKPinLoc = MW_UNDEFINED_VALUE;
    MW_SPI_Close(obj->MW_SPI_HANDLE, MOSIPinLoc, MISOPinLoc, SCKPinLoc,
                 PinNameLoc);
  }
}

static void PI_UDP_Reciev_SystemCore_delete(const
  codertarget_raspi_internal_SP_T *obj)
{
  PI_UDP_Recie_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(codertarget_raspi_internal_SP_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    PI_UDP_Reciev_SystemCore_delete(obj);
  }
}

// Model step function for TID0
void PI_UDP_Recieve_step0(void)        // Sample time: [0.1s, 0.0s]
{
  uint32_T PinNameLoc;
  uint8_T status;
  MW_SPI_Mode_type ClockModeValue;
  MW_SPI_FirstBitTransfer_Type MsbFirstTransferLoc;
  uint16_T b_x[7];
  int32_T b_k;
  uint8_T y[2];
  uint8_T b_x_0[2];
  uint16_T y_0;
  boolean_T b_varargout_1;
  real32_T tmp;
  uint16_T b_x_1;

  {                                    // Sample time: [0.1s, 0.0s]
    rate_monotonic_scheduler();
  }

  // Reset subsysRan breadcrumbs
  srClearBC(PI_UDP_Recieve_DW.GetRosMessage_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(PI_UDP_Recieve_DW.EnabledSubsystem_SubsysRanBC);

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Inport: '<S7>/In1'

  b_varargout_1 = Sub_PI_UDP_Recieve_153.getLatestMessage
    (&PI_UDP_Recieve_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S7>/Enable'

  if (b_varargout_1) {
    PI_UDP_Recieve_B.In1 = PI_UDP_Recieve_B.b_varargout_2;
    srUpdateBC(PI_UDP_Recieve_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'

  // Outputs for Triggered SubSystem: '<Root>/GetRosMessage' incorporates:
  //   TriggerPort: '<S3>/Trigger'

  if (b_varargout_1 && (PI_UDP_Recieve_PrevZCX.GetRosMessage_Trig_ZCE !=
                        POS_ZCSIG)) {
    // DataTypeConversion: '<S3>/Data Type Conversion1'
    PI_UDP_Recieve_B.DataTypeConversion1 = static_cast<real32_T>
      (PI_UDP_Recieve_B.In1.Linear.X);

    // DataTypeConversion: '<S3>/Data Type Conversion2'
    PI_UDP_Recieve_B.DataTypeConversion2 = static_cast<real32_T>
      (PI_UDP_Recieve_B.In1.Angular.Z);

    // DataTypeConversion: '<S3>/Data Type Conversion3'
    PI_UDP_Recieve_B.DataTypeConversion3 = static_cast<real32_T>
      (PI_UDP_Recieve_B.In1.Linear.Y);

    // DataTypeConversion: '<S3>/Data Type Conversion4'
    PI_UDP_Recieve_B.DataTypeConversion4 = static_cast<real32_T>
      (PI_UDP_Recieve_B.In1.Linear.Z);

    // DataTypeConversion: '<S3>/Data Type Conversion5'
    PI_UDP_Recieve_B.DataTypeConversion5 = static_cast<real32_T>
      (PI_UDP_Recieve_B.In1.Angular.X);

    // DataTypeConversion: '<S3>/Data Type Conversion6'
    PI_UDP_Recieve_B.DataTypeConversion6 = static_cast<real32_T>
      (PI_UDP_Recieve_B.In1.Angular.Y);
    PI_UDP_Recieve_DW.GetRosMessage_SubsysRanBC = 4;
  }

  PI_UDP_Recieve_PrevZCX.GetRosMessage_Trig_ZCE = b_varargout_1;

  // End of MATLABSystem: '<S4>/SourceBlock'
  // End of Outputs for SubSystem: '<Root>/GetRosMessage'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Lookup_n-D: '<S2>/1-D Lookup Table9' incorporates:
  //   Gain: '<Root>/Gain7'

  PI_UDP_Recieve_B.Left_right = look1_iflf_binlcpw(PI_UDP_Recieve_P.Gain7_Gain *
    PI_UDP_Recieve_B.DataTypeConversion1,
    PI_UDP_Recieve_P.uDLookupTable9_bp01Data,
    PI_UDP_Recieve_P.uDLookupTable9_tableData, 4U);

  // Lookup_n-D: '<S2>/1-D Lookup Table1' incorporates:
  //   Gain: '<Root>/Gain8'

  PI_UDP_Recieve_B.Up_Down = look1_iflf_binlcpw(PI_UDP_Recieve_P.Gain8_Gain *
    PI_UDP_Recieve_B.DataTypeConversion2,
    PI_UDP_Recieve_P.uDLookupTable1_bp01Data,
    PI_UDP_Recieve_P.uDLookupTable1_tableData, 4U);

  // Lookup_n-D: '<Root>/1-D Lookup Table7' incorporates:
  //   Constant: '<Root>/Constant4'
  //   Gain: '<Root>/Gain6'

  PI_UDP_Recieve_B.Up_Down_h = look1_iflf_binlcpw(PI_UDP_Recieve_P.Gain6_Gain *
    PI_UDP_Recieve_P.Constant4_Value, PI_UDP_Recieve_P.uDLookupTable7_bp01Data,
    PI_UDP_Recieve_P.uDLookupTable7_tableData, 4U);

  // Lookup_n-D: '<Root>/1-D Lookup Table1' incorporates:
  //   Constant: '<Root>/Constant5'
  //   Gain: '<Root>/Gain2'

  PI_UDP_Recieve_B.uDLookupTable1 = look1_iflf_binlcpw
    (PI_UDP_Recieve_P.Gain2_Gain * PI_UDP_Recieve_P.Constant5_Value,
     PI_UDP_Recieve_P.uDLookupTable1_bp01Data_b,
     PI_UDP_Recieve_P.uDLookupTable1_tableData_g, 4U);

  // Lookup_n-D: '<Root>/1-D Lookup Table2' incorporates:
  //   Constant: '<Root>/Constant6'
  //   Gain: '<Root>/Gain3'

  PI_UDP_Recieve_B.Left_right_c = look1_iflf_binlcpw(PI_UDP_Recieve_P.Gain3_Gain
    * PI_UDP_Recieve_P.Constant6_Value, PI_UDP_Recieve_P.uDLookupTable2_bp01Data,
    PI_UDP_Recieve_P.uDLookupTable2_tableData, 2U);

  // Lookup_n-D: '<Root>/1-D Lookup Table3' incorporates:
  //   Constant: '<Root>/Constant7'
  //   Gain: '<Root>/Gain1'

  PI_UDP_Recieve_B.Up_Down_n = look1_iflf_binlcpw(PI_UDP_Recieve_P.Gain1_Gain *
    PI_UDP_Recieve_P.Constant7_Value, PI_UDP_Recieve_P.uDLookupTable3_bp01Data,
    PI_UDP_Recieve_P.uDLookupTable3_tableData, 2U);

  // Constant: '<Root>/Constant2'
  PI_UDP_Recieve_B.Constant2 = PI_UDP_Recieve_P.Constant2_Value;

  // DataTypeConversion: '<Root>/Data Type Conversion'
  tmp = rt_roundf_snf(PI_UDP_Recieve_B.Left_right);
  if (tmp < 65536.0F) {
    if (tmp >= 0.0F) {
      // MATLABSystem: '<Root>/SPI Master Transfer'
      b_x[0] = static_cast<uint16_T>(tmp);
    } else {
      // MATLABSystem: '<Root>/SPI Master Transfer'
      b_x[0] = 0U;
    }
  } else {
    // MATLABSystem: '<Root>/SPI Master Transfer'
    b_x[0] = MAX_uint16_T;
  }

  tmp = rt_roundf_snf(PI_UDP_Recieve_B.Up_Down);
  if (tmp < 65536.0F) {
    if (tmp >= 0.0F) {
      // MATLABSystem: '<Root>/SPI Master Transfer'
      b_x[1] = static_cast<uint16_T>(tmp);
    } else {
      // MATLABSystem: '<Root>/SPI Master Transfer'
      b_x[1] = 0U;
    }
  } else {
    // MATLABSystem: '<Root>/SPI Master Transfer'
    b_x[1] = MAX_uint16_T;
  }

  tmp = rt_roundf_snf(PI_UDP_Recieve_B.Up_Down_h);
  if (tmp < 65536.0F) {
    if (tmp >= 0.0F) {
      // MATLABSystem: '<Root>/SPI Master Transfer'
      b_x[2] = static_cast<uint16_T>(tmp);
    } else {
      // MATLABSystem: '<Root>/SPI Master Transfer'
      b_x[2] = 0U;
    }
  } else {
    // MATLABSystem: '<Root>/SPI Master Transfer'
    b_x[2] = MAX_uint16_T;
  }

  tmp = rt_roundf_snf(PI_UDP_Recieve_B.uDLookupTable1);
  if (tmp < 65536.0F) {
    if (tmp >= 0.0F) {
      // MATLABSystem: '<Root>/SPI Master Transfer'
      b_x[3] = static_cast<uint16_T>(tmp);
    } else {
      // MATLABSystem: '<Root>/SPI Master Transfer'
      b_x[3] = 0U;
    }
  } else {
    // MATLABSystem: '<Root>/SPI Master Transfer'
    b_x[3] = MAX_uint16_T;
  }

  tmp = rt_roundf_snf(PI_UDP_Recieve_B.Left_right_c);
  if (tmp < 65536.0F) {
    if (tmp >= 0.0F) {
      // MATLABSystem: '<Root>/SPI Master Transfer'
      b_x[4] = static_cast<uint16_T>(tmp);
    } else {
      // MATLABSystem: '<Root>/SPI Master Transfer'
      b_x[4] = 0U;
    }
  } else {
    // MATLABSystem: '<Root>/SPI Master Transfer'
    b_x[4] = MAX_uint16_T;
  }

  tmp = rt_roundf_snf(PI_UDP_Recieve_B.Up_Down_n);
  if (tmp < 65536.0F) {
    if (tmp >= 0.0F) {
      // MATLABSystem: '<Root>/SPI Master Transfer'
      b_x[5] = static_cast<uint16_T>(tmp);
    } else {
      // MATLABSystem: '<Root>/SPI Master Transfer'
      b_x[5] = 0U;
    }
  } else {
    // MATLABSystem: '<Root>/SPI Master Transfer'
    b_x[5] = MAX_uint16_T;
  }

  tmp = rt_roundf_snf(PI_UDP_Recieve_B.Constant2);
  if (tmp < 65536.0F) {
    if (tmp >= 0.0F) {
      // MATLABSystem: '<Root>/SPI Master Transfer'
      b_x[6] = static_cast<uint16_T>(tmp);
    } else {
      // MATLABSystem: '<Root>/SPI Master Transfer'
      b_x[6] = 0U;
    }
  } else {
    // MATLABSystem: '<Root>/SPI Master Transfer'
    b_x[6] = MAX_uint16_T;
  }

  // End of DataTypeConversion: '<Root>/Data Type Conversion'

  // MATLABSystem: '<Root>/SPI Master Transfer'
  for (b_k = 0; b_k < 7; b_k++) {
    b_x_1 = b_x[b_k];
    memcpy((void *)&y[0], (void *)&b_x_1, (uint32_T)((size_t)2 * sizeof(uint8_T)));
    b_x_0[0] = y[1];
    b_x_0[1] = y[0];
    memcpy((void *)&y_0, (void *)&b_x_0[0], (uint32_T)((size_t)1 * sizeof
            (uint16_T)));
    b_x[b_k] = y_0;
  }

  memcpy((void *)&PI_UDP_Recieve_B.wrDataRaw[0], (void *)&b_x[0], (uint32_T)
         ((size_t)14 * sizeof(uint8_T)));
  PinNameLoc = SPI0_CE0;
  MW_SPI_SetSlaveSelect(PI_UDP_Recieve_DW.obj.MW_SPI_HANDLE, PinNameLoc, true);
  ClockModeValue = MW_SPI_MODE_0;
  MsbFirstTransferLoc = MW_SPI_MOST_SIGNIFICANT_BIT_FIRST;
  status = MW_SPI_SetFormat(PI_UDP_Recieve_DW.obj.MW_SPI_HANDLE, 8,
    ClockModeValue, MsbFirstTransferLoc);
  if (status == 0) {
    MW_SPI_MasterWriteRead_8bits(PI_UDP_Recieve_DW.obj.MW_SPI_HANDLE,
      PI_UDP_Recieve_B.wrDataRaw, PI_UDP_Recieve_B.rdDataRaw, 14U);
  }

  memcpy((void *)&PI_UDP_Recieve_B.SPIMasterTransfer[0], (void *)
         &PI_UDP_Recieve_B.rdDataRaw[0], (uint32_T)((size_t)7 * sizeof(uint16_T)));
  for (b_k = 0; b_k < 7; b_k++) {
    b_x_1 = PI_UDP_Recieve_B.SPIMasterTransfer[b_k];
    memcpy((void *)&y[0], (void *)&b_x_1, (uint32_T)((size_t)2 * sizeof(uint8_T)));
    b_x_0[0] = y[1];
    b_x_0[1] = y[0];
    memcpy((void *)&y_0, (void *)&b_x_0[0], (uint32_T)((size_t)1 * sizeof
            (uint16_T)));
    PI_UDP_Recieve_B.SPIMasterTransfer[b_k] = y_0;
  }

  // External mode
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, (real_T)PI_UDP_Recieve_M->Timing.taskTime0);

  // signal main to stop simulation
  {                                    // Sample time: [0.1s, 0.0s]
    if ((rtmGetTFinal(PI_UDP_Recieve_M)!=-1) &&
        !((rtmGetTFinal(PI_UDP_Recieve_M)-PI_UDP_Recieve_M->Timing.taskTime0) >
          PI_UDP_Recieve_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(PI_UDP_Recieve_M, "Simulation finished");
    }

    if (rtmGetStopRequested(PI_UDP_Recieve_M)) {
      rtmSetErrorStatus(PI_UDP_Recieve_M, "Simulation finished");
    }
  }

  // Update absolute time
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  PI_UDP_Recieve_M->Timing.taskTime0 =
    (++PI_UDP_Recieve_M->Timing.clockTick0) * PI_UDP_Recieve_M->Timing.stepSize0;
}

// Model step function for TID1
void PI_UDP_Recieve_step1(void)        // Sample time: [1.0s, 0.0s]
{
  // UnitDelay: '<S1>/Output'
  PI_UDP_Recieve_B.Output = PI_UDP_Recieve_DW.Output_DSTATE;

  // Sum: '<S5>/FixPt Sum1' incorporates:
  //   Constant: '<S5>/FixPt Constant'

  PI_UDP_Recieve_DW.Output_DSTATE = static_cast<uint8_T>((static_cast<uint32_T>
    (PI_UDP_Recieve_B.Output) + PI_UDP_Recieve_P.FixPtConstant_Value));

  // Switch: '<S6>/FixPt Switch' incorporates:
  //   Constant: '<S6>/Constant'
  //   UnitDelay: '<S1>/Output'

  if (PI_UDP_Recieve_DW.Output_DSTATE > PI_UDP_Recieve_P.CounterLimited_uplimit)
  {
    PI_UDP_Recieve_DW.Output_DSTATE = PI_UDP_Recieve_P.Constant_Value_m;
  }

  // End of Switch: '<S6>/FixPt Switch'
  rtExtModeUpload(1, (real_T)((PI_UDP_Recieve_M->Timing.clockTick1) * 1.0));

  // Update absolute time
  // The "clockTick1" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 1.0, which is the step size
  //  of the task. Size of "clockTick1" ensures timer will not overflow during the
  //  application lifespan selected.

  PI_UDP_Recieve_M->Timing.clockTick1++;
}

// Model step wrapper function for compatibility with a static main program
void PI_UDP_Recieve_step(int_T tid)
{
  switch (tid) {
   case 0 :
    PI_UDP_Recieve_step0();
    break;

   case 1 :
    PI_UDP_Recieve_step1();
    break;

   default :
    break;
  }
}

// Model initialize function
void PI_UDP_Recieve_initialize(void)
{
  // Registration code
  rtmSetTFinal(PI_UDP_Recieve_M, -1);
  PI_UDP_Recieve_M->Timing.stepSize0 = 0.1;

  // External mode info
  PI_UDP_Recieve_M->Sizes.checksums[0] = (3389596803U);
  PI_UDP_Recieve_M->Sizes.checksums[1] = (4147866139U);
  PI_UDP_Recieve_M->Sizes.checksums[2] = (3992559819U);
  PI_UDP_Recieve_M->Sizes.checksums[3] = (2027735132U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    PI_UDP_Recieve_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)&PI_UDP_Recieve_DW.GetRosMessage_SubsysRanBC;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)
      &PI_UDP_Recieve_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PI_UDP_Recieve_M->extModeInfo,
      &PI_UDP_Recieve_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PI_UDP_Recieve_M->extModeInfo,
                        PI_UDP_Recieve_M->Sizes.checksums);
    rteiSetTPtr(PI_UDP_Recieve_M->extModeInfo, rtmGetTPtr(PI_UDP_Recieve_M));
  }

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    PI_UDP_Recieve_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;

    // Parameters transition table
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_raspi_internal_SP_T *obj;
    uint32_T SSPinNameLoc;
    uint32_T MOSIPinLoc;
    uint32_T MISOPinLoc;
    uint32_T SCKPinLoc;
    char_T tmp[17];
    int32_T i;
    static const char_T tmp_0[16] = { '/', 'p', 'l', 'a', 'n', 'n', 'e', 'r',
      '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S4>/SourceBlock'
    PI_UDP_Recieve_DW.obj_c.matlabCodegenIsDeleted = false;
    PI_UDP_Recieve_DW.obj_c.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      tmp[i] = tmp_0[i];
    }

    tmp[16] = '\x00';
    Sub_PI_UDP_Recieve_153.createSubscriber(tmp, 1);
    PI_UDP_Recieve_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // Start for MATLABSystem: '<Root>/SPI Master Transfer'
    PI_UDP_Recieve_DW.obj.matlabCodegenIsDeleted = true;
    PI_UDP_Recieve_DW.obj.isInitialized = 0;
    PI_UDP_Recieve_DW.obj.matlabCodegenIsDeleted = false;
    obj = &PI_UDP_Recieve_DW.obj;
    PI_UDP_Recieve_DW.obj.isSetupComplete = false;
    PI_UDP_Recieve_DW.obj.isInitialized = 1;
    SSPinNameLoc = SPI0_CE0;
    MOSIPinLoc = MW_UNDEFINED_VALUE;
    MISOPinLoc = MW_UNDEFINED_VALUE;
    SCKPinLoc = MW_UNDEFINED_VALUE;
    obj->MW_SPI_HANDLE = MW_SPI_Open(0U, MOSIPinLoc, MISOPinLoc, SCKPinLoc,
      SSPinNameLoc, true, 0);
    MW_SPI_SetBusSpeed(PI_UDP_Recieve_DW.obj.MW_SPI_HANDLE, 500000U);
    PI_UDP_Recieve_DW.obj.isSetupComplete = true;
    PI_UDP_Recieve_PrevZCX.GetRosMessage_Trig_ZCE = POS_ZCSIG;

    // InitializeConditions for UnitDelay: '<S1>/Output'
    PI_UDP_Recieve_DW.Output_DSTATE = PI_UDP_Recieve_P.Output_InitialCondition;

    // SystemInitialize for Triggered SubSystem: '<Root>/GetRosMessage'
    // SystemInitialize for Outport: '<S3>/Lx'
    PI_UDP_Recieve_B.DataTypeConversion1 = PI_UDP_Recieve_P.Lx_Y0;

    // SystemInitialize for Outport: '<S3>/Ly '
    PI_UDP_Recieve_B.DataTypeConversion3 = PI_UDP_Recieve_P.Ly_Y0;

    // SystemInitialize for Outport: '<S3>/Lz'
    PI_UDP_Recieve_B.DataTypeConversion4 = PI_UDP_Recieve_P.Lz_Y0;

    // SystemInitialize for Outport: '<S3>/Ax'
    PI_UDP_Recieve_B.DataTypeConversion5 = PI_UDP_Recieve_P.Ax_Y0;

    // SystemInitialize for Outport: '<S3>/Ay '
    PI_UDP_Recieve_B.DataTypeConversion6 = PI_UDP_Recieve_P.Ay_Y0;

    // SystemInitialize for Outport: '<S3>/Az '
    PI_UDP_Recieve_B.DataTypeConversion2 = PI_UDP_Recieve_P.Az_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/GetRosMessage'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S7>/Out1'
    PI_UDP_Recieve_B.In1 = PI_UDP_Recieve_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'
  }
}

// Model terminate function
void PI_UDP_Recieve_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  matlabCodegenHandle_matlabCod_c(&PI_UDP_Recieve_DW.obj_c);

  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for MATLABSystem: '<Root>/SPI Master Transfer'
  matlabCodegenHandle_matlabCodeg(&PI_UDP_Recieve_DW.obj);
}

//
// File trailer for generated code.
//
// [EOF]
//
