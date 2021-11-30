#include <stdio.h>
#define DIM1 5
#define DIM2 2

/*
  Scrivere un programma in C che chiede all'utente i dati di due
  matrici di interi, la prima 5x5 e la seconda 2x2. Il programma
  calcola e visualizza il numero di volte che la seconda matrice è
  contenuta nella prima.
*/

int main() {
  int a[DIM1][DIM1], b[DIM2][DIM2], i, j, ii, jj, count, contenuta;

  for (i = 0; i < DIM1; i++)
    for (j = 0; j < DIM1; j++)
      scanf("%d", &a[i][j]);
  for (i = 0; i < DIM2; i++)
    for (j = 0; j < DIM2; j++)
      scanf("%d", &b[i][j]);

  for (i = 0, count = 0; i <= DIM1 - DIM2; i++) {
    for (j = 0; j <= DIM1 - DIM2; j++) {
      contenuta = 1;

      for (ii = 0; ii < DIM2 && contenuta; ii++) {
        for (jj = 0; jj < DIM2 && contenuta; jj++) {
          if (a[i + ii][j + jj] != b[ii][jj])
            contenuta = 0;
        }
      }

      if (contenuta)
        count++;
    }
  }

  printf("%d\n", count);

  return 0;
}
