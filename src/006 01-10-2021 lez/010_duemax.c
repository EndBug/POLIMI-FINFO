#include <stdio.h>
#define DIM 10

/*
  Scrivere un programma che acquisisce 10 numeri interi. In seguito,
  il programma calcola i primi due valori massimi e li visualizza.
*/

int main() {
  int arr[DIM], i, m1, m2;

  for (i = 0; i < DIM; i++)
    scanf("%d", &arr[i]);

  m1 = arr[0];
  if (arr[1] > m1) {
    m2 = m1;
    m1 = arr[1];
  } else
    m2 = arr[1];

  for (i = 2; i < DIM; i++) {
    if (arr[i] > m1) {
      m2 = m1;
      m1 = arr[i];
    } else if (arr[i] > m2 && arr[i] != m1)
      /* Assumo che due valori identici vengano contati come uno solo. */
      m2 = arr[i];
  }

  printf("%d %d\n", m1, m2);

  return 0;
}
