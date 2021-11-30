#include <stdio.h>

/*
  Scrivere un sottoprogramma che esegue la divisione tra due interi
  positivi, restituendo mediante parametri passati per indirizzo sia
  il risultato che il resto. Scrivere un programma che chiede un
  numero all'utente e trova il primo divisore più grande di 1,
  visualizzandolo il divisore ed il risultato della divisione.
*/

void divisione(int n, int d, int *q, int *r);

int main() {
  int n, d, q, r;

  scanf("%d", &n);

  d = 1;
  r = 1;
  while (r != 0) {
    d++;
    divisione(n, d, &q, &r);
  }

  printf("%d: %d/%d = %d resto %d\n", d, n, d, q, r);

  return 0;
}

void divisione(int n, int d, int *q, int *r) {
  *q = n / d;
  *r = n - ((*q) * d);
}
