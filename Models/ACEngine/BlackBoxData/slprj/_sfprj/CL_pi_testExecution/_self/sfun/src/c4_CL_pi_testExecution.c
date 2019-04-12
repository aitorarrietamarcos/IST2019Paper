/* Include files */

#include "CL_pi_testExecution_sfun.h"
#include "c4_CL_pi_testExecution.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CL_pi_testExecution_sfun_debug_macros.h"
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
static const char * c4_debug_family_names[18] = { "num_signals", "nargin",
  "nargout", "test_order", "tc_size", "trans1", "trans2", "trans3", "trans4",
  "v_engine", "temp", "test_order_id", "state_id", "test_case", "state",
  "test_order_id1", "state_id1", "simulation_stop" };

/* Function Declarations */
static void initialize_c4_CL_pi_testExecution
  (SFc4_CL_pi_testExecutionInstanceStruct *chartInstance);
static void initialize_params_c4_CL_pi_testExecution
  (SFc4_CL_pi_testExecutionInstanceStruct *chartInstance);
static void enable_c4_CL_pi_testExecution(SFc4_CL_pi_testExecutionInstanceStruct
  *chartInstance);
static void disable_c4_CL_pi_testExecution
  (SFc4_CL_pi_testExecutionInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_CL_pi_testExecution
  (SFc4_CL_pi_testExecutionInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_CL_pi_testExecution
  (SFc4_CL_pi_testExecutionInstanceStruct *chartInstance);
static void set_sim_state_c4_CL_pi_testExecution
  (SFc4_CL_pi_testExecutionInstanceStruct *chartInstance, const mxArray *c4_st);
static void finalize_c4_CL_pi_testExecution
  (SFc4_CL_pi_testExecutionInstanceStruct *chartInstance);
static void sf_gateway_c4_CL_pi_testExecution
  (SFc4_CL_pi_testExecutionInstanceStruct *chartInstance);
static void mdl_start_c4_CL_pi_testExecution
  (SFc4_CL_pi_testExecutionInstanceStruct *chartInstance);
static void initSimStructsc4_CL_pi_testExecution
  (SFc4_CL_pi_testExecutionInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static boolean_T c4_emlrt_marshallIn(SFc4_CL_pi_testExecutionInstanceStruct
  *chartInstance, const mxArray *c4_b_simulation_stop, const char_T
  *c4_identifier);
static boolean_T c4_b_emlrt_marshallIn(SFc4_CL_pi_testExecutionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn(SFc4_CL_pi_testExecutionInstanceStruct
  *chartInstance, const mxArray *c4_b_state_id1, const char_T *c4_identifier);
static real_T c4_d_emlrt_marshallIn(SFc4_CL_pi_testExecutionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_e_emlrt_marshallIn(SFc4_CL_pi_testExecutionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_f_emlrt_marshallIn(SFc4_CL_pi_testExecutionInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_CL_pi_testExecution, const
  char_T *c4_identifier);
static uint8_T c4_g_emlrt_marshallIn(SFc4_CL_pi_testExecutionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_CL_pi_testExecutionInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc4_CL_pi_testExecutionInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_CL_pi_testExecution
  (SFc4_CL_pi_testExecutionInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc4_CL_pi_testExecution(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_is_active_c4_CL_pi_testExecution = 0U;
}

static void initialize_params_c4_CL_pi_testExecution
  (SFc4_CL_pi_testExecutionInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_CL_pi_testExecution(SFc4_CL_pi_testExecutionInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_CL_pi_testExecution
  (SFc4_CL_pi_testExecutionInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_CL_pi_testExecution
  (SFc4_CL_pi_testExecutionInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_CL_pi_testExecution
  (SFc4_CL_pi_testExecutionInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  boolean_T c4_hoistedGlobal;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_hoistedGlobal;
  const mxArray *c4_c_y = NULL;
  real_T c4_c_hoistedGlobal;
  const mxArray *c4_d_y = NULL;
  real_T c4_d_hoistedGlobal;
  const mxArray *c4_e_y = NULL;
  real_T c4_e_hoistedGlobal;
  const mxArray *c4_f_y = NULL;
  uint8_T c4_f_hoistedGlobal;
  const mxArray *c4_g_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(6, 1), false);
  c4_hoistedGlobal = *chartInstance->c4_simulation_stop;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_hoistedGlobal, 11, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = *chartInstance->c4_state;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = *chartInstance->c4_state_id1;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_hoistedGlobal = *chartInstance->c4_test_case;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_e_hoistedGlobal = *chartInstance->c4_test_order_id1;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  c4_f_hoistedGlobal = chartInstance->c4_is_active_c4_CL_pi_testExecution;
  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_create("y", &c4_f_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 5, c4_g_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_CL_pi_testExecution
  (SFc4_CL_pi_testExecutionInstanceStruct *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  *chartInstance->c4_simulation_stop = c4_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 0)), "simulation_stop");
  *chartInstance->c4_state = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 1)), "state");
  *chartInstance->c4_state_id1 = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 2)), "state_id1");
  *chartInstance->c4_test_case = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 3)), "test_case");
  *chartInstance->c4_test_order_id1 = c4_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 4)), "test_order_id1");
  chartInstance->c4_is_active_c4_CL_pi_testExecution = c4_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 5)),
     "is_active_c4_CL_pi_testExecution");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_CL_pi_testExecution(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_CL_pi_testExecution
  (SFc4_CL_pi_testExecutionInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_CL_pi_testExecution
  (SFc4_CL_pi_testExecutionInstanceStruct *chartInstance)
{
  int32_T c4_i0;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  real_T c4_b_test_order;
  int32_T c4_i5;
  int32_T c4_i6;
  real_T c4_b_tc_size[120];
  int32_T c4_i7;
  real_T c4_b_trans1[960];
  int32_T c4_i8;
  real_T c4_b_trans2[960];
  int32_T c4_i9;
  real_T c4_b_trans3[960];
  real_T c4_b_v_engine;
  real_T c4_b_trans4[960];
  real_T c4_b_temp;
  real_T c4_b_test_order_id;
  real_T c4_b_state_id;
  uint32_T c4_debug_family_var_map[18];
  real_T c4_num_signals;
  real_T c4_nargin = 10.0;
  real_T c4_nargout = 5.0;
  real_T c4_b_test_case;
  real_T c4_b_state;
  real_T c4_b_test_order_id1;
  real_T c4_b_state_id1;
  boolean_T c4_b_simulation_stop;
  real_T c4_d0;
  real_T c4_d1;
  real_T c4_A;
  real_T c4_d2;
  boolean_T guard1 = false;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_state_id, 9U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_test_order_id, 8U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_temp, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_v_engine, 6U);
  for (c4_i0 = 0; c4_i0 < 960; c4_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c4_trans4)[c4_i0], 5U);
  }

  for (c4_i1 = 0; c4_i1 < 960; c4_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c4_trans3)[c4_i1], 4U);
  }

  for (c4_i2 = 0; c4_i2 < 960; c4_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c4_trans2)[c4_i2], 3U);
  }

  for (c4_i3 = 0; c4_i3 < 960; c4_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c4_trans1)[c4_i3], 2U);
  }

  for (c4_i4 = 0; c4_i4 < 120; c4_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c4_tc_size)[c4_i4], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_test_order, 0U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  c4_b_test_order = *chartInstance->c4_test_order;
  for (c4_i5 = 0; c4_i5 < 120; c4_i5++) {
    c4_b_tc_size[c4_i5] = (*chartInstance->c4_tc_size)[c4_i5];
  }

  for (c4_i6 = 0; c4_i6 < 960; c4_i6++) {
    c4_b_trans1[c4_i6] = (*chartInstance->c4_trans1)[c4_i6];
  }

  for (c4_i7 = 0; c4_i7 < 960; c4_i7++) {
    c4_b_trans2[c4_i7] = (*chartInstance->c4_trans2)[c4_i7];
  }

  for (c4_i8 = 0; c4_i8 < 960; c4_i8++) {
    c4_b_trans3[c4_i8] = (*chartInstance->c4_trans3)[c4_i8];
  }

  for (c4_i9 = 0; c4_i9 < 960; c4_i9++) {
    c4_b_trans4[c4_i9] = (*chartInstance->c4_trans4)[c4_i9];
  }

  c4_b_v_engine = *chartInstance->c4_v_engine;
  c4_b_temp = *chartInstance->c4_temp;
  c4_b_test_order_id = *chartInstance->c4_test_order_id;
  c4_b_state_id = *chartInstance->c4_state_id;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_num_signals, 0U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_test_order, 3U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_b_tc_size, 4U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_b_trans1, 5U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_b_trans2, 6U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_b_trans3, 7U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_b_trans4, 8U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_v_engine, 9U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_temp, 10U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_test_order_id, 11U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_state_id, 12U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_test_case, 13U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_state, 14U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_test_order_id1, 15U,
    c4_b_sf_marshallOut, c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_state_id1, 16U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_simulation_stop, 17U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 3);
  c4_num_signals = 4.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 226, 13, MAX_uint32_T, (int32_T)sf_integer_check
    (chartInstance->S, 1U, 226U, 13U, c4_b_test_order_id), 1, 1);
  c4_b_test_case = c4_b_test_order;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  c4_b_test_order_id1 = c4_b_test_order_id;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
  c4_b_state = c4_b_state_id;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_b_state_id1 = c4_b_state;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_b_simulation_stop = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
  c4_d0 = c4_b_trans1[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 375, 26, MAX_uint32_T, (int32_T)sf_integer_check
    (chartInstance->S, 1U, 375U, 26U, c4_b_test_case), 1, 120) + 120 *
                       (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 375, 26, MAX_uint32_T, (int32_T)sf_integer_check
    (chartInstance->S, 1U, 375U, 26U, c4_b_state_id), 1, 8) - 1)) - 1];
  guard1 = false;
  if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c4_b_v_engine, c4_d0,
        -1, 4U, c4_b_v_engine > c4_d0))) {
    c4_d1 = c4_b_trans2[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 416, 26, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 416U, 26U, c4_b_test_case), 1, 120) + 120 *
                         (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 416, 26, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 416U, 26U, c4_b_state_id), 1, 8) - 1)) - 1];
    if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c4_b_v_engine, c4_d1,
          -1, 2U, c4_b_v_engine < c4_d1))) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 0, true);
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
      c4_A = c4_b_tc_size[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 462, 18, MAX_uint32_T, (int32_T)sf_integer_check
        (chartInstance->S, 1U, 462U, 18U, c4_b_test_case), 1, 120) - 1];
      c4_d2 = c4_A / 4.0;
      if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 2, c4_b_state_id, c4_d2,
            -1, 2U, c4_b_state_id < c4_d2))) {
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
        c4_b_state = c4_b_state_id + 1.0;
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
        c4_b_state_id1 = c4_b_state;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
        if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 3, c4_b_test_order_id1,
              1.0, -1, 2U, c4_b_test_order_id1 < 1.0))) {
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 16);
          c4_b_state = 1.0;
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 17);
          c4_b_state_id1 = c4_b_state;
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 18);
          c4_b_test_order_id1 = c4_b_test_order_id + 1.0;
        } else {
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 20);
          c4_b_simulation_stop = true;
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

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c4_test_case = c4_b_test_case;
  *chartInstance->c4_state = c4_b_state;
  *chartInstance->c4_test_order_id1 = c4_b_test_order_id1;
  *chartInstance->c4_state_id1 = c4_b_state_id1;
  *chartInstance->c4_simulation_stop = c4_b_simulation_stop;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CL_pi_testExecutionMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_test_case, 10U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_state, 11U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_test_order_id1, 12U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_state_id1, 13U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_simulation_stop, 14U);
}

