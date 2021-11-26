#include <stdio.h>
#define DIM 10

/*
  Scrivere un programma in C che chiede all'utente una sequenza di 10
  numeri interi. Il programma controlla che non vi siano duplicati
  all'interno della sequenza data e visualizza l'esito del test (1 se
  non ci sono duplicati, 0 altrimenti).
*/

int main() {
  int a[DIM], nodup, i, j;

  for (i = 0; i < DIM; i++)
    scanf("%d", &a[i]);

  for (i = 0, nodup = 1; i < DIM && nodup; i++)
    for (j = 0; j < i && nodup; j++)
      if (a[i] == a[j])
        nodup = 0;
  

  printf("OK: %d\n", nodup);

  return 0;
}