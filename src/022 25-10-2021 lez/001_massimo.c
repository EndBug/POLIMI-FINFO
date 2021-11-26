#include <stdio.h>
#define DIM 10

/*
  Scrivere un programma che chiede all'utente tre numeri interi e,
  mediante l'utilizzo di un puntatore, identifica e visualizza il
  valore massimo.
  Estendere il programma in modo tale che chieda 10 valori da salvare
  in un array ed in seguito calcoli e visualizzi il valore massimo.
*/

int main() {
  int a[DIM], i, *max;

  for (i = 0; i < DIM; i++)
    scanf("%d", &a[i]);

  max = &a[0];
  for (i = 1; i < DIM; i++)
    if (*max < a[i])
      max = &a[i];

  printf("%d\n", *max);

  return 0;
}

int main_0() {
  int a, b, c, *max;

  scanf("%d %d %d", &a, &b, &c);

  /* Dato che qua gli assegno sicuramente un valore, non è necessario inizializzare max a NULL. */
  if (a > b)
    max = &a;
  else
    max = &b;

  if (*max < c)
    max = &c;

  printf("%d\n", *max);

  return 0;
}