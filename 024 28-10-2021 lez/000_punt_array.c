#include <stdio.h>
#define DIM 10

int main() {
  int a[DIM], b[DIM];
  int *p;

  /*
    Il nome dell'array corrisponde all'indirizzo della prima cella, e quindi 
    queste due righe sono equivalenti:
  */
  p = &a[0];
  p = a;

  /* Possiamo quindi fare operazioni del tipo: */
  p = p + 2;
  /*
    Abbiamo quindi "fatto scorrere" il nostro puntatore di due posizioni dell'array
    -> ARITMETICA DEI PUNTATORI
    In realtà le celle della memoria hanno dimensioni diverse in base al tipo
    di dato, ma di questo si occupa il compilatore (2 posizioni di char significa
    2 byte, per un'intero significa invece 64 bit = 8 byte).
  */

  p = a;
  a[5] = 10;
  *(p+5) = 10;

  /* Ci viene vietato fare a = b. Tutti i simboli degli array non sono modificabili. */
  a = b;

  return 0;
}