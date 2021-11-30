#include <stdio.h>
#define DIM 4

/*
  Scrivere un programma in C che chiede all'utente di inserire i dati
  interi di un array bidimensionale quadrato di dimensione 4x4 e
  visualizza 1 se si tratta di una matrice identità, altrimenti 0.
*/

int main() {
  int m[DIM][DIM], i, j, id;

  for (i = 0; i < DIM; i++)
    for (j = 0; j < DIM; j++)
      scanf("%d", &m[i][j]);

  for (i = 0, id = 1; i < DIM && id; i++) {
    for (j = 0; j < DIM && id; j++) {
      if ((i == j && m[i][j] != 1) || (i != j && m[i][j] != 0))
        id = 0;
    }
  }

  printf("%d\n", id);

  return 0;
}
