#include <stdio.h>

/*
  Scrivere un programma che ricevuto in ingresso due numeri interi
  positivi a e b (e se così non è, li richiede), visualizza un
  rettangolo di dimensione a*b usando il carattere '*'.
*/

int main() {
  int a, b, i, j;

  scanf("%d %d", &a, &b);

  i = 0;
  while (i < a) {
    j = 0;
    while (j < b) {
      printf("*");
      j++;
    }

    printf("\n");
    i++;
  }

  return 0;
}
