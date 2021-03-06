% Produced by CVXGEN, 2017-04-25 21:53:09 -0400.
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
%B_0 = params.B_0;
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
Q = params.Q;
Q_final = params.Q_final;
R = params.R;
Rd = params.Rd;
u_max = params.u_max;
u_min = params.u_min;
%x_0 = params.x_0;
%xe_0 = params.xe_0;
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
cvx_begin
  % Caution: automatically generated by cvxgen. May be incorrect.
  variable u_0;
  u_0 >= 0;
  variable x_1(3, 1);
  variable u_1;
  u_1 >= 0;
  variable x_2(3, 1);
  variable u_2;
  u_2 >= 0;
  variable x_3(3, 1);
  variable u_3;
  u_3 >= 0;
  variable x_4(3, 1);
  variable u_4;
  u_4 >= 0;
  variable x_5(3, 1);
  variable u_5;
  u_5 >= 0;
  variable x_6(3, 1);
  variable u_6;
  u_6 >= 0;
  variable x_7(3, 1);
  variable u_7;
  u_7 >= 0;
  variable x_8(3, 1);
  variable u_8;
  u_8 >= 0;
  variable x_9(3, 1);
  variable u_9;
  u_9 >= 0;
  variable x_10(3, 1);
  variable u_10;
  u_10 >= 0;
  variable x_11(3, 1);

  minimize(quad_form(x_0 - xe_0, Q) + quad_form(u_0, R) + quad_form(x_1 - xe_1, Q) + quad_form(u_1, R) + quad_form(x_2 - xe_2, Q) + quad_form(u_2, R) + quad_form(x_3 - xe_3, Q) + quad_form(u_3, R) + quad_form(x_4 - xe_4, Q) + quad_form(u_4, R) + quad_form(x_5 - xe_5, Q) + quad_form(u_5, R) + quad_form(x_6 - xe_6, Q) + quad_form(u_6, R) + quad_form(x_7 - xe_7, Q) + quad_form(u_7, R) + quad_form(x_8 - xe_8, Q) + quad_form(u_8, R) + quad_form(x_9 - xe_9, Q) + quad_form(u_9, R) + quad_form(x_10 - xe_10, Q) + quad_form(u_10, R) + quad_form(x_11 - xe_11, Q_final) + quad_form(u_1 - u_0, Rd) + quad_form(u_2 - u_1, Rd) + quad_form(u_3 - u_2, Rd) + quad_form(u_4 - u_3, Rd) + quad_form(u_5 - u_4, Rd) + quad_form(u_6 - u_5, Rd) + quad_form(u_7 - u_6, Rd) + quad_form(u_8 - u_7, Rd) + quad_form(u_9 - u_8, Rd) + quad_form(u_10 - u_9, Rd));
  subject to
    x_1 == A_0*x_0 + B_0*u_0;
    x_2 == A_1*x_1 + B_1*u_1;
    x_3 == A_2*x_2 + B_2*u_2;
    x_4 == A_3*x_3 + B_3*u_3;
    x_5 == A_4*x_4 + B_4*u_4;
    x_6 == A_5*x_5 + B_5*u_5;
    x_7 == A_6*x_6 + B_6*u_6;
    x_8 == A_7*x_7 + B_7*u_7;
    x_9 == A_8*x_8 + B_8*u_8;
    x_10 == A_9*x_9 + B_9*u_9;
    x_11 == A_10*x_10 + B_10*u_10;
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
status.cvx_status = cvx_status;
% Provide a drop-in replacement for csolve.
status.optval = cvx_optval;
status.converged = strcmp(cvx_status, 'Solved');
