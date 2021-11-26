#include <stdio.h>
#define DIM 10

/*
  Scrivere un programma in C che legge una sequenza di numeri interi
  di lunghezza indefinita composta da elementi nell'intervallo [0;9] e
  terminata da un qualsiasi numero non incluso in tale intervallo. Il
  programma visualizza l'istogramma a barre orizzontali delle
  occorrenze di ciascun numero nell'intervallo [0;9], disegnandolo
  tramite il carattere *.
  Esempio: se l'utente inserisce la sequenza:
  1 2 1 1 4 5 7 8 4 2 2 2 -4
  il programma visualizza il seguente messaggio:
  0
  1 * * *
  2 * * * *
  3
  4 * *
  5 *
  6
  7 *
  8 *
  9
*/

int main() {
  int num, ist[DIM], i, j;

  for (i = 0; i < DIM; i++)
    ist[i] = 0;

  scanf("%d", &num);
  while (num >= 0 && num < DIM) {
    ist[num]++;
    scanf("%d", &num);
  }
  
  for (i = 0; i < DIM; i++) {
    printf("%d", i);
    for (j = 0; j < ist[i]; j++)
      printf(" *");
    printf("\n");
  }

  return 0;
}
