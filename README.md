# SDogica
Programul acesta a fost conceput pentru creare si analizarea diagramelor logice

# Cum il compilez?
Cu aceasta comanda:
sudo g++ -lSDL2 -lSDL2_ttf sdogica.cpp -o sdogica
sudo g++ -lSDL2 -lSDL2_ttf menu.cpp -o menu
Fisierele trebuiesc puse in acelasi folder!

# Cum il folosesc?

Meniul este destul de intuitiv. Programul in sine merita putin explicat:
El functioneaza pe baza de comenzi, ceea ce este scris aparand in coltul din stanga jos.
Exista 4 comenzi: termen, highlight, iesire, stergere.

1. Comanda termen: creaza termenul. Fara niciun argument adaugat(adaugare se face prin Enter) se va
crea un program fara nicio relatie cu altul. Argumentele se impart in doua categori: de id si de 
relatie.
    Astfel, daca utilizatorul doreste sa creeze un termen, acestea sunt cateva exemple:
     termen (creeza un termen).
     termen 1 2 (creeaza un termen cu relatia 2 cu termenul 1)

2. Comanda highlight: coloreaza cu rosul termenul cu id-ul specificat. Astfel, daca se cere
   sublinierea termenului 1, se va scrie:
       highlight 1
3. Comanda iesire: iese din programul, intrand in meniu
4. Comanda stergere: sterge ceea ce este facut. Sterge si in fisierul in care se salveaza programul

! Se apasa tasta Enter intainte de a scrie argumentul !

# Care sunt relatiile?
Acestea sunt recunoscute de program prin cifre:
1 - identitate
2 - gen-specie (subordonare)
3 - incrucisare
4 - contradictie.
Fara niciun argument, termenii sunt pusi in relatie de contrarietate.
Fara niciun argument, termenii sunt pusi in relatie de
   
