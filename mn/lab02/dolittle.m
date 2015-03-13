function [L U] = dolittle(A)
    [n n] = size(A);
    for p = 1 : n
        for i = p : n
            s = A(i, 1 : p-1) * A(1 : p-1, i);
            A(p,i) = A(p,i) - s;
        endfor
        for j = p+1 : n
            s = A(j, 1 : p-1) * A(1 : p-1, p);
            A(j,p) = (A(j,p) - s) / A(p,p);
        endfor
    endfor
    U = triu(A);
    L = A - U + eye(n);
endfunction
