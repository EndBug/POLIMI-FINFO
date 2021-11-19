#include <stdio.h>
#include <stdlib.h>
#define DIM 10

/*
  Scrivere un sottoprogramma che riceve come parametri un array a1 di
  interi e la sua dimensione dim. Il sottoprogramma alloca
  dinamicamente un array della stessa dimensione dim, vi copia il
  contenuto di a1 e lo restituisce al chiamante. Gestire
  opportunamente gli eventuali errori di allocazione della memoria.
  Scrivere un programma che dichiara un array da 10 elementi interi e
  lo popola con i valori letti da tastiera. Il programma invoca il
  sottoprogramma sopra definito e visualizza il suo risultato. Infine
  il programma rilascia la memoria allocata dinamicamente. Gestire
  opportunamente gli eventuali errori di allocazione della memoria.
*/

int* arrayCopy(int[], int);

int main() {
  int a1[DIM], *a2, i;

  for (i = 0; i < DIM; i++)
    scanf("%d", &a1[i]);

  a2 = arrayCopy(a1, DIM);

  if (a2) {
    for (i = 0; i < DIM; i++)
      printf("%d ", a2[i]);
    printf("\n");

    /* 
      La free va messa qua, perché se facciamo free(NULL) il programma crasha 
      (non possiamo liberare 0x0, che non ci è mai stato allocato)
    */
    free(a2);
  }

  return 0;
}

int* arrayCopy(int a[], int dim) {
  int i, *p;

  p = (int*) malloc(sizeof(int)*dim);

  if (p) {
    for (i = 0; i < dim; i++)
      *(p+i) = a[i];
  } else
    printf("Errore\n");

  /* Se ci sarà stato un errore avrò restituito NULL */
  return p;
}