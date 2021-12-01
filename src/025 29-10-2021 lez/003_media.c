#include <stdio.h>
#define NR 5
#define NC 5

/*
  Scrivere un sottoprogramma che riceve in ingresso un array
  bidimensionale di interi (dichiarato con NC=5 colonne) e le
  dimensioni effettive della parte della matrice utilizzata. Il
  sottoprogramma calcola la media dei valori contenuti nella matrice e
  trasmette al chiamante le coordinate del valore più vicino alla
  media. Se più valori hanno stessa distanza minima selezionare
  l'ultimo.
  Scrivere un programma che chiede all'utente i dati di una matrice
  5x5 di interi, invoca il sottoprogramma sopra definito e visualizza
  i risultati.
*/

void calcMedia(int m[][NC], int nRows, int nCols, int *x, int *y);
float absVal(float n);

int main() {
  int m[NR][NC], xRes, yRes, i, j;
  for (i = 0; i < NR; i++) {
    for (j = 0; j < NC; j++) {
      scanf("%d", &m[i][j]);
    }
  }

  calcMedia(m, NR, NC, &xRes, &yRes);

  printf("(%d, %d): %d\n", xRes, yRes, m[xRes][yRes]);

  return 0;
}

void calcMedia(int m[][NC], int nRows, int nCols, int *x, int *y) {
  int i, j;
  float media, dist;

  media = 0;
  for (i = 0; i < nRows; i++) {
    for (j = 0; j < nCols; j++) {
      media += m[i][j];
    }
  }
  media /= i * j;
  printf("%f\n", media);

  dist = -1;
  for (i = 0; i < nRows; i++) {
    for (j = 0; j < nCols; j++) {
      if (dist == -1 || absVal(media - m[i][j]) <= dist) {
        *x = i;
        *y = j;
        dist = absVal(media - m[i][j]);
      }
    }
  }
}

float absVal(float n) {
  if (n < 0)
    return -n;
  else
    return n;
}
