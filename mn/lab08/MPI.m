function [lambda x OK] = MPI(A, y, eps, maxiter)
        % Metoda puterii inverse
        [n n] = size(A);
        k = 0;
        e = 2 * epsilon;
        OK = 1;
        u = y' * A * y;
        while e >= epsilon
                if k > maxiter
                        OK = 0;
                        error("Nu converge!");
                end
                x = (A - u*eye(n)) \ y;
                x = x / norm(x);
                lambda = x' * A * x;
                e = abs(1 - abs(y' * x));
                y = x;
                k = k + 1;
                u = lambda;
        end
end
