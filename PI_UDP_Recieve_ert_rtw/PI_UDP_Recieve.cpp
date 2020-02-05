//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PI_UDP_Recieve.cpp
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
#include "PI_UDP_Recieve.h"
#include "PI_UDP_Recieve_private.h"
#include "PI_UDP_Recieve_dt.h"

// Block signals (default storage)
B_PI_UDP_Recieve_T PI_UDP_Recieve_B;

// Block states (default storage)
DW_PI_UDP_Recieve_T PI_UDP_Recieve_DW;

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
  eventFlags[2] = ((boolean_T)rtmStepTask(PI_UDP_Recieve_M, 2));
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
  // To ensure a deterministic data transfer between two rates,
  //  data is transferred at the priority of a fast task and the frequency
  //  of the slow task.  The following flags indicate when the data transfer
  //  happens.  That is, a rate interaction flag is set true when both rates
  //  will run, and false otherwise.


  // tid 0 shares data with slower tid rate: 1
  PI_UDP_Recieve_M->Timing.RateInteraction.TID0_1 =
    (PI_UDP_Recieve_M->Timing.TaskCounters.TID[1] == 0);

  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (PI_UDP_Recieve_M->Timing.TaskCounters.TID[1])++;
  if ((PI_UDP_Recieve_M->Timing.TaskCounters.TID[1]) > 9) {// Sample time: [0.1s, 0.0s] 
    PI_UDP_Recieve_M->Timing.TaskCounters.TID[1] = 0;
  }

  (PI_UDP_Recieve_M->Timing.TaskCounters.TID[2])++;
  if ((PI_UDP_Recieve_M->Timing.TaskCounters.TID[2]) > 99) {// Sample time: [1.0s, 0.0s] 
    PI_UDP_Recieve_M->Timing.TaskCounters.TID[2] = 0;
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
void PI_UDP_Recieve_step0(void)        // Sample time: [0.01s, 0.0s]
{
  char_T *sErr;
  int32_T samplesRead;
  boolean_T b_varargout_1;
  real32_T rtb_Gain1;

  {                                    // Sample time: [0.01s, 0.0s]
    rate_monotonic_scheduler();
  }

  // Reset subsysRan breadcrumbs
  srClearBC(PI_UDP_Recieve_DW.EnabledSubsystem_SubsysRanBC);

  // Lookup_n-D: '<S2>/1-D Lookup Table9' incorporates:
  //   Gain: '<Root>/Gain7'

  PI_UDP_Recieve_B.Left_right = look1_iflf_binlcpw(PI_UDP_Recieve_P.Gain7_Gain *
    0.0F, PI_UDP_Recieve_P.uDLookupTable9_bp01Data,
    PI_UDP_Recieve_P.uDLookupTable9_tableData, 4U);

  // Lookup_n-D: '<S2>/1-D Lookup Table1' incorporates:
  //   Gain: '<Root>/Gain8'

  PI_UDP_Recieve_B.Up_Down = look1_iflf_binlcpw(PI_UDP_Recieve_P.Gain8_Gain *
    0.0F, PI_UDP_Recieve_P.uDLookupTable1_bp01Data,
    PI_UDP_Recieve_P.uDLookupTable1_tableData, 4U);

  // S-Function (sdspFromNetwork): '<Root>/UDP Receive'
  sErr = GetErrorBuffer(&PI_UDP_Recieve_DW.UDPReceive_NetworkLib[0U]);
  samplesRead = 6;
  LibOutputs_Network(&PI_UDP_Recieve_DW.UDPReceive_NetworkLib[0U],
                     &PI_UDP_Recieve_B.Axes[0U], &samplesRead);
  if (*sErr != 0) {
    rtmSetErrorStatus(PI_UDP_Recieve_M, sErr);
    rtmSetStopRequested(PI_UDP_Recieve_M, 1);
  }

  PI_UDP_Recieve_B.UDPReceive_o2 = static_cast<uint16_T>(samplesRead);

  // End of S-Function (sdspFromNetwork): '<Root>/UDP Receive'

  // Gain: '<Root>/Gain6'
  rtb_Gain1 = PI_UDP_Recieve_P.Gain6_Gain * PI_UDP_Recieve_B.Axes[2];

  // Lookup_n-D: '<Root>/1-D Lookup Table7'
  PI_UDP_Recieve_B.Up_Down_h = look1_iflf_binlcpw(rtb_Gain1,
    PI_UDP_Recieve_P.uDLookupTable7_bp01Data,
    PI_UDP_Recieve_P.uDLookupTable7_tableData, 4U);

  // Gain: '<Root>/Gain2'
  rtb_Gain1 = PI_UDP_Recieve_P.Gain2_Gain * PI_UDP_Recieve_B.Axes[3];

  // Lookup_n-D: '<Root>/1-D Lookup Table1'
  PI_UDP_Recieve_B.uDLookupTable1 = look1_iflf_binlcpw(rtb_Gain1,
    PI_UDP_Recieve_P.uDLookupTable1_bp01Data_b,
    PI_UDP_Recieve_P.uDLookupTable1_tableData_g, 4U);

  // Gain: '<Root>/Gain3'
  rtb_Gain1 = PI_UDP_Recieve_P.Gain3_Gain * PI_UDP_Recieve_B.Axes[4];

  // Lookup_n-D: '<Root>/1-D Lookup Table2'
  PI_UDP_Recieve_B.Left_right_c = look1_iflf_binlcpw(rtb_Gain1,
    PI_UDP_Recieve_P.uDLookupTable2_bp01Data,
    PI_UDP_Recieve_P.uDLookupTable2_tableData, 2U);

  // Gain: '<Root>/Gain1'
  rtb_Gain1 = PI_UDP_Recieve_P.Gain1_Gain * PI_UDP_Recieve_B.Axes[5];

  // Lookup_n-D: '<Root>/1-D Lookup Table3'
  PI_UDP_Recieve_B.Up_Down_n = look1_iflf_binlcpw(rtb_Gain1,
    PI_UDP_Recieve_P.uDLookupTable3_bp01Data,
    PI_UDP_Recieve_P.uDLookupTable3_tableData, 2U);

  // Constant: '<Root>/Constant2'
  PI_UDP_Recieve_B.Constant2 = PI_UDP_Recieve_P.Constant2_Value;

  // RateTransition: '<Root>/Rate Transition1'
  if (PI_UDP_Recieve_M->Timing.RateInteraction.TID0_1) {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    rtb_Gain1 = rt_roundf_snf(PI_UDP_Recieve_B.Left_right);
    if (rtb_Gain1 < 65536.0F) {
      if (rtb_Gain1 >= 0.0F) {
        PI_UDP_Recieve_DW.RateTransition1_Buffer[0] = static_cast<uint16_T>
          (rtb_Gain1);
      } else {
        PI_UDP_Recieve_DW.RateTransition1_Buffer[0] = 0U;
      }
    } else {
      PI_UDP_Recieve_DW.RateTransition1_Buffer[0] = MAX_uint16_T;
    }

    rtb_Gain1 = rt_roundf_snf(PI_UDP_Recieve_B.Up_Down);
    if (rtb_Gain1 < 65536.0F) {
      if (rtb_Gain1 >= 0.0F) {
        PI_UDP_Recieve_DW.RateTransition1_Buffer[1] = static_cast<uint16_T>
          (rtb_Gain1);
      } else {
        PI_UDP_Recieve_DW.RateTransition1_Buffer[1] = 0U;
      }
    } else {
      PI_UDP_Recieve_DW.RateTransition1_Buffer[1] = MAX_uint16_T;
    }

    rtb_Gain1 = rt_roundf_snf(PI_UDP_Recieve_B.Up_Down_h);
    if (rtb_Gain1 < 65536.0F) {
      if (rtb_Gain1 >= 0.0F) {
        PI_UDP_Recieve_DW.RateTransition1_Buffer[2] = static_cast<uint16_T>
          (rtb_Gain1);
      } else {
        PI_UDP_Recieve_DW.RateTransition1_Buffer[2] = 0U;
      }
    } else {
      PI_UDP_Recieve_DW.RateTransition1_Buffer[2] = MAX_uint16_T;
    }

    rtb_Gain1 = rt_roundf_snf(PI_UDP_Recieve_B.uDLookupTable1);
    if (rtb_Gain1 < 65536.0F) {
      if (rtb_Gain1 >= 0.0F) {
        PI_UDP_Recieve_DW.RateTransition1_Buffer[3] = static_cast<uint16_T>
          (rtb_Gain1);
      } else {
        PI_UDP_Recieve_DW.RateTransition1_Buffer[3] = 0U;
      }
    } else {
      PI_UDP_Recieve_DW.RateTransition1_Buffer[3] = MAX_uint16_T;
    }

    rtb_Gain1 = rt_roundf_snf(PI_UDP_Recieve_B.Left_right_c);
    if (rtb_Gain1 < 65536.0F) {
      if (rtb_Gain1 >= 0.0F) {
        PI_UDP_Recieve_DW.RateTransition1_Buffer[4] = static_cast<uint16_T>
          (rtb_Gain1);
      } else {
        PI_UDP_Recieve_DW.RateTransition1_Buffer[4] = 0U;
      }
    } else {
      PI_UDP_Recieve_DW.RateTransition1_Buffer[4] = MAX_uint16_T;
    }

    rtb_Gain1 = rt_roundf_snf(PI_UDP_Recieve_B.Up_Down_n);
    if (rtb_Gain1 < 65536.0F) {
      if (rtb_Gain1 >= 0.0F) {
        PI_UDP_Recieve_DW.RateTransition1_Buffer[5] = static_cast<uint16_T>
          (rtb_Gain1);
      } else {
        PI_UDP_Recieve_DW.RateTransition1_Buffer[5] = 0U;
      }
    } else {
      PI_UDP_Recieve_DW.RateTransition1_Buffer[5] = MAX_uint16_T;
    }

    rtb_Gain1 = rt_roundf_snf(PI_UDP_Recieve_B.Constant2);
    if (rtb_Gain1 < 65536.0F) {
      if (rtb_Gain1 >= 0.0F) {
        PI_UDP_Recieve_DW.RateTransition1_Buffer[6] = static_cast<uint16_T>
          (rtb_Gain1);
      } else {
        PI_UDP_Recieve_DW.RateTransition1_Buffer[6] = 0U;
      }
    } else {
      PI_UDP_Recieve_DW.RateTransition1_Buffer[6] = MAX_uint16_T;
    }

    // End of DataTypeConversion: '<Root>/Data Type Conversion'
  }

  // End of RateTransition: '<Root>/Rate Transition1'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S3>/SourceBlock'
  b_varargout_1 = Sub_PI_UDP_Recieve_153.getLatestMessage
    (&PI_UDP_Recieve_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S6>/Enable'

  if (b_varargout_1) {
    srUpdateBC(PI_UDP_Recieve_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of MATLABSystem: '<S3>/SourceBlock'
  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // External mode
  rtExtModeUploadCheckTrigger(3);
  rtExtModeUpload(0, (real_T)PI_UDP_Recieve_M->Timing.taskTime0);

  // signal main to stop simulation
  {                                    // Sample time: [0.01s, 0.0s]
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
void PI_UDP_Recieve_step1(void)        // Sample time: [0.1s, 0.0s]
{
  uint32_T PinNameLoc;
  uint8_T status;
  MW_SPI_Mode_type ClockModeValue;
  MW_SPI_FirstBitTransfer_Type MsbFirstTransferLoc;
  uint16_T b_x[7];
  uint8_T y[2];
  uint8_T b_x_0[2];
  uint16_T y_0;
  int32_T i;
  uint16_T b_x_1;

  // MATLABSystem: '<Root>/SPI Master Transfer' incorporates:
  //   RateTransition: '<Root>/Rate Transition1'

  for (i = 0; i < 7; i++) {
    b_x[i] = PI_UDP_Recieve_DW.RateTransition1_Buffer[i];
  }

  for (i = 0; i < 7; i++) {
    b_x_1 = b_x[i];
    memcpy((void *)&y[0], (void *)&b_x_1, (uint32_T)((size_t)2 * sizeof(uint8_T)));
    b_x_0[0] = y[1];
    b_x_0[1] = y[0];
    memcpy((void *)&y_0, (void *)&b_x_0[0], (uint32_T)((size_t)1 * sizeof
            (uint16_T)));
    b_x[i] = y_0;
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
  for (i = 0; i < 7; i++) {
    b_x_1 = PI_UDP_Recieve_B.SPIMasterTransfer[i];
    memcpy((void *)&y[0], (void *)&b_x_1, (uint32_T)((size_t)2 * sizeof(uint8_T)));
    b_x_0[0] = y[1];
    b_x_0[1] = y[0];
    memcpy((void *)&y_0, (void *)&b_x_0[0], (uint32_T)((size_t)1 * sizeof
            (uint16_T)));
    PI_UDP_Recieve_B.SPIMasterTransfer[i] = y_0;
  }

  // End of MATLABSystem: '<Root>/SPI Master Transfer'
  rtExtModeUpload(1, (real_T)((PI_UDP_Recieve_M->Timing.clockTick1) * 0.1));

  // Update absolute time
  // The "clockTick1" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.1, which is the step size
  //  of the task. Size of "clockTick1" ensures timer will not overflow during the
  //  application lifespan selected.

  PI_UDP_Recieve_M->Timing.clockTick1++;
}

// Model step function for TID2
void PI_UDP_Recieve_step2(void)        // Sample time: [1.0s, 0.0s]
{
  // UnitDelay: '<S1>/Output'
  PI_UDP_Recieve_B.Output = PI_UDP_Recieve_DW.Output_DSTATE;

  // Sum: '<S4>/FixPt Sum1' incorporates:
  //   Constant: '<S4>/FixPt Constant'

  PI_UDP_Recieve_DW.Output_DSTATE = static_cast<uint8_T>((static_cast<uint32_T>
    (PI_UDP_Recieve_B.Output) + PI_UDP_Recieve_P.FixPtConstant_Value));

  // Switch: '<S5>/FixPt Switch' incorporates:
  //   Constant: '<S5>/Constant'
  //   UnitDelay: '<S1>/Output'

  if (PI_UDP_Recieve_DW.Output_DSTATE > PI_UDP_Recieve_P.CounterLimited_uplimit)
  {
    PI_UDP_Recieve_DW.Output_DSTATE = PI_UDP_Recieve_P.Constant_Value_m;
  }

  // End of Switch: '<S5>/FixPt Switch'
  rtExtModeUpload(2, (real_T)((PI_UDP_Recieve_M->Timing.clockTick2) * 1.0));

  // Update absolute time
  // The "clockTick2" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 1.0, which is the step size
  //  of the task. Size of "clockTick2" ensures timer will not overflow during the
  //  application lifespan selected.

  PI_UDP_Recieve_M->Timing.clockTick2++;
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

   case 2 :
    PI_UDP_Recieve_step2();
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
  PI_UDP_Recieve_M->Timing.stepSize0 = 0.01;

  // External mode info
  PI_UDP_Recieve_M->Sizes.checksums[0] = (4137458206U);
  PI_UDP_Recieve_M->Sizes.checksums[1] = (1570638343U);
  PI_UDP_Recieve_M->Sizes.checksums[2] = (1925585545U);
  PI_UDP_Recieve_M->Sizes.checksums[3] = (4019662560U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    PI_UDP_Recieve_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)
      &PI_UDP_Recieve_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[5] = &rtAlwaysEnabled;
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
    char_T *sErr;
    codertarget_raspi_internal_SP_T *obj;
    uint32_T SSPinNameLoc;
    uint32_T MOSIPinLoc;
    uint32_T MISOPinLoc;
    uint32_T SCKPinLoc;
    int32_T i;
    static const char_T tmp[16] = { '/', 'p', 'l', 'a', 'n', 'n', 'e', 'r', '/',
      'c', 'm', 'd', '_', 'v', 'e', 'l' };

    // Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive'
    sErr = GetErrorBuffer(&PI_UDP_Recieve_DW.UDPReceive_NetworkLib[0U]);
    CreateUDPInterface(&PI_UDP_Recieve_DW.UDPReceive_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&PI_UDP_Recieve_DW.UDPReceive_NetworkLib[0U], 0,
                        "0.0.0.0", PI_UDP_Recieve_P.UDPReceive_Port, "0.0.0.0",
                        -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&PI_UDP_Recieve_DW.UDPReceive_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&PI_UDP_Recieve_DW.UDPReceive_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(PI_UDP_Recieve_M, sErr);
        rtmSetStopRequested(PI_UDP_Recieve_M, 1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive'

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S3>/SourceBlock'
    PI_UDP_Recieve_DW.obj_c.matlabCodegenIsDeleted = true;
    PI_UDP_Recieve_DW.obj_c.isInitialized = 0;
    PI_UDP_Recieve_DW.obj_c.matlabCodegenIsDeleted = false;
    PI_UDP_Recieve_DW.obj_c.isSetupComplete = false;
    PI_UDP_Recieve_DW.obj_c.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      PI_UDP_Recieve_B.cv[i] = tmp[i];
    }

    PI_UDP_Recieve_B.cv[16] = '\x00';
    Sub_PI_UDP_Recieve_153.createSubscriber(PI_UDP_Recieve_B.cv, 1);
    PI_UDP_Recieve_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SourceBlock'
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

    // InitializeConditions for UnitDelay: '<S1>/Output'
    PI_UDP_Recieve_DW.Output_DSTATE = PI_UDP_Recieve_P.Output_InitialCondition;
  }
}

// Model terminate function
void PI_UDP_Recieve_terminate(void)
{
  char_T *sErr;

  // Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive'
  sErr = GetErrorBuffer(&PI_UDP_Recieve_DW.UDPReceive_NetworkLib[0U]);
  LibTerminate(&PI_UDP_Recieve_DW.UDPReceive_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(PI_UDP_Recieve_M, sErr);
    rtmSetStopRequested(PI_UDP_Recieve_M, 1);
  }

  LibDestroy(&PI_UDP_Recieve_DW.UDPReceive_NetworkLib[0U], 0);
  DestroyUDPInterface(&PI_UDP_Recieve_DW.UDPReceive_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S3>/SourceBlock'
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
