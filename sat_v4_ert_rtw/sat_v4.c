/*
 * File: sat_v4.c
 *
 * Code generated for Simulink model 'sat_v4'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Jan  9 11:53:50 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sat_v4.h"
#include "sat_v4_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define sat_v4_IN_BW                   ((uint8_T)1U)
#define sat_v4_IN_FW                   ((uint8_T)2U)
#define sat_v4_IN_Gripper              ((uint8_T)3U)
#define sat_v4_IN_Start                ((uint8_T)4U)
#define sat_v4_IN_Stop                 ((uint8_T)5U)

/* Block signals (default storage) */
B_sat_v4_T sat_v4_B;

/* Continuous states */
X_sat_v4_T sat_v4_X;

/* Block states (default storage) */
DW_sat_v4_T sat_v4_DW;

/* Real-time model */
RT_MODEL_sat_v4_T sat_v4_M_;
RT_MODEL_sat_v4_T *const sat_v4_M = &sat_v4_M_;

/* Forward declaration for local functions */
static void sat_v4_SystemCore_release_k(codertarget_arduinobase_inter_T *obj);
static void SystemCore_delet_kxmhghao1ntb0h(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHan_kxmhghao1ntb0h(codertarget_arduinobase_inter_T *obj);
static void sat_v4_SystemCore_release(codertarget_arduinobase_inter_T *obj);
static void SystemCore_delete_kxmhghao1ntb0(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHand_kxmhghao1ntb0(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHandle__kxmhghao1n(codertarget_arduinobase_blo_k_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj);
static void arduino_ServoWrite_set_pinNumbe(codertarget_arduinobase_int_k_T *obj,
  i_codertarget_arduinobase_int_T *iobj_0);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void sat_v4_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(sat_v4_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(sat_v4_M, 3));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rates: 2, 3 */
  if (sat_v4_M->Timing.TaskCounters.TID[1] == 0) {
    sat_v4_M->Timing.RateInteraction.TID1_2 = (sat_v4_M->
      Timing.TaskCounters.TID[2] == 0);
    sat_v4_M->Timing.RateInteraction.TID1_3 = (sat_v4_M->
      Timing.TaskCounters.TID[3] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (sat_v4_M->Timing.TaskCounters.TID[2])++;
  if ((sat_v4_M->Timing.TaskCounters.TID[2]) > 1) {/* Sample time: [0.001s, 0.0s] */
    sat_v4_M->Timing.TaskCounters.TID[2] = 0;
  }

  (sat_v4_M->Timing.TaskCounters.TID[3])++;
  if ((sat_v4_M->Timing.TaskCounters.TID[3]) > 9) {/* Sample time: [0.005s, 0.0s] */
    sat_v4_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  sat_v4_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  sat_v4_step0();
  sat_v4_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  sat_v4_step0();
  sat_v4_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void sat_v4_SystemCore_release_k(codertarget_arduinobase_inter_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(54UL);
    MW_AnalogIn_Close(obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE);
  }
}

static void SystemCore_delet_kxmhghao1ntb0h(codertarget_arduinobase_inter_T *obj)
{
  sat_v4_SystemCore_release_k(obj);
}

static void matlabCodegenHan_kxmhghao1ntb0h(codertarget_arduinobase_inter_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_delet_kxmhghao1ntb0h(obj);
  }
}

static void sat_v4_SystemCore_release(codertarget_arduinobase_inter_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(55UL);
    MW_AnalogIn_Close(obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE);
  }
}

static void SystemCore_delete_kxmhghao1ntb0(codertarget_arduinobase_inter_T *obj)
{
  sat_v4_SystemCore_release(obj);
}

static void matlabCodegenHand_kxmhghao1ntb0(codertarget_arduinobase_inter_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_delete_kxmhghao1ntb0(obj);
  }
}

static void matlabCodegenHandle__kxmhghao1n(codertarget_arduinobase_blo_k_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void arduino_ServoWrite_set_pinNumbe(codertarget_arduinobase_int_k_T *obj,
  i_codertarget_arduinobase_int_T *iobj_0)
{
  iobj_0->AvailablePwmPinNames.f1 = '2';
  iobj_0->AvailablePwmPinNames.f2 = '3';
  iobj_0->AvailablePwmPinNames.f3 = '4';
  iobj_0->AvailablePwmPinNames.f4 = '5';
  iobj_0->AvailablePwmPinNames.f5 = '6';
  iobj_0->AvailablePwmPinNames.f6 = '7';
  iobj_0->AvailablePwmPinNames.f7 = '8';
  iobj_0->AvailablePwmPinNames.f8 = '9';
  iobj_0->AvailablePwmPinNames.f9[0] = '1';
  iobj_0->AvailablePwmPinNames.f9[1] = '0';
  iobj_0->AvailablePwmPinNames.f10[0] = '1';
  iobj_0->AvailablePwmPinNames.f10[1] = '1';
  iobj_0->AvailablePwmPinNames.f11[0] = '1';
  iobj_0->AvailablePwmPinNames.f11[1] = '2';
  iobj_0->AvailablePwmPinNames.f12[0] = '1';
  iobj_0->AvailablePwmPinNames.f12[1] = '3';
  obj->Hw = iobj_0;
}

/* Model step function for TID0 */
void sat_v4_step0(void)                /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(sat_v4_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&sat_v4_M->solverInfo,((sat_v4_M->Timing.clockTick0+1)*
      sat_v4_M->Timing.stepSize0));

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(sat_v4_M)) {
    sat_v4_M->Timing.t[0] = rtsiGetT(&sat_v4_M->solverInfo);
  }

  {
    uint16_T rtb_Ft_sensor_0;
    uint16_T rtb_POT_SENSOR_0;
    codertarget_arduinobase_inter_T *obj;
    real_T Switch_f;
    real_T Switch;
    uint32_T PID_ELAPS_T;
    uint8_T tmp;

    /* TransferFcn: '<S2>/Transfer Fcn' */
    sat_v4_B.TransferFcn = 0.0;
    sat_v4_B.TransferFcn += sat_v4_P.TransferFcn_C * sat_v4_X.TransferFcn_CSTATE;

    /* RateTransition generated from: '<Root>/Chart' */
    if (rtmIsMajorTimeStep(sat_v4_M)) {
      /* Delay: '<S2>/Delay' */
      sat_v4_B.Delay = sat_v4_DW.Delay_DSTATE[0];
      if (sat_v4_M->Timing.RateInteraction.TID1_2) {
        sat_v4_B.TmpRTBAtChartInport4 = sat_v4_DW.TmpRTBAtChartInport4_Buffer0;

        /* RateTransition generated from: '<Root>/Chart' */
        sat_v4_B.TmpRTBAtChartInport5 = sat_v4_DW.TmpRTBAtChartInport5_Buffer0;

        /* RateTransition generated from: '<Root>/Chart' */
        sat_v4_B.TmpRTBAtChartInport6 = sat_v4_DW.TmpRTBAtChartInport6_Buffer0;

        /* RateTransition generated from: '<Root>/Chart' */
        sat_v4_B.ONOFF = sat_v4_DW.ONOFF_Buffer0;

        /* RateTransition generated from: '<Root>/Chart' */
        sat_v4_B.TmpRTBAtChartInport9 = sat_v4_DW.TmpRTBAtChartInport9_Buffer0;

        /* RateTransition generated from: '<Root>/Chart' */
        sat_v4_B.TmpRTBAtChartInport10 = sat_v4_DW.TmpRTBAtChartInport10_Buffer0;

        /* RateTransition generated from: '<Root>/Chart' */
        sat_v4_B.TmpRTBAtChartInport11 = sat_v4_DW.TmpRTBAtChartInport11_Buffer0;

        /* RateTransition generated from: '<Root>/Chart' */
        sat_v4_B.TmpRTBAtChartInport12 = sat_v4_DW.TmpRTBAtChartInport12_Buffer0;
      }
    }

    /* End of RateTransition generated from: '<Root>/Chart' */

    /* Switch: '<S2>/Switch' incorporates:
     *  Constant: '<S2>/One'
     *  Constant: '<S2>/Zero'
     *  Sum: '<S2>/Sum'
     */
    if (sat_v4_B.TransferFcn - sat_v4_B.Delay > sat_v4_P.Switch_Threshold) {
      Switch = sat_v4_P.Zero_Value;
    } else {
      Switch = sat_v4_P.One_Value;
    }

    /* End of Switch: '<S2>/Switch' */

    /* TransferFcn: '<S3>/Transfer Fcn' */
    sat_v4_B.TransferFcn_m = 0.0;
    sat_v4_B.TransferFcn_m += sat_v4_P.TransferFcn_C_g *
      sat_v4_X.TransferFcn_CSTATE_p;
    if (rtmIsMajorTimeStep(sat_v4_M)) {
      /* Delay: '<S3>/Delay' */
      sat_v4_B.Delay_g = sat_v4_DW.Delay_DSTATE_l[0];
    }

    /* Switch: '<S3>/Switch' incorporates:
     *  Constant: '<S3>/One'
     *  Constant: '<S3>/Zero'
     *  Sum: '<S3>/Sum'
     */
    if (sat_v4_B.TransferFcn_m - sat_v4_B.Delay_g > sat_v4_P.Switch_Threshold_b)
    {
      Switch_f = sat_v4_P.Zero_Value_b;
    } else {
      Switch_f = sat_v4_P.One_Value_b;
    }

    /* End of Switch: '<S3>/Switch' */
    if (rtmIsMajorTimeStep(sat_v4_M)) {
      /* MATLABSystem: '<Root>/Analog Input2' */
      if (sat_v4_DW.obj.SampleTime != sat_v4_P.AnalogInput2_SampleTime) {
        sat_v4_DW.obj.SampleTime = sat_v4_P.AnalogInput2_SampleTime;
      }

      obj = &sat_v4_DW.obj;
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(54UL);
      MW_AnalogInSingle_ReadResult
        (sat_v4_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_Ft_sensor_0, 3);

      /* MATLABSystem: '<Root>/Analog Input1' */
      if (sat_v4_DW.obj_p.SampleTime != sat_v4_P.AnalogInput1_SampleTime) {
        sat_v4_DW.obj_p.SampleTime = sat_v4_P.AnalogInput1_SampleTime;
      }

      obj = &sat_v4_DW.obj_p;
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(55UL);
      MW_AnalogInSingle_ReadResult
        (sat_v4_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_POT_SENSOR_0,
         3);

      /* Chart: '<Root>/Chart' incorporates:
       *  Gain: '<S43>/Proportional Gain'
       *  MATLABSystem: '<Root>/Analog Input1'
       *  MATLABSystem: '<Root>/Analog Input2'
       *  Sum: '<S47>/Sum'
       *  Sum: '<S5>/Sum'
       */
      if (sat_v4_DW.is_active_c3_sat_v4 == 0U) {
        sat_v4_DW.is_active_c3_sat_v4 = 1U;
        sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_Stop;
        sat_v4_B.servo = 160.0;
      } else {
        switch (sat_v4_DW.is_c3_sat_v4) {
         case sat_v4_IN_BW:
          if (!sat_v4_B.ONOFF) {
            sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_Stop;
            sat_v4_B.servo = 160.0;
          } else if ((Switch_f == 1.0) || ((!sat_v4_B.TmpRTBAtChartInport5) && (
                       !sat_v4_B.TmpRTBAtChartInport11))) {
            sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_Start;
            sat_v4_B.steppON = 0.0;
            sat_v4_B.FW_LED = 0.0;
            sat_v4_B.BW_LED = 0.0;
            sat_v4_B.servo = 160.0;
            sat_v4_B.Gripper_LED = 0.0;
            sat_v4_B.pot_status = (rtb_POT_SENSOR_0 <= 500U);
          } else {
            sat_v4_B.BW_LED = 1.0;
            sat_v4_B.direction = 0.0;
            sat_v4_B.steppON = 1.0;
          }
          break;

         case sat_v4_IN_FW:
          if (!sat_v4_B.ONOFF) {
            sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_Stop;
            sat_v4_B.servo = 160.0;
          } else if ((Switch == 1.0) || ((!sat_v4_B.TmpRTBAtChartInport6) &&
                      (!sat_v4_B.TmpRTBAtChartInport10))) {
            sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_Start;
            sat_v4_B.steppON = 0.0;
            sat_v4_B.FW_LED = 0.0;
            sat_v4_B.BW_LED = 0.0;
            sat_v4_B.servo = 160.0;
            sat_v4_B.Gripper_LED = 0.0;
            sat_v4_B.pot_status = (rtb_POT_SENSOR_0 <= 500U);
          } else {
            sat_v4_B.FW_LED = 1.0;
            sat_v4_B.direction = 1.0;
            sat_v4_B.steppON = 1.0;
          }
          break;

         case sat_v4_IN_Gripper:
          sat_v4_B.Gripper_LED = 1.0;
          if ((!sat_v4_B.TmpRTBAtChartInport4) &&
              (!sat_v4_B.TmpRTBAtChartInport12)) {
            sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_Start;
            sat_v4_B.steppON = 0.0;
            sat_v4_B.FW_LED = 0.0;
            sat_v4_B.BW_LED = 0.0;
            sat_v4_B.servo = 160.0;
            sat_v4_B.Gripper_LED = 0.0;
            sat_v4_B.pot_status = (rtb_POT_SENSOR_0 <= 500U);
          } else {
            if (!sat_v4_B.ONOFF) {
              sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_Stop;
              sat_v4_B.servo = 160.0;
            }
          }
          break;

         case sat_v4_IN_Start:
          sat_v4_B.Gripper_LED = 0.0;
          if ((!sat_v4_B.ONOFF) || (!sat_v4_B.TmpRTBAtChartInport9)) {
            sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_Stop;
            sat_v4_B.servo = 160.0;
          } else if ((sat_v4_B.TmpRTBAtChartInport6 ||
                      sat_v4_B.TmpRTBAtChartInport10) && (Switch == 0.0)) {
            sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_FW;
          } else if (sat_v4_B.TmpRTBAtChartInport4 ||
                     sat_v4_B.TmpRTBAtChartInport12) {
            sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_Gripper;
            sat_v4_B.Gripper_LED = 1.0;
            if (rtb_Ft_sensor_0 < 200U) {
              /* Outputs for Function Call SubSystem: '<S1>/PID' */
              if (sat_v4_DW.PID_RESET_ELAPS_T) {
                PID_ELAPS_T = 0UL;
              } else {
                PID_ELAPS_T = sat_v4_M->Timing.clockTick1 - sat_v4_DW.PID_PREV_T;
              }

              sat_v4_DW.PID_PREV_T = sat_v4_M->Timing.clockTick1;
              sat_v4_DW.PID_RESET_ELAPS_T = false;

              /* DiscreteIntegrator: '<S33>/Filter' */
              if (sat_v4_DW.Filter_SYSTEM_ENABLE == 0) {
                sat_v4_DW.Filter_DSTATE += sat_v4_P.Filter_gainval * (real_T)
                  PID_ELAPS_T * sat_v4_DW.Filter_PREV_U;
              }

              /* End of DiscreteIntegrator: '<S33>/Filter' */

              /* Gain: '<S41>/Filter Coefficient' incorporates:
               *  Gain: '<S32>/Derivative Gain'
               *  Sum: '<S33>/SumD'
               *  Sum: '<S5>/Sum'
               */
              sat_v4_DW.Filter_PREV_U = ((400.0 - (real_T)rtb_Ft_sensor_0) *
                sat_v4_P.PIDController_D - sat_v4_DW.Filter_DSTATE) *
                sat_v4_P.PIDController_N;

              /* DiscreteIntegrator: '<S38>/Integrator' */
              if (sat_v4_DW.Integrator_SYSTEM_ENABLE == 0) {
                sat_v4_DW.Integrator_DSTATE += sat_v4_P.Integrator_gainval *
                  (real_T)PID_ELAPS_T * sat_v4_DW.Integrator_PREV_U;
              }

              /* End of DiscreteIntegrator: '<S38>/Integrator' */

              /* Update for DiscreteIntegrator: '<S33>/Filter' */
              sat_v4_DW.Filter_SYSTEM_ENABLE = 0U;

              /* Update for DiscreteIntegrator: '<S38>/Integrator' incorporates:
               *  Gain: '<S35>/Integral Gain'
               *  Sum: '<S5>/Sum'
               */
              sat_v4_DW.Integrator_SYSTEM_ENABLE = 0U;
              sat_v4_DW.Integrator_PREV_U = (400.0 - (real_T)rtb_Ft_sensor_0) *
                sat_v4_P.PIDController_I;
              sat_v4_B.servo = 160.0 - (((400.0 - (real_T)rtb_Ft_sensor_0) *
                sat_v4_P.PIDController_P + sat_v4_DW.Integrator_DSTATE) +
                sat_v4_DW.Filter_PREV_U);

              /* End of Outputs for SubSystem: '<S1>/PID' */
            }
          } else {
            if ((sat_v4_B.TmpRTBAtChartInport5 || sat_v4_B.TmpRTBAtChartInport11)
                && (Switch_f == 0.0)) {
              sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_BW;
            }
          }
          break;

         default:
          /* case IN_Stop: */
          if (sat_v4_B.ONOFF && sat_v4_B.TmpRTBAtChartInport9) {
            sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_Start;
            sat_v4_B.steppON = 0.0;
            sat_v4_B.FW_LED = 0.0;
            sat_v4_B.BW_LED = 0.0;
            sat_v4_B.servo = 160.0;
            sat_v4_B.Gripper_LED = 0.0;
            sat_v4_B.pot_status = (rtb_POT_SENSOR_0 <= 500U);
          }
          break;
        }
      }

      /* End of Chart: '<Root>/Chart' */

      /* MATLABSystem: '<Root>/Digital Output1' */
      Switch = rt_roundd_snf(sat_v4_B.Gripper_LED);
      if (Switch < 256.0) {
        if (Switch >= 0.0) {
          tmp = (uint8_T)Switch;
        } else {
          tmp = 0U;
        }
      } else {
        tmp = MAX_uint8_T;
      }

      writeDigitalPin(12, tmp);

      /* End of MATLABSystem: '<Root>/Digital Output1' */

      /* MATLABSystem: '<Root>/Digital Output2' */
      Switch = rt_roundd_snf(sat_v4_B.FW_LED);
      if (Switch < 256.0) {
        if (Switch >= 0.0) {
          tmp = (uint8_T)Switch;
        } else {
          tmp = 0U;
        }
      } else {
        tmp = MAX_uint8_T;
      }

      writeDigitalPin(13, tmp);

      /* End of MATLABSystem: '<Root>/Digital Output2' */

      /* MATLABSystem: '<Root>/Digital Output3' */
      Switch = rt_roundd_snf(sat_v4_B.BW_LED);
      if (Switch < 256.0) {
        if (Switch >= 0.0) {
          tmp = (uint8_T)Switch;
        } else {
          tmp = 0U;
        }
      } else {
        tmp = MAX_uint8_T;
      }

      writeDigitalPin(8, tmp);

      /* End of MATLABSystem: '<Root>/Digital Output3' */

      /* MATLABSystem: '<Root>/Standard Servo Write1' */
      if (sat_v4_B.servo < 0.0) {
        tmp = 0U;
      } else if (sat_v4_B.servo > 180.0) {
        tmp = 180U;
      } else {
        Switch = rt_roundd_snf(sat_v4_B.servo);
        if (Switch < 256.0) {
          if (Switch >= 0.0) {
            tmp = (uint8_T)Switch;
          } else {
            tmp = 0U;
          }
        } else {
          tmp = MAX_uint8_T;
        }
      }

      MW_servoWrite(0, tmp);

      /* End of MATLABSystem: '<Root>/Standard Servo Write1' */

      /* DiscretePulseGenerator: '<S4>/Pulse Generator2' */
      Switch = (sat_v4_DW.clockTickCounter < sat_v4_P.PulseGenerator2_Duty) &&
        (sat_v4_DW.clockTickCounter >= 0L) ? sat_v4_P.PulseGenerator2_Amp : 0.0;
      if (sat_v4_DW.clockTickCounter >= sat_v4_P.PulseGenerator2_Period - 1.0) {
        sat_v4_DW.clockTickCounter = 0L;
      } else {
        sat_v4_DW.clockTickCounter++;
      }

      /* End of DiscretePulseGenerator: '<S4>/Pulse Generator2' */

      /* RateTransition generated from: '<S4>/Product3' */
      if (sat_v4_M->Timing.RateInteraction.TID1_3) {
        sat_v4_B.TmpRTBAtProduct3Inport2 =
          sat_v4_DW.TmpRTBAtProduct3Inport2_Buffer0;
      }

      /* End of RateTransition generated from: '<S4>/Product3' */

      /* MATLABSystem: '<S4>/Digital Output3' incorporates:
       *  Logic: '<S4>/NOT'
       *  Product: '<S4>/Product1'
       *  Product: '<S4>/Product2'
       *  Product: '<S4>/Product3'
       *  Sum: '<S4>/Sum'
       */
      Switch = rt_roundd_snf(((real_T)!(sat_v4_B.pot_status != 0.0) *
        sat_v4_B.TmpRTBAtProduct3Inport2 + Switch * sat_v4_B.pot_status) *
        sat_v4_B.steppON);
      if (Switch < 256.0) {
        if (Switch >= 0.0) {
          tmp = (uint8_T)Switch;
        } else {
          tmp = 0U;
        }
      } else {
        tmp = MAX_uint8_T;
      }

      writeDigitalPin(3, tmp);

      /* End of MATLABSystem: '<S4>/Digital Output3' */

      /* MATLABSystem: '<S4>/Digital Output2' */
      Switch = rt_roundd_snf(sat_v4_B.direction);
      if (Switch < 256.0) {
        if (Switch >= 0.0) {
          tmp = (uint8_T)Switch;
        } else {
          tmp = 0U;
        }
      } else {
        tmp = MAX_uint8_T;
      }

      writeDigitalPin(2, tmp);

      /* End of MATLABSystem: '<S4>/Digital Output2' */

      /* RateTransition generated from: '<S2>/Transfer Fcn' */
      if (sat_v4_M->Timing.RateInteraction.TID1_2) {
        sat_v4_B.TmpRTBAtTransferFcnInport1 =
          sat_v4_DW.TmpRTBAtTransferFcnInport1_Buff;

        /* RateTransition generated from: '<S3>/Transfer Fcn' */
        sat_v4_B.TmpRTBAtTransferFcnInport1_n =
          sat_v4_DW.TmpRTBAtTransferFcnInport1_Bu_d;
      }

      /* End of RateTransition generated from: '<S2>/Transfer Fcn' */
    }
  }

  if (rtmIsMajorTimeStep(sat_v4_M)) {
    int_T frameIdx;
    if (rtmIsMajorTimeStep(sat_v4_M)) {
      for (frameIdx = 0; frameIdx < 9; frameIdx++) {
        /* Update for Delay: '<S2>/Delay' */
        sat_v4_DW.Delay_DSTATE[frameIdx] = sat_v4_DW.Delay_DSTATE[frameIdx + 1];

        /* Update for Delay: '<S3>/Delay' */
        sat_v4_DW.Delay_DSTATE_l[frameIdx] = sat_v4_DW.Delay_DSTATE_l[frameIdx +
          1];
      }

      /* Update for Delay: '<S2>/Delay' */
      sat_v4_DW.Delay_DSTATE[9] = sat_v4_B.TransferFcn;

      /* Update for Delay: '<S3>/Delay' */
      sat_v4_DW.Delay_DSTATE_l[9] = sat_v4_B.TransferFcn_m;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(sat_v4_M)) {
    rt_ertODEUpdateContinuousStates(&sat_v4_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++sat_v4_M->Timing.clockTick0;
    sat_v4_M->Timing.t[0] = rtsiGetSolverStopTime(&sat_v4_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.0005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    sat_v4_M->Timing.clockTick1++;
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void sat_v4_derivatives(void)
{
  XDot_sat_v4_T *_rtXdot;
  _rtXdot = ((XDot_sat_v4_T *) sat_v4_M->derivs);

  /* Derivatives for TransferFcn: '<S2>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += sat_v4_P.TransferFcn_A *
    sat_v4_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += sat_v4_B.TmpRTBAtTransferFcnInport1;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_p = 0.0;
  _rtXdot->TransferFcn_CSTATE_p += sat_v4_P.TransferFcn_A_m *
    sat_v4_X.TransferFcn_CSTATE_p;
  _rtXdot->TransferFcn_CSTATE_p += sat_v4_B.TmpRTBAtTransferFcnInport1_n;
}

/* Model step function for TID2 */
void sat_v4_step2(void)                /* Sample time: [0.001s, 0.0s] */
{
  int16_T rtb_DataTypeConversion;
  boolean_T rtb_Bw;

  /* MATLABSystem: '<Root>/Digital Input3' */
  if (sat_v4_DW.obj_i.SampleTime != sat_v4_P.step_size) {
    sat_v4_DW.obj_i.SampleTime = sat_v4_P.step_size;
  }

  rtb_Bw = readDigitalPin(10);

  /* Logic: '<Root>/Bw' incorporates:
   *  MATLABSystem: '<Root>/Digital Input3'
   */
  rtb_Bw = !rtb_Bw;

  /* RateTransition generated from: '<Root>/Chart' */
  sat_v4_DW.TmpRTBAtChartInport5_Buffer0 = rtb_Bw;

  /* MATLABSystem: '<Root>/Digital Input' */
  if (sat_v4_DW.obj_j.SampleTime != sat_v4_P.step_size) {
    sat_v4_DW.obj_j.SampleTime = sat_v4_P.step_size;
  }

  rtb_Bw = readDigitalPin(4);

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  MATLABSystem: '<Root>/Digital Input'
   */
  rtb_DataTypeConversion = rtb_Bw;

  /* RateTransition generated from: '<S2>/Transfer Fcn' */
  sat_v4_DW.TmpRTBAtTransferFcnInport1_Buff = rtb_DataTypeConversion;

  /* MATLABSystem: '<Root>/Digital Input1' */
  if (sat_v4_DW.obj_b.SampleTime != sat_v4_P.step_size) {
    sat_v4_DW.obj_b.SampleTime = sat_v4_P.step_size;
  }

  rtb_Bw = readDigitalPin(5);

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  MATLABSystem: '<Root>/Digital Input1'
   */
  rtb_DataTypeConversion = rtb_Bw;

  /* RateTransition generated from: '<S3>/Transfer Fcn' */
  sat_v4_DW.TmpRTBAtTransferFcnInport1_Bu_d = rtb_DataTypeConversion;

  /* MATLABSystem: '<Root>/Digital Input2' */
  if (sat_v4_DW.obj_l.SampleTime != sat_v4_P.step_size) {
    sat_v4_DW.obj_l.SampleTime = sat_v4_P.step_size;
  }

  rtb_Bw = readDigitalPin(6);

  /* Logic: '<Root>/G_SW' incorporates:
   *  MATLABSystem: '<Root>/Digital Input2'
   */
  rtb_Bw = !rtb_Bw;

  /* RateTransition generated from: '<Root>/Chart' */
  sat_v4_DW.TmpRTBAtChartInport4_Buffer0 = rtb_Bw;

  /* MATLABSystem: '<Root>/Digital Input4' */
  if (sat_v4_DW.obj_ix.SampleTime != sat_v4_P.step_size) {
    sat_v4_DW.obj_ix.SampleTime = sat_v4_P.step_size;
  }

  rtb_Bw = readDigitalPin(7);

  /* Logic: '<Root>/FW' incorporates:
   *  MATLABSystem: '<Root>/Digital Input4'
   */
  rtb_Bw = !rtb_Bw;

  /* RateTransition generated from: '<Root>/Chart' */
  sat_v4_DW.TmpRTBAtChartInport6_Buffer0 = rtb_Bw;

  /* MATLABSystem: '<Root>/Digital Input5' */
  if (sat_v4_DW.obj_n.SampleTime != sat_v4_P.step_size) {
    sat_v4_DW.obj_n.SampleTime = sat_v4_P.step_size;
  }

  rtb_Bw = readDigitalPin(11);

  /* End of MATLABSystem: '<Root>/Digital Input5' */

  /* RateTransition generated from: '<Root>/Chart' */
  sat_v4_DW.ONOFF_Buffer0 = rtb_Bw;

  /* MATLABSystem: '<Root>/Digital Input6' */
  if (sat_v4_DW.obj_g.SampleTime != sat_v4_P.step_size) {
    sat_v4_DW.obj_g.SampleTime = sat_v4_P.step_size;
  }

  rtb_Bw = readDigitalPin(22);

  /* End of MATLABSystem: '<Root>/Digital Input6' */

  /* RateTransition generated from: '<Root>/Chart' */
  sat_v4_DW.TmpRTBAtChartInport9_Buffer0 = rtb_Bw;

  /* MATLABSystem: '<Root>/Digital Input7' */
  if (sat_v4_DW.obj_ni.SampleTime != sat_v4_P.step_size) {
    sat_v4_DW.obj_ni.SampleTime = sat_v4_P.step_size;
  }

  rtb_Bw = readDigitalPin(26);

  /* End of MATLABSystem: '<Root>/Digital Input7' */

  /* RateTransition generated from: '<Root>/Chart' */
  sat_v4_DW.TmpRTBAtChartInport10_Buffer0 = rtb_Bw;

  /* MATLABSystem: '<Root>/Digital Input8' */
  if (sat_v4_DW.obj_f.SampleTime != sat_v4_P.step_size) {
    sat_v4_DW.obj_f.SampleTime = sat_v4_P.step_size;
  }

  rtb_Bw = readDigitalPin(24);

  /* End of MATLABSystem: '<Root>/Digital Input8' */

  /* RateTransition generated from: '<Root>/Chart' */
  sat_v4_DW.TmpRTBAtChartInport11_Buffer0 = rtb_Bw;

  /* MATLABSystem: '<Root>/Digital Input9' */
  if (sat_v4_DW.obj_lm.SampleTime != sat_v4_P.step_size) {
    sat_v4_DW.obj_lm.SampleTime = sat_v4_P.step_size;
  }

  rtb_Bw = readDigitalPin(28);

  /* End of MATLABSystem: '<Root>/Digital Input9' */

  /* RateTransition generated from: '<Root>/Chart' */
  sat_v4_DW.TmpRTBAtChartInport12_Buffer0 = rtb_Bw;
}

/* Model step function for TID3 */
void sat_v4_step3(void)                /* Sample time: [0.005s, 0.0s] */
{
  real_T rtb_PulseGenerator1;

  /* DiscretePulseGenerator: '<S4>/Pulse Generator1' */
  rtb_PulseGenerator1 = (sat_v4_DW.clockTickCounter_e <
    sat_v4_P.PulseGenerator1_Duty) && (sat_v4_DW.clockTickCounter_e >= 0L) ?
    sat_v4_P.PulseGenerator1_Amp : 0.0;
  if (sat_v4_DW.clockTickCounter_e >= sat_v4_P.PulseGenerator1_Period - 1.0) {
    sat_v4_DW.clockTickCounter_e = 0L;
  } else {
    sat_v4_DW.clockTickCounter_e++;
  }

  /* End of DiscretePulseGenerator: '<S4>/Pulse Generator1' */

  /* RateTransition generated from: '<S4>/Product3' */
  sat_v4_DW.TmpRTBAtProduct3Inport2_Buffer0 = rtb_PulseGenerator1;
}

/* Model initialize function */
void sat_v4_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&sat_v4_M->solverInfo, &sat_v4_M->Timing.simTimeStep);
    rtsiSetTPtr(&sat_v4_M->solverInfo, &rtmGetTPtr(sat_v4_M));
    rtsiSetStepSizePtr(&sat_v4_M->solverInfo, &sat_v4_M->Timing.stepSize0);
    rtsiSetdXPtr(&sat_v4_M->solverInfo, &sat_v4_M->derivs);
    rtsiSetContStatesPtr(&sat_v4_M->solverInfo, (real_T **)
                         &sat_v4_M->contStates);
    rtsiSetNumContStatesPtr(&sat_v4_M->solverInfo,
      &sat_v4_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&sat_v4_M->solverInfo,
      &sat_v4_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&sat_v4_M->solverInfo,
      &sat_v4_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&sat_v4_M->solverInfo,
      &sat_v4_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&sat_v4_M->solverInfo, (&rtmGetErrorStatus(sat_v4_M)));
    rtsiSetRTModelPtr(&sat_v4_M->solverInfo, sat_v4_M);
  }

  rtsiSetSimTimeStep(&sat_v4_M->solverInfo, MAJOR_TIME_STEP);
  sat_v4_M->intgData.y = sat_v4_M->odeY;
  sat_v4_M->intgData.f[0] = sat_v4_M->odeF[0];
  sat_v4_M->intgData.f[1] = sat_v4_M->odeF[1];
  sat_v4_M->intgData.f[2] = sat_v4_M->odeF[2];
  sat_v4_M->contStates = ((X_sat_v4_T *) &sat_v4_X);
  rtsiSetSolverData(&sat_v4_M->solverInfo, (void *)&sat_v4_M->intgData);
  rtsiSetSolverName(&sat_v4_M->solverInfo,"ode3");
  rtmSetTPtr(sat_v4_M, &sat_v4_M->Timing.tArray[0]);
  sat_v4_M->Timing.stepSize0 = 0.0005;

  {
    codertarget_arduinobase_inter_T *obj;
    int16_T i;

    /* Start for RateTransition generated from: '<Root>/Chart' */
    sat_v4_B.TmpRTBAtChartInport4 = sat_v4_P.TmpRTBAtChartInport4_InitialCon;

    /* Start for RateTransition generated from: '<Root>/Chart' */
    sat_v4_B.TmpRTBAtChartInport5 = sat_v4_P.TmpRTBAtChartInport5_InitialCon;

    /* Start for RateTransition generated from: '<Root>/Chart' */
    sat_v4_B.TmpRTBAtChartInport6 = sat_v4_P.TmpRTBAtChartInport6_InitialCon;

    /* Start for RateTransition generated from: '<Root>/Chart' */
    sat_v4_B.ONOFF = sat_v4_P.ONOFF_InitialCondition;

    /* Start for RateTransition generated from: '<Root>/Chart' */
    sat_v4_B.TmpRTBAtChartInport9 = sat_v4_P.TmpRTBAtChartInport9_InitialCon;

    /* Start for RateTransition generated from: '<Root>/Chart' */
    sat_v4_B.TmpRTBAtChartInport10 = sat_v4_P.TmpRTBAtChartInport10_InitialCo;

    /* Start for RateTransition generated from: '<Root>/Chart' */
    sat_v4_B.TmpRTBAtChartInport11 = sat_v4_P.TmpRTBAtChartInport11_InitialCo;

    /* Start for RateTransition generated from: '<Root>/Chart' */
    sat_v4_B.TmpRTBAtChartInport12 = sat_v4_P.TmpRTBAtChartInport12_InitialCo;

    /* Start for RateTransition generated from: '<S4>/Product3' */
    sat_v4_B.TmpRTBAtProduct3Inport2 = sat_v4_P.TmpRTBAtProduct3Inport2_Initial;

    /* Start for RateTransition generated from: '<S2>/Transfer Fcn' */
    sat_v4_B.TmpRTBAtTransferFcnInport1 =
      sat_v4_P.TmpRTBAtTransferFcnInport1_Init;

    /* Start for RateTransition generated from: '<S3>/Transfer Fcn' */
    sat_v4_B.TmpRTBAtTransferFcnInport1_n =
      sat_v4_P.TmpRTBAtTransferFcnInport1_In_j;

    /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn' */
    sat_v4_X.TransferFcn_CSTATE = 0.0;

    /* InitializeConditions for Delay: '<S2>/Delay' */
    for (i = 0; i < 10; i++) {
      sat_v4_DW.Delay_DSTATE[i] = sat_v4_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S2>/Delay' */

    /* InitializeConditions for RateTransition generated from: '<Root>/Chart' */
    sat_v4_DW.TmpRTBAtChartInport4_Buffer0 =
      sat_v4_P.TmpRTBAtChartInport4_InitialCon;

    /* InitializeConditions for RateTransition generated from: '<Root>/Chart' */
    sat_v4_DW.TmpRTBAtChartInport5_Buffer0 =
      sat_v4_P.TmpRTBAtChartInport5_InitialCon;

    /* InitializeConditions for RateTransition generated from: '<Root>/Chart' */
    sat_v4_DW.TmpRTBAtChartInport6_Buffer0 =
      sat_v4_P.TmpRTBAtChartInport6_InitialCon;

    /* InitializeConditions for RateTransition generated from: '<Root>/Chart' */
    sat_v4_DW.ONOFF_Buffer0 = sat_v4_P.ONOFF_InitialCondition;

    /* InitializeConditions for RateTransition generated from: '<Root>/Chart' */
    sat_v4_DW.TmpRTBAtChartInport9_Buffer0 =
      sat_v4_P.TmpRTBAtChartInport9_InitialCon;

    /* InitializeConditions for RateTransition generated from: '<Root>/Chart' */
    sat_v4_DW.TmpRTBAtChartInport10_Buffer0 =
      sat_v4_P.TmpRTBAtChartInport10_InitialCo;

    /* InitializeConditions for RateTransition generated from: '<Root>/Chart' */
    sat_v4_DW.TmpRTBAtChartInport11_Buffer0 =
      sat_v4_P.TmpRTBAtChartInport11_InitialCo;

    /* InitializeConditions for RateTransition generated from: '<Root>/Chart' */
    sat_v4_DW.TmpRTBAtChartInport12_Buffer0 =
      sat_v4_P.TmpRTBAtChartInport12_InitialCo;

    /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn' */
    sat_v4_X.TransferFcn_CSTATE_p = 0.0;

    /* InitializeConditions for Delay: '<S3>/Delay' */
    for (i = 0; i < 10; i++) {
      sat_v4_DW.Delay_DSTATE_l[i] = sat_v4_P.Delay_InitialCondition_a;
    }

    /* End of InitializeConditions for Delay: '<S3>/Delay' */

    /* InitializeConditions for RateTransition generated from: '<S4>/Product3' */
    sat_v4_DW.TmpRTBAtProduct3Inport2_Buffer0 =
      sat_v4_P.TmpRTBAtProduct3Inport2_Initial;

    /* InitializeConditions for RateTransition generated from: '<S2>/Transfer Fcn' */
    sat_v4_DW.TmpRTBAtTransferFcnInport1_Buff =
      sat_v4_P.TmpRTBAtTransferFcnInport1_Init;

    /* InitializeConditions for RateTransition generated from: '<S3>/Transfer Fcn' */
    sat_v4_DW.TmpRTBAtTransferFcnInport1_Bu_d =
      sat_v4_P.TmpRTBAtTransferFcnInport1_In_j;

    /* SystemInitialize for Chart: '<Root>/Chart' incorporates:
     *  SubSystem: '<S1>/PID'
     */
    /* InitializeConditions for DiscreteIntegrator: '<S33>/Filter' */
    sat_v4_DW.Filter_DSTATE = sat_v4_P.PIDController_InitialConditionF;

    /* InitializeConditions for DiscreteIntegrator: '<S38>/Integrator' */
    sat_v4_DW.Integrator_DSTATE = sat_v4_P.PIDController_InitialConditio_b;

    /* Start for MATLABSystem: '<Root>/Analog Input2' */
    sat_v4_DW.obj.matlabCodegenIsDeleted = true;
    sat_v4_DW.obj.isInitialized = 0L;
    sat_v4_DW.obj.SampleTime = -1.0;
    sat_v4_DW.obj.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj.SampleTime = sat_v4_P.AnalogInput2_SampleTime;
    obj = &sat_v4_DW.obj;
    sat_v4_DW.obj.isSetupComplete = false;
    sat_v4_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(54UL);
    sat_v4_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input1' */
    sat_v4_DW.obj_p.matlabCodegenIsDeleted = true;
    sat_v4_DW.obj_p.isInitialized = 0L;
    sat_v4_DW.obj_p.SampleTime = -1.0;
    sat_v4_DW.obj_p.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_p.SampleTime = sat_v4_P.AnalogInput1_SampleTime;
    obj = &sat_v4_DW.obj_p;
    sat_v4_DW.obj_p.isSetupComplete = false;
    sat_v4_DW.obj_p.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(55UL);
    sat_v4_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output1' */
    sat_v4_DW.obj_jb.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_jb.isInitialized = 1L;
    digitalIOSetup(12, 1);
    sat_v4_DW.obj_jb.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output2' */
    sat_v4_DW.obj_m.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_m.isInitialized = 1L;
    digitalIOSetup(13, 1);
    sat_v4_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output3' */
    sat_v4_DW.obj_ii.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_ii.isInitialized = 1L;
    digitalIOSetup(8, 1);
    sat_v4_DW.obj_ii.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Standard Servo Write1' */
    sat_v4_DW.obj_l5.isInitialized = 0L;
    arduino_ServoWrite_set_pinNumbe(&sat_v4_DW.obj_l5, &sat_v4_DW.gobj_2);
    sat_v4_DW.obj_l5.isInitialized = 1L;
    MW_servoAttach(0, 9);

    /* Start for MATLABSystem: '<S4>/Digital Output3' */
    sat_v4_DW.obj_bu.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_bu.isInitialized = 1L;
    digitalIOSetup(3, 1);
    sat_v4_DW.obj_bu.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Output2' */
    sat_v4_DW.obj_h.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_h.isInitialized = 1L;
    digitalIOSetup(2, 1);
    sat_v4_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input3' */
    sat_v4_DW.obj_i.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_i.SampleTime = sat_v4_P.step_size;
    sat_v4_DW.obj_i.isInitialized = 1L;
    digitalIOSetup(10, 0);
    sat_v4_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input' */
    sat_v4_DW.obj_j.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_j.SampleTime = sat_v4_P.step_size;
    sat_v4_DW.obj_j.isInitialized = 1L;
    digitalIOSetup(4, 0);
    sat_v4_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input1' */
    sat_v4_DW.obj_b.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_b.SampleTime = sat_v4_P.step_size;
    sat_v4_DW.obj_b.isInitialized = 1L;
    digitalIOSetup(5, 0);
    sat_v4_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input2' */
    sat_v4_DW.obj_l.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_l.SampleTime = sat_v4_P.step_size;
    sat_v4_DW.obj_l.isInitialized = 1L;
    digitalIOSetup(6, 0);
    sat_v4_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input4' */
    sat_v4_DW.obj_ix.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_ix.SampleTime = sat_v4_P.step_size;
    sat_v4_DW.obj_ix.isInitialized = 1L;
    digitalIOSetup(7, 0);
    sat_v4_DW.obj_ix.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input5' */
    sat_v4_DW.obj_n.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_n.SampleTime = sat_v4_P.step_size;
    sat_v4_DW.obj_n.isInitialized = 1L;
    digitalIOSetup(11, 0);
    sat_v4_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input6' */
    sat_v4_DW.obj_g.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_g.SampleTime = sat_v4_P.step_size;
    sat_v4_DW.obj_g.isInitialized = 1L;
    digitalIOSetup(22, 0);
    sat_v4_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input7' */
    sat_v4_DW.obj_ni.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_ni.SampleTime = sat_v4_P.step_size;
    sat_v4_DW.obj_ni.isInitialized = 1L;
    digitalIOSetup(26, 0);
    sat_v4_DW.obj_ni.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input8' */
    sat_v4_DW.obj_f.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_f.SampleTime = sat_v4_P.step_size;
    sat_v4_DW.obj_f.isInitialized = 1L;
    digitalIOSetup(24, 0);
    sat_v4_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input9' */
    sat_v4_DW.obj_lm.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_lm.SampleTime = sat_v4_P.step_size;
    sat_v4_DW.obj_lm.isInitialized = 1L;
    digitalIOSetup(28, 0);
    sat_v4_DW.obj_lm.isSetupComplete = true;

    /* Enable for Chart: '<Root>/Chart' incorporates:
     *  SubSystem: '<S1>/PID'
     */
    sat_v4_DW.PID_RESET_ELAPS_T = true;

    /* Enable for DiscreteIntegrator: '<S33>/Filter' */
    sat_v4_DW.Filter_SYSTEM_ENABLE = 1U;

    /* Enable for DiscreteIntegrator: '<S38>/Integrator' */
    sat_v4_DW.Integrator_SYSTEM_ENABLE = 1U;
  }
}

/* Model terminate function */
void sat_v4_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input2' */
  matlabCodegenHan_kxmhghao1ntb0h(&sat_v4_DW.obj);

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  matlabCodegenHand_kxmhghao1ntb0(&sat_v4_DW.obj_p);

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  matlabCodegenHandle__kxmhghao1n(&sat_v4_DW.obj_jb);

  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  matlabCodegenHandle__kxmhghao1n(&sat_v4_DW.obj_m);

  /* Terminate for MATLABSystem: '<Root>/Digital Output3' */
  matlabCodegenHandle__kxmhghao1n(&sat_v4_DW.obj_ii);

  /* Terminate for MATLABSystem: '<S4>/Digital Output3' */
  matlabCodegenHandle__kxmhghao1n(&sat_v4_DW.obj_bu);

  /* Terminate for MATLABSystem: '<S4>/Digital Output2' */
  matlabCodegenHandle__kxmhghao1n(&sat_v4_DW.obj_h);

  /* Terminate for MATLABSystem: '<Root>/Digital Input3' */
  matlabCodegenHandle_matlabCodeg(&sat_v4_DW.obj_i);

  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  matlabCodegenHandle_matlabCodeg(&sat_v4_DW.obj_j);

  /* Terminate for MATLABSystem: '<Root>/Digital Input1' */
  matlabCodegenHandle_matlabCodeg(&sat_v4_DW.obj_b);

  /* Terminate for MATLABSystem: '<Root>/Digital Input2' */
  matlabCodegenHandle_matlabCodeg(&sat_v4_DW.obj_l);

  /* Terminate for MATLABSystem: '<Root>/Digital Input4' */
  matlabCodegenHandle_matlabCodeg(&sat_v4_DW.obj_ix);

  /* Terminate for MATLABSystem: '<Root>/Digital Input5' */
  matlabCodegenHandle_matlabCodeg(&sat_v4_DW.obj_n);

  /* Terminate for MATLABSystem: '<Root>/Digital Input6' */
  matlabCodegenHandle_matlabCodeg(&sat_v4_DW.obj_g);

  /* Terminate for MATLABSystem: '<Root>/Digital Input7' */
  matlabCodegenHandle_matlabCodeg(&sat_v4_DW.obj_ni);

  /* Terminate for MATLABSystem: '<Root>/Digital Input8' */
  matlabCodegenHandle_matlabCodeg(&sat_v4_DW.obj_f);

  /* Terminate for MATLABSystem: '<Root>/Digital Input9' */
  matlabCodegenHandle_matlabCodeg(&sat_v4_DW.obj_lm);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
