#include <stdio.h>

/*
  Scrivere un programma che chiede all'utente due numeri in virgola
  mobile che rappresentano i parametri a e b di un'equazione di primo
  grado ax+b=0. Il programma calcola e visualizza la soluzione
  dell'equazione. Si ricordi che l'equazione può essere impossibile o
  indeterminata.
*/

int main() {
  float a, b, risultato;

  scanf("%f %f", &a, &b);

  if (a != 0) {
    risultato = -b / a;
    printf("x = %f", risultato);
  } else {
    if (b == 0)
      printf("Indeterminata.\n");
    else
      printf("Impossibile.\n");
  }

  return 0;
}
