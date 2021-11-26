#include <stdio.h>
#define PI 3.14

/*
  Scrivere un programma che chiede all'utente un valore in virgola
  mobile che rappresenta il raggio di un cerchio. Il programma calcola
  e visualizza l'area ed il perimetro di tale cerchio.
*/

int main() {
  float r, p, A;

  scanf("%f", &r);

  p = 2 * PI * r;
  A = PI * r * r;

  printf("%f %f\n", p, A);

  return 0;
}
