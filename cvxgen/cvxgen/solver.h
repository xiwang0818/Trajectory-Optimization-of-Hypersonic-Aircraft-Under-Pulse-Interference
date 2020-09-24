/* Produced by CVXGEN, 2017-06-14 01:00:33 -0400.  */
/* CVXGEN is Copyright (C) 2006-2012 Jacob Mattingley, jem@cvxgen.com. */
/* The code in this file is Copyright (C) 2006-2012 Jacob Mattingley. */
/* CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial */
/* applications without prior written permission from Jacob Mattingley. */

/* Filename: solver.h. */
/* Description: Header file with relevant definitions. */
#ifndef SOLVER_H
#define SOLVER_H
/* Uncomment the next line to remove all library dependencies. */
/*#define ZERO_LIBRARY_MODE */
#ifdef MATLAB_MEX_FILE
/* Matlab functions. MATLAB_MEX_FILE will be defined by the mex compiler. */
/* If you are not using the mex compiler, this functionality will not intrude, */
/* as it will be completely disabled at compile-time. */
#include "mex.h"
#else
#ifndef ZERO_LIBRARY_MODE
#include <stdio.h>
#endif
#endif
/* Space must be allocated somewhere (testsolver.c, csolve.c or your own */
/* program) for the global variables vars, params, work and settings. */
/* At the bottom of this file, they are externed. */
#ifndef ZERO_LIBRARY_MODE
#include <math.h>
#define pm(A, m, n) printmatrix(#A, A, m, n, 1)
#endif
typedef struct Params_t {
  double x_0[3];
  double xe_0[3];
  double Q[9];
  double R[1];
  double xe_1[3];
  double xe_2[3];
  double xe_3[3];
  double xe_4[3];
  double xe_5[3];
  double xe_6[3];
  double xe_7[3];
  double xe_8[3];
  double xe_9[3];
  double xe_10[3];
  double xe_11[3];
  double xe_12[3];
  double xe_13[3];
  double xe_14[3];
  double xe_15[3];
  double xe_16[3];
  double xe_17[3];
  double xe_18[3];
  double xe_19[3];
  double xe_20[3];
  double xe_21[3];
  double xe_22[3];
  double xe_23[3];
  double xe_24[3];
  double xe_25[3];
  double xe_26[3];
  double xe_27[3];
  double xe_28[3];
  double xe_29[3];
  double xe_30[3];
  double xe_31[3];
  double xe_32[3];
  double xe_33[3];
  double xe_34[3];
  double xe_35[3];
  double xe_36[3];
  double xe_37[3];
  double xe_38[3];
  double xe_39[3];
  double xe_40[3];
  double xe_41[3];
  double xe_42[3];
  double xe_43[3];
  double xe_44[3];
  double xe_45[3];
  double xe_46[3];
  double xe_47[3];
  double xe_48[3];
  double xe_49[3];
  double xe_50[3];
  double xe_51[3];
  double Q_final[9];
  double Rd[1];
  double A_0[9];
  double B_0[3];
  double f0_0[3];
  double A_1[9];
  double B_1[3];
  double f0_1[3];
  double A_2[9];
  double B_2[3];
  double f0_2[3];
  double A_3[9];
  double B_3[3];
  double f0_3[3];
  double A_4[9];
  double B_4[3];
  double f0_4[3];
  double A_5[9];
  double B_5[3];
  double f0_5[3];
  double A_6[9];
  double B_6[3];
  double f0_6[3];
  double A_7[9];
  double B_7[3];
  double f0_7[3];
  double A_8[9];
  double B_8[3];
  double f0_8[3];
  double A_9[9];
  double B_9[3];
  double f0_9[3];
  double A_10[9];
  double B_10[3];
  double f0_10[3];
  double A_11[9];
  double B_11[3];
  double f0_11[3];
  double A_12[9];
  double B_12[3];
  double f0_12[3];
  double A_13[9];
  double B_13[3];
  double f0_13[3];
  double A_14[9];
  double B_14[3];
  double f0_14[3];
  double A_15[9];
  double B_15[3];
  double f0_15[3];
  double A_16[9];
  double B_16[3];
  double f0_16[3];
  double A_17[9];
  double B_17[3];
  double f0_17[3];
  double A_18[9];
  double B_18[3];
  double f0_18[3];
  double A_19[9];
  double B_19[3];
  double f0_19[3];
  double A_20[9];
  double B_20[3];
  double f0_20[3];
  double A_21[9];
  double B_21[3];
  double f0_21[3];
  double A_22[9];
  double B_22[3];
  double f0_22[3];
  double A_23[9];
  double B_23[3];
  double f0_23[3];
  double A_24[9];
  double B_24[3];
  double f0_24[3];
  double A_25[9];
  double B_25[3];
  double f0_25[3];
  double A_26[9];
  double B_26[3];
  double f0_26[3];
  double A_27[9];
  double B_27[3];
  double f0_27[3];
  double A_28[9];
  double B_28[3];
  double f0_28[3];
  double A_29[9];
  double B_29[3];
  double f0_29[3];
  double A_30[9];
  double B_30[3];
  double f0_30[3];
  double A_31[9];
  double B_31[3];
  double f0_31[3];
  double A_32[9];
  double B_32[3];
  double f0_32[3];
  double A_33[9];
  double B_33[3];
  double f0_33[3];
  double A_34[9];
  double B_34[3];
  double f0_34[3];
  double A_35[9];
  double B_35[3];
  double f0_35[3];
  double A_36[9];
  double B_36[3];
  double f0_36[3];
  double A_37[9];
  double B_37[3];
  double f0_37[3];
  double A_38[9];
  double B_38[3];
  double f0_38[3];
  double A_39[9];
  double B_39[3];
  double f0_39[3];
  double A_40[9];
  double B_40[3];
  double f0_40[3];
  double A_41[9];
  double B_41[3];
  double f0_41[3];
  double A_42[9];
  double B_42[3];
  double f0_42[3];
  double A_43[9];
  double B_43[3];
  double f0_43[3];
  double A_44[9];
  double B_44[3];
  double f0_44[3];
  double A_45[9];
  double B_45[3];
  double f0_45[3];
  double A_46[9];
  double B_46[3];
  double f0_46[3];
  double A_47[9];
  double B_47[3];
  double f0_47[3];
  double A_48[9];
  double B_48[3];
  double f0_48[3];
  double A_49[9];
  double B_49[3];
  double f0_49[3];
  double A_50[9];
  double B_50[3];
  double f0_50[3];
  double u_min[1];
  double u_max[1];
  double *x[1];
  double *xe[52];
  double *A[51];
  double *B[51];
  double *f0[51];
} Params;
typedef struct Vars_t {
  double *u_0; /* 1 rows. */
  double *x_1; /* 3 rows. */
  double *u_1; /* 1 rows. */
  double *x_2; /* 3 rows. */
  double *u_2; /* 1 rows. */
  double *x_3; /* 3 rows. */
  double *u_3; /* 1 rows. */
  double *x_4; /* 3 rows. */
  double *u_4; /* 1 rows. */
  double *x_5; /* 3 rows. */
  double *u_5; /* 1 rows. */
  double *x_6; /* 3 rows. */
  double *u_6; /* 1 rows. */
  double *x_7; /* 3 rows. */
  double *u_7; /* 1 rows. */
  double *x_8; /* 3 rows. */
  double *u_8; /* 1 rows. */
  double *x_9; /* 3 rows. */
  double *u_9; /* 1 rows. */
  double *x_10; /* 3 rows. */
  double *u_10; /* 1 rows. */
  double *x_11; /* 3 rows. */
  double *u_11; /* 1 rows. */
  double *x_12; /* 3 rows. */
  double *u_12; /* 1 rows. */
  double *x_13; /* 3 rows. */
  double *u_13; /* 1 rows. */
  double *x_14; /* 3 rows. */
  double *u_14; /* 1 rows. */
  double *x_15; /* 3 rows. */
  double *u_15; /* 1 rows. */
  double *x_16; /* 3 rows. */
  double *u_16; /* 1 rows. */
  double *x_17; /* 3 rows. */
  double *u_17; /* 1 rows. */
  double *x_18; /* 3 rows. */
  double *u_18; /* 1 rows. */
  double *x_19; /* 3 rows. */
  double *u_19; /* 1 rows. */
  double *x_20; /* 3 rows. */
  double *u_20; /* 1 rows. */
  double *x_21; /* 3 rows. */
  double *u_21; /* 1 rows. */
  double *x_22; /* 3 rows. */
  double *u_22; /* 1 rows. */
  double *x_23; /* 3 rows. */
  double *u_23; /* 1 rows. */
  double *x_24; /* 3 rows. */
  double *u_24; /* 1 rows. */
  double *x_25; /* 3 rows. */
  double *u_25; /* 1 rows. */
  double *x_26; /* 3 rows. */
  double *u_26; /* 1 rows. */
  double *x_27; /* 3 rows. */
  double *u_27; /* 1 rows. */
  double *x_28; /* 3 rows. */
  double *u_28; /* 1 rows. */
  double *x_29; /* 3 rows. */
  double *u_29; /* 1 rows. */
  double *x_30; /* 3 rows. */
  double *u_30; /* 1 rows. */
  double *x_31; /* 3 rows. */
  double *u_31; /* 1 rows. */
  double *x_32; /* 3 rows. */
  double *u_32; /* 1 rows. */
  double *x_33; /* 3 rows. */
  double *u_33; /* 1 rows. */
  double *x_34; /* 3 rows. */
  double *u_34; /* 1 rows. */
  double *x_35; /* 3 rows. */
  double *u_35; /* 1 rows. */
  double *x_36; /* 3 rows. */
  double *u_36; /* 1 rows. */
  double *x_37; /* 3 rows. */
  double *u_37; /* 1 rows. */
  double *x_38; /* 3 rows. */
  double *u_38; /* 1 rows. */
  double *x_39; /* 3 rows. */
  double *u_39; /* 1 rows. */
  double *x_40; /* 3 rows. */
  double *u_40; /* 1 rows. */
  double *x_41; /* 3 rows. */
  double *u_41; /* 1 rows. */
  double *x_42; /* 3 rows. */
  double *u_42; /* 1 rows. */
  double *x_43; /* 3 rows. */
  double *u_43; /* 1 rows. */
  double *x_44; /* 3 rows. */
  double *u_44; /* 1 rows. */
  double *x_45; /* 3 rows. */
  double *u_45; /* 1 rows. */
  double *x_46; /* 3 rows. */
  double *u_46; /* 1 rows. */
  double *x_47; /* 3 rows. */
  double *u_47; /* 1 rows. */
  double *x_48; /* 3 rows. */
  double *u_48; /* 1 rows. */
  double *x_49; /* 3 rows. */
  double *u_49; /* 1 rows. */
  double *x_50; /* 3 rows. */
  double *u_50; /* 1 rows. */
  double *x_51; /* 3 rows. */
  double *t_01; /* 1 rows. */
  double *t_02; /* 1 rows. */
  double *t_03; /* 1 rows. */
  double *t_04; /* 1 rows. */
  double *t_05; /* 1 rows. */
  double *t_06; /* 1 rows. */
  double *t_07; /* 1 rows. */
  double *t_08; /* 1 rows. */
  double *t_09; /* 1 rows. */
  double *t_10; /* 1 rows. */
  double *t_11; /* 1 rows. */
  double *t_12; /* 1 rows. */
  double *t_13; /* 1 rows. */
  double *t_14; /* 1 rows. */
  double *t_15; /* 1 rows. */
  double *t_16; /* 1 rows. */
  double *t_17; /* 1 rows. */
  double *t_18; /* 1 rows. */
  double *t_19; /* 1 rows. */
  double *t_20; /* 1 rows. */
  double *t_21; /* 1 rows. */
  double *t_22; /* 1 rows. */
  double *t_23; /* 1 rows. */
  double *t_24; /* 1 rows. */
  double *t_25; /* 1 rows. */
  double *t_26; /* 1 rows. */
  double *t_27; /* 1 rows. */
  double *t_28; /* 1 rows. */
  double *t_29; /* 1 rows. */
  double *t_30; /* 1 rows. */
  double *t_31; /* 1 rows. */
  double *t_32; /* 1 rows. */
  double *t_33; /* 1 rows. */
  double *t_34; /* 1 rows. */
  double *t_35; /* 1 rows. */
  double *t_36; /* 1 rows. */
  double *t_37; /* 1 rows. */
  double *t_38; /* 1 rows. */
  double *t_39; /* 1 rows. */
  double *t_40; /* 1 rows. */
  double *t_41; /* 1 rows. */
  double *t_42; /* 1 rows. */
  double *t_43; /* 1 rows. */
  double *t_44; /* 1 rows. */
  double *t_45; /* 1 rows. */
  double *t_46; /* 1 rows. */
  double *t_47; /* 1 rows. */
  double *t_48; /* 1 rows. */
  double *t_49; /* 1 rows. */
  double *t_50; /* 1 rows. */
  double *u[51];
  double *x[52];
} Vars;
typedef struct Workspace_t {
  double h[102];
  double s_inv[102];
  double s_inv_z[102];
  double b[203];
  double q[254];
  double rhs[661];
  double x[661];
  double *s;
  double *z;
  double *y;
  double lhs_aff[661];
  double lhs_cc[661];
  double buffer[661];
  double buffer2[661];
  double KKT[1721];
  double L[1913];
  double d[661];
  double v[661];
  double d_inv[661];
  double gap;
  double optval;
  double ineq_resid_squared;
  double eq_resid_squared;
  double block_33[1];
  /* Pre-op symbols. */
  double quad_641805803520[1];
  double quad_423815467008[1];
  double quad_713451630592[1];
  double quad_558480441344[1];
  double quad_53182197760[1];
  double quad_690109157376[1];
  double quad_307941638144[1];
  double quad_709715156992[1];
  double quad_130251710464[1];
  double quad_55484551168[1];
  double quad_888851320832[1];
  double quad_16934739968[1];
  double quad_366156496896[1];
  double quad_903167664128[1];
  double quad_94211928064[1];
  double quad_906191552512[1];
  double quad_204402315264[1];
  double quad_107308544000[1];
  double quad_665239408640[1];
  double quad_590505107456[1];
  double quad_521915838464[1];
  double quad_805029249024[1];
  double quad_501711880192[1];
  double quad_489800986624[1];
  double quad_504476749824[1];
  double quad_268001808384[1];
  double quad_588448862208[1];
  double quad_909800046592[1];
  double quad_89403891712[1];
  double quad_809956282368[1];
  double quad_979173351424[1];
  double quad_201859977216[1];
  double quad_678285099008[1];
  double quad_955469410304[1];
  double quad_275013197824[1];
  double quad_395912531968[1];
  double quad_678601420800[1];
  double quad_800438898688[1];
  double quad_851903152128[1];
  double quad_52813090816[1];
  double quad_780911804416[1];
  double quad_99588780032[1];
  double quad_243188109312[1];
  double quad_397260767232[1];
  double quad_248949084160[1];
  double quad_583808462848[1];
  double quad_35856556032[1];
  double quad_734023659520[1];
  double quad_73594830848[1];
  double quad_112548880384[1];
  double quad_10423115776[1];
  double quad_65166344192[1];
  int converged;
} Workspace;
typedef struct Settings_t {
  double resid_tol;
  double eps;
  int max_iters;
  int refine_steps;
  int better_start;
  /* Better start obviates the need for s_init and z_init. */
  double s_init;
  double z_init;
  int verbose;
  /* Show extra details of the iterative refinement steps. */
  int verbose_refinement;
  int debug;
  /* For regularization. Minimum value of abs(D_ii) in the kkt D factor. */
  double kkt_reg;
} Settings;
extern Vars vars;
extern Params params;
extern Workspace work;
extern Settings settings;
/* Function definitions in ldl.c: */
void ldl_solve(double *target, double *var);
void ldl_factor(void);
double check_factorization(void);
void matrix_multiply(double *result, double *source);
double check_residual(double *target, double *multiplicand);
void fill_KKT(void);

