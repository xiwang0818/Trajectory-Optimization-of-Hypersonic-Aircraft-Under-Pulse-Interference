p=size(vars.u,1);
    u(1)=vars.u_0;
for i=1:p+1
    x1(:,i)=vars.x{i};
    u(i+1)=vars.u{i};
    xe1(:,i)=params.xe{i};
end
for k=1:p
v(k+1)= delt*(1/(2*m)*rho*v(k)^2*(0.6203*cos(u(k))-s*((0.645*u(k)^2+0.0043378*u(k)+0.003772)))-mu*sin(theta(k))/(h(k)+Re)^2)+v(k);  
    theta(k+1)=delt*(rho*s*v(k)^2*(0.6203*u(k)+0.02576*sin(u(k)))/(2*m*v(k))-(mu-v(k)^2*(h(k)+Re))*cos(theta(k))/(v(k)*(h(k)+Re)^2))+theta(k);
    h(k+1)=delt*(v(k)*sin(theta(k)))+h(k);
  
 x(:,k+1)=[h(k+1);v(k+1);theta(k+1)];