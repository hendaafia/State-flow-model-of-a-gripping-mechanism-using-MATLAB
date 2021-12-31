/*
 * File: Project.h
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

#ifndef RTW_HEADER_Project_h_
#define RTW_HEADER_Project_h_
#include <math.h>
#include <stddef.h>
#ifndef Project_COMMON_INCLUDES_
# define Project_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_ServoWriteRead.h"
#include "MW_arduino_digitalio.h"
#include "MW_AnalogIn.h"
#endif                                 /* Project_COMMON_INCLUDES_ */

#include "Project_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T is_gripped;                   /* '<Root>/Chart' */
  real_T pot_status;                   /* '<Root>/Chart' */
  real_T On_LED;                       /* '<Root>/Chart' */
  real_T Gripper_LED;                  /* '<Root>/Chart' */
  real_T steppON;                      /* '<Root>/Chart' */
  real_T direction;                    /* '<Root>/Chart' */
} B_Project_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input' */
  codertarget_arduinobase_inter_T obj_a;/* '<Root>/Analog Input1' */
  codertarget_arduinobase_blo_o_T obj_b;/* '<Root>/Digital Input' */
  codertarget_arduinobase_blo_o_T obj_ac;/* '<Root>/Digital Input1' */
  codertarget_arduinobase_blo_o_T obj_aq;/* '<Root>/Digital Input2' */
  codertarget_arduinobase_blo_o_T obj_j;/* '<Root>/Digital Input3' */
  codertarget_arduinobase_blo_o_T obj_bg;/* '<Root>/Digital Input4' */
  codertarget_arduinobase_blo_o_T obj_d;/* '<Root>/Digital Input5' */
  codertarget_arduinobase_int_o_T obj_m;/* '<Root>/Standard Servo Write' */
  i_codertarget_arduinobase_int_T gobj_1;/* '<Root>/Standard Servo Write' */
  i_codertarget_arduinobase_int_T gobj_2;/* '<Root>/Standard Servo Write' */
  i_codertarget_arduinobase_int_T gobj_3;/* '<Root>/Standard Servo Write' */
  i_codertarget_arduinobase_int_T gobj_4;/* '<Root>/Standard Servo Write' */
  codertarget_arduinobase_block_T obj_o;/* '<S2>/Digital Output3' */
  codertarget_arduinobase_block_T obj_e;/* '<S2>/Digital Output2' */
  codertarget_arduinobase_block_T obj_ec;/* '<Root>/Digital Output' */
  codertarget_arduinobase_block_T obj_g;/* '<Root>/Digital Output1' */
  real_T PID_done;                     /* '<Root>/Chart' */
  int32_T clockTickCounter;            /* '<S2>/Pulse Generator2' */
  int32_T clockTickCounter_n;          /* '<S2>/Pulse Generator1' */
  uint8_T is_active_c3_Project;        /* '<Root>/Chart' */
  uint8_T is_c3_Project;               /* '<Root>/Chart' */
} DW_Project_T;

