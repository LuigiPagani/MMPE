d = [1.1500
1.2500
1.3500
1.4500
1.5500
1.6500
1.7500
1.8500
1.9500
2.0500
2.1500
2.2500
2.3500
2.4500
2.5500
2.6500
2.7500
2.8500
2.9500
3.0500
3.1500
3.2500
3.3500
3.4500
3.5500
3.6500
];
E = [-55.89073
-55.88748
-55.88595
-55.88764
-55.89050
-55.89312
-55.89513
-55.89656
-55.89753
-55.89815
-55.89853
-55.89874
-55.89884
-55.89887
-55.89885
-55.89881
-55.89876
-55.89870
-55.89865
-55.89860
-55.89856
-55.89852
-55.89848
-55.89846
-55.89843
-55.89841
];
% Trova il massimo valore di E e il corrispondente valore di d
[maxE, idx] = max(E);
maxD = d(idx);

figure;
plot(d, E, 'g', 'LineWidth', 1.5);
hold on;
plot(maxD, maxE, '*', 'MarkerSize', 10, 'Color', 'k'); % Punto massimo

% Aggiungi linea tratteggiata verticale
xline(maxD, '--', 'Color', 'b', 'LineWidth', 1.5);

% Imposta i limiti dell'asse y
ylim([-55.9, -55.885]);

xlabel('d [Å]');
ylabel('E [Hartree]');
title('Scan for transition state');
grid on;
hold off;
