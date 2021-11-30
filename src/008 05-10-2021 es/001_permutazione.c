#include <stdio.h>
#define DIM 10

/*
  Scrivere un programma in C che chiede all'utente di inserire due
  sequenze di 10 numeri interi ciascuna. Il programma controlla che la
  seconda sequenza sia una permutazione della prima e stampa a video
  l'esito del test (1: permutazioni, 0: altrimenti).
*/

int main() {
  int a[DIM], b[DIM], i, j, perm, countA, countB;

  for (i = 0; i < DIM; i++)
    scanf("%d", &a[i]);
  for (i = 0; i < DIM; i++)
    scanf("%d", &b[i]);

  for (i = 0, perm = 1; i < DIM && perm; i++) {
    for (j = 0, countA = 0, countB = 0; j < DIM; j++) {
      if (a[j] == a[i])
        countA++;
      if (b[j] == a[i])
        countB++;
    }

    if (countA != countB)
      perm = 0;
  }

  printf("Perm: %d\n", perm);

  return 0;
}
