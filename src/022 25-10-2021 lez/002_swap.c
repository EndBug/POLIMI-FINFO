#include <stdio.h>

/*
  Scrivere un sottoprogramma che riceve in ingresso due variabili
  contenenti due numeri interi e ne scambia il contenuto, rendendo
  effettiva la modifica anche nel chiamante. Scrivere un programma che
  acquisisce due numeri interi e li scambia mediante il sottoprogramma
  sopra definito.
*/

void swap(int *, int *);

int main() {
  int x, y;

  scanf("%d %d", &x, &y);

  swap(&x, &y);

  printf("%d %d\n", x, y);

  return 0;
}

void swap(int *a, int *b) {
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}
