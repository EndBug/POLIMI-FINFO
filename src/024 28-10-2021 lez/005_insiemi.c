#include <stdio.h>
#define DIM 20

/*
  Scrivere un sottoprogramma che riceve come parametri un array di
  interi e la sua dimensione. Il sottoprogramma popola tutto l'array
  con valori chiesti all'utente.
  Scrivere un secondo sottoprogramma che riceve come parametri un
  array di interi e la sua dimensione, quest'ultima passata per
  indirizzo. Il sottoprogramma rimuove dall'array i valori duplicati
  ed aggiorna la dimensione ricevuta come parametro con il numero
  effettivo di valori validi contenuti nell'array.
  Scrivere un terzo sottoprogramma che riceve come parametri due array
  con le relative dimensioni. Il sottoprogramma calcola l'intersezione
  del contenuto dei due array salvando il risultato in un terzo array
  ricevuto anch'esso come parametro; inoltre il sottoprogramma
  restituisce al chiamate tramite un ultimo parametro passato per
  indirizzo il numero effettivo di valori contenuti nell'intersezione.
  Scrivere un sottoprogramma che riceve come parametri un array di
  interi e la sua dimensione e visualizza il contenuto dell'array.
  Scrivere un programma che mediante l'ausilio dei sottoprogrammi
  sopra definiti 1) chiede all'utente i dati di tre array contenenti
  20 valori interi ciascuno, 2) rimuove i duplicati in ciascuno di
  essi, 3) visualizza i tre insiemi risultanti, 4) calcola
  l'intersezione dei tre insiemi, 5) visualizza il risultato finale.
*/

void popola(int *arr, int dim);
void rimuoviDup(int *arr, int *dim);
void intersezione(int *a, int dimA, int *b, int dimB, int *res, int *dimRes);
void visualizza(int *a, int dimA);

int main() {
  int a[DIM], b[DIM], c[DIM], res[DIM];
  int dimA, dimB, dimC, dimRes;

  dimA = dimB = dimC = DIM;

  popola(a, dimA);
  popola(b, dimB);
  popola(c, dimC);

  rimuoviDup(a, &dimA);
  rimuoviDup(b, &dimB);
  rimuoviDup(c, &dimC);

  visualizza(a, dimA);
  visualizza(b, dimB);
  visualizza(c, dimC);

  intersezione(a, dimA, b, dimB, res, &dimRes);
  intersezione(res, dimRes, c, dimC, res, &dimRes);
  visualizza(res, dimRes);

  return 0;
}

void popola(int *arr, int dim) {
  int i;
  for (i = 0; i < dim; i++)
    scanf("%d", arr + i);
}

void rimuoviDup(int *arr, int *dim) {
  int i, j, found;

  for (i = 0; i < *dim; i++) {
    for (j = 0, found = 0; j < i && !found; j++) {
      if (*(arr + j) == *(arr + i))
        found = 1;
    }

    if (found) {
      for (j = i; j < *dim - 1; j++) {
        *(arr + j) = *(arr + j + 1);
      }
      (*dim)--;
      i--;
    }
  }
}

void intersezione(int *a, int dimA, int *b, int dimB, int *res, int *dimRes) {
  int i, j, found;

  for (i = 0, *dimRes = 0; i < dimA; i++) {
    for (j = 0, found = 0; j < dimB && !found; j++) {
      if (*(a + i) == *(b + j))
        found = 1;
    }

    if (found) {
      *(res + (*dimRes)) = *(a + i);
      (*dimRes)++;
    }
  }
}

void visualizza(int *a, int dimA) {
  int i;
  for (i = 0; i < dimA; i++)
    printf("%d ", *(a + i));
  printf("\n");
}
