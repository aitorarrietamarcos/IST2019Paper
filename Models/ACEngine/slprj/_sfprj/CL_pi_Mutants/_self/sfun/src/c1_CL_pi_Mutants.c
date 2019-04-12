/* Include files */

#include "CL_pi_Mutants_sfun.h"
#include "c1_CL_pi_Mutants.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CL_pi_Mutants_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[18] = { "num_signals", "nargin",
  "nargout", "test_order", "tc_size", "trans1", "trans2", "trans3", "trans4",
  "v_engine", "temp", "test_order_id", "state_id", "test_case", "state",
  "test_order_id1", "state_id1", "simulation_stop" };

/* Function Declarations */
static void initialize_c1_CL_pi_Mutants(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance);
static void initialize_params_c1_CL_pi_Mutants(SFc1_CL_pi_MutantsInstanceStruct *
  chartInstance);
static void enable_c1_CL_pi_Mutants(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance);
static void disable_c1_CL_pi_Mutants(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_CL_pi_Mutants
  (SFc1_CL_pi_MutantsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_CL_pi_Mutants
  (SFc1_CL_pi_MutantsInstanceStruct *chartInstance);
static void set_sim_state_c1_CL_pi_Mutants(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_CL_pi_Mutants(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance);
static void sf_gateway_c1_CL_pi_Mutants(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance);
static void mdl_start_c1_CL_pi_Mutants(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance);
static void initSimStructsc1_CL_pi_Mutants(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static boolean_T c1_emlrt_marshallIn(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance, const mxArray *c1_b_simulation_stop, const char_T
  *c1_identifier);
static boolean_T c1_b_emlrt_marshallIn(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance, const mxArray *c1_b_state_id1, const char_T *c1_identifier);
static real_T c1_d_emlrt_marshallIn(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_e_emlrt_marshallIn(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_f_emlrt_marshallIn(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_CL_pi_Mutants, const char_T
  *c1_identifier);
static uint8_T c1_g_emlrt_marshallIn(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_CL_pi_Mutants(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc1_CL_pi_Mutants(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_CL_pi_Mutants = 0U;
}

static void initialize_params_c1_CL_pi_Mutants(SFc1_CL_pi_MutantsInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_CL_pi_Mutants(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_CL_pi_Mutants(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_CL_pi_Mutants
  (SFc1_CL_pi_MutantsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_CL_pi_Mutants
  (SFc1_CL_pi_MutantsInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  boolean_T c1_hoistedGlobal;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_hoistedGlobal;
  const mxArray *c1_d_y = NULL;
  real_T c1_d_hoistedGlobal;
  const mxArray *c1_e_y = NULL;
  real_T c1_e_hoistedGlobal;
  const mxArray *c1_f_y = NULL;
  uint8_T c1_f_hoistedGlobal;
  const mxArray *c1_g_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(6, 1), false);
  c1_hoistedGlobal = *chartInstance->c1_simulation_stop;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_hoistedGlobal, 11, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *chartInstance->c1_state;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *chartInstance->c1_state_id1;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = *chartInstance->c1_test_case;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = *chartInstance->c1_test_order_id1;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = chartInstance->c1_is_active_c1_CL_pi_Mutants;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_CL_pi_Mutants(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  *chartInstance->c1_simulation_stop = c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("simulation_stop", c1_u, 0)), "simulation_stop");
  *chartInstance->c1_state = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("state", c1_u, 1)), "state");
  *chartInstance->c1_state_id1 = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("state_id1", c1_u, 2)), "state_id1");
  *chartInstance->c1_test_case = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("test_case", c1_u, 3)), "test_case");
  *chartInstance->c1_test_order_id1 = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("test_order_id1", c1_u, 4)), "test_order_id1");
  chartInstance->c1_is_active_c1_CL_pi_Mutants = c1_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c1_CL_pi_Mutants", c1_u,
       5)), "is_active_c1_CL_pi_Mutants");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_CL_pi_Mutants(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_CL_pi_Mutants(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_CL_pi_Mutants(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance)
{
  int32_T c1_i0;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_hoistedGlobal;
  int32_T c1_i6;
  int32_T c1_i7;
  real_T c1_b_test_order[6];
  int32_T c1_i8;
  real_T c1_b_tc_size[120];
  int32_T c1_i9;
  real_T c1_b_trans1[960];
  int32_T c1_i10;
  real_T c1_b_trans2[960];
  int32_T c1_i11;
  real_T c1_b_trans3[960];
  real_T c1_b_v_engine;
  real_T c1_b_trans4[960];
  real_T c1_b_temp;
  real_T c1_b_test_order_id;
  real_T c1_b_state_id;
  uint32_T c1_debug_family_var_map[18];
  real_T c1_num_signals;
  real_T c1_nargin = 10.0;
  real_T c1_nargout = 5.0;
  real_T c1_b_test_case;
  real_T c1_b_state;
  real_T c1_b_test_order_id1;
  real_T c1_b_state_id1;
  boolean_T c1_b_simulation_stop;
  real_T c1_d0;
  real_T c1_d1;
  real_T c1_A;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_d2;
  boolean_T guard1 = false;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_state_id, 9U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_test_order_id, 8U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_temp, 7U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_v_engine, 6U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
  for (c1_i0 = 0; c1_i0 < 960; c1_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_trans4)[c1_i0], 5U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }

  for (c1_i1 = 0; c1_i1 < 960; c1_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_trans3)[c1_i1], 4U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }

  for (c1_i2 = 0; c1_i2 < 960; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_trans2)[c1_i2], 3U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }

  for (c1_i3 = 0; c1_i3 < 960; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_trans1)[c1_i3], 2U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }

  for (c1_i4 = 0; c1_i4 < 120; c1_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_tc_size)[c1_i4], 1U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }

  for (c1_i5 = 0; c1_i5 < 6; c1_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_test_order)[c1_i5], 0U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *chartInstance->c1_v_engine;
  c1_b_hoistedGlobal = *chartInstance->c1_temp;
  c1_c_hoistedGlobal = *chartInstance->c1_test_order_id;
  c1_d_hoistedGlobal = *chartInstance->c1_state_id;
  for (c1_i6 = 0; c1_i6 < 6; c1_i6++) {
    c1_b_test_order[c1_i6] = (*chartInstance->c1_test_order)[c1_i6];
  }

  for (c1_i7 = 0; c1_i7 < 120; c1_i7++) {
    c1_b_tc_size[c1_i7] = (*chartInstance->c1_tc_size)[c1_i7];
  }

  for (c1_i8 = 0; c1_i8 < 960; c1_i8++) {
    c1_b_trans1[c1_i8] = (*chartInstance->c1_trans1)[c1_i8];
  }

  for (c1_i9 = 0; c1_i9 < 960; c1_i9++) {
    c1_b_trans2[c1_i9] = (*chartInstance->c1_trans2)[c1_i9];
  }

  for (c1_i10 = 0; c1_i10 < 960; c1_i10++) {
    c1_b_trans3[c1_i10] = (*chartInstance->c1_trans3)[c1_i10];
  }

  for (c1_i11 = 0; c1_i11 < 960; c1_i11++) {
    c1_b_trans4[c1_i11] = (*chartInstance->c1_trans4)[c1_i11];
  }

  c1_b_v_engine = c1_hoistedGlobal;
  c1_b_temp = c1_b_hoistedGlobal;
  c1_b_test_order_id = c1_c_hoistedGlobal;
  c1_b_state_id = c1_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_num_signals, 0U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_test_order, 3U, c1_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_tc_size, 4U, c1_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_trans1, 5U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_trans2, 6U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_trans3, 7U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_trans4, 8U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_v_engine, 9U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_temp, 10U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_test_order_id, 11U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_state_id, 12U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_test_case, 13U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_state, 14U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_test_order_id1, 15U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_state_id1, 16U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_simulation_stop, 17U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_num_signals = 4.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_b_test_case = c1_b_test_order[sf_eml_array_bounds_check
    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 215, 25, MAX_uint32_T,
     (int32_T)sf_integer_check(chartInstance->S, 1U, 215U, 25U,
      c1_b_test_order_id), 1, 6) - 1];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_b_test_order_id1 = c1_b_test_order_id;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  c1_b_state = c1_b_state_id;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_b_state_id1 = c1_b_state;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_b_simulation_stop = false;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  c1_d0 = c1_b_trans1[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 382, 9, MAX_uint32_T, (int32_T)sf_integer_check
    (chartInstance->S, 1U, 382U, 9U, c1_b_test_case), 1, 120) + 120 *
                       (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 392, 8, MAX_uint32_T, (int32_T)sf_integer_check
    (chartInstance->S, 1U, 392U, 8U, c1_b_state_id), 1, 8) - 1)) - 1];
  guard1 = false;
  if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c1_b_v_engine, c1_d0,
        -1, 4U, c1_b_v_engine > c1_d0))) {
    c1_d1 = c1_b_trans2[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 423, 9, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 423U, 9U, c1_b_test_case), 1, 120) + 120 *
                         (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 433, 8, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 433U, 8U, c1_b_state_id), 1, 8) - 1)) - 1];
    if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c1_b_v_engine, c1_d1,
          -1, 2U, c1_b_v_engine < c1_d1))) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 0, true);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
      c1_A = c1_b_tc_size[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 517, 18, MAX_uint32_T, (int32_T)sf_integer_check
        (chartInstance->S, 1U, 517U, 18U, c1_b_test_case), 1, 120) - 1];
      c1_x = c1_A;
      c1_b_x = c1_x;
      c1_d2 = c1_b_x / 4.0;
      if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 2, c1_b_state_id, c1_d2,
            -1, 2U, c1_b_state_id < c1_d2))) {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
        c1_b_state = c1_b_state_id + 1.0;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
        c1_b_state_id1 = c1_b_state;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
        if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 3, c1_b_test_order_id1,
              6.0, -1, 2U, c1_b_test_order_id1 < 6.0))) {
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
          c1_b_state = 1.0;
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
          c1_b_state_id1 = c1_b_state;
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
          c1_b_test_order_id1 = c1_b_test_order_id + 1.0;
        } else {
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
          c1_b_simulation_stop = true;
        }
      }
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 0, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -21);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c1_test_case = c1_b_test_case;
  *chartInstance->c1_state = c1_b_state;
  *chartInstance->c1_test_order_id1 = c1_b_test_order_id1;
  *chartInstance->c1_state_id1 = c1_b_state_id1;
  *chartInstance->c1_simulation_stop = c1_b_simulation_stop;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CL_pi_MutantsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_test_case, 10U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_state, 11U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_test_order_id1, 12U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_state_id1, 13U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_simulation_stop, 14U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
}

