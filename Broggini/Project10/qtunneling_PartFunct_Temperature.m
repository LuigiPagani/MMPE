T = [100
200
300
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
];

qtunn_Ia = [2.34E+41
3.39E+10
7.08E+06
2.45E+06
1.71E+06
1.43E+06
1.30E+06
1.22E+06
1.17E+06
1.13E+06
1.11E+06
1.09E+06
1.08E+06
1.06E+06
1.06E+06
1.05E+06
1.04E+06
1.04E+06
1.03E+06
1.03E+06
];

qtunn_Ec = [7.07E+28
1.96E+10
7.46E+06
2.53E+06
1.75E+06
1.46E+06
1.31E+06
1.23E+06
1.18E+06
1.14E+06
1.12E+06
1.10E+06
1.08E+06
1.07E+06
1.06E+06
1.05E+06
1.05E+06
1.04E+06
1.04E+06
1.03E+06
];


figure;
semilogy(T, qtunn_Ia, 'LineWidth', 1.5, 'color', 'r');
hold on;
semilogy(T, qtunn_Ec, 'LineWidth', 1.5, 'color', 'b');
grid on;
xlabel('T [K]');
legend('I_a', 'E_c');
title('Partition functions Quantum Tunneling');




