#include <stdio.h>
#define DIM 5

/*
  Scrivere un programma in C che chiede all'utente di inserire 5
  numeri interi e poi li visualizza in ordine inverso.
*/

int main() {
  /* Creiamo un array di DIM elementi */
int array[DIM];
int i;

/* 
    Ciascun elemento dell'array può essere ottenuto tramite il suo index (da 0 a DIM-1).
    I singoli elementi possono essere manipolati come comuni variabili.
    array[i];

    Se proviamo ad accedere a un valore al di fuori della dimensione dell'array rischiamo
    o di ottenere valori spazzatura, o di far crashare il programma.
  */

for (i = 0; i < DIM; i++)
  scanf("%d", &array[i]);

for (i = DIM - 1; i >= 0; i--)
{
  printf("%d\n", array[i]);
  }

  return 0;
}
