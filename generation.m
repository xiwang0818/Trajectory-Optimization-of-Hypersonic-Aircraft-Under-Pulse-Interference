clear
close all
figure(1); hold;
% figure(2);hold;
% figure(3);hold;
p=50;
alpha_min=0*pi/180;alpha_max=20*pi/180;                                          %%%%%%%%%%%%%%%%%% ˝æ› ‰»Î
m=136820;
rho=0.012537;
Re=6371387;
s=334.73;
% CT=0.02576;
mu=3.936*10^14;

 load sam01f02;
xe1=xe;
t1=0;tf=5;
delt=0.1;cdelt=0.5;
cc=0;
%  for k=1:size(te,2)
%      a{k}=[1/m*rho*s*ve(k)*(CT-0.645*(alphae(k))^2+0.0043378*alphae(k)+0.003772) -mu*cos(thetae(k))/(he(k)+Re)^2 -2* ...
%         mu*sin(thetae(k))/(he(k)+Re)^3;1/(2*m)*rho*s*(0.6203*alphae(k)+sin(alphae(k))*CT)+cos(thetae(k))/(he(k)+Re)+mu* ...
%         cos(thetae(k))/(ve(k)^2*(he(k)+Re)^2) sin(thetae(k))*(mu-((ve(k))^2)*(he(k)+Re))/(ve(k)*(he(k)+Re)^2) 2* ...
%         mu*cos(thetae(k))/(ve(k)*(he(k)+Re)^3)-ve(k)*cos(thetae(k))/(he(k)+Re)^2;sin(thetae(k)) (ve(k))*cos(thetae(k)) 0];
%      b{k}=[1/(2*m)*s*rho*ve(k)*(-1.29*alphae(k)+0.0043378); 1/(2*m)*s*rho*ve(k)*(CT*cos(alphae(k))+0.6203); 0];
%      A{k}=a{k}*delt+eye(3);
%      B{k}=b{k}*delt;
%  end
eta=1;
k=1;
v(1)=4590.3+5;
h(1)=33528+10;
theta(1)=0.00;
x(:,1)=[v(1);theta(1);h(1)];
xr(:,k)=x(:,1);
params.Q=[1 0 0;0 1 0;0 0 1];
params.Q_final= [1 0 0;0 1 0;0 0 1]*1;                                         
params.R=100;  
params.Rd=100;                                                      
params.u_max=alpha_max;
params.u_min=alpha_min;
settings.verbose = 0;  % disable output of solver progress.
settings.max_iters = 60;  % reduce the maximum iteration count, from 25.
settings.eps = 1e-6;  % reduce the required objective tolerance, from 1e-6.
settings.resid_tol = 1e-2;  % reduce the required residual tolerances, from 1e-4.
nn=10;
k=t1/delt+1;
   for kk=1:nn
       
    params.x_0=x(:,k);
    params.xe_0=xe(:,k);
    params.A_0=A{k};
    params.B_0=B{k};
    params.f0_0=f0{k};
    xr(:,k+1)=xr(:,k)+delt*f11{k};
    for i= 1:p
        params.A{i}=A{k+i};
        params.B{i}=B{k+i};  
        params.xe{i}=xe(:,k+i);
        params.f0{i}=f0{k+i};
        xr(:,k+i+1)=xr(:,k+i)+delt*f11{k+i};
    end
    params.xe{p+1}=xe(:,k+p+1);
     plot(xe(3,k:k+p+1));
    plot(xr(3,k:k+p+1));
