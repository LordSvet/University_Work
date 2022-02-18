format long

%Setting the armslengths a, endpoint p, epsilon for precision for when the
%while loop will stop and the starting point which I have put as 2;1.
a = [5 3];
p = [-5 4]';

startVector = [2 1]';
epsilon = 10^-5;

%Calculating function f(phi1,phi2) as from moodle.
Fx_0 = [a(1)*cos(startVector(1))+a(2)*cos(startVector(2)); a(1)*sin(startVector(1))+a(2)*sin(startVector(2))]  - [p];

%Jakobian Matrix.
Jakobi = [a(1) * -sin(startVector(1)), a(2) * -sin(startVector(2)); a(1) * cos(startVector(1)), a(2) * cos(startVector(2))];

%Multidimensional newton Iteration
nextVec = startVector - inv(Jakobi) * Fx_0;

%Loops it until precision is calculated
while ( abs( sqrt( nextVec(1) ^ 2 + nextVec(2) ^ 2) - sqrt(startVector(1) ^ 2 + startVector(2) ^ 2)) > epsilon )

    startVector = nextVec;
    Fx_0 = [a(1) * cos(startVector(1)) + a(2)*cos(startVector(2)); a(1) * sin(startVector(1)) + a(2) * sin(startVector(2))]  - [p];
    Jakobi = [a(1) * - sin(startVector(1)), a(2) * - sin(startVector(2)); a(1) * cos(startVector(1)), a(2) * cos(startVector(2))];
    nextVec = startVector - inv(Jakobi) * Fx_0;

end

%Brings answer to console
nextVec
