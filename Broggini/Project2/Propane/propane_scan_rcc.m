% Trova il valore minimo dell'energia
[minEnergia, indiceMin] = min(EnergyTot);

% Creazione del plot
plot(rc, EnergyTot, 'r'); % Plotto y in funzione di x, la 'b' indica il colore blu
hold on; % Mantieni il plot corrente

% Aggiungi un asterisco per evidenziare il minimo
plot(rc(indiceMin), minEnergia, 'x'); 

% Aggiunta di titoli e etichette degli assi
title('Propane Total Energy'); % Titolo del plot con "2" come pedice
xlabel('d [Å]'); % Etichetta dell'asse x
ylabel('E [kcal/mol]'); % Etichetta dell'asse y

% Visualizzazione del grid
grid on;

% distanza minima
rc(indiceMin)