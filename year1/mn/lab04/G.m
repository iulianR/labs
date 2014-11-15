function A = G(A)

    [m, n] = size(A);

    B = zeros(n,1);

    for p = 1 : n-1     
        for i = p+1 : n
            u(i,p) = A(i,p)/A(p,p);
            A(i,p) = u(i,p);
        end
        for i = p+1 : n
           for j = p+1:n
                u(i,p) = A(i,p)/A(p,p);
                A(i,j) = A(i,j) - u(i,p)*A(p,j);
           end
        end
     end

end