static void mdl_start_c4_CL_pi_testExecution
  (SFc4_CL_pi_testExecutionInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc4_CL_pi_testExecution
  (SFc4_CL_pi_testExecutionInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)(c4_machineNumber);
  (void)(c4_chartNumber);
  (void)(c4_instanceNumber);
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  boolean_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_CL_pi_testExecutionInstanceStruct *chartInstance;
  chartInstance = (SFc4_CL_pi_testExecutionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(boolean_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static boolean_T c4_emlrt_marshallIn(SFc4_CL_pi_testExecutionInstanceStruct
  *chartInstance, const mxArray *c4_b_simulation_stop, const char_T
  *c4_identifier)
{
  boolean_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_simulation_stop),
    &c4_thisId);
  sf_mex_destroy(&c4_b_simulation_stop);
  return c4_y;
}

static boolean_T c4_b_emlrt_marshallIn(SFc4_CL_pi_testExecutionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  boolean_T c4_y;
  boolean_T c4_b0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_b0, 1, 11, 0U, 0, 0U, 0);
  c4_y = c4_b0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_simulation_stop;
  emlrtMsgIdentifier c4_thisId;
  boolean_T c4_y;
  SFc4_CL_pi_testExecutionInstanceStruct *chartInstance;
  chartInstance = (SFc4_CL_pi_testExecutionInstanceStruct *)chartInstanceVoid;
  c4_b_simulation_stop = sf_mex_dup(c4_mxArrayInData);
  c4_thisId.fIdentifier = (const char *)c4_varName;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_simulation_stop),
    &c4_thisId);
  sf_mex_destroy(&c4_b_simulation_stop);
  *(boolean_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_CL_pi_testExecutionInstanceStruct *chartInstance;
  chartInstance = (SFc4_CL_pi_testExecutionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_c_emlrt_marshallIn(SFc4_CL_pi_testExecutionInstanceStruct
  *chartInstance, const mxArray *c4_b_state_id1, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_state_id1),
    &c4_thisId);
  sf_mex_destroy(&c4_b_state_id1);
  return c4_y;
}

