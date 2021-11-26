#include <stdio.h>

/*
  Scrivere un programma che acquisisce due numeri interi e stampa a
  video il maggiore dei due.
*/

int main() {
  int a, b;

  scanf("%d %d", &a, &b);

  if (a > b)
    printf("%d\n", a);
  else
    printf("%d\n", b);

  return 0;
}
