#include <stdio.h>

/*
  Si definisce triangolare un numero costituito dalla somma dei primi
  N numeri interi positivi per un certo N. Esempio: dato N=4, il
  numero triangolare Q è 10 (Q=1+2+3+4).
  Scrivere un programma che visualizza tutti i numeri triangolari
  minori o uguali ad un valore K chiesto all'utente.
*/

int main() {
  int k, n, q;

  scanf("%d", &k);
  n = 1;
  q = 1;

  while (q < k) {
    printf("%d ", q);
    n++;
    q += n;
  }
  printf("\n");

  return 0;
}
