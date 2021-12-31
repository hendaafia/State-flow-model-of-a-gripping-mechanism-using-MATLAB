/*
 * File: Project_data.c
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

/* Block parameters (default storage) */
P_Project_T Project_P = {
  /* Variable: step_size
   * Referenced by:
   *   '<Root>/Digital Input'
   *   '<Root>/Digital Input1'
   *   '<Root>/Digital Input2'
   *   '<Root>/Digital Input3'
   *   '<Root>/Digital Input4'
   *   '<Root>/Digital Input5'
   */
  0.05,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S41>/Proportional Gain'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input'
   */
  -1.0,

  /* Computed Parameter: servo_action_Y0
   * Referenced by: '<S3>/servo_action'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

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
  0.0,

  /* Expression: 50
   * Referenced by: '<Root>/Constant1'
   */
  50.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
