T = [298.15, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, ...
    1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100];

r_forw = [1.09E+09, 1.02E+09, 1.00E+09, 1.03E+09, 1.09E+09, 1.17E+09, 1.26E+09, 1.37E+09, ...
    1.49E+09, 1.62E+09, 1.75E+09, 1.90E+09, 2.05E+09, 2.21E+09, 2.38E+09, 2.55E+09, ...
    2.73E+09, 2.91E+09, 3.10E+09];

r_forw_corretto =[2.52E+09
1.76E+09
1.47E+09
1.37E+09
1.35E+09
1.38E+09
1.45E+09
1.53E+09
1.63E+09
1.75E+09
1.88E+09
2.01E+09
2.16E+09
2.31E+09
2.47E+09
2.64E+09
2.82E+09
3.00E+09
3.18E+09
];

%figure;
%loglog(T, r_forw, 'r', 'LineWidth', 1.5);
%plot(T,r_forw_corretto,'b', 'LineWidth', 1.5);
%xlabel('T [K]');
%ylabel('r(T) [s^{-1}]');
%title('Velocità di reazione r (forward direction) con correzione di Wigner');
%grid on;

r_back = [1.21E+06
2.88E+06
4.62E+06
6.36E+06
8.13E+06
1.00E+07
1.20E+07
1.42E+07
1.67E+07
1.94E+07
2.23E+07
2.56E+07
2.91E+07
3.30E+07
3.72E+07
4.17E+07
4.66E+07
5.19E+07
5.75E+07
];

r_back_corretto=[2.79E+06
4.97E+06
6.77E+06
8.41E+06
1.01E+07
1.18E+07
1.38E+07
1.59E+07
1.83E+07
2.09E+07
2.39E+07
2.71E+07
3.06E+07
3.45E+07
3.87E+07
4.32E+07
4.81E+07
5.34E+07
5.90E+07
];

figure;
%loglog(T, r_forw, 'r', 'LineWidth', 1.5);
plot(T,r_back_corretto,'b', 'LineWidth', 1.5);
xlabel('T [K]');
ylabel('r(T) [s^{-1}]');
title('Velocità di reazione r (backward direction) con correzione di Wigner');
grid on;
