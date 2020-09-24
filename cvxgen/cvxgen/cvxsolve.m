% Produced by CVXGEN, 2017-06-14 00:59:57 -0400.
% CVXGEN is Copyright (C) 2006-2012 Jacob Mattingley, jem@cvxgen.com.
% The code in this file is Copyright (C) 2006-2012 Jacob Mattingley.
% CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial
% applications without prior written permission from Jacob Mattingley.

% Filename: cvxsolve.m.
% Description: Solution file, via cvx, for use with sample.m.
function [vars, status] = cvxsolve(params, settings)
A_0 = params.A_0;
if isfield(params, 'A_1')
  A_1 = params.A_1;
elseif isfield(params, 'A')
  A_1 = params.A{1};
else
  error 'could not find A_1'
end
if isfield(params, 'A_2')
  A_2 = params.A_2;
elseif isfield(params, 'A')
  A_2 = params.A{2};
else
  error 'could not find A_2'
end
if isfield(params, 'A_3')
  A_3 = params.A_3;
elseif isfield(params, 'A')
  A_3 = params.A{3};
else
  error 'could not find A_3'
end
if isfield(params, 'A_4')
  A_4 = params.A_4;
elseif isfield(params, 'A')
  A_4 = params.A{4};
else
  error 'could not find A_4'
end
if isfield(params, 'A_5')
  A_5 = params.A_5;
elseif isfield(params, 'A')
  A_5 = params.A{5};
else
  error 'could not find A_5'
end
if isfield(params, 'A_6')
  A_6 = params.A_6;
elseif isfield(params, 'A')
  A_6 = params.A{6};
else
  error 'could not find A_6'
end
if isfield(params, 'A_7')
  A_7 = params.A_7;
elseif isfield(params, 'A')
  A_7 = params.A{7};
else
  error 'could not find A_7'
end
if isfield(params, 'A_8')
  A_8 = params.A_8;
elseif isfield(params, 'A')
  A_8 = params.A{8};
else
  error 'could not find A_8'
end
if isfield(params, 'A_9')
  A_9 = params.A_9;
elseif isfield(params, 'A')
  A_9 = params.A{9};
else
  error 'could not find A_9'
end
if isfield(params, 'A_10')
  A_10 = params.A_10;
elseif isfield(params, 'A')
  A_10 = params.A{10};
else
  error 'could not find A_10'
end
if isfield(params, 'A_11')
  A_11 = params.A_11;
elseif isfield(params, 'A')
  A_11 = params.A{11};
else
  error 'could not find A_11'
end
if isfield(params, 'A_12')
  A_12 = params.A_12;
elseif isfield(params, 'A')
  A_12 = params.A{12};
else
  error 'could not find A_12'
end
if isfield(params, 'A_13')
  A_13 = params.A_13;
elseif isfield(params, 'A')
  A_13 = params.A{13};
else
  error 'could not find A_13'
end
if isfield(params, 'A_14')
  A_14 = params.A_14;
elseif isfield(params, 'A')
  A_14 = params.A{14};
else
  error 'could not find A_14'
end
if isfield(params, 'A_15')
  A_15 = params.A_15;
elseif isfield(params, 'A')
  A_15 = params.A{15};
else
  error 'could not find A_15'
end
if isfield(params, 'A_16')
  A_16 = params.A_16;
elseif isfield(params, 'A')
  A_16 = params.A{16};
else
  error 'could not find A_16'
end
if isfield(params, 'A_17')
  A_17 = params.A_17;
elseif isfield(params, 'A')
  A_17 = params.A{17};
else
  error 'could not find A_17'
end
if isfield(params, 'A_18')
  A_18 = params.A_18;
elseif isfield(params, 'A')
  A_18 = params.A{18};
else
  error 'could not find A_18'
end
if isfield(params, 'A_19')
  A_19 = params.A_19;
elseif isfield(params, 'A')
  A_19 = params.A{19};
else
  error 'could not find A_19'
end
if isfield(params, 'A_20')
  A_20 = params.A_20;
elseif isfield(params, 'A')
  A_20 = params.A{20};
else
  error 'could not find A_20'
end
if isfield(params, 'A_21')
  A_21 = params.A_21;
elseif isfield(params, 'A')
  A_21 = params.A{21};
else
  error 'could not find A_21'
end
if isfield(params, 'A_22')
  A_22 = params.A_22;
elseif isfield(params, 'A')
  A_22 = params.A{22};
else
  error 'could not find A_22'
end
if isfield(params, 'A_23')
  A_23 = params.A_23;
elseif isfield(params, 'A')
  A_23 = params.A{23};
else
  error 'could not find A_23'
end
if isfield(params, 'A_24')
  A_24 = params.A_24;
elseif isfield(params, 'A')
  A_24 = params.A{24};
else
  error 'could not find A_24'
end
if isfield(params, 'A_25')
  A_25 = params.A_25;
elseif isfield(params, 'A')
  A_25 = params.A{25};
else
  error 'could not find A_25'
end
if isfield(params, 'A_26')
  A_26 = params.A_26;
elseif isfield(params, 'A')
  A_26 = params.A{26};
else
  error 'could not find A_26'
end
if isfield(params, 'A_27')
  A_27 = params.A_27;
elseif isfield(params, 'A')
  A_27 = params.A{27};
else
  error 'could not find A_27'
end
if isfield(params, 'A_28')
  A_28 = params.A_28;
elseif isfield(params, 'A')
  A_28 = params.A{28};
else
  error 'could not find A_28'
end
if isfield(params, 'A_29')
  A_29 = params.A_29;
elseif isfield(params, 'A')
  A_29 = params.A{29};
else
  error 'could not find A_29'
end
if isfield(params, 'A_30')
  A_30 = params.A_30;
elseif isfield(params, 'A')
  A_30 = params.A{30};
else
  error 'could not find A_30'
end
if isfield(params, 'A_31')
  A_31 = params.A_31;
elseif isfield(params, 'A')
  A_31 = params.A{31};
else
  error 'could not find A_31'
end
if isfield(params, 'A_32')
  A_32 = params.A_32;
elseif isfield(params, 'A')
  A_32 = params.A{32};
else
  error 'could not find A_32'
end
if isfield(params, 'A_33')
  A_33 = params.A_33;
elseif isfield(params, 'A')
  A_33 = params.A{33};
else
  error 'could not find A_33'
end
if isfield(params, 'A_34')
  A_34 = params.A_34;
elseif isfield(params, 'A')
  A_34 = params.A{34};
else
  error 'could not find A_34'
end
if isfield(params, 'A_35')
  A_35 = params.A_35;
elseif isfield(params, 'A')
  A_35 = params.A{35};
else
  error 'could not find A_35'
end
if isfield(params, 'A_36')
  A_36 = params.A_36;
elseif isfield(params, 'A')
  A_36 = params.A{36};
else
  error 'could not find A_36'
end
if isfield(params, 'A_37')
  A_37 = params.A_37;
elseif isfield(params, 'A')
  A_37 = params.A{37};
else
  error 'could not find A_37'
end
if isfield(params, 'A_38')
  A_38 = params.A_38;
elseif isfield(params, 'A')
  A_38 = params.A{38};
else
  error 'could not find A_38'
end
if isfield(params, 'A_39')
  A_39 = params.A_39;
elseif isfield(params, 'A')
  A_39 = params.A{39};
else
  error 'could not find A_39'
end
if isfield(params, 'A_40')
  A_40 = params.A_40;
elseif isfield(params, 'A')
  A_40 = params.A{40};
else
  error 'could not find A_40'
