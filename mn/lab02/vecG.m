function [t, x] = vecG(p, x)
	x = x(:);
	n = length(x);
	t = zeros(n, 1);
	t(p+1:n) = x(p+1:n)./x(p);
	x(p+1:n) = 0;
