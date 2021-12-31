/*
 * File: Project.c
 *
 * Code generated for Simulink model 'Project'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Dec 30 13:58:55 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Project.h"
#include "Project_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Project_IN_BW                  ((uint8_T)1U)
#define Project_IN_FW                  ((uint8_T)2U)
#define Project_IN_Gripper             ((uint8_T)3U)
#define Project_IN_Release             ((uint8_T)4U)
#define Project_IN_Start               ((uint8_T)5U)
#define Project_IN_Stop                ((uint8_T)6U)

/* Block signals (default storage) */
B_Project_T Project_B;

/* Block states (default storage) */
DW_Project_T Project_DW;

/* Real-time model */
RT_MODEL_Project_T Project_M_;
RT_MODEL_Project_T *const Project_M = &Project_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabC_os5(codertarget_arduinobase_blo_o_T *obj);
static void Project_SystemCore_release_o(codertarget_arduinobase_inter_T *obj);
static void Proje_SystemCore_delete_os530mc(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHandle_mat_os530mc(codertarget_arduinobase_inter_T *obj);
static void Project_SystemCore_release(codertarget_arduinobase_inter_T *obj);
static void Project_SystemCore_delete_os(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHandle_matlabCo_os(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj);
static void arduino_ServoWrite_set_pinNumbe(codertarget_arduinobase_int_o_T *obj,
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

static void matlabCodegenHandle_matlabC_os5(codertarget_arduinobase_blo_o_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void Project_SystemCore_release_o(codertarget_arduinobase_inter_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
    MW_AnalogIn_Close(obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE);
  }
}

static void Proje_SystemCore_delete_os530mc(codertarget_arduinobase_inter_T *obj)
{
  Project_SystemCore_release_o(obj);
}

static void matlabCodegenHandle_mat_os530mc(codertarget_arduinobase_inter_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Proje_SystemCore_delete_os530mc(obj);
  }
}

static void Project_SystemCore_release(codertarget_arduinobase_inter_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15UL);
    MW_AnalogIn_Close(obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE);
  }
}