[vars, status] = csolve(params,settings);
xe(:,k)=params.x_0;
ue(k)=vars.u_0;
alphae(k)=ue(k);
    a{k}=[1/m*rho*s*ve(k)*(0.002576*eta*cos(alphae(k))-0.645*(alphae(k))^2-0.0043378*alphae(k)-0.003772) -mu*cos(thetae(k))/(he(k)+Re)^2 2* ...
        mu*sin(thetae(k))/(he(k)+Re)^3;...
        1/(2*m)*rho*s*(0.6203*alphae(k)+sin(alphae(k))*0.002576*eta)+cos(thetae(k))/(he(k)+Re)+mu* ...
        cos(thetae(k))/(ve(k)^2*(he(k)+Re)^2) sin(thetae(k))*(mu-((ve(k))^2)*(he(k)+Re))/(ve(k)*(he(k)+Re)^2) 2* ...
        mu*cos(thetae(k))/(ve(k)*(he(k)+Re)^3)-ve(k)*cos(thetae(k))/(he(k)+Re)^2;sin(thetae(k)) (ve(k))*cos(thetae(k)) 0];
     b{k}=[1/(2*m)*s*rho*(ve(k))^2*(-0.02576*eta*sin(alphae(k))-1.29*alphae(k)-0.0043378); 1/(2*m)*s*rho*ve(k)*(0.02576*eta*cos(alphae(k))+0.6203); 0];
     A{k}=a{k}*delt+eye(3);
     B{k}=b{k}*delt;
     h(k)=he(k);
     v(k)=ve(k);
     theta(k)=thetae(k);
     u(k)=ue(k);
     f1=[1/(2*m)*rho*v(k)^2*s*(0.02576*eta*cos(u(k))-(0.645*u(k)^2+0.0043378*u(k)+0.003772))-mu*sin(theta(k))/(h(k)+Re)^2;rho*s*v(k)*(0.6203*u(k)+0.02576*eta*sin(u(k)))/(2*m)-(mu-v(k)^2*(h(k)+Re))*cos(theta(k))/(v(k)*(h(k)+Re)^2);v(k)*sin(theta(k)) ] ;
     f2=a{k}*xe(:,k)+b{k}*ue(k);
     f0{k}=delt*(f1-f2);
     f11{k}=f1;
for i=1:p
    xe(:,k+i)=vars.x{i};
    ue(k+i)=vars.u{i};
    ve(k)=xe(1,k+i);
    thetae(k)=xe(2,k+i);
    he(k)=xe(3,k+i);
    alphae(k)=ue(k+i);
       a{k}=[1/m*rho*s*ve(k)*(0.002576*eta*cos(alphae(k))-0.645*(alphae(k))^2-0.0043378*alphae(k)-0.003772) -mu*cos(thetae(k))/(he(k)+Re)^2 2* ...
        mu*sin(thetae(k))/(he(k)+Re)^3;...
        1/(2*m)*rho*s*(0.6203*alphae(k)+sin(alphae(k))*0.002576*eta)+cos(thetae(k))/(he(k)+Re)+mu* ...
        cos(thetae(k))/(ve(k)^2*(he(k)+Re)^2) sin(thetae(k))*(mu-((ve(k))^2)*(he(k)+Re))/(ve(k)*(he(k)+Re)^2) 2* ...
        mu*cos(thetae(k))/(ve(k)*(he(k)+Re)^3)-ve(k)*cos(thetae(k))/(he(k)+Re)^2;sin(thetae(k)) (ve(k))*cos(thetae(k)) 0];
     b{k}=[1/(2*m)*s*rho*(ve(k))^2*(-0.02576*eta*sin(alphae(k))-1.29*alphae(k)-0.0043378); 1/(2*m)*s*rho*ve(k)*(0.02576*eta*cos(alphae(k))+0.6203); 0];
     A{k}=a{k}*delt+eye(3);
     B{k}=b{k}*delt;
     h(k)=he(k);
