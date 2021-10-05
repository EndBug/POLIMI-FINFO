#include <stdio.h>
#define DIM 2

/*
  Scrivere un programma in C che chiede i dati di due matrici quadrate
  4x4 di interi. Il programma calcola e visualizza il loro prodotto
  matriciale.
*/

int main() {
  int a[DIM][DIM], b[DIM][DIM], r[DIM][DIM], i, j, k;

  for (i = 0; i < DIM; i++) {
    for (j = 0; j < DIM; j++)
      scanf("%d", &a[i][j]);
  }
  for (i = 0; i < DIM; i++) {
    for (j = 0; j < DIM; j++)
      scanf("%d", &b[i][j]);
  }

  for (i = 0; i < DIM; i++){
    for (j = 0; j < DIM; j++) {
      for (k = 0, r[i][j] = 0; k < DIM; k++)
        r[i][j] += a[i][k] * b[k][j];
    }
  }

  for (i = 0; i < DIM; i++) {
    for (j = 0; j < DIM; j++)
      printf("%d ", r[i][j]);
    printf("\n");
  }

  return 0;
}