static real_T c4_d_emlrt_marshallIn(SFc4_CL_pi_testExecutionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d3;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d3, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d3;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_state_id1;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_CL_pi_testExecutionInstanceStruct *chartInstance;
  chartInstance = (SFc4_CL_pi_testExecutionInstanceStruct *)chartInstanceVoid;
  c4_b_state_id1 = sf_mex_dup(c4_mxArrayInData);
  c4_thisId.fIdentifier = (const char *)c4_varName;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_state_id1),
    &c4_thisId);
  sf_mex_destroy(&c4_b_state_id1);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_i10;
  int32_T c4_i11;
  const mxArray *c4_y = NULL;
  int32_T c4_i12;
  real_T c4_u[960];
  SFc4_CL_pi_testExecutionInstanceStruct *chartInstance;
  chartInstance = (SFc4_CL_pi_testExecutionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_i10 = 0;
  for (c4_i11 = 0; c4_i11 < 8; c4_i11++) {
    for (c4_i12 = 0; c4_i12 < 120; c4_i12++) {
      c4_u[c4_i12 + c4_i10] = (*(real_T (*)[960])c4_inData)[c4_i12 + c4_i10];
    }

    c4_i10 += 120;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 120, 8), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_i13;
  const mxArray *c4_y = NULL;
  real_T c4_u[120];
  SFc4_CL_pi_testExecutionInstanceStruct *chartInstance;
  chartInstance = (SFc4_CL_pi_testExecutionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  for (c4_i13 = 0; c4_i13 < 120; c4_i13++) {
    c4_u[c4_i13] = (*(real_T (*)[120])c4_inData)[c4_i13];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 120), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

const mxArray *sf_c4_CL_pi_testExecution_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_CL_pi_testExecutionInstanceStruct *chartInstance;
  chartInstance = (SFc4_CL_pi_testExecutionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_e_emlrt_marshallIn(SFc4_CL_pi_testExecutionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i14;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i14, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i14;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_CL_pi_testExecutionInstanceStruct *chartInstance;
  chartInstance = (SFc4_CL_pi_testExecutionInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_thisId.fIdentifier = (const char *)c4_varName;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_f_emlrt_marshallIn(SFc4_CL_pi_testExecutionInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_CL_pi_testExecution, const
  char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_CL_pi_testExecution), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_CL_pi_testExecution);
  return c4_y;
}

static uint8_T c4_g_emlrt_marshallIn(SFc4_CL_pi_testExecutionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_CL_pi_testExecutionInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_CL_pi_testExecutionInstanceStruct
  *chartInstance)
{
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_test_order = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_tc_size = (real_T (*)[120])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_trans1 = (real_T (*)[960])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c4_trans2 = (real_T (*)[960])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c4_trans3 = (real_T (*)[960])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c4_trans4 = (real_T (*)[960])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c4_v_engine = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c4_temp = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c4_test_order_id = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c4_state_id = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c4_test_case = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_state = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c4_test_order_id1 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c4_state_id1 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c4_simulation_stop = (boolean_T *)ssGetOutputPortSignal_wrapper
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

void sf_c4_CL_pi_testExecution_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(313549982U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(990505539U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(895401901U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(734535759U);
}

mxArray* sf_c4_CL_pi_testExecution_get_post_codegen_info(void);
mxArray *sf_c4_CL_pi_testExecution_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("jlPsaVm6ZefvHNPSsRMa9");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,10,3,dataFields);

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
    mxArray* mxPostCodegenInfo = sf_c4_CL_pi_testExecution_get_post_codegen_info
      ();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_CL_pi_testExecution_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_CL_pi_testExecution_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("needsCoverage");
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

mxArray *sf_c4_CL_pi_testExecution_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c4_CL_pi_testExecution_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c4_CL_pi_testExecution(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[19],T\"simulation_stop\",},{M[1],M[14],T\"state\",},{M[1],M[18],T\"state_id1\",},{M[1],M[13],T\"test_case\",},{M[1],M[17],T\"test_order_id1\",},{M[8],M[0],T\"is_active_c4_CL_pi_testExecution\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_CL_pi_testExecution_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_CL_pi_testExecutionInstanceStruct *chartInstance =
      (SFc4_CL_pi_testExecutionInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CL_pi_testExecutionMachineNumber_,
           4,
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
        init_script_number_translation(_CL_pi_testExecutionMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_CL_pi_testExecutionMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _CL_pi_testExecutionMachineNumber_,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,834);
        _SFD_CV_INIT_EML_IF(0,1,0,361,442,-1,829);
        _SFD_CV_INIT_EML_IF(0,1,1,450,492,559,821);
        _SFD_CV_INIT_EML_IF(0,1,2,575,613,736,810);

        {
          static int condStart[] = { 364, 405 };

          static int condEnd[] = { 401, 442 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,364,442,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,364,401,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,405,442,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,453,492,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,578,613,-1,2);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 120U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 120U;
          dimVector[1]= 8U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 120U;
          dimVector[1]= 8U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 120U;
          dimVector[1]= 8U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 120U;
          dimVector[1]= 8U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _CL_pi_testExecutionMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_CL_pi_testExecutionInstanceStruct *chartInstance =
      (SFc4_CL_pi_testExecutionInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c4_test_order);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c4_tc_size);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c4_trans1);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c4_trans2);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c4_trans3);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c4_trans4);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c4_v_engine);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c4_temp);
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)chartInstance->c4_test_order_id);
        _SFD_SET_DATA_VALUE_PTR(9U, (void *)chartInstance->c4_state_id);
        _SFD_SET_DATA_VALUE_PTR(10U, (void *)chartInstance->c4_test_case);
        _SFD_SET_DATA_VALUE_PTR(11U, (void *)chartInstance->c4_state);
        _SFD_SET_DATA_VALUE_PTR(12U, (void *)chartInstance->c4_test_order_id1);
        _SFD_SET_DATA_VALUE_PTR(13U, (void *)chartInstance->c4_state_id1);
        _SFD_SET_DATA_VALUE_PTR(14U, (void *)chartInstance->c4_simulation_stop);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sWAtZEr5cy1HthTs7Jv5WnB";
}

