clear
m=136820;
rho=0.012537;
Re=6371387;
s=334.73;
% CT=0.02576;
mu=3.936*10^14;
load sam01ref2
delt=0.1;
eta=1;
 for k=1:size(te,2)
     a{k}=[1/m*rho*s*ve(k)*(0.002576*eta*cos(alphae(k))-0.645*(alphae(k))^2-0.0043378*alphae(k)-0.003772) -mu*cos(thetae(k))/(he(k)+Re)^2 2* ...
        mu*sin(thetae(k))/(he(k)+Re)^3;...
        1/(2*m)*rho*s*(0.6203*alphae(k)+sin(alphae(k))*0.002576*eta)+cos(thetae(k))/(he(k)+Re)+mu* ...
        cos(thetae(k))/(ve(k)^2*(he(k)+Re)^2) sin(thetae(k))*(mu-((ve(k))^2)*(he(k)+Re))/(ve(k)*(he(k)+Re)^2) 2* ...
        mu*cos(thetae(k))/(ve(k)*(he(k)+Re)^3)-ve(k)*cos(thetae(k))/(he(k)+Re)^2;sin(thetae(k)) (ve(k))*cos(thetae(k)) 0];
     b{k}=[1/(2*m)*s*rho*(ve(k))^2*(-0.02576*eta*sin(alphae(k))-1.29*alphae(k)-0.0043378);1/(2*m)*s*rho*ve(k)*(0.02576*eta*cos(alphae(k))+0.6203); 0];
     A{k}=a{k}*delt+eye(3);
     B{k}=b{k}*delt;
     h(k)=he(k);
v(k)=ve(k);
theta(k)=thetae(k);
u(k)=ue(k);
% f1=[v(k)*sin(theta(k));1/(2*m)*rho*v(k)^2*(0.6203*cos(u(k))-s*((0.645*u(k)^2+0.0043378*...
%     u(k)+0.003772)))-mu*sin(theta(k))/(h(k)+Re)^2;rho*s*v(k)^2*(0.6203*u(k)+0.02576*sin(u(k)))/...
%     (2*m*v(k))-(mu-v(k)^2*(h(k)+Re))*cos(theta(k))/(v(k)*(h(k)+Re)^2) ] ;
f1=[1/(2*m)*rho*v(k)^2*s*(0.02576*eta*cos(u(k))-(0.645*u(k)^2+0.0043378*u(k)+0.003772))-mu*sin(theta(k))/(h(k)+Re)^2;rho*s*v(k)*(0.6203*u(k)+0.02576*eta*sin(u(k)))/(2*m)-(mu-v(k)^2*(h(k)+Re))*cos(theta(k))/(v(k)*(h(k)+Re)^2);v(k)*sin(theta(k)) ] ;
f2=a{k}*xe(:,k)+b{k}*ue(k);
f0{k}=delt*(f1-f2);
 end

save sam01f02 f0 A B te ue ve thetae xe he alphae
%  x(:,k+1)=delt*(A{k}*x(:,k)+B{k}*u(k)+f0)+x(:,k);