static void mdl_start_c1_CL_pi_Mutants(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc1_CL_pi_Mutants(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  (void)c1_chartNumber;
  (void)c1_instanceNumber;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_CL_pi_MutantsInstanceStruct *chartInstance;
  chartInstance = (SFc1_CL_pi_MutantsInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static boolean_T c1_emlrt_marshallIn(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance, const mxArray *c1_b_simulation_stop, const char_T
  *c1_identifier)
{
  boolean_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_simulation_stop),
    &c1_thisId);
  sf_mex_destroy(&c1_b_simulation_stop);
  return c1_y;
}

static boolean_T c1_b_emlrt_marshallIn(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_simulation_stop;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_CL_pi_MutantsInstanceStruct *chartInstance;
  chartInstance = (SFc1_CL_pi_MutantsInstanceStruct *)chartInstanceVoid;
  c1_b_simulation_stop = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_simulation_stop),
    &c1_thisId);
  sf_mex_destroy(&c1_b_simulation_stop);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_CL_pi_MutantsInstanceStruct *chartInstance;
  chartInstance = (SFc1_CL_pi_MutantsInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance, const mxArray *c1_b_state_id1, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_state_id1),
    &c1_thisId);
  sf_mex_destroy(&c1_b_state_id1);
  return c1_y;
}

