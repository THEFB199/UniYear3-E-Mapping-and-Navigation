//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: untitled.cpp
//
// Code generated for Simulink model 'untitled'.
//
// Model version                  : 1.0
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Wed Feb  5 14:42:24 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "untitled.h"
#include "untitled_private.h"
#include "untitled_dt.h"

// Block signals (default storage)
B_untitled_T untitled_B;

// Block states (default storage)
DW_untitled_T untitled_DW;

// Previous zero-crossings (trigger) states
PrevZCX_untitled_T untitled_PrevZCX;

// Real-time model
RT_MODEL_untitled_T untitled_M_ = RT_MODEL_untitled_T();
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

// Forward declaration for local functions
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Subs_T *obj);
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Subs_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

// Model step function
void untitled_step(void)
{
  SL_Bus_untitled_geometry_msgs_Twist b_varargout_2;
  boolean_T b_varargout_1;

  // Reset subsysRan breadcrumbs
  srClearBC(untitled_DW.GetRosMessage_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(untitled_DW.EnabledSubsystem_SubsysRanBC);

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S2>/SourceBlock' incorporates:
  //   Inport: '<S3>/In1'

  b_varargout_1 = Sub_untitled_21.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S2>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S3>/Enable'

  if (b_varargout_1) {
    untitled_B.In1 = b_varargout_2;
    srUpdateBC(untitled_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S2>/Enabled Subsystem'

  // Outputs for Triggered SubSystem: '<Root>/GetRosMessage' incorporates:
  //   TriggerPort: '<S1>/Trigger'

  if (b_varargout_1 && (untitled_PrevZCX.GetRosMessage_Trig_ZCE != POS_ZCSIG)) {
    // DataTypeConversion: '<S1>/Data Type Conversion1'
    untitled_B.DataTypeConversion1 = static_cast<real32_T>
      (untitled_B.In1.Linear.X);

    // DataTypeConversion: '<S1>/Data Type Conversion2'
    untitled_B.DataTypeConversion2 = static_cast<real32_T>
      (untitled_B.In1.Angular.Z);

    // DataTypeConversion: '<S1>/Data Type Conversion3'
    untitled_B.DataTypeConversion3 = static_cast<real32_T>
      (untitled_B.In1.Linear.Y);

    // DataTypeConversion: '<S1>/Data Type Conversion4'
    untitled_B.DataTypeConversion4 = static_cast<real32_T>
      (untitled_B.In1.Linear.Z);

    // DataTypeConversion: '<S1>/Data Type Conversion5'
    untitled_B.DataTypeConversion5 = static_cast<real32_T>
      (untitled_B.In1.Angular.X);

    // DataTypeConversion: '<S1>/Data Type Conversion6'
    untitled_B.DataTypeConversion6 = static_cast<real32_T>
      (untitled_B.In1.Angular.Y);
    untitled_DW.GetRosMessage_SubsysRanBC = 4;
  }

  untitled_PrevZCX.GetRosMessage_Trig_ZCE = b_varargout_1;

  // End of MATLABSystem: '<S2>/SourceBlock'
  // End of Outputs for SubSystem: '<Root>/GetRosMessage'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // External mode
  rtExtModeUploadCheckTrigger(1);

  {                                    // Sample time: [0.2s, 0.0s]
    rtExtModeUpload(0, (real_T)untitled_M->Timing.taskTime0);
  }

  // signal main to stop simulation
  {                                    // Sample time: [0.2s, 0.0s]
    if ((rtmGetTFinal(untitled_M)!=-1) &&
        !((rtmGetTFinal(untitled_M)-untitled_M->Timing.taskTime0) >
          untitled_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }

    if (rtmGetStopRequested(untitled_M)) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  untitled_M->Timing.taskTime0 =
    (++untitled_M->Timing.clockTick0) * untitled_M->Timing.stepSize0;
}

// Model initialize function
void untitled_initialize(void)
{
  // Registration code
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.2;

  // External mode info
  untitled_M->Sizes.checksums[0] = (3544824096U);
  untitled_M->Sizes.checksums[1] = (1304968158U);
  untitled_M->Sizes.checksums[2] = (1748047383U);
  untitled_M->Sizes.checksums[3] = (1246132418U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&untitled_DW.GetRosMessage_SubsysRanBC;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)&untitled_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    untitled_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;

    // Parameters transition table
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    char_T tmp[17];
    int32_T i;
    static const char_T tmp_0[16] = { '/', 'p', 'l', 'a', 'n', 'n', 'e', 'r',
      '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S2>/SourceBlock'
    untitled_DW.obj.matlabCodegenIsDeleted = false;
    untitled_DW.obj.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      tmp[i] = tmp_0[i];
    }

    tmp[16] = '\x00';
    Sub_untitled_21.createSubscriber(tmp, 1);
    untitled_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Subscribe'
    untitled_PrevZCX.GetRosMessage_Trig_ZCE = POS_ZCSIG;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S2>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S3>/Out1'
    untitled_B.In1 = untitled_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S2>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Triggered SubSystem: '<Root>/GetRosMessage'
    // SystemInitialize for Outport: '<S1>/Lx'
    untitled_B.DataTypeConversion1 = untitled_P.Lx_Y0;

    // SystemInitialize for Outport: '<S1>/Ly '
    untitled_B.DataTypeConversion3 = untitled_P.Ly_Y0;

    // SystemInitialize for Outport: '<S1>/Lz'
    untitled_B.DataTypeConversion4 = untitled_P.Lz_Y0;

    // SystemInitialize for Outport: '<S1>/Ax'
    untitled_B.DataTypeConversion5 = untitled_P.Ax_Y0;

    // SystemInitialize for Outport: '<S1>/Ay '
    untitled_B.DataTypeConversion6 = untitled_P.Ay_Y0;

    // SystemInitialize for Outport: '<S1>/Az '
    untitled_B.DataTypeConversion2 = untitled_P.Az_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/GetRosMessage'
  }
}

// Model terminate function
void untitled_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S2>/SourceBlock'
  matlabCodegenHandle_matlabCodeg(&untitled_DW.obj);

  // End of Terminate for SubSystem: '<Root>/Subscribe'
}

//
// File trailer for generated code.
//
// [EOF]
//
