#include <stdio.h>

/*
  Scrivere un programma in C che chiede all'utente una serie di numeri
  interi terminata dal valore 0 (che non fa parte della sequenza). Il
  programma stabilisce se la serie, se non vuota, è monotona crescente
  (non strettamente) e visualizza un apposito messaggio di testo.
*/

int main() {
  int a, b, ok;

  scanf("%d", &a);

  if (a != 0) {
    ok = 1;

    while (a != 0 && ok) {
      scanf("%d", &b);

      if (b < a)
        ok = 0;

      a = b;
    }

    if (ok)
      printf("Monotona crescente.\n");
    else
      printf("Non Monotona crescente.\n");
  } else
    printf("Sequenza vuota.\n");

  return 0;
}