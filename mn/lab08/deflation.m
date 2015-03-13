function [lambda, vects] = deflation(A, numar_perechi, eps, maxiter)
	[r c] = size ( A );
	if ( r ~= c )
	   disp('Matricea trebuie sa fie patratica');
	   return;
	end;
	n = r;

	l = zeros (1, numar_perechi);
	v = zeros (n, numar_perechi);

	[l(1) v(:,1)] = MPD (A, rand(n,1), eps, maxiter);
	for i = 2:numar_perechi
	    A = hd ( A, l(i-1), v(:,i-1) );
		[l(i) v(:,i)] = MPD(A, rand(n,1), eps, maxiter);
	end;

	lambda = l;
	vects = v;

	return;

function B = hd(A, l, v)
	B = A - (l / dot(v, v)) * v * v';
	return;