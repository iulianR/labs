function [Q, R] = Gram_Schmidt(A)
%%%% Initial step
	[n n] = size(A);
	Q = zeros(n);
	R = zeros(n);
	for j = 1:n
		for i = 1:j-1
			R(i,j) = Q(:, i)' * A(:,j);
		endfor
		s = zeros(n, 1);
		for i = 1:j-1
			s = s + R(i, j) * Q(:, i);
		endfor
	%%% Echivalent pentru instructiunea for de mai sus:
	%% s = Q(:, 1:j-1) * R(1:j-1, j);
	%%%
		aux = A(:, j) - s;
		R(j, j) = norm(aux, 2);
		Q(:, j) = aux/ R(j, j);
	endfor
endfunction
