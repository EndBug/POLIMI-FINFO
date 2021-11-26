#include <stdio.h>
#define CM 1.8
#define CA 32

/*
  Scrivere un programma che chiede all'utente un valore in virgola
  mobile che rappresenta una temperatura in gradi celsius, converte il
  valore in gradi Fahrenheit e visualizza il risultato. NOTA: la
  formula per la conversione è gradi_F = gradi_C x 1.8 + 32
*/

int main() {
  float cel, far;

  scanf("%f", &cel);

  far = cel * CM + CA;

  printf("%f\n", far);

  return 0;
}
