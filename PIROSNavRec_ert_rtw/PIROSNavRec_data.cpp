//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PIROSNavRec_data.cpp
//
// Code generated for Simulink model 'PIROSNavRec'.
//
// Model version                  : 1.11
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Wed Feb  5 17:15:48 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "PIROSNavRec.h"
#include "PIROSNavRec_private.h"

// Block parameters (default storage)
P_PIROSNavRec_T PIROSNavRec_P = {
  // Mask Parameter: CounterLimited_uplimit
  //  Referenced by: '<S6>/FixPt Switch'

  7U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S7>/Out1'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Linear

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    }                                  // Angular
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S4>/Constant'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Linear

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    }                                  // Angular
  },

  // Computed Parameter: Gain8_Gain
  //  Referenced by: '<Root>/Gain8'

  100.0F,

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<Root>/Constant'

  0.0F,

  // Computed Parameter: Lx_Y0
  //  Referenced by: '<S3>/Lx'

  0.0F,

  // Computed Parameter: Ly_Y0
  //  Referenced by: '<S3>/Ly '

  0.0F,

  // Computed Parameter: Lz_Y0
  //  Referenced by: '<S3>/Lz'

  0.0F,

  // Computed Parameter: Ax_Y0
  //  Referenced by: '<S3>/Ax'

  0.0F,

  // Computed Parameter: Ay_Y0
  //  Referenced by: '<S3>/Ay '

  0.0F,

  // Computed Parameter: Az_Y0
  //  Referenced by: '<S3>/Az '

  0.0F,

  // Computed Parameter: Gain7_Gain
  //  Referenced by: '<Root>/Gain7'

  100.0F,

  // Computed Parameter: uDLookupTable9_tableData
  //  Referenced by: '<S2>/1-D Lookup Table9'

  { 1000.0F, 1250.0F, 1500.0F, 1750.0F, 2000.0F },

  // Computed Parameter: uDLookupTable9_bp01Data
  //  Referenced by: '<S2>/1-D Lookup Table9'

  { -100.0F, -50.0F, 0.0F, 50.0F, 100.0F },

  // Computed Parameter: uDLookupTable1_tableData
  //  Referenced by: '<S2>/1-D Lookup Table1'

  { 2000.0F, 1750.0F, 1500.0F, 1250.0F, 1000.0F },

  // Computed Parameter: uDLookupTable1_bp01Data
  //  Referenced by: '<S2>/1-D Lookup Table1'

  { -100.0F, -50.0F, 0.0F, 50.0F, 100.0F },

  // Computed Parameter: Constant5_Value
  //  Referenced by: '<Root>/Constant5'

  0.0F,

  // Computed Parameter: Constant4_Value
  //  Referenced by: '<Root>/Constant4'

  0.0F,

  // Computed Parameter: Constant3_Value
  //  Referenced by: '<Root>/Constant3'

  0.0F,

  // Computed Parameter: Constant1_Value
  //  Referenced by: '<Root>/Constant1'

  0.0F,

  // Computed Parameter: Constant2_Value
  //  Referenced by: '<Root>/Constant2'

  65535.0F,

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S6>/Constant'

  0U,

  // Computed Parameter: ManualSwitch_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch'

  0U,

  // Computed Parameter: Output_InitialCondition
  //  Referenced by: '<S1>/Output'

  0U,

  // Computed Parameter: FixPtConstant_Value
  //  Referenced by: '<S5>/FixPt Constant'

  1U
};

//
// File trailer for generated code.
//
// [EOF]
//
