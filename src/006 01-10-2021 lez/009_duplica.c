#include <stdio.h>
#define DIM 20

/*
  Scrivere un programma che acquisisce una sequenza s1 di al massimo
  20 numeri interi positivi terminati da un valore negativo o nullo, o
  dal raggiungimento del massimo numero di valori. Il programma
  costruisce una nuova sequenza di numeri s2 in un nuovo array
  copiando il contenuto di s1 e duplicando ciascun valore pari. Infine
  il programma visualizza s2.
  Esempio:
  Se l'utente inserisce: 1 2 3 4 5 0
  Il programma stamperà a video: 1 2 2 3 4 4 5
*/

int main() {
  int s1[DIM], dim, s2[DIM * 2], i, j;

  for (i = 0, dim = -1; i < DIM && dim < 0; i++) {
    scanf("%d", &s1[i]);
    if (s1[i] == 0)
      dim = i;
  }
  if (dim < 0)
    dim = i;

  for (i = 0, j = 0; i < dim; i++) {
    s2[j] = s1[i];
    j++;

    if (s1[i] % 2 == 0) {
      s2[j] = s1[i];
      j++;
    }
  }

  for (i = 0; i < j; i++)
    printf("%d ", s2[i]);
  printf("\n");

  return 0;
}
