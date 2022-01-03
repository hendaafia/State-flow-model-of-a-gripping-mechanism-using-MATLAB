/*
 * File: sat_v4_data.c
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

/* Block parameters (default storage) */
P_sat_v4_T sat_v4_P = {
  /* Variable: step_size
   * Referenced by:
   *   '<Root>/Digital Input'
   *   '<Root>/Digital Input1'
   *   '<Root>/Digital Input2'
   *   '<Root>/Digital Input3'
   *   '<Root>/Digital Input4'
   *   '<Root>/Digital Input5'
   */
  0.01,

  /* Mask Parameter: PIDController_D
   * Referenced by: '<S30>/Derivative Gain'
   */
  0.005,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S33>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S31>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_b
   * Referenced by: '<S36>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S39>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S41>/Proportional Gain'
   */
  0.001,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input2'
   */
  -1.0,

  /* Computed Parameter: servo_action_Y0
   * Referenced by: '<S3>/servo_action'
   */
  0.0,

  /* Computed Parameter: error_Y0
   * Referenced by: '<S3>/error'
   */
  0.0,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S31>/Filter'
   */
  0.01,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S36>/Integrator'
   */
  0.01,

  /* Expression: 1
   * Referenced by: '<S2>/Pulse Generator2'
   */
  1.0,

  /* Computed Parameter: PulseGenerator2_Period
   * Referenced by: '<S2>/Pulse Generator2'
   */
  2.0,

  /* Computed Parameter: PulseGenerator2_Duty
   * Referenced by: '<S2>/Pulse Generator2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Pulse Generator2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Pulse Generator1'
   */
  1.0,

  /* Computed Parameter: PulseGenerator1_Period
   * Referenced by: '<S2>/Pulse Generator1'
   */
  2.0,

  /* Computed Parameter: PulseGenerator1_Duty
   * Referenced by: '<S2>/Pulse Generator1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Pulse Generator1'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
