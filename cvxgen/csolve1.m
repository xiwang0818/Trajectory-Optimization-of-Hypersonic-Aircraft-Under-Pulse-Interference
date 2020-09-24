% csolve  Solves a custom quadratic program very rapidly.
%
% [vars, status] = csolve(params, settings)
%
% solves the convex optimization problem
%
%   minimize(quad_form(x_0 - xe_0, Q) + quad_form(u_0, R) + quad_form(x_1 - xe_1, Q) + quad_form(u_1, R) + quad_form(x_2 - xe_2, Q) + quad_form(u_2, R) + quad_form(x_3 - xe_3, Q) + quad_form(u_3, R) + quad_form(x_4 - xe_4, Q) + quad_form(u_4, R) + quad_form(x_5 - xe_5, Q) + quad_form(u_5, R) + quad_form(x_6 - xe_6, Q) + quad_form(u_6, R) + quad_form(x_7 - xe_7, Q) + quad_form(u_7, R) + quad_form(x_8 - xe_8, Q) + quad_form(u_8, R) + quad_form(x_9 - xe_9, Q) + quad_form(u_9, R) + quad_form(x_10 - xe_10, Q) + quad_form(u_10, R) + quad_form(x_11 - xe_11, Q_final) + quad_form(u_1 - u_0, Rd) + quad_form(u_2 - u_1, Rd) + quad_form(u_3 - u_2, Rd) + quad_form(u_4 - u_3, Rd) + quad_form(u_5 - u_4, Rd) + quad_form(u_6 - u_5, Rd) + quad_form(u_7 - u_6, Rd) + quad_form(u_8 - u_7, Rd) + quad_form(u_9 - u_8, Rd) + quad_form(u_10 - u_9, Rd))
%   subject to
%     x_1 == A_0*x_0 + B_0*u_0
%     x_2 == A_1*x_1 + B_1*u_1
%     x_3 == A_2*x_2 + B_2*u_2
%     x_4 == A_3*x_3 + B_3*u_3
%     x_5 == A_4*x_4 + B_4*u_4
%     x_6 == A_5*x_5 + B_5*u_5
%     x_7 == A_6*x_6 + B_6*u_6
%     x_8 == A_7*x_7 + B_7*u_7
%     x_9 == A_8*x_8 + B_8*u_8
%     x_10 == A_9*x_9 + B_9*u_9
%     x_11 == A_10*x_10 + B_10*u_10
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
%
% with variables
%      u_0   1 x 1    positive
%      u_1   1 x 1    positive
%      u_2   1 x 1    positive
%      u_3   1 x 1    positive
%      u_4   1 x 1    positive
%      u_5   1 x 1    positive
%      u_6   1 x 1    positive
%      u_7   1 x 1    positive
%      u_8   1 x 1    positive
%      u_9   1 x 1    positive
%     u_10   1 x 1    positive
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
%        Q   3 x 3    PSD
%  Q_final   3 x 3    PSD
%        R   1 x 1    PSD
%       Rd   1 x 1    PSD
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
%
% Note:
%   - Check status.converged, which will be 1 if optimization succeeded.
%   - You don't have to specify settings if you don't want to.
%   - To hide output, use settings.verbose = 0.
%   - To change iterations, use settings.max_iters = 20.
%   - You may wish to compare with cvxsolve to check the solver is correct.
%
% Specify params.A_0, ..., params.xe_11, then run
%   [vars, status] = csolve(params, settings)
% Produced by CVXGEN, 2017-04-25 21:53:09 -0400.
% CVXGEN is Copyright (C) 2006-2012 Jacob Mattingley, jem@cvxgen.com.
% The code in this file is Copyright (C) 2006-2012 Jacob Mattingley.
% CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial
% applications without prior written permission from Jacob Mattingley.

% Filename: csolve.m.
% Description: Help file for the Matlab solver interface.
