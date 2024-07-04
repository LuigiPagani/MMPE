% Trova il valore minimo dell'energia
[minEnergia, indiceMin] = min(EnergiaTotalekcalmol);

% Creazione del plot
plot(d, EnergiaTotalekcalmol, 'r'); % Plotto y in funzione di x, la 'b' indica il colore blu
hold on; % Mantieni il plot corrente

% Aggiungi un asterisco per evidenziare il minimo
plot(d(indiceMin), minEnergia, '*'); 

% Aggiunta di titoli e etichette degli assi
title('H_2 Total Energy as a function of distance d between atoms'); % Titolo del plot con "2" come pedice
xlabel('d [Å]'); % Etichetta dell'asse x
ylabel('E [kcal/mol]'); % Etichetta dell'asse y

% Visualizzazione del grid
grid on;