static real_T c1_d_emlrt_marshallIn(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d3;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d3, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d3;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_state_id1;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_CL_pi_MutantsInstanceStruct *chartInstance;
  chartInstance = (SFc1_CL_pi_MutantsInstanceStruct *)chartInstanceVoid;
  c1_b_state_id1 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_state_id1),
    &c1_thisId);
  sf_mex_destroy(&c1_b_state_id1);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i12;
  int32_T c1_i13;
  const mxArray *c1_y = NULL;
  int32_T c1_i14;
  real_T c1_u[960];
  SFc1_CL_pi_MutantsInstanceStruct *chartInstance;
  chartInstance = (SFc1_CL_pi_MutantsInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_i12 = 0;
  for (c1_i13 = 0; c1_i13 < 8; c1_i13++) {
    for (c1_i14 = 0; c1_i14 < 120; c1_i14++) {
      c1_u[c1_i14 + c1_i12] = (*(real_T (*)[960])c1_inData)[c1_i14 + c1_i12];
    }

    c1_i12 += 120;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 120, 8), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i15;
  const mxArray *c1_y = NULL;
  real_T c1_u[120];
  SFc1_CL_pi_MutantsInstanceStruct *chartInstance;
  chartInstance = (SFc1_CL_pi_MutantsInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  for (c1_i15 = 0; c1_i15 < 120; c1_i15++) {
    c1_u[c1_i15] = (*(real_T (*)[120])c1_inData)[c1_i15];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 120), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i16;
  const mxArray *c1_y = NULL;
  real_T c1_u[6];
  SFc1_CL_pi_MutantsInstanceStruct *chartInstance;
  chartInstance = (SFc1_CL_pi_MutantsInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  for (c1_i16 = 0; c1_i16 < 6; c1_i16++) {
    c1_u[c1_i16] = (*(real_T (*)[6])c1_inData)[c1_i16];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

const mxArray *sf_c1_CL_pi_Mutants_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_CL_pi_MutantsInstanceStruct *chartInstance;
  chartInstance = (SFc1_CL_pi_MutantsInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_e_emlrt_marshallIn(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i17;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i17, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i17;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_CL_pi_MutantsInstanceStruct *chartInstance;
  chartInstance = (SFc1_CL_pi_MutantsInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_CL_pi_Mutants, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_CL_pi_Mutants), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_CL_pi_Mutants);
  return c1_y;
}

static uint8_T c1_g_emlrt_marshallIn(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_CL_pi_MutantsInstanceStruct
  *chartInstance)
{
  chartInstance->c1_test_order = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_tc_size = (real_T (*)[120])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_trans1 = (real_T (*)[960])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_trans2 = (real_T (*)[960])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c1_trans3 = (real_T (*)[960])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c1_trans4 = (real_T (*)[960])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c1_v_engine = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c1_temp = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c1_test_order_id = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c1_state_id = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c1_test_case = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_state = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_test_order_id1 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c1_state_id1 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c1_simulation_stop = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_CL_pi_Mutants_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1112412584U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3107320272U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1300054539U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(564875740U);
}

mxArray* sf_c1_CL_pi_Mutants_get_post_codegen_info(void);
mxArray *sf_c1_CL_pi_Mutants_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("k9wWmEB3NIw9224FwRTBNB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,10,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(120);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(120);
      pr[1] = (double)(8);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(120);
      pr[1] = (double)(8);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(120);
      pr[1] = (double)(8);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(120);
      pr[1] = (double)(8);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c1_CL_pi_Mutants_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_CL_pi_Mutants_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_CL_pi_Mutants_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_CL_pi_Mutants_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_CL_pi_Mutants_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c1_CL_pi_Mutants(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[19],T\"simulation_stop\",},{M[1],M[14],T\"state\",},{M[1],M[18],T\"state_id1\",},{M[1],M[13],T\"test_case\",},{M[1],M[17],T\"test_order_id1\",},{M[8],M[0],T\"is_active_c1_CL_pi_Mutants\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_CL_pi_Mutants_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_CL_pi_MutantsInstanceStruct *chartInstance =
      (SFc1_CL_pi_MutantsInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CL_pi_MutantsMachineNumber_,
           1,
           1,
           1,
           0,
           15,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_CL_pi_MutantsMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_CL_pi_MutantsMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _CL_pi_MutantsMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"test_order");
          _SFD_SET_DATA_PROPS(1,1,1,0,"tc_size");
          _SFD_SET_DATA_PROPS(2,1,1,0,"trans1");
          _SFD_SET_DATA_PROPS(3,1,1,0,"trans2");
          _SFD_SET_DATA_PROPS(4,1,1,0,"trans3");
          _SFD_SET_DATA_PROPS(5,1,1,0,"trans4");
          _SFD_SET_DATA_PROPS(6,1,1,0,"v_engine");
          _SFD_SET_DATA_PROPS(7,1,1,0,"temp");
          _SFD_SET_DATA_PROPS(8,1,1,0,"test_order_id");
          _SFD_SET_DATA_PROPS(9,1,1,0,"state_id");
          _SFD_SET_DATA_PROPS(10,2,0,1,"test_case");
          _SFD_SET_DATA_PROPS(11,2,0,1,"state");
          _SFD_SET_DATA_PROPS(12,2,0,1,"test_order_id1");
          _SFD_SET_DATA_PROPS(13,2,0,1,"state_id1");
          _SFD_SET_DATA_PROPS(14,2,0,1,"simulation_stop");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,3,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,889);
        _SFD_CV_INIT_EML_IF(0,1,0,361,442,-1,884);
        _SFD_CV_INIT_EML_IF(0,1,1,505,547,614,876);
        _SFD_CV_INIT_EML_IF(0,1,2,630,668,791,865);

        {
          static int condStart[] = { 364, 405 };

          static int condEnd[] = { 401, 442 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,364,442,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,364,401,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,405,442,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,508,547,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,633,668,-1,2);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 120U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 120U;
          dimVector[1]= 8U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 120U;
          dimVector[1]= 8U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 120U;
          dimVector[1]= 8U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 120U;
          dimVector[1]= 8U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _CL_pi_MutantsMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_CL_pi_MutantsInstanceStruct *chartInstance =
      (SFc1_CL_pi_MutantsInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c1_test_order);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c1_tc_size);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c1_trans1);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c1_trans2);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c1_trans3);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c1_trans4);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c1_v_engine);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c1_temp);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c1_test_order_id);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c1_state_id);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c1_test_case);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c1_state);
        _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c1_test_order_id1);
        _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c1_state_id1);
        _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c1_simulation_stop);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "so6bNRvYdbdUc9vhB7NjMgH";
}