static void Project_SystemCore_delete_os(codertarget_arduinobase_inter_T *obj)
{
  Project_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCo_os(codertarget_arduinobase_inter_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Project_SystemCore_delete_os(obj);
  }
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void arduino_ServoWrite_set_pinNumbe(codertarget_arduinobase_int_o_T *obj,
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
void Project_step(void)
{
  uint16_T rtb_Ft_sensor_0;
  boolean_T rtb_ONOFF_0;
  uint16_T rtb_POT_SENSOR_0;
  codertarget_arduinobase_inter_T *obj;
  boolean_T rtb_G_SW;
  boolean_T rtb_Bw;
  boolean_T rtb_FW;
  real_T rtb_Switch;
  real_T rtb_PulseGenerator1;
  uint8_T tmp;

  /* MATLABSystem: '<Root>/Digital Input' */
  if (Project_DW.obj_b.SampleTime != Project_P.step_size) {
    Project_DW.obj_b.SampleTime = Project_P.step_size;
  }

  readDigitalPin(13);

  /* End of MATLABSystem: '<Root>/Digital Input' */

  /* MATLABSystem: '<Root>/Digital Input1' */
  if (Project_DW.obj_ac.SampleTime != Project_P.step_size) {
    Project_DW.obj_ac.SampleTime = Project_P.step_size;
  }

  readDigitalPin(4);

  /* End of MATLABSystem: '<Root>/Digital Input1' */

  /* MATLABSystem: '<Root>/Analog Input' */
  if (Project_DW.obj.SampleTime != Project_P.AnalogInput_SampleTime) {
    Project_DW.obj.SampleTime = Project_P.AnalogInput_SampleTime;
  }

  obj = &Project_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
  MW_AnalogInSingle_ReadResult
    (Project_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_Ft_sensor_0, 3);

  /* MATLABSystem: '<Root>/Digital Input2' */
  if (Project_DW.obj_aq.SampleTime != Project_P.step_size) {
    Project_DW.obj_aq.SampleTime = Project_P.step_size;
  }

  rtb_G_SW = readDigitalPin(6);

  /* Logic: '<Root>/G_SW' incorporates:
   *  MATLABSystem: '<Root>/Digital Input2'
   */
  rtb_G_SW = !rtb_G_SW;

  /* MATLABSystem: '<Root>/Digital Input3' */
  if (Project_DW.obj_j.SampleTime != Project_P.step_size) {
    Project_DW.obj_j.SampleTime = Project_P.step_size;
  }

  rtb_Bw = readDigitalPin(7);

  /* Logic: '<Root>/Bw' incorporates:
   *  MATLABSystem: '<Root>/Digital Input3'
   */
  rtb_Bw = !rtb_Bw;

  /* MATLABSystem: '<Root>/Digital Input4' */
  if (Project_DW.obj_bg.SampleTime != Project_P.step_size) {
    Project_DW.obj_bg.SampleTime = Project_P.step_size;
  }

  rtb_FW = readDigitalPin(10);

  /* Logic: '<Root>/FW' incorporates:
   *  MATLABSystem: '<Root>/Digital Input4'
   */
  rtb_FW = !rtb_FW;

  /* MATLABSystem: '<Root>/Digital Input5' */
  if (Project_DW.obj_d.SampleTime != Project_P.step_size) {
    Project_DW.obj_d.SampleTime = Project_P.step_size;
  }

  rtb_ONOFF_0 = readDigitalPin(11);

  /* MATLABSystem: '<Root>/Analog Input1' */
  if (Project_DW.obj_a.SampleTime != Project_P.AnalogInput1_SampleTime) {
    Project_DW.obj_a.SampleTime = Project_P.AnalogInput1_SampleTime;
  }

  obj = &Project_DW.obj_a;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15UL);
  MW_AnalogInSingle_ReadResult
    (Project_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_POT_SENSOR_0, 3);

  /* Chart: '<Root>/Chart' incorporates:
   *  MATLABSystem: '<Root>/Analog Input'
   *  MATLABSystem: '<Root>/Analog Input1'
   *  MATLABSystem: '<Root>/Digital Input5'
   */
  if (Project_DW.is_active_c3_Project == 0U) {
    Project_DW.is_active_c3_Project = 1U;
    Project_DW.is_c3_Project = Project_IN_Stop;
    Project_B.is_gripped = 0.0;
    Project_B.On_LED = 0.0;
  } else {
    switch (Project_DW.is_c3_Project) {
     case Project_IN_BW:
      if (!rtb_ONOFF_0) {
        Project_DW.is_c3_Project = Project_IN_Stop;
        Project_B.is_gripped = 0.0;
        Project_B.On_LED = 0.0;
      } else if (!rtb_Bw) {
        Project_DW.is_c3_Project = Project_IN_Start;
        Project_DW.PID_done = 0.0;
        Project_B.steppON = 0.0;
        Project_B.On_LED = 1.0;
        Project_B.Gripper_LED = 0.0;
        Project_B.pot_status = (rtb_POT_SENSOR_0 <= 100U);
      } else {
        Project_B.direction = 0.0;
        Project_B.steppON = 1.0;
      }
      break;

     case Project_IN_FW:
      if (!rtb_ONOFF_0) {
        Project_DW.is_c3_Project = Project_IN_Stop;
        Project_B.is_gripped = 0.0;
        Project_B.On_LED = 0.0;
      } else if (!rtb_FW) {
        Project_DW.is_c3_Project = Project_IN_Start;
        Project_DW.PID_done = 0.0;
        Project_B.steppON = 0.0;
        Project_B.On_LED = 1.0;
        Project_B.Gripper_LED = 0.0;
        Project_B.pot_status = (rtb_POT_SENSOR_0 <= 100U);
      } else {
        Project_B.direction = 1.0;
        Project_B.steppON = 1.0;
      }
      break;

     case Project_IN_Gripper:
      Project_B.is_gripped = 1.0;
      Project_B.Gripper_LED = 1.0;
      if (!rtb_ONOFF_0) {
        Project_DW.is_c3_Project = Project_IN_Stop;
        Project_B.is_gripped = 0.0;
        Project_B.On_LED = 0.0;
      } else if (Project_DW.PID_done == 1.0) {
        Project_DW.is_c3_Project = Project_IN_Start;
        Project_DW.PID_done = 0.0;
        Project_B.steppON = 0.0;
        Project_B.On_LED = 1.0;
        Project_B.Gripper_LED = 0.0;
        Project_B.pot_status = (rtb_POT_SENSOR_0 <= 100U);
      } else {
        rtb_POT_SENSOR_0 = 400U - /*MW:OvSatOk*/ rtb_Ft_sensor_0;
        if (rtb_POT_SENSOR_0 > 400U) {
          rtb_POT_SENSOR_0 = 0U;
        }

        if ((rtb_Ft_sensor_0 > 400U) || (rtb_Ft_sensor_0 == 400U) ||
            (rtb_POT_SENSOR_0 < 0.1)) {
          Project_DW.PID_done = 1.0;
        }
      }
      break;

     case Project_IN_Release:
      Project_B.is_gripped = 0.0;
      if (!rtb_ONOFF_0) {
        Project_DW.is_c3_Project = Project_IN_Stop;
        Project_B.is_gripped = 0.0;
        Project_B.On_LED = 0.0;
      } else {
        if (rtb_Ft_sensor_0 == 0U) {
          Project_DW.is_c3_Project = Project_IN_Start;
          Project_DW.PID_done = 0.0;
          Project_B.steppON = 0.0;
          Project_B.On_LED = 1.0;
          Project_B.Gripper_LED = 0.0;
          Project_B.pot_status = (rtb_POT_SENSOR_0 <= 100U);
        }
      }
      break;

     case Project_IN_Start:
      Project_B.On_LED = 1.0;
      Project_B.Gripper_LED = 0.0;
      if (!rtb_ONOFF_0) {
        Project_DW.is_c3_Project = Project_IN_Stop;
        Project_B.is_gripped = 0.0;
        Project_B.On_LED = 0.0;
      } else if (rtb_FW) {
        Project_DW.is_c3_Project = Project_IN_FW;
      } else if (rtb_Bw) {
        Project_DW.is_c3_Project = Project_IN_BW;
      } else if (rtb_G_SW && (Project_B.is_gripped == 0.0)) {
        Project_DW.is_c3_Project = Project_IN_Gripper;
        Project_B.is_gripped = 1.0;
        Project_B.Gripper_LED = 1.0;
      } else {
        if (rtb_G_SW && (Project_B.is_gripped == 1.0)) {
          Project_DW.is_c3_Project = Project_IN_Release;
          Project_B.is_gripped = 0.0;
        }
      }
      break;

     default:
      /* case IN_Stop: */
      Project_B.is_gripped = 0.0;
      Project_B.On_LED = 0.0;
      if (rtb_ONOFF_0) {
        Project_DW.is_c3_Project = Project_IN_Start;
        Project_DW.PID_done = 0.0;
        Project_B.steppON = 0.0;
        Project_B.On_LED = 1.0;
        Project_B.Gripper_LED = 0.0;
        Project_B.pot_status = (rtb_POT_SENSOR_0 <= 100U);
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<Root>/Digital Output' */
  rtb_Switch = rt_roundd_snf(Project_B.On_LED);
  if (rtb_Switch < 256.0) {
    if (rtb_Switch >= 0.0) {
      tmp = (uint8_T)rtb_Switch;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(0, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output' */

  /* MATLABSystem: '<Root>/Digital Output1' */
  rtb_Switch = rt_roundd_snf(Project_B.Gripper_LED);
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

  /* DiscretePulseGenerator: '<S2>/Pulse Generator2' */
  rtb_Switch = (Project_DW.clockTickCounter < Project_P.PulseGenerator2_Duty) &&
    (Project_DW.clockTickCounter >= 0L) ? Project_P.PulseGenerator2_Amp : 0.0;
  if (Project_DW.clockTickCounter >= Project_P.PulseGenerator2_Period - 1.0) {
    Project_DW.clockTickCounter = 0L;
  } else {
    Project_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S2>/Pulse Generator2' */

  /* DiscretePulseGenerator: '<S2>/Pulse Generator1' */
  rtb_PulseGenerator1 = (Project_DW.clockTickCounter_n <
    Project_P.PulseGenerator1_Duty) && (Project_DW.clockTickCounter_n >= 0L) ?
    Project_P.PulseGenerator1_Amp : 0.0;
  if (Project_DW.clockTickCounter_n >= Project_P.PulseGenerator1_Period - 1.0) {
    Project_DW.clockTickCounter_n = 0L;
  } else {
    Project_DW.clockTickCounter_n++;
  }

  /* End of DiscretePulseGenerator: '<S2>/Pulse Generator1' */

  /* Switch: '<S2>/Switch' */
  if (!(Project_B.pot_status != 0.0)) {
    rtb_Switch = rtb_PulseGenerator1;
  }

  /* End of Switch: '<S2>/Switch' */

  /* MATLABSystem: '<S2>/Digital Output3' incorporates:
   *  Product: '<S2>/Product1'
   */
  rtb_Switch = rt_roundd_snf(rtb_Switch * Project_B.steppON);
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
  rtb_Switch = rt_roundd_snf(Project_B.direction);
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

  /* MATLABSystem: '<Root>/Standard Servo Write' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (Project_P.Constant1_Value < 0.0) {
    tmp = 0U;
  } else if (Project_P.Constant1_Value > 180.0) {
    tmp = 180U;
  } else {
    rtb_Switch = rt_roundd_snf(Project_P.Constant1_Value);
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

  /* End of MATLABSystem: '<Root>/Standard Servo Write' */
}

/* Model initialize function */
void Project_initialize(void)
{
  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/Digital Input' */
    Project_DW.obj_b.matlabCodegenIsDeleted = false;
    Project_DW.obj_b.SampleTime = Project_P.step_size;
    Project_DW.obj_b.isInitialized = 1L;
    digitalIOSetup(13, 0);
    Project_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input1' */
    Project_DW.obj_ac.matlabCodegenIsDeleted = false;
    Project_DW.obj_ac.SampleTime = Project_P.step_size;
    Project_DW.obj_ac.isInitialized = 1L;
    digitalIOSetup(4, 0);
    Project_DW.obj_ac.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    Project_DW.obj.matlabCodegenIsDeleted = true;
    Project_DW.obj.isInitialized = 0L;
    Project_DW.obj.SampleTime = -1.0;
    Project_DW.obj.matlabCodegenIsDeleted = false;
    Project_DW.obj.SampleTime = Project_P.AnalogInput_SampleTime;
    obj = &Project_DW.obj;
    Project_DW.obj.isSetupComplete = false;
    Project_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(14UL);
    Project_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input2' */
    Project_DW.obj_aq.matlabCodegenIsDeleted = false;
    Project_DW.obj_aq.SampleTime = Project_P.step_size;
    Project_DW.obj_aq.isInitialized = 1L;
    digitalIOSetup(6, 0);
    Project_DW.obj_aq.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input3' */
    Project_DW.obj_j.matlabCodegenIsDeleted = false;
    Project_DW.obj_j.SampleTime = Project_P.step_size;
    Project_DW.obj_j.isInitialized = 1L;
    digitalIOSetup(7, 0);
    Project_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input4' */
    Project_DW.obj_bg.matlabCodegenIsDeleted = false;
    Project_DW.obj_bg.SampleTime = Project_P.step_size;
    Project_DW.obj_bg.isInitialized = 1L;
    digitalIOSetup(10, 0);
    Project_DW.obj_bg.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input5' */
    Project_DW.obj_d.matlabCodegenIsDeleted = false;
    Project_DW.obj_d.SampleTime = Project_P.step_size;
    Project_DW.obj_d.isInitialized = 1L;
    digitalIOSetup(11, 0);
    Project_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input1' */
    Project_DW.obj_a.matlabCodegenIsDeleted = true;
    Project_DW.obj_a.isInitialized = 0L;
    Project_DW.obj_a.SampleTime = -1.0;
    Project_DW.obj_a.matlabCodegenIsDeleted = false;
    Project_DW.obj_a.SampleTime = Project_P.AnalogInput1_SampleTime;
    obj = &Project_DW.obj_a;
    Project_DW.obj_a.isSetupComplete = false;
    Project_DW.obj_a.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(15UL);
    Project_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output' */
    Project_DW.obj_ec.matlabCodegenIsDeleted = false;
    Project_DW.obj_ec.isInitialized = 1L;
    digitalIOSetup(0, 1);
    Project_DW.obj_ec.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output1' */
    Project_DW.obj_g.matlabCodegenIsDeleted = false;
    Project_DW.obj_g.isInitialized = 1L;
    digitalIOSetup(12, 1);
    Project_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Output3' */
    Project_DW.obj_o.matlabCodegenIsDeleted = false;
    Project_DW.obj_o.isInitialized = 1L;
    digitalIOSetup(3, 1);
    Project_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Output2' */
    Project_DW.obj_e.matlabCodegenIsDeleted = false;
    Project_DW.obj_e.isInitialized = 1L;
    digitalIOSetup(2, 1);
    Project_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Standard Servo Write' */
    Project_DW.obj_m.isInitialized = 0L;
    arduino_ServoWrite_set_pinNumbe(&Project_DW.obj_m, &Project_DW.gobj_2);
    Project_DW.obj_m.isInitialized = 1L;
    MW_servoAttach(0, 9);
  }
}

/* Model terminate function */
void Project_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  matlabCodegenHandle_matlabC_os5(&Project_DW.obj_b);

  /* Terminate for MATLABSystem: '<Root>/Digital Input1' */
  matlabCodegenHandle_matlabC_os5(&Project_DW.obj_ac);

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  matlabCodegenHandle_mat_os530mc(&Project_DW.obj);

  /* Terminate for MATLABSystem: '<Root>/Digital Input2' */
  matlabCodegenHandle_matlabC_os5(&Project_DW.obj_aq);

  /* Terminate for MATLABSystem: '<Root>/Digital Input3' */
  matlabCodegenHandle_matlabC_os5(&Project_DW.obj_j);

  /* Terminate for MATLABSystem: '<Root>/Digital Input4' */
  matlabCodegenHandle_matlabC_os5(&Project_DW.obj_bg);

  /* Terminate for MATLABSystem: '<Root>/Digital Input5' */
  matlabCodegenHandle_matlabC_os5(&Project_DW.obj_d);

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  matlabCodegenHandle_matlabCo_os(&Project_DW.obj_a);

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  matlabCodegenHandle_matlabCodeg(&Project_DW.obj_ec);

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  matlabCodegenHandle_matlabCodeg(&Project_DW.obj_g);

  /* Terminate for MATLABSystem: '<S2>/Digital Output3' */
  matlabCodegenHandle_matlabCodeg(&Project_DW.obj_o);

  /* Terminate for MATLABSystem: '<S2>/Digital Output2' */
  matlabCodegenHandle_matlabCodeg(&Project_DW.obj_e);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
