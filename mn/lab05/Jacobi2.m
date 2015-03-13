function x = Jacobi2(A, b, x0, tol, max_iteratii)
[n n] = size(A);
x = zeros(n,1);
for p = 1:max_iteratii
    for i = 1:n
        s = A(i,1:n) * x0(1:n);
        s = s - A(i,i) * x0(i);
        x0(i) = (b(i) - s) / A(i,i);
    endfor
    q = norm(x - x0, 1);
    x = x0;
    if q < tol
        break;
    endif
endfor
endfunction
