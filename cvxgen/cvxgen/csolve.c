/* Produced by CVXGEN, 2017-06-14 00:59:56 -0400.  */
/* CVXGEN is Copyright (C) 2006-2012 Jacob Mattingley, jem@cvxgen.com. */
/* The code in this file is Copyright (C) 2006-2012 Jacob Mattingley. */
/* CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial */
/* applications without prior written permission from Jacob Mattingley. */

/* Filename: csolve.c. */
/* Description: mex-able file for running cvxgen solver. */
#include "mex.h"
#include "solver.h"
Vars vars;
Params params;
Workspace work;
Settings settings;
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
  int i, j;
  mxArray *xm, *cell, *xm_cell;
  double *src;
  double *dest;
  double *dest_cell;
  int valid_vars;
  int steps;
  int this_var_errors;
  int warned_diags;
  int prepare_for_c = 0;
  int extra_solves;
  const char *status_names[] = {"optval", "gap", "steps", "converged"};
  mwSize dims1x1of1[1] = {1};
  mwSize dims[1];
  const char *var_names[] = {"u_0", "u_1", "u_2", "u_3", "u_4", "u_5", "u_6", "u_7", "u_8", "u_9", "u_10", "u_11", "u_12", "u_13", "u_14", "u_15", "u_16", "u_17", "u_18", "u_19", "u_20", "u_21", "u_22", "u_23", "u_24", "u_25", "u_26", "u_27", "u_28", "u_29", "u_30", "u_31", "u_32", "u_33", "u_34", "u_35", "u_36", "u_37", "u_38", "u_39", "u_40", "u_41", "u_42", "u_43", "u_44", "u_45", "u_46", "u_47", "u_48", "u_49", "u_50", "x_1", "x_2", "x_3", "x_4", "x_5", "x_6", "x_7", "x_8", "x_9", "x_10", "x_11", "x_12", "x_13", "x_14", "x_15", "x_16", "x_17", "x_18", "x_19", "x_20", "x_21", "x_22", "x_23", "x_24", "x_25", "x_26", "x_27", "x_28", "x_29", "x_30", "x_31", "x_32", "x_33", "x_34", "x_35", "x_36", "x_37", "x_38", "x_39", "x_40", "x_41", "x_42", "x_43", "x_44", "x_45", "x_46", "x_47", "x_48", "x_49", "x_50", "x_51", "u", "x"};
  const int num_var_names = 104;
  /* Avoid compiler warnings of unused variables by using a dummy assignment. */
  warned_diags = j = 0;
  extra_solves = 0;
  set_defaults();
  /* Check we got the right number of arguments. */
  if (nrhs == 0)
    mexErrMsgTxt("Not enough arguments: You need to specify at least the parameters.\n");
  if (nrhs > 1) {
    /* Assume that the second argument is the settings. */
    if (mxGetField(prhs[1], 0, "eps") != NULL)
      settings.eps = *mxGetPr(mxGetField(prhs[1], 0, "eps"));
    if (mxGetField(prhs[1], 0, "max_iters") != NULL)
      settings.max_iters = *mxGetPr(mxGetField(prhs[1], 0, "max_iters"));
    if (mxGetField(prhs[1], 0, "refine_steps") != NULL)
      settings.refine_steps = *mxGetPr(mxGetField(prhs[1], 0, "refine_steps"));
    if (mxGetField(prhs[1], 0, "verbose") != NULL)
      settings.verbose = *mxGetPr(mxGetField(prhs[1], 0, "verbose"));
    if (mxGetField(prhs[1], 0, "better_start") != NULL)
      settings.better_start = *mxGetPr(mxGetField(prhs[1], 0, "better_start"));
    if (mxGetField(prhs[1], 0, "verbose_refinement") != NULL)
      settings.verbose_refinement = *mxGetPr(mxGetField(prhs[1], 0,
            "verbose_refinement"));
    if (mxGetField(prhs[1], 0, "debug") != NULL)
      settings.debug = *mxGetPr(mxGetField(prhs[1], 0, "debug"));
    if (mxGetField(prhs[1], 0, "kkt_reg") != NULL)
      settings.kkt_reg = *mxGetPr(mxGetField(prhs[1], 0, "kkt_reg"));
    if (mxGetField(prhs[1], 0, "s_init") != NULL)
      settings.s_init = *mxGetPr(mxGetField(prhs[1], 0, "s_init"));
    if (mxGetField(prhs[1], 0, "z_init") != NULL)
      settings.z_init = *mxGetPr(mxGetField(prhs[1], 0, "z_init"));
    if (mxGetField(prhs[1], 0, "resid_tol") != NULL)
      settings.resid_tol = *mxGetPr(mxGetField(prhs[1], 0, "resid_tol"));
    if (mxGetField(prhs[1], 0, "extra_solves") != NULL)
      extra_solves = *mxGetPr(mxGetField(prhs[1], 0, "extra_solves"));
    else
      extra_solves = 0;
    if (mxGetField(prhs[1], 0, "prepare_for_c") != NULL)
      prepare_for_c = *mxGetPr(mxGetField(prhs[1], 0, "prepare_for_c"));
  }
  valid_vars = 0;
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_0");
  if (xm == NULL) {
    printf("could not find params.A_0.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_0 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_0 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_0 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_0 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_0;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_1");
  if (xm == NULL) {
    /* Attempt to pull A_1 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 0);
  }
  if (xm == NULL) {
    printf("could not find params.A_1 or params.A{1}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_1 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_1 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_1 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_1 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_1;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_2");
  if (xm == NULL) {
    /* Attempt to pull A_2 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 1);
  }
  if (xm == NULL) {
    printf("could not find params.A_2 or params.A{2}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_2 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_2 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_2 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_2 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_2;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_3");
  if (xm == NULL) {
    /* Attempt to pull A_3 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 2);
  }
  if (xm == NULL) {
    printf("could not find params.A_3 or params.A{3}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_3 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_3 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_3 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_3 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_3;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_4");
  if (xm == NULL) {
    /* Attempt to pull A_4 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 3);
  }
  if (xm == NULL) {
    printf("could not find params.A_4 or params.A{4}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_4 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_4 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_4 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_4 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_4;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_5");
  if (xm == NULL) {
    /* Attempt to pull A_5 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 4);
  }
  if (xm == NULL) {
    printf("could not find params.A_5 or params.A{5}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_5 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_5 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_5 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_5 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_5;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_6");
  if (xm == NULL) {
    /* Attempt to pull A_6 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 5);
  }
  if (xm == NULL) {
    printf("could not find params.A_6 or params.A{6}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_6 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_6 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_6 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_6 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_6;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_7");
  if (xm == NULL) {
    /* Attempt to pull A_7 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 6);
  }
  if (xm == NULL) {
    printf("could not find params.A_7 or params.A{7}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_7 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_7 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_7 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_7 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_7;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_8");
  if (xm == NULL) {
    /* Attempt to pull A_8 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 7);
  }
  if (xm == NULL) {
    printf("could not find params.A_8 or params.A{8}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_8 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_8 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_8 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_8 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_8;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_9");
  if (xm == NULL) {
    /* Attempt to pull A_9 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 8);
  }
  if (xm == NULL) {
    printf("could not find params.A_9 or params.A{9}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_9 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_9 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_9 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_9 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_9;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_10");
  if (xm == NULL) {
    /* Attempt to pull A_10 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 9);
  }
  if (xm == NULL) {
    printf("could not find params.A_10 or params.A{10}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_10 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_10 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_10 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_10 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_10;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_11");
  if (xm == NULL) {
    /* Attempt to pull A_11 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 10);
  }
  if (xm == NULL) {
    printf("could not find params.A_11 or params.A{11}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_11 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_11 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_11 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_11 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_11;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_12");
  if (xm == NULL) {
    /* Attempt to pull A_12 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 11);
  }
  if (xm == NULL) {
    printf("could not find params.A_12 or params.A{12}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_12 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_12 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_12 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_12 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_12;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_13");
  if (xm == NULL) {
    /* Attempt to pull A_13 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 12);
  }
  if (xm == NULL) {
    printf("could not find params.A_13 or params.A{13}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_13 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_13 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_13 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_13 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_13;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_14");
  if (xm == NULL) {
    /* Attempt to pull A_14 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 13);
  }
  if (xm == NULL) {
    printf("could not find params.A_14 or params.A{14}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_14 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_14 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_14 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_14 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_14;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_15");
  if (xm == NULL) {
    /* Attempt to pull A_15 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 14);
  }
  if (xm == NULL) {
    printf("could not find params.A_15 or params.A{15}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_15 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_15 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_15 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_15 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_15;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_16");
  if (xm == NULL) {
    /* Attempt to pull A_16 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 15);
  }
  if (xm == NULL) {
    printf("could not find params.A_16 or params.A{16}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_16 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_16 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_16 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_16 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_16;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_17");
  if (xm == NULL) {
    /* Attempt to pull A_17 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 16);
  }
  if (xm == NULL) {
    printf("could not find params.A_17 or params.A{17}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_17 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_17 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_17 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_17 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_17;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_18");
  if (xm == NULL) {
    /* Attempt to pull A_18 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 17);
  }
  if (xm == NULL) {
    printf("could not find params.A_18 or params.A{18}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_18 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_18 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_18 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_18 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_18;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_19");
  if (xm == NULL) {
    /* Attempt to pull A_19 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 18);
  }
  if (xm == NULL) {
    printf("could not find params.A_19 or params.A{19}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_19 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_19 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_19 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_19 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_19;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_20");
  if (xm == NULL) {
    /* Attempt to pull A_20 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 19);
  }
  if (xm == NULL) {
    printf("could not find params.A_20 or params.A{20}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_20 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_20 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_20 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_20 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_20;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_21");
  if (xm == NULL) {
    /* Attempt to pull A_21 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 20);
  }
  if (xm == NULL) {
    printf("could not find params.A_21 or params.A{21}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_21 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_21 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_21 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_21 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_21;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_22");
  if (xm == NULL) {
    /* Attempt to pull A_22 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 21);
  }
  if (xm == NULL) {
    printf("could not find params.A_22 or params.A{22}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_22 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_22 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_22 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_22 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_22;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_23");
  if (xm == NULL) {
    /* Attempt to pull A_23 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 22);
  }
  if (xm == NULL) {
    printf("could not find params.A_23 or params.A{23}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_23 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_23 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_23 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_23 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_23;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_24");
  if (xm == NULL) {
    /* Attempt to pull A_24 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 23);
  }
  if (xm == NULL) {
    printf("could not find params.A_24 or params.A{24}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_24 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_24 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_24 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_24 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_24;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_25");
  if (xm == NULL) {
    /* Attempt to pull A_25 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 24);
  }
  if (xm == NULL) {
    printf("could not find params.A_25 or params.A{25}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_25 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_25 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_25 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_25 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_25;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_26");
  if (xm == NULL) {
    /* Attempt to pull A_26 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 25);
  }
  if (xm == NULL) {
    printf("could not find params.A_26 or params.A{26}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_26 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_26 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_26 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_26 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_26;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_27");
  if (xm == NULL) {
    /* Attempt to pull A_27 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 26);
  }
  if (xm == NULL) {
    printf("could not find params.A_27 or params.A{27}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_27 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_27 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_27 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_27 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_27;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_28");
  if (xm == NULL) {
    /* Attempt to pull A_28 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 27);
  }
  if (xm == NULL) {
    printf("could not find params.A_28 or params.A{28}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_28 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_28 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_28 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_28 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_28;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_29");
  if (xm == NULL) {
    /* Attempt to pull A_29 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 28);
  }
  if (xm == NULL) {
    printf("could not find params.A_29 or params.A{29}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_29 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_29 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_29 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_29 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_29;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_30");
  if (xm == NULL) {
    /* Attempt to pull A_30 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 29);
  }
  if (xm == NULL) {
    printf("could not find params.A_30 or params.A{30}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_30 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_30 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_30 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_30 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_30;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_31");
  if (xm == NULL) {
    /* Attempt to pull A_31 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 30);
  }
  if (xm == NULL) {
    printf("could not find params.A_31 or params.A{31}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_31 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_31 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_31 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_31 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_31;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_32");
  if (xm == NULL) {
    /* Attempt to pull A_32 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 31);
  }
  if (xm == NULL) {
    printf("could not find params.A_32 or params.A{32}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_32 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_32 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_32 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_32 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_32;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_33");
  if (xm == NULL) {
    /* Attempt to pull A_33 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 32);
  }
  if (xm == NULL) {
    printf("could not find params.A_33 or params.A{33}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_33 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_33 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_33 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_33 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_33;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_34");
  if (xm == NULL) {
    /* Attempt to pull A_34 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 33);
  }
  if (xm == NULL) {
    printf("could not find params.A_34 or params.A{34}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_34 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_34 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_34 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_34 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_34;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_35");
  if (xm == NULL) {
    /* Attempt to pull A_35 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 34);
  }
  if (xm == NULL) {
    printf("could not find params.A_35 or params.A{35}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_35 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_35 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_35 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_35 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_35;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_36");
  if (xm == NULL) {
    /* Attempt to pull A_36 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 35);
  }
  if (xm == NULL) {
    printf("could not find params.A_36 or params.A{36}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_36 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_36 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_36 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_36 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_36;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_37");
  if (xm == NULL) {
    /* Attempt to pull A_37 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 36);
  }
  if (xm == NULL) {
    printf("could not find params.A_37 or params.A{37}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_37 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_37 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_37 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_37 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_37;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_38");
  if (xm == NULL) {
    /* Attempt to pull A_38 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 37);
  }
  if (xm == NULL) {
    printf("could not find params.A_38 or params.A{38}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_38 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_38 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_38 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_38 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_38;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_39");
  if (xm == NULL) {
    /* Attempt to pull A_39 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 38);
  }
  if (xm == NULL) {
    printf("could not find params.A_39 or params.A{39}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_39 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_39 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_39 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_39 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_39;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_40");
  if (xm == NULL) {
    /* Attempt to pull A_40 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 39);
  }
  if (xm == NULL) {
    printf("could not find params.A_40 or params.A{40}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_40 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_40 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_40 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_40 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_40;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_41");
  if (xm == NULL) {
    /* Attempt to pull A_41 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 40);
  }
  if (xm == NULL) {
    printf("could not find params.A_41 or params.A{41}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_41 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_41 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_41 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_41 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_41;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_42");
  if (xm == NULL) {
    /* Attempt to pull A_42 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 41);
  }
  if (xm == NULL) {
    printf("could not find params.A_42 or params.A{42}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_42 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_42 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_42 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_42 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_42;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_43");
  if (xm == NULL) {
    /* Attempt to pull A_43 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 42);
  }
  if (xm == NULL) {
    printf("could not find params.A_43 or params.A{43}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_43 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_43 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_43 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_43 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_43;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_44");
  if (xm == NULL) {
    /* Attempt to pull A_44 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 43);
  }
  if (xm == NULL) {
    printf("could not find params.A_44 or params.A{44}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_44 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_44 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_44 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_44 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_44;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_45");
  if (xm == NULL) {
    /* Attempt to pull A_45 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 44);
  }
  if (xm == NULL) {
    printf("could not find params.A_45 or params.A{45}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_45 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_45 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_45 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_45 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_45;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_46");
  if (xm == NULL) {
    /* Attempt to pull A_46 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 45);
  }
  if (xm == NULL) {
    printf("could not find params.A_46 or params.A{46}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_46 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_46 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_46 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_46 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_46;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_47");
  if (xm == NULL) {
    /* Attempt to pull A_47 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 46);
  }
  if (xm == NULL) {
    printf("could not find params.A_47 or params.A{47}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_47 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_47 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_47 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_47 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_47;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_48");
  if (xm == NULL) {
    /* Attempt to pull A_48 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 47);
  }
  if (xm == NULL) {
    printf("could not find params.A_48 or params.A{48}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_48 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_48 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_48 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_48 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_48;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_49");
  if (xm == NULL) {
    /* Attempt to pull A_49 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 48);
  }
  if (xm == NULL) {
    printf("could not find params.A_49 or params.A{49}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_49 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_49 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_49 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_49 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_49;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "A_50");
  if (xm == NULL) {
    /* Attempt to pull A_50 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "A");
    if (cell != NULL)
      xm = mxGetCell(cell, 49);
  }
  if (xm == NULL) {
    printf("could not find params.A_50 or params.A{50}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("A_50 must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter A_50 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter A_50 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter A_50 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.A_50;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_0");
  if (xm == NULL) {
    printf("could not find params.B_0.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_0 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_0 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_0 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_0 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_0;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_1");
  if (xm == NULL) {
    /* Attempt to pull B_1 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 0);
  }
  if (xm == NULL) {
    printf("could not find params.B_1 or params.B{1}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_1 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_1 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_1 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_1 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_1;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_2");
  if (xm == NULL) {
    /* Attempt to pull B_2 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 1);
  }
  if (xm == NULL) {
    printf("could not find params.B_2 or params.B{2}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_2 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_2 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_2 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_2 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_2;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_3");
  if (xm == NULL) {
    /* Attempt to pull B_3 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 2);
  }
  if (xm == NULL) {
    printf("could not find params.B_3 or params.B{3}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_3 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_3 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_3 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_3 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_3;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_4");
  if (xm == NULL) {
    /* Attempt to pull B_4 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 3);
  }
  if (xm == NULL) {
    printf("could not find params.B_4 or params.B{4}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_4 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_4 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_4 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_4 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_4;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_5");
  if (xm == NULL) {
    /* Attempt to pull B_5 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 4);
  }
  if (xm == NULL) {
    printf("could not find params.B_5 or params.B{5}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_5 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_5 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_5 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_5 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_5;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_6");
  if (xm == NULL) {
    /* Attempt to pull B_6 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 5);
  }
  if (xm == NULL) {
    printf("could not find params.B_6 or params.B{6}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_6 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_6 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_6 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_6 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_6;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_7");
  if (xm == NULL) {
    /* Attempt to pull B_7 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 6);
  }
  if (xm == NULL) {
    printf("could not find params.B_7 or params.B{7}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_7 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_7 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_7 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_7 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_7;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_8");
  if (xm == NULL) {
    /* Attempt to pull B_8 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 7);
  }
  if (xm == NULL) {
    printf("could not find params.B_8 or params.B{8}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_8 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_8 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_8 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_8 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_8;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_9");
  if (xm == NULL) {
    /* Attempt to pull B_9 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 8);
  }
  if (xm == NULL) {
    printf("could not find params.B_9 or params.B{9}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_9 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_9 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_9 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_9 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_9;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_10");
  if (xm == NULL) {
    /* Attempt to pull B_10 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 9);
  }
  if (xm == NULL) {
    printf("could not find params.B_10 or params.B{10}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_10 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_10 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_10 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_10 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_10;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_11");
  if (xm == NULL) {
    /* Attempt to pull B_11 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 10);
  }
  if (xm == NULL) {
    printf("could not find params.B_11 or params.B{11}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_11 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_11 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_11 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_11 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_11;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_12");
  if (xm == NULL) {
    /* Attempt to pull B_12 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 11);
  }
  if (xm == NULL) {
    printf("could not find params.B_12 or params.B{12}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_12 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_12 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_12 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_12 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_12;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_13");
  if (xm == NULL) {
    /* Attempt to pull B_13 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 12);
  }
  if (xm == NULL) {
    printf("could not find params.B_13 or params.B{13}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_13 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_13 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_13 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_13 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_13;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_14");
  if (xm == NULL) {
    /* Attempt to pull B_14 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 13);
  }
  if (xm == NULL) {
    printf("could not find params.B_14 or params.B{14}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_14 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_14 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_14 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_14 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_14;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_15");
  if (xm == NULL) {
    /* Attempt to pull B_15 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 14);
  }
  if (xm == NULL) {
    printf("could not find params.B_15 or params.B{15}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_15 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_15 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_15 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_15 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_15;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_16");
  if (xm == NULL) {
    /* Attempt to pull B_16 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 15);
  }
  if (xm == NULL) {
    printf("could not find params.B_16 or params.B{16}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_16 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_16 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_16 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_16 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_16;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_17");
  if (xm == NULL) {
    /* Attempt to pull B_17 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 16);
  }
  if (xm == NULL) {
    printf("could not find params.B_17 or params.B{17}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_17 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_17 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_17 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_17 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_17;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_18");
  if (xm == NULL) {
    /* Attempt to pull B_18 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 17);
  }
  if (xm == NULL) {
    printf("could not find params.B_18 or params.B{18}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_18 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_18 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_18 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_18 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_18;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_19");
  if (xm == NULL) {
    /* Attempt to pull B_19 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 18);
  }
  if (xm == NULL) {
    printf("could not find params.B_19 or params.B{19}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_19 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_19 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_19 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_19 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_19;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_20");
  if (xm == NULL) {
    /* Attempt to pull B_20 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 19);
  }
  if (xm == NULL) {
    printf("could not find params.B_20 or params.B{20}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_20 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_20 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_20 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_20 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_20;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_21");
  if (xm == NULL) {
    /* Attempt to pull B_21 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 20);
  }
  if (xm == NULL) {
    printf("could not find params.B_21 or params.B{21}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_21 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_21 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_21 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_21 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_21;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_22");
  if (xm == NULL) {
    /* Attempt to pull B_22 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 21);
  }
  if (xm == NULL) {
    printf("could not find params.B_22 or params.B{22}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_22 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_22 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_22 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_22 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_22;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_23");
  if (xm == NULL) {
    /* Attempt to pull B_23 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 22);
  }
  if (xm == NULL) {
    printf("could not find params.B_23 or params.B{23}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_23 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_23 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_23 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_23 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_23;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_24");
  if (xm == NULL) {
    /* Attempt to pull B_24 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 23);
  }
  if (xm == NULL) {
    printf("could not find params.B_24 or params.B{24}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_24 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_24 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_24 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_24 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_24;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_25");
  if (xm == NULL) {
    /* Attempt to pull B_25 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 24);
  }
  if (xm == NULL) {
    printf("could not find params.B_25 or params.B{25}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_25 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_25 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_25 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_25 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_25;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_26");
  if (xm == NULL) {
    /* Attempt to pull B_26 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 25);
  }
  if (xm == NULL) {
    printf("could not find params.B_26 or params.B{26}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_26 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_26 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_26 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_26 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_26;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_27");
  if (xm == NULL) {
    /* Attempt to pull B_27 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 26);
  }
  if (xm == NULL) {
    printf("could not find params.B_27 or params.B{27}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_27 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_27 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_27 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_27 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_27;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_28");
  if (xm == NULL) {
    /* Attempt to pull B_28 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 27);
  }
  if (xm == NULL) {
    printf("could not find params.B_28 or params.B{28}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_28 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_28 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_28 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_28 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_28;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_29");
  if (xm == NULL) {
    /* Attempt to pull B_29 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 28);
  }
  if (xm == NULL) {
    printf("could not find params.B_29 or params.B{29}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_29 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_29 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_29 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_29 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_29;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_30");
  if (xm == NULL) {
    /* Attempt to pull B_30 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 29);
  }
  if (xm == NULL) {
    printf("could not find params.B_30 or params.B{30}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_30 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_30 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_30 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_30 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_30;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_31");
  if (xm == NULL) {
    /* Attempt to pull B_31 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 30);
  }
  if (xm == NULL) {
    printf("could not find params.B_31 or params.B{31}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_31 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_31 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_31 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_31 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_31;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_32");
  if (xm == NULL) {
    /* Attempt to pull B_32 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 31);
  }
  if (xm == NULL) {
    printf("could not find params.B_32 or params.B{32}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_32 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_32 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_32 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_32 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_32;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_33");
  if (xm == NULL) {
    /* Attempt to pull B_33 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 32);
  }
  if (xm == NULL) {
    printf("could not find params.B_33 or params.B{33}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_33 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_33 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_33 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_33 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_33;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_34");
  if (xm == NULL) {
    /* Attempt to pull B_34 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 33);
  }
  if (xm == NULL) {
    printf("could not find params.B_34 or params.B{34}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_34 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_34 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_34 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_34 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_34;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_35");
  if (xm == NULL) {
    /* Attempt to pull B_35 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 34);
  }
  if (xm == NULL) {
    printf("could not find params.B_35 or params.B{35}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_35 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_35 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_35 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_35 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_35;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_36");
  if (xm == NULL) {
    /* Attempt to pull B_36 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 35);
  }
  if (xm == NULL) {
    printf("could not find params.B_36 or params.B{36}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_36 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_36 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_36 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_36 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_36;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_37");
  if (xm == NULL) {
    /* Attempt to pull B_37 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 36);
  }
  if (xm == NULL) {
    printf("could not find params.B_37 or params.B{37}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_37 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_37 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_37 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_37 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_37;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_38");
  if (xm == NULL) {
    /* Attempt to pull B_38 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 37);
  }
  if (xm == NULL) {
    printf("could not find params.B_38 or params.B{38}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_38 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_38 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_38 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_38 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_38;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_39");
  if (xm == NULL) {
    /* Attempt to pull B_39 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 38);
  }
  if (xm == NULL) {
    printf("could not find params.B_39 or params.B{39}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_39 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_39 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_39 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_39 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_39;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_40");
  if (xm == NULL) {
    /* Attempt to pull B_40 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 39);
  }
  if (xm == NULL) {
    printf("could not find params.B_40 or params.B{40}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_40 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_40 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_40 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_40 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_40;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_41");
  if (xm == NULL) {
    /* Attempt to pull B_41 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 40);
  }
  if (xm == NULL) {
    printf("could not find params.B_41 or params.B{41}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_41 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_41 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_41 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_41 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_41;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_42");
  if (xm == NULL) {
    /* Attempt to pull B_42 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 41);
  }
  if (xm == NULL) {
    printf("could not find params.B_42 or params.B{42}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_42 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_42 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_42 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_42 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_42;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_43");
  if (xm == NULL) {
    /* Attempt to pull B_43 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 42);
  }
  if (xm == NULL) {
    printf("could not find params.B_43 or params.B{43}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_43 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_43 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_43 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_43 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_43;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_44");
  if (xm == NULL) {
    /* Attempt to pull B_44 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 43);
  }
  if (xm == NULL) {
    printf("could not find params.B_44 or params.B{44}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_44 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_44 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_44 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_44 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_44;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_45");
  if (xm == NULL) {
    /* Attempt to pull B_45 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 44);
  }
  if (xm == NULL) {
    printf("could not find params.B_45 or params.B{45}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_45 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_45 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_45 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_45 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_45;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_46");
  if (xm == NULL) {
    /* Attempt to pull B_46 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 45);
  }
  if (xm == NULL) {
    printf("could not find params.B_46 or params.B{46}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_46 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_46 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_46 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_46 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_46;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_47");
  if (xm == NULL) {
    /* Attempt to pull B_47 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 46);
  }
  if (xm == NULL) {
    printf("could not find params.B_47 or params.B{47}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_47 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_47 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_47 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_47 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_47;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_48");
  if (xm == NULL) {
    /* Attempt to pull B_48 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 47);
  }
  if (xm == NULL) {
    printf("could not find params.B_48 or params.B{48}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_48 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_48 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_48 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_48 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_48;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_49");
  if (xm == NULL) {
    /* Attempt to pull B_49 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 48);
  }
  if (xm == NULL) {
    printf("could not find params.B_49 or params.B{49}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_49 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_49 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_49 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_49 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_49;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "B_50");
  if (xm == NULL) {
    /* Attempt to pull B_50 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "B");
    if (cell != NULL)
      xm = mxGetCell(cell, 49);
  }
  if (xm == NULL) {
    printf("could not find params.B_50 or params.B{50}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("B_50 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter B_50 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter B_50 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter B_50 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.B_50;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "Q");
  if (xm == NULL) {
    printf("could not find params.Q.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("Q must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter Q must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter Q must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter Q must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.Q;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "Q_final");
  if (xm == NULL) {
    printf("could not find params.Q_final.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 3))) {
      printf("Q_final must be size (3,3), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter Q_final must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter Q_final must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter Q_final must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.Q_final;
      src = mxGetPr(xm);
      for (i = 0; i < 9; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "R");
  if (xm == NULL) {
    printf("could not find params.R.\n");
  } else {
    if (!((mxGetM(xm) == 1) && (mxGetN(xm) == 1))) {
      printf("R must be size (1,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter R must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter R must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter R must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.R;
      src = mxGetPr(xm);
      for (i = 0; i < 1; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "Rd");
  if (xm == NULL) {
    printf("could not find params.Rd.\n");
  } else {
    if (!((mxGetM(xm) == 1) && (mxGetN(xm) == 1))) {
      printf("Rd must be size (1,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter Rd must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter Rd must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter Rd must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.Rd;
      src = mxGetPr(xm);
      for (i = 0; i < 1; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_0");
  if (xm == NULL) {
    printf("could not find params.f0_0.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_0 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_0 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_0 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_0 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_0;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_1");
  if (xm == NULL) {
    /* Attempt to pull f0_1 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 0);
  }
  if (xm == NULL) {
    printf("could not find params.f0_1 or params.f0{1}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_1 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_1 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_1 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_1 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_1;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_2");
  if (xm == NULL) {
    /* Attempt to pull f0_2 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 1);
  }
  if (xm == NULL) {
    printf("could not find params.f0_2 or params.f0{2}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_2 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_2 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_2 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_2 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_2;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_3");
  if (xm == NULL) {
    /* Attempt to pull f0_3 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 2);
  }
  if (xm == NULL) {
    printf("could not find params.f0_3 or params.f0{3}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_3 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_3 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_3 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_3 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_3;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_4");
  if (xm == NULL) {
    /* Attempt to pull f0_4 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 3);
  }
  if (xm == NULL) {
    printf("could not find params.f0_4 or params.f0{4}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_4 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_4 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_4 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_4 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_4;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_5");
  if (xm == NULL) {
    /* Attempt to pull f0_5 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 4);
  }
  if (xm == NULL) {
    printf("could not find params.f0_5 or params.f0{5}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_5 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_5 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_5 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_5 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_5;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_6");
  if (xm == NULL) {
    /* Attempt to pull f0_6 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 5);
  }
  if (xm == NULL) {
    printf("could not find params.f0_6 or params.f0{6}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_6 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_6 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_6 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_6 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_6;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_7");
  if (xm == NULL) {
    /* Attempt to pull f0_7 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 6);
  }
  if (xm == NULL) {
    printf("could not find params.f0_7 or params.f0{7}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_7 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_7 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_7 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_7 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_7;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_8");
  if (xm == NULL) {
    /* Attempt to pull f0_8 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 7);
  }
  if (xm == NULL) {
    printf("could not find params.f0_8 or params.f0{8}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_8 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_8 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_8 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_8 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_8;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_9");
  if (xm == NULL) {
    /* Attempt to pull f0_9 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 8);
  }
  if (xm == NULL) {
    printf("could not find params.f0_9 or params.f0{9}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_9 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_9 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_9 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_9 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_9;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_10");
  if (xm == NULL) {
    /* Attempt to pull f0_10 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 9);
  }
  if (xm == NULL) {
    printf("could not find params.f0_10 or params.f0{10}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_10 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_10 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_10 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_10 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_10;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_11");
  if (xm == NULL) {
    /* Attempt to pull f0_11 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 10);
  }
  if (xm == NULL) {
    printf("could not find params.f0_11 or params.f0{11}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_11 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_11 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_11 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_11 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_11;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_12");
  if (xm == NULL) {
    /* Attempt to pull f0_12 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 11);
  }
  if (xm == NULL) {
    printf("could not find params.f0_12 or params.f0{12}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_12 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_12 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_12 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_12 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_12;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_13");
  if (xm == NULL) {
    /* Attempt to pull f0_13 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 12);
  }
  if (xm == NULL) {
    printf("could not find params.f0_13 or params.f0{13}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_13 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_13 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_13 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_13 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_13;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_14");
  if (xm == NULL) {
    /* Attempt to pull f0_14 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 13);
  }
  if (xm == NULL) {
    printf("could not find params.f0_14 or params.f0{14}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_14 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_14 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_14 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_14 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_14;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_15");
  if (xm == NULL) {
    /* Attempt to pull f0_15 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 14);
  }
  if (xm == NULL) {
    printf("could not find params.f0_15 or params.f0{15}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_15 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_15 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_15 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_15 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_15;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_16");
  if (xm == NULL) {
    /* Attempt to pull f0_16 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 15);
  }
  if (xm == NULL) {
    printf("could not find params.f0_16 or params.f0{16}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_16 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_16 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_16 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_16 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_16;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_17");
  if (xm == NULL) {
    /* Attempt to pull f0_17 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 16);
  }
  if (xm == NULL) {
    printf("could not find params.f0_17 or params.f0{17}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_17 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_17 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_17 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_17 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_17;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_18");
  if (xm == NULL) {
    /* Attempt to pull f0_18 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 17);
  }
  if (xm == NULL) {
    printf("could not find params.f0_18 or params.f0{18}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_18 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_18 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_18 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_18 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_18;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_19");
  if (xm == NULL) {
    /* Attempt to pull f0_19 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 18);
  }
  if (xm == NULL) {
    printf("could not find params.f0_19 or params.f0{19}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_19 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_19 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_19 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_19 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_19;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_20");
  if (xm == NULL) {
    /* Attempt to pull f0_20 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 19);
  }
  if (xm == NULL) {
    printf("could not find params.f0_20 or params.f0{20}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_20 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_20 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_20 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_20 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_20;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_21");
  if (xm == NULL) {
    /* Attempt to pull f0_21 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 20);
  }
  if (xm == NULL) {
    printf("could not find params.f0_21 or params.f0{21}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_21 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_21 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_21 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_21 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_21;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_22");
  if (xm == NULL) {
    /* Attempt to pull f0_22 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 21);
  }
  if (xm == NULL) {
    printf("could not find params.f0_22 or params.f0{22}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_22 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_22 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_22 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_22 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_22;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_23");
  if (xm == NULL) {
    /* Attempt to pull f0_23 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 22);
  }
  if (xm == NULL) {
    printf("could not find params.f0_23 or params.f0{23}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_23 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_23 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_23 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_23 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_23;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_24");
  if (xm == NULL) {
    /* Attempt to pull f0_24 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 23);
  }
  if (xm == NULL) {
    printf("could not find params.f0_24 or params.f0{24}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_24 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_24 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_24 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_24 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_24;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_25");
  if (xm == NULL) {
    /* Attempt to pull f0_25 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 24);
  }
  if (xm == NULL) {
    printf("could not find params.f0_25 or params.f0{25}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_25 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_25 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_25 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_25 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_25;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_26");
  if (xm == NULL) {
    /* Attempt to pull f0_26 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 25);
  }
  if (xm == NULL) {
    printf("could not find params.f0_26 or params.f0{26}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_26 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_26 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_26 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_26 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_26;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_27");
  if (xm == NULL) {
    /* Attempt to pull f0_27 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 26);
  }
  if (xm == NULL) {
    printf("could not find params.f0_27 or params.f0{27}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_27 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_27 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_27 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_27 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_27;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_28");
  if (xm == NULL) {
    /* Attempt to pull f0_28 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 27);
  }
  if (xm == NULL) {
    printf("could not find params.f0_28 or params.f0{28}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_28 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_28 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_28 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_28 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_28;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_29");
  if (xm == NULL) {
    /* Attempt to pull f0_29 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 28);
  }
  if (xm == NULL) {
    printf("could not find params.f0_29 or params.f0{29}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_29 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_29 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_29 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_29 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_29;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_30");
  if (xm == NULL) {
    /* Attempt to pull f0_30 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 29);
  }
  if (xm == NULL) {
    printf("could not find params.f0_30 or params.f0{30}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_30 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_30 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_30 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_30 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_30;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_31");
  if (xm == NULL) {
    /* Attempt to pull f0_31 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 30);
  }
  if (xm == NULL) {
    printf("could not find params.f0_31 or params.f0{31}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_31 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_31 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_31 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_31 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_31;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_32");
  if (xm == NULL) {
    /* Attempt to pull f0_32 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 31);
  }
  if (xm == NULL) {
    printf("could not find params.f0_32 or params.f0{32}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_32 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_32 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_32 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_32 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_32;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_33");
  if (xm == NULL) {
    /* Attempt to pull f0_33 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 32);
  }
  if (xm == NULL) {
    printf("could not find params.f0_33 or params.f0{33}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_33 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_33 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_33 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_33 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_33;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_34");
  if (xm == NULL) {
    /* Attempt to pull f0_34 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 33);
  }
  if (xm == NULL) {
    printf("could not find params.f0_34 or params.f0{34}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_34 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_34 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_34 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_34 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_34;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_35");
  if (xm == NULL) {
    /* Attempt to pull f0_35 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 34);
  }
  if (xm == NULL) {
    printf("could not find params.f0_35 or params.f0{35}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_35 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_35 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_35 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_35 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_35;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_36");
  if (xm == NULL) {
    /* Attempt to pull f0_36 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 35);
  }
  if (xm == NULL) {
    printf("could not find params.f0_36 or params.f0{36}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_36 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_36 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_36 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_36 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_36;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_37");
  if (xm == NULL) {
    /* Attempt to pull f0_37 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 36);
  }
  if (xm == NULL) {
    printf("could not find params.f0_37 or params.f0{37}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_37 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_37 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_37 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_37 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_37;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_38");
  if (xm == NULL) {
    /* Attempt to pull f0_38 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 37);
  }
  if (xm == NULL) {
    printf("could not find params.f0_38 or params.f0{38}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_38 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_38 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_38 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_38 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_38;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_39");
  if (xm == NULL) {
    /* Attempt to pull f0_39 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 38);
  }
  if (xm == NULL) {
    printf("could not find params.f0_39 or params.f0{39}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_39 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_39 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_39 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_39 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_39;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_40");
  if (xm == NULL) {
    /* Attempt to pull f0_40 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 39);
  }
  if (xm == NULL) {
    printf("could not find params.f0_40 or params.f0{40}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_40 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_40 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_40 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_40 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_40;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_41");
  if (xm == NULL) {
    /* Attempt to pull f0_41 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 40);
  }
  if (xm == NULL) {
    printf("could not find params.f0_41 or params.f0{41}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_41 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_41 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_41 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_41 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_41;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_42");
  if (xm == NULL) {
    /* Attempt to pull f0_42 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 41);
  }
  if (xm == NULL) {
    printf("could not find params.f0_42 or params.f0{42}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_42 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_42 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_42 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_42 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_42;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_43");
  if (xm == NULL) {
    /* Attempt to pull f0_43 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 42);
  }
  if (xm == NULL) {
    printf("could not find params.f0_43 or params.f0{43}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_43 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_43 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_43 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_43 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_43;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_44");
  if (xm == NULL) {
    /* Attempt to pull f0_44 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 43);
  }
  if (xm == NULL) {
    printf("could not find params.f0_44 or params.f0{44}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_44 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_44 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_44 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_44 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_44;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_45");
  if (xm == NULL) {
    /* Attempt to pull f0_45 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 44);
  }
  if (xm == NULL) {
    printf("could not find params.f0_45 or params.f0{45}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_45 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_45 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_45 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_45 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_45;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_46");
  if (xm == NULL) {
    /* Attempt to pull f0_46 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 45);
  }
  if (xm == NULL) {
    printf("could not find params.f0_46 or params.f0{46}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_46 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_46 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_46 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_46 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_46;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_47");
  if (xm == NULL) {
    /* Attempt to pull f0_47 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 46);
  }
  if (xm == NULL) {
    printf("could not find params.f0_47 or params.f0{47}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_47 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_47 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_47 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_47 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_47;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_48");
  if (xm == NULL) {
    /* Attempt to pull f0_48 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 47);
  }
  if (xm == NULL) {
    printf("could not find params.f0_48 or params.f0{48}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_48 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_48 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_48 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_48 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_48;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_49");
  if (xm == NULL) {
    /* Attempt to pull f0_49 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 48);
  }
  if (xm == NULL) {
    printf("could not find params.f0_49 or params.f0{49}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_49 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_49 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_49 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_49 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_49;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "f0_50");
  if (xm == NULL) {
    /* Attempt to pull f0_50 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "f0");
    if (cell != NULL)
      xm = mxGetCell(cell, 49);
  }
  if (xm == NULL) {
    printf("could not find params.f0_50 or params.f0{50}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("f0_50 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter f0_50 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter f0_50 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter f0_50 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.f0_50;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "u_max");
  if (xm == NULL) {
    printf("could not find params.u_max.\n");
  } else {
    if (!((mxGetM(xm) == 1) && (mxGetN(xm) == 1))) {
      printf("u_max must be size (1,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter u_max must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter u_max must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter u_max must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.u_max;
      src = mxGetPr(xm);
      for (i = 0; i < 1; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "u_min");
  if (xm == NULL) {
    printf("could not find params.u_min.\n");
  } else {
    if (!((mxGetM(xm) == 1) && (mxGetN(xm) == 1))) {
      printf("u_min must be size (1,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter u_min must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter u_min must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter u_min must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.u_min;
      src = mxGetPr(xm);
      for (i = 0; i < 1; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "x_0");
  if (xm == NULL) {
    printf("could not find params.x_0.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("x_0 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter x_0 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter x_0 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter x_0 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.x_0;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_0");
  if (xm == NULL) {
    printf("could not find params.xe_0.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_0 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_0 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_0 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_0 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_0;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_1");
  if (xm == NULL) {
    /* Attempt to pull xe_1 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 0);
  }
  if (xm == NULL) {
    printf("could not find params.xe_1 or params.xe{1}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_1 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_1 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_1 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_1 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_1;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_2");
  if (xm == NULL) {
    /* Attempt to pull xe_2 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 1);
  }
  if (xm == NULL) {
    printf("could not find params.xe_2 or params.xe{2}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_2 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_2 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_2 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_2 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_2;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_3");
  if (xm == NULL) {
    /* Attempt to pull xe_3 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 2);
  }
  if (xm == NULL) {
    printf("could not find params.xe_3 or params.xe{3}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_3 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_3 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_3 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_3 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_3;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_4");
  if (xm == NULL) {
    /* Attempt to pull xe_4 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 3);
  }
  if (xm == NULL) {
    printf("could not find params.xe_4 or params.xe{4}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_4 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_4 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_4 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_4 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_4;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_5");
  if (xm == NULL) {
    /* Attempt to pull xe_5 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 4);
  }
  if (xm == NULL) {
    printf("could not find params.xe_5 or params.xe{5}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_5 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_5 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_5 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_5 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_5;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_6");
  if (xm == NULL) {
    /* Attempt to pull xe_6 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 5);
  }
  if (xm == NULL) {
    printf("could not find params.xe_6 or params.xe{6}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_6 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_6 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_6 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_6 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_6;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_7");
  if (xm == NULL) {
    /* Attempt to pull xe_7 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 6);
  }
  if (xm == NULL) {
    printf("could not find params.xe_7 or params.xe{7}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_7 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_7 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_7 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_7 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_7;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_8");
  if (xm == NULL) {
    /* Attempt to pull xe_8 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 7);
  }
  if (xm == NULL) {
    printf("could not find params.xe_8 or params.xe{8}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_8 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_8 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_8 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_8 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_8;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_9");
  if (xm == NULL) {
    /* Attempt to pull xe_9 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 8);
  }
  if (xm == NULL) {
    printf("could not find params.xe_9 or params.xe{9}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_9 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_9 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_9 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_9 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_9;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_10");
  if (xm == NULL) {
    /* Attempt to pull xe_10 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 9);
  }
  if (xm == NULL) {
    printf("could not find params.xe_10 or params.xe{10}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_10 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_10 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_10 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_10 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_10;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_11");
  if (xm == NULL) {
    /* Attempt to pull xe_11 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 10);
  }
  if (xm == NULL) {
    printf("could not find params.xe_11 or params.xe{11}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_11 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_11 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_11 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_11 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_11;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_12");
  if (xm == NULL) {
    /* Attempt to pull xe_12 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 11);
  }
  if (xm == NULL) {
    printf("could not find params.xe_12 or params.xe{12}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_12 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_12 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_12 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_12 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_12;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_13");
  if (xm == NULL) {
    /* Attempt to pull xe_13 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 12);
  }
  if (xm == NULL) {
    printf("could not find params.xe_13 or params.xe{13}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_13 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_13 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_13 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_13 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_13;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_14");
  if (xm == NULL) {
    /* Attempt to pull xe_14 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 13);
  }
  if (xm == NULL) {
    printf("could not find params.xe_14 or params.xe{14}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_14 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_14 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_14 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_14 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_14;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_15");
  if (xm == NULL) {
    /* Attempt to pull xe_15 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 14);
  }
  if (xm == NULL) {
    printf("could not find params.xe_15 or params.xe{15}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_15 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_15 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_15 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_15 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_15;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_16");
  if (xm == NULL) {
    /* Attempt to pull xe_16 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 15);
  }
  if (xm == NULL) {
    printf("could not find params.xe_16 or params.xe{16}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_16 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_16 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_16 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_16 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_16;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_17");
  if (xm == NULL) {
    /* Attempt to pull xe_17 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 16);
  }
  if (xm == NULL) {
    printf("could not find params.xe_17 or params.xe{17}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_17 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_17 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_17 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_17 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_17;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_18");
  if (xm == NULL) {
    /* Attempt to pull xe_18 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 17);
  }
  if (xm == NULL) {
    printf("could not find params.xe_18 or params.xe{18}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_18 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_18 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_18 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_18 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_18;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_19");
  if (xm == NULL) {
    /* Attempt to pull xe_19 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 18);
  }
  if (xm == NULL) {
    printf("could not find params.xe_19 or params.xe{19}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_19 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_19 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_19 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_19 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_19;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_20");
  if (xm == NULL) {
    /* Attempt to pull xe_20 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 19);
  }
  if (xm == NULL) {
    printf("could not find params.xe_20 or params.xe{20}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_20 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_20 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_20 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_20 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_20;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_21");
  if (xm == NULL) {
    /* Attempt to pull xe_21 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 20);
  }
  if (xm == NULL) {
    printf("could not find params.xe_21 or params.xe{21}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_21 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_21 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_21 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_21 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_21;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_22");
  if (xm == NULL) {
    /* Attempt to pull xe_22 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 21);
  }
  if (xm == NULL) {
    printf("could not find params.xe_22 or params.xe{22}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_22 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_22 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_22 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_22 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_22;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_23");
  if (xm == NULL) {
    /* Attempt to pull xe_23 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 22);
  }
  if (xm == NULL) {
    printf("could not find params.xe_23 or params.xe{23}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_23 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_23 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_23 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_23 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_23;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_24");
  if (xm == NULL) {
    /* Attempt to pull xe_24 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 23);
  }
  if (xm == NULL) {
    printf("could not find params.xe_24 or params.xe{24}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_24 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_24 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_24 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_24 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_24;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_25");
  if (xm == NULL) {
    /* Attempt to pull xe_25 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 24);
  }
  if (xm == NULL) {
    printf("could not find params.xe_25 or params.xe{25}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_25 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_25 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_25 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_25 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_25;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_26");
  if (xm == NULL) {
    /* Attempt to pull xe_26 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 25);
  }
  if (xm == NULL) {
    printf("could not find params.xe_26 or params.xe{26}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_26 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_26 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_26 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_26 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_26;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_27");
  if (xm == NULL) {
    /* Attempt to pull xe_27 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 26);
  }
  if (xm == NULL) {
    printf("could not find params.xe_27 or params.xe{27}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_27 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_27 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_27 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_27 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_27;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_28");
  if (xm == NULL) {
    /* Attempt to pull xe_28 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 27);
  }
  if (xm == NULL) {
    printf("could not find params.xe_28 or params.xe{28}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_28 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_28 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_28 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_28 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_28;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_29");
  if (xm == NULL) {
    /* Attempt to pull xe_29 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 28);
  }
  if (xm == NULL) {
    printf("could not find params.xe_29 or params.xe{29}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_29 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_29 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_29 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_29 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_29;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_30");
  if (xm == NULL) {
    /* Attempt to pull xe_30 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 29);
  }
  if (xm == NULL) {
    printf("could not find params.xe_30 or params.xe{30}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_30 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_30 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_30 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_30 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_30;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_31");
  if (xm == NULL) {
    /* Attempt to pull xe_31 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 30);
  }
  if (xm == NULL) {
    printf("could not find params.xe_31 or params.xe{31}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_31 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_31 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_31 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_31 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_31;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_32");
  if (xm == NULL) {
    /* Attempt to pull xe_32 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 31);
  }
  if (xm == NULL) {
    printf("could not find params.xe_32 or params.xe{32}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_32 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_32 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_32 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_32 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_32;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_33");
  if (xm == NULL) {
    /* Attempt to pull xe_33 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 32);
  }
  if (xm == NULL) {
    printf("could not find params.xe_33 or params.xe{33}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_33 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_33 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_33 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_33 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_33;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_34");
  if (xm == NULL) {
    /* Attempt to pull xe_34 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 33);
  }
  if (xm == NULL) {
    printf("could not find params.xe_34 or params.xe{34}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_34 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_34 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_34 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_34 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_34;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_35");
  if (xm == NULL) {
    /* Attempt to pull xe_35 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 34);
  }
  if (xm == NULL) {
    printf("could not find params.xe_35 or params.xe{35}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_35 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_35 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_35 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_35 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_35;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_36");
  if (xm == NULL) {
    /* Attempt to pull xe_36 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 35);
  }
  if (xm == NULL) {
    printf("could not find params.xe_36 or params.xe{36}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_36 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_36 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_36 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_36 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_36;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_37");
  if (xm == NULL) {
    /* Attempt to pull xe_37 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 36);
  }
  if (xm == NULL) {
    printf("could not find params.xe_37 or params.xe{37}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_37 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_37 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_37 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_37 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_37;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_38");
  if (xm == NULL) {
    /* Attempt to pull xe_38 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 37);
  }
  if (xm == NULL) {
    printf("could not find params.xe_38 or params.xe{38}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_38 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_38 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_38 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_38 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_38;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_39");
  if (xm == NULL) {
    /* Attempt to pull xe_39 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 38);
  }
  if (xm == NULL) {
    printf("could not find params.xe_39 or params.xe{39}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_39 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_39 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_39 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_39 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_39;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_40");
  if (xm == NULL) {
    /* Attempt to pull xe_40 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 39);
  }
  if (xm == NULL) {
    printf("could not find params.xe_40 or params.xe{40}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_40 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_40 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_40 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_40 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_40;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_41");
  if (xm == NULL) {
    /* Attempt to pull xe_41 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 40);
  }
  if (xm == NULL) {
    printf("could not find params.xe_41 or params.xe{41}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_41 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_41 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_41 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_41 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_41;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_42");
  if (xm == NULL) {
    /* Attempt to pull xe_42 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 41);
  }
  if (xm == NULL) {
    printf("could not find params.xe_42 or params.xe{42}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_42 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_42 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_42 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_42 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_42;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_43");
  if (xm == NULL) {
    /* Attempt to pull xe_43 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 42);
  }
  if (xm == NULL) {
    printf("could not find params.xe_43 or params.xe{43}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_43 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_43 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_43 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_43 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_43;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_44");
  if (xm == NULL) {
    /* Attempt to pull xe_44 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 43);
  }
  if (xm == NULL) {
    printf("could not find params.xe_44 or params.xe{44}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_44 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_44 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_44 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_44 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_44;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_45");
  if (xm == NULL) {
    /* Attempt to pull xe_45 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 44);
  }
  if (xm == NULL) {
    printf("could not find params.xe_45 or params.xe{45}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_45 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_45 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_45 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_45 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_45;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_46");
  if (xm == NULL) {
    /* Attempt to pull xe_46 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 45);
  }
  if (xm == NULL) {
    printf("could not find params.xe_46 or params.xe{46}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_46 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_46 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_46 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_46 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_46;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_47");
  if (xm == NULL) {
    /* Attempt to pull xe_47 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 46);
  }
  if (xm == NULL) {
    printf("could not find params.xe_47 or params.xe{47}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_47 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_47 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_47 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_47 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_47;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_48");
  if (xm == NULL) {
    /* Attempt to pull xe_48 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 47);
  }
  if (xm == NULL) {
    printf("could not find params.xe_48 or params.xe{48}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_48 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_48 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_48 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_48 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_48;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_49");
  if (xm == NULL) {
    /* Attempt to pull xe_49 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 48);
  }
  if (xm == NULL) {
    printf("could not find params.xe_49 or params.xe{49}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_49 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_49 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_49 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_49 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_49;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_50");
  if (xm == NULL) {
    /* Attempt to pull xe_50 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 49);
  }
  if (xm == NULL) {
    printf("could not find params.xe_50 or params.xe{50}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_50 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_50 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_50 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_50 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_50;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  this_var_errors = 0;
  xm = mxGetField(prhs[0], 0, "xe_51");
  if (xm == NULL) {
    /* Attempt to pull xe_51 from a cell array, as an additional option. */
    cell = mxGetField(prhs[0], 0, "xe");
    if (cell != NULL)
      xm = mxGetCell(cell, 50);
  }
  if (xm == NULL) {
    printf("could not find params.xe_51 or params.xe{51}.\n");
  } else {
    if (!((mxGetM(xm) == 3) && (mxGetN(xm) == 1))) {
      printf("xe_51 must be size (3,1), not (%d,%d).\n", mxGetM(xm), mxGetN(xm));
      this_var_errors++;
    }
    if (mxIsComplex(xm)) {
      printf("parameter xe_51 must be real.\n");
      this_var_errors++;
    }
    if (!mxIsClass(xm, "double")) {
      printf("parameter xe_51 must be a full matrix of doubles.\n");
      this_var_errors++;
    }
    if (mxIsSparse(xm)) {
      printf("parameter xe_51 must be a full matrix.\n");
      this_var_errors++;
    }
    if (this_var_errors == 0) {
      dest = params.xe_51;
      src = mxGetPr(xm);
      for (i = 0; i < 3; i++)
        *dest++ = *src++;
      valid_vars++;
    }
  }
  if (valid_vars != 212) {
    printf("Error: %d parameters are invalid.\n", 212 - valid_vars);
    mexErrMsgTxt("invalid parameters found.");
  }
  if (prepare_for_c) {
    printf("settings.prepare_for_c == 1. thus, outputting for C.\n");
    for (i = 0; i < 3; i++)
      printf("  params.x_0[%d] = %.6g;\n", i, params.x_0[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_0[%d] = %.6g;\n", i, params.xe_0[i]);
    for (i = 0; i < 9; i++)
      printf("  params.Q[%d] = %.6g;\n", i, params.Q[i]);
    for (i = 0; i < 1; i++)
      printf("  params.R[%d] = %.6g;\n", i, params.R[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_1[%d] = %.6g;\n", i, params.xe_1[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_2[%d] = %.6g;\n", i, params.xe_2[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_3[%d] = %.6g;\n", i, params.xe_3[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_4[%d] = %.6g;\n", i, params.xe_4[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_5[%d] = %.6g;\n", i, params.xe_5[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_6[%d] = %.6g;\n", i, params.xe_6[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_7[%d] = %.6g;\n", i, params.xe_7[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_8[%d] = %.6g;\n", i, params.xe_8[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_9[%d] = %.6g;\n", i, params.xe_9[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_10[%d] = %.6g;\n", i, params.xe_10[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_11[%d] = %.6g;\n", i, params.xe_11[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_12[%d] = %.6g;\n", i, params.xe_12[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_13[%d] = %.6g;\n", i, params.xe_13[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_14[%d] = %.6g;\n", i, params.xe_14[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_15[%d] = %.6g;\n", i, params.xe_15[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_16[%d] = %.6g;\n", i, params.xe_16[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_17[%d] = %.6g;\n", i, params.xe_17[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_18[%d] = %.6g;\n", i, params.xe_18[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_19[%d] = %.6g;\n", i, params.xe_19[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_20[%d] = %.6g;\n", i, params.xe_20[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_21[%d] = %.6g;\n", i, params.xe_21[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_22[%d] = %.6g;\n", i, params.xe_22[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_23[%d] = %.6g;\n", i, params.xe_23[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_24[%d] = %.6g;\n", i, params.xe_24[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_25[%d] = %.6g;\n", i, params.xe_25[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_26[%d] = %.6g;\n", i, params.xe_26[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_27[%d] = %.6g;\n", i, params.xe_27[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_28[%d] = %.6g;\n", i, params.xe_28[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_29[%d] = %.6g;\n", i, params.xe_29[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_30[%d] = %.6g;\n", i, params.xe_30[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_31[%d] = %.6g;\n", i, params.xe_31[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_32[%d] = %.6g;\n", i, params.xe_32[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_33[%d] = %.6g;\n", i, params.xe_33[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_34[%d] = %.6g;\n", i, params.xe_34[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_35[%d] = %.6g;\n", i, params.xe_35[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_36[%d] = %.6g;\n", i, params.xe_36[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_37[%d] = %.6g;\n", i, params.xe_37[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_38[%d] = %.6g;\n", i, params.xe_38[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_39[%d] = %.6g;\n", i, params.xe_39[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_40[%d] = %.6g;\n", i, params.xe_40[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_41[%d] = %.6g;\n", i, params.xe_41[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_42[%d] = %.6g;\n", i, params.xe_42[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_43[%d] = %.6g;\n", i, params.xe_43[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_44[%d] = %.6g;\n", i, params.xe_44[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_45[%d] = %.6g;\n", i, params.xe_45[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_46[%d] = %.6g;\n", i, params.xe_46[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_47[%d] = %.6g;\n", i, params.xe_47[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_48[%d] = %.6g;\n", i, params.xe_48[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_49[%d] = %.6g;\n", i, params.xe_49[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_50[%d] = %.6g;\n", i, params.xe_50[i]);
    for (i = 0; i < 3; i++)
      printf("  params.xe_51[%d] = %.6g;\n", i, params.xe_51[i]);
    for (i = 0; i < 9; i++)
      printf("  params.Q_final[%d] = %.6g;\n", i, params.Q_final[i]);
    for (i = 0; i < 1; i++)
      printf("  params.Rd[%d] = %.6g;\n", i, params.Rd[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_0[%d] = %.6g;\n", i, params.A_0[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_0[%d] = %.6g;\n", i, params.B_0[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_0[%d] = %.6g;\n", i, params.f0_0[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_1[%d] = %.6g;\n", i, params.A_1[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_1[%d] = %.6g;\n", i, params.B_1[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_1[%d] = %.6g;\n", i, params.f0_1[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_2[%d] = %.6g;\n", i, params.A_2[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_2[%d] = %.6g;\n", i, params.B_2[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_2[%d] = %.6g;\n", i, params.f0_2[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_3[%d] = %.6g;\n", i, params.A_3[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_3[%d] = %.6g;\n", i, params.B_3[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_3[%d] = %.6g;\n", i, params.f0_3[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_4[%d] = %.6g;\n", i, params.A_4[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_4[%d] = %.6g;\n", i, params.B_4[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_4[%d] = %.6g;\n", i, params.f0_4[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_5[%d] = %.6g;\n", i, params.A_5[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_5[%d] = %.6g;\n", i, params.B_5[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_5[%d] = %.6g;\n", i, params.f0_5[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_6[%d] = %.6g;\n", i, params.A_6[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_6[%d] = %.6g;\n", i, params.B_6[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_6[%d] = %.6g;\n", i, params.f0_6[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_7[%d] = %.6g;\n", i, params.A_7[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_7[%d] = %.6g;\n", i, params.B_7[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_7[%d] = %.6g;\n", i, params.f0_7[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_8[%d] = %.6g;\n", i, params.A_8[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_8[%d] = %.6g;\n", i, params.B_8[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_8[%d] = %.6g;\n", i, params.f0_8[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_9[%d] = %.6g;\n", i, params.A_9[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_9[%d] = %.6g;\n", i, params.B_9[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_9[%d] = %.6g;\n", i, params.f0_9[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_10[%d] = %.6g;\n", i, params.A_10[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_10[%d] = %.6g;\n", i, params.B_10[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_10[%d] = %.6g;\n", i, params.f0_10[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_11[%d] = %.6g;\n", i, params.A_11[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_11[%d] = %.6g;\n", i, params.B_11[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_11[%d] = %.6g;\n", i, params.f0_11[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_12[%d] = %.6g;\n", i, params.A_12[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_12[%d] = %.6g;\n", i, params.B_12[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_12[%d] = %.6g;\n", i, params.f0_12[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_13[%d] = %.6g;\n", i, params.A_13[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_13[%d] = %.6g;\n", i, params.B_13[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_13[%d] = %.6g;\n", i, params.f0_13[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_14[%d] = %.6g;\n", i, params.A_14[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_14[%d] = %.6g;\n", i, params.B_14[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_14[%d] = %.6g;\n", i, params.f0_14[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_15[%d] = %.6g;\n", i, params.A_15[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_15[%d] = %.6g;\n", i, params.B_15[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_15[%d] = %.6g;\n", i, params.f0_15[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_16[%d] = %.6g;\n", i, params.A_16[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_16[%d] = %.6g;\n", i, params.B_16[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_16[%d] = %.6g;\n", i, params.f0_16[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_17[%d] = %.6g;\n", i, params.A_17[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_17[%d] = %.6g;\n", i, params.B_17[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_17[%d] = %.6g;\n", i, params.f0_17[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_18[%d] = %.6g;\n", i, params.A_18[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_18[%d] = %.6g;\n", i, params.B_18[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_18[%d] = %.6g;\n", i, params.f0_18[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_19[%d] = %.6g;\n", i, params.A_19[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_19[%d] = %.6g;\n", i, params.B_19[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_19[%d] = %.6g;\n", i, params.f0_19[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_20[%d] = %.6g;\n", i, params.A_20[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_20[%d] = %.6g;\n", i, params.B_20[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_20[%d] = %.6g;\n", i, params.f0_20[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_21[%d] = %.6g;\n", i, params.A_21[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_21[%d] = %.6g;\n", i, params.B_21[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_21[%d] = %.6g;\n", i, params.f0_21[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_22[%d] = %.6g;\n", i, params.A_22[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_22[%d] = %.6g;\n", i, params.B_22[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_22[%d] = %.6g;\n", i, params.f0_22[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_23[%d] = %.6g;\n", i, params.A_23[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_23[%d] = %.6g;\n", i, params.B_23[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_23[%d] = %.6g;\n", i, params.f0_23[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_24[%d] = %.6g;\n", i, params.A_24[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_24[%d] = %.6g;\n", i, params.B_24[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_24[%d] = %.6g;\n", i, params.f0_24[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_25[%d] = %.6g;\n", i, params.A_25[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_25[%d] = %.6g;\n", i, params.B_25[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_25[%d] = %.6g;\n", i, params.f0_25[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_26[%d] = %.6g;\n", i, params.A_26[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_26[%d] = %.6g;\n", i, params.B_26[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_26[%d] = %.6g;\n", i, params.f0_26[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_27[%d] = %.6g;\n", i, params.A_27[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_27[%d] = %.6g;\n", i, params.B_27[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_27[%d] = %.6g;\n", i, params.f0_27[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_28[%d] = %.6g;\n", i, params.A_28[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_28[%d] = %.6g;\n", i, params.B_28[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_28[%d] = %.6g;\n", i, params.f0_28[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_29[%d] = %.6g;\n", i, params.A_29[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_29[%d] = %.6g;\n", i, params.B_29[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_29[%d] = %.6g;\n", i, params.f0_29[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_30[%d] = %.6g;\n", i, params.A_30[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_30[%d] = %.6g;\n", i, params.B_30[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_30[%d] = %.6g;\n", i, params.f0_30[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_31[%d] = %.6g;\n", i, params.A_31[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_31[%d] = %.6g;\n", i, params.B_31[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_31[%d] = %.6g;\n", i, params.f0_31[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_32[%d] = %.6g;\n", i, params.A_32[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_32[%d] = %.6g;\n", i, params.B_32[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_32[%d] = %.6g;\n", i, params.f0_32[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_33[%d] = %.6g;\n", i, params.A_33[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_33[%d] = %.6g;\n", i, params.B_33[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_33[%d] = %.6g;\n", i, params.f0_33[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_34[%d] = %.6g;\n", i, params.A_34[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_34[%d] = %.6g;\n", i, params.B_34[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_34[%d] = %.6g;\n", i, params.f0_34[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_35[%d] = %.6g;\n", i, params.A_35[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_35[%d] = %.6g;\n", i, params.B_35[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_35[%d] = %.6g;\n", i, params.f0_35[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_36[%d] = %.6g;\n", i, params.A_36[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_36[%d] = %.6g;\n", i, params.B_36[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_36[%d] = %.6g;\n", i, params.f0_36[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_37[%d] = %.6g;\n", i, params.A_37[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_37[%d] = %.6g;\n", i, params.B_37[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_37[%d] = %.6g;\n", i, params.f0_37[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_38[%d] = %.6g;\n", i, params.A_38[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_38[%d] = %.6g;\n", i, params.B_38[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_38[%d] = %.6g;\n", i, params.f0_38[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_39[%d] = %.6g;\n", i, params.A_39[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_39[%d] = %.6g;\n", i, params.B_39[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_39[%d] = %.6g;\n", i, params.f0_39[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_40[%d] = %.6g;\n", i, params.A_40[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_40[%d] = %.6g;\n", i, params.B_40[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_40[%d] = %.6g;\n", i, params.f0_40[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_41[%d] = %.6g;\n", i, params.A_41[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_41[%d] = %.6g;\n", i, params.B_41[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_41[%d] = %.6g;\n", i, params.f0_41[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_42[%d] = %.6g;\n", i, params.A_42[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_42[%d] = %.6g;\n", i, params.B_42[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_42[%d] = %.6g;\n", i, params.f0_42[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_43[%d] = %.6g;\n", i, params.A_43[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_43[%d] = %.6g;\n", i, params.B_43[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_43[%d] = %.6g;\n", i, params.f0_43[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_44[%d] = %.6g;\n", i, params.A_44[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_44[%d] = %.6g;\n", i, params.B_44[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_44[%d] = %.6g;\n", i, params.f0_44[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_45[%d] = %.6g;\n", i, params.A_45[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_45[%d] = %.6g;\n", i, params.B_45[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_45[%d] = %.6g;\n", i, params.f0_45[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_46[%d] = %.6g;\n", i, params.A_46[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_46[%d] = %.6g;\n", i, params.B_46[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_46[%d] = %.6g;\n", i, params.f0_46[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_47[%d] = %.6g;\n", i, params.A_47[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_47[%d] = %.6g;\n", i, params.B_47[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_47[%d] = %.6g;\n", i, params.f0_47[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_48[%d] = %.6g;\n", i, params.A_48[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_48[%d] = %.6g;\n", i, params.B_48[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_48[%d] = %.6g;\n", i, params.f0_48[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_49[%d] = %.6g;\n", i, params.A_49[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_49[%d] = %.6g;\n", i, params.B_49[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_49[%d] = %.6g;\n", i, params.f0_49[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_50[%d] = %.6g;\n", i, params.A_50[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_50[%d] = %.6g;\n", i, params.B_50[i]);
    for (i = 0; i < 3; i++)
      printf("  params.f0_50[%d] = %.6g;\n", i, params.f0_50[i]);
    for (i = 0; i < 1; i++)
      printf("  params.u_min[%d] = %.6g;\n", i, params.u_min[i]);
    for (i = 0; i < 1; i++)
      printf("  params.u_max[%d] = %.6g;\n", i, params.u_max[i]);
  }
  /* Perform the actual solve in here. */
  steps = solve();
  /* For profiling purposes, allow extra silent solves if desired. */
  settings.verbose = 0;
  for (i = 0; i < extra_solves; i++)
    solve();
  /* Update the status variables. */
  plhs[1] = mxCreateStructArray(1, dims1x1of1, 4, status_names);
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[1], 0, "optval", xm);
  *mxGetPr(xm) = work.optval;
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[1], 0, "gap", xm);
  *mxGetPr(xm) = work.gap;
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[1], 0, "steps", xm);
  *mxGetPr(xm) = steps;
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[1], 0, "converged", xm);
  *mxGetPr(xm) = work.converged;
  /* Extract variable values. */
  plhs[0] = mxCreateStructArray(1, dims1x1of1, num_var_names, var_names);
  /* Create cell arrays for indexed variables. */
  dims[0] = 50;
  cell = mxCreateCellArray(1, dims);
  mxSetField(plhs[0], 0, "u", cell);
  dims[0] = 51;
  cell = mxCreateCellArray(1, dims);
  mxSetField(plhs[0], 0, "x", cell);
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_0", xm);
  dest = mxGetPr(xm);
  src = vars.u_0;
  for (i = 0; i < 1; i++) {
    *dest++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_1", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 0, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_1;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_2", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 1, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_2;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_3", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 2, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_3;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_4", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 3, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_4;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_5", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 4, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_5;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_6", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 5, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_6;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_7", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 6, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_7;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_8", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 7, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_8;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_9", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 8, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_9;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_10", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 9, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_10;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_11", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 10, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_11;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_12", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 11, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_12;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_13", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 12, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_13;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_14", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 13, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_14;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_15", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 14, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_15;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_16", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 15, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_16;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_17", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 16, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_17;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_18", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 17, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_18;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_19", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 18, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_19;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_20", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 19, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_20;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_21", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 20, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_21;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_22", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 21, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_22;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_23", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 22, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_23;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_24", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 23, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_24;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_25", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 24, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_25;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_26", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 25, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_26;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_27", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 26, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_27;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_28", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 27, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_28;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_29", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 28, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_29;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_30", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 29, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_30;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_31", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 30, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_31;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_32", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 31, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_32;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_33", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 32, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_33;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_34", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 33, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_34;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_35", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 34, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_35;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_36", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 35, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_36;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_37", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 36, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_37;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_38", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 37, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_38;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_39", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 38, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_39;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_40", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 39, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_40;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_41", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 40, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_41;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_42", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 41, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_42;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_43", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 42, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_43;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_44", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 43, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_44;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_45", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 44, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_45;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_46", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 45, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_46;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_47", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 46, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_47;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_48", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 47, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_48;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_49", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 48, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_49;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(1, 1, mxREAL);
  mxSetField(plhs[0], 0, "u_50", xm);
  xm_cell = mxCreateDoubleMatrix(1, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "u");
  mxSetCell(cell, 49, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.u_50;
  for (i = 0; i < 1; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_1", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 0, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_1;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_2", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 1, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_2;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_3", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 2, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_3;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_4", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 3, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_4;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_5", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 4, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_5;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_6", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 5, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_6;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_7", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 6, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_7;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_8", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 7, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_8;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_9", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 8, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_9;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_10", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 9, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_10;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_11", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 10, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_11;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_12", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 11, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_12;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_13", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 12, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_13;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_14", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 13, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_14;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_15", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 14, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_15;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_16", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 15, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_16;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_17", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 16, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_17;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_18", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 17, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_18;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_19", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 18, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_19;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_20", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 19, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_20;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_21", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 20, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_21;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_22", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 21, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_22;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_23", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 22, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_23;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_24", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 23, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_24;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_25", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 24, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_25;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_26", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 25, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_26;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_27", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 26, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_27;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_28", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 27, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_28;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_29", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 28, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_29;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_30", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 29, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_30;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_31", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 30, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_31;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_32", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 31, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_32;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_33", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 32, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_33;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_34", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 33, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_34;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_35", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 34, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_35;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_36", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 35, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_36;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_37", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 36, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_37;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_38", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 37, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_38;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_39", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 38, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_39;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_40", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 39, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_40;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_41", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 40, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_41;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_42", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 41, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_42;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_43", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 42, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_43;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_44", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 43, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_44;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_45", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 44, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_45;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_46", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 45, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_46;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_47", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 46, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_47;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_48", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 47, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_48;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_49", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 48, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_49;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_50", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 49, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_50;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
  xm = mxCreateDoubleMatrix(3, 1, mxREAL);
  mxSetField(plhs[0], 0, "x_51", xm);
  xm_cell = mxCreateDoubleMatrix(3, 1, mxREAL);
  cell = mxGetField(plhs[0], 0, "x");
  mxSetCell(cell, 50, xm_cell);
  dest = mxGetPr(xm);
  dest_cell = mxGetPr(xm_cell);
  src = vars.x_51;
  for (i = 0; i < 3; i++) {
    *dest++ = *src;
    *dest_cell++ = *src++;
  }
}
