
% Setting the output display to type long.
format long
syms i

% Creating variables and matrix R which is made out of
% zeros for now.
a = 0;
b = 2;
n = 5;
R = zeros(n, n);

% Loop in which we calculate R(k,1) using the given formula
for k = 1:n+1
   
    p= 2^(k-1);
    R(k,1) = (b-a)/(2*p)*(exp(a) + exp(b) + 2*symsum(exp(a+i*(b-a)/p), i, 1, p-1));

end

% Two loops which go through all of the other values as it makes it a more
% accurate approximation with each time.
for i = 1:n
    for k = 1:i
    
    R(i + 1, k + 1) = (4^k*R(i + 1, k) - R(i, k))/(4^k - 1);
    
    end
end    

R(i,i) % Brings answer to console

