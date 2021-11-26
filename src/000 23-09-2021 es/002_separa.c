#include <stdio.h>

/*
  Scrivere un programma che chiede all'utente una numero in virgola
  mobile. Il programma calcola e visualizza su due righe separate la
  parte intera e quella decimale di tale numero. Per esempio nel caso
  in cui l'utente inserisce il numero 4.14, il programma visualizzerà:
  4
  0.14
*/

int main() {
  float n, decimale;
  int intera;

  scanf("%f", &n);

  /*
    In questo assegnamento stiamo facendo il cast di float su int, perdendo la
    parte decimale.
  */
  intera = n;
  decimale = n - intera;

  printf("%d\n%f\n", intera, decimale);

  return 0;
}
