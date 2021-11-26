#include <stdio.h>
#define MAXR 5
#define MAXC 10

/*
Scrivere un programma in C che visualizza la tabella pitagorica.
*/

int main() {
  int i, j, n;

  i = 1;
  while (i <= MAXR) {
    j = 1;
    while (j <= MAXC) {
      n = i*j;

      /* Utilizziamo 3d per indicare di spaziarli come se avessero 3 cifre. */
      printf("%3d ", n);
      j++;
    }
    printf("\n");
    i++;
  }

  return 0;
}