#include <stdio.h>
#define NROW 10
#define NCOL 10

/*
  Scrivere un sottoprogramma che riceve in ingresso un array
  bidimensionale di interi mat (dichiarato nel chiamate con NCOL=10),
  un intero val e qualsiasi parametro ritenuto strettamente necessario
  e trasmette al chiamate gli indici di riga e colonna che
  identificano la posizione del primo elemento (scandendo l'array per
  righe) che, sommato a tutti i suoi precedenti, dia come risultato un
  valore > val. Nel caso in cui tal elemento non esista, si
  trasmettono i valori -1, -1.

  ??? Il testo non chiede di scrivere il programma...
*/

void checkAcc(int[][NCOL], int, int, int, int*, int*);

int main() {
  int mat[NROW][NCOL];
  int val, row, col, i, j;

  for (i = 0; i < NROW; i++) {
    for (j = 0; j < NCOL; j++) {
      scanf("%d", &mat[i][j]);
    }
  }

  printf("Soglia: ");
  scanf("%d", &val);

  checkAcc(mat, NROW, NCOL, val, &row, &col);
  printf("Indici: %d %d", row, col);

  return 0;
}

void checkAcc(int arr[][NCOL], int nRow, int nCol, int val, int *resI, int *resJ) {
  int i, acc, found;

  for (i = 0, acc = 0, found = -1; i < nRow*nCol & found < 0; i++) {
    acc += arr[i/nCol][i%nCol];
    if (acc > val)
      found = i;
  }

  if (found > -1) {
    *resI = found/nCol;
    *resJ = found%nCol;
  } else {
    *resI = -1;
    *resJ = -1;
  }
}