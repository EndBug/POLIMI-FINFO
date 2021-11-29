#include <stdio.h>
#define N 50

/*
  Scrivere un programma che calcola il massimo di una sequenza di 50
  numeri interi inseriti dall'utente e visualizza il risultato.
*/

int main() {
  int n, i, max;

  scanf("%d", &n);
  max = n;

  i = 1;
  while (i < N) {
    scanf("%d", &n);
    if (max < n)
      max = n;
    i++;
  }

  printf("Max: %d\n", max);

  return 0;
}
