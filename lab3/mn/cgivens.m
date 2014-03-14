function [Q R] = cgivens(A)
[m,n] = size(A);
Q = eye(n);
for l = 2:m
	for k = 1:l-1
		ro = sqrt(A(k,k) * A(k,k) + A(l,k) * A(l,k));
		sin_teta = (-1) * A(l,k) / ro;
		cos_teta = A(k,k) / ro;
		G = eye(n);
		G(k,k) = cos_teta;
		G(l,l) = cos_teta;
		G(k,l) = -sin_teta;
		G(l,k) = sin_teta;
		Q = Q * G';
		A = G * A;
	endfor
endfor
R = A;
endfunction
