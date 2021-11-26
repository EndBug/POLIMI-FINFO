#include <stdio.h>
#define DIM 3

/*
  Scrivere un programma in C che chiede all'utente di inserire i dati
  interi di una matrice bidimensionale quadrata di dimensione 5. Il
  programma calcola la matrice ruotata di 90 gradi in senso
  antiorario, salvandola in una nuova variabile e visualizza il
  risultato.
*/

/*
  Approcciamo il problema guardando in che posizione vanno a finire gli indici:
  [0][0]->[4][0], [0][1]->[3][0], [0][2]->[2][0], ...
  [1][0]->[4][1], [1][1]->[3][1], [1][2]->[2][2], ...

  => La nuova colonna è uguale alla riga, la nuova riga è uguale al complementare della colonna.
  [i][j]->[DIM-1-j][i]
*/

int main() {
  int m[DIM][DIM], m1[DIM][DIM], i, j;

  for (i = 0; i < DIM; i++)
    for (j = 0; j < DIM; j++)
      scanf("%d", &m[i][j]);

  for (i = 0; i < DIM; i++)
    for (j = 0; j < DIM; j++)
      m1[DIM-1-j][i] = m[i][j];

  for (i = 0; i < DIM; i++) {
    for (j = 0; j < DIM; j++)
      printf("%2d ", m1[i][j]);
    printf("\n");
  }

  return 0;
}