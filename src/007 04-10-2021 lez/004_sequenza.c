#include <stdio.h>
#define DIM 20

/*
  Da es. 01-10-2021
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
  int a1[DIM], a2[DIM*2], size1, size2, i;

  size1 = 0;
  scanf("%d", &a1[size1]);
  while (size1 < DIM && a1[size1] > 0) {
    size1++;

    /*
      Dobbiamo controllare anche questa condizione perché altrimenti rischiamo
      di richiedere anche il 21° valore.
    */
    if (size1 < DIM)
      scanf("%d", &a1[size1]);
  }

  for (i = 0, size2 = 0; i < size1; i++, size2++) {
    if (a1[i]%2 == 0) {
      a2[size2] = a1[i];
      size2++;
    }

    a2[size2] = a1[i];
  }

  for (i = 0; i < size2; i++)
    printf("%d ", a2[i]);
  printf("\n");


  return 0;
}