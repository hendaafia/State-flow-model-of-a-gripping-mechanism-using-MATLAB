/*
 * File: sat_v4.h
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

#ifndef RTW_HEADER_sat_v4_h_
#define RTW_HEADER_sat_v4_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef sat_v4_COMMON_INCLUDES_
# define sat_v4_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#include "MW_ServoWriteRead.h"
#include "MW_AnalogIn.h"
#endif                                 /* sat_v4_COMMON_INCLUDES_ */

#include "sat_v4_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T TransferFcn;                  /* '<S2>/Transfer Fcn' */
  real_T Delay;                        /* '<S2>/Delay' */
  real_T TransferFcn_m;                /* '<S3>/Transfer Fcn' */
  real_T Delay_g;                      /* '<S3>/Delay' */
  real_T TmpRTBAtProduct3Inport2;      /* '<S4>/Pulse Generator1' */
  real_T TmpRTBAtTransferFcnInport1;   /* '<S2>/Data Type Conversion' */
  real_T TmpRTBAtTransferFcnInport1_n; /* '<S3>/Data Type Conversion' */
  real_T pot_status;                   /* '<Root>/Chart' */
  real_T steppON;                      /* '<Root>/Chart' */
  real_T direction;                    /* '<Root>/Chart' */
  real_T Gripper_LED;                  /* '<Root>/Chart' */
  real_T servo;                        /* '<Root>/Chart' */
  real_T BW_LED;                       /* '<Root>/Chart' */
  real_T FW_LED;                       /* '<Root>/Chart' */
  boolean_T TmpRTBAtChartInport4;      /* '<Root>/G_SW' */
  boolean_T TmpRTBAtChartInport5;      /* '<Root>/Bw' */
  boolean_T TmpRTBAtChartInport6;      /* '<Root>/FW' */
  boolean_T ONOFF;                     /* '<Root>/Digital Input5' */
  boolean_T TmpRTBAtChartInport9;      /* '<Root>/Digital Input6' */
  boolean_T TmpRTBAtChartInport10;     /* '<Root>/Digital Input7' */
  boolean_T TmpRTBAtChartInport11;     /* '<Root>/Digital Input8' */
  boolean_T TmpRTBAtChartInport12;     /* '<Root>/Digital Input9' */
} B_sat_v4_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input2' */
  codertarget_arduinobase_inter_T obj_p;/* '<Root>/Analog Input1' */
  codertarget_arduinobase_block_T obj_i;/* '<Root>/Digital Input3' */
  codertarget_arduinobase_block_T obj_j;/* '<Root>/Digital Input' */
  codertarget_arduinobase_block_T obj_b;/* '<Root>/Digital Input1' */
  codertarget_arduinobase_block_T obj_l;/* '<Root>/Digital Input2' */
  codertarget_arduinobase_block_T obj_ix;/* '<Root>/Digital Input4' */
  codertarget_arduinobase_block_T obj_n;/* '<Root>/Digital Input5' */
  codertarget_arduinobase_block_T obj_g;/* '<Root>/Digital Input6' */
  codertarget_arduinobase_block_T obj_ni;/* '<Root>/Digital Input7' */
  codertarget_arduinobase_block_T obj_f;/* '<Root>/Digital Input8' */
  codertarget_arduinobase_block_T obj_lm;/* '<Root>/Digital Input9' */
  codertarget_arduinobase_int_k_T obj_l5;/* '<Root>/Standard Servo Write1' */
  i_codertarget_arduinobase_int_T gobj_1;/* '<Root>/Standard Servo Write1' */
  i_codertarget_arduinobase_int_T gobj_2;/* '<Root>/Standard Servo Write1' */
  i_codertarget_arduinobase_int_T gobj_3;/* '<Root>/Standard Servo Write1' */
  i_codertarget_arduinobase_int_T gobj_4;/* '<Root>/Standard Servo Write1' */
  codertarget_arduinobase_blo_k_T obj_bu;/* '<S4>/Digital Output3' */
  codertarget_arduinobase_blo_k_T obj_h;/* '<S4>/Digital Output2' */
  codertarget_arduinobase_blo_k_T obj_jb;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_blo_k_T obj_m;/* '<Root>/Digital Output2' */
  codertarget_arduinobase_blo_k_T obj_ii;/* '<Root>/Digital Output3' */
  real_T Delay_DSTATE[10];             /* '<S2>/Delay' */
  real_T Delay_DSTATE_l[10];           /* '<S3>/Delay' */
  real_T Filter_DSTATE;                /* '<S33>/Filter' */
  real_T Integrator_DSTATE;            /* '<S38>/Integrator' */
  real_T TmpRTBAtProduct3Inport2_Buffer0;/* synthesized block */
  real_T TmpRTBAtTransferFcnInport1_Buff;/* synthesized block */
  real_T TmpRTBAtTransferFcnInport1_Bu_d;/* synthesized block */
  real_T Filter_PREV_U;                /* '<S33>/Filter' */
  real_T Integrator_PREV_U;            /* '<S38>/Integrator' */
  int32_T clockTickCounter;            /* '<S4>/Pulse Generator2' */
  int32_T clockTickCounter_e;          /* '<S4>/Pulse Generator1' */
  uint32_T PID_PREV_T;                 /* '<S1>/PID' */
  uint8_T is_active_c3_sat_v4;         /* '<Root>/Chart' */
  uint8_T is_c3_sat_v4;                /* '<Root>/Chart' */
  uint8_T Filter_SYSTEM_ENABLE;        /* '<S33>/Filter' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S38>/Integrator' */
  boolean_T TmpRTBAtChartInport4_Buffer0;/* synthesized block */
  boolean_T TmpRTBAtChartInport5_Buffer0;/* synthesized block */
  boolean_T TmpRTBAtChartInport6_Buffer0;/* synthesized block */
  boolean_T ONOFF_Buffer0;             /* synthesized block */
  boolean_T TmpRTBAtChartInport9_Buffer0;/* synthesized block */
  boolean_T TmpRTBAtChartInport10_Buffer0;/* synthesized block */
  boolean_T TmpRTBAtChartInport11_Buffer0;/* synthesized block */
  boolean_T TmpRTBAtChartInport12_Buffer0;/* synthesized block */
  boolean_T PID_RESET_ELAPS_T;         /* '<S1>/PID' */
} DW_sat_v4_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S2>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_p;         /* '<S3>/Transfer Fcn' */
} X_sat_v4_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S2>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_p;         /* '<S3>/Transfer Fcn' */
} XDot_sat_v4_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn_CSTATE;        /* '<S2>/Transfer Fcn' */
  boolean_T TransferFcn_CSTATE_p;      /* '<S3>/Transfer Fcn' */
} XDis_sat_v4_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

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
                                        *   '<Root>/Digital Input6'
                                        *   '<Root>/Digital Input7'
                                        *   '<Root>/Digital Input8'
                                        *   '<Root>/Digital Input9'
                                        */
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S32>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S35>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S33>/Filter'
                               */
  real_T PIDController_InitialConditio_b;
                              /* Mask Parameter: PIDController_InitialConditio_b
                               * Referenced by: '<S38>/Integrator'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S41>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S43>/Proportional Gain'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  real_T AnalogInput2_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input2'
                                        */
  real_T servo_action_Y0;              /* Computed Parameter: servo_action_Y0
                                        * Referenced by: '<S5>/servo_action'
                                        */
  real_T error_Y0;                     /* Computed Parameter: error_Y0
                                        * Referenced by: '<S5>/error'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S33>/Filter'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S38>/Integrator'
                                        */
  real_T Zero_Value;                   /* Expression: 0
                                        * Referenced by: '<S2>/Zero'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S2>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S2>/Transfer Fcn'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S2>/Delay'
                                        */
  real_T One_Value;                    /* Expression: 1
                                        * Referenced by: '<S2>/One'
                                        */
  real_T Switch_Threshold;             /* Expression: 2*10^-4
                                        * Referenced by: '<S2>/Switch'
                                        */
  real_T Zero_Value_b;                 /* Expression: 0
                                        * Referenced by: '<S3>/Zero'
                                        */
  real_T TransferFcn_A_m;              /* Computed Parameter: TransferFcn_A_m
                                        * Referenced by: '<S3>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_g;              /* Computed Parameter: TransferFcn_C_g
                                        * Referenced by: '<S3>/Transfer Fcn'
                                        */
  real_T Delay_InitialCondition_a;     /* Expression: 0.0
                                        * Referenced by: '<S3>/Delay'
                                        */
  real_T One_Value_b;                  /* Expression: 1
                                        * Referenced by: '<S3>/One'
                                        */
  real_T Switch_Threshold_b;           /* Expression: 2*10^-4
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T PulseGenerator2_Amp;          /* Expression: 1
                                        * Referenced by: '<S4>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_Period;   /* Computed Parameter: PulseGenerator2_Period
                                    * Referenced by: '<S4>/Pulse Generator2'
                                    */
  real_T PulseGenerator2_Duty;       /* Computed Parameter: PulseGenerator2_Duty
                                      * Referenced by: '<S4>/Pulse Generator2'
                                      */
  real_T PulseGenerator2_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S4>/Pulse Generator2'
                                        */
  real_T TmpRTBAtProduct3Inport2_Initial;/* Expression: 0
                                          * Referenced by: synthesized block
                                          */
  real_T TmpRTBAtTransferFcnInport1_Init;/* Expression: 0
                                          * Referenced by: synthesized block
                                          */
  real_T TmpRTBAtTransferFcnInport1_In_j;/* Expression: 0
                                          * Referenced by: synthesized block
                                          */
  real_T PulseGenerator1_Amp;          /* Expression: 1
                                        * Referenced by: '<S4>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;   /* Computed Parameter: PulseGenerator1_Period
                                    * Referenced by: '<S4>/Pulse Generator1'
                                    */
  real_T PulseGenerator1_Duty;       /* Computed Parameter: PulseGenerator1_Duty
                                      * Referenced by: '<S4>/Pulse Generator1'
                                      */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S4>/Pulse Generator1'
                                        */
  boolean_T TmpRTBAtChartInport4_InitialCon;
                          /* Computed Parameter: TmpRTBAtChartInport4_InitialCon
                           * Referenced by: synthesized block
                           */
  boolean_T TmpRTBAtChartInport5_InitialCon;
                          /* Computed Parameter: TmpRTBAtChartInport5_InitialCon
                           * Referenced by: synthesized block
                           */
  boolean_T TmpRTBAtChartInport6_InitialCon;
                          /* Computed Parameter: TmpRTBAtChartInport6_InitialCon
                           * Referenced by: synthesized block
                           */
  boolean_T ONOFF_InitialCondition;/* Computed Parameter: ONOFF_InitialCondition
                                    * Referenced by: synthesized block
                                    */
  boolean_T TmpRTBAtChartInport9_InitialCon;
                          /* Computed Parameter: TmpRTBAtChartInport9_InitialCon
                           * Referenced by: synthesized block
                           */
  boolean_T TmpRTBAtChartInport10_InitialCo;
                          /* Computed Parameter: TmpRTBAtChartInport10_InitialCo
                           * Referenced by: synthesized block
                           */
  boolean_T TmpRTBAtChartInport11_InitialCo;
                          /* Computed Parameter: TmpRTBAtChartInport11_InitialCo
                           * Referenced by: synthesized block
                           */
  boolean_T TmpRTBAtChartInport12_InitialCo;
                          /* Computed Parameter: TmpRTBAtChartInport12_InitialCo
                           * Referenced by: synthesized block
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_sat_v4_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_sat_v4_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[4];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
      boolean_T TID1_3;
    } RateInteraction;

    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[4];
  } Timing;
};

/* Block parameters (default storage) */
extern P_sat_v4_T sat_v4_P;

