#include <stdio.h>
#define MAX_G 8

/*
  Da es. 10-01-2021
  Scrivere un programma in C in grado di calcolare il valore di
  polinomi di grado massimo 8. Il programma chiede all'utente il grado
  n del polinomio desiderato (un intero compreso tra 0 e 8 inclusi e
  nel caso di valore non valido lo richiede). Successivamente, chiede
  all'utente i coefficienti (interi) di tutti i monomi che compongono
  il polinomio. Infine, chiede all'utente il valore x (un intero) per
  cui fornire la soluzione del polinomio, la calcola e la stampa a
  video.
*/

int main() {
  /* Qui abbiamo usato un'espressione di costanti, che quindi è costante => ok */
  int poli[MAX_G+1], grado, i, x, val, potx;

  do
    scanf("%d", &grado);
  while (grado < 0 || grado > MAX_G);

  for (i = 0; i <= grado; i++) 
    scanf("%d", &poli[i]);
  /* => poli: x0, x1, x2, ... */

  scanf("%d", &x);

  for (i = 0, val = 0, potx = 1; i <= grado; i++) {
    val += potx * poli[i];
    potx *= x;
  }

  printf("%d\n", val);

  return 0;
}