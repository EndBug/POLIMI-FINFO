#include <stdio.h>

/*
  Scrivere un programma chiede all'utente un numero intero e ne
  visualizza il suo valore assoluto.
*/

int main() {
  int n;

  scanf("%d", &n);

  if (n < 0)
    n = -n;

  printf("%d\n", n);

  return 0;
}
