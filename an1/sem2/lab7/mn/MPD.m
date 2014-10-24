function [lambda x ok] = MPD(A, q)
 	eps = 10^-3; maxiter=100;
	ok = 1;
	k = 0;
	q = q/norm(q);
	e = 2 * eps;
	i = 0;
	while i < 3;
		k = k + 1;
		if k > maxiter
			ok = 0;
			error('Nu converge');
		end
		x = A * q;
		x = x/norm(x);
		lambda = x' * A * x;
		lambda
		x
		e = abs(1 - abs(q' * x))
		q = x;
		i = i + 1;
	end
end