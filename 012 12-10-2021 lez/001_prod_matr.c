#include <stdio.h>
#define MAXDIM 5

/*
  Definire un tipo di dato in C per rappresentare una matrice
  bidimensionale di valori in virgola mobile di dimensioni massime
  5x5; la struttura dati dovrà memorizzare le dimensioni effettive
  della matrice ed i dati. Scrivere un programma in C che acquisisce
  due matrici, chiedendo prima le dimensioni (e richiedendole nel caso
  non siano valide) e poi i valori. Il programma calcola, se
  possibile, il prodotto matriciale visualizzando il risultato; in
  alternativa visualizza un messaggio di errore.
*/

typedef struct {
  float dati[MAXDIM][MAXDIM];
  int righe, colonne;
} matrice_t;

int main() {
  matrice_t a, b, p;
  int i, j, k;

  do
    scanf("%d", &a.righe);
  while (a.righe <= 0 || a.righe > MAXDIM);
  do
    scanf("%d", &a.colonne);
  while (a.colonne <= 0 || a.colonne > MAXDIM);
  for (i = 0; i < a.righe; i++)
    for (j = 0; j < a.colonne; j++)
      scanf("%f", &a.dati[i][j]);

  /* Qua facciamo copia-incolla, poi useremo le funzioni */
  do
    scanf("%d", &b.righe);
  while (b.righe <= 0 || b.righe > MAXDIM);
  do
    scanf("%d", &b.colonne);
  while (b.colonne <= 0 || b.colonne > MAXDIM);
  for (i = 0; i < b.righe; i++)
    for (j = 0; j < b.colonne; j++)
      scanf("%f", &b.dati[i][j]);

  if (a.colonne == b.righe) {
    p.righe = a.righe;
    p.colonne = b.colonne;

    for (i = 0; i < p.righe; i++)
      for (j = 0; j < p.colonne; j++)
        for (k = 0, p.dati[i][j] = 0; k < a.colonne; k++)
          p.dati[i][j] += a.dati[i][k]*b.dati[k][j];

    for (i = 0; i < p.righe; i++) {
      for (j = 0; j < p.colonne; j++)
        printf("%f ", p.dati[i][j]);

      printf("\n");
    }
  } else
    printf("Errore.\n");

  return 0;
}