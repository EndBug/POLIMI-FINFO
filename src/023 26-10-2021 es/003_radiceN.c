#include <stdio.h>

/*
  Scrivere un sottoprogramma che riceve due numeri interi positivi e
  calcola l'elevamento a potenza del primo rispetto al secondo,
  restituendo il risultato.
  Scrivere un sottoprogramma che calcola la radice ennesima intera di
  un numero intero positivo. Il sottoprogramma prende come parametri
  il numero, il grado della radice, e una variabile, passata per
  indirizzo, in cui memorizzare la radice intera. Il sottoprogramma
  restituisce 1 se la radice intera è precisa, in alternativa 0.
  Scrivere un programma che utilizza tale sottoprogramma per calcolare
  la radice ennesima intera di un numero e di un grado chiesti
  all'utente, e ne visualizza il risultato.
*/

int potenza(int, int);
int radice(int, int, int *);

int main() {
  int n, grado, rad, prec;

  scanf("%d %d", &n, &grado);

  prec = radice(n, grado, &rad);

  printf("%d (prec: %d)\n", rad, prec);

  return 0;
}

int potenza(int base, int esponente) {
  int i, res;

  for (i = 0, res = 1; i < esponente; i++)
    res *= base;

  return res;
}

int radice(int arg, int grado, int *res) {
  *res = 0;

  while (potenza(*res, grado) < arg)
    (*res)++;

  if (potenza(*res, grado) == arg)
    return 1;
  else {
    (*res)--;
    return 0;
  }
}