end
if isfield(params, 'A_41')
  A_41 = params.A_41;
elseif isfield(params, 'A')
  A_41 = params.A{41};
else
  error 'could not find A_41'
end
if isfield(params, 'A_42')
  A_42 = params.A_42;
elseif isfield(params, 'A')
  A_42 = params.A{42};
else
  error 'could not find A_42'
end
if isfield(params, 'A_43')
  A_43 = params.A_43;
elseif isfield(params, 'A')
  A_43 = params.A{43};
else
  error 'could not find A_43'
end
if isfield(params, 'A_44')
  A_44 = params.A_44;
elseif isfield(params, 'A')
  A_44 = params.A{44};
else
  error 'could not find A_44'
end
if isfield(params, 'A_45')
  A_45 = params.A_45;
elseif isfield(params, 'A')
  A_45 = params.A{45};
else
  error 'could not find A_45'
end
if isfield(params, 'A_46')
  A_46 = params.A_46;
elseif isfield(params, 'A')
  A_46 = params.A{46};
else
  error 'could not find A_46'
end
if isfield(params, 'A_47')
  A_47 = params.A_47;
elseif isfield(params, 'A')
  A_47 = params.A{47};
else
  error 'could not find A_47'
end
if isfield(params, 'A_48')
  A_48 = params.A_48;
elseif isfield(params, 'A')
  A_48 = params.A{48};
else
  error 'could not find A_48'
end
if isfield(params, 'A_49')
  A_49 = params.A_49;
elseif isfield(params, 'A')
  A_49 = params.A{49};
else
  error 'could not find A_49'
end
if isfield(params, 'A_50')
  A_50 = params.A_50;
elseif isfield(params, 'A')
  A_50 = params.A{50};
else
  error 'could not find A_50'
end
B_0 = params.B_0;
if isfield(params, 'B_1')
  B_1 = params.B_1;
elseif isfield(params, 'B')
  B_1 = params.B{1};
else
  error 'could not find B_1'
end
if isfield(params, 'B_2')
  B_2 = params.B_2;
elseif isfield(params, 'B')
  B_2 = params.B{2};
else
  error 'could not find B_2'
end
if isfield(params, 'B_3')
  B_3 = params.B_3;
elseif isfield(params, 'B')
  B_3 = params.B{3};
else
  error 'could not find B_3'
end
if isfield(params, 'B_4')
  B_4 = params.B_4;
elseif isfield(params, 'B')
  B_4 = params.B{4};
else
  error 'could not find B_4'
end
if isfield(params, 'B_5')
  B_5 = params.B_5;
elseif isfield(params, 'B')
  B_5 = params.B{5};
else
  error 'could not find B_5'
end
if isfield(params, 'B_6')
  B_6 = params.B_6;
elseif isfield(params, 'B')
  B_6 = params.B{6};
else
  error 'could not find B_6'
end
if isfield(params, 'B_7')
  B_7 = params.B_7;
elseif isfield(params, 'B')
  B_7 = params.B{7};
else
  error 'could not find B_7'
end
if isfield(params, 'B_8')
  B_8 = params.B_8;
elseif isfield(params, 'B')
  B_8 = params.B{8};
else
  error 'could not find B_8'
end
if isfield(params, 'B_9')
  B_9 = params.B_9;
elseif isfield(params, 'B')
  B_9 = params.B{9};
else
  error 'could not find B_9'
end
if isfield(params, 'B_10')
  B_10 = params.B_10;
elseif isfield(params, 'B')
  B_10 = params.B{10};
else
  error 'could not find B_10'
end
if isfield(params, 'B_11')
  B_11 = params.B_11;
elseif isfield(params, 'B')
  B_11 = params.B{11};
else
  error 'could not find B_11'
end
if isfield(params, 'B_12')
  B_12 = params.B_12;
elseif isfield(params, 'B')
  B_12 = params.B{12};
else
  error 'could not find B_12'
end
if isfield(params, 'B_13')
  B_13 = params.B_13;
elseif isfield(params, 'B')
  B_13 = params.B{13};
else
  error 'could not find B_13'
end
if isfield(params, 'B_14')
  B_14 = params.B_14;
elseif isfield(params, 'B')
  B_14 = params.B{14};
else
  error 'could not find B_14'
end
if isfield(params, 'B_15')
  B_15 = params.B_15;
elseif isfield(params, 'B')
  B_15 = params.B{15};
else
  error 'could not find B_15'
end
if isfield(params, 'B_16')
  B_16 = params.B_16;
elseif isfield(params, 'B')
  B_16 = params.B{16};
else
  error 'could not find B_16'
end
if isfield(params, 'B_17')
  B_17 = params.B_17;
elseif isfield(params, 'B')
  B_17 = params.B{17};
else
  error 'could not find B_17'
end
if isfield(params, 'B_18')
  B_18 = params.B_18;
elseif isfield(params, 'B')
  B_18 = params.B{18};
else
  error 'could not find B_18'
end
if isfield(params, 'B_19')
  B_19 = params.B_19;
elseif isfield(params, 'B')
  B_19 = params.B{19};
else
  error 'could not find B_19'
end
if isfield(params, 'B_20')
  B_20 = params.B_20;
elseif isfield(params, 'B')
  B_20 = params.B{20};
else
  error 'could not find B_20'
end
if isfield(params, 'B_21')
  B_21 = params.B_21;
elseif isfield(params, 'B')
  B_21 = params.B{21};
else
  error 'could not find B_21'
end
if isfield(params, 'B_22')
  B_22 = params.B_22;
elseif isfield(params, 'B')
  B_22 = params.B{22};
else
  error 'could not find B_22'
end
if isfield(params, 'B_23')
  B_23 = params.B_23;
elseif isfield(params, 'B')
  B_23 = params.B{23};
else
  error 'could not find B_23'
end
if isfield(params, 'B_24')
  B_24 = params.B_24;
elseif isfield(params, 'B')
  B_24 = params.B{24};
else
  error 'could not find B_24'
end
if isfield(params, 'B_25')
  B_25 = params.B_25;
elseif isfield(params, 'B')
  B_25 = params.B{25};
else
  error 'could not find B_25'
end
if isfield(params, 'B_26')
  B_26 = params.B_26;
elseif isfield(params, 'B')
  B_26 = params.B{26};
else
  error 'could not find B_26'
end
if isfield(params, 'B_27')
  B_27 = params.B_27;
elseif isfield(params, 'B')
  B_27 = params.B{27};
else
  error 'could not find B_27'
end
if isfield(params, 'B_28')
  B_28 = params.B_28;
elseif isfield(params, 'B')
  B_28 = params.B{28};
else
  error 'could not find B_28'
end
if isfield(params, 'B_29')
  B_29 = params.B_29;
elseif isfield(params, 'B')
  B_29 = params.B{29};
else
  error 'could not find B_29'
end
if isfield(params, 'B_30')
  B_30 = params.B_30;
elseif isfield(params, 'B')
  B_30 = params.B{30};
else
  error 'could not find B_30'
end
if isfield(params, 'B_31')
  B_31 = params.B_31;
elseif isfield(params, 'B')
  B_31 = params.B{31};
else
  error 'could not find B_31'
end
if isfield(params, 'B_32')
  B_32 = params.B_32;
elseif isfield(params, 'B')
  B_32 = params.B{32};
else
  error 'could not find B_32'
end
if isfield(params, 'B_33')
  B_33 = params.B_33;
elseif isfield(params, 'B')
  B_33 = params.B{33};
else
  error 'could not find B_33'
