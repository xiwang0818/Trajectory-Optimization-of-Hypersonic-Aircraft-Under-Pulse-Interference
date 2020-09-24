dimensions
  n = 3
  m = 1
  T = 10
end

parameters
  A[t] (n,n), t=0..T
  B[t] (n,m), t=0..T
  x[0] (n)
  u_max nonnegative
  u_min 
  xe[t] (n), t=0..T+1
  f0[t] (n), t=0..T
  Q (n,n) psd
  R psd
  Rd psd
  Q_final (n,n) psd   
end

variables
  
  x[t] (n), t=1..T+1
  u[t] (m), t=0..T
end

minimize
  sum[t=0..T](quad(x[t]-xe[t], Q)+quad(u[t], R))+quad(x[T+1]-xe[T+1],Q_final)+sum[t=1..T](quad(u[t]-u[t-1], Rd))
subject to
  x[t+1] == A[t]*x[t]+B[t]*u[t]+f0[t], t=0..T
  u[t] >= u_min, t=0..T
  u[t] <= u_max, t=0..T
end
?