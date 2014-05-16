function RK4()
	h=1.5;
	x = 0:h:3;
	y = zeros(1,length(x));
	y(1) = 5;
	F_xy = @(t,r) 3.*exp(-t)-0.4*r;

	for i=1:(length(x)-1)
	    k_1 = F_xy(x(i),y(i));
	    k_2 = F_xy(x(i)+0.5*h,y(i)+0.5*h*k_1);
	    k_3 = F_xy((x(i)+0.5*h),(y(i)+0.5*h*k_2));
	    k_4 = F_xy((x(i)+h),(y(i)+k_3*h));

	    y(i+1) = y(i) + (1/6)*(k_1+2*k_2+2*k_3+k_4)*h;  % main equation
	end
	y
end