end
if isfield(params, 'B_34')
  B_34 = params.B_34;
elseif isfield(params, 'B')
  B_34 = params.B{34};
else
  error 'could not find B_34'
end
if isfield(params, 'B_35')
  B_35 = params.B_35;
elseif isfield(params, 'B')
  B_35 = params.B{35};
else
  error 'could not find B_35'
end
if isfield(params, 'B_36')
  B_36 = params.B_36;
elseif isfield(params, 'B')
  B_36 = params.B{36};
else
  error 'could not find B_36'
end
if isfield(params, 'B_37')
  B_37 = params.B_37;
elseif isfield(params, 'B')
  B_37 = params.B{37};
else
  error 'could not find B_37'
end
if isfield(params, 'B_38')
  B_38 = params.B_38;
elseif isfield(params, 'B')
  B_38 = params.B{38};
else
  error 'could not find B_38'
end
if isfield(params, 'B_39')
  B_39 = params.B_39;
elseif isfield(params, 'B')
  B_39 = params.B{39};
else
  error 'could not find B_39'
end
if isfield(params, 'B_40')
  B_40 = params.B_40;
elseif isfield(params, 'B')
  B_40 = params.B{40};
else
  error 'could not find B_40'
end
if isfield(params, 'B_41')
  B_41 = params.B_41;
elseif isfield(params, 'B')
  B_41 = params.B{41};
else
  error 'could not find B_41'
end
if isfield(params, 'B_42')
  B_42 = params.B_42;
elseif isfield(params, 'B')
  B_42 = params.B{42};
else
  error 'could not find B_42'
end
if isfield(params, 'B_43')
  B_43 = params.B_43;
elseif isfield(params, 'B')
  B_43 = params.B{43};
else
  error 'could not find B_43'
end
if isfield(params, 'B_44')
  B_44 = params.B_44;
elseif isfield(params, 'B')
  B_44 = params.B{44};
else
  error 'could not find B_44'
end
if isfield(params, 'B_45')
  B_45 = params.B_45;
elseif isfield(params, 'B')
  B_45 = params.B{45};
else
  error 'could not find B_45'
end
if isfield(params, 'B_46')
  B_46 = params.B_46;
elseif isfield(params, 'B')
  B_46 = params.B{46};
else
  error 'could not find B_46'
end
if isfield(params, 'B_47')
  B_47 = params.B_47;
elseif isfield(params, 'B')
  B_47 = params.B{47};
else
  error 'could not find B_47'
end
if isfield(params, 'B_48')
  B_48 = params.B_48;
elseif isfield(params, 'B')
  B_48 = params.B{48};
else
  error 'could not find B_48'
end
if isfield(params, 'B_49')
  B_49 = params.B_49;
elseif isfield(params, 'B')
  B_49 = params.B{49};
else
  error 'could not find B_49'
end
if isfield(params, 'B_50')
  B_50 = params.B_50;
elseif isfield(params, 'B')
  B_50 = params.B{50};
else
  error 'could not find B_50'
end
Q = params.Q;
Q_final = params.Q_final;
R = params.R;
Rd = params.Rd;
f0_0 = params.f0_0;
if isfield(params, 'f0_1')
  f0_1 = params.f0_1;
elseif isfield(params, 'f0')
  f0_1 = params.f0{1};
else
  error 'could not find f0_1'
end
if isfield(params, 'f0_2')
  f0_2 = params.f0_2;
elseif isfield(params, 'f0')
  f0_2 = params.f0{2};
else
  error 'could not find f0_2'
end
if isfield(params, 'f0_3')
  f0_3 = params.f0_3;
elseif isfield(params, 'f0')
  f0_3 = params.f0{3};
else
  error 'could not find f0_3'
end
if isfield(params, 'f0_4')
  f0_4 = params.f0_4;
elseif isfield(params, 'f0')
  f0_4 = params.f0{4};
else
  error 'could not find f0_4'
end
if isfield(params, 'f0_5')
  f0_5 = params.f0_5;
elseif isfield(params, 'f0')
  f0_5 = params.f0{5};
else
  error 'could not find f0_5'
end
if isfield(params, 'f0_6')
  f0_6 = params.f0_6;
elseif isfield(params, 'f0')
  f0_6 = params.f0{6};
else
  error 'could not find f0_6'
end
if isfield(params, 'f0_7')
  f0_7 = params.f0_7;
elseif isfield(params, 'f0')
  f0_7 = params.f0{7};
else
  error 'could not find f0_7'
end
if isfield(params, 'f0_8')
  f0_8 = params.f0_8;
elseif isfield(params, 'f0')
  f0_8 = params.f0{8};
else
  error 'could not find f0_8'
end
if isfield(params, 'f0_9')
  f0_9 = params.f0_9;
elseif isfield(params, 'f0')
  f0_9 = params.f0{9};
else
  error 'could not find f0_9'
end
if isfield(params, 'f0_10')
  f0_10 = params.f0_10;
elseif isfield(params, 'f0')
  f0_10 = params.f0{10};
else
  error 'could not find f0_10'
end
if isfield(params, 'f0_11')
  f0_11 = params.f0_11;
elseif isfield(params, 'f0')
  f0_11 = params.f0{11};
else
  error 'could not find f0_11'
end
if isfield(params, 'f0_12')
  f0_12 = params.f0_12;
elseif isfield(params, 'f0')
  f0_12 = params.f0{12};
else
  error 'could not find f0_12'
end
if isfield(params, 'f0_13')
  f0_13 = params.f0_13;
elseif isfield(params, 'f0')
  f0_13 = params.f0{13};
else
  error 'could not find f0_13'
end
if isfield(params, 'f0_14')
  f0_14 = params.f0_14;
elseif isfield(params, 'f0')
  f0_14 = params.f0{14};
else
  error 'could not find f0_14'
end
if isfield(params, 'f0_15')
  f0_15 = params.f0_15;
elseif isfield(params, 'f0')
  f0_15 = params.f0{15};
else
  error 'could not find f0_15'
end
if isfield(params, 'f0_16')
  f0_16 = params.f0_16;
elseif isfield(params, 'f0')
  f0_16 = params.f0{16};
else
  error 'could not find f0_16'
end
if isfield(params, 'f0_17')
  f0_17 = params.f0_17;
elseif isfield(params, 'f0')
  f0_17 = params.f0{17};
else
  error 'could not find f0_17'
end
if isfield(params, 'f0_18')
  f0_18 = params.f0_18;
elseif isfield(params, 'f0')
  f0_18 = params.f0{18};
else
  error 'could not find f0_18'
end
if isfield(params, 'f0_19')
  f0_19 = params.f0_19;
elseif isfield(params, 'f0')
  f0_19 = params.f0{19};
else
  error 'could not find f0_19'
end
if isfield(params, 'f0_20')
  f0_20 = params.f0_20;
elseif isfield(params, 'f0')
  f0_20 = params.f0{20};
else
  error 'could not find f0_20'
end
if isfield(params, 'f0_21')
  f0_21 = params.f0_21;
elseif isfield(params, 'f0')
  f0_21 = params.f0{21};
else
  error 'could not find f0_21'
end
if isfield(params, 'f0_22')
  f0_22 = params.f0_22;
elseif isfield(params, 'f0')
  f0_22 = params.f0{22};
else
  error 'could not find f0_22'
end
if isfield(params, 'f0_23')
  f0_23 = params.f0_23;
elseif isfield(params, 'f0')
  f0_23 = params.f0{23};
else
  error 'could not find f0_23'
end
if isfield(params, 'f0_24')
  f0_24 = params.f0_24;
