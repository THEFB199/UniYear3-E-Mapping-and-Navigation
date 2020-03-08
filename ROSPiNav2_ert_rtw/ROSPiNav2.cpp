//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ROSPiNav2.cpp
//
// Code generated for Simulink model 'ROSPiNav2'.
//
// Model version                  : 1.9
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Sun Mar  8 15:54:33 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ROSPiNav2.h"
#include "ROSPiNav2_private.h"
#include "ROSPiNav2_dt.h"

// Block signals (default storage)
B_ROSPiNav2_T ROSPiNav2_B;

// Block states (default storage)
DW_ROSPiNav2_T ROSPiNav2_DW;

// Real-time model
RT_MODEL_ROSPiNav2_T ROSPiNav2_M_ = RT_MODEL_ROSPiNav2_T();
RT_MODEL_ROSPiNav2_T *const ROSPiNav2_M = &ROSPiNav2_M_;

// Forward declaration for local functions
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Subs_T *obj);
static void ROSPiNav2_SystemCore_release(const codertarget_raspi_internal_SP_T
  *obj);
static void ROSPiNav2_SystemCore_delete_ig(const codertarget_raspi_internal_SP_T
  *obj);
static void matlabCodegenHandle_matlabCo_ig(codertarget_raspi_internal_SP_T *obj);
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

