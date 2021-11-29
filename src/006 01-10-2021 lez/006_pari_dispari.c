#include <stdio.h>
#define DIM 10

/*
  Scrivere un programma che chiede all'utente di inserire una sequenza
  10 numeri interi; il programma visualizza tutti i pari, poi tutti i
  dispari.
*/

int main() {
  int arr[DIM], i;

  for (i = 0; i < DIM; i++)
    scanf("%d", &arr[i]);

  for (i = 0; i < DIM; i++) {
    if (!(arr[i] % 2))
      printf("%d ", arr[i]);
  }
  for (i = 0; i < DIM; i++) {
    if (arr[i] % 2)
      printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