elseif isfield(params, 'f0')
  f0_24 = params.f0{24};
else
  error 'could not find f0_24'
end
if isfield(params, 'f0_25')
  f0_25 = params.f0_25;
elseif isfield(params, 'f0')
  f0_25 = params.f0{25};
else
  error 'could not find f0_25'
end
if isfield(params, 'f0_26')
  f0_26 = params.f0_26;
elseif isfield(params, 'f0')
  f0_26 = params.f0{26};
else
  error 'could not find f0_26'
end
if isfield(params, 'f0_27')
  f0_27 = params.f0_27;
elseif isfield(params, 'f0')
  f0_27 = params.f0{27};
else
  error 'could not find f0_27'
end
if isfield(params, 'f0_28')
  f0_28 = params.f0_28;
elseif isfield(params, 'f0')
  f0_28 = params.f0{28};
else
  error 'could not find f0_28'
end
if isfield(params, 'f0_29')
  f0_29 = params.f0_29;
elseif isfield(params, 'f0')
  f0_29 = params.f0{29};
else
  error 'could not find f0_29'
end
if isfield(params, 'f0_30')
  f0_30 = params.f0_30;
elseif isfield(params, 'f0')
  f0_30 = params.f0{30};
else
  error 'could not find f0_30'
end
if isfield(params, 'f0_31')
  f0_31 = params.f0_31;
elseif isfield(params, 'f0')
  f0_31 = params.f0{31};
else
  error 'could not find f0_31'
end
if isfield(params, 'f0_32')
  f0_32 = params.f0_32;
elseif isfield(params, 'f0')
  f0_32 = params.f0{32};
else
  error 'could not find f0_32'
end
if isfield(params, 'f0_33')
  f0_33 = params.f0_33;
elseif isfield(params, 'f0')
  f0_33 = params.f0{33};
else
  error 'could not find f0_33'
end
if isfield(params, 'f0_34')
  f0_34 = params.f0_34;
elseif isfield(params, 'f0')
  f0_34 = params.f0{34};
else
  error 'could not find f0_34'
end
if isfield(params, 'f0_35')
  f0_35 = params.f0_35;
elseif isfield(params, 'f0')
  f0_35 = params.f0{35};
else
  error 'could not find f0_35'
end
if isfield(params, 'f0_36')
  f0_36 = params.f0_36;
elseif isfield(params, 'f0')
  f0_36 = params.f0{36};
else
  error 'could not find f0_36'
end
if isfield(params, 'f0_37')
  f0_37 = params.f0_37;
elseif isfield(params, 'f0')
  f0_37 = params.f0{37};
else
  error 'could not find f0_37'
end
if isfield(params, 'f0_38')
  f0_38 = params.f0_38;
elseif isfield(params, 'f0')
  f0_38 = params.f0{38};
else
  error 'could not find f0_38'
end
if isfield(params, 'f0_39')
  f0_39 = params.f0_39;
elseif isfield(params, 'f0')
  f0_39 = params.f0{39};
else
  error 'could not find f0_39'
end
if isfield(params, 'f0_40')
  f0_40 = params.f0_40;
elseif isfield(params, 'f0')
  f0_40 = params.f0{40};
else
  error 'could not find f0_40'
end
if isfield(params, 'f0_41')
  f0_41 = params.f0_41;
elseif isfield(params, 'f0')
  f0_41 = params.f0{41};
else
  error 'could not find f0_41'
end
if isfield(params, 'f0_42')
  f0_42 = params.f0_42;
elseif isfield(params, 'f0')
  f0_42 = params.f0{42};
else
  error 'could not find f0_42'
end
if isfield(params, 'f0_43')
  f0_43 = params.f0_43;
elseif isfield(params, 'f0')
  f0_43 = params.f0{43};
else
  error 'could not find f0_43'
end
if isfield(params, 'f0_44')
  f0_44 = params.f0_44;
elseif isfield(params, 'f0')
  f0_44 = params.f0{44};
else
  error 'could not find f0_44'
end
if isfield(params, 'f0_45')
  f0_45 = params.f0_45;
elseif isfield(params, 'f0')
  f0_45 = params.f0{45};
else
  error 'could not find f0_45'
end
if isfield(params, 'f0_46')
  f0_46 = params.f0_46;
elseif isfield(params, 'f0')
  f0_46 = params.f0{46};
else
  error 'could not find f0_46'
end
if isfield(params, 'f0_47')
  f0_47 = params.f0_47;
elseif isfield(params, 'f0')
  f0_47 = params.f0{47};
else
  error 'could not find f0_47'
end
if isfield(params, 'f0_48')
  f0_48 = params.f0_48;
elseif isfield(params, 'f0')
  f0_48 = params.f0{48};
else
  error 'could not find f0_48'
end
if isfield(params, 'f0_49')
  f0_49 = params.f0_49;
elseif isfield(params, 'f0')
  f0_49 = params.f0{49};
else
  error 'could not find f0_49'
end
if isfield(params, 'f0_50')
  f0_50 = params.f0_50;
elseif isfield(params, 'f0')
  f0_50 = params.f0{50};
else
  error 'could not find f0_50'
end
u_max = params.u_max;
u_min = params.u_min;
x_0 = params.x_0;
xe_0 = params.xe_0;
if isfield(params, 'xe_1')
  xe_1 = params.xe_1;
elseif isfield(params, 'xe')
  xe_1 = params.xe{1};
else
  error 'could not find xe_1'
end
if isfield(params, 'xe_2')
  xe_2 = params.xe_2;
elseif isfield(params, 'xe')
  xe_2 = params.xe{2};
else
  error 'could not find xe_2'
end
if isfield(params, 'xe_3')
  xe_3 = params.xe_3;
elseif isfield(params, 'xe')
  xe_3 = params.xe{3};
else
  error 'could not find xe_3'
end
if isfield(params, 'xe_4')
  xe_4 = params.xe_4;
elseif isfield(params, 'xe')
  xe_4 = params.xe{4};
else
  error 'could not find xe_4'
end
if isfield(params, 'xe_5')
  xe_5 = params.xe_5;
elseif isfield(params, 'xe')
  xe_5 = params.xe{5};
else
  error 'could not find xe_5'
end
if isfield(params, 'xe_6')
  xe_6 = params.xe_6;
elseif isfield(params, 'xe')
  xe_6 = params.xe{6};
else
  error 'could not find xe_6'
end
if isfield(params, 'xe_7')
  xe_7 = params.xe_7;
elseif isfield(params, 'xe')
  xe_7 = params.xe{7};
else
  error 'could not find xe_7'
end
if isfield(params, 'xe_8')
  xe_8 = params.xe_8;
elseif isfield(params, 'xe')
  xe_8 = params.xe{8};
else
  error 'could not find xe_8'
end
if isfield(params, 'xe_9')
  xe_9 = params.xe_9;
elseif isfield(params, 'xe')
  xe_9 = params.xe{9};
else
  error 'could not find xe_9'
end
if isfield(params, 'xe_10')
  xe_10 = params.xe_10;
elseif isfield(params, 'xe')
  xe_10 = params.xe{10};
else
  error 'could not find xe_10'
end
if isfield(params, 'xe_11')
  xe_11 = params.xe_11;
elseif isfield(params, 'xe')
  xe_11 = params.xe{11};
else
  error 'could not find xe_11'
end
if isfield(params, 'xe_12')
  xe_12 = params.xe_12;
elseif isfield(params, 'xe')
  xe_12 = params.xe{12};
else
  error 'could not find xe_12'
