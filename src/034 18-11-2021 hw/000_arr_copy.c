#include <stdio.h>
#include <stdlib.h>
#define DIM 10

/*
  Scrivere un sottoprogramma che riceve come parametri un array a1 di
  interi, la sua dimensione dim ed un puntatore ad intero a2. Il
  sottoprogramma alloca dinamicamente un array della stessa dimensione
  dim, vi copia il contenuto di a1 e lo trasmette al chiamante tramite
  il puntatore a2. Gestire opportunamente gli eventuali errori di
  allocazione della memoria.
  Scrivere un programma che dichiara un array da 10 elementi interi e
  lo popola con i valori letti da tastiera. Il programma invoca il
  sottoprogramma sopra definito e visualizza il suo risultato. Infine
  il programma rilascia la memoria allocata dinamicamente. Gestire
  opportunamente gli eventuali errori di allocazione della memoria.
*/

void arrayCopy(int a1[], int dim, int **a2);

int main() {
  int arr[DIM], *res, i;

  for (i = 0; i < DIM; i++)
    scanf("%d", &arr[i]);

  arrayCopy(arr, DIM, &res);

  if (res) {
    for (i = 0; i < DIM; i++)
      printf("%d ", *(res + i));
    printf("\n");

    free(res);
  }

  return 0;
}

void arrayCopy(int a1[], int dim, int **a2) {
  int i;

  *a2 = malloc(dim * sizeof(int));

  if (*a2) {
    for (i = 0; i < dim; i++)
      *((*a2) + i) = a1[i];
  } else
    printf("Errore di allocazione.\n");
}
