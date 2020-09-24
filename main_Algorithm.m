close all
clear
clc

figure(5)
hold

alpha_min=0*pi/180;alpha_max=5*pi/180;                                          %%%%%%%%%%%%%%%%%%数据输入
m=136820;
rho=0.012537;
Re=6371387;
s=334.73;
CT=0.02576;
mu=3.936*10^14;
g0=9.8;
eta=1;

 load sam01f02;
 
 for k=1:length(te);
     
 a{k}=[1/m*rho*s*ve(k)*(CT*cos(alphae(k))-0.645*(alphae(k))^2-0.0043378*alphae(k)-0.003772) -mu*cos(thetae(k))/(he(k)+Re)^2 2* ...
 mu*sin(thetae(k))/(he(k)+Re)^3;1/(2*m)*rho*s*(0.6203*alphae(k)+sin(alphae(k))*CT)+cos(thetae(k))/(he(k)+Re)+mu* ...
 cos(thetae(k))/(ve(k)^2*(he(k)+Re)^2) sin(thetae(k))*(mu-((ve(k))^2)*(he(k)+Re))/(ve(k)*(he(k)+Re)^2) 2* ...
 mu*cos(thetae(k))/(ve(k)*(he(k)+Re)^3)-ve(k)*cos(thetae(k))/(he(k)+Re)^2;sin(thetae(k)) (ve(k))*cos(thetae(k)) 0];
 b{k}=[1/(2*m)*s*rho*ve(k)^2*(-0.02576*sin(alphae(k))-1.29*alphae(k)-0.0043378);1/(2*m)*s*rho*ve(k)*(CT*cos(alphae(k))+0.6203);0];
%       a1{k}=[1/m*rho*s*ve(k)*(0.002576*eta*cos(alphae(k))-0.645*(alphae(k))^2-0.0043378*alphae(k)-0.003772) -mu*cos(thetae(k))/(he(k)+Re)^2 2* ...
%         mu*sin(thetae(k))/(he(k)+Re)^3;1/(2*m)*rho*s*(0.6203*alphae(k)+sin(alphae(k))*0.002576*eta)+cos(thetae(k))/(he(k)+Re)+mu* ...
%         cos(thetae(k))/(ve(k)^2*(he(k)+Re)^2) sin(thetae(k))*(mu-((ve(k))^2)*(he(k)+Re))/(ve(k)*(he(k)+Re)^2) 2* ...
%         mu*cos(thetae(k))/(ve(k)*(he(k)+Re)^3)-ve(k)*cos(thetae(k))/(he(k)+Re)^2;sin(thetae(k)) (ve(k))*cos(thetae(k)) 0];
%      b1{k}=[1/(2*m)*s*rho*(ve(k))^2*(-0.02576*eta*sin(alphae(k))-1.29*alphae(k)-0.0043378); 1/(2*m)*s*rho*ve(k)*(0.02576*eta*cos(alphae(k))+0.6203); 0];
 end

 
params.Q=[0.1 0 0;0 1 0;0 0 1];
params.Q_final= eye(3);                                         
params.R=100;  
params.Rd= 100;                                                      
params.u_max=alpha_max;
params.u_min=alpha_min;

v=4590.3+5;
theta=0;                                                           %%%%%%%%%%%%%%输入初值x(0) 
h=33528+20;
x(:,1)=[v theta h]';
 xr(:,1)=x(:,1);
delta=0.1;
p=50;                                                               
   k=1; 
   tf=0;
    xi=xe;
for t=0:delta:tf;   
    ts(k)=t;
 params.x_0=x(:,k);


for j=1:1:30;
 
 params.A_0=a{k}*delta+eye(3);
 params.B_0=b{k}*delta;
 params.xe_0=xi(:,k);
 params.xe_51=xi(:,k+51);
 params.f0_0=f0{k};
% xr(:,k+1)=xr(:,k)+delta*f11{k};
     
   for i= 1:p;
params.A{i}=a{k+i}*delta+eye(3);
params.B{i}=b{k+i}*delta;                                                   %%%%%%%%%%%%离散化
params.xe{i}=xi(:,k+i);
params.f0{i}=f0{k+i};

%xr(:,k+i+1)=xr(:,k+i)+delta*f11{k+i};
   end
  
   
settings.verbose = 0;  % disable output of solver progress.
settings.max_iters = 60;  % reduce the maximum iteration count, from 25.
settings.eps = 1e-6;  % reduce the required objective tolerance, from 1e-6.
settings.resid_tol = 1e-2;  % reduce the required residual tolerances, from 1e-4.
%   tic
  [vars, status] = csolve(params,settings);                 %csolve(params,settings);%cvxsolve(params, settings)