end
if isfield(params, 'xe_13')
  xe_13 = params.xe_13;
elseif isfield(params, 'xe')
  xe_13 = params.xe{13};
else
  error 'could not find xe_13'
end
if isfield(params, 'xe_14')
  xe_14 = params.xe_14;
elseif isfield(params, 'xe')
  xe_14 = params.xe{14};
else
  error 'could not find xe_14'
end
if isfield(params, 'xe_15')
  xe_15 = params.xe_15;
elseif isfield(params, 'xe')
  xe_15 = params.xe{15};
else
  error 'could not find xe_15'
end
if isfield(params, 'xe_16')
  xe_16 = params.xe_16;
elseif isfield(params, 'xe')
  xe_16 = params.xe{16};
else
  error 'could not find xe_16'
end
if isfield(params, 'xe_17')
  xe_17 = params.xe_17;
elseif isfield(params, 'xe')
  xe_17 = params.xe{17};
else
  error 'could not find xe_17'
end
if isfield(params, 'xe_18')
  xe_18 = params.xe_18;
elseif isfield(params, 'xe')
  xe_18 = params.xe{18};
else
  error 'could not find xe_18'
end
if isfield(params, 'xe_19')
  xe_19 = params.xe_19;
elseif isfield(params, 'xe')
  xe_19 = params.xe{19};
else
  error 'could not find xe_19'
end
if isfield(params, 'xe_20')
  xe_20 = params.xe_20;
elseif isfield(params, 'xe')
  xe_20 = params.xe{20};
else
  error 'could not find xe_20'
end
if isfield(params, 'xe_21')
  xe_21 = params.xe_21;
elseif isfield(params, 'xe')
  xe_21 = params.xe{21};
else
  error 'could not find xe_21'
end
if isfield(params, 'xe_22')
  xe_22 = params.xe_22;
elseif isfield(params, 'xe')
  xe_22 = params.xe{22};
else
  error 'could not find xe_22'
end
if isfield(params, 'xe_23')
  xe_23 = params.xe_23;
elseif isfield(params, 'xe')
  xe_23 = params.xe{23};
else
  error 'could not find xe_23'
end
if isfield(params, 'xe_24')
  xe_24 = params.xe_24;
elseif isfield(params, 'xe')
  xe_24 = params.xe{24};
else
  error 'could not find xe_24'
end
if isfield(params, 'xe_25')
  xe_25 = params.xe_25;
elseif isfield(params, 'xe')
  xe_25 = params.xe{25};
else
  error 'could not find xe_25'
end
if isfield(params, 'xe_26')
  xe_26 = params.xe_26;
elseif isfield(params, 'xe')
  xe_26 = params.xe{26};
else
  error 'could not find xe_26'
end
if isfield(params, 'xe_27')
  xe_27 = params.xe_27;
elseif isfield(params, 'xe')
  xe_27 = params.xe{27};
else
  error 'could not find xe_27'
end
if isfield(params, 'xe_28')
  xe_28 = params.xe_28;
elseif isfield(params, 'xe')
  xe_28 = params.xe{28};
else
  error 'could not find xe_28'
end
if isfield(params, 'xe_29')
  xe_29 = params.xe_29;
elseif isfield(params, 'xe')
  xe_29 = params.xe{29};
else
  error 'could not find xe_29'
end
if isfield(params, 'xe_30')
  xe_30 = params.xe_30;
elseif isfield(params, 'xe')
  xe_30 = params.xe{30};
else
  error 'could not find xe_30'
end
if isfield(params, 'xe_31')
  xe_31 = params.xe_31;
elseif isfield(params, 'xe')
  xe_31 = params.xe{31};
else
  error 'could not find xe_31'
end
if isfield(params, 'xe_32')
  xe_32 = params.xe_32;
elseif isfield(params, 'xe')
  xe_32 = params.xe{32};
else
  error 'could not find xe_32'
end
if isfield(params, 'xe_33')
  xe_33 = params.xe_33;
elseif isfield(params, 'xe')
  xe_33 = params.xe{33};
else
  error 'could not find xe_33'
end
if isfield(params, 'xe_34')
  xe_34 = params.xe_34;
elseif isfield(params, 'xe')
  xe_34 = params.xe{34};
else
  error 'could not find xe_34'
end
if isfield(params, 'xe_35')
  xe_35 = params.xe_35;
elseif isfield(params, 'xe')
  xe_35 = params.xe{35};
else
  error 'could not find xe_35'
end
if isfield(params, 'xe_36')
  xe_36 = params.xe_36;
elseif isfield(params, 'xe')
  xe_36 = params.xe{36};
else
  error 'could not find xe_36'
end
if isfield(params, 'xe_37')
  xe_37 = params.xe_37;
elseif isfield(params, 'xe')
  xe_37 = params.xe{37};
else
  error 'could not find xe_37'
end
if isfield(params, 'xe_38')
  xe_38 = params.xe_38;
elseif isfield(params, 'xe')
  xe_38 = params.xe{38};
else
  error 'could not find xe_38'
end
if isfield(params, 'xe_39')
  xe_39 = params.xe_39;
elseif isfield(params, 'xe')
  xe_39 = params.xe{39};
else
  error 'could not find xe_39'
end
if isfield(params, 'xe_40')
  xe_40 = params.xe_40;
elseif isfield(params, 'xe')
  xe_40 = params.xe{40};
else
  error 'could not find xe_40'
end
if isfield(params, 'xe_41')
  xe_41 = params.xe_41;
elseif isfield(params, 'xe')
  xe_41 = params.xe{41};
else
  error 'could not find xe_41'
end
if isfield(params, 'xe_42')
  xe_42 = params.xe_42;
elseif isfield(params, 'xe')
  xe_42 = params.xe{42};
else
  error 'could not find xe_42'
end
if isfield(params, 'xe_43')
  xe_43 = params.xe_43;
elseif isfield(params, 'xe')
  xe_43 = params.xe{43};
else
  error 'could not find xe_43'
end
if isfield(params, 'xe_44')
  xe_44 = params.xe_44;
elseif isfield(params, 'xe')
  xe_44 = params.xe{44};
else
  error 'could not find xe_44'
end
if isfield(params, 'xe_45')
  xe_45 = params.xe_45;
elseif isfield(params, 'xe')
  xe_45 = params.xe{45};
else
  error 'could not find xe_45'
end
if isfield(params, 'xe_46')
  xe_46 = params.xe_46;
elseif isfield(params, 'xe')
  xe_46 = params.xe{46};
else
  error 'could not find xe_46'
end
if isfield(params, 'xe_47')
  xe_47 = params.xe_47;
elseif isfield(params, 'xe')
  xe_47 = params.xe{47};
else
  error 'could not find xe_47'
end
if isfield(params, 'xe_48')
  xe_48 = params.xe_48;
elseif isfield(params, 'xe')
  xe_48 = params.xe{48};
else
  error 'could not find xe_48'
end
if isfield(params, 'xe_49')
  xe_49 = params.xe_49;
elseif isfield(params, 'xe')
  xe_49 = params.xe{49};
else
  error 'could not find xe_49'
end
if isfield(params, 'xe_50')
  xe_50 = params.xe_50;
elseif isfield(params, 'xe')
  xe_50 = params.xe{50};
else
  error 'could not find xe_50'
end
if isfield(params, 'xe_51')
  xe_51 = params.xe_51;
elseif isfield(params, 'xe')
  xe_51 = params.xe{51};
else
  error 'could not find xe_51'
