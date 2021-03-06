function [L] = Cholesky(A)
    [n n] = size(A);
    L = zeros(n);    
    L(1,1) = sqrt(A(1,1));
    for i = 2 : n
        for j = 1 : i - 1
            L(i,j) = A(i,j) / L(j,j);
        endfor
        L(i,i) = sqrt(A(i,i) - L(i,i-1)^2);
    endfor
endfunction
