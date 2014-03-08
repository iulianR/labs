function X = invGauss(A)
	[m, n] = size(A);
	X=eye(n);
	for p = 1 : n-1
		for i = p+1 : n
			t = A(i,p) / A(p,p);
			A(i,p) = 0;
			A(i,p+1:n) = A(i,p+1:n)-t * A(p,p+1:n);
		end
		X(i,1:n) = X(i,1:n) - t * X(p,1:n);
	end
	for i = n : -1 : 1
		for k = 1 : n
			suma = A(i,i+1:n)*X(i+1:n,k);
			X(i,k) = (X(i,k) - suma) / A(i,i);
		end
	end
endfunction
