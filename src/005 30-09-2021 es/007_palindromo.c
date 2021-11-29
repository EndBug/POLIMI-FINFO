#include <stdio.h>
#define BASE 10

/*
  Un numero intero è palindromo quando le sue cifre rappresentano lo
  stesso valore sia che siano lette da destra che da sinistra. Esempi
  di numeri palindromi sono 111, 121, 13431.
  Scrivere un programma che chiede all'utente un numero intero
  positivo (nel caso il valore non sia valido il programma stampa un
  messaggio di errore e richiede il valore). Il programma verifica se
  il numero è palindromo; in caso affermativo stampa a video 1 altrimenti
  0.
*/

int main() {
  int n, a, inverso, cifra;

  do
    scanf("%d", &n);
  while (n <= 0);

  a = n;
  inverso = 0;

  while (a > 0) {
    cifra = a % BASE;
    inverso = inverso * BASE + cifra;
    a /= BASE;
  }

  printf("Palindromo: %d\n", inverso == n);

  return 0;
}
