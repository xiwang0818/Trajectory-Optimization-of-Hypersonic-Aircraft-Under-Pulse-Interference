% csolve  Solves a custom quadratic program very rapidly.
%
% [vars, status] = csolve(params, settings)
%
% solves the convex optimization problem
%
%   minimize(quad_form(x_0 - xe_0, Q) + quad_form(u_0, R) + quad_form(x_1 - xe_1, Q) + quad_form(u_1, R) + quad_form(x_2 - xe_2, Q) + quad_form(u_2, R) + quad_form(x_3 - xe_3, Q) + quad_form(u_3, R) + quad_form(x_4 - xe_4, Q) + quad_form(u_4, R) + quad_form(x_5 - xe_5, Q) + quad_form(u_5, R) + quad_form(x_6 - xe_6, Q) + quad_form(u_6, R) + quad_form(x_7 - xe_7, Q) + quad_form(u_7, R) + quad_form(x_8 - xe_8, Q) + quad_form(u_8, R) + quad_form(x_9 - xe_9, Q) + quad_form(u_9, R) + quad_form(x_10 - xe_10, Q) + quad_form(u_10, R) + quad_form(x_11 - xe_11, Q) + quad_form(u_11, R) + quad_form(x_12 - xe_12, Q) + quad_form(u_12, R) + quad_form(x_13 - xe_13, Q) + quad_form(u_13, R) + quad_form(x_14 - xe_14, Q) + quad_form(u_14, R) + quad_form(x_15 - xe_15, Q) + quad_form(u_15, R) + quad_form(x_16 - xe_16, Q) + quad_form(u_16, R) + quad_form(x_17 - xe_17, Q) + quad_form(u_17, R) + quad_form(x_18 - xe_18, Q) + quad_form(u_18, R) + quad_form(x_19 - xe_19, Q) + quad_form(u_19, R) + quad_form(x_20 - xe_20, Q) + quad_form(u_20, R) + quad_form(x_21 - xe_21, Q) + quad_form(u_21, R) + quad_form(x_22 - xe_22, Q) + quad_form(u_22, R) + quad_form(x_23 - xe_23, Q) + quad_form(u_23, R) + quad_form(x_24 - xe_24, Q) + quad_form(u_24, R) + quad_form(x_25 - xe_25, Q) + quad_form(u_25, R) + quad_form(x_26 - xe_26, Q) + quad_form(u_26, R) + quad_form(x_27 - xe_27, Q) + quad_form(u_27, R) + quad_form(x_28 - xe_28, Q) + quad_form(u_28, R) + quad_form(x_29 - xe_29, Q) + quad_form(u_29, R) + quad_form(x_30 - xe_30, Q) + quad_form(u_30, R) + quad_form(x_31 - xe_31, Q) + quad_form(u_31, R) + quad_form(x_32 - xe_32, Q) + quad_form(u_32, R) + quad_form(x_33 - xe_33, Q) + quad_form(u_33, R) + quad_form(x_34 - xe_34, Q) + quad_form(u_34, R) + quad_form(x_35 - xe_35, Q) + quad_form(u_35, R) + quad_form(x_36 - xe_36, Q) + quad_form(u_36, R) + quad_form(x_37 - xe_37, Q) + quad_form(u_37, R) + quad_form(x_38 - xe_38, Q) + quad_form(u_38, R) + quad_form(x_39 - xe_39, Q) + quad_form(u_39, R) + quad_form(x_40 - xe_40, Q) + quad_form(u_40, R) + quad_form(x_41 - xe_41, Q) + quad_form(u_41, R) + quad_form(x_42 - xe_42, Q) + quad_form(u_42, R) + quad_form(x_43 - xe_43, Q) + quad_form(u_43, R) + quad_form(x_44 - xe_44, Q) + quad_form(u_44, R) + quad_form(x_45 - xe_45, Q) + quad_form(u_45, R) + quad_form(x_46 - xe_46, Q) + quad_form(u_46, R) + quad_form(x_47 - xe_47, Q) + quad_form(u_47, R) + quad_form(x_48 - xe_48, Q) + quad_form(u_48, R) + quad_form(x_49 - xe_49, Q) + quad_form(u_49, R) + quad_form(x_50 - xe_50, Q) + quad_form(u_50, R) + quad_form(x_51 - xe_51, Q_final) + quad_form(u_1 - u_0, Rd) + quad_form(u_2 - u_1, Rd) + quad_form(u_3 - u_2, Rd) + quad_form(u_4 - u_3, Rd) + quad_form(u_5 - u_4, Rd) + quad_form(u_6 - u_5, Rd) + quad_form(u_7 - u_6, Rd) + quad_form(u_8 - u_7, Rd) + quad_form(u_9 - u_8, Rd) + quad_form(u_10 - u_9, Rd) + quad_form(u_11 - u_10, Rd) + quad_form(u_12 - u_11, Rd) + quad_form(u_13 - u_12, Rd) + quad_form(u_14 - u_13, Rd) + quad_form(u_15 - u_14, Rd) + quad_form(u_16 - u_15, Rd) + quad_form(u_17 - u_16, Rd) + quad_form(u_18 - u_17, Rd) + quad_form(u_19 - u_18, Rd) + quad_form(u_20 - u_19, Rd) + quad_form(u_21 - u_20, Rd) + quad_form(u_22 - u_21, Rd) + quad_form(u_23 - u_22, Rd) + quad_form(u_24 - u_23, Rd) + quad_form(u_25 - u_24, Rd) + quad_form(u_26 - u_25, Rd) + quad_form(u_27 - u_26, Rd) + quad_form(u_28 - u_27, Rd) + quad_form(u_29 - u_28, Rd) + quad_form(u_30 - u_29, Rd) + quad_form(u_31 - u_30, Rd) + quad_form(u_32 - u_31, Rd) + quad_form(u_33 - u_32, Rd) + quad_form(u_34 - u_33, Rd) + quad_form(u_35 - u_34, Rd) + quad_form(u_36 - u_35, Rd) + quad_form(u_37 - u_36, Rd) + quad_form(u_38 - u_37, Rd) + quad_form(u_39 - u_38, Rd) + quad_form(u_40 - u_39, Rd) + quad_form(u_41 - u_40, Rd) + quad_form(u_42 - u_41, Rd) + quad_form(u_43 - u_42, Rd) + quad_form(u_44 - u_43, Rd) + quad_form(u_45 - u_44, Rd) + quad_form(u_46 - u_45, Rd) + quad_form(u_47 - u_46, Rd) + quad_form(u_48 - u_47, Rd) + quad_form(u_49 - u_48, Rd) + quad_form(u_50 - u_49, Rd))
%   subject to
%     x_1 == A_0*x_0 + B_0*u_0 + f0_0
%     x_2 == A_1*x_1 + B_1*u_1 + f0_1
%     x_3 == A_2*x_2 + B_2*u_2 + f0_2
%     x_4 == A_3*x_3 + B_3*u_3 + f0_3
%     x_5 == A_4*x_4 + B_4*u_4 + f0_4
%     x_6 == A_5*x_5 + B_5*u_5 + f0_5
%     x_7 == A_6*x_6 + B_6*u_6 + f0_6
%     x_8 == A_7*x_7 + B_7*u_7 + f0_7
%     x_9 == A_8*x_8 + B_8*u_8 + f0_8
%     x_10 == A_9*x_9 + B_9*u_9 + f0_9
%     x_11 == A_10*x_10 + B_10*u_10 + f0_10
%     x_12 == A_11*x_11 + B_11*u_11 + f0_11
%     x_13 == A_12*x_12 + B_12*u_12 + f0_12
%     x_14 == A_13*x_13 + B_13*u_13 + f0_13
%     x_15 == A_14*x_14 + B_14*u_14 + f0_14
%     x_16 == A_15*x_15 + B_15*u_15 + f0_15
%     x_17 == A_16*x_16 + B_16*u_16 + f0_16
%     x_18 == A_17*x_17 + B_17*u_17 + f0_17
%     x_19 == A_18*x_18 + B_18*u_18 + f0_18
%     x_20 == A_19*x_19 + B_19*u_19 + f0_19
%     x_21 == A_20*x_20 + B_20*u_20 + f0_20
%     x_22 == A_21*x_21 + B_21*u_21 + f0_21
%     x_23 == A_22*x_22 + B_22*u_22 + f0_22
%     x_24 == A_23*x_23 + B_23*u_23 + f0_23
%     x_25 == A_24*x_24 + B_24*u_24 + f0_24
%     x_26 == A_25*x_25 + B_25*u_25 + f0_25
%     x_27 == A_26*x_26 + B_26*u_26 + f0_26
%     x_28 == A_27*x_27 + B_27*u_27 + f0_27
%     x_29 == A_28*x_28 + B_28*u_28 + f0_28
%     x_30 == A_29*x_29 + B_29*u_29 + f0_29
%     x_31 == A_30*x_30 + B_30*u_30 + f0_30
%     x_32 == A_31*x_31 + B_31*u_31 + f0_31
%     x_33 == A_32*x_32 + B_32*u_32 + f0_32
%     x_34 == A_33*x_33 + B_33*u_33 + f0_33
%     x_35 == A_34*x_34 + B_34*u_34 + f0_34
%     x_36 == A_35*x_35 + B_35*u_35 + f0_35
%     x_37 == A_36*x_36 + B_36*u_36 + f0_36
%     x_38 == A_37*x_37 + B_37*u_37 + f0_37
%     x_39 == A_38*x_38 + B_38*u_38 + f0_38
%     x_40 == A_39*x_39 + B_39*u_39 + f0_39
%     x_41 == A_40*x_40 + B_40*u_40 + f0_40
%     x_42 == A_41*x_41 + B_41*u_41 + f0_41
%     x_43 == A_42*x_42 + B_42*u_42 + f0_42
%     x_44 == A_43*x_43 + B_43*u_43 + f0_43
%     x_45 == A_44*x_44 + B_44*u_44 + f0_44
%     x_46 == A_45*x_45 + B_45*u_45 + f0_45
%     x_47 == A_46*x_46 + B_46*u_46 + f0_46
%     x_48 == A_47*x_47 + B_47*u_47 + f0_47
%     x_49 == A_48*x_48 + B_48*u_48 + f0_48
%     x_50 == A_49*x_49 + B_49*u_49 + f0_49
%     x_51 == A_50*x_50 + B_50*u_50 + f0_50
%     u_0 >= u_min
%     u_1 >= u_min
%     u_2 >= u_min
%     u_3 >= u_min
%     u_4 >= u_min
%     u_5 >= u_min
%     u_6 >= u_min
%     u_7 >= u_min
%     u_8 >= u_min
%     u_9 >= u_min
%     u_10 >= u_min
%     u_11 >= u_min
%     u_12 >= u_min
%     u_13 >= u_min
%     u_14 >= u_min
%     u_15 >= u_min
%     u_16 >= u_min
%     u_17 >= u_min
%     u_18 >= u_min
%     u_19 >= u_min
%     u_20 >= u_min
%     u_21 >= u_min
%     u_22 >= u_min
%     u_23 >= u_min
%     u_24 >= u_min
%     u_25 >= u_min
%     u_26 >= u_min
%     u_27 >= u_min
%     u_28 >= u_min
%     u_29 >= u_min
%     u_30 >= u_min
%     u_31 >= u_min
%     u_32 >= u_min
%     u_33 >= u_min
%     u_34 >= u_min
%     u_35 >= u_min
%     u_36 >= u_min
%     u_37 >= u_min
%     u_38 >= u_min
%     u_39 >= u_min
%     u_40 >= u_min
%     u_41 >= u_min
%     u_42 >= u_min
%     u_43 >= u_min
%     u_44 >= u_min
%     u_45 >= u_min
%     u_46 >= u_min
%     u_47 >= u_min
%     u_48 >= u_min
%     u_49 >= u_min
%     u_50 >= u_min
%     u_0 <= u_max
%     u_1 <= u_max
%     u_2 <= u_max
%     u_3 <= u_max
%     u_4 <= u_max
%     u_5 <= u_max
%     u_6 <= u_max
%     u_7 <= u_max
%     u_8 <= u_max
%     u_9 <= u_max
%     u_10 <= u_max
%     u_11 <= u_max
%     u_12 <= u_max
%     u_13 <= u_max
%     u_14 <= u_max
%     u_15 <= u_max
%     u_16 <= u_max
%     u_17 <= u_max
%     u_18 <= u_max
%     u_19 <= u_max
%     u_20 <= u_max
%     u_21 <= u_max
%     u_22 <= u_max
%     u_23 <= u_max
%     u_24 <= u_max
%     u_25 <= u_max
%     u_26 <= u_max
%     u_27 <= u_max
%     u_28 <= u_max
%     u_29 <= u_max
%     u_30 <= u_max
%     u_31 <= u_max
%     u_32 <= u_max
%     u_33 <= u_max
%     u_34 <= u_max
%     u_35 <= u_max
%     u_36 <= u_max
%     u_37 <= u_max
%     u_38 <= u_max
%     u_39 <= u_max
%     u_40 <= u_max
%     u_41 <= u_max
%     u_42 <= u_max
%     u_43 <= u_max
%     u_44 <= u_max
%     u_45 <= u_max
%     u_46 <= u_max
%     u_47 <= u_max
%     u_48 <= u_max
%     u_49 <= u_max
%     u_50 <= u_max
%
% with variables
%      u_0   1 x 1
%      u_1   1 x 1
%      u_2   1 x 1
%      u_3   1 x 1
%      u_4   1 x 1
%      u_5   1 x 1
%      u_6   1 x 1
%      u_7   1 x 1
%      u_8   1 x 1
%      u_9   1 x 1
%     u_10   1 x 1
%     u_11   1 x 1
%     u_12   1 x 1
%     u_13   1 x 1
%     u_14   1 x 1
%     u_15   1 x 1
%     u_16   1 x 1
%     u_17   1 x 1
%     u_18   1 x 1
%     u_19   1 x 1
%     u_20   1 x 1
%     u_21   1 x 1
%     u_22   1 x 1
%     u_23   1 x 1
%     u_24   1 x 1
%     u_25   1 x 1
%     u_26   1 x 1
%     u_27   1 x 1
%     u_28   1 x 1
%     u_29   1 x 1
%     u_30   1 x 1
%     u_31   1 x 1
%     u_32   1 x 1
%     u_33   1 x 1
%     u_34   1 x 1
%     u_35   1 x 1
%     u_36   1 x 1
%     u_37   1 x 1
%     u_38   1 x 1
%     u_39   1 x 1
%     u_40   1 x 1
%     u_41   1 x 1
%     u_42   1 x 1
%     u_43   1 x 1
%     u_44   1 x 1
%     u_45   1 x 1
%     u_46   1 x 1
%     u_47   1 x 1
%     u_48   1 x 1
%     u_49   1 x 1
%     u_50   1 x 1
%      x_1   3 x 1
%      x_2   3 x 1
%      x_3   3 x 1
%      x_4   3 x 1
%      x_5   3 x 1
%      x_6   3 x 1
%      x_7   3 x 1
%      x_8   3 x 1
%      x_9   3 x 1
%     x_10   3 x 1
%     x_11   3 x 1
%     x_12   3 x 1
%     x_13   3 x 1
%     x_14   3 x 1
%     x_15   3 x 1
%     x_16   3 x 1
%     x_17   3 x 1
%     x_18   3 x 1
%     x_19   3 x 1
%     x_20   3 x 1
%     x_21   3 x 1
%     x_22   3 x 1
%     x_23   3 x 1
%     x_24   3 x 1
%     x_25   3 x 1
%     x_26   3 x 1
%     x_27   3 x 1
%     x_28   3 x 1
%     x_29   3 x 1
%     x_30   3 x 1
%     x_31   3 x 1
%     x_32   3 x 1
%     x_33   3 x 1
%     x_34   3 x 1
%     x_35   3 x 1
%     x_36   3 x 1
%     x_37   3 x 1
%     x_38   3 x 1
%     x_39   3 x 1
%     x_40   3 x 1
%     x_41   3 x 1
%     x_42   3 x 1
%     x_43   3 x 1
%     x_44   3 x 1
%     x_45   3 x 1
%     x_46   3 x 1
%     x_47   3 x 1
%     x_48   3 x 1
%     x_49   3 x 1
%     x_50   3 x 1
%     x_51   3 x 1
%
% and parameters
%      A_0   3 x 3
%      A_1   3 x 3
%      A_2   3 x 3
%      A_3   3 x 3
%      A_4   3 x 3
%      A_5   3 x 3
%      A_6   3 x 3
%      A_7   3 x 3
%      A_8   3 x 3
%      A_9   3 x 3
%     A_10   3 x 3
%     A_11   3 x 3
%     A_12   3 x 3
%     A_13   3 x 3
%     A_14   3 x 3
%     A_15   3 x 3
%     A_16   3 x 3
%     A_17   3 x 3
%     A_18   3 x 3
%     A_19   3 x 3
%     A_20   3 x 3
%     A_21   3 x 3
%     A_22   3 x 3
%     A_23   3 x 3
%     A_24   3 x 3
%     A_25   3 x 3
%     A_26   3 x 3
%     A_27   3 x 3
%     A_28   3 x 3
%     A_29   3 x 3
%     A_30   3 x 3
%     A_31   3 x 3
%     A_32   3 x 3
%     A_33   3 x 3
%     A_34   3 x 3
%     A_35   3 x 3
%     A_36   3 x 3
%     A_37   3 x 3
%     A_38   3 x 3
%     A_39   3 x 3
%     A_40   3 x 3
%     A_41   3 x 3
%     A_42   3 x 3
%     A_43   3 x 3
%     A_44   3 x 3
%     A_45   3 x 3
%     A_46   3 x 3
%     A_47   3 x 3
%     A_48   3 x 3
%     A_49   3 x 3
%     A_50   3 x 3
%      B_0   3 x 1
%      B_1   3 x 1
%      B_2   3 x 1
%      B_3   3 x 1
%      B_4   3 x 1
%      B_5   3 x 1
%      B_6   3 x 1
%      B_7   3 x 1
%      B_8   3 x 1
%      B_9   3 x 1
%     B_10   3 x 1
%     B_11   3 x 1
%     B_12   3 x 1
%     B_13   3 x 1
%     B_14   3 x 1
%     B_15   3 x 1
%     B_16   3 x 1
%     B_17   3 x 1
%     B_18   3 x 1
%     B_19   3 x 1
%     B_20   3 x 1
%     B_21   3 x 1
%     B_22   3 x 1
%     B_23   3 x 1
%     B_24   3 x 1
%     B_25   3 x 1
%     B_26   3 x 1
%     B_27   3 x 1
%     B_28   3 x 1
%     B_29   3 x 1
%     B_30   3 x 1
%     B_31   3 x 1
%     B_32   3 x 1
%     B_33   3 x 1
%     B_34   3 x 1
%     B_35   3 x 1
%     B_36   3 x 1
%     B_37   3 x 1
%     B_38   3 x 1
%     B_39   3 x 1
%     B_40   3 x 1
%     B_41   3 x 1
%     B_42   3 x 1
%     B_43   3 x 1
%     B_44   3 x 1
%     B_45   3 x 1
%     B_46   3 x 1
%     B_47   3 x 1
%     B_48   3 x 1
%     B_49   3 x 1
%     B_50   3 x 1
%        Q   3 x 3    PSD
%  Q_final   3 x 3    PSD
%        R   1 x 1    PSD
%       Rd   1 x 1    PSD
%     f0_0   3 x 1
%     f0_1   3 x 1
%     f0_2   3 x 1
%     f0_3   3 x 1
%     f0_4   3 x 1
%     f0_5   3 x 1
%     f0_6   3 x 1
%     f0_7   3 x 1
%     f0_8   3 x 1
%     f0_9   3 x 1
%    f0_10   3 x 1
%    f0_11   3 x 1
%    f0_12   3 x 1
%    f0_13   3 x 1
%    f0_14   3 x 1
%    f0_15   3 x 1
%    f0_16   3 x 1
%    f0_17   3 x 1
%    f0_18   3 x 1
%    f0_19   3 x 1
%    f0_20   3 x 1
%    f0_21   3 x 1
%    f0_22   3 x 1
%    f0_23   3 x 1
%    f0_24   3 x 1
%    f0_25   3 x 1
%    f0_26   3 x 1
%    f0_27   3 x 1
%    f0_28   3 x 1
%    f0_29   3 x 1
%    f0_30   3 x 1
%    f0_31   3 x 1
%    f0_32   3 x 1
%    f0_33   3 x 1
%    f0_34   3 x 1
%    f0_35   3 x 1
%    f0_36   3 x 1
%    f0_37   3 x 1
%    f0_38   3 x 1
%    f0_39   3 x 1
%    f0_40   3 x 1
%    f0_41   3 x 1
%    f0_42   3 x 1
%    f0_43   3 x 1
%    f0_44   3 x 1
%    f0_45   3 x 1
%    f0_46   3 x 1
%    f0_47   3 x 1
%    f0_48   3 x 1
%    f0_49   3 x 1
%    f0_50   3 x 1
%    u_max   1 x 1    positive
%    u_min   1 x 1
%      x_0   3 x 1
%     xe_0   3 x 1
%     xe_1   3 x 1
%     xe_2   3 x 1
%     xe_3   3 x 1
%     xe_4   3 x 1
%     xe_5   3 x 1
%     xe_6   3 x 1
%     xe_7   3 x 1
%     xe_8   3 x 1
%     xe_9   3 x 1
%    xe_10   3 x 1
%    xe_11   3 x 1
%    xe_12   3 x 1
%    xe_13   3 x 1
%    xe_14   3 x 1
%    xe_15   3 x 1
%    xe_16   3 x 1
%    xe_17   3 x 1
%    xe_18   3 x 1
%    xe_19   3 x 1
%    xe_20   3 x 1
%    xe_21   3 x 1
%    xe_22   3 x 1
%    xe_23   3 x 1
%    xe_24   3 x 1
%    xe_25   3 x 1
%    xe_26   3 x 1
%    xe_27   3 x 1
%    xe_28   3 x 1
%    xe_29   3 x 1
%    xe_30   3 x 1
%    xe_31   3 x 1
%    xe_32   3 x 1
%    xe_33   3 x 1
%    xe_34   3 x 1
%    xe_35   3 x 1
%    xe_36   3 x 1
%    xe_37   3 x 1
%    xe_38   3 x 1
%    xe_39   3 x 1
%    xe_40   3 x 1
%    xe_41   3 x 1
%    xe_42   3 x 1
%    xe_43   3 x 1
%    xe_44   3 x 1
%    xe_45   3 x 1
%    xe_46   3 x 1
%    xe_47   3 x 1
%    xe_48   3 x 1
%    xe_49   3 x 1
%    xe_50   3 x 1
%    xe_51   3 x 1
%
% Note:
%   - Check status.converged, which will be 1 if optimization succeeded.
%   - You don't have to specify settings if you don't want to.
%   - To hide output, use settings.verbose = 0.
%   - To change iterations, use settings.max_iters = 20.
%   - You may wish to compare with cvxsolve to check the solver is correct.
%
% Specify params.A_0, ..., params.xe_51, then run
%   [vars, status] = csolve(params, settings)
% Produced by CVXGEN, 2017-06-14 00:59:57 -0400.
% CVXGEN is Copyright (C) 2006-2012 Jacob Mattingley, jem@cvxgen.com.
% The code in this file is Copyright (C) 2006-2012 Jacob Mattingley.
% CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial
% applications without prior written permission from Jacob Mattingley.

% Filename: csolve.m.
% Description: Help file for the Matlab solver interface.
