#include <stdio.h>

/*
  Scrivere un programma che chiede all'utente i tre coefficienti di
  un'equazione di secondo grado (ax^2+bx+c=0), tre numeri in virgola
  mobile. Il programma verifica prima che l'equazione sia
  effettivamente di secondo grado (ovvero a != 0). In caso
  affermativo, il programma deve calcolarne il determinante e
  informare l'utente se le soluzioni sono reali e distinte (det>0),
  coincidenti (det=0) o complesse coniugate (det<0). Nel caso a=0, il
  programma stampa un messaggio di errore.
*/

int main() {
  float a, b, c, det;

  scanf("%f %f %f", &a, &b, &c);

  if (a != 0) {
    det = b * b - 4 * a * c;

    if (det > 0)
      printf("Reali e distinte.\n");
    else if (det == 0)
      printf("Reali e coincidenti.\n");
    else
      printf("Complesse coniugate.\n");
  } else
    printf("Errore.\n");

  return 0;
}
