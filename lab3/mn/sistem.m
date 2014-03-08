function x = sistem(A, b)
	[Q R] = gs(A);
	x = invGauss(R) * Q' * b;
endfunction
