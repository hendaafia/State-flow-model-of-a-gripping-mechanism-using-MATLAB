/*
 * File: sat_v4.h
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

#ifndef RTW_HEADER_sat_v4_h_
#define RTW_HEADER_sat_v4_h_
#include <math.h>
#include <stddef.h>
#ifndef sat_v4_COMMON_INCLUDES_
# define sat_v4_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_ServoWriteRead.h"
#include "MW_arduino_digitalio.h"
#include "MW_AnalogIn.h"
#endif                                 /* sat_v4_COMMON_INCLUDES_ */

#include "sat_v4_types.h"
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
  real_T pot_status;                   /* '<Root>/Chart' */
  real_T steppON;                      /* '<Root>/Chart' */
  real_T direction;                    /* '<Root>/Chart' */
  real_T Gripper_LED;                  /* '<Root>/Chart' */
  real_T servo;                        /* '<Root>/Chart' */
  real_T BW_LED;                       /* '<Root>/Chart' */
  real_T FW_LED;                       /* '<Root>/Chart' */
} B_sat_v4_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input2' */
  codertarget_arduinobase_inter_T obj_p;/* '<Root>/Analog Input1' */
  codertarget_arduinobase_blo_k_T obj_j;/* '<Root>/Digital Input' */
  codertarget_arduinobase_blo_k_T obj_b;/* '<Root>/Digital Input1' */
  codertarget_arduinobase_blo_k_T obj_l;/* '<Root>/Digital Input2' */
  codertarget_arduinobase_blo_k_T obj_i;/* '<Root>/Digital Input3' */
  codertarget_arduinobase_blo_k_T obj_ix;/* '<Root>/Digital Input4' */
  codertarget_arduinobase_blo_k_T obj_n;/* '<Root>/Digital Input5' */
  codertarget_arduinobase_int_k_T obj_l5;/* '<Root>/Standard Servo Write1' */
  i_codertarget_arduinobase_int_T gobj_1;/* '<Root>/Standard Servo Write1' */
  i_codertarget_arduinobase_int_T gobj_2;/* '<Root>/Standard Servo Write1' */
  i_codertarget_arduinobase_int_T gobj_3;/* '<Root>/Standard Servo Write1' */
  i_codertarget_arduinobase_int_T gobj_4;/* '<Root>/Standard Servo Write1' */
  codertarget_arduinobase_block_T obj_bu;/* '<S2>/Digital Output3' */
  codertarget_arduinobase_block_T obj_h;/* '<S2>/Digital Output2' */
  codertarget_arduinobase_block_T obj_jb;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_block_T obj_m;/* '<Root>/Digital Output2' */
  codertarget_arduinobase_block_T obj_ii;/* '<Root>/Digital Output3' */
  real_T Filter_DSTATE;                /* '<S31>/Filter' */
  real_T Integrator_DSTATE;            /* '<S36>/Integrator' */
  real_T Filter_PREV_U;                /* '<S31>/Filter' */
  real_T Integrator_PREV_U;            /* '<S36>/Integrator' */
  int32_T clockTickCounter;            /* '<S2>/Pulse Generator2' */
  int32_T clockTickCounter_e;          /* '<S2>/Pulse Generator1' */
  uint32_T PID_PREV_T;                 /* '<S1>/PID' */
  uint8_T is_active_c3_sat_v4;         /* '<Root>/Chart' */
  uint8_T is_c3_sat_v4;                /* '<Root>/Chart' */
  uint8_T Filter_SYSTEM_ENABLE;        /* '<S31>/Filter' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S36>/Integrator' */
  boolean_T PID_RESET_ELAPS_T;         /* '<S1>/PID' */
} DW_sat_v4_T;

