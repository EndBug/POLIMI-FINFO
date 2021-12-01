#include <stdio.h>
#define MAX 10

/*
  ES1 - Scrivere un programma che mostra a video il triangolo di Tartaglia di
  dimensione chiesta all'utente (massimo 10). Il programma deve eseguire un
  controllo di validità sulla dimensione chiesta all'utente e nel caso di
  valore non valido richiederla. Esempio: il triangolo di Tartaglia di
  dimensione 5 (valore inserito dall'utente) è:
  1
  1 1
  1 2 1
  1 3 3 1
  1 4 6 4 1
*/

int main() {
  int dim, i, j;
  int t[MAX][MAX];

  do
    scanf("%d", &dim);
  while (dim < 1 || dim > MAX);

  for (i = 0; i < dim; i++) {
    for (j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        t[i][j] = 1;
      else
        t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
    }
  }

  for (i = 0; i < dim; i++) {
    for (j = 0; j <= i; j++)
      printf("%d ", t[i][j]);
    printf("\n");
  }
  return 0;
}
