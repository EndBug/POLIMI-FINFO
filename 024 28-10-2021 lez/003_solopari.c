#include <stdio.h>
#define DIM 10

/*
  Scrivere un sottoprogramma che riceve come parametri due array a1 e
  a2 di interi e le relative dimensioni d1 e d2, quest'ultima passata
  per indirizzo. Il sottoprogramma individua i valori pari contenuti
  in a1 e li salva in a2, aggiornando in d2 il numero effettivo di
  valori salvati.
  Scrivere un programma che chiede all'utente 10 valori da memorizzare
  in un array, invoca la funzione sopra definita e visualizza il
  contenuto finale dell'array.
*/

void soloPari(int[], int, int*, int*);

int main() {
  int a1[DIM], a2[DIM], d2, i;

  for (i = 0; i < DIM; i++)
    scanf("%d", &a1[i]);

  soloPari(a1, DIM, a2, &d2);

  for (i = 0; i < d2; i++)
    printf("%d ", a2[i]);
  printf("\n");

  return 0;
}

void soloPari(int a1[], int d1, int *a2, int *d2) {
  int i;

  for (i = 0, *d2 = 0; i < d1; i++) {
    if (!(a1[i] % 2)) {
      *(a2 + *d2) = a1[i];
      (*d2)++;
    }
  }
}