/* Parameters (default storage) */
struct P_Project_T_ {
  real_T step_size;                    /* Variable: step_size
                                        * Referenced by:
                                        *   '<Root>/Digital Input'
                                        *   '<Root>/Digital Input1'
                                        *   '<Root>/Digital Input2'
                                        *   '<Root>/Digital Input3'
                                        *   '<Root>/Digital Input4'
                                        *   '<Root>/Digital Input5'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S41>/Proportional Gain'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T servo_action_Y0;              /* Computed Parameter: servo_action_Y0
                                        * Referenced by: '<S3>/servo_action'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T PulseGenerator2_Amp;          /* Expression: 1
                                        * Referenced by: '<S2>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_Period;   /* Computed Parameter: PulseGenerator2_Period
                                    * Referenced by: '<S2>/Pulse Generator2'
                                    */
  real_T PulseGenerator2_Duty;       /* Computed Parameter: PulseGenerator2_Duty
                                      * Referenced by: '<S2>/Pulse Generator2'
                                      */
  real_T PulseGenerator2_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S2>/Pulse Generator2'
                                        */
  real_T PulseGenerator1_Amp;          /* Expression: 1
                                        * Referenced by: '<S2>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;   /* Computed Parameter: PulseGenerator1_Period
                                    * Referenced by: '<S2>/Pulse Generator1'
                                    */
  real_T PulseGenerator1_Duty;       /* Computed Parameter: PulseGenerator1_Duty
                                      * Referenced by: '<S2>/Pulse Generator1'
                                      */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S2>/Pulse Generator1'
                                        */
  real_T Constant1_Value;              /* Expression: 50
                                        * Referenced by: '<Root>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Project_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_Project_T Project_P;

/* Block signals (default storage) */
extern B_Project_T Project_B;

/* Block states (default storage) */
extern DW_Project_T Project_DW;

/* Model entry point functions */
extern void Project_initialize(void);
extern void Project_step(void);
extern void Project_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Project_T *const Project_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<S3>/Scope1' : Unused code path elimination
 * Block '<S3>/Scope2' : Unused code path elimination
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S2>/Scope1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Project'
 * '<S1>'   : 'Project/Chart'
 * '<S2>'   : 'Project/Subsystem'
 * '<S3>'   : 'Project/Chart/PID'
 * '<S4>'   : 'Project/Chart/PID/PID Controller'
 * '<S5>'   : 'Project/Chart/PID/PID Controller/Anti-windup'
 * '<S6>'   : 'Project/Chart/PID/PID Controller/D Gain'
 * '<S7>'   : 'Project/Chart/PID/PID Controller/Filter'
 * '<S8>'   : 'Project/Chart/PID/PID Controller/Filter ICs'
 * '<S9>'   : 'Project/Chart/PID/PID Controller/I Gain'
 * '<S10>'  : 'Project/Chart/PID/PID Controller/Ideal P Gain'
 * '<S11>'  : 'Project/Chart/PID/PID Controller/Ideal P Gain Fdbk'
 * '<S12>'  : 'Project/Chart/PID/PID Controller/Integrator'
 * '<S13>'  : 'Project/Chart/PID/PID Controller/Integrator ICs'
 * '<S14>'  : 'Project/Chart/PID/PID Controller/N Copy'
 * '<S15>'  : 'Project/Chart/PID/PID Controller/N Gain'
 * '<S16>'  : 'Project/Chart/PID/PID Controller/P Copy'
 * '<S17>'  : 'Project/Chart/PID/PID Controller/Parallel P Gain'
 * '<S18>'  : 'Project/Chart/PID/PID Controller/Reset Signal'
 * '<S19>'  : 'Project/Chart/PID/PID Controller/Saturation'
 * '<S20>'  : 'Project/Chart/PID/PID Controller/Saturation Fdbk'
 * '<S21>'  : 'Project/Chart/PID/PID Controller/Sum'
 * '<S22>'  : 'Project/Chart/PID/PID Controller/Sum Fdbk'
 * '<S23>'  : 'Project/Chart/PID/PID Controller/Tracking Mode'
 * '<S24>'  : 'Project/Chart/PID/PID Controller/Tracking Mode Sum'
 * '<S25>'  : 'Project/Chart/PID/PID Controller/Tsamp - Integral'
 * '<S26>'  : 'Project/Chart/PID/PID Controller/Tsamp - Ngain'
 * '<S27>'  : 'Project/Chart/PID/PID Controller/postSat Signal'
 * '<S28>'  : 'Project/Chart/PID/PID Controller/preSat Signal'
 * '<S29>'  : 'Project/Chart/PID/PID Controller/Anti-windup/Disabled'
 * '<S30>'  : 'Project/Chart/PID/PID Controller/D Gain/Disabled'
 * '<S31>'  : 'Project/Chart/PID/PID Controller/Filter/Disabled'
 * '<S32>'  : 'Project/Chart/PID/PID Controller/Filter ICs/Disabled'
 * '<S33>'  : 'Project/Chart/PID/PID Controller/I Gain/Disabled'
 * '<S34>'  : 'Project/Chart/PID/PID Controller/Ideal P Gain/Passthrough'
 * '<S35>'  : 'Project/Chart/PID/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S36>'  : 'Project/Chart/PID/PID Controller/Integrator/Disabled'
 * '<S37>'  : 'Project/Chart/PID/PID Controller/Integrator ICs/Disabled'
 * '<S38>'  : 'Project/Chart/PID/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S39>'  : 'Project/Chart/PID/PID Controller/N Gain/Disabled'
 * '<S40>'  : 'Project/Chart/PID/PID Controller/P Copy/Disabled'
 * '<S41>'  : 'Project/Chart/PID/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S42>'  : 'Project/Chart/PID/PID Controller/Reset Signal/Disabled'
 * '<S43>'  : 'Project/Chart/PID/PID Controller/Saturation/Passthrough'
 * '<S44>'  : 'Project/Chart/PID/PID Controller/Saturation Fdbk/Disabled'
 * '<S45>'  : 'Project/Chart/PID/PID Controller/Sum/Passthrough_P'
 * '<S46>'  : 'Project/Chart/PID/PID Controller/Sum Fdbk/Disabled'
 * '<S47>'  : 'Project/Chart/PID/PID Controller/Tracking Mode/Disabled'
 * '<S48>'  : 'Project/Chart/PID/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S49>'  : 'Project/Chart/PID/PID Controller/Tsamp - Integral/Disabled wSignal Specification'
 * '<S50>'  : 'Project/Chart/PID/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S51>'  : 'Project/Chart/PID/PID Controller/postSat Signal/Forward_Path'
 * '<S52>'  : 'Project/Chart/PID/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_Project_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
