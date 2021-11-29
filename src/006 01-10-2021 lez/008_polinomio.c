#include <stdio.h>
#define GRADO_MAX 8

/*
  Scrivere un programma in grado di calcolare il valore di polinomi di
  grado massimo 8. Il programma chiede all'utente il grado n del
  polinomio desiderato (un intero compreso tra 0 e 8 inclusi e nel
  caso di valore non valido lo richiede). Successivamente, chiede
  all'utente i coefficienti (interi) di tutti i monomi che compongono
  il polinomio. Infine, chiede all'utente il valore x (un intero) per
  cui fornire la soluzione del polinomio, la calcola e la stampa a
  video.
*/

int main() {
  int p[GRADO_MAX + 1], grado, x, i, potX, res;

  printf("Grado: ");
  scanf("%d", &grado);
  while (grado < 0 || grado > GRADO_MAX) {
    printf("Errore input.\nGrado: ");
    scanf("%d", &grado);
  }

  printf("Coefficienti: ");
  for (i = 0; i <= grado; i++) {
    scanf("%d", &p[i]);
  }

  printf("x: ");
  scanf("%d", &x);

  for (i = 0, potX = 1, res = 0; i <= grado; i++, potX *= x)
    res += p[i] * potX;

  printf("%d\n", res);

  return 0;
}
