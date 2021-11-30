#include <stdio.h>
#define DIM 5

/*
  Scrivere un programma in C che chiede all'utente 5 valori interi non
  negativi e ne disegna l'istogramma a barre verticali orientate dal
  basso verso l'alto come mostrato nel seguente esempio. Se l'utente
  inserisce i valori: 1 4 5 2 1, il programma visualizzerà il seguente
  output:
      *
    * *
    * *
    * * *
  * * * * *
  1 4 5 2 1
*/

int main() {
  int a[DIM], i, j, max;

  /*
    max = 0 va bene finché i valori sono >= 0, altirmenti dovremmo calcolare
    il massimo in un ciclo separato
  */
  for (i = 0; i < DIM; i++)
    scanf("%d", &a[i]);

  for (i = 1, max = a[0]; i < DIM; i++)
    if (max < a[i])
      max = a[i];

  for (i = 1; i <= max; i++) {
    for (j = 0; j < DIM; j++) {
      if (DIM - a[j] >= i)
        printf("  ");
      else
        printf("* ");
    }
    printf("\n");
  }

  for (i = 0; i < DIM; i++)
    printf("%d ", a[i]);
  printf("\n");

  return 0;
}
