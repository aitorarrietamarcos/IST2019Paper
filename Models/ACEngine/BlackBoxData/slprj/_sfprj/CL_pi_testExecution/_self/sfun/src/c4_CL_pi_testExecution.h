#ifndef __c4_CL_pi_testExecution_h__
#define __c4_CL_pi_testExecution_h__

/* Type Definitions */
#ifndef typedef_SFc4_CL_pi_testExecutionInstanceStruct
#define typedef_SFc4_CL_pi_testExecutionInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_CL_pi_testExecution;
  void *c4_fEmlrtCtx;
  real_T *c4_test_order;
  real_T (*c4_tc_size)[120];
  real_T (*c4_trans1)[960];
  real_T (*c4_trans2)[960];
  real_T (*c4_trans3)[960];
  real_T (*c4_trans4)[960];
  real_T *c4_v_engine;
  real_T *c4_temp;
  real_T *c4_test_order_id;
  real_T *c4_state_id;
  real_T *c4_test_case;
  real_T *c4_state;
  real_T *c4_test_order_id1;
  real_T *c4_state_id1;
  boolean_T *c4_simulation_stop;
} SFc4_CL_pi_testExecutionInstanceStruct;

#endif                                 /*typedef_SFc4_CL_pi_testExecutionInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_CL_pi_testExecution_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c4_CL_pi_testExecution_get_check_sum(mxArray *plhs[]);
extern void c4_CL_pi_testExecution_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
