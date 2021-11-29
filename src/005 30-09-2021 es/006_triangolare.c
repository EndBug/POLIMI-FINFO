#include <stdio.h>

/*
  Si definisce triangolare un numero costituito dalla somma dei primi
  N numeri interi positivi per un certo N. Esempio: dato N=4, il
  numero triangolare Q è 10 (Q=1+2+3+4).
  Scrivere un programma che acquisisce un numero intero positivo Q (si
  assuma che l'utente inserisca un valore valido) e stabilisce se tale
  numero è triangolare o meno, visualizzando il responso (1: vero, 0:
  falso).
*/

int main() {
  int q, n, k, tr;

  scanf("%d", &q);
  n = 1;
  k = 1;
  tr = 0;

  while (k <= q && !tr) {
    if (k == q)
      tr = 1;

    n++;
    k += n;
  }

  if (tr)
    printf("Vero.\n");
  else
    printf("Falso.\n");

  return 0;
}
