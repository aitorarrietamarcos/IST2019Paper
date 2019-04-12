#ifndef __c3_CL_pi_testExecution_h__
#define __c3_CL_pi_testExecution_h__

/* Type Definitions */
#ifndef typedef_SFc3_CL_pi_testExecutionInstanceStruct
#define typedef_SFc3_CL_pi_testExecutionInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_CL_pi_testExecution;
  void *c3_fEmlrtCtx;
  real_T (*c3_tc_simul)[3840];
  real_T *c3_port_1;
  real_T *c3_test_case;
  real_T *c3_state;
  real_T *c3_port_2;
  real_T *c3_port_3;
  real_T *c3_port_4;
} SFc3_CL_pi_testExecutionInstanceStruct;

#endif                                 /*typedef_SFc3_CL_pi_testExecutionInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_CL_pi_testExecution_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c3_CL_pi_testExecution_get_check_sum(mxArray *plhs[]);
extern void c3_CL_pi_testExecution_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
