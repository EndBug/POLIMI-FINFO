#include <stdio.h>
#define DIM 10

/*
  Scrivere un sottoprogramma ricorsivo che riceve come parametro un
  array di interi (e la sua dimensione) e ne calcola e restituisce il
  valore massimo.
  Scrivere un programma che chiede all'utente 10 valori interi, invoca
  il sottoprogramma definito e visualizza il risultato.
*/

int max(int[DIM], int);

int main() {
  int arr[DIM], i, m;

  for (i = 0; i < DIM; i++)
    scanf("%d", &arr[i]);

  m = max(arr, DIM);

  printf("%d\n", m);

  return 0;
}

int max(int *arr, int dim) {
  int m;

  if (dim == 1)
    return *arr;
  else {
    m = max(arr+1, dim-1);

    if (*arr > m)
      return *arr;
    else
      return m;
  }

}