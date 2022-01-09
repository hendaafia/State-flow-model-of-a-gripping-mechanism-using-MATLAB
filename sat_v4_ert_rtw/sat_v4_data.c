/*
 * File: sat_v4_data.c
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
   *   '<Root>/Digital Input6'
   *   '<Root>/Digital Input7'
   *   '<Root>/Digital Input8'
   *   '<Root>/Digital Input9'
   */
  0.001,

  /* Mask Parameter: PIDController_D
   * Referenced by: '<S32>/Derivative Gain'
   */
  0.005,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S35>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S33>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_b
   * Referenced by: '<S38>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S41>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S43>/Proportional Gain'
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
   * Referenced by: '<S5>/servo_action'
   */
  0.0,

  /* Computed Parameter: error_Y0
   * Referenced by: '<S5>/error'
   */
  0.0,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S33>/Filter'
   */
  0.0005,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S38>/Integrator'
   */
  0.0005,

  /* Expression: 0
   * Referenced by: '<S2>/Zero'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S2>/Transfer Fcn'
   */
  -0.00015915494309189535,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S2>/Transfer Fcn'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S2>/Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/One'
   */
  1.0,

  /* Expression: 2*10^-4
   * Referenced by: '<S2>/Switch'
   */
  0.0002,

  /* Expression: 0
   * Referenced by: '<S3>/Zero'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A_m
   * Referenced by: '<S3>/Transfer Fcn'
   */
  -0.00015915494309189535,

  /* Computed Parameter: TransferFcn_C_g
   * Referenced by: '<S3>/Transfer Fcn'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S3>/Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/One'
   */
  1.0,

  /* Expression: 2*10^-4
   * Referenced by: '<S3>/Switch'
   */
  0.0002,

  /* Expression: 1
   * Referenced by: '<S4>/Pulse Generator2'
   */
  1.0,

  /* Computed Parameter: PulseGenerator2_Period
   * Referenced by: '<S4>/Pulse Generator2'
   */
  2.0,

  /* Computed Parameter: PulseGenerator2_Duty
   * Referenced by: '<S4>/Pulse Generator2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Pulse Generator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: synthesized block
   */
  0.0,

  /* Expression: 0
   * Referenced by: synthesized block
   */
  0.0,

  /* Expression: 0
   * Referenced by: synthesized block
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S4>/Pulse Generator1'
   */
  1.0,

  /* Computed Parameter: PulseGenerator1_Period
   * Referenced by: '<S4>/Pulse Generator1'
   */
  2.0,

  /* Computed Parameter: PulseGenerator1_Duty
   * Referenced by: '<S4>/Pulse Generator1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Pulse Generator1'
   */
  0.0,

  /* Computed Parameter: TmpRTBAtChartInport4_InitialCon
   * Referenced by: synthesized block
   */
  0,

  /* Computed Parameter: TmpRTBAtChartInport5_InitialCon
   * Referenced by: synthesized block
   */
  0,

  /* Computed Parameter: TmpRTBAtChartInport6_InitialCon
   * Referenced by: synthesized block
   */
  0,

  /* Computed Parameter: ONOFF_InitialCondition
   * Referenced by: synthesized block
   */
  0,

  /* Computed Parameter: TmpRTBAtChartInport9_InitialCon
   * Referenced by: synthesized block
   */
  0,

  /* Computed Parameter: TmpRTBAtChartInport10_InitialCo
   * Referenced by: synthesized block
   */
  0,

  /* Computed Parameter: TmpRTBAtChartInport11_InitialCo
   * Referenced by: synthesized block
   */
  0,

  /* Computed Parameter: TmpRTBAtChartInport12_InitialCo
   * Referenced by: synthesized block
   */
  0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
