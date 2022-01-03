/*
 * File: sat_v4.c
 *
 * Code generated for Simulink model 'sat_v4'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Jan  2 12:17:20 2022
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

/* Block states (default storage) */
DW_sat_v4_T sat_v4_DW;

/* Real-time model */
RT_MODEL_sat_v4_T sat_v4_M_;
RT_MODEL_sat_v4_T *const sat_v4_M = &sat_v4_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlab_kxmh(codertarget_arduinobase_blo_k_T *obj);
static void sat_v4_SystemCore_release_k(codertarget_arduinobase_inter_T *obj);
static void sat__SystemCore_delete_kxmhghao(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHandle_ma_kxmhghao(codertarget_arduinobase_inter_T *obj);
static void sat_v4_SystemCore_release(codertarget_arduinobase_inter_T *obj);
static void sat_v4_SystemCore_delete_kxm(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHandle_matlabC_kxm(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj);
static void arduino_ServoWrite_set_pinNumbe(codertarget_arduinobase_int_k_T *obj,
  i_codertarget_arduinobase_int_T *iobj_0);
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

static void matlabCodegenHandle_matlab_kxmh(codertarget_arduinobase_blo_k_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void sat_v4_SystemCore_release_k(codertarget_arduinobase_inter_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(54UL);
    MW_AnalogIn_Close(obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE);
  }
}

static void sat__SystemCore_delete_kxmhghao(codertarget_arduinobase_inter_T *obj)
{
  sat_v4_SystemCore_release_k(obj);
}

static void matlabCodegenHandle_ma_kxmhghao(codertarget_arduinobase_inter_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    sat__SystemCore_delete_kxmhghao(obj);
  }
}

static void sat_v4_SystemCore_release(codertarget_arduinobase_inter_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(55UL);
    MW_AnalogIn_Close(obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE);
  }
}