/* Parameters (default storage) */
struct P_sat_v4_T_ {
  real_T step_size;                    /* Variable: step_size
                                        * Referenced by:
                                        *   '<Root>/Digital Input'
                                        *   '<Root>/Digital Input1'
                                        *   '<Root>/Digital Input2'
                                        *   '<Root>/Digital Input3'
                                        *   '<Root>/Digital Input4'
                                        *   '<Root>/Digital Input5'
                                        */
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S30>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S33>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S31>/Filter'
                               */
  real_T PIDController_InitialConditio_b;
                              /* Mask Parameter: PIDController_InitialConditio_b
                               * Referenced by: '<S36>/Integrator'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S39>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S41>/Proportional Gain'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  real_T AnalogInput2_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input2'
                                        */
  real_T servo_action_Y0;              /* Computed Parameter: servo_action_Y0
                                        * Referenced by: '<S3>/servo_action'
                                        */
  real_T error_Y0;                     /* Computed Parameter: error_Y0
                                        * Referenced by: '<S3>/error'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S31>/Filter'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S36>/Integrator'
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
};

/* Real-time Model Data Structure */
struct tag_RTM_sat_v4_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block parameters (default storage) */
extern P_sat_v4_T sat_v4_P;

/* Block signals (default storage) */
extern B_sat_v4_T sat_v4_B;

/* Block states (default storage) */
extern DW_sat_v4_T sat_v4_DW;

/* Model entry point functions */
extern void sat_v4_initialize(void);
extern void sat_v4_step(void);
extern void sat_v4_terminate(void);

/* Real-time Model object */
extern RT_MODEL_sat_v4_T *const sat_v4_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
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
 * '<Root>' : 'sat_v4'
 * '<S1>'   : 'sat_v4/Chart'
 * '<S2>'   : 'sat_v4/Subsystem'
 * '<S3>'   : 'sat_v4/Chart/PID'
 * '<S4>'   : 'sat_v4/Chart/PID/PID Controller'
 * '<S5>'   : 'sat_v4/Chart/PID/PID Controller/Anti-windup'
 * '<S6>'   : 'sat_v4/Chart/PID/PID Controller/D Gain'
 * '<S7>'   : 'sat_v4/Chart/PID/PID Controller/Filter'
 * '<S8>'   : 'sat_v4/Chart/PID/PID Controller/Filter ICs'
 * '<S9>'   : 'sat_v4/Chart/PID/PID Controller/I Gain'
 * '<S10>'  : 'sat_v4/Chart/PID/PID Controller/Ideal P Gain'
 * '<S11>'  : 'sat_v4/Chart/PID/PID Controller/Ideal P Gain Fdbk'
 * '<S12>'  : 'sat_v4/Chart/PID/PID Controller/Integrator'
 * '<S13>'  : 'sat_v4/Chart/PID/PID Controller/Integrator ICs'
 * '<S14>'  : 'sat_v4/Chart/PID/PID Controller/N Copy'
 * '<S15>'  : 'sat_v4/Chart/PID/PID Controller/N Gain'
 * '<S16>'  : 'sat_v4/Chart/PID/PID Controller/P Copy'
 * '<S17>'  : 'sat_v4/Chart/PID/PID Controller/Parallel P Gain'
 * '<S18>'  : 'sat_v4/Chart/PID/PID Controller/Reset Signal'
 * '<S19>'  : 'sat_v4/Chart/PID/PID Controller/Saturation'
 * '<S20>'  : 'sat_v4/Chart/PID/PID Controller/Saturation Fdbk'
 * '<S21>'  : 'sat_v4/Chart/PID/PID Controller/Sum'
 * '<S22>'  : 'sat_v4/Chart/PID/PID Controller/Sum Fdbk'
 * '<S23>'  : 'sat_v4/Chart/PID/PID Controller/Tracking Mode'
 * '<S24>'  : 'sat_v4/Chart/PID/PID Controller/Tracking Mode Sum'
 * '<S25>'  : 'sat_v4/Chart/PID/PID Controller/Tsamp - Integral'
 * '<S26>'  : 'sat_v4/Chart/PID/PID Controller/Tsamp - Ngain'
 * '<S27>'  : 'sat_v4/Chart/PID/PID Controller/postSat Signal'
 * '<S28>'  : 'sat_v4/Chart/PID/PID Controller/preSat Signal'
 * '<S29>'  : 'sat_v4/Chart/PID/PID Controller/Anti-windup/Passthrough'
 * '<S30>'  : 'sat_v4/Chart/PID/PID Controller/D Gain/Internal Parameters'
 * '<S31>'  : 'sat_v4/Chart/PID/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S32>'  : 'sat_v4/Chart/PID/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S33>'  : 'sat_v4/Chart/PID/PID Controller/I Gain/Internal Parameters'
 * '<S34>'  : 'sat_v4/Chart/PID/PID Controller/Ideal P Gain/Passthrough'
 * '<S35>'  : 'sat_v4/Chart/PID/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S36>'  : 'sat_v4/Chart/PID/PID Controller/Integrator/Discrete'
 * '<S37>'  : 'sat_v4/Chart/PID/PID Controller/Integrator ICs/Internal IC'
 * '<S38>'  : 'sat_v4/Chart/PID/PID Controller/N Copy/Disabled'
 * '<S39>'  : 'sat_v4/Chart/PID/PID Controller/N Gain/Internal Parameters'
 * '<S40>'  : 'sat_v4/Chart/PID/PID Controller/P Copy/Disabled'
 * '<S41>'  : 'sat_v4/Chart/PID/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S42>'  : 'sat_v4/Chart/PID/PID Controller/Reset Signal/Disabled'
 * '<S43>'  : 'sat_v4/Chart/PID/PID Controller/Saturation/Passthrough'
 * '<S44>'  : 'sat_v4/Chart/PID/PID Controller/Saturation Fdbk/Disabled'
 * '<S45>'  : 'sat_v4/Chart/PID/PID Controller/Sum/Sum_PID'
 * '<S46>'  : 'sat_v4/Chart/PID/PID Controller/Sum Fdbk/Disabled'
 * '<S47>'  : 'sat_v4/Chart/PID/PID Controller/Tracking Mode/Disabled'
 * '<S48>'  : 'sat_v4/Chart/PID/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S49>'  : 'sat_v4/Chart/PID/PID Controller/Tsamp - Integral/Passthrough'
 * '<S50>'  : 'sat_v4/Chart/PID/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S51>'  : 'sat_v4/Chart/PID/PID Controller/postSat Signal/Forward_Path'
 * '<S52>'  : 'sat_v4/Chart/PID/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_sat_v4_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
