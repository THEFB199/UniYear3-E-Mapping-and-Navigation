//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
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
#include <stdio.h>
#include <stdlib.h>
#include "untitled1.h"
#include "untitled1_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "linuxinitialize.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

// Function prototype declaration
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
pthread_t backgroundThread;
void *threadJoinStatus;
int terminatingmodel = 0;
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(untitled1_M) == (NULL)) && !rtmGetStopRequested
    (untitled1_M);
  while (runModel) {
    sem_wait(&baserateTaskSem);

    // External mode
    {
      boolean_T rtmStopReq = false;
      rtExtModePauseIfNeeded(untitled1_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(untitled1_M, true);
      }

      if (rtmGetStopRequested(untitled1_M) == true) {
        rtmSetErrorStatus(untitled1_M, "Simulation finished");
        break;
      }
    }

    untitled1_step();

    // Get model outputs here
    rtExtModeCheckEndTrigger();
    stopRequested = !((rtmGetErrorStatus(untitled1_M) == (NULL)) &&
                      !rtmGetStopRequested(untitled1_M));
    runModel = !stopRequested;
  }

  runModel = 0;
  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(untitled1_M, "stopping the model");
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;

    // Wait for background task to complete
    CHECK_STATUS(pthread_join(backgroundThread, &threadJoinStatus), 0,
                 "pthread_join");
  }

  // Disable rt_OneStep() here

  // Terminate model
  untitled1_terminate();
  rtExtModeShutdown(1);
  sem_post(&stopSem);
  return NULL;
}

void *backgroundTask(void *arg)
{
  while (runModel) {
    // External mode
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(untitled1_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(untitled1_M, true);
      }
    }
  }

  return NULL;
}

int main(int argc, char **argv)
{
  UNUSED(argc);
  UNUSED(argv);
  void slros_node_init(int argc, char** argv);
  slros_node_init(argc, argv);
  rtmSetErrorStatus(untitled1_M, 0);
  rtExtModeParseArgs(argc, (const char_T **)argv, NULL);

  // Initialize model
  untitled1_initialize();

  // External mode
  rtSetTFinalForExtMode(&rtmGetTFinal(untitled1_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(untitled1_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(untitled1_M, true);
    }
  }

  rtERTExtModeStartMsg();

  // Call RTOS Initialization function
  myRTOSInit(0.1, 0);

  // Wait for stop semaphore
  sem_wait(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(sem_destroy(&timerTaskSem[i]), 0, "sem_destroy");
    }
  }

#endif

  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
