#include <stdio.h>
#define DIM 5
#define SDIM 3

/*
  Scrivere un programma in C che chiede all'utente il contenuto di una
  matrice quadrata 5x5 di interi. Il programma calcola e visualizza
  gli indici (i, j) ed il valore dei massimi locali della matrice. Un
  massimo locale è definito come un elemento della matrice i cui
  adiacenti sono tutti minori o uguali ad esso.

  Esempio:
  se l'utente inserisce la matrice:
  7 4 3 2 1
  1 9 6 4 3
  5 9 3 1 6
  9 8 2 4 3
  4 2 8 4 5
  il programma stamperà a video:
  M[1][1] = 9
  M[2][1] = 9
  M[2][4] = 6
  M[3][0] = 9
  M[4][2] = 8
  M[4][4] = 5
*/

int main() {
  int m[DIM][DIM], i, j, ii, jj, max;

  for (i = 0; i < DIM; i++)
    for (j = 0; j < DIM; j++)
      scanf("%d", &m[i][j]);

  for (i = 0; i < DIM; i++) {
    for (j = 0; j < DIM; j++) {
      /*
        Potremmo anche fare così, ma a quel punto andiamo a limitare la
        dimensione della sottomatrice. Nell'altro modo andiamo a controllare
        gli elementi nel raggio SDIM/2.

        if (
          (i <= 0 || j <= 0 || m[i-1][j-1] <= m[i][j])
          && (i <= 0 || m[i-1][j] <= m[i][j])
          && (i <= 0 || j >= DIM-1 || m[i-1][j+1] <= m[i][j])
          && (j <= 0 || m[i][j-1] <= m[i][j])
          && (j >= DIM-1 || m[i][j+1] <= m[i][j])
          && (i >= DIM-1 || j <= 0 || m[i+1][j-1] <= m[i][j])
          && (i >= DIM-1 || m[i+1][j] <= m[i][j])
          && (i >= DIM-1 || j >= DIM-1 || m[i+1][j+1] <= m[i][j])
        ) 
          printf("(%d, %d) = %d\n", i, j, m[i][j]);
      */

      for (ii = -SDIM/2, max = 1; ii <= SDIM/2 && max; ii++) {
        for (jj = -SDIM/2; jj <= SDIM/2 && max; jj++) {
          if (
            i+ii >= 0 
            && i+ii < DIM 
            && j+jj >= 0 
            && j+jj < DIM 
            && m[i][j] < m[i+ii][j+jj]
          )
            max = 0;
        }
      }

      if (max)
        printf("M[%d][%d] = %d\n", i, j, m[i][j]);
    }
  }

  return 0;
}