end
cvx_begin
  % Caution: automatically generated by cvxgen. May be incorrect.
  variable u_0;
  variable x_1(3, 1);
  variable u_1;
  variable x_2(3, 1);
  variable u_2;
  variable x_3(3, 1);
  variable u_3;
  variable x_4(3, 1);
  variable u_4;
  variable x_5(3, 1);
  variable u_5;
  variable x_6(3, 1);
  variable u_6;
  variable x_7(3, 1);
  variable u_7;
  variable x_8(3, 1);
  variable u_8;
  variable x_9(3, 1);
  variable u_9;
  variable x_10(3, 1);
  variable u_10;
  variable x_11(3, 1);
  variable u_11;
  variable x_12(3, 1);
  variable u_12;
  variable x_13(3, 1);
  variable u_13;
  variable x_14(3, 1);
  variable u_14;
  variable x_15(3, 1);
  variable u_15;
  variable x_16(3, 1);
  variable u_16;
  variable x_17(3, 1);
  variable u_17;
  variable x_18(3, 1);
  variable u_18;
  variable x_19(3, 1);
  variable u_19;
  variable x_20(3, 1);
  variable u_20;
  variable x_21(3, 1);
  variable u_21;
  variable x_22(3, 1);
  variable u_22;
  variable x_23(3, 1);
  variable u_23;
  variable x_24(3, 1);
  variable u_24;
  variable x_25(3, 1);
  variable u_25;
  variable x_26(3, 1);
  variable u_26;
  variable x_27(3, 1);
  variable u_27;
  variable x_28(3, 1);
  variable u_28;
  variable x_29(3, 1);
  variable u_29;
  variable x_30(3, 1);
  variable u_30;
  variable x_31(3, 1);
  variable u_31;
  variable x_32(3, 1);
  variable u_32;
  variable x_33(3, 1);
  variable u_33;
  variable x_34(3, 1);
  variable u_34;
  variable x_35(3, 1);
  variable u_35;
  variable x_36(3, 1);
  variable u_36;
  variable x_37(3, 1);
  variable u_37;
  variable x_38(3, 1);
  variable u_38;
  variable x_39(3, 1);
  variable u_39;
  variable x_40(3, 1);
  variable u_40;
  variable x_41(3, 1);
  variable u_41;
  variable x_42(3, 1);
  variable u_42;
  variable x_43(3, 1);
  variable u_43;
  variable x_44(3, 1);
  variable u_44;
  variable x_45(3, 1);
  variable u_45;
  variable x_46(3, 1);
  variable u_46;
  variable x_47(3, 1);
  variable u_47;
  variable x_48(3, 1);
  variable u_48;
  variable x_49(3, 1);
  variable u_49;
  variable x_50(3, 1);
  variable u_50;
  variable x_51(3, 1);

  minimize(quad_form(x_0 - xe_0, Q) + quad_form(u_0, R) + quad_form(x_1 - xe_1, Q) + quad_form(u_1, R) + quad_form(x_2 - xe_2, Q) + quad_form(u_2, R) + quad_form(x_3 - xe_3, Q) + quad_form(u_3, R) + quad_form(x_4 - xe_4, Q) + quad_form(u_4, R) + quad_form(x_5 - xe_5, Q) + quad_form(u_5, R) + quad_form(x_6 - xe_6, Q) + quad_form(u_6, R) + quad_form(x_7 - xe_7, Q) + quad_form(u_7, R) + quad_form(x_8 - xe_8, Q) + quad_form(u_8, R) + quad_form(x_9 - xe_9, Q) + quad_form(u_9, R) + quad_form(x_10 - xe_10, Q) + quad_form(u_10, R) + quad_form(x_11 - xe_11, Q) + quad_form(u_11, R) + quad_form(x_12 - xe_12, Q) + quad_form(u_12, R) + quad_form(x_13 - xe_13, Q) + quad_form(u_13, R) + quad_form(x_14 - xe_14, Q) + quad_form(u_14, R) + quad_form(x_15 - xe_15, Q) + quad_form(u_15, R) + quad_form(x_16 - xe_16, Q) + quad_form(u_16, R) + quad_form(x_17 - xe_17, Q) + quad_form(u_17, R) + quad_form(x_18 - xe_18, Q) + quad_form(u_18, R) + quad_form(x_19 - xe_19, Q) + quad_form(u_19, R) + quad_form(x_20 - xe_20, Q) + quad_form(u_20, R) + quad_form(x_21 - xe_21, Q) + quad_form(u_21, R) + quad_form(x_22 - xe_22, Q) + quad_form(u_22, R) + quad_form(x_23 - xe_23, Q) + quad_form(u_23, R) + quad_form(x_24 - xe_24, Q) + quad_form(u_24, R) + quad_form(x_25 - xe_25, Q) + quad_form(u_25, R) + quad_form(x_26 - xe_26, Q) + quad_form(u_26, R) + quad_form(x_27 - xe_27, Q) + quad_form(u_27, R) + quad_form(x_28 - xe_28, Q) + quad_form(u_28, R) + quad_form(x_29 - xe_29, Q) + quad_form(u_29, R) + quad_form(x_30 - xe_30, Q) + quad_form(u_30, R) + quad_form(x_31 - xe_31, Q) + quad_form(u_31, R) + quad_form(x_32 - xe_32, Q) + quad_form(u_32, R) + quad_form(x_33 - xe_33, Q) + quad_form(u_33, R) + quad_form(x_34 - xe_34, Q) + quad_form(u_34, R) + quad_form(x_35 - xe_35, Q) + quad_form(u_35, R) + quad_form(x_36 - xe_36, Q) + quad_form(u_36, R) + quad_form(x_37 - xe_37, Q) + quad_form(u_37, R) + quad_form(x_38 - xe_38, Q) + quad_form(u_38, R) + quad_form(x_39 - xe_39, Q) + quad_form(u_39, R) + quad_form(x_40 - xe_40, Q) + quad_form(u_40, R) + quad_form(x_41 - xe_41, Q) + quad_form(u_41, R) + quad_form(x_42 - xe_42, Q) + quad_form(u_42, R) + quad_form(x_43 - xe_43, Q) + quad_form(u_43, R) + quad_form(x_44 - xe_44, Q) + quad_form(u_44, R) + quad_form(x_45 - xe_45, Q) + quad_form(u_45, R) + quad_form(x_46 - xe_46, Q) + quad_form(u_46, R) + quad_form(x_47 - xe_47, Q) + quad_form(u_47, R) + quad_form(x_48 - xe_48, Q) + quad_form(u_48, R) + quad_form(x_49 - xe_49, Q) + quad_form(u_49, R) + quad_form(x_50 - xe_50, Q) + quad_form(u_50, R) + quad_form(x_51 - xe_51, Q_final) + quad_form(u_1 - u_0, Rd) + quad_form(u_2 - u_1, Rd) + quad_form(u_3 - u_2, Rd) + quad_form(u_4 - u_3, Rd) + quad_form(u_5 - u_4, Rd) + quad_form(u_6 - u_5, Rd) + quad_form(u_7 - u_6, Rd) + quad_form(u_8 - u_7, Rd) + quad_form(u_9 - u_8, Rd) + quad_form(u_10 - u_9, Rd) + quad_form(u_11 - u_10, Rd) + quad_form(u_12 - u_11, Rd) + quad_form(u_13 - u_12, Rd) + quad_form(u_14 - u_13, Rd) + quad_form(u_15 - u_14, Rd) + quad_form(u_16 - u_15, Rd) + quad_form(u_17 - u_16, Rd) + quad_form(u_18 - u_17, Rd) + quad_form(u_19 - u_18, Rd) + quad_form(u_20 - u_19, Rd) + quad_form(u_21 - u_20, Rd) + quad_form(u_22 - u_21, Rd) + quad_form(u_23 - u_22, Rd) + quad_form(u_24 - u_23, Rd) + quad_form(u_25 - u_24, Rd) + quad_form(u_26 - u_25, Rd) + quad_form(u_27 - u_26, Rd) + quad_form(u_28 - u_27, Rd) + quad_form(u_29 - u_28, Rd) + quad_form(u_30 - u_29, Rd) + quad_form(u_31 - u_30, Rd) + quad_form(u_32 - u_31, Rd) + quad_form(u_33 - u_32, Rd) + quad_form(u_34 - u_33, Rd) + quad_form(u_35 - u_34, Rd) + quad_form(u_36 - u_35, Rd) + quad_form(u_37 - u_36, Rd) + quad_form(u_38 - u_37, Rd) + quad_form(u_39 - u_38, Rd) + quad_form(u_40 - u_39, Rd) + quad_form(u_41 - u_40, Rd) + quad_form(u_42 - u_41, Rd) + quad_form(u_43 - u_42, Rd) + quad_form(u_44 - u_43, Rd) + quad_form(u_45 - u_44, Rd) + quad_form(u_46 - u_45, Rd) + quad_form(u_47 - u_46, Rd) + quad_form(u_48 - u_47, Rd) + quad_form(u_49 - u_48, Rd) + quad_form(u_50 - u_49, Rd));
  subject to
    x_1 == A_0*x_0 + B_0*u_0 + f0_0;
    x_2 == A_1*x_1 + B_1*u_1 + f0_1;
    x_3 == A_2*x_2 + B_2*u_2 + f0_2;
    x_4 == A_3*x_3 + B_3*u_3 + f0_3;
    x_5 == A_4*x_4 + B_4*u_4 + f0_4;
    x_6 == A_5*x_5 + B_5*u_5 + f0_5;
    x_7 == A_6*x_6 + B_6*u_6 + f0_6;
    x_8 == A_7*x_7 + B_7*u_7 + f0_7;
    x_9 == A_8*x_8 + B_8*u_8 + f0_8;
    x_10 == A_9*x_9 + B_9*u_9 + f0_9;
    x_11 == A_10*x_10 + B_10*u_10 + f0_10;
    x_12 == A_11*x_11 + B_11*u_11 + f0_11;
    x_13 == A_12*x_12 + B_12*u_12 + f0_12;
    x_14 == A_13*x_13 + B_13*u_13 + f0_13;
    x_15 == A_14*x_14 + B_14*u_14 + f0_14;
    x_16 == A_15*x_15 + B_15*u_15 + f0_15;
    x_17 == A_16*x_16 + B_16*u_16 + f0_16;
    x_18 == A_17*x_17 + B_17*u_17 + f0_17;
    x_19 == A_18*x_18 + B_18*u_18 + f0_18;
    x_20 == A_19*x_19 + B_19*u_19 + f0_19;
    x_21 == A_20*x_20 + B_20*u_20 + f0_20;
    x_22 == A_21*x_21 + B_21*u_21 + f0_21;
    x_23 == A_22*x_22 + B_22*u_22 + f0_22;
    x_24 == A_23*x_23 + B_23*u_23 + f0_23;
    x_25 == A_24*x_24 + B_24*u_24 + f0_24;
    x_26 == A_25*x_25 + B_25*u_25 + f0_25;
    x_27 == A_26*x_26 + B_26*u_26 + f0_26;
    x_28 == A_27*x_27 + B_27*u_27 + f0_27;
    x_29 == A_28*x_28 + B_28*u_28 + f0_28;
    x_30 == A_29*x_29 + B_29*u_29 + f0_29;
    x_31 == A_30*x_30 + B_30*u_30 + f0_30;
    x_32 == A_31*x_31 + B_31*u_31 + f0_31;
    x_33 == A_32*x_32 + B_32*u_32 + f0_32;
    x_34 == A_33*x_33 + B_33*u_33 + f0_33;
    x_35 == A_34*x_34 + B_34*u_34 + f0_34;
    x_36 == A_35*x_35 + B_35*u_35 + f0_35;
    x_37 == A_36*x_36 + B_36*u_36 + f0_36;
    x_38 == A_37*x_37 + B_37*u_37 + f0_37;
    x_39 == A_38*x_38 + B_38*u_38 + f0_38;
    x_40 == A_39*x_39 + B_39*u_39 + f0_39;
    x_41 == A_40*x_40 + B_40*u_40 + f0_40;
    x_42 == A_41*x_41 + B_41*u_41 + f0_41;
    x_43 == A_42*x_42 + B_42*u_42 + f0_42;
    x_44 == A_43*x_43 + B_43*u_43 + f0_43;
    x_45 == A_44*x_44 + B_44*u_44 + f0_44;
    x_46 == A_45*x_45 + B_45*u_45 + f0_45;
    x_47 == A_46*x_46 + B_46*u_46 + f0_46;
    x_48 == A_47*x_47 + B_47*u_47 + f0_47;
    x_49 == A_48*x_48 + B_48*u_48 + f0_48;
    x_50 == A_49*x_49 + B_49*u_49 + f0_49;
    x_51 == A_50*x_50 + B_50*u_50 + f0_50;
    u_0 >= u_min;
    u_1 >= u_min;
    u_2 >= u_min;
    u_3 >= u_min;
    u_4 >= u_min;
    u_5 >= u_min;
    u_6 >= u_min;
    u_7 >= u_min;
    u_8 >= u_min;
    u_9 >= u_min;
    u_10 >= u_min;
    u_11 >= u_min;
    u_12 >= u_min;
    u_13 >= u_min;
    u_14 >= u_min;
    u_15 >= u_min;
    u_16 >= u_min;
    u_17 >= u_min;
    u_18 >= u_min;
    u_19 >= u_min;
    u_20 >= u_min;
    u_21 >= u_min;
    u_22 >= u_min;
    u_23 >= u_min;
    u_24 >= u_min;
    u_25 >= u_min;
    u_26 >= u_min;
    u_27 >= u_min;
    u_28 >= u_min;
    u_29 >= u_min;
    u_30 >= u_min;
    u_31 >= u_min;
    u_32 >= u_min;
    u_33 >= u_min;
    u_34 >= u_min;
    u_35 >= u_min;
    u_36 >= u_min;
    u_37 >= u_min;
    u_38 >= u_min;
    u_39 >= u_min;
    u_40 >= u_min;
    u_41 >= u_min;
    u_42 >= u_min;
    u_43 >= u_min;
    u_44 >= u_min;
    u_45 >= u_min;
    u_46 >= u_min;
    u_47 >= u_min;
    u_48 >= u_min;
    u_49 >= u_min;
    u_50 >= u_min;
    u_0 <= u_max;
    u_1 <= u_max;
    u_2 <= u_max;
    u_3 <= u_max;
    u_4 <= u_max;
    u_5 <= u_max;
    u_6 <= u_max;
    u_7 <= u_max;
    u_8 <= u_max;
    u_9 <= u_max;
    u_10 <= u_max;
    u_11 <= u_max;
    u_12 <= u_max;
    u_13 <= u_max;
    u_14 <= u_max;
    u_15 <= u_max;
    u_16 <= u_max;
    u_17 <= u_max;
    u_18 <= u_max;
    u_19 <= u_max;
    u_20 <= u_max;
    u_21 <= u_max;
    u_22 <= u_max;
    u_23 <= u_max;
    u_24 <= u_max;
    u_25 <= u_max;
    u_26 <= u_max;
    u_27 <= u_max;
    u_28 <= u_max;
    u_29 <= u_max;
    u_30 <= u_max;
    u_31 <= u_max;
    u_32 <= u_max;
    u_33 <= u_max;
    u_34 <= u_max;
    u_35 <= u_max;
    u_36 <= u_max;
    u_37 <= u_max;
    u_38 <= u_max;
    u_39 <= u_max;
    u_40 <= u_max;
    u_41 <= u_max;
    u_42 <= u_max;
    u_43 <= u_max;
    u_44 <= u_max;
    u_45 <= u_max;
    u_46 <= u_max;
    u_47 <= u_max;
    u_48 <= u_max;
    u_49 <= u_max;
    u_50 <= u_max;
