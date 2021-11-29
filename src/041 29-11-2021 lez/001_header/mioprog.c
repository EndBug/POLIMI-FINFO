/*
  Per compilare: gcc lista.c mioprog.c
  Dobbiamo compilare tutti i codici sorgente, sarà poi l'header a dare i
  riferimenti. Compilati separatamente i file non servono a niente, perché
  hanno solo parte del codice.
  Quando compiliamo avvengono i seguenti passaggi
  - il precompilatore applica le direttive: sostituisce i valori per le #define,
    aggiunge i prototipi per gli #include
  - il compilatore converte in file oggetto (.o) in linguaggio macchina ciascun
    file sorgente
  - il linker prende tutti i file oggetto compilati e quelli delle librerie, e
    crea un unico file di output in linguaggio macchina
  - viene eventualmente mostrato un log con gli errori che si sono verificati
    e/o eventuali warning
  Volendo poso eseguire la compilazione step-by-step:
    gcc -c lista.c -o lista.o
    gcc -c main.c -o main.o
    gcc lista.o main.o -o main
    ./main
*/

#include <stdio.h>
#include <stdlib.h>
/* Qua non utilizziamo <> perché non è nella directory di gcc */
#include "lista.h"

int main(int argc, char *argv[]) {
  nodo_t *testa;
  testa = NULL;
  testa = inserisciInCoda(testa, 1);
  testa = inserisciInCoda(testa, 2);
  visualizza(testa);
  testa = distruggi(testa);

  return 0;
}
