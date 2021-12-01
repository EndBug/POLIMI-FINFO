#include <stdio.h>

/*
  Scrivere un sottoprogramma ricorsivo che calcola e restituisce l'iesimo
  numero della sequenza di Fibonacci con i intero positivo o
  nullo ricevuto come parametro.
  Scrivere un programma che chiede all'utente un valore intero
  positivo o nullo (che si assume venga inserito correttamente),
  invoca il sottoprogramma definito e visualizza il risultato.
*/

int fibonacci(int);

int main() {
  int n, f;

  scanf("%d", &n);

  f = fibonacci(n);

  printf("%d\n", f);

  return 0;
}

/*
  Questa soluzione ricalca precisamente la definizione, ed è quindi molto
  elegante, però è molto costosa dal punto di vista computazionale.
*/
int fibonacci(int i) {
  if (i >= 2)
    return fibonacci(i - 1) + fibonacci(i - 2);
  else
    return i;
}
