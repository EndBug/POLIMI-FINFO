#include <stdio.h>
#define N 4

/*
  Scrivere un programma che chiede all'utente di inserire i dati
  interi di un array bidimensionale quadrato di dimensione 4x4 e
  visualizza 1 se la matrice è simmetrica, altrimenti 0.
*/

int main() {
  int m[N][N], i, j, simm;

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      scanf("%d", &m[i][j]);

  for (i = 0, simm = 1; i < N && simm; i++) {
    for (j = 0; j < i && simm; j++) {
      if (m[i][j] != m[j][i])
        simm = 0;
    }
  }

  printf("Simmetrica: %d\n", simm);

  return 0;
}
