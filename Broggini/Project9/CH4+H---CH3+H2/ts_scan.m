d = [1.0500, 1.2000, 1.3500, 1.5000, 1.6500, 1.8000, 1.9500, 2.1000, 2.2500, 2.4000, ...
    2.5500, 2.7000, 2.8500, 3.0000, 3.1500, 3.3000, 3.4500, 3.6000, 3.7500, 3.9000, 4.0500];
E = [-40.14865, -40.15845, -40.15110, -40.14192, -40.13634, -40.13415, -40.13385, -40.13429, ...
    -40.13485, -40.13530, -40.13560, -40.13576, -40.13585, -40.13588, -40.13589, -40.13589, ...
    -40.13588, -40.13587, -40.13586, -40.13586, -40.13586];

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
ylim([-40.13 max(E) + 0.01]);

xlabel('d [Å]');
ylabel('E [Hartree]');
title('Scan for transition state');
grid on;
hold off;
