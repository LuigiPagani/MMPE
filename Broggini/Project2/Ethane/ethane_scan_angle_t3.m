% Trova il valore minimo dell'energia
[minEnergia, indiceMin] = min(EnergyTot);

% Creazione del plot
plot(t3, EnergyTot, 'r'); % Plotto y in funzione di x, la 'b' indica il colore blu
hold on; % Mantieni il plot corrente

% Aggiungi un asterisco per evidenziare il minimo
plot(t3(indiceMin), minEnergia, '*'); 

% Aggiunta di titoli e etichette degli assi
title('C_2H_6 Total Energy as a function of angle t_3 between atoms'); % Titolo del plot con "2" come pedice
xlabel('t_3 [°]'); % Etichetta dell'asse x
ylabel('E [kcal/mol]'); % Etichetta dell'asse y

% Visualizzazione del grid
grid on;