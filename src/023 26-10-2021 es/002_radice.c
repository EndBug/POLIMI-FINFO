#include <stdio.h>

/*
  Scrivere un sottoprogramma che calcola la radice quadrata intera di
  un numero intero positivo. Il sottoprogramma riceve come parametro
  il numero intero ed un'altra variabile, passata per indirizzo, in
  cui memorizzare la radice intera. Il sottoprogramma restituisce 1 se
  la radice intera è precisa, in alternativa 0. Scrivere un programma
  che utilizza tale sottoprogramma per calcolare la radice quadrata
  intera di un numero chiesto all'utente, e ne visualizza il
  risultato.
*/

int radice(int, int*);

int main() {
  int n, rad;

  scanf("%d", &n);

  radice(n, &rad);

  printf("%d\n", rad);

  return 0;
}

int radice(int arg, int *res) {
  *res = 0;

  while ((*res)*(*res) < arg) {
    (*res)++;
  }

  if ((*res)*(*res) == arg) 
    return 1;
  else {
    (*res)--;
    return 0;
  }
}