//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PI_UDP_Recieve_data.cpp
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

// Block parameters (default storage)
P_PI_UDP_Recieve_T PI_UDP_Recieve_P = {
  // Mask Parameter: CounterLimited_uplimit
  //  Referenced by: '<S5>/FixPt Switch'

  7U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S6>/Out1'

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
  //  Referenced by: '<S3>/Constant'

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

  // Computed Parameter: UDPReceive_Port
  //  Referenced by: '<Root>/UDP Receive'

  25000,

  // Computed Parameter: Gain7_Gain
  //  Referenced by: '<Root>/Gain7'

  100.0F,

  // Computed Parameter: uDLookupTable9_tableData
  //  Referenced by: '<S2>/1-D Lookup Table9'

  { 1000.0F, 1250.0F, 1500.0F, 1750.0F, 2000.0F },

  // Computed Parameter: uDLookupTable9_bp01Data
  //  Referenced by: '<S2>/1-D Lookup Table9'

  { -100.0F, -50.0F, 0.0F, 50.0F, 100.0F },

  // Computed Parameter: Gain8_Gain
  //  Referenced by: '<Root>/Gain8'

  100.0F,

  // Computed Parameter: uDLookupTable1_tableData
  //  Referenced by: '<S2>/1-D Lookup Table1'

  { 2000.0F, 1750.0F, 1500.0F, 1250.0F, 1000.0F },

  // Computed Parameter: uDLookupTable1_bp01Data
  //  Referenced by: '<S2>/1-D Lookup Table1'

  { -100.0F, -50.0F, 0.0F, 50.0F, 100.0F },

  // Computed Parameter: Gain6_Gain
  //  Referenced by: '<Root>/Gain6'

  100.0F,

  // Computed Parameter: uDLookupTable7_tableData
  //  Referenced by: '<Root>/1-D Lookup Table7'

  { 1000.0F, 1120.0F, 1280.0F, 1750.0F, 2000.0F },

  // Computed Parameter: uDLookupTable7_bp01Data
  //  Referenced by: '<Root>/1-D Lookup Table7'

  { -100.0F, -50.0F, 0.0F, 50.0F, 100.0F },

  // Computed Parameter: Gain2_Gain
  //  Referenced by: '<Root>/Gain2'

  100.0F,

  // Computed Parameter: uDLookupTable1_tableData_g
  //  Referenced by: '<Root>/1-D Lookup Table1'

  { 1000.0F, 1120.0F, 1280.0F, 1750.0F, 2000.0F },

  // Computed Parameter: uDLookupTable1_bp01Data_b
  //  Referenced by: '<Root>/1-D Lookup Table1'

  { -100.0F, -50.0F, 0.0F, 50.0F, 100.0F },

  // Computed Parameter: Gain3_Gain
  //  Referenced by: '<Root>/Gain3'

  100.0F,

  // Computed Parameter: uDLookupTable2_tableData
  //  Referenced by: '<Root>/1-D Lookup Table2'

  { 90.0F, 45.0F, 0.0F },

  // Computed Parameter: uDLookupTable2_bp01Data
  //  Referenced by: '<Root>/1-D Lookup Table2'

  { 0.0F, 50.0F, 100.0F },

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<Root>/Gain1'

  100.0F,

  // Computed Parameter: uDLookupTable3_tableData
  //  Referenced by: '<Root>/1-D Lookup Table3'

  { 180.0F, 90.0F, 0.0F },

  // Computed Parameter: uDLookupTable3_bp01Data
  //  Referenced by: '<Root>/1-D Lookup Table3'

  { 0.0F, 50.0F, 100.0F },

  // Computed Parameter: Constant2_Value
  //  Referenced by: '<Root>/Constant2'

  65535.0F,

  // Computed Parameter: Constant_Value_m
  //  Referenced by: '<S5>/Constant'

  0U,

  // Computed Parameter: Output_InitialCondition
  //  Referenced by: '<S1>/Output'

  0U,

  // Computed Parameter: FixPtConstant_Value
  //  Referenced by: '<S4>/FixPt Constant'

  1U
};

//
// File trailer for generated code.
//
// [EOF]
//
