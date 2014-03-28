function [x ok] = secanta(a=0.1, b=1.5, tol=10^-3, maxiter=1000)
	contor = 1;
	ok = 0;
	x0 = (a*f(b) - b*f(a))/(f(b) - f(a));
	xant = 10000;
	if (f(a) * f(x0) < 0)
		b = x0;
		x0 = (a*f(b) - b*f(a))/(f(b) - f(a));
	end
	if (f(b) * f(x0) < 0)
		a = x0;
		x0 = (a*f(b) - b*f(a))/(f(b) - f(a));
	end
	while contor < maxiter
		if abs(f(xant) - f(x0)) < tol
			break;
		end
		if (f(a) * f(x0) < 0)
			b = x0;
			xant = x0;
			x0 = (a*f(b) - b*f(a))/(f(b) - f(a));
			contor += 1;
			continue;
		end
		if (f(b) * f(x0) < 0)
			a = x0;
			xant = x0;
			x0 = (a*f(b) - b*f(a))/(f(b) - f(a));
			contor += 1;
			continue;
		end
	end
	contor
	x = x0;
	if contor < maxiter
		ok = 1;
end