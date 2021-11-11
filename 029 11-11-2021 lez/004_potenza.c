#include <stdio.h>

/*
  Scrivere un sottoprogramma ricorsivo che riceve come parametri due
  interi positivi a e b, calcola e restituisce a^b.
  Scrivere un programma che chiede due numeri interi m e n che
  rappresentano la base e l'esponente di una potenza (e che si assume
  vengano inseriti correttamente) ed invoca il sottoprogramma per
  calcolare la potenza m^n. Il programma visualizza infine il
  risultato.
*/

int potenza(int, int);

int main() {
  int m, n, p;

  scanf("%d %d", &m, &n);

  p = potenza(m, n);

  printf("%d\n", p);

  return 0;
}

int potenza(int a, int b) {
  if (b == 0)
    return 1;
  
  return a * potenza(a, b-1);
}