%   toc
  
ui(k)=vars.u_0;
  
  i=0;
xi(:,k+i) = x(:,k);   
    vi=xi(1,k+i);
    thetai=xi(2,k+i);
    hi=xi(3,k+i);
    alphai=ui(k+i);
    xr(:,k+i) = x(:,k);  
     vr=xr(1,k+i);
    thetar=xr(2,k+i);
    hr=xr(3,k+i);
   
    
  a{k+i}=[1/m*rho*s*vi*(CT*cos(alphai)-0.645*(alphai)^2-0.0043378*alphai-0.003772) -mu*cos(thetai)/(hi+Re)^2 2* ...
mu*sin(thetai)/(hi+Re)^3;1/(2*m)*rho*s*(0.6203*alphai+sin(alphai)*CT)+cos(thetai)/(hi+Re)+mu* ...
cos(thetai)/(vi^2*(hi+Re)^2) sin(thetai)*(mu-((vi)^2)*(hi+Re))/(vi*(hi+Re)^2) 2* ...
mu*cos(thetai)/(vi*(hi+Re)^3)-vi*cos(thetai)/(hi+Re)^2;sin(thetai) (vi)*cos(thetai) 0];
b{k+i}=[1/(2*m)*s*rho*vi^2*(-0.02576*sin(alphai)-1.29*alphai-0.0043378);1/(2*m)*s*rho*vi*(CT*cos(alphai)+0.6203);0];
f1=[1/(2*m)*rho*vi^2*s*(0.02576*eta*cos(alphai)-(0.645*alphai^2+0.0043378*alphai+0.003772))-mu*sin(thetai)/(hi+Re)^2;rho* ...
    s*vi*(0.6203*alphai+0.02576*eta*sin(alphai))/(2*m)-(mu-vi^2*(hi+Re))*cos(thetai)/(vi*(hi+Re)^2);vi*sin(thetai)] ;    
fr1=[1/(2*m)*rho*vr^2*s*(0.02576*eta*cos(alphai)-(0.645*alphai^2+0.0043378*alphai+0.003772))-mu*sin(thetar)/(hr+Re)^2;rho* ...
    s*vr*(0.6203*alphai+0.02576*eta*sin(alphai))/(2*m)-(mu-vr^2*(hr+Re))*cos(thetar)/(vi*(hr+Re)^2);vr*sin(thetar)] ;    
f2=a{k+i}*xi(:,k+i)+b{k+i}*ui(k+i);
f0{k+i}=delta*(f1-f2);   
f11{k+i}=fr1;
xr(:,k+i+1)=xr(:,k+i)+delta*f11{k+i};

  for i=1:p;
    ui(k+i) = vars.u{i};      
    xi(:,k+i) = vars.x{i};   
    vi=xi(1,k+i);
    thetai=xi(2,k+i);
    hi=xi(3,k+i);
    alphai=ui(k+i);
     vr=xr(1,k+i);
    thetar=xr(2,k+i);
    hr=xr(3,k+i);
    
a{k+i}=[1/m*rho*s*vi*(CT*cos(alphai)-0.645*(alphai)^2-0.0043378*alphai-0.003772) -mu*cos(thetai)/(hi+Re)^2 2* ...
mu*sin(thetai)/(hi+Re)^3;1/(2*m)*rho*s*(0.6203*alphai+sin(alphai)*CT)+cos(thetai)/(hi+Re)+mu* ...
cos(thetai)/(vi^2*(hi+Re)^2) sin(thetai)*(mu-((vi)^2)*(hi+Re))/(vi*(hi+Re)^2) 2* ...
mu*cos(thetai)/(vi*(hi+Re)^3)-vi*cos(thetai)/(hi+Re)^2;sin(thetai) (vi)*cos(thetai) 0];
b{k+i}=[1/(2*m)*s*rho*vi^2*(-0.02576*sin(alphai)-1.29*alphai-0.0043378);1/(2*m)*s*rho*vi*(CT*cos(alphai)+0.6203);0];
f1=[1/(2*m)*rho*vi^2*s*(0.02576*eta*cos(alphai)-(0.645*alphai^2+0.0043378*alphai+0.003772))-mu*sin(thetai)/(hi+Re)^2;rho* ...
    s*vi*(0.6203*alphai+0.02576*eta*sin(alphai))/(2*m)-(mu-vi^2*(hi+Re))*cos(thetai)/(vi*(hi+Re)^2);vi*sin(thetai)];    
