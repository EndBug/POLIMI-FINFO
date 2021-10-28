#include <stdio.h>
#define DIM 10

/*
  Scrivere un sottoprogramma che riceve come parametri un array di
  interi e la sua dimensione. Il sottoprogramma sostituisce ciascun
  valore negativo dell'array con il suo valore assoluto. Scrivere un
  programma che chiede all'utente 10 valori da memorizzare in un
  array, invoca la funzione sopra definita e visualizza il contenuto
  finale dell'array.
*/

void absArr(int*, int);

int main() {
  int arr[DIM], i;

  for (i = 0; i < DIM; i++)
    scanf("%d", &arr[i]);

  absArr(arr, DIM);

  for (i = 0; i < DIM; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}

void absArr(int *arr, int dim) {
  int i;

  for (i = 0; i < dim; i++) {
    if (*(arr+i) < 0)
      *(arr+i) *= -1;
  }
}

/*
  Questa soluzione è equivalente, semplicemente si usa una notazione differente.
  Teoricamente potremmo anche dichiarare *arr e poi accedere con arr[i], però non
  è bello dal punto di vista stilistico => scegliamo una notazione e usiamo quella
  in tutto il corpo della funzione.
*/
void absArrVAR(int arr[], int dim) {
  int i;

  for (i = 0; i < dim; i++) {
    if (arr[i] < 0)
      arr[i] *= -1;
  }
}