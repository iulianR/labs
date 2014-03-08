function [A, b] = gauss(A, b)
	[n, n] = size(A);
	for p = 1:n - 1
		[t, A(:,p)] = vecG(p, A(:,p));
		for j=p+1:n
			A(:,j)=TG(A(:,j),p,t);
		endfor
		b=TG(b,p,t);
	endfor
endfunction
