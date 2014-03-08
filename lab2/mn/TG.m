function y = TG(y, p, t)
	y = y(:);
	t = t(:);
	n = length(t);
	y(p+1:n) = y(p+1:n) - t(p+1:n).*y(p);
