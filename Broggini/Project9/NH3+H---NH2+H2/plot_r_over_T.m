T = [298.15, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, ...
    1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100];

r_forw = [3.15E+08
2.73E+08
2.52E+08
2.44E+08
2.43E+08
2.49E+08
2.58E+08
2.70E+08
2.85E+08
3.02E+08
3.21E+08
3.41E+08
3.63E+08
3.86E+08
4.11E+08
4.36E+08
4.63E+08
4.90E+08
5.19E+08
];

r_forw_corretto = [7.59E+08
4.87E+08
3.79E+08
3.29E+08
3.06E+08
2.97E+08
2.98E+08
3.04E+08
3.15E+08
3.29E+08
3.45E+08
3.63E+08
3.84E+08
4.05E+08
4.29E+08
4.53E+08
4.79E+08
5.06E+08
5.33E+08
];

%figure;
%plot(T,r_forw_corretto,'b', 'LineWidth', 1.5);
%xlabel('T [K]');
%ylabel('r(T) [s^{-1}]');
%title('Velocità di reazione r (forward direction) con correzione di Wigner');
%grid on;

r_back = [1.12E+06
3.04E+06
5.30E+06
7.75E+06
1.04E+07
1.32E+07
1.63E+07
1.97E+07
2.34E+07
2.75E+07
3.21E+07
3.71E+07
4.26E+07
4.86E+07
5.51E+07
6.21E+07
6.97E+07
7.78E+07
8.66E+07
];

r_back_corretto = [2.70E+06
5.42E+06
7.96E+06
1.04E+07
1.30E+07
1.57E+07
1.88E+07
2.21E+07
2.58E+07
2.99E+07
3.45E+07
3.95E+07
4.50E+07
5.10E+07
5.75E+07
6.45E+07
7.21E+07
8.03E+07
8.90E+07
];

figure;
%loglog(T, r_forw, 'r', 'LineWidth', 1.5);
plot(T,r_back_corretto,'b', 'LineWidth', 1.5);
xlabel('T [K]');
ylabel('r(T) [s^{-1}]');
title('Velocità di reazione r (backward direction) con correzione di Wigner');
grid on;
