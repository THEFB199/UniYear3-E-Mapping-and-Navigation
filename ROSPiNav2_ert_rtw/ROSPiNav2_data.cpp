//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ROSPiNav2_data.cpp
//
// Code generated for Simulink model 'ROSPiNav2'.
//
// Model version                  : 1.4
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Tue Feb 25 11:49:18 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ROSPiNav2.h"
#include "ROSPiNav2_private.h"

// Block parameters (default storage)
P_ROSPiNav2_T ROSPiNav2_P = {
  // Mask Parameter: CounterLimited_uplimit
  //  Referenced by: '<S10>/FixPt Switch'

  7U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S15>/Out1'

  {
    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // Axes

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    },                                 // Axes_SL_Info

    {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0 }
    ,                                  // Buttons

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    },                                 // Buttons_SL_Info

    {
      0U,                              // Seq

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      },                               // FrameId_SL_Info

      {
        0.0,                           // Sec
        0.0                            // Nsec
      }                                // Stamp
    }                                  // Header
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S7>/Constant'

  {
    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // Axes

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    },                                 // Axes_SL_Info

    {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0 }
    ,                                  // Buttons

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    },                                 // Buttons_SL_Info

    {
      0U,                              // Seq

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      },                               // FrameId_SL_Info

      {
        0.0,                           // Sec
        0.0                            // Nsec
      }                                // Stamp
    }                                  // Header
  },

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S14>/Out1'

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

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S6>/Constant'

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

  // Computed Parameter: Constant2_Value
  //  Referenced by: '<Root>/Constant2'

  0.0F,

  // Computed Parameter: Constant_Value_f
  //  Referenced by: '<Root>/Constant'

  1.0F,

  // Computed Parameter: Lx_Y0
  //  Referenced by: '<S4>/Lx'

  0.0F,

  // Computed Parameter: Ly_Y0
  //  Referenced by: '<S4>/Ly '

  0.0F,

  // Computed Parameter: Lz_Y0
  //  Referenced by: '<S4>/Lz'

  0.0F,

  // Computed Parameter: Ax_Y0
  //  Referenced by: '<S4>/Ax'

  0.0F,

  // Computed Parameter: Ay_Y0
  //  Referenced by: '<S4>/Ay '

  0.0F,

  // Computed Parameter: Az_Y0
  //  Referenced by: '<S4>/Az '

  0.0F,

  // Computed Parameter: LeftRightL_Y0
  //  Referenced by: '<S5>/LeftRightL'

  0.0F,

  // Computed Parameter: UpDownL_Y0
  //  Referenced by: '<S5>/UpDownL'

  0.0F,

  // Computed Parameter: LeftTrigger_Y0
  //  Referenced by: '<S5>/LeftTrigger'

  0.0F,

  // Computed Parameter: LeftRightR_Y0
  //  Referenced by: '<S5>/LeftRightR'

  0.0F,

  // Computed Parameter: UpDownR_Y0
  //  Referenced by: '<S5>/UpDownR'

  0.0F,

  // Computed Parameter: RightTrigger_Y0
  //  Referenced by: '<S5>/RightTrigger'

  0.0F,

  // Computed Parameter: LeftRightDpad_Y0
  //  Referenced by: '<S5>/LeftRightDpad'

  0.0F,

  // Computed Parameter: UpDownDpad_Y0
  //  Referenced by: '<S5>/UpDownDpad'

  0.0F,

  // Computed Parameter: Buttons_Y0
  //  Referenced by: '<S5>/Buttons '

  0.0F,

  // Computed Parameter: DeadZone_Start
  //  Referenced by: '<S13>/Dead Zone'

  -0.1F,

  // Computed Parameter: DeadZone_End
  //  Referenced by: '<S13>/Dead Zone'

  0.1F,

  // Computed Parameter: uDLookupTable1_tableData
  //  Referenced by: '<S13>/1-D Lookup Table1'

  { -1.0F, 0.0F, 1.0F },

  // Computed Parameter: uDLookupTable1_bp01Data
  //  Referenced by: '<S13>/1-D Lookup Table1'

  { -0.9F, 0.0F, 0.9F },

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<S1>/Gain1'

  100.0F,

  // Computed Parameter: uDLookupTable9_tableData
  //  Referenced by: '<S3>/1-D Lookup Table9'

  { 1000.0F, 1250.0F, 1500.0F, 1750.0F, 2000.0F },

  // Computed Parameter: uDLookupTable9_bp01Data
  //  Referenced by: '<S3>/1-D Lookup Table9'

  { -100.0F, -50.0F, 0.0F, 50.0F, 100.0F },

  // Computed Parameter: uDLookupTable1_tableData_b
  //  Referenced by: '<S3>/1-D Lookup Table1'

  { 1000.0F, 1250.0F, 1500.0F, 1750.0F, 2000.0F },

  // Computed Parameter: uDLookupTable1_bp01Data_g
  //  Referenced by: '<S3>/1-D Lookup Table1'

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

  // Computed Parameter: EndofData_Value
  //  Referenced by: '<S8>/EndofData'

  65535.0F,

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S10>/Constant'

  0U,

  // Computed Parameter: ManualSwitch1_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch1'

  1U,

  // Computed Parameter: Output_InitialCondition
  //  Referenced by: '<S2>/Output'

  0U,

  // Computed Parameter: FixPtConstant_Value
  //  Referenced by: '<S9>/FixPt Constant'

  1U
};

//
// File trailer for generated code.
//
// [EOF]
//