static void sat_v4_SystemCore_delete_kxm(codertarget_arduinobase_inter_T *obj)
{
  sat_v4_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabC_kxm(codertarget_arduinobase_inter_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    sat_v4_SystemCore_delete_kxm(obj);
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

/* Model step function */
void sat_v4_step(void)
{
  uint16_T rtb_Ft_sensor_0;
  boolean_T rtb_ONOFF_0;
  uint16_T rtb_POT_SENSOR_0;
  codertarget_arduinobase_inter_T *obj;
  boolean_T rtb_Bw;
  boolean_T rtb_G_SW;
  boolean_T rtb_FW;
  real_T rtb_Switch;
  real_T rtb_PulseGenerator1;
  uint32_T PID_ELAPS_T;
  uint8_T tmp;

  /* MATLABSystem: '<Root>/Digital Input' */
  if (sat_v4_DW.obj_j.SampleTime != sat_v4_P.step_size) {
    sat_v4_DW.obj_j.SampleTime = sat_v4_P.step_size;
  }

  readDigitalPin(5);

  /* End of MATLABSystem: '<Root>/Digital Input' */

  /* MATLABSystem: '<Root>/Digital Input1' */
  if (sat_v4_DW.obj_b.SampleTime != sat_v4_P.step_size) {
    sat_v4_DW.obj_b.SampleTime = sat_v4_P.step_size;
  }

  readDigitalPin(4);

  /* End of MATLABSystem: '<Root>/Digital Input1' */

  /* MATLABSystem: '<Root>/Analog Input2' */
  if (sat_v4_DW.obj.SampleTime != sat_v4_P.AnalogInput2_SampleTime) {
    sat_v4_DW.obj.SampleTime = sat_v4_P.AnalogInput2_SampleTime;
  }

  obj = &sat_v4_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(54UL);
  MW_AnalogInSingle_ReadResult
    (sat_v4_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_Ft_sensor_0, 3);

  /* MATLABSystem: '<Root>/Digital Input2' */
  if (sat_v4_DW.obj_l.SampleTime != sat_v4_P.step_size) {
    sat_v4_DW.obj_l.SampleTime = sat_v4_P.step_size;
  }

  rtb_G_SW = readDigitalPin(6);

  /* Logic: '<Root>/G_SW' incorporates:
   *  MATLABSystem: '<Root>/Digital Input2'
   */
  rtb_G_SW = !rtb_G_SW;

  /* MATLABSystem: '<Root>/Digital Input3' */
  if (sat_v4_DW.obj_i.SampleTime != sat_v4_P.step_size) {
    sat_v4_DW.obj_i.SampleTime = sat_v4_P.step_size;
  }

  rtb_Bw = readDigitalPin(10);

  /* Logic: '<Root>/Bw' incorporates:
   *  MATLABSystem: '<Root>/Digital Input3'
   */
  rtb_Bw = !rtb_Bw;

  /* MATLABSystem: '<Root>/Digital Input4' */
  if (sat_v4_DW.obj_ix.SampleTime != sat_v4_P.step_size) {
    sat_v4_DW.obj_ix.SampleTime = sat_v4_P.step_size;
  }

  rtb_FW = readDigitalPin(7);

  /* Logic: '<Root>/FW' incorporates:
   *  MATLABSystem: '<Root>/Digital Input4'
   */
  rtb_FW = !rtb_FW;

  /* MATLABSystem: '<Root>/Digital Input5' */
  if (sat_v4_DW.obj_n.SampleTime != sat_v4_P.step_size) {
    sat_v4_DW.obj_n.SampleTime = sat_v4_P.step_size;
  }

  rtb_ONOFF_0 = readDigitalPin(11);

  /* MATLABSystem: '<Root>/Analog Input1' */
  if (sat_v4_DW.obj_p.SampleTime != sat_v4_P.AnalogInput1_SampleTime) {
    sat_v4_DW.obj_p.SampleTime = sat_v4_P.AnalogInput1_SampleTime;
  }

  obj = &sat_v4_DW.obj_p;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(55UL);
  MW_AnalogInSingle_ReadResult
    (sat_v4_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_POT_SENSOR_0, 3);

  /* Chart: '<Root>/Chart' incorporates:
   *  Gain: '<S41>/Proportional Gain'
   *  MATLABSystem: '<Root>/Analog Input1'
   *  MATLABSystem: '<Root>/Analog Input2'
   *  MATLABSystem: '<Root>/Digital Input5'
   *  Sum: '<S3>/Sum'
   *  Sum: '<S45>/Sum'
   */
  if (sat_v4_DW.is_active_c3_sat_v4 == 0U) {
    sat_v4_DW.is_active_c3_sat_v4 = 1U;
    sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_Stop;
    sat_v4_B.servo = 160.0;
  } else {
    switch (sat_v4_DW.is_c3_sat_v4) {
     case sat_v4_IN_BW:
      if (!rtb_ONOFF_0) {
        sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_Stop;
        sat_v4_B.servo = 160.0;
      } else if (!rtb_Bw) {
        sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_Start;
        sat_v4_B.steppON = 0.0;
        sat_v4_B.FW_LED = 0.0;
        sat_v4_B.BW_LED = 0.0;
        sat_v4_B.servo = 160.0;
        sat_v4_B.Gripper_LED = 0.0;
        sat_v4_B.pot_status = (rtb_POT_SENSOR_0 <= 100U);
      } else {
        sat_v4_B.BW_LED = 1.0;
        sat_v4_B.direction = 0.0;
        sat_v4_B.steppON = 1.0;
      }
      break;

     case sat_v4_IN_FW:
      if (!rtb_ONOFF_0) {
        sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_Stop;
        sat_v4_B.servo = 160.0;
      } else if (!rtb_FW) {
        sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_Start;
        sat_v4_B.steppON = 0.0;
        sat_v4_B.FW_LED = 0.0;
        sat_v4_B.BW_LED = 0.0;
        sat_v4_B.servo = 160.0;
        sat_v4_B.Gripper_LED = 0.0;
        sat_v4_B.pot_status = (rtb_POT_SENSOR_0 <= 100U);
      } else {
        sat_v4_B.FW_LED = 1.0;
        sat_v4_B.direction = 1.0;
        sat_v4_B.steppON = 1.0;
      }
      break;

     case sat_v4_IN_Gripper:
      sat_v4_B.Gripper_LED = 1.0;
      if (!rtb_G_SW) {
        sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_Start;
        sat_v4_B.steppON = 0.0;
        sat_v4_B.FW_LED = 0.0;
        sat_v4_B.BW_LED = 0.0;
        sat_v4_B.servo = 160.0;
        sat_v4_B.Gripper_LED = 0.0;
        sat_v4_B.pot_status = (rtb_POT_SENSOR_0 <= 100U);
      } else {
        if (!rtb_ONOFF_0) {
          sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_Stop;
          sat_v4_B.servo = 160.0;
        }
      }
      break;

     case sat_v4_IN_Start:
      sat_v4_B.Gripper_LED = 0.0;
      if (!rtb_ONOFF_0) {
        sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_Stop;
        sat_v4_B.servo = 160.0;
      } else if (rtb_FW) {
        sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_FW;
      } else if (rtb_G_SW) {
        sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_Gripper;
        sat_v4_B.Gripper_LED = 1.0;
        if (rtb_Ft_sensor_0 < 200U) {
          /* Outputs for Function Call SubSystem: '<S1>/PID' */
          if (sat_v4_DW.PID_RESET_ELAPS_T) {
            PID_ELAPS_T = 0UL;
          } else {
            PID_ELAPS_T = sat_v4_M->Timing.clockTick0 - sat_v4_DW.PID_PREV_T;
          }

          sat_v4_DW.PID_PREV_T = sat_v4_M->Timing.clockTick0;
          sat_v4_DW.PID_RESET_ELAPS_T = false;

          /* DiscreteIntegrator: '<S31>/Filter' */
          if (sat_v4_DW.Filter_SYSTEM_ENABLE == 0) {
            sat_v4_DW.Filter_DSTATE += sat_v4_P.Filter_gainval * (real_T)
              PID_ELAPS_T * sat_v4_DW.Filter_PREV_U;
          }

          /* End of DiscreteIntegrator: '<S31>/Filter' */

          /* Gain: '<S39>/Filter Coefficient' incorporates:
           *  Gain: '<S30>/Derivative Gain'
           *  Sum: '<S31>/SumD'
           *  Sum: '<S3>/Sum'
           */
          sat_v4_DW.Filter_PREV_U = ((400.0 - (real_T)rtb_Ft_sensor_0) *
            sat_v4_P.PIDController_D - sat_v4_DW.Filter_DSTATE) *
            sat_v4_P.PIDController_N;

          /* DiscreteIntegrator: '<S36>/Integrator' */
          if (sat_v4_DW.Integrator_SYSTEM_ENABLE == 0) {
            sat_v4_DW.Integrator_DSTATE += sat_v4_P.Integrator_gainval * (real_T)
              PID_ELAPS_T * sat_v4_DW.Integrator_PREV_U;
          }

          /* End of DiscreteIntegrator: '<S36>/Integrator' */

          /* Update for DiscreteIntegrator: '<S31>/Filter' */
          sat_v4_DW.Filter_SYSTEM_ENABLE = 0U;

          /* Update for DiscreteIntegrator: '<S36>/Integrator' incorporates:
           *  Gain: '<S33>/Integral Gain'
           *  Sum: '<S3>/Sum'
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
        if (rtb_Bw) {
          sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_BW;
        }
      }
      break;

     default:
      /* case IN_Stop: */
      if (rtb_ONOFF_0) {
        sat_v4_DW.is_c3_sat_v4 = sat_v4_IN_Start;
        sat_v4_B.steppON = 0.0;
        sat_v4_B.FW_LED = 0.0;
        sat_v4_B.BW_LED = 0.0;
        sat_v4_B.servo = 160.0;
        sat_v4_B.Gripper_LED = 0.0;
        sat_v4_B.pot_status = (rtb_POT_SENSOR_0 <= 100U);
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<Root>/Digital Output1' */
  rtb_Switch = rt_roundd_snf(sat_v4_B.Gripper_LED);
  if (rtb_Switch < 256.0) {
    if (rtb_Switch >= 0.0) {
      tmp = (uint8_T)rtb_Switch;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(12, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output1' */

  /* MATLABSystem: '<Root>/Digital Output2' */
  rtb_Switch = rt_roundd_snf(sat_v4_B.FW_LED);
  if (rtb_Switch < 256.0) {
    if (rtb_Switch >= 0.0) {
      tmp = (uint8_T)rtb_Switch;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(13, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output2' */

  /* MATLABSystem: '<Root>/Digital Output3' */
  rtb_Switch = rt_roundd_snf(sat_v4_B.BW_LED);
  if (rtb_Switch < 256.0) {
    if (rtb_Switch >= 0.0) {
      tmp = (uint8_T)rtb_Switch;
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
    rtb_Switch = rt_roundd_snf(sat_v4_B.servo);
    if (rtb_Switch < 256.0) {
      if (rtb_Switch >= 0.0) {
        tmp = (uint8_T)rtb_Switch;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }
  }

  MW_servoWrite(0, tmp);

  /* End of MATLABSystem: '<Root>/Standard Servo Write1' */

  /* DiscretePulseGenerator: '<S2>/Pulse Generator2' */
  rtb_Switch = (sat_v4_DW.clockTickCounter < sat_v4_P.PulseGenerator2_Duty) &&
    (sat_v4_DW.clockTickCounter >= 0L) ? sat_v4_P.PulseGenerator2_Amp : 0.0;
  if (sat_v4_DW.clockTickCounter >= sat_v4_P.PulseGenerator2_Period - 1.0) {
    sat_v4_DW.clockTickCounter = 0L;
  } else {
    sat_v4_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S2>/Pulse Generator2' */

  /* DiscretePulseGenerator: '<S2>/Pulse Generator1' */
  rtb_PulseGenerator1 = (sat_v4_DW.clockTickCounter_e <
    sat_v4_P.PulseGenerator1_Duty) && (sat_v4_DW.clockTickCounter_e >= 0L) ?
    sat_v4_P.PulseGenerator1_Amp : 0.0;
  if (sat_v4_DW.clockTickCounter_e >= sat_v4_P.PulseGenerator1_Period - 1.0) {
    sat_v4_DW.clockTickCounter_e = 0L;
  } else {
    sat_v4_DW.clockTickCounter_e++;
  }

  /* End of DiscretePulseGenerator: '<S2>/Pulse Generator1' */

  /* Switch: '<S2>/Switch' */
  if (!(sat_v4_B.pot_status != 0.0)) {
    rtb_Switch = rtb_PulseGenerator1;
  }

  /* End of Switch: '<S2>/Switch' */

  /* MATLABSystem: '<S2>/Digital Output3' incorporates:
   *  Product: '<S2>/Product1'
   */
  rtb_Switch = rt_roundd_snf(rtb_Switch * sat_v4_B.steppON);
  if (rtb_Switch < 256.0) {
    if (rtb_Switch >= 0.0) {
      tmp = (uint8_T)rtb_Switch;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(3, tmp);

  /* End of MATLABSystem: '<S2>/Digital Output3' */

  /* MATLABSystem: '<S2>/Digital Output2' */
  rtb_Switch = rt_roundd_snf(sat_v4_B.direction);
  if (rtb_Switch < 256.0) {
    if (rtb_Switch >= 0.0) {
      tmp = (uint8_T)rtb_Switch;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(2, tmp);

  /* End of MATLABSystem: '<S2>/Digital Output2' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  sat_v4_M->Timing.clockTick0++;
}

/* Model initialize function */
void sat_v4_initialize(void)
{
  {
    codertarget_arduinobase_inter_T *obj;

    /* SystemInitialize for Chart: '<Root>/Chart' incorporates:
     *  SubSystem: '<S1>/PID'
     */
    /* InitializeConditions for DiscreteIntegrator: '<S31>/Filter' */
    sat_v4_DW.Filter_DSTATE = sat_v4_P.PIDController_InitialConditionF;

    /* InitializeConditions for DiscreteIntegrator: '<S36>/Integrator' */
    sat_v4_DW.Integrator_DSTATE = sat_v4_P.PIDController_InitialConditio_b;

    /* Start for MATLABSystem: '<Root>/Digital Input' */
    sat_v4_DW.obj_j.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_j.SampleTime = sat_v4_P.step_size;
    sat_v4_DW.obj_j.isInitialized = 1L;
    digitalIOSetup(5, 0);
    sat_v4_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input1' */
    sat_v4_DW.obj_b.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_b.SampleTime = sat_v4_P.step_size;
    sat_v4_DW.obj_b.isInitialized = 1L;
    digitalIOSetup(4, 0);
    sat_v4_DW.obj_b.isSetupComplete = true;

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

    /* Start for MATLABSystem: '<Root>/Digital Input2' */
    sat_v4_DW.obj_l.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_l.SampleTime = sat_v4_P.step_size;
    sat_v4_DW.obj_l.isInitialized = 1L;
    digitalIOSetup(6, 0);
    sat_v4_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input3' */
    sat_v4_DW.obj_i.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_i.SampleTime = sat_v4_P.step_size;
    sat_v4_DW.obj_i.isInitialized = 1L;
    digitalIOSetup(10, 0);
    sat_v4_DW.obj_i.isSetupComplete = true;

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

    /* Start for MATLABSystem: '<S2>/Digital Output3' */
    sat_v4_DW.obj_bu.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_bu.isInitialized = 1L;
    digitalIOSetup(3, 1);
    sat_v4_DW.obj_bu.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Output2' */
    sat_v4_DW.obj_h.matlabCodegenIsDeleted = false;
    sat_v4_DW.obj_h.isInitialized = 1L;
    digitalIOSetup(2, 1);
    sat_v4_DW.obj_h.isSetupComplete = true;

    /* Enable for Chart: '<Root>/Chart' incorporates:
     *  SubSystem: '<S1>/PID'
     */
    sat_v4_DW.PID_RESET_ELAPS_T = true;

    /* Enable for DiscreteIntegrator: '<S31>/Filter' */
    sat_v4_DW.Filter_SYSTEM_ENABLE = 1U;

    /* Enable for DiscreteIntegrator: '<S36>/Integrator' */
    sat_v4_DW.Integrator_SYSTEM_ENABLE = 1U;
  }
}

/* Model terminate function */
void sat_v4_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  matlabCodegenHandle_matlab_kxmh(&sat_v4_DW.obj_j);

  /* Terminate for MATLABSystem: '<Root>/Digital Input1' */
  matlabCodegenHandle_matlab_kxmh(&sat_v4_DW.obj_b);

  /* Terminate for MATLABSystem: '<Root>/Analog Input2' */
  matlabCodegenHandle_ma_kxmhghao(&sat_v4_DW.obj);

  /* Terminate for MATLABSystem: '<Root>/Digital Input2' */
  matlabCodegenHandle_matlab_kxmh(&sat_v4_DW.obj_l);

  /* Terminate for MATLABSystem: '<Root>/Digital Input3' */
  matlabCodegenHandle_matlab_kxmh(&sat_v4_DW.obj_i);

  /* Terminate for MATLABSystem: '<Root>/Digital Input4' */
  matlabCodegenHandle_matlab_kxmh(&sat_v4_DW.obj_ix);

  /* Terminate for MATLABSystem: '<Root>/Digital Input5' */
  matlabCodegenHandle_matlab_kxmh(&sat_v4_DW.obj_n);

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  matlabCodegenHandle_matlabC_kxm(&sat_v4_DW.obj_p);

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  matlabCodegenHandle_matlabCodeg(&sat_v4_DW.obj_jb);

  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  matlabCodegenHandle_matlabCodeg(&sat_v4_DW.obj_m);

  /* Terminate for MATLABSystem: '<Root>/Digital Output3' */
  matlabCodegenHandle_matlabCodeg(&sat_v4_DW.obj_ii);

  /* Terminate for MATLABSystem: '<S2>/Digital Output3' */
  matlabCodegenHandle_matlabCodeg(&sat_v4_DW.obj_bu);

  /* Terminate for MATLABSystem: '<S2>/Digital Output2' */
  matlabCodegenHandle_matlabCodeg(&sat_v4_DW.obj_h);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