v(k)=ve(k);
theta(k)=thetae(k);
u(k)=ue(k);
f1=[1/(2*m)*rho*v(k)^2*s*(0.02576*eta*cos(u(k))-(0.645*u(k)^2+0.0043378*u(k)+0.003772))-mu*sin(theta(k))/(h(k)+Re)^2;rho*s*v(k)*(0.6203*u(k)+0.02576*eta*sin(u(k)))/(2*m)-(mu-v(k)^2*(h(k)+Re))*cos(theta(k))/(v(k)*(h(k)+Re)^2);v(k)*sin(theta(k)) ] ;
f2=a{k}*xe(:,k)+b{k}*ue(k);
f0{k}=delt*(f1-f2);
f11{k}=f1;
    
end

   end
   
% %%gengxin
% for k1=k:(k+p)
%     ve(k)=
%     for t=0:delt:tf
%     
%     
% u(k)=vars.u_0;
% sta(k)=status.converged;
% if sta(k)==0
%     cc=cc+1;
% end
% % u(k)=ue(k);
% alpha=u(k);
% %  cl=0.6203*alpha;
% %   cd=0.6450*alpha^2+0.0043378*alpha+0.003772;
% %   if eta<=1
% %       ct=0.02576*eta;
% %   else
% %       ct=0.0224+0.00336*eta;
% %   end
% %   q=1/2*rho*(v(k))^2;
% %   r=h(k)+Re;
% %   L=q*s*cl;
% %   D=q*s*cd;
% %   T=q*s*ct;
% %   v(k+1)=v(k)+delt*((T*cos(alpha)-D)/m-mu*sin(theta(k))/r^2);
% %   theta(k+1)=theta(k)+delt*((L+T*sin(alpha))/m/v(k)-((mu-(v(k))^2*r)*cos(theta(k)))/v(k)/r^2);
% %   h(k+1)=h(k)+delt*(v(k)*sin(theta(k)));  
% %      v1(k+1)= delt*(1/(2*m)*rho*v(k)^2*s*(0.02576*eta*cos(u(k))-(0.645*u(k)^2+0.0043378*u(k)+0.003772))-mu*sin(theta(k))/(h(k)+Re)^2)+v(k);  
% %     theta1(k+1)=delt*(rho*s*v(k)^2*(0.6203*u(k)+0.02576*sin(u(k)))/(2*m*v(k))-(mu-v(k)^2*(h(k)+Re))*cos(theta(k))/(v(k)*(h(k)+Re)^2))+theta(k);
% %     h1(k+1)=delt*(v(k)*sin(theta(k)))+h(k);
% if t>20&&t<25
%     eta=0.5;
% else
%     eta=1;
% end
% Eta(k)=eta;
%   x(:,k+1)=[1/(2*m)*rho*v(k)^2*s*(0.02576*eta*cos(u(k))-(0.645*u(k)^2+0.0043378*...
%     u(k)+0.003772))-mu*sin(theta(k))/(h(k)+Re)^2;rho*s*v(k)*(0.6203*u(k)+0.02576*eta*sin(u(k)))/...
%     (2*m)-(mu-v(k)^2*(h(k)+Re))*cos(theta(k))/(v(k)*(h(k)+Re)^2);v(k)*sin(theta(k)) ]*delt+x(:,k);
% v(k+1)=x(1,k+1);theta(k+1)=x(2,k+1);h(k+1)=x(3,k+1);
% %  x(:,k+1)=[v(k+1);theta(k+1);h(k+1)];
%  x1(:,k+1)=A{k}*x1(:,k)+B{k}*u(k)+f0{k};
%   ts(k)=t;
%   k=k+1;
% end
%     
% 
% %     alpha=1.77*pi/180;
% % %   alpha=alphae(k);
% %
% figure
% subplot(2,2,1)
% plot(ts,x(1,1:end-1),ts,xe(1,1:size(ts,2)))
% subplot(2,2,2)
% plot(ts,x(2,1:end-1),ts,xe(2,1:size(ts,2)))
% subplot(2,2,3)
% plot(ts,x(3,1:end-1),ts,xe(3,1:size(ts,2)))
% subplot(2,2,4)
% plot(ts,u)
% cc