cvx_end
vars.u_0 = u_0;
vars.u_1 = u_1;
vars.u{1} = u_1;
vars.u_2 = u_2;
vars.u{2} = u_2;
vars.u_3 = u_3;
vars.u{3} = u_3;
vars.u_4 = u_4;
vars.u{4} = u_4;
vars.u_5 = u_5;
vars.u{5} = u_5;
vars.u_6 = u_6;
vars.u{6} = u_6;
vars.u_7 = u_7;
vars.u{7} = u_7;
vars.u_8 = u_8;
vars.u{8} = u_8;
vars.u_9 = u_9;
vars.u{9} = u_9;
vars.u_10 = u_10;
vars.u{10} = u_10;
vars.u_11 = u_11;
vars.u{11} = u_11;
vars.u_12 = u_12;
vars.u{12} = u_12;
vars.u_13 = u_13;
vars.u{13} = u_13;
vars.u_14 = u_14;
vars.u{14} = u_14;
vars.u_15 = u_15;
vars.u{15} = u_15;
vars.u_16 = u_16;
vars.u{16} = u_16;
vars.u_17 = u_17;
vars.u{17} = u_17;
vars.u_18 = u_18;
vars.u{18} = u_18;
vars.u_19 = u_19;
vars.u{19} = u_19;
vars.u_20 = u_20;
vars.u{20} = u_20;
vars.u_21 = u_21;
vars.u{21} = u_21;
vars.u_22 = u_22;
vars.u{22} = u_22;
vars.u_23 = u_23;
vars.u{23} = u_23;
vars.u_24 = u_24;
vars.u{24} = u_24;
vars.u_25 = u_25;
vars.u{25} = u_25;
vars.u_26 = u_26;
vars.u{26} = u_26;
vars.u_27 = u_27;
vars.u{27} = u_27;
vars.u_28 = u_28;
vars.u{28} = u_28;
vars.u_29 = u_29;
vars.u{29} = u_29;
vars.u_30 = u_30;
vars.u{30} = u_30;
vars.u_31 = u_31;
vars.u{31} = u_31;
vars.u_32 = u_32;
vars.u{32} = u_32;
vars.u_33 = u_33;
vars.u{33} = u_33;
vars.u_34 = u_34;
vars.u{34} = u_34;
vars.u_35 = u_35;
vars.u{35} = u_35;
vars.u_36 = u_36;
vars.u{36} = u_36;
vars.u_37 = u_37;
vars.u{37} = u_37;
vars.u_38 = u_38;
vars.u{38} = u_38;
vars.u_39 = u_39;
vars.u{39} = u_39;
vars.u_40 = u_40;
vars.u{40} = u_40;
vars.u_41 = u_41;
vars.u{41} = u_41;
vars.u_42 = u_42;
vars.u{42} = u_42;
vars.u_43 = u_43;
vars.u{43} = u_43;
vars.u_44 = u_44;
vars.u{44} = u_44;
vars.u_45 = u_45;
vars.u{45} = u_45;
vars.u_46 = u_46;
vars.u{46} = u_46;
vars.u_47 = u_47;
vars.u{47} = u_47;
vars.u_48 = u_48;
vars.u{48} = u_48;
vars.u_49 = u_49;
vars.u{49} = u_49;
vars.u_50 = u_50;
vars.u{50} = u_50;
vars.x_1 = x_1;
vars.x{1} = x_1;
vars.x_2 = x_2;
vars.x{2} = x_2;
vars.x_3 = x_3;
vars.x{3} = x_3;
vars.x_4 = x_4;
vars.x{4} = x_4;
vars.x_5 = x_5;
vars.x{5} = x_5;
vars.x_6 = x_6;
vars.x{6} = x_6;
vars.x_7 = x_7;
vars.x{7} = x_7;
vars.x_8 = x_8;
vars.x{8} = x_8;
vars.x_9 = x_9;
vars.x{9} = x_9;
vars.x_10 = x_10;
vars.x{10} = x_10;
vars.x_11 = x_11;
vars.x{11} = x_11;
vars.x_12 = x_12;
vars.x{12} = x_12;
vars.x_13 = x_13;
vars.x{13} = x_13;
vars.x_14 = x_14;
vars.x{14} = x_14;
vars.x_15 = x_15;
vars.x{15} = x_15;
vars.x_16 = x_16;
vars.x{16} = x_16;
vars.x_17 = x_17;
vars.x{17} = x_17;
vars.x_18 = x_18;
vars.x{18} = x_18;
vars.x_19 = x_19;
vars.x{19} = x_19;
vars.x_20 = x_20;
vars.x{20} = x_20;
vars.x_21 = x_21;
vars.x{21} = x_21;
vars.x_22 = x_22;
vars.x{22} = x_22;
vars.x_23 = x_23;
vars.x{23} = x_23;
vars.x_24 = x_24;
vars.x{24} = x_24;
vars.x_25 = x_25;
vars.x{25} = x_25;
vars.x_26 = x_26;
vars.x{26} = x_26;
vars.x_27 = x_27;
vars.x{27} = x_27;
vars.x_28 = x_28;
vars.x{28} = x_28;
vars.x_29 = x_29;
vars.x{29} = x_29;
vars.x_30 = x_30;
vars.x{30} = x_30;
vars.x_31 = x_31;
vars.x{31} = x_31;
vars.x_32 = x_32;
vars.x{32} = x_32;
vars.x_33 = x_33;
vars.x{33} = x_33;
vars.x_34 = x_34;
vars.x{34} = x_34;
vars.x_35 = x_35;
vars.x{35} = x_35;
vars.x_36 = x_36;
vars.x{36} = x_36;
vars.x_37 = x_37;
vars.x{37} = x_37;
vars.x_38 = x_38;
vars.x{38} = x_38;
vars.x_39 = x_39;
vars.x{39} = x_39;
vars.x_40 = x_40;
vars.x{40} = x_40;
vars.x_41 = x_41;
vars.x{41} = x_41;
vars.x_42 = x_42;
vars.x{42} = x_42;
vars.x_43 = x_43;
vars.x{43} = x_43;
vars.x_44 = x_44;
vars.x{44} = x_44;
vars.x_45 = x_45;
vars.x{45} = x_45;
vars.x_46 = x_46;
vars.x{46} = x_46;
vars.x_47 = x_47;
vars.x{47} = x_47;
vars.x_48 = x_48;
vars.x{48} = x_48;
vars.x_49 = x_49;
vars.x{49} = x_49;
vars.x_50 = x_50;
vars.x{50} = x_50;
vars.x_51 = x_51;
vars.x{51} = x_51;
status.cvx_status = cvx_status;
% Provide a drop-in replacement for csolve.
status.optval = cvx_optval;
status.converged = strcmp(cvx_status, 'Solved');
