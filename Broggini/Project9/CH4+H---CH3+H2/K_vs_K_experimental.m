T = [298.15
400
500
600
700
800
900
1000
1100
1200
1300
1400
1500
1600
1700
1800
1900
2000
2100
];

k=[6.40E-22
2.32E-19
7.51E-18
7.93E-17
4.47E-16
1.70E-15
4.99E-15
1.22E-14
2.61E-14
5.04E-14
8.99E-14
1.51E-13
2.39E-13
3.64E-13
5.35E-13
7.62E-13
1.06E-12
1.43E-12
1.90E-12
];

k_wig=[1.54E-21
4.13E-19
1.13E-17
1.07E-16
5.61E-16
2.03E-15
5.76E-15
1.37E-14
2.88E-14
5.48E-14
9.66E-14
1.61E-13
2.52E-13
3.82E-13
5.58E-13
7.91E-13
1.10E-12
1.47E-12
1.95E-12
];

figure;
plot(T, k, 'LineWidth',1.5, 'Color', 'r');
hold on;
plot(T, k_wig, 'LineWidth', 1.5, 'Color', 'b');
legend('k', 'k_{Wigner}');
xlabel('T [K]');
ylabel('k [cm^3 /mol^{-1}s^{-1}] ');
title('Confronto con il metodo di Wigner (Backward direction)');
grid on;