#include <stdio.h>
#define DIM 10

/*
  Scrivere un sottoprogramma che riceve come parametri due array di
  interi di egual dimensione, e qualsiasi altro parametro ritenuto
  strettamente necessario. Il sottoprogramma verifica se, pur di fare
  uno scorrimento circolare del secondo array, i due array siano
  identici. Nello scorrimento circolare, la cifra che si trova in
  ultima posizione diventa quella in prima posizione dopo lo
  scorrimento. In caso affermativo il sottoprogramma restituisce
  quante posizioni deve essere fatto scorrere il secondo array verso
  destra. In caso negativo, restituisce -1.
  Scrivere un programma che acquisisce i dati per popolare due array
  monodimensionali di 10 interi ciascuno. Il programma invoca il
  sottoprogramma sopra definito e visualizza il risultato.

  Esempio:
  se il sottoprogramma riceve i seguenti due array:
  a = [0 2 4 8 2 1 7 8 2 9]
  b = [1 7 4 8 2 7 2 6 1 6]
  Il sottoprogramma restituisce -1
  se il sottoprogramma riceve i seguenti due array:
  a = [5 4 9 8 3 0 1 9 3 4]
  b = [9 3 4 5 4 9 8 3 0 1]
  Il sottoprogramma restituisce 7
*/

int arrOffset(int[], int[], int);

int main() {
  int a[DIM], b[DIM];
  int i, res;

  for (i = 0; i < DIM; i++)
    scanf("%d", &a[i]);
  for (i = 0; i < DIM; i++)
    scanf("%d", &b[i]);

  res = arrOffset(a, b, DIM);

  printf("%d\n", res);

  return 0;
}

int arrOffset(int a[], int b[], int dim) {
  int i, equal, offset, res;

  res = -1;
  for (offset = 0; offset < dim && res < 0; offset++) {
    equal = 1;

    for (i = 0; i < dim && equal; i++) {
      if (a[(offset + i) % dim] != b[i])
        equal = 0;
    }

    if (equal)
      res = offset;
  }

  return res;
}
