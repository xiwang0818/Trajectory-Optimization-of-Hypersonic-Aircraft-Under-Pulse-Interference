/* Produced by CVXGEN, 2017-04-25 21:53:09 -0400.  */
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
  const char *var_names[] = {"u_0", "u_1", "u_2", "u_3", "u_4", "u_5", "u_6", "u_7", "u_8", "u_9", "u_10", "x_1", "x_2", "x_3", "x_4", "x_5", "x_6", "x_7", "x_8", "x_9", "x_10", "x_11", "u", "x"};
  const int num_var_names = 24;
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
  if (valid_vars != 41) {
    printf("Error: %d parameters are invalid.\n", 41 - valid_vars);
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
    for (i = 0; i < 9; i++)
      printf("  params.Q_final[%d] = %.6g;\n", i, params.Q_final[i]);
    for (i = 0; i < 1; i++)
      printf("  params.Rd[%d] = %.6g;\n", i, params.Rd[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_0[%d] = %.6g;\n", i, params.A_0[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_0[%d] = %.6g;\n", i, params.B_0[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_1[%d] = %.6g;\n", i, params.A_1[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_1[%d] = %.6g;\n", i, params.B_1[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_2[%d] = %.6g;\n", i, params.A_2[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_2[%d] = %.6g;\n", i, params.B_2[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_3[%d] = %.6g;\n", i, params.A_3[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_3[%d] = %.6g;\n", i, params.B_3[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_4[%d] = %.6g;\n", i, params.A_4[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_4[%d] = %.6g;\n", i, params.B_4[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_5[%d] = %.6g;\n", i, params.A_5[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_5[%d] = %.6g;\n", i, params.B_5[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_6[%d] = %.6g;\n", i, params.A_6[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_6[%d] = %.6g;\n", i, params.B_6[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_7[%d] = %.6g;\n", i, params.A_7[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_7[%d] = %.6g;\n", i, params.B_7[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_8[%d] = %.6g;\n", i, params.A_8[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_8[%d] = %.6g;\n", i, params.B_8[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_9[%d] = %.6g;\n", i, params.A_9[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_9[%d] = %.6g;\n", i, params.B_9[i]);
    for (i = 0; i < 9; i++)
      printf("  params.A_10[%d] = %.6g;\n", i, params.A_10[i]);
    for (i = 0; i < 3; i++)
      printf("  params.B_10[%d] = %.6g;\n", i, params.B_10[i]);
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
  dims[0] = 10;
  cell = mxCreateCellArray(1, dims);
  mxSetField(plhs[0], 0, "u", cell);
  dims[0] = 11;
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
}
