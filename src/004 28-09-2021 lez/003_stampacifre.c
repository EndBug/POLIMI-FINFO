#include <stdio.h>
#define BASE 10

/*
  Scrivere un programma in C che chiede all'utente un numero intero
  positivo (assumiamo per brevità che l'utente inserisca correttamente
  il valore). Il programma stampa a video le cifre che compongono il
  numero al contrario dalla più piccola alla più grande.
  Esempio: se l'utente inserisce il valore 23445, il programma stampa
  il messaggio "54432".
*/

int main() {
  int n, cifra, b;

  scanf("%d", &n);

  for (cifra = 9; cifra >= 0; cifra--) {
    for (b = n; b; b /= BASE) {
      if (b % BASE == cifra)
        printf("%d", cifra);
    }
  }
  printf("\n");

  return 0;
}
