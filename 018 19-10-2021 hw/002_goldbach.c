#include <stdio.h>

/*
  In matematica, la congettura di Goldbach è uno dei più vecchi
  problemi irrisolti nella teoria dei numeri. Essa afferma che ogni
  numero pari maggiore di 2 può essere scritto come somma di due
  numeri primi (che possono essere anche uguali).
  Scrivere un sottoprogramma che riceve un numero intero positivo
  maggiore di 1 e restituisce 1 se il numero è primo, 0 altrimenti.
  Scrivere un programma che chiede all'utente un numero n maggiore di
  2 e pari (nel caso richiede il numero) e calcola e visualizza tutte
  le possibili coppie di numeri primi la cui somma è uguale ad n.
*/

int primo(int);

int main() {
  int n, i;

  do
    scanf("%d", &n);
  while (n < 2 || n % 2);

  for (i = 1; i < n/2; i++) {
    if (primo(i) && primo(n-i))
      printf("(%d, %d)\n", i, n-i);
  }

  return 0;
}

int primo(int n) {
  int i, flag;

  for (i = n/2, flag = 1; i > 1 && flag; i--) {
    if (!(n % i))
      flag = 0;
  }

  return flag;
}