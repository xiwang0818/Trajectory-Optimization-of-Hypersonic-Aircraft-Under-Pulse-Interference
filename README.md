# Trajectory-Optimization-of-Hypersonic-Aircraft-Under-Pulse-Interference
This is a project that I've done to keep the stable track of Hypersonic Aircraft despite of pulse interference. 
For the project I mainly used Matlab, as well as solver tools in c.

#Docu_Catalogue
main_Algorithm: main Realization Process of the program.
nominal_value: normal values to refer for Hypersonic Aircraft.
cvxgen: convex optimization solver tool.

#Introduction
When the operating status of hypersonic Aircraft changes suddenly,for example, the ignition and flameout of the engine,wind shear interference,etc,the control system would suffer momentary and immense interference, which can easily lead to conspicuous deviation of the track of the hypersonic aircraft, thus brings tackles to the design of the guidance control system. We describe this typical kind of interference as pulse jamming. We find it difficult to reach the design requirement using traditional off-line design control law. To deal with this problem, in this project I focus on the longitudinal plane, and study the track optimization of the hypersonic aircraft in this case. First, I build up the model, after linearization and discretization, basing on convex optimization solution tool cvxgen, I realize the control arithmetic which combines Model Prediction Control and Iterative Approximation,using real-time update, track the nominal trajectory. The convex optimization solution tool CVXGEN, of which each step lasts only around millisecond, which assures the feasibility of this method, can be used to this problem. Through tuning parameters ,restriction,weight matrix, I study optimization characteristics under different setting combinations, eventually product the most accurate feasible on-line track. As is illustrated by the simulation result, on the premise of control variable restriction, the optimization scheme basing on the design method above can make the hypersonic aircraft acquire excellent track optimization characteristics.
