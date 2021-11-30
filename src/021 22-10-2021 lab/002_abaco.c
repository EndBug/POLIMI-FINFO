#include <stdio.h>
#define BASE 10
#define VARIANTE 1

/*
  ES3. Scrivere un programma in C che chiede un numero intero positivo
  e nel caso in cui l'utente inserisca un numero non valido lo
  richiede. Il programma visualizza in formato "abaco" il numero dalla
  cifra meno significativa alla più significativa. Ad esempio se viene
  inserito il numero 2134, il programma stamperà a video:
  |****
  |***
  |*
  |**
  VARIANTE: modificare il programma in modo tale che visualizzi le
  cifre dalla più significativa alla meno significativa. Quindi per il
  numero 2134 il programma visualizza:
  |**
  |*
  |***
  |****
*/

int main() {
  if (VARIANTE)
    return main_VAR();
  else
    return main_SIMPLE();
}

int main_VAR() {
  int n, maxPot, q;

  do
    scanf("%d", &n);
  while (n <= 0);

  maxPot = 1;
  while (BASE * maxPot < n)
    maxPot *= BASE;

  while (n > 0) {
    maxPot /= BASE;

    if (maxPot) {
      q = n / (BASE * maxPot);
      n = n % (BASE * maxPot);
    } else {
      /*
        Isolo il caso in cui maxPot = 0, e quindi devo solo guardare l'ultima
        cifra.
      */
      q = n;
      n = 0;
    }

    printf("|");
    for (q; q > 0; q--)
      printf("*");
    printf("\n");
  }

  return 0;
}

int main_SIMPLE() {
  int n, r;

  do
    scanf("%d", &n);
  while (n <= 0);

  while (n > 0) {
    r = n % BASE;
    n /= BASE;

    printf("|");
    for (r; r > 0; r--)
      printf("*");
    printf("\n");
  }

  return 0;
}
