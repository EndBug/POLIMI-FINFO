#include <stdio.h>
#define DIM 10

/*
  Scrivere un sottoprogramma ricorsivo che riceve come parametri un
  array di interi ordinati in ordine crescente (e la sua dimensione)
  ed un numero n. Il sottoprogramma verifica se n è contenuto
  nell'array utilizzando il metodo della bisezione. In caso
  affermativo restituisce 1 altrimenti 0.
  Scrivere un programma che chiede all'utente 10 valori interi, invoca
  il sottoprogramma definito e visualizza il risultato.
*/

int includes(int, int*, int);

int main() {
  int arr[DIM], n, i, res;

  for (i = 0; i < DIM; i++)
    scanf("%d", &arr[i]);
  scanf("%d", &n);

  res = includes(n, arr, DIM);

  printf("%d\n", res);

  return 0;
}

int includes(int n, int *arr, int dim) {
  if (dim == 1)
    return *arr == n;

  if (*(arr + dim/2) > n)
    return includes(n, arr, dim/2);
  else
    return includes(n, arr + dim/2, dim - (dim/2));
}