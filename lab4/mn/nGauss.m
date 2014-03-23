function A = nG(A)
	[m, n] = size(A);
	for p = 1:n-1
		for i = p+1:n
			u = A(i,p)/A(p,p);
			A(i, p) = u;
		end
		for i = p+1:n
			for j = p+1:n
				u = A(i,p)/A(p,p);
				A(i,j) = A(i,j) - u*A(p,j); 
			end
		end
	end
end
