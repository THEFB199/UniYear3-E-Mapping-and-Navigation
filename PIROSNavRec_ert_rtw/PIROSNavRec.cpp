//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PIROSNavRec.cpp
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
#include "PIROSNavRec.h"
#include "PIROSNavRec_private.h"
#include "PIROSNavRec_dt.h"

// Block signals (default storage)
B_PIROSNavRec_T PIROSNavRec_B;

// Block states (default storage)
DW_PIROSNavRec_T PIROSNavRec_DW;

// Previous zero-crossings (trigger) states
PrevZCX_PIROSNavRec_T PIROSNavRec_PrevZCX;

// Real-time model
RT_MODEL_PIROSNavRec_T PIROSNavRec_M_ = RT_MODEL_PIROSNavRec_T();
RT_MODEL_PIROSNavRec_T *const PIROSNavRec_M = &PIROSNavRec_M_;

// Forward declaration for local functions
static void matlabCodegenHandle_matlabCod_a(ros_slros_internal_block_Subs_T *obj);
static void PIROSNavRec_SystemCore_release(const codertarget_raspi_internal_SP_T
  *obj);
static void PIROSNavRec_SystemCore_delete(const codertarget_raspi_internal_SP_T *
  obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_raspi_internal_SP_T *obj);
static void rate_scheduler(void);
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
//   This function updates active task flag for each subrate.
// The function is called at model base rate, hence the
// generated code self-manages all its subrates.
//
static void rate_scheduler(void)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (PIROSNavRec_M->Timing.TaskCounters.TID[1])++;
  if ((PIROSNavRec_M->Timing.TaskCounters.TID[1]) > 9) {// Sample time: [1.0s, 0.0s] 
    PIROSNavRec_M->Timing.TaskCounters.TID[1] = 0;
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

static void matlabCodegenHandle_matlabCod_a(ros_slros_internal_block_Subs_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void PIROSNavRec_SystemCore_release(const codertarget_raspi_internal_SP_T
  *obj)
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

static void PIROSNavRec_SystemCore_delete(const codertarget_raspi_internal_SP_T *
  obj)
{
  PIROSNavRec_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(codertarget_raspi_internal_SP_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    PIROSNavRec_SystemCore_delete(obj);
  }
}

// Model step function
void PIROSNavRec_step(void)
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
  real32_T tmp;
  uint16_T b_x_1;

  // Reset subsysRan breadcrumbs
  srClearBC(PIROSNavRec_DW.GetRosMessage_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(PIROSNavRec_DW.EnabledSubsystem_SubsysRanBC);

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S4>/SourceBlock'
  PIROSNavRec_B.SourceBlock_o1 = Sub_PIROSNavRec_21.getLatestMessage
    (&PIROSNavRec_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S7>/Enable'

  if (PIROSNavRec_B.SourceBlock_o1) {
    // Inport: '<S7>/In1' incorporates:
    //   MATLABSystem: '<S4>/SourceBlock'

    PIROSNavRec_B.In1 = PIROSNavRec_B.b_varargout_2;
    srUpdateBC(PIROSNavRec_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Outputs for Triggered SubSystem: '<Root>/GetRosMessage' incorporates:
  //   TriggerPort: '<S3>/Trigger'

  if (PIROSNavRec_B.SourceBlock_o1 &&
      (PIROSNavRec_PrevZCX.GetRosMessage_Trig_ZCE != POS_ZCSIG)) {
    // DataTypeConversion: '<S3>/Data Type Conversion1'
    PIROSNavRec_B.DataTypeConversion1 = static_cast<real32_T>
      (PIROSNavRec_B.In1.Linear.X);

    // DataTypeConversion: '<S3>/Data Type Conversion2'
    PIROSNavRec_B.DataTypeConversion2 = static_cast<real32_T>
      (PIROSNavRec_B.In1.Angular.Z);

    // DataTypeConversion: '<S3>/Data Type Conversion3'
    PIROSNavRec_B.DataTypeConversion3 = static_cast<real32_T>
      (PIROSNavRec_B.In1.Linear.Y);

    // DataTypeConversion: '<S3>/Data Type Conversion4'
    PIROSNavRec_B.DataTypeConversion4 = static_cast<real32_T>
      (PIROSNavRec_B.In1.Linear.Z);

    // DataTypeConversion: '<S3>/Data Type Conversion5'
    PIROSNavRec_B.DataTypeConversion5 = static_cast<real32_T>
      (PIROSNavRec_B.In1.Angular.X);

    // DataTypeConversion: '<S3>/Data Type Conversion6'
    PIROSNavRec_B.DataTypeConversion6 = static_cast<real32_T>
      (PIROSNavRec_B.In1.Angular.Y);
    PIROSNavRec_DW.GetRosMessage_SubsysRanBC = 4;
  }

  PIROSNavRec_PrevZCX.GetRosMessage_Trig_ZCE = PIROSNavRec_B.SourceBlock_o1;

  // End of Outputs for SubSystem: '<Root>/GetRosMessage'

  // ManualSwitch: '<Root>/Manual Switch1' incorporates:
  //   Constant: '<Root>/Constant6'
  //   Gain: '<Root>/Gain7'

  if (PIROSNavRec_P.ManualSwitch1_CurrentSetting == 1) {
    tmp = PIROSNavRec_P.Gain7_Gain * PIROSNavRec_B.DataTypeConversion1;
  } else {
    tmp = PIROSNavRec_P.Constant6_Value;
  }

  // End of ManualSwitch: '<Root>/Manual Switch1'

  // DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
  //   Lookup_n-D: '<S2>/1-D Lookup Table9'

  tmp = rt_roundf_snf(look1_iflf_binlcpw(tmp,
    PIROSNavRec_P.uDLookupTable9_bp01Data,
    PIROSNavRec_P.uDLookupTable9_tableData, 4U));
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

  // ManualSwitch: '<Root>/Manual Switch' incorporates:
  //   Constant: '<Root>/Constant'
  //   Gain: '<Root>/Gain8'

  if (PIROSNavRec_P.ManualSwitch_CurrentSetting == 1) {
    tmp = PIROSNavRec_P.Constant_Value_b;
  } else {
    tmp = PIROSNavRec_P.Gain8_Gain * PIROSNavRec_B.DataTypeConversion2;
  }

  // End of ManualSwitch: '<Root>/Manual Switch'

  // DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Constant3'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<Root>/Constant5'
  //   Lookup_n-D: '<S2>/1-D Lookup Table1'

  tmp = rt_roundf_snf(look1_iflf_binlcpw(tmp,
    PIROSNavRec_P.uDLookupTable1_bp01Data,
    PIROSNavRec_P.uDLookupTable1_tableData, 4U));
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

  tmp = rt_roundf_snf(PIROSNavRec_P.Constant5_Value);
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

  tmp = rt_roundf_snf(PIROSNavRec_P.Constant4_Value);
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

  tmp = rt_roundf_snf(PIROSNavRec_P.Constant3_Value);
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

  tmp = rt_roundf_snf(PIROSNavRec_P.Constant1_Value);
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

  tmp = rt_roundf_snf(PIROSNavRec_P.Constant2_Value);
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

  memcpy((void *)&PIROSNavRec_B.wrDataRaw[0], (void *)&b_x[0], (uint32_T)
         ((size_t)14 * sizeof(uint8_T)));
  PinNameLoc = SPI0_CE0;
  MW_SPI_SetSlaveSelect(PIROSNavRec_DW.obj.MW_SPI_HANDLE, PinNameLoc, true);
  ClockModeValue = MW_SPI_MODE_0;
  MsbFirstTransferLoc = MW_SPI_MOST_SIGNIFICANT_BIT_FIRST;
  status = MW_SPI_SetFormat(PIROSNavRec_DW.obj.MW_SPI_HANDLE, 8, ClockModeValue,
    MsbFirstTransferLoc);
  if (status == 0) {
    MW_SPI_MasterWriteRead_8bits(PIROSNavRec_DW.obj.MW_SPI_HANDLE,
      PIROSNavRec_B.wrDataRaw, PIROSNavRec_B.rdDataRaw, 14U);
  }

  memcpy((void *)&PIROSNavRec_B.SPIMasterTransfer[0], (void *)
         &PIROSNavRec_B.rdDataRaw[0], (uint32_T)((size_t)7 * sizeof(uint16_T)));
  for (b_k = 0; b_k < 7; b_k++) {
    b_x_1 = PIROSNavRec_B.SPIMasterTransfer[b_k];
    memcpy((void *)&y[0], (void *)&b_x_1, (uint32_T)((size_t)2 * sizeof(uint8_T)));
    b_x_0[0] = y[1];
    b_x_0[1] = y[0];
    memcpy((void *)&y_0, (void *)&b_x_0[0], (uint32_T)((size_t)1 * sizeof
            (uint16_T)));
    PIROSNavRec_B.SPIMasterTransfer[b_k] = y_0;
  }

  if (PIROSNavRec_M->Timing.TaskCounters.TID[1] == 0) {
    // UnitDelay: '<S1>/Output'
    PIROSNavRec_B.Output = PIROSNavRec_DW.Output_DSTATE;

    // Sum: '<S5>/FixPt Sum1' incorporates:
    //   Constant: '<S5>/FixPt Constant'

    PIROSNavRec_DW.Output_DSTATE = static_cast<uint8_T>((static_cast<uint32_T>
      (PIROSNavRec_B.Output) + PIROSNavRec_P.FixPtConstant_Value));

    // Switch: '<S6>/FixPt Switch' incorporates:
    //   Constant: '<S6>/Constant'
    //   UnitDelay: '<S1>/Output'

    if (PIROSNavRec_DW.Output_DSTATE > PIROSNavRec_P.CounterLimited_uplimit) {
      PIROSNavRec_DW.Output_DSTATE = PIROSNavRec_P.Constant_Value_i;
    }

    // End of Switch: '<S6>/FixPt Switch'
  }

  // External mode
  rtExtModeUploadCheckTrigger(2);

  {                                    // Sample time: [0.1s, 0.0s]
    rtExtModeUpload(0, (real_T)PIROSNavRec_M->Timing.taskTime0);
  }

  if (PIROSNavRec_M->Timing.TaskCounters.TID[1] == 0) {// Sample time: [1.0s, 0.0s] 
    rtExtModeUpload(1, (real_T)((PIROSNavRec_M->Timing.clockTick1) * 1.0));
  }

  // signal main to stop simulation
  {                                    // Sample time: [0.1s, 0.0s]
    if ((rtmGetTFinal(PIROSNavRec_M)!=-1) &&
        !((rtmGetTFinal(PIROSNavRec_M)-PIROSNavRec_M->Timing.taskTime0) >
          PIROSNavRec_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(PIROSNavRec_M, "Simulation finished");
    }

    if (rtmGetStopRequested(PIROSNavRec_M)) {
      rtmSetErrorStatus(PIROSNavRec_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  PIROSNavRec_M->Timing.taskTime0 =
    (++PIROSNavRec_M->Timing.clockTick0) * PIROSNavRec_M->Timing.stepSize0;
  if (PIROSNavRec_M->Timing.TaskCounters.TID[1] == 0) {
    // Update absolute timer for sample time: [1.0s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 1.0, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    PIROSNavRec_M->Timing.clockTick1++;
  }

  rate_scheduler();
}

// Model initialize function
void PIROSNavRec_initialize(void)
{
  // Registration code
  rtmSetTFinal(PIROSNavRec_M, -1);
  PIROSNavRec_M->Timing.stepSize0 = 0.1;

  // External mode info
  PIROSNavRec_M->Sizes.checksums[0] = (3824279447U);
  PIROSNavRec_M->Sizes.checksums[1] = (803712296U);
  PIROSNavRec_M->Sizes.checksums[2] = (1380924021U);
  PIROSNavRec_M->Sizes.checksums[3] = (3581574213U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    PIROSNavRec_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = (sysRanDType *)&PIROSNavRec_DW.GetRosMessage_SubsysRanBC;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)&PIROSNavRec_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[10] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PIROSNavRec_M->extModeInfo,
      &PIROSNavRec_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PIROSNavRec_M->extModeInfo,
                        PIROSNavRec_M->Sizes.checksums);
    rteiSetTPtr(PIROSNavRec_M->extModeInfo, rtmGetTPtr(PIROSNavRec_M));
  }

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    PIROSNavRec_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    PIROSNavRec_DW.obj_n.matlabCodegenIsDeleted = false;
    PIROSNavRec_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      tmp[i] = tmp_0[i];
    }

    tmp[16] = '\x00';
    Sub_PIROSNavRec_21.createSubscriber(tmp, 1);
    PIROSNavRec_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // Start for MATLABSystem: '<Root>/SPI Master Transfer'
    PIROSNavRec_DW.obj.matlabCodegenIsDeleted = true;
    PIROSNavRec_DW.obj.isInitialized = 0;
    PIROSNavRec_DW.obj.matlabCodegenIsDeleted = false;
    obj = &PIROSNavRec_DW.obj;
    PIROSNavRec_DW.obj.isSetupComplete = false;
    PIROSNavRec_DW.obj.isInitialized = 1;
    SSPinNameLoc = SPI0_CE0;
    MOSIPinLoc = MW_UNDEFINED_VALUE;
    MISOPinLoc = MW_UNDEFINED_VALUE;
    SCKPinLoc = MW_UNDEFINED_VALUE;
    obj->MW_SPI_HANDLE = MW_SPI_Open(0U, MOSIPinLoc, MISOPinLoc, SCKPinLoc,
      SSPinNameLoc, true, 0);
    MW_SPI_SetBusSpeed(PIROSNavRec_DW.obj.MW_SPI_HANDLE, 500000U);
    PIROSNavRec_DW.obj.isSetupComplete = true;
    PIROSNavRec_PrevZCX.GetRosMessage_Trig_ZCE = POS_ZCSIG;

    // InitializeConditions for UnitDelay: '<S1>/Output'
    PIROSNavRec_DW.Output_DSTATE = PIROSNavRec_P.Output_InitialCondition;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S7>/Out1'
    PIROSNavRec_B.In1 = PIROSNavRec_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Triggered SubSystem: '<Root>/GetRosMessage'
    // SystemInitialize for Outport: '<S3>/Lx'
    PIROSNavRec_B.DataTypeConversion1 = PIROSNavRec_P.Lx_Y0;

    // SystemInitialize for Outport: '<S3>/Ly '
    PIROSNavRec_B.DataTypeConversion3 = PIROSNavRec_P.Ly_Y0;

    // SystemInitialize for Outport: '<S3>/Lz'
    PIROSNavRec_B.DataTypeConversion4 = PIROSNavRec_P.Lz_Y0;

    // SystemInitialize for Outport: '<S3>/Ax'
    PIROSNavRec_B.DataTypeConversion5 = PIROSNavRec_P.Ax_Y0;

    // SystemInitialize for Outport: '<S3>/Ay '
    PIROSNavRec_B.DataTypeConversion6 = PIROSNavRec_P.Ay_Y0;

    // SystemInitialize for Outport: '<S3>/Az '
    PIROSNavRec_B.DataTypeConversion2 = PIROSNavRec_P.Az_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/GetRosMessage'
  }
}

// Model terminate function
void PIROSNavRec_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  matlabCodegenHandle_matlabCod_a(&PIROSNavRec_DW.obj_n);

  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for MATLABSystem: '<Root>/SPI Master Transfer'
  matlabCodegenHandle_matlabCodeg(&PIROSNavRec_DW.obj);
}

//
// File trailer for generated code.
//
// [EOF]
//
