#include <stdio.h>
#define SIZE 20

/*
  ES1. Scrivere un programma in C che acquisisce 20 numeri interi
  salvandoli in una array a1. Il programma copia il contenuto di a1 in
  un secondo array a2 mettendo prima i numeri pari e poi quelli
  dispari. Infine il programma visualizza il risultato.
*/

int main() {
  int a1[SIZE], a2[SIZE], i, l;

  for (i = 0; i < SIZE; i++)
    scanf("%d", &a1[i]);

  l = 0;
  for (i = 0; i < SIZE; i++) {
    if ((a1[i] % 2) == 0) {
      a2[l] = a1[i];
      l++;
    }
  }

  for (i = 0; i < SIZE; i++) {
    if (a1[i] % 2) {
      a2[l] = a1[i];
      l++;
    }
  }

  for (i = 0; i < l; i++)
    printf("%d ", a2[i]);
  printf("\n");
  return 0;
}
