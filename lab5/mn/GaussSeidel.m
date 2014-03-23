function x = GaussSeidel(A, b, x0, maxiter, tol)
    [m, n] = size(A);
    x = x0;
    for p = 1:maxiter
        for i = 1:n
            s1 = A(i, 1:i-1) * x(1:i-1);
            s2 = A(i, i+1:n) * x0(i+1:n);
            x(i) = (b(i) - s1 - s2)/A(i,i);
        end
        q = norm(x-x0, 1);
        x0 = x
        if q < eps * norm(x)
            break
        end
    end
    s = p
end
