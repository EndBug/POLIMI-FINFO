#include <stdio.h>

/*
  Scrivere un sottoprogramma ricorsivo che calcola e restituisce Il
  fattoriale di un numero intero positivo o nullo n ricevuto come
  parametro.
  Scrivere un programma che chiede all'utente un valore intero
  positivo o nullo (e nel caso non sia un valore valido lo richiede),
  invoca il sottoprogramma definito e visualizza il risultato.
*/

int fattoriale(int);

int main() {
  int n, f;

  do
    scanf("%d", &n);
  while (n < 0);

  f = fattoriale(n);

  printf("%d\n", f);

  return 0;
}

int fattoriale(int n) {
  if (n > 1) /* passo ricorsivo */
    return n * fattoriale(n-1);
  else /* n == 0 || n == 1, per definizione => caso base */
    return 1;
}