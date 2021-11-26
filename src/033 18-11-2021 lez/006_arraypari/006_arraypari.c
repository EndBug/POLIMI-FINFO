#include <stdio.h>
#include <stdlib.h>
#define DIM 10

/*
  Scrivere un sottoprogramma che riceve come parametri un array di
  interi a e la sua dimensione dim. Il sottoprogramma copia in un
  secondo array b i numeri pari contenuti in a; si noti che b deve
  essere allocato dinamicamente delle dimensioni strettamente
  necessarie per contenere i numeri pari. Infine il sottoprogramma
  trasmette al chiamante b e la sua dimensione. Gestire opportunamente
  gli eventuali errori di allocazione della memoria trasmettendo una
  dimensione dell'array allocato pari a -1.
  Scrivere un programma che chiede all'utente 10 valori interi da
  salvare in un array. Il programma invoca il sottoprogramma sopra
  definito e ne visualizza il risultato. Infine il programma libera la
  memoria allocata. Gestire opportunamente gli eventuali errori di
  allocazione della memoria.
*/

void arraypari(int[], int, int**, int*);

int main() {
  int arr[DIM], *res, dimRes, i;

  for (i = 0; i < DIM; i++)
    scanf("%d", &arr[i]);

  arraypari(arr, DIM, &res, &dimRes);

  if (dimRes > 0) {
    for (i = 0; i < dimRes; i++)
      printf("%d ", res[i]);
    printf("\n");

    free(res);
  } else if (dimRes == 0)
    printf("Array vuoto.\n");
  else
    printf("Errore.\n");  

  return 0;
}


void arraypari(int a[], int dima, int **b, int *dimb) {
  int i, j;
  for (i = 0, *dimb = 0; i < dima; i++) {
    if (a[i]%2 == 0) {
      (*dimb)++;
    }
  }

  if (*dimb != 0)
    *b = malloc(sizeof(int)*(*dimb));
  else
    *b = NULL;

  if (*b) {
    for (i = 0, j = 0; i < dima; i++) {
      if (a[i]%2 == 0) {
        *(*b + j) = a[i];
        j++;
      }
    }
  } else {
    *dimb = -1;
  }
}