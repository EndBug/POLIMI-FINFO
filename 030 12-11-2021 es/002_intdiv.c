#include <stdio.h>

/*
  Scrivere un sottoprogramma ricorsivo che riceve due numeri interi
  positivi a e b e calcola risultato e resto della divisione intera a/
  b (senza l'utilizzo degli operatori / e %).
  Scrivere un programma che acquisisce due valori x e y ed invoca la
  funzione sopra definita, visualizzando poi il risultato.
*/

void intDiv(int, int, int*, int*);

int main() {
  int x, y, q, r;

  scanf("%d %d", &x, &y);
  intDiv(x, y, &q, &r);
  printf("Q: %d R: %d\n", q, r);

  return 0;
}

void intDiv(int a, int b, int *q, int *r) {
  if (a-b < 0) {
    *q = 0;
    *r = a;
  } else {
    intDiv(a-b, b, q, r);
    (*q)++;
  }
}