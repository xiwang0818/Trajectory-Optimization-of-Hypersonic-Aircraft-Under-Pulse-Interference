/* Produced by CVXGEN, 2017-06-14 01:00:20 -0400.  */
/* CVXGEN is Copyright (C) 2006-2012 Jacob Mattingley, jem@cvxgen.com. */
/* The code in this file is Copyright (C) 2006-2012 Jacob Mattingley. */
/* CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial */
/* applications without prior written permission from Jacob Mattingley. */

/* Filename: solver.c. */
/* Description: Main solver file. */
#include "solver.h"
double eval_gap(void) {
  int i;
  double gap;
  gap = 0;
  for (i = 0; i < 102; i++)
    gap += work.z[i]*work.s[i];
  return gap;
}
void set_defaults(void) {
  settings.resid_tol = 1e-6;
  settings.eps = 1e-4;
  settings.max_iters = 25;
  settings.refine_steps = 1;
  settings.s_init = 1;
  settings.z_init = 1;
  settings.debug = 0;
  settings.verbose = 1;
  settings.verbose_refinement = 0;
  settings.better_start = 1;
  settings.kkt_reg = 1e-7;
}
void setup_pointers(void) {
  work.y = work.x + 254;
  work.s = work.x + 457;
  work.z = work.x + 559;
  vars.u_0 = work.x + 50;
  vars.u_1 = work.x + 51;
  vars.u_2 = work.x + 52;
  vars.u_3 = work.x + 53;
  vars.u_4 = work.x + 54;
  vars.u_5 = work.x + 55;
  vars.u_6 = work.x + 56;
  vars.u_7 = work.x + 57;
  vars.u_8 = work.x + 58;
  vars.u_9 = work.x + 59;
  vars.u_10 = work.x + 60;
  vars.u_11 = work.x + 61;
  vars.u_12 = work.x + 62;
  vars.u_13 = work.x + 63;
  vars.u_14 = work.x + 64;
  vars.u_15 = work.x + 65;
  vars.u_16 = work.x + 66;
  vars.u_17 = work.x + 67;
  vars.u_18 = work.x + 68;
  vars.u_19 = work.x + 69;
  vars.u_20 = work.x + 70;
  vars.u_21 = work.x + 71;
  vars.u_22 = work.x + 72;
  vars.u_23 = work.x + 73;
  vars.u_24 = work.x + 74;
  vars.u_25 = work.x + 75;
  vars.u_26 = work.x + 76;
  vars.u_27 = work.x + 77;
  vars.u_28 = work.x + 78;
  vars.u_29 = work.x + 79;
  vars.u_30 = work.x + 80;
  vars.u_31 = work.x + 81;
  vars.u_32 = work.x + 82;
  vars.u_33 = work.x + 83;
  vars.u_34 = work.x + 84;
  vars.u_35 = work.x + 85;
  vars.u_36 = work.x + 86;
  vars.u_37 = work.x + 87;
  vars.u_38 = work.x + 88;
  vars.u_39 = work.x + 89;
  vars.u_40 = work.x + 90;
  vars.u_41 = work.x + 91;
  vars.u_42 = work.x + 92;
  vars.u_43 = work.x + 93;
  vars.u_44 = work.x + 94;
  vars.u_45 = work.x + 95;
  vars.u_46 = work.x + 96;
  vars.u_47 = work.x + 97;
  vars.u_48 = work.x + 98;
  vars.u_49 = work.x + 99;
  vars.u_50 = work.x + 100;
  vars.x_1 = work.x + 101;
  vars.x_2 = work.x + 104;
  vars.x_3 = work.x + 107;
  vars.x_4 = work.x + 110;
  vars.x_5 = work.x + 113;
  vars.x_6 = work.x + 116;
  vars.x_7 = work.x + 119;
  vars.x_8 = work.x + 122;
  vars.x_9 = work.x + 125;
  vars.x_10 = work.x + 128;
  vars.x_11 = work.x + 131;
  vars.x_12 = work.x + 134;
  vars.x_13 = work.x + 137;
  vars.x_14 = work.x + 140;
  vars.x_15 = work.x + 143;
  vars.x_16 = work.x + 146;
  vars.x_17 = work.x + 149;
  vars.x_18 = work.x + 152;
  vars.x_19 = work.x + 155;
  vars.x_20 = work.x + 158;
  vars.x_21 = work.x + 161;
  vars.x_22 = work.x + 164;
  vars.x_23 = work.x + 167;
  vars.x_24 = work.x + 170;
  vars.x_25 = work.x + 173;
  vars.x_26 = work.x + 176;
  vars.x_27 = work.x + 179;
  vars.x_28 = work.x + 182;
  vars.x_29 = work.x + 185;
  vars.x_30 = work.x + 188;
  vars.x_31 = work.x + 191;
  vars.x_32 = work.x + 194;
  vars.x_33 = work.x + 197;
  vars.x_34 = work.x + 200;
  vars.x_35 = work.x + 203;
  vars.x_36 = work.x + 206;
  vars.x_37 = work.x + 209;
  vars.x_38 = work.x + 212;
  vars.x_39 = work.x + 215;
  vars.x_40 = work.x + 218;
  vars.x_41 = work.x + 221;
  vars.x_42 = work.x + 224;
  vars.x_43 = work.x + 227;
  vars.x_44 = work.x + 230;
  vars.x_45 = work.x + 233;
  vars.x_46 = work.x + 236;
  vars.x_47 = work.x + 239;
  vars.x_48 = work.x + 242;
  vars.x_49 = work.x + 245;
  vars.x_50 = work.x + 248;
  vars.x_51 = work.x + 251;
}
void setup_indexed_params(void) {
  /* In CVXGEN, you can say */
  /*   parameters */
  /*     A[i] (5,3), i=1..4 */
  /*   end */
  /* This function sets up A[2] to be a pointer to A_2, which is a length-15 */
  /* vector of doubles. */
  /* If you access parameters that you haven't defined in CVXGEN, the result */
  /* is undefined. */
  params.x[0] = params.x_0;
  params.xe[0] = params.xe_0;
  params.xe[1] = params.xe_1;
  params.xe[2] = params.xe_2;
  params.xe[3] = params.xe_3;
  params.xe[4] = params.xe_4;
  params.xe[5] = params.xe_5;
  params.xe[6] = params.xe_6;
  params.xe[7] = params.xe_7;
  params.xe[8] = params.xe_8;
  params.xe[9] = params.xe_9;
  params.xe[10] = params.xe_10;
  params.xe[11] = params.xe_11;
  params.xe[12] = params.xe_12;
  params.xe[13] = params.xe_13;
  params.xe[14] = params.xe_14;
  params.xe[15] = params.xe_15;
  params.xe[16] = params.xe_16;
  params.xe[17] = params.xe_17;
  params.xe[18] = params.xe_18;
  params.xe[19] = params.xe_19;
  params.xe[20] = params.xe_20;
  params.xe[21] = params.xe_21;
  params.xe[22] = params.xe_22;
  params.xe[23] = params.xe_23;
  params.xe[24] = params.xe_24;
  params.xe[25] = params.xe_25;
  params.xe[26] = params.xe_26;
  params.xe[27] = params.xe_27;
  params.xe[28] = params.xe_28;
  params.xe[29] = params.xe_29;
  params.xe[30] = params.xe_30;
  params.xe[31] = params.xe_31;
  params.xe[32] = params.xe_32;
  params.xe[33] = params.xe_33;
  params.xe[34] = params.xe_34;
  params.xe[35] = params.xe_35;
  params.xe[36] = params.xe_36;
  params.xe[37] = params.xe_37;
  params.xe[38] = params.xe_38;
  params.xe[39] = params.xe_39;
  params.xe[40] = params.xe_40;
  params.xe[41] = params.xe_41;
  params.xe[42] = params.xe_42;
  params.xe[43] = params.xe_43;
  params.xe[44] = params.xe_44;
  params.xe[45] = params.xe_45;
  params.xe[46] = params.xe_46;
  params.xe[47] = params.xe_47;
  params.xe[48] = params.xe_48;
  params.xe[49] = params.xe_49;
  params.xe[50] = params.xe_50;
  params.xe[51] = params.xe_51;
  params.A[0] = params.A_0;
  params.B[0] = params.B_0;
  params.f0[0] = params.f0_0;
  params.A[1] = params.A_1;
  params.B[1] = params.B_1;
  params.f0[1] = params.f0_1;
  params.A[2] = params.A_2;
  params.B[2] = params.B_2;
  params.f0[2] = params.f0_2;
  params.A[3] = params.A_3;
  params.B[3] = params.B_3;
  params.f0[3] = params.f0_3;
  params.A[4] = params.A_4;
  params.B[4] = params.B_4;
  params.f0[4] = params.f0_4;
  params.A[5] = params.A_5;
  params.B[5] = params.B_5;
  params.f0[5] = params.f0_5;
  params.A[6] = params.A_6;
  params.B[6] = params.B_6;
  params.f0[6] = params.f0_6;
  params.A[7] = params.A_7;
  params.B[7] = params.B_7;
  params.f0[7] = params.f0_7;
  params.A[8] = params.A_8;
  params.B[8] = params.B_8;
  params.f0[8] = params.f0_8;
  params.A[9] = params.A_9;
  params.B[9] = params.B_9;
  params.f0[9] = params.f0_9;
  params.A[10] = params.A_10;
  params.B[10] = params.B_10;
  params.f0[10] = params.f0_10;
  params.A[11] = params.A_11;
  params.B[11] = params.B_11;
  params.f0[11] = params.f0_11;
  params.A[12] = params.A_12;
  params.B[12] = params.B_12;
  params.f0[12] = params.f0_12;
  params.A[13] = params.A_13;
  params.B[13] = params.B_13;
  params.f0[13] = params.f0_13;
  params.A[14] = params.A_14;
  params.B[14] = params.B_14;
  params.f0[14] = params.f0_14;
  params.A[15] = params.A_15;
  params.B[15] = params.B_15;
  params.f0[15] = params.f0_15;
  params.A[16] = params.A_16;
  params.B[16] = params.B_16;
  params.f0[16] = params.f0_16;
  params.A[17] = params.A_17;
  params.B[17] = params.B_17;
  params.f0[17] = params.f0_17;
  params.A[18] = params.A_18;
  params.B[18] = params.B_18;
  params.f0[18] = params.f0_18;
  params.A[19] = params.A_19;
  params.B[19] = params.B_19;
  params.f0[19] = params.f0_19;
  params.A[20] = params.A_20;
  params.B[20] = params.B_20;
  params.f0[20] = params.f0_20;
  params.A[21] = params.A_21;
  params.B[21] = params.B_21;
  params.f0[21] = params.f0_21;
  params.A[22] = params.A_22;
  params.B[22] = params.B_22;
  params.f0[22] = params.f0_22;
  params.A[23] = params.A_23;
  params.B[23] = params.B_23;
  params.f0[23] = params.f0_23;
  params.A[24] = params.A_24;
  params.B[24] = params.B_24;
  params.f0[24] = params.f0_24;
  params.A[25] = params.A_25;
  params.B[25] = params.B_25;
  params.f0[25] = params.f0_25;
  params.A[26] = params.A_26;
  params.B[26] = params.B_26;
  params.f0[26] = params.f0_26;
  params.A[27] = params.A_27;
  params.B[27] = params.B_27;
  params.f0[27] = params.f0_27;
  params.A[28] = params.A_28;
  params.B[28] = params.B_28;
  params.f0[28] = params.f0_28;
  params.A[29] = params.A_29;
  params.B[29] = params.B_29;
  params.f0[29] = params.f0_29;
  params.A[30] = params.A_30;
  params.B[30] = params.B_30;
  params.f0[30] = params.f0_30;
  params.A[31] = params.A_31;
  params.B[31] = params.B_31;
  params.f0[31] = params.f0_31;
  params.A[32] = params.A_32;
  params.B[32] = params.B_32;
  params.f0[32] = params.f0_32;
  params.A[33] = params.A_33;
  params.B[33] = params.B_33;
  params.f0[33] = params.f0_33;
  params.A[34] = params.A_34;
  params.B[34] = params.B_34;
  params.f0[34] = params.f0_34;
  params.A[35] = params.A_35;
  params.B[35] = params.B_35;
  params.f0[35] = params.f0_35;
  params.A[36] = params.A_36;
  params.B[36] = params.B_36;
  params.f0[36] = params.f0_36;
  params.A[37] = params.A_37;
  params.B[37] = params.B_37;
  params.f0[37] = params.f0_37;
  params.A[38] = params.A_38;
  params.B[38] = params.B_38;
  params.f0[38] = params.f0_38;
  params.A[39] = params.A_39;
  params.B[39] = params.B_39;
  params.f0[39] = params.f0_39;
  params.A[40] = params.A_40;
  params.B[40] = params.B_40;
  params.f0[40] = params.f0_40;
  params.A[41] = params.A_41;
  params.B[41] = params.B_41;
  params.f0[41] = params.f0_41;
  params.A[42] = params.A_42;
  params.B[42] = params.B_42;
  params.f0[42] = params.f0_42;
  params.A[43] = params.A_43;
  params.B[43] = params.B_43;
  params.f0[43] = params.f0_43;
  params.A[44] = params.A_44;
  params.B[44] = params.B_44;
  params.f0[44] = params.f0_44;
  params.A[45] = params.A_45;
  params.B[45] = params.B_45;
  params.f0[45] = params.f0_45;
  params.A[46] = params.A_46;
  params.B[46] = params.B_46;
  params.f0[46] = params.f0_46;
  params.A[47] = params.A_47;
  params.B[47] = params.B_47;
  params.f0[47] = params.f0_47;
  params.A[48] = params.A_48;
  params.B[48] = params.B_48;
  params.f0[48] = params.f0_48;
  params.A[49] = params.A_49;
  params.B[49] = params.B_49;
  params.f0[49] = params.f0_49;
  params.A[50] = params.A_50;
  params.B[50] = params.B_50;
  params.f0[50] = params.f0_50;
}
void setup_indexed_optvars(void) {
  /* In CVXGEN, you can say */
  /*   variables */
  /*     x[i] (5), i=2..4 */
  /*   end */
  /* This function sets up x[3] to be a pointer to x_3, which is a length-5 */
  /* vector of doubles. */
  /* If you access variables that you haven't defined in CVXGEN, the result */
  /* is undefined. */
  vars.u[0] = vars.u_0;
  vars.x[1] = vars.x_1;
  vars.u[1] = vars.u_1;
  vars.x[2] = vars.x_2;
  vars.u[2] = vars.u_2;
  vars.x[3] = vars.x_3;
  vars.u[3] = vars.u_3;
  vars.x[4] = vars.x_4;
  vars.u[4] = vars.u_4;
  vars.x[5] = vars.x_5;
  vars.u[5] = vars.u_5;
  vars.x[6] = vars.x_6;
  vars.u[6] = vars.u_6;
  vars.x[7] = vars.x_7;
  vars.u[7] = vars.u_7;
  vars.x[8] = vars.x_8;
  vars.u[8] = vars.u_8;
  vars.x[9] = vars.x_9;
  vars.u[9] = vars.u_9;
  vars.x[10] = vars.x_10;
  vars.u[10] = vars.u_10;
  vars.x[11] = vars.x_11;
  vars.u[11] = vars.u_11;
  vars.x[12] = vars.x_12;
  vars.u[12] = vars.u_12;
  vars.x[13] = vars.x_13;
  vars.u[13] = vars.u_13;
  vars.x[14] = vars.x_14;
  vars.u[14] = vars.u_14;
  vars.x[15] = vars.x_15;
  vars.u[15] = vars.u_15;
  vars.x[16] = vars.x_16;
  vars.u[16] = vars.u_16;
  vars.x[17] = vars.x_17;
  vars.u[17] = vars.u_17;
  vars.x[18] = vars.x_18;
  vars.u[18] = vars.u_18;
  vars.x[19] = vars.x_19;
  vars.u[19] = vars.u_19;
  vars.x[20] = vars.x_20;
  vars.u[20] = vars.u_20;
  vars.x[21] = vars.x_21;
  vars.u[21] = vars.u_21;
  vars.x[22] = vars.x_22;
  vars.u[22] = vars.u_22;
  vars.x[23] = vars.x_23;
  vars.u[23] = vars.u_23;
  vars.x[24] = vars.x_24;
  vars.u[24] = vars.u_24;
  vars.x[25] = vars.x_25;
  vars.u[25] = vars.u_25;
  vars.x[26] = vars.x_26;
  vars.u[26] = vars.u_26;
  vars.x[27] = vars.x_27;
  vars.u[27] = vars.u_27;
  vars.x[28] = vars.x_28;
  vars.u[28] = vars.u_28;
  vars.x[29] = vars.x_29;
  vars.u[29] = vars.u_29;
  vars.x[30] = vars.x_30;
  vars.u[30] = vars.u_30;
  vars.x[31] = vars.x_31;
  vars.u[31] = vars.u_31;
  vars.x[32] = vars.x_32;
  vars.u[32] = vars.u_32;
  vars.x[33] = vars.x_33;
  vars.u[33] = vars.u_33;
  vars.x[34] = vars.x_34;
  vars.u[34] = vars.u_34;
  vars.x[35] = vars.x_35;
  vars.u[35] = vars.u_35;
  vars.x[36] = vars.x_36;
  vars.u[36] = vars.u_36;
  vars.x[37] = vars.x_37;
  vars.u[37] = vars.u_37;
  vars.x[38] = vars.x_38;
  vars.u[38] = vars.u_38;
  vars.x[39] = vars.x_39;
  vars.u[39] = vars.u_39;
  vars.x[40] = vars.x_40;
  vars.u[40] = vars.u_40;
  vars.x[41] = vars.x_41;
  vars.u[41] = vars.u_41;
  vars.x[42] = vars.x_42;
  vars.u[42] = vars.u_42;
  vars.x[43] = vars.x_43;
  vars.u[43] = vars.u_43;
  vars.x[44] = vars.x_44;
  vars.u[44] = vars.u_44;
  vars.x[45] = vars.x_45;
  vars.u[45] = vars.u_45;
  vars.x[46] = vars.x_46;
  vars.u[46] = vars.u_46;
  vars.x[47] = vars.x_47;
  vars.u[47] = vars.u_47;
  vars.x[48] = vars.x_48;
  vars.u[48] = vars.u_48;
  vars.x[49] = vars.x_49;
  vars.u[49] = vars.u_49;
  vars.x[50] = vars.x_50;
  vars.u[50] = vars.u_50;
  vars.x[51] = vars.x_51;
}
void setup_indexing(void) {
  setup_pointers();
  setup_indexed_params();
  setup_indexed_optvars();
}
void set_start(void) {
  int i;
  for (i = 0; i < 254; i++)
    work.x[i] = 0;
  for (i = 0; i < 203; i++)
    work.y[i] = 0;
  for (i = 0; i < 102; i++)
    work.s[i] = (work.h[i] > 0) ? work.h[i] : settings.s_init;
  for (i = 0; i < 102; i++)
    work.z[i] = settings.z_init;
}
double eval_objv(void) {
  int i;
  double objv;
  /* Borrow space in work.rhs. */
  multbyP(work.rhs, work.x);
  objv = 0;
  for (i = 0; i < 254; i++)
    objv += work.x[i]*work.rhs[i];
  objv *= 0.5;
  for (i = 0; i < 254; i++)
    objv += work.q[i]*work.x[i];
  objv += work.quad_641805803520[0]+work.quad_423815467008[0]+work.quad_713451630592[0]+work.quad_558480441344[0]+work.quad_53182197760[0]+work.quad_690109157376[0]+work.quad_307941638144[0]+work.quad_709715156992[0]+work.quad_130251710464[0]+work.quad_55484551168[0]+work.quad_888851320832[0]+work.quad_16934739968[0]+work.quad_366156496896[0]+work.quad_903167664128[0]+work.quad_94211928064[0]+work.quad_906191552512[0]+work.quad_204402315264[0]+work.quad_107308544000[0]+work.quad_665239408640[0]+work.quad_590505107456[0]+work.quad_521915838464[0]+work.quad_805029249024[0]+work.quad_501711880192[0]+work.quad_489800986624[0]+work.quad_504476749824[0]+work.quad_268001808384[0]+work.quad_588448862208[0]+work.quad_909800046592[0]+work.quad_89403891712[0]+work.quad_809956282368[0]+work.quad_979173351424[0]+work.quad_201859977216[0]+work.quad_678285099008[0]+work.quad_955469410304[0]+work.quad_275013197824[0]+work.quad_395912531968[0]+work.quad_678601420800[0]+work.quad_800438898688[0]+work.quad_851903152128[0]+work.quad_52813090816[0]+work.quad_780911804416[0]+work.quad_99588780032[0]+work.quad_243188109312[0]+work.quad_397260767232[0]+work.quad_248949084160[0]+work.quad_583808462848[0]+work.quad_35856556032[0]+work.quad_734023659520[0]+work.quad_73594830848[0]+work.quad_112548880384[0]+work.quad_10423115776[0]+work.quad_65166344192[0];
  return objv;
}
void fillrhs_aff(void) {
  int i;
  double *r1, *r2, *r3, *r4;
  r1 = work.rhs;
  r2 = work.rhs + 254;
  r3 = work.rhs + 356;
  r4 = work.rhs + 458;
  /* r1 = -A^Ty - G^Tz - Px - q. */
  multbymAT(r1, work.y);
  multbymGT(work.buffer, work.z);
  for (i = 0; i < 254; i++)
    r1[i] += work.buffer[i];
  multbyP(work.buffer, work.x);
  for (i = 0; i < 254; i++)
    r1[i] -= work.buffer[i] + work.q[i];
  /* r2 = -z. */
  for (i = 0; i < 102; i++)
    r2[i] = -work.z[i];
  /* r3 = -Gx - s + h. */
  multbymG(r3, work.x);
  for (i = 0; i < 102; i++)
    r3[i] += -work.s[i] + work.h[i];
  /* r4 = -Ax + b. */
  multbymA(r4, work.x);
  for (i = 0; i < 203; i++)
    r4[i] += work.b[i];
}
void fillrhs_cc(void) {
  int i;
  double *r2;
  double *ds_aff, *dz_aff;
  double mu;
  double alpha;
  double sigma;
  double smu;
  double minval;
  r2 = work.rhs + 254;
  ds_aff = work.lhs_aff + 254;
  dz_aff = work.lhs_aff + 356;
  mu = 0;
  for (i = 0; i < 102; i++)
    mu += work.s[i]*work.z[i];
  /* Don't finish calculating mu quite yet. */
  /* Find min(min(ds./s), min(dz./z)). */
  minval = 0;
  for (i = 0; i < 102; i++)
    if (ds_aff[i] < minval*work.s[i])
      minval = ds_aff[i]/work.s[i];
  for (i = 0; i < 102; i++)
    if (dz_aff[i] < minval*work.z[i])
      minval = dz_aff[i]/work.z[i];
  /* Find alpha. */
  if (-1 < minval)
      alpha = 1;
  else
      alpha = -1/minval;
  sigma = 0;
  for (i = 0; i < 102; i++)
    sigma += (work.s[i] + alpha*ds_aff[i])*
      (work.z[i] + alpha*dz_aff[i]);
  sigma /= mu;
  sigma = sigma*sigma*sigma;
  /* Finish calculating mu now. */
  mu *= 0.00980392156862745;
  smu = sigma*mu;
  /* Fill-in the rhs. */
  for (i = 0; i < 254; i++)
    work.rhs[i] = 0;
  for (i = 356; i < 661; i++)
    work.rhs[i] = 0;
  for (i = 0; i < 102; i++)
    r2[i] = work.s_inv[i]*(smu - ds_aff[i]*dz_aff[i]);
}
void refine(double *target, double *var) {
  int i, j;
  double *residual = work.buffer;
  double norm2;
  double *new_var = work.buffer2;
  for (j = 0; j < settings.refine_steps; j++) {
    norm2 = 0;
    matrix_multiply(residual, var);
    for (i = 0; i < 661; i++) {
      residual[i] = residual[i] - target[i];
      norm2 += residual[i]*residual[i];
    }
#ifndef ZERO_LIBRARY_MODE
    if (settings.verbose_refinement) {
      if (j == 0)
        printf("Initial residual before refinement has norm squared %.6g.\n", norm2);
      else
        printf("After refinement we get squared norm %.6g.\n", norm2);
    }
#endif
    /* Solve to find new_var = KKT \ (target - A*var). */
    ldl_solve(residual, new_var);
    /* Update var += new_var, or var += KKT \ (target - A*var). */
    for (i = 0; i < 661; i++) {
      var[i] -= new_var[i];
    }
  }
#ifndef ZERO_LIBRARY_MODE
  if (settings.verbose_refinement) {
    /* Check the residual once more, but only if we're reporting it, since */
    /* it's expensive. */
    norm2 = 0;
    matrix_multiply(residual, var);
    for (i = 0; i < 661; i++) {
      residual[i] = residual[i] - target[i];
      norm2 += residual[i]*residual[i];
    }
    if (j == 0)
      printf("Initial residual before refinement has norm squared %.6g.\n", norm2);
    else
      printf("After refinement we get squared norm %.6g.\n", norm2);
  }
#endif
}
double calc_ineq_resid_squared(void) {
  /* Calculates the norm ||-Gx - s + h||. */
  double norm2_squared;
  int i;
  /* Find -Gx. */
  multbymG(work.buffer, work.x);
  /* Add -s + h. */
  for (i = 0; i < 102; i++)
    work.buffer[i] += -work.s[i] + work.h[i];
  /* Now find the squared norm. */
  norm2_squared = 0;
  for (i = 0; i < 102; i++)
    norm2_squared += work.buffer[i]*work.buffer[i];
  return norm2_squared;
}
double calc_eq_resid_squared(void) {
  /* Calculates the norm ||-Ax + b||. */
  double norm2_squared;
  int i;
  /* Find -Ax. */
  multbymA(work.buffer, work.x);
  /* Add +b. */
  for (i = 0; i < 203; i++)
    work.buffer[i] += work.b[i];
  /* Now find the squared norm. */
  norm2_squared = 0;
  for (i = 0; i < 203; i++)
    norm2_squared += work.buffer[i]*work.buffer[i];
  return norm2_squared;
}
void better_start(void) {
  /* Calculates a better starting point, using a similar approach to CVXOPT. */
  /* Not yet speed optimized. */
  int i;
  double *x, *s, *z, *y;
  double alpha;
  work.block_33[0] = -1;
  /* Make sure sinvz is 1 to make hijacked KKT system ok. */
  for (i = 0; i < 102; i++)
    work.s_inv_z[i] = 1;
  fill_KKT();
  ldl_factor();
  fillrhs_start();
  /* Borrow work.lhs_aff for the solution. */
  ldl_solve(work.rhs, work.lhs_aff);
  /* Don't do any refinement for now. Precision doesn't matter too much. */
  x = work.lhs_aff;
  s = work.lhs_aff + 254;
  z = work.lhs_aff + 356;
  y = work.lhs_aff + 458;
  /* Just set x and y as is. */
  for (i = 0; i < 254; i++)
    work.x[i] = x[i];
  for (i = 0; i < 203; i++)
    work.y[i] = y[i];
  /* Now complete the initialization. Start with s. */
  /* Must have alpha > max(z). */
  alpha = -1e99;
  for (i = 0; i < 102; i++)
    if (alpha < z[i])
      alpha = z[i];
  if (alpha < 0) {
    for (i = 0; i < 102; i++)
      work.s[i] = -z[i];
  } else {
    alpha += 1;
    for (i = 0; i < 102; i++)
      work.s[i] = -z[i] + alpha;
  }
  /* Now initialize z. */
  /* Now must have alpha > max(-z). */
  alpha = -1e99;
  for (i = 0; i < 102; i++)
    if (alpha < -z[i])
      alpha = -z[i];
  if (alpha < 0) {
    for (i = 0; i < 102; i++)
      work.z[i] = z[i];
  } else {
    alpha += 1;
    for (i = 0; i < 102; i++)
      work.z[i] = z[i] + alpha;
  }
}
void fillrhs_start(void) {
  /* Fill rhs with (-q, 0, h, b). */
  int i;
  double *r1, *r2, *r3, *r4;
  r1 = work.rhs;
  r2 = work.rhs + 254;
  r3 = work.rhs + 356;
  r4 = work.rhs + 458;
  for (i = 0; i < 254; i++)
    r1[i] = -work.q[i];
  for (i = 0; i < 102; i++)
    r2[i] = 0;
  for (i = 0; i < 102; i++)
    r3[i] = work.h[i];
  for (i = 0; i < 203; i++)
    r4[i] = work.b[i];
}
long solve(void) {
  int i;
  int iter;
  double *dx, *ds, *dy, *dz;
  double minval;
  double alpha;
  work.converged = 0;
  setup_pointers();
  pre_ops();
#ifndef ZERO_LIBRARY_MODE
  if (settings.verbose)
    printf("iter     objv        gap       |Ax-b|    |Gx+s-h|    step\n");
#endif
  fillq();
  fillh();
  fillb();
  if (settings.better_start)
    better_start();
  else
    set_start();
  for (iter = 0; iter < settings.max_iters; iter++) {
    for (i = 0; i < 102; i++) {
      work.s_inv[i] = 1.0 / work.s[i];
      work.s_inv_z[i] = work.s_inv[i]*work.z[i];
    }
    work.block_33[0] = 0;
    fill_KKT();
    ldl_factor();
    /* Affine scaling directions. */
    fillrhs_aff();
    ldl_solve(work.rhs, work.lhs_aff);
    refine(work.rhs, work.lhs_aff);
    /* Centering plus corrector directions. */
    fillrhs_cc();
    ldl_solve(work.rhs, work.lhs_cc);
    refine(work.rhs, work.lhs_cc);
    /* Add the two together and store in aff. */
    for (i = 0; i < 661; i++)
      work.lhs_aff[i] += work.lhs_cc[i];
    /* Rename aff to reflect its new meaning. */
    dx = work.lhs_aff;
    ds = work.lhs_aff + 254;
    dz = work.lhs_aff + 356;
    dy = work.lhs_aff + 458;
    /* Find min(min(ds./s), min(dz./z)). */
    minval = 0;
    for (i = 0; i < 102; i++)
      if (ds[i] < minval*work.s[i])
        minval = ds[i]/work.s[i];
    for (i = 0; i < 102; i++)
      if (dz[i] < minval*work.z[i])
        minval = dz[i]/work.z[i];
    /* Find alpha. */
    if (-0.99 < minval)
      alpha = 1;
    else
      alpha = -0.99/minval;
    /* Update the primal and dual variables. */
    for (i = 0; i < 254; i++)
      work.x[i] += alpha*dx[i];
    for (i = 0; i < 102; i++)
      work.s[i] += alpha*ds[i];
    for (i = 0; i < 102; i++)
      work.z[i] += alpha*dz[i];
    for (i = 0; i < 203; i++)
      work.y[i] += alpha*dy[i];
    work.gap = eval_gap();
    work.eq_resid_squared = calc_eq_resid_squared();
    work.ineq_resid_squared = calc_ineq_resid_squared();
#ifndef ZERO_LIBRARY_MODE
    if (settings.verbose) {
      work.optval = eval_objv();
      printf("%3d   %10.3e  %9.2e  %9.2e  %9.2e  % 6.4f\n",
          iter+1, work.optval, work.gap, sqrt(work.eq_resid_squared),
          sqrt(work.ineq_resid_squared), alpha);
    }
#endif
    /* Test termination conditions. Requires optimality, and satisfied */
    /* constraints. */
    if (   (work.gap < settings.eps)
        && (work.eq_resid_squared <= settings.resid_tol*settings.resid_tol)
        && (work.ineq_resid_squared <= settings.resid_tol*settings.resid_tol)
       ) {
      work.converged = 1;
      work.optval = eval_objv();
      return iter+1;
    }
  }
  return iter;
}
