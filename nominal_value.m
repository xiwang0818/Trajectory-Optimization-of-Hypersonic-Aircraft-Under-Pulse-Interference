clear
p=50;
alpha_min=-10*pi/180;alpha_max=10*pi/180;                                          %%%%%%%%%%%%%%%%%% ˝æ› ‰»Î
m=136820;
rho=0.012537;
Re=6371387;
s=334.73;
CT=0.02576;
mu=3.936*10^14;

%  load sam01f01;

tf=100;
delt=0.1;

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
v(1)=4590.3;
h(1)=33528;
theta(1)=0.0;
x(:,1)=[v(1);theta(1);h(1)];
x1(:,1)=x(:,1);
for t=0:delt:tf
   
alpha=1.68*pi/180;
 cl=0.6203*alpha;
  cd=0.6450*alpha^2+0.0043378*alpha+0.003772;
  if eta<=1
      ct=0.02576*eta;
  else
      ct=0.0224+0.00336*eta;
  end
  q=1/2*rho*(v(k))^2;
  r=h(k)+Re;
  L=q*s*cl;
  D=q*s*cd;
  T=q*s*ct;
  v(k+1)=v(k)+delt*((T*cos(alpha)-D)/m-mu*sin(theta(k))/r^2);
  theta(k+1)=theta(k)+delt*((L+T*sin(alpha))/m/v(k)-((mu-(v(k))^2*r)*cos(theta(k)))/v(k)/r^2);
  h(k+1)=h(k)+delt*(v(k)*sin(theta(k)));  
%      v1(k+1)= delt*(1/(2*m)*rho*v(k)^2*s*(0.02576*eta*cos(u(k))-(0.645*u(k)^2+0.0043378*u(k)+0.003772))-mu*sin(theta(k))/(h(k)+Re)^2)+v(k);  
%     theta1(k+1)=delt*(rho*s*v(k)^2*(0.6203*u(k)+0.02576*sin(u(k)))/(2*m*v(k))-(mu-v(k)^2*(h(k)+Re))*cos(theta(k))/(v(k)*(h(k)+Re)^2))+theta(k);
%     h1(k+1)=delt*(v(k)*sin(theta(k)))+h(k);
  u(k)=alpha;
 x(:,k+1)=[v(k+1);theta(k+1);h(k+1)];
%  x1(:,k+1)=A{k}*x1(:,k)+B{k}*u(k)+f0{k};
% x(:,k+1)=[1/(2*m)*rho*v(k)^2*s*(0.02576*eta*cos(u(k))-(0.645*u(k)^2+0.0043378*...
%     u(k)+0.003772))-mu*sin(theta(k))/(h(k)+Re)^2;rho*s*v(k)*(0.6203*u(k)+0.02576*eta*sin(u(k)))/...
%     (2*m)-(mu-v(k)^2*(h(k)+Re))*cos(theta(k))/(v(k)*(h(k)+Re)^2);v(k)*sin(theta(k)) ]*delt+x(:,k);
% v(k+1)=x(1,k+1);theta(k+1)=x(2,k+1);h(k+1)=x(3,k+1);
  ts(k)=t;
  k=k+1;
end
    

%     alpha=1.77*pi/180;
% %   alpha=alphae(k);
%  
 plot(ts,x(3,1:end-1))
alphae=u;
he=h;
ve=v;
thetae=theta;
xe=x;
ue=u;
te=ts;
%  save sam01ref2 alphae he ve thetae xe ue te