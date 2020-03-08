//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: untitled1.cpp
//
// Code generated for Simulink model 'untitled1'.
//
// Model version                  : 1.0
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Tue Feb 25 12:27:41 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "untitled1.h"
#include "untitled1_private.h"
#include "untitled1_dt.h"

// Block signals (default storage)
B_untitled1_T untitled1_B;

// Block states (default storage)
DW_untitled1_T untitled1_DW;

// Real-time model
RT_MODEL_untitled1_T untitled1_M_ = RT_MODEL_untitled1_T();
RT_MODEL_untitled1_T *const untitled1_M = &untitled1_M_;

// Forward declaration for local functions
static void untitled1_SystemCore_release(const codertarget_linux_blocks_SDLV_T
  *obj);
static void untitled1_SystemCore_delete(const codertarget_linux_blocks_SDLV_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_linux_blocks_SDLV_T *obj);
static void untitled1_SystemCore_release(const codertarget_linux_blocks_SDLV_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SDL_videoDisplayTerminate(0, 0);
  }
}

static void untitled1_SystemCore_delete(const codertarget_linux_blocks_SDLV_T
  *obj)
{
  untitled1_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(codertarget_linux_blocks_SDLV_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    untitled1_SystemCore_delete(obj);
  }
}

// Model step function
void untitled1_step(void)
{
  // S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture'
  MW_videoCaptureOutput(untitled1_ConstP.V4L2VideoCapture_p1,
                        untitled1_B.V4L2VideoCapture_o1,
                        untitled1_B.V4L2VideoCapture_o2,
                        untitled1_B.V4L2VideoCapture_o3);

  // MATLABSystem: '<S2>/MATLAB System'
  memcpy(&untitled1_B.pln1[0], &untitled1_B.V4L2VideoCapture_o1[0], 480000U *
         sizeof(uint8_T));
  memcpy(&untitled1_B.pln2[0], &untitled1_B.V4L2VideoCapture_o2[0], 240000U *
         sizeof(uint8_T));
  memcpy(&untitled1_B.pln3[0], &untitled1_B.V4L2VideoCapture_o3[0], 240000U *
         sizeof(uint8_T));
  MW_SDL_videoDisplayOutput(untitled1_B.pln1, untitled1_B.pln2, untitled1_B.pln3);

  // UnitDelay: '<S1>/Output'
  untitled1_B.Output = untitled1_DW.Output_DSTATE;

  // Sum: '<S3>/FixPt Sum1' incorporates:
  //   Constant: '<S3>/FixPt Constant'

  untitled1_DW.Output_DSTATE = static_cast<uint8_T>((static_cast<uint32_T>
    (untitled1_B.Output) + untitled1_P.FixPtConstant_Value));

  // Switch: '<S4>/FixPt Switch' incorporates:
  //   Constant: '<S4>/Constant'
  //   UnitDelay: '<S1>/Output'

  if (untitled1_DW.Output_DSTATE > untitled1_P.CounterLimited_uplimit) {
    untitled1_DW.Output_DSTATE = untitled1_P.Constant_Value;
  }

  // End of Switch: '<S4>/FixPt Switch'

  // External mode
  rtExtModeUploadCheckTrigger(1);

  {                                    // Sample time: [0.1s, 0.0s]
    rtExtModeUpload(0, (real_T)untitled1_M->Timing.taskTime0);
  }

  // signal main to stop simulation
  {                                    // Sample time: [0.1s, 0.0s]
    if ((rtmGetTFinal(untitled1_M)!=-1) &&
        !((rtmGetTFinal(untitled1_M)-untitled1_M->Timing.taskTime0) >
          untitled1_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled1_M, "Simulation finished");
    }

    if (rtmGetStopRequested(untitled1_M)) {
      rtmSetErrorStatus(untitled1_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  untitled1_M->Timing.taskTime0 =
    (++untitled1_M->Timing.clockTick0) * untitled1_M->Timing.stepSize0;
}

// Model initialize function
void untitled1_initialize(void)
{
  // Registration code
  rtmSetTFinal(untitled1_M, -1);
  untitled1_M->Timing.stepSize0 = 0.1;

  // External mode info
  untitled1_M->Sizes.checksums[0] = (1221922023U);
  untitled1_M->Sizes.checksums[1] = (1420174825U);
  untitled1_M->Sizes.checksums[2] = (1794441290U);
  untitled1_M->Sizes.checksums[3] = (3692907762U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    untitled1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled1_M->extModeInfo,
      &untitled1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled1_M->extModeInfo, untitled1_M->Sizes.checksums);
    rteiSetTPtr(untitled1_M->extModeInfo, rtmGetTPtr(untitled1_M));
  }

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    untitled1_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;

    // Parameters transition table
    dtInfo.PTransTable = &rtPTransTable;
  }

  // Start for S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' 
  MW_videoCaptureInit(untitled1_ConstP.V4L2VideoCapture_p1, 0, 0, 0, 0, 800U,
                      600U, 1U, 2U, 1U, 0.1);

  // Start for MATLABSystem: '<S2>/MATLAB System'
  untitled1_DW.obj.matlabCodegenIsDeleted = false;
  untitled1_DW.obj.isInitialized = 1;
  untitled1_DW.obj.PixelFormatEnum = 2;
  MW_SDL_videoDisplayInit(untitled1_DW.obj.PixelFormatEnum, 1, 1, 800.0, 600.0);
  untitled1_DW.obj.isSetupComplete = true;

  // End of Start for SubSystem: '<Root>/SDL Video Display'

  // InitializeConditions for UnitDelay: '<S1>/Output'
  untitled1_DW.Output_DSTATE = untitled1_P.Output_InitialCondition;
}

// Model terminate function
void untitled1_terminate(void)
{
  // Terminate for S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' 
  MW_videoCaptureTerminate(untitled1_ConstP.V4L2VideoCapture_p1);

  // Terminate for MATLABSystem: '<S2>/MATLAB System'
  matlabCodegenHandle_matlabCodeg(&untitled1_DW.obj);

  // End of Terminate for SubSystem: '<Root>/SDL Video Display'
}

//
// File trailer for generated code.
//
// [EOF]
//
