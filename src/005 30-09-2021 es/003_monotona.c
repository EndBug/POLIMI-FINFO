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

    scanf("%d", &b);
    while (b != 0 && ok) {

      if (b < a)
        ok = 0;

      a = b;
      scanf("%d", &b);
    }

    if (ok)
      printf("Monotona crescente.\n");
    else
      printf("Non monotona crescente.\n");
  } else
    printf("Sequenza vuota.\n");

  return 0;
}
