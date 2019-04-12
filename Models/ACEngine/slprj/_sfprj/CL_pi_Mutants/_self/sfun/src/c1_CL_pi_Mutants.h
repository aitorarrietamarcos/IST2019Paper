#ifndef __c1_CL_pi_Mutants_h__
#define __c1_CL_pi_Mutants_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_CL_pi_MutantsInstanceStruct
#define typedef_SFc1_CL_pi_MutantsInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_CL_pi_Mutants;
  real_T (*c1_test_order)[6];
  real_T (*c1_tc_size)[120];
  real_T (*c1_trans1)[960];
  real_T (*c1_trans2)[960];
  real_T (*c1_trans3)[960];
  real_T (*c1_trans4)[960];
  real_T *c1_v_engine;
  real_T *c1_temp;
  real_T *c1_test_order_id;
  real_T *c1_state_id;
  real_T *c1_test_case;
  real_T *c1_state;
  real_T *c1_test_order_id1;
  real_T *c1_state_id1;
  boolean_T *c1_simulation_stop;
} SFc1_CL_pi_MutantsInstanceStruct;

#endif                                 /*typedef_SFc1_CL_pi_MutantsInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_CL_pi_Mutants_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_CL_pi_Mutants_get_check_sum(mxArray *plhs[]);
extern void c1_CL_pi_Mutants_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
