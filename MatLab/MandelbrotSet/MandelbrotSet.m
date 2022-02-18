%Initializing variables
n = 256;
x_0 = -1.5; %x_0 <= real(c) <= x_1
x_1 = 0.5;  
y_0 = -1;   %y_0 <= imag(c) <= y_1
y_1 = 1;

[x,y] = meshgrid(linspace(x_0, x_1, 500), linspace(y_0, y_1, 500));
%Coordinates are between 0-500

c = x + 1i * y;
x = zeros(size(c));
z = zeros(size(c)); %z = x_(i+1)
colors = zeros(size(c));

for iter = 1:n
    x = z;
    z = z.^2 + c;
end

colors(abs(x) <= 2) = 0; 
colors(abs(x) > 2) = 1;

imagesc(colors),
colormap(gray(2))