fr1=[1/(2*m)*rho*vr^2*s*(0.02576*eta*cos(alphai)-(0.645*alphai^2+0.0043378*alphai+0.003772))-mu*sin(thetar)/(hr+Re)^2;rho* ...
    s*vr*(0.6203*alphai+0.02576*eta*sin(alphai))/(2*m)-(mu-vr^2*(hr+Re))*cos(thetar)/(vi*(hr+Re)^2);vr*sin(thetar)] ;   
f2=a{k+i}*xi(:,k+i)+b{k+i}*ui(k+i);
f0{k+i}=delta*(f1-f2);        
f11{k+i}=fr1;

xr(:,k+i+1)=xr(:,k+i)+delta*f11{k+i};
  end
% 
   if k==1  ;
       if j==30;
figure(5)
plot(xi(3,1:51))
ylabel('h/m')
grid on
legend('优化值')


figure(5)
plot(xr(3,k:k+p),'s')
ylabel('h/m')
grid on
legend('优化轨迹')
       else
           figure(5)
plot(xi(3,1:51))
ylabel('h/m')
grid on
legend('优化值')


figure(5)
plot(xr(3,k:k+p),'.')
ylabel('h/m')
grid on
legend('优化轨迹')
       end
end
   

  end   
 u(k) = vars.u_0; 
   
  g=g0*Re^2/(Re+h(k))^2;
  q=1/2*rho*(v(k))^2;
   r=h(k)+Re;
  if ts(k)>24 && ts(k)<25;
   L=q*s*0.6203*u(k)+(0.001*sin(50*ts(k))+0.1)*m*g;
   T=q*s*0.02576+(0.001*sin(50*ts(k))+0.1)*m*g;     
    
  else
   L=q*s*0.6203*u(k);
   T=q*s*0.02576;
  end

   D=q*s*(0.645*u(k)^2+0.0043378*u(k)+0.003772);
  Lk(k)=L;
  Tk(k)=T;
  v(k+1)=v(k)+delta*((T*cos(u(k))-D)/m-mu*sin(theta(k))/r^2);
  theta(k+1)=theta(k)+delta*((L+T*sin(u(k)))/m/v(k)-((mu-(v(k))^2*r)*cos(theta(k)))/v(k)/r^2);
  h(k+1)=h(k)+delta*(v(k)*sin(theta(k)));  
  x(:,k+1)=[v(k+1) theta(k+1) h(k+1)]'; 

  k=k+1;

end
   
%      figure(6)
%     plot(ts,Lk,ts,Tk)
%     grid on                                                      %%%%%%%%%%%%%%%%输出升力、推力图像
%    xlabel('t/s');box off
%    ylabel('F/N')
%    legend('升力','推力')
% 
% figure(1)
% plot(ts,x(1,1:end-1),ts,xe(1,1:size(ts,2)))
% grid on
% xlabel('t/s');box off
% ylabel('v/(m/s)')
% legend('实际值','标称值')
% 
% figure(2)
% plot(ts,x(2,1:end-1),ts,xe(2,1:size(ts,2)))
% grid on
% xlabel('t/s');box off
% ylabel('theta/rad')
% legend('实际值','标称值')
%  
% figure(3)
% plot(ts,x(3,1:end-1),ts,xe(3,1:size(ts,2)))
% grid on
% xlabel('t/s');box off
% ylabel('h/m')
% legend('实际轨迹','标称轨迹')
% 
% figure(4)
% plot(ts,u,ts,ue(1:501)) 
% grid on
% xlabel('t/s');box off
% ylabel('alpha/rad')
% legend('实际值','标称值')

 
 figure(5)
plot(xe(3,(1:51)),'*')
grid on
ylabel('h/m')

legend('标称轨迹')

% figure(5)
% plot(xi(3,1:p+1),'*')
% grid on
% figure(5)
% plot(xr(3,1:p+1),'*')
% grid on


% figure
% subplot(2,2,1)
% plot(ts,x(1,1:end-1),ts,xe(1,1:size(ts,2)))
% grid on
% xlabel('t/s');box off
% ylabel('v/(m/s)')
% legend('实际值','标称值')
% 
% subplot(2,2,2)
% plot(ts,x(2,1:end-1),ts,xe(2,1:size(ts,2)))
% grid on
% xlabel('t/s');box off
% ylabel('theta/rad')
% legend('实际值','标称值')
%  
% subplot(2,2,3)
% plot(ts,x(3,1:end-1),ts,xe(3,1:size(ts,2)))
% grid on
% xlabel('t/s');box off
% ylabel('h/m')
% legend('实际轨迹','标称轨迹')
% 
% subplot(2,2,4)
% plot(ts,u,ts,ue(1:501)) 
% grid on
% xlabel('t/s');box off
% ylabel('alpha/rad')
% legend('实际值','标称值')
%   
