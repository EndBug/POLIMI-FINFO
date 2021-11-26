#include <stdio.h>
#define DIM 5

/*
  Scrivere un programma in C che chiede all'utente di inserire 5
  numeri interi e li salva in un array. Il programma inverte di ordine
  i numeri nell'array e poi li visualizza.
*/

int main() {
  int a[DIM], i, tmp;

  for (i = 0; i < DIM; i++)
    scanf("%d", &a[i]);
  
  /*
    Dobbiamo scambiare gli elementi da 0 a DIM/2
    Ciascun elemento viene scambiato con il suo opposto, i <-> DIM-1-i
    Questo ci permette di utilizzare una sola variabile indice

    Utilizziamo una variabile swap (tmp), in modo da non dover fare operazioni strane e
    rischiare di fare overflow
  */
  for (i = 0; i < DIM/2; i++) {
    tmp = a[i];
    a[i] = a[DIM-1-i];
    a[DIM-1-i] = tmp;
   }

  for (i = 0; i < DIM; i++)
    printf("%d\n", a[i]);

  return 0;
}