/* Function definitions in matrix_support.c: */
void multbymA(double *lhs, double *rhs);
void multbymAT(double *lhs, double *rhs);
void multbymG(double *lhs, double *rhs);
void multbymGT(double *lhs, double *rhs);
void multbyP(double *lhs, double *rhs);
void fillq(void);
void fillh(void);
void fillb(void);
void pre_ops(void);

/* Function definitions in solver.c: */
double eval_gap(void);
void set_defaults(void);
void setup_pointers(void);
void setup_indexed_params(void);
void setup_indexed_optvars(void);
void setup_indexing(void);
void set_start(void);
double eval_objv(void);
void fillrhs_aff(void);
void fillrhs_cc(void);
void refine(double *target, double *var);
double calc_ineq_resid_squared(void);
double calc_eq_resid_squared(void);
void better_start(void);
void fillrhs_start(void);
long solve(void);

/* Function definitions in testsolver.c: */
int main(int argc, char **argv);
void load_default_data(void);

/* Function definitions in util.c: */
void tic(void);
float toc(void);
float tocq(void);
void printmatrix(char *name, double *A, int m, int n, int sparse);
double unif(double lower, double upper);
float ran1(long*idum, int reset);
float randn_internal(long *idum, int reset);
double randn(void);
void reset_rand(void);

#endif