static void sf_opaque_initialize_c1_CL_pi_Mutants(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_CL_pi_MutantsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_CL_pi_Mutants((SFc1_CL_pi_MutantsInstanceStruct*)
    chartInstanceVar);
  initialize_c1_CL_pi_Mutants((SFc1_CL_pi_MutantsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_CL_pi_Mutants(void *chartInstanceVar)
{
  enable_c1_CL_pi_Mutants((SFc1_CL_pi_MutantsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_CL_pi_Mutants(void *chartInstanceVar)
{
  disable_c1_CL_pi_Mutants((SFc1_CL_pi_MutantsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_CL_pi_Mutants(void *chartInstanceVar)
{
  sf_gateway_c1_CL_pi_Mutants((SFc1_CL_pi_MutantsInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_CL_pi_Mutants(SimStruct* S)
{
  return get_sim_state_c1_CL_pi_Mutants((SFc1_CL_pi_MutantsInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_CL_pi_Mutants(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c1_CL_pi_Mutants((SFc1_CL_pi_MutantsInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c1_CL_pi_Mutants(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_CL_pi_MutantsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CL_pi_Mutants_optimization_info();
    }

    finalize_c1_CL_pi_Mutants((SFc1_CL_pi_MutantsInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_CL_pi_Mutants((SFc1_CL_pi_MutantsInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_CL_pi_Mutants(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_CL_pi_Mutants((SFc1_CL_pi_MutantsInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c1_CL_pi_Mutants(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CL_pi_Mutants_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 1);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,10);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,5);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=5; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 10; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(605811424U));
  ssSetChecksum1(S,(3557740501U));
  ssSetChecksum2(S,(174258191U));
  ssSetChecksum3(S,(1864010710U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_CL_pi_Mutants(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_CL_pi_Mutants(SimStruct *S)
{
  SFc1_CL_pi_MutantsInstanceStruct *chartInstance;
  chartInstance = (SFc1_CL_pi_MutantsInstanceStruct *)utMalloc(sizeof
    (SFc1_CL_pi_MutantsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_CL_pi_MutantsInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_CL_pi_Mutants;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_CL_pi_Mutants;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_CL_pi_Mutants;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_CL_pi_Mutants;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_CL_pi_Mutants;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_CL_pi_Mutants;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_CL_pi_Mutants;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_CL_pi_Mutants;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_CL_pi_Mutants;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_CL_pi_Mutants;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_CL_pi_Mutants;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c1_CL_pi_Mutants(chartInstance);
}

void c1_CL_pi_Mutants_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_CL_pi_Mutants(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_CL_pi_Mutants(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_CL_pi_Mutants(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_CL_pi_Mutants_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
