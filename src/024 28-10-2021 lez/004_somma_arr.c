#include <stdio.h>
#define DIM 10

/*
  Scrivere un sottoprogramma che riceve come parametri un array di
  interi e la sua dimensione. Il sottoprogramma calcola la somma dei
  valori dell'array e restituisce il risultato.
  Scrivere un programma che chiede all'utente 10 valori da memorizzare
  in un array e mediante l'ausilio della funzione sopra definita
  calcola la somma dei valori della prima metà dell'array e quella
  della seconda metà. Infine il programma valuta se la prima somma è
  maggiore visualizzando un apposito messaggio a video.
*/

int sommaArr(int[], int);

int main() {
  int arr[DIM], i, s1, s2;

  for (i = 0; i < DIM; i++)
    scanf("%d", &arr[i]);

  s1 = sommaArr(arr, DIM / 2);
  s2 = sommaArr(arr + DIM / 2, DIM / 2);

  if (s1 > s2)
    printf("Maggiore\n");
  else
    printf("Non maggiore\n");

  return 0;
}

int sommaArr(int arr[], int dim) {
  int i, acc;

  for (i = 0, acc = 0; i < dim; i++)
    acc += arr[i];

  return acc;
}