/* Block signals (default storage) */
extern B_sat_v4_T sat_v4_B;

/* Continuous states (default storage) */
extern X_sat_v4_T sat_v4_X;

/* Block states (default storage) */
extern DW_sat_v4_T sat_v4_DW;

/* External function called from main */
extern void sat_v4_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void sat_v4_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void sat_v4_initialize(void);
extern void sat_v4_step0(void);
extern void sat_v4_step2(void);
extern void sat_v4_step3(void);
extern void sat_v4_terminate(void);

/* Real-time Model object */
extern RT_MODEL_sat_v4_T *const sat_v4_M;

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
 * '<S2>'   : 'sat_v4/LPF1'
 * '<S3>'   : 'sat_v4/LPF2'
 * '<S4>'   : 'sat_v4/Subsystem'
 * '<S5>'   : 'sat_v4/Chart/PID'
 * '<S6>'   : 'sat_v4/Chart/PID/PID Controller'
 * '<S7>'   : 'sat_v4/Chart/PID/PID Controller/Anti-windup'
 * '<S8>'   : 'sat_v4/Chart/PID/PID Controller/D Gain'
 * '<S9>'   : 'sat_v4/Chart/PID/PID Controller/Filter'
 * '<S10>'  : 'sat_v4/Chart/PID/PID Controller/Filter ICs'
 * '<S11>'  : 'sat_v4/Chart/PID/PID Controller/I Gain'
 * '<S12>'  : 'sat_v4/Chart/PID/PID Controller/Ideal P Gain'
 * '<S13>'  : 'sat_v4/Chart/PID/PID Controller/Ideal P Gain Fdbk'
 * '<S14>'  : 'sat_v4/Chart/PID/PID Controller/Integrator'
 * '<S15>'  : 'sat_v4/Chart/PID/PID Controller/Integrator ICs'
 * '<S16>'  : 'sat_v4/Chart/PID/PID Controller/N Copy'
 * '<S17>'  : 'sat_v4/Chart/PID/PID Controller/N Gain'
 * '<S18>'  : 'sat_v4/Chart/PID/PID Controller/P Copy'
 * '<S19>'  : 'sat_v4/Chart/PID/PID Controller/Parallel P Gain'
 * '<S20>'  : 'sat_v4/Chart/PID/PID Controller/Reset Signal'
 * '<S21>'  : 'sat_v4/Chart/PID/PID Controller/Saturation'
 * '<S22>'  : 'sat_v4/Chart/PID/PID Controller/Saturation Fdbk'
 * '<S23>'  : 'sat_v4/Chart/PID/PID Controller/Sum'
 * '<S24>'  : 'sat_v4/Chart/PID/PID Controller/Sum Fdbk'
 * '<S25>'  : 'sat_v4/Chart/PID/PID Controller/Tracking Mode'
 * '<S26>'  : 'sat_v4/Chart/PID/PID Controller/Tracking Mode Sum'
 * '<S27>'  : 'sat_v4/Chart/PID/PID Controller/Tsamp - Integral'
 * '<S28>'  : 'sat_v4/Chart/PID/PID Controller/Tsamp - Ngain'
 * '<S29>'  : 'sat_v4/Chart/PID/PID Controller/postSat Signal'
 * '<S30>'  : 'sat_v4/Chart/PID/PID Controller/preSat Signal'
 * '<S31>'  : 'sat_v4/Chart/PID/PID Controller/Anti-windup/Passthrough'
 * '<S32>'  : 'sat_v4/Chart/PID/PID Controller/D Gain/Internal Parameters'
 * '<S33>'  : 'sat_v4/Chart/PID/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S34>'  : 'sat_v4/Chart/PID/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S35>'  : 'sat_v4/Chart/PID/PID Controller/I Gain/Internal Parameters'
 * '<S36>'  : 'sat_v4/Chart/PID/PID Controller/Ideal P Gain/Passthrough'
 * '<S37>'  : 'sat_v4/Chart/PID/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S38>'  : 'sat_v4/Chart/PID/PID Controller/Integrator/Discrete'
 * '<S39>'  : 'sat_v4/Chart/PID/PID Controller/Integrator ICs/Internal IC'
 * '<S40>'  : 'sat_v4/Chart/PID/PID Controller/N Copy/Disabled'
 * '<S41>'  : 'sat_v4/Chart/PID/PID Controller/N Gain/Internal Parameters'
 * '<S42>'  : 'sat_v4/Chart/PID/PID Controller/P Copy/Disabled'
 * '<S43>'  : 'sat_v4/Chart/PID/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S44>'  : 'sat_v4/Chart/PID/PID Controller/Reset Signal/Disabled'
 * '<S45>'  : 'sat_v4/Chart/PID/PID Controller/Saturation/Passthrough'
 * '<S46>'  : 'sat_v4/Chart/PID/PID Controller/Saturation Fdbk/Disabled'
 * '<S47>'  : 'sat_v4/Chart/PID/PID Controller/Sum/Sum_PID'
 * '<S48>'  : 'sat_v4/Chart/PID/PID Controller/Sum Fdbk/Disabled'
 * '<S49>'  : 'sat_v4/Chart/PID/PID Controller/Tracking Mode/Disabled'
 * '<S50>'  : 'sat_v4/Chart/PID/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S51>'  : 'sat_v4/Chart/PID/PID Controller/Tsamp - Integral/Passthrough'
 * '<S52>'  : 'sat_v4/Chart/PID/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S53>'  : 'sat_v4/Chart/PID/PID Controller/postSat Signal/Forward_Path'
 * '<S54>'  : 'sat_v4/Chart/PID/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_sat_v4_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
