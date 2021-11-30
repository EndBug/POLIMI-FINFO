#include <stdio.h>

/*
  Scrivere un sottoprogramma che riceve in ingresso un valore intero e
  ne restituisce il valore assoluto.
  Scrivere un sottoprogramma che riceve in ingresso due numeri interi
  e ne restituisce il minore.
  Scrivere un programma che chiede all'utente due valori interi; il
  programma calcola e visualizza il minore tra i valori assoluti dei
  due numeri mediante i sottoprogrammi sopra definiti.
*/

int abs(int);
int min(int, int);

int main() {
  int a, b, res;

  scanf("%d %d", &a, &b);

  res = min(abs(a), abs(b));

  printf("%d\n", res);

  return 0;
}

int abs(int n) {
  int res;

  if (n < 0)
    res = -n;
  else
    res = n;

  return res;
}

int min(int a, int b) {
  int res;

  if (a < b)
    res = a;
  else
    res = b;

  return res;
}
