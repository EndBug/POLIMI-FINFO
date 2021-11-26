#include <stdio.h>

/*
  Scrivere un programma che acquisisce 3 interi. Il programma verifica
  se costituiscono una terna pitagorica; in caso affermativo il
  programma stampa a video "1" altrimenti "0". NOTA: l'utente può
  inserire i tre numeri in qualsiasi ordine; es. "3 4 5" e "5 3 4"
  sono entrambe terne pitagoriche.
*/

int main() {
  int a, b, c, tmp, terna;

  scanf("%d %d %d", &a, &b, &c);

  /* Faccio in modo di avere l'ipotenusa in c. */
  if (a > b && a > c) {
    tmp = c;
    c = a;
    a = tmp;
  }
  if (b > a && b > c) {
    tmp = c;
    c = b;
    b = tmp;
  }

  terna = ((a * a) + (b * b) == (c * c));

  printf("%d\n", terna);

  return 0;
}
