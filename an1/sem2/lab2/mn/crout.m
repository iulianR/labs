function A = crout(A)
	[m, n] = size(A);
	for p = 1 : n
		for i = p : n
			s = A(i, 1:p-1) * A(1:p-1, p);
			A(i,p) = A(i,p) - s;
		end
		for j = p+1 :n
			s = A(p, 1:p-1)* A(1:p-1, j);
			A(p, j) = (A(p,j) -s) / A(p,p);
		end
	end
end
