function [Q R] = householder(A)
    [m n] = size(A);
    minim = min(m, n);
    u(1:m) = 0;
    u = u';
    Q = eye(m);
    for p = 1 : minim - 1
        x = A(:,p);
        sigma = sign(x(p)) * norm(x(p:m));
        beta = 1 / (sigma * (sigma + x(p)));
        u(1:p-1) = 0;
        u(p) = (x(p) + sigma);
        u(p+1:m) = x(p+1:m);
        H = eye(m) - beta * (u * u');
        A = H * A;
        Q = Q * H';
    end
    R = A;
endfunction
