#include <stdio.h>
#include <stdlib.h>

/*
  Scrivere un sottoprogramma che riceve come parametro un intero
  positivo N, alloca dinamicamente e restituisce una matrice quadrata
  NxN. Il sottoprogramma restituisce NULL nel caso di errore di
  allocazione (deallocando l'eventuale memoria già allocata).
  Scrivere un sottoprogramma che riceve come parametro una matrice
  bidimensionale allocata dinamicamente ed il suo numero di righe, e
  ne libera la memoria.
  Scrivere un programma che chiede all'utente la dimensione di una
  matrice quadrata m e poi i dati per popolarla; non sapendo a priori
  le dimensioni della matrice m, il programma allocherà la matrice
  mediante il sottoprogramma sopra definito. Il programma cerca nella
  matrice m la sottomatrice di dimensione massima che parte da m[0][0]
  e la cui somma dei valori è pari a zero e, se esiste, la salva in
  una seconda matrice allocata anch'essa dinamicamente. In seguito, il
  programma stampa a video la nuova matrice calcolata (se esiste),
  libera la memoria e termina. Gestire opportunamente gli eventuali
  errori nell'allocazione della memoria.
  Esempio: se l'utente inserisce la matrice 3x3:
   1  2  3
  -1 -2  3
   3  3  3
  La sottomatrice a somma nulla di dimensione massima che parte da
  m[0][0] è:
   1  2
  -1 -2
*/

int** buildMatrix(int n);
void clearMatrix(int **m, int n);

int main() {
  int **m, n, i, j, ii, jj, r, acc, found;

  scanf("%d", &n);
  m = buildMatrix(n);

  if (m) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++)
        scanf("%d", *(m+i)+j);
    }

    found = 0;
    for (r = n; r > 0 && !found; r--) {
      for (i = 0; i <= n-r && !found; i++) {
        for (j = 0; j <= n-r && !found; j++) {
          acc = 0;

          for (ii = 0; ii < r; ii++) {
            for (jj = 0; jj < r; jj++) {
              acc += m[i+ii][j+jj];
            }
          }

          if (acc == 0)
            found = 1;
        }
      }
    }

    if (found) {
      printf("Start: m[%d][%d], R: %d\n", i-1, j-1, r+1);
      for (ii = 0; ii < r+1; ii++) {
        for (jj = 0; jj < r+1; jj++)
          printf("%2d ", m[i-1 + ii][j-1 + jj]);
        printf("\n");
      }
    } else
      printf("Non trovata.\n");

    for (i = 0; i < n; i++)
      free(*(m+i));
    free(m);
  } else
    printf("Errore di allocazione.\n");

  return 0;
}

int** buildMatrix(int n) {
  int **m, i, j, stop;

  m = malloc(n * sizeof(int*));

  if (m) {
    for (i = 0, stop = 0; i < n; i++) {
      *(m+i) = malloc(n * sizeof(int));

      if (!(*(m+i)))
        stop = 1;
    }

    if (stop) {
      for (j = 0; j < i; j++)
        free(*(m+i));
      m = NULL;
    }
  }

  return m;
}

void clearMatrix(int **m, int n) {
  int i;

  for (i = 0; i < n; i++)
    free(*(m+i));
}