real32_T look1_iflf_binlxpw(real32_T u0, const real32_T bp0[], const real32_T
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
  // Extrapolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Linear'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
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
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
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

  (ROSPiNav2_M->Timing.TaskCounters.TID[1])++;
  if ((ROSPiNav2_M->Timing.TaskCounters.TID[1]) > 9) {// Sample time: [1.0s, 0.0s] 
    ROSPiNav2_M->Timing.TaskCounters.TID[1] = 0;
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

static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Subs_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void ROSPiNav2_SystemCore_release(const codertarget_raspi_internal_SP_T
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

static void ROSPiNav2_SystemCore_delete_ig(const codertarget_raspi_internal_SP_T
  *obj)
{
  ROSPiNav2_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCo_ig(codertarget_raspi_internal_SP_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    ROSPiNav2_SystemCore_delete_ig(obj);
  }
}

// Model step function
void ROSPiNav2_step(void)
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
  real32_T rtb_Gain1_idx_0;
  real32_T rtb_Gain1_idx_1;
  uint16_T b_x_1;

  // Reset subsysRan breadcrumbs
  srClearBC(ROSPiNav2_DW.GetRosMessage_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(ROSPiNav2_DW.GetRosMessage1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(ROSPiNav2_DW.EnabledSubsystem_SubsysRanBC_j);

  // Reset subsysRan breadcrumbs
  srClearBC(ROSPiNav2_DW.EnabledSubsystem_SubsysRanBC);

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // MATLABSystem: '<S7>/SourceBlock'
  ROSPiNav2_B.SourceBlock_o1 = Sub_ROSPiNav2_137.getLatestMessage
    (&ROSPiNav2_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S15>/Enable'

  if (ROSPiNav2_B.SourceBlock_o1) {
    // Inport: '<S15>/In1' incorporates:
    //   MATLABSystem: '<S7>/SourceBlock'

    ROSPiNav2_B.In1 = ROSPiNav2_B.b_varargout_2;
    srUpdateBC(ROSPiNav2_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // Outputs for Enabled SubSystem: '<Root>/GetRosMessage1' incorporates:
  //   EnablePort: '<S5>/Enable'

  if (ROSPiNav2_B.SourceBlock_o1) {
    // DeadZone: '<S13>/Dead Zone' incorporates:
    //   MATLAB Function: '<S5>/MATLAB Function'

    for (i = 0; i < 8; i++) {
      if (ROSPiNav2_B.In1.Axes[i] > ROSPiNav2_P.DeadZone_End) {
        ROSPiNav2_B.DeadZone[i] = ROSPiNav2_B.In1.Axes[i] -
          ROSPiNav2_P.DeadZone_End;
      } else if (ROSPiNav2_B.In1.Axes[i] >= ROSPiNav2_P.DeadZone_Start) {
        ROSPiNav2_B.DeadZone[i] = 0.0F;
      } else {
        ROSPiNav2_B.DeadZone[i] = ROSPiNav2_B.In1.Axes[i] -
          ROSPiNav2_P.DeadZone_Start;
      }
    }

    // End of DeadZone: '<S13>/Dead Zone'

    // Lookup_n-D: '<S13>/1-D Lookup Table1' incorporates:
    //   SignalConversion generated from: '<S13>/1-D Lookup Table1'

    ROSPiNav2_B.uDLookupTable1[0] = look1_iflf_binlxpw(ROSPiNav2_B.DeadZone[0],
      ROSPiNav2_P.uDLookupTable1_bp01Data, ROSPiNav2_P.uDLookupTable1_tableData,
      2U);
    ROSPiNav2_B.uDLookupTable1[1] = look1_iflf_binlxpw(ROSPiNav2_B.DeadZone[1],
      ROSPiNav2_P.uDLookupTable1_bp01Data, ROSPiNav2_P.uDLookupTable1_tableData,
      2U);
    ROSPiNav2_B.uDLookupTable1[2] = look1_iflf_binlxpw(ROSPiNav2_B.DeadZone[3],
      ROSPiNav2_P.uDLookupTable1_bp01Data, ROSPiNav2_P.uDLookupTable1_tableData,
      2U);
    ROSPiNav2_B.uDLookupTable1[3] = look1_iflf_binlxpw(ROSPiNav2_B.DeadZone[4],
      ROSPiNav2_P.uDLookupTable1_bp01Data, ROSPiNav2_P.uDLookupTable1_tableData,
      2U);

    // Gain: '<S5>/Gain'
    ROSPiNav2_B.Gain = ROSPiNav2_P.Gain_Gain_h * ROSPiNav2_B.uDLookupTable1[0];
    srUpdateBC(ROSPiNav2_DW.GetRosMessage1_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<Root>/GetRosMessage1'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S6>/SourceBlock'
  ROSPiNav2_B.SourceBlock_o1_g = Sub_ROSPiNav2_136.getLatestMessage
    (&ROSPiNav2_B.b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S14>/Enable'

  if (ROSPiNav2_B.SourceBlock_o1_g) {
    // Inport: '<S14>/In1' incorporates:
    //   MATLABSystem: '<S6>/SourceBlock'

    ROSPiNav2_B.In1_l = ROSPiNav2_B.b_varargout_2_m;
    srUpdateBC(ROSPiNav2_DW.EnabledSubsystem_SubsysRanBC_j);
  }

  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Outputs for Enabled SubSystem: '<Root>/GetRosMessage' incorporates:
  //   EnablePort: '<S4>/Enable'

  if (ROSPiNav2_B.SourceBlock_o1_g) {
    // DataTypeConversion: '<S4>/Data Type Conversion1'
    ROSPiNav2_B.DataTypeConversion1 = static_cast<real32_T>
      (ROSPiNav2_B.In1_l.Linear.X);

    // Gain: '<S4>/Gain' incorporates:
    //   DataTypeConversion: '<S4>/Data Type Conversion2'

    ROSPiNav2_B.Gain_b = ROSPiNav2_P.Gain_Gain * static_cast<real32_T>
      (ROSPiNav2_B.In1_l.Angular.Z);

    // DataTypeConversion: '<S4>/Data Type Conversion3'
    ROSPiNav2_B.DataTypeConversion3 = static_cast<real32_T>
      (ROSPiNav2_B.In1_l.Linear.Y);

    // DataTypeConversion: '<S4>/Data Type Conversion4'
    ROSPiNav2_B.DataTypeConversion4 = static_cast<real32_T>
      (ROSPiNav2_B.In1_l.Linear.Z);

    // DataTypeConversion: '<S4>/Data Type Conversion5'
    ROSPiNav2_B.DataTypeConversion5 = static_cast<real32_T>
      (ROSPiNav2_B.In1_l.Angular.X);

    // DataTypeConversion: '<S4>/Data Type Conversion6'
    ROSPiNav2_B.DataTypeConversion6 = static_cast<real32_T>
      (ROSPiNav2_B.In1_l.Angular.Y);
    srUpdateBC(ROSPiNav2_DW.GetRosMessage_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<Root>/GetRosMessage'

  // ManualSwitch: '<Root>/Manual Switch1' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<Root>/Constant2'

  if (ROSPiNav2_P.ManualSwitch1_CurrentSetting == 1) {
    rtb_Gain1_idx_1 = ROSPiNav2_P.Constant_Value_f;
  } else {
    rtb_Gain1_idx_1 = ROSPiNav2_P.Constant2_Value;
  }

  // End of ManualSwitch: '<Root>/Manual Switch1'

  // Switch: '<S1>/Switch'
  if (rtb_Gain1_idx_1 != 0.0F) {
    // Switch: '<S1>/Switch1' incorporates:
    //   Constant: '<Root>/FullNav '
    //   Sum: '<S1>/Add'

    if (ROSPiNav2_P.FullNav_Value != 0.0F) {
      rtb_Gain1_idx_0 = ROSPiNav2_B.DataTypeConversion1;
      rtb_Gain1_idx_1 = ROSPiNav2_B.Gain_b;
    } else {
      rtb_Gain1_idx_0 = ROSPiNav2_B.DataTypeConversion1 +
        ROSPiNav2_B.uDLookupTable1[1];
      rtb_Gain1_idx_1 = ROSPiNav2_B.Gain_b + ROSPiNav2_B.Gain;
    }

    // End of Switch: '<S1>/Switch1'
  } else {
    rtb_Gain1_idx_0 = ROSPiNav2_B.uDLookupTable1[1];
    rtb_Gain1_idx_1 = ROSPiNav2_B.Gain;
  }

  // End of Switch: '<S1>/Switch'

  // Gain: '<S1>/Gain1'
  rtb_Gain1_idx_0 *= ROSPiNav2_P.Gain1_Gain;

  // Lookup_n-D: '<S3>/1-D Lookup Table9'
  ROSPiNav2_B.Saturation = look1_iflf_binlcpw(rtb_Gain1_idx_0,
    ROSPiNav2_P.uDLookupTable9_bp01Data, ROSPiNav2_P.uDLookupTable9_tableData,
    4U);

  // Saturate: '<S3>/Saturation'
  if (ROSPiNav2_B.Saturation > ROSPiNav2_P.Saturation_UpperSat) {
    // Lookup_n-D: '<S3>/1-D Lookup Table9'
    ROSPiNav2_B.Saturation = ROSPiNav2_P.Saturation_UpperSat;
  } else {
    if (ROSPiNav2_B.Saturation < ROSPiNav2_P.Saturation_LowerSat) {
      // Lookup_n-D: '<S3>/1-D Lookup Table9'
      ROSPiNav2_B.Saturation = ROSPiNav2_P.Saturation_LowerSat;
    }
  }

  // End of Saturate: '<S3>/Saturation'

  // Lookup_n-D: '<S3>/1-D Lookup Table1' incorporates:
  //   Gain: '<S1>/Gain1'

  ROSPiNav2_B.Saturation1 = look1_iflf_binlcpw(ROSPiNav2_P.Gain1_Gain *
    rtb_Gain1_idx_1, ROSPiNav2_P.uDLookupTable1_bp01Data_g,
    ROSPiNav2_P.uDLookupTable1_tableData_b, 4U);

  // Saturate: '<S3>/Saturation1'
  if (ROSPiNav2_B.Saturation1 > ROSPiNav2_P.Saturation1_UpperSat) {
    // Lookup_n-D: '<S3>/1-D Lookup Table1'
    ROSPiNav2_B.Saturation1 = ROSPiNav2_P.Saturation1_UpperSat;
  } else {
    if (ROSPiNav2_B.Saturation1 < ROSPiNav2_P.Saturation1_LowerSat) {
      // Lookup_n-D: '<S3>/1-D Lookup Table1'
      ROSPiNav2_B.Saturation1 = ROSPiNav2_P.Saturation1_LowerSat;
    }
  }

  // End of Saturate: '<S3>/Saturation1'

  // DataTypeConversion: '<S8>/Data Type Conversion' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Constant: '<Root>/Constant3'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<Root>/Constant5'
  //   Constant: '<S8>/EndofData'

  rtb_Gain1_idx_1 = rt_roundf_snf(ROSPiNav2_B.Saturation);
  if (rtb_Gain1_idx_1 < 65536.0F) {
    if (rtb_Gain1_idx_1 >= 0.0F) {
      // MATLABSystem: '<S8>/SPI Master Transfer'
      b_x[0] = static_cast<uint16_T>(rtb_Gain1_idx_1);
    } else {
      // MATLABSystem: '<S8>/SPI Master Transfer'
      b_x[0] = 0U;
    }
  } else {
    // MATLABSystem: '<S8>/SPI Master Transfer'
    b_x[0] = MAX_uint16_T;
  }

  rtb_Gain1_idx_1 = rt_roundf_snf(ROSPiNav2_B.Saturation1);
  if (rtb_Gain1_idx_1 < 65536.0F) {
    if (rtb_Gain1_idx_1 >= 0.0F) {
      // MATLABSystem: '<S8>/SPI Master Transfer'
      b_x[1] = static_cast<uint16_T>(rtb_Gain1_idx_1);
    } else {
      // MATLABSystem: '<S8>/SPI Master Transfer'
      b_x[1] = 0U;
    }
  } else {
    // MATLABSystem: '<S8>/SPI Master Transfer'
    b_x[1] = MAX_uint16_T;
  }

  rtb_Gain1_idx_1 = rt_roundf_snf(ROSPiNav2_P.Constant5_Value);
  if (rtb_Gain1_idx_1 < 65536.0F) {
    if (rtb_Gain1_idx_1 >= 0.0F) {
      // MATLABSystem: '<S8>/SPI Master Transfer'
      b_x[2] = static_cast<uint16_T>(rtb_Gain1_idx_1);
    } else {
      // MATLABSystem: '<S8>/SPI Master Transfer'
      b_x[2] = 0U;
    }
  } else {
    // MATLABSystem: '<S8>/SPI Master Transfer'
    b_x[2] = MAX_uint16_T;
  }

  rtb_Gain1_idx_1 = rt_roundf_snf(ROSPiNav2_P.Constant4_Value);
  if (rtb_Gain1_idx_1 < 65536.0F) {
    if (rtb_Gain1_idx_1 >= 0.0F) {
      // MATLABSystem: '<S8>/SPI Master Transfer'
      b_x[3] = static_cast<uint16_T>(rtb_Gain1_idx_1);
    } else {
      // MATLABSystem: '<S8>/SPI Master Transfer'
      b_x[3] = 0U;
    }
  } else {
    // MATLABSystem: '<S8>/SPI Master Transfer'
    b_x[3] = MAX_uint16_T;
  }

  rtb_Gain1_idx_1 = rt_roundf_snf(ROSPiNav2_P.Constant3_Value);
  if (rtb_Gain1_idx_1 < 65536.0F) {
    if (rtb_Gain1_idx_1 >= 0.0F) {
      // MATLABSystem: '<S8>/SPI Master Transfer'
      b_x[4] = static_cast<uint16_T>(rtb_Gain1_idx_1);
    } else {
      // MATLABSystem: '<S8>/SPI Master Transfer'
      b_x[4] = 0U;
    }
  } else {
    // MATLABSystem: '<S8>/SPI Master Transfer'
    b_x[4] = MAX_uint16_T;
  }

  rtb_Gain1_idx_1 = rt_roundf_snf(ROSPiNav2_P.Constant1_Value);
  if (rtb_Gain1_idx_1 < 65536.0F) {
    if (rtb_Gain1_idx_1 >= 0.0F) {
      // MATLABSystem: '<S8>/SPI Master Transfer'
      b_x[5] = static_cast<uint16_T>(rtb_Gain1_idx_1);
    } else {
      // MATLABSystem: '<S8>/SPI Master Transfer'
      b_x[5] = 0U;
    }
  } else {
    // MATLABSystem: '<S8>/SPI Master Transfer'
    b_x[5] = MAX_uint16_T;
  }

  rtb_Gain1_idx_1 = rt_roundf_snf(ROSPiNav2_P.EndofData_Value);
  if (rtb_Gain1_idx_1 < 65536.0F) {
    if (rtb_Gain1_idx_1 >= 0.0F) {
      // MATLABSystem: '<S8>/SPI Master Transfer'
      b_x[6] = static_cast<uint16_T>(rtb_Gain1_idx_1);
    } else {
      // MATLABSystem: '<S8>/SPI Master Transfer'
      b_x[6] = 0U;
    }
  } else {
    // MATLABSystem: '<S8>/SPI Master Transfer'
    b_x[6] = MAX_uint16_T;
  }

  // End of DataTypeConversion: '<S8>/Data Type Conversion'

  // MATLABSystem: '<S8>/SPI Master Transfer'
  for (i = 0; i < 7; i++) {
    b_x_1 = b_x[i];
    memcpy((void *)&y[0], (void *)&b_x_1, (uint32_T)((size_t)2 * sizeof(uint8_T)));
    b_x_0[0] = y[1];
    b_x_0[1] = y[0];
    memcpy((void *)&y_0, (void *)&b_x_0[0], (uint32_T)((size_t)1 * sizeof
            (uint16_T)));
    b_x[i] = y_0;
  }

  memcpy((void *)&ROSPiNav2_B.wrDataRaw[0], (void *)&b_x[0], (uint32_T)((size_t)
          14 * sizeof(uint8_T)));
  PinNameLoc = SPI0_CE0;
  MW_SPI_SetSlaveSelect(ROSPiNav2_DW.obj.MW_SPI_HANDLE, PinNameLoc, true);
  ClockModeValue = MW_SPI_MODE_0;
  MsbFirstTransferLoc = MW_SPI_MOST_SIGNIFICANT_BIT_FIRST;
  status = MW_SPI_SetFormat(ROSPiNav2_DW.obj.MW_SPI_HANDLE, 8, ClockModeValue,
    MsbFirstTransferLoc);
  if (status == 0) {
    MW_SPI_MasterWriteRead_8bits(ROSPiNav2_DW.obj.MW_SPI_HANDLE,
      ROSPiNav2_B.wrDataRaw, ROSPiNav2_B.rdDataRaw, 14U);
  }

  memcpy((void *)&ROSPiNav2_B.SPIMasterTransfer[0], (void *)
         &ROSPiNav2_B.rdDataRaw[0], (uint32_T)((size_t)7 * sizeof(uint16_T)));
  for (i = 0; i < 7; i++) {
    b_x_1 = ROSPiNav2_B.SPIMasterTransfer[i];
    memcpy((void *)&y[0], (void *)&b_x_1, (uint32_T)((size_t)2 * sizeof(uint8_T)));
    b_x_0[0] = y[1];
    b_x_0[1] = y[0];
    memcpy((void *)&y_0, (void *)&b_x_0[0], (uint32_T)((size_t)1 * sizeof
            (uint16_T)));
    ROSPiNav2_B.SPIMasterTransfer[i] = y_0;
  }

  if (ROSPiNav2_M->Timing.TaskCounters.TID[1] == 0) {
    // UnitDelay: '<S2>/Output'
    ROSPiNav2_B.Output = ROSPiNav2_DW.Output_DSTATE;

    // Sum: '<S9>/FixPt Sum1' incorporates:
    //   Constant: '<S9>/FixPt Constant'

    ROSPiNav2_DW.Output_DSTATE = static_cast<uint8_T>((static_cast<uint32_T>
      (ROSPiNav2_B.Output) + ROSPiNav2_P.FixPtConstant_Value));

    // Switch: '<S10>/FixPt Switch' incorporates:
    //   Constant: '<S10>/Constant'
    //   UnitDelay: '<S2>/Output'

    if (ROSPiNav2_DW.Output_DSTATE > ROSPiNav2_P.CounterLimited_uplimit) {
      ROSPiNav2_DW.Output_DSTATE = ROSPiNav2_P.Constant_Value_a;
    }

    // End of Switch: '<S10>/FixPt Switch'
  }

  // External mode
  rtExtModeUploadCheckTrigger(2);

  {                                    // Sample time: [0.1s, 0.0s]
    rtExtModeUpload(0, (real_T)ROSPiNav2_M->Timing.taskTime0);
  }

  if (ROSPiNav2_M->Timing.TaskCounters.TID[1] == 0) {// Sample time: [1.0s, 0.0s] 
    rtExtModeUpload(1, (real_T)((ROSPiNav2_M->Timing.clockTick1) * 1.0));
  }

  // signal main to stop simulation
  {                                    // Sample time: [0.1s, 0.0s]
    if ((rtmGetTFinal(ROSPiNav2_M)!=-1) &&
        !((rtmGetTFinal(ROSPiNav2_M)-ROSPiNav2_M->Timing.taskTime0) >
          ROSPiNav2_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(ROSPiNav2_M, "Simulation finished");
    }

    if (rtmGetStopRequested(ROSPiNav2_M)) {
      rtmSetErrorStatus(ROSPiNav2_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  ROSPiNav2_M->Timing.taskTime0 =
    (++ROSPiNav2_M->Timing.clockTick0) * ROSPiNav2_M->Timing.stepSize0;
  if (ROSPiNav2_M->Timing.TaskCounters.TID[1] == 0) {
    // Update absolute timer for sample time: [1.0s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 1.0, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    ROSPiNav2_M->Timing.clockTick1++;
  }

  rate_scheduler();
}

// Model initialize function
void ROSPiNav2_initialize(void)
{
  // Registration code
  rtmSetTFinal(ROSPiNav2_M, -1);
  ROSPiNav2_M->Timing.stepSize0 = 0.1;

  // External mode info
  ROSPiNav2_M->Sizes.checksums[0] = (54968763U);
  ROSPiNav2_M->Sizes.checksums[1] = (4225996166U);
  ROSPiNav2_M->Sizes.checksums[2] = (3651411929U);
  ROSPiNav2_M->Sizes.checksums[3] = (26614725U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[17];
    ROSPiNav2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)&ROSPiNav2_DW.GetRosMessage_SubsysRanBC;
    systemRan[7] = (sysRanDType *)&ROSPiNav2_DW.GetRosMessage1_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&ROSPiNav2_DW.GetRosMessage1_SubsysRanBC;
    systemRan[9] = (sysRanDType *)&ROSPiNav2_DW.GetRosMessage1_SubsysRanBC;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = (sysRanDType *)&ROSPiNav2_DW.EnabledSubsystem_SubsysRanBC_j;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = (sysRanDType *)&ROSPiNav2_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ROSPiNav2_M->extModeInfo,
      &ROSPiNav2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ROSPiNav2_M->extModeInfo, ROSPiNav2_M->Sizes.checksums);
    rteiSetTPtr(ROSPiNav2_M->extModeInfo, rtmGetTPtr(ROSPiNav2_M));
  }

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    ROSPiNav2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 22;
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
    char_T tmp[5];
    int32_T i;
    static const char_T tmp_0[16] = { '/', 'p', 'l', 'a', 'n', 'n', 'e', 'r',
      '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    // Start for Atomic SubSystem: '<Root>/Subscribe1'
    // Start for MATLABSystem: '<S7>/SourceBlock'
    ROSPiNav2_DW.obj_l.matlabCodegenIsDeleted = false;
    ROSPiNav2_DW.obj_l.isInitialized = 1;
    tmp[0] = '/';
    tmp[1] = 'j';
    tmp[2] = 'o';
    tmp[3] = 'y';
    tmp[4] = '\x00';
    Sub_ROSPiNav2_137.createSubscriber(tmp, 1);
    ROSPiNav2_DW.obj_l.isSetupComplete = true;

    // End of Start for SubSystem: '<Root>/Subscribe1'

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S6>/SourceBlock'
    ROSPiNav2_DW.obj_e.matlabCodegenIsDeleted = false;
    ROSPiNav2_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      ROSPiNav2_B.cv[i] = tmp_0[i];
    }

    ROSPiNav2_B.cv[16] = '\x00';
    Sub_ROSPiNav2_136.createSubscriber(ROSPiNav2_B.cv, 1);
    ROSPiNav2_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // Start for MATLABSystem: '<S8>/SPI Master Transfer'
    ROSPiNav2_DW.obj.matlabCodegenIsDeleted = true;
    ROSPiNav2_DW.obj.isInitialized = 0;
    ROSPiNav2_DW.obj.matlabCodegenIsDeleted = false;
    obj = &ROSPiNav2_DW.obj;
    ROSPiNav2_DW.obj.isSetupComplete = false;
    ROSPiNav2_DW.obj.isInitialized = 1;
    SSPinNameLoc = SPI0_CE0;
    MOSIPinLoc = MW_UNDEFINED_VALUE;
    MISOPinLoc = MW_UNDEFINED_VALUE;
    SCKPinLoc = MW_UNDEFINED_VALUE;
    obj->MW_SPI_HANDLE = MW_SPI_Open(0U, MOSIPinLoc, MISOPinLoc, SCKPinLoc,
      SSPinNameLoc, true, 0);
    MW_SPI_SetBusSpeed(ROSPiNav2_DW.obj.MW_SPI_HANDLE, 500000U);
    ROSPiNav2_DW.obj.isSetupComplete = true;

    // InitializeConditions for UnitDelay: '<S2>/Output'
    ROSPiNav2_DW.Output_DSTATE = ROSPiNav2_P.Output_InitialCondition;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S15>/Out1'
    ROSPiNav2_B.In1 = ROSPiNav2_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Enabled SubSystem: '<Root>/GetRosMessage1'
    // SystemInitialize for Outport: '<S5>/LeftRightL'
    ROSPiNav2_B.Gain = ROSPiNav2_P.LeftRightL_Y0;

    // SystemInitialize for Outport: '<S5>/UpDownL'
    ROSPiNav2_B.uDLookupTable1[1] = ROSPiNav2_P.UpDownL_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/GetRosMessage1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S14>/Out1'
    ROSPiNav2_B.In1_l = ROSPiNav2_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Enabled SubSystem: '<Root>/GetRosMessage'
    // SystemInitialize for Outport: '<S4>/Lx'
    ROSPiNav2_B.DataTypeConversion1 = ROSPiNav2_P.Lx_Y0;

    // SystemInitialize for Outport: '<S4>/Ly '
    ROSPiNav2_B.DataTypeConversion3 = ROSPiNav2_P.Ly_Y0;

    // SystemInitialize for Outport: '<S4>/Lz'
    ROSPiNav2_B.DataTypeConversion4 = ROSPiNav2_P.Lz_Y0;

    // SystemInitialize for Outport: '<S4>/Ax'
    ROSPiNav2_B.DataTypeConversion5 = ROSPiNav2_P.Ax_Y0;

    // SystemInitialize for Outport: '<S4>/Ay '
    ROSPiNav2_B.DataTypeConversion6 = ROSPiNav2_P.Ay_Y0;

    // SystemInitialize for Outport: '<S4>/Az '
    ROSPiNav2_B.Gain_b = ROSPiNav2_P.Az_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/GetRosMessage'
  }
}

// Model terminate function
void ROSPiNav2_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  matlabCodegenHandle_matlabCodeg(&ROSPiNav2_DW.obj_l);

  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  matlabCodegenHandle_matlabCodeg(&ROSPiNav2_DW.obj_e);

  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for MATLABSystem: '<S8>/SPI Master Transfer'
  matlabCodegenHandle_matlabCo_ig(&ROSPiNav2_DW.obj);
}

//
// File trailer for generated code.
//
// [EOF]
//
