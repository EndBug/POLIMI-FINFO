#include <stdio.h>
#define BASE 10

/*
  Scrivere un programma in C che chiede all'utente un numero intero
  positivo e nel caso questo non sia valido stampa un messaggio
  dell'errore e continua a richiederlo. Il programma verifica se il
  numero è composto da sole cifre pari (0, 2, 4, 6, 8) e visualizza un
  messaggio con il responso del test (1: vero, 0: falso).
*/

int main() {
  int n, cifra, tuttePari;

  scanf("%d", &n);
  while (n <= 0) {
    printf("Errore input.\n");
    scanf("%d", &n);
  }

  tuttePari = 1;
  while (n > 1 && tuttePari) {
    cifra = n % BASE;
    n /= BASE;

    if (cifra % 2)
      tuttePari = 0;
  }

  if (tuttePari)
    printf("Vero.\n");
  else
    printf("Falso.\n");

  return 0;
}