static void sf_opaque_initialize_c4_CL_pi_testExecution(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_CL_pi_testExecutionInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_CL_pi_testExecution
    ((SFc4_CL_pi_testExecutionInstanceStruct*) chartInstanceVar);
  initialize_c4_CL_pi_testExecution((SFc4_CL_pi_testExecutionInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_CL_pi_testExecution(void *chartInstanceVar)
{
  enable_c4_CL_pi_testExecution((SFc4_CL_pi_testExecutionInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_CL_pi_testExecution(void *chartInstanceVar)
{
  disable_c4_CL_pi_testExecution((SFc4_CL_pi_testExecutionInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_CL_pi_testExecution(void *chartInstanceVar)
{
  sf_gateway_c4_CL_pi_testExecution((SFc4_CL_pi_testExecutionInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_CL_pi_testExecution(SimStruct*
  S)
{
  return get_sim_state_c4_CL_pi_testExecution
    ((SFc4_CL_pi_testExecutionInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_CL_pi_testExecution(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c4_CL_pi_testExecution((SFc4_CL_pi_testExecutionInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c4_CL_pi_testExecution(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_CL_pi_testExecutionInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CL_pi_testExecution_optimization_info();
    }

    finalize_c4_CL_pi_testExecution((SFc4_CL_pi_testExecutionInstanceStruct*)
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
  initSimStructsc4_CL_pi_testExecution((SFc4_CL_pi_testExecutionInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_CL_pi_testExecution(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_CL_pi_testExecution
      ((SFc4_CL_pi_testExecutionInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c4_CL_pi_testExecution(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetInputPortDirectFeedThrough(S, 2, 1);
  ssSetInputPortDirectFeedThrough(S, 3, 1);
  ssSetInputPortDirectFeedThrough(S, 4, 1);
  ssSetInputPortDirectFeedThrough(S, 5, 1);
  ssSetInputPortDirectFeedThrough(S, 6, 1);
  ssSetInputPortDirectFeedThrough(S, 7, 1);
  ssSetInputPortDirectFeedThrough(S, 8, 1);
  ssSetInputPortDirectFeedThrough(S, 9, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CL_pi_testExecution_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 4);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,4);
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
        infoStruct,4,10);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,5);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2100158726U));
  ssSetChecksum1(S,(2645354810U));
  ssSetChecksum2(S,(3551266057U));
  ssSetChecksum3(S,(3239361680U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_CL_pi_testExecution(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_CL_pi_testExecution(SimStruct *S)
{
  SFc4_CL_pi_testExecutionInstanceStruct *chartInstance;
  chartInstance = (SFc4_CL_pi_testExecutionInstanceStruct *)utMalloc(sizeof
    (SFc4_CL_pi_testExecutionInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_CL_pi_testExecutionInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_CL_pi_testExecution;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_CL_pi_testExecution;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_CL_pi_testExecution;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_CL_pi_testExecution;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_CL_pi_testExecution;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_CL_pi_testExecution;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_CL_pi_testExecution;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_CL_pi_testExecution;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_CL_pi_testExecution;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_CL_pi_testExecution;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_CL_pi_testExecution;
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
  mdl_start_c4_CL_pi_testExecution(chartInstance);
}

void c4_CL_pi_testExecution_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_CL_pi_testExecution(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_CL_pi_testExecution(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_CL_pi_testExecution(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_CL_pi_testExecution_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
