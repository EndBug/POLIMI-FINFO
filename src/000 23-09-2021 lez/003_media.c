#include <stdio.h>

/*
  Scrivere un programma che chiede all'utente due numeri interi. Il
  programma calcola e visualizza la media dei valori acquisti. Si noti
  che la media è un valore reale.
*/

int main() {
  int a, b;
  float media;

  scanf("%d %d", &a, &b);

  /*
    Se scriviamo (a+b)/2 viene eseguita una divisione intera, il cui risultato
    verrà convertito in float. Possiamo o utilizzare 2.0, inducendo un cast
    implicito, oppure utilizzare un operatore di cast esplicito. (float) è
    un'operatore unario, quindi ha priorità massima.
  */
  media = (float)(a + b) / 2;

  printf("%f\n", media);

  return 0;
}
