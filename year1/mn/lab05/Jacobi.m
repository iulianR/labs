function [X S] = Jacobi(A, b, X0, maxiter, eps);
    N = diag(A);
    N = diag(N)
    P = -(A-N)
    G = inv(N) * P;
    C = inv(N) * b;
    for i = 1:maxiter
        X = G*X0 + C
        q = norm(X-X0);
        if q < eps * norm(X);
            break;
        end
        X0 = X;
    end
    S = i < maxiter;
end
