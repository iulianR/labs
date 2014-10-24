function [lambda x] = MPD(A, q, eps, maxiter)
	% Metoda puterii directe
	% Genereaza cea mai mare valoare proprie (lambda) in modul si vectorul
	% propriu asociat (x)
	ok = 1;
	k = 0;
	q = q / norm(q);
	e = 2 * eps;
	while e >= eps
		k = k + 1;
		if k > maxiter
			ok = 0;
			error('Nu converge');
		end
		x = A * q;
		x = x / norm(x);
		lambda = x' * A * x;
		eps = abs(1 - abs(q' * x));
		q = x;
	end
end
