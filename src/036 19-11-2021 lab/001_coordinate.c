#include <stdio.h>
#include <math.h>
#define N 3

/*
  ES2 - Un punto nel piano cartesiano è definito dalla coppia di
  coordinate intere x e y: si definisca l'opportuno tipo di dato
  point_t.
  Data una matrice quadrata NxN di punti, i punti della diagonale,
  quelli di ogni riga e quelli di ogni colonna definiscono linee
  spezzate (ciascuna di N-1 lati). Si definisce regolare una matrice
  dove la lunghezza della spezzata definita dalla diagonale è maggiore
  della lunghezza di tutte le spezzate definite dalle righe e dalle
  colonne della matrice.
  Scrivere un sottoprogramma regolare() che ricevuta in ingresso una
  matrice quadrata di punti e qualsiasi parametro ritenuto
  strettamente necessario, restituisce 1 se la matrice è regolare, 0
  altrimenti.
  Si supponga che esista una direttiva
  # define N ...
  che indica la dimensione utilizzata nella dichiarazione della
  matrice quadrata passata al sottoprogramma.
  Infine si suggerisce di realizzare un apposito sottoprogramma di
  ausilio
  float dist(point_t p1, point_t p2)
  che calcola e restituisce la distanza euclidea tra due punti.
  Scrivere un programma che chiede i dati di una matrice NxN di punti
  (con N=3), invoca il programma sopra definito e visualizza il
  risultato.
*/

typedef struct {
  int x, y;
} point_t;

float dist(point_t p1, point_t p2);
int regolare(point_t m[][N], int dim);

int main() {
  int i, j, reg;
  point_t m[N][N];

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("[%d][%d]: ", i, j);
      scanf("%d %d", &m[i][j].x, &m[i][j].y);
    }
  }

  reg = regolare(m, N);

  if (reg)
    printf("Regolare.\n");
  else
    printf("Non regolare.\n");

  return 0;
}

float dist(point_t p1, point_t p2) {
  return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

int regolare(point_t m[][N], int dim) {
  float l_diag, l_tmp1, l_tmp2;
  int i, j, reg;

  l_diag = 0;
  for (i = 0; i < dim-1; i++)
    l_diag += dist(m[i][i], m[i+1][i+1]);

  reg = 1;
  for (i = 0; i < dim && reg; i++) {
    l_tmp1 = 0;
    l_tmp2 = 0;

    for (j = 0; j < dim-1; j++) {
      l_tmp1 += dist(m[i][j], m[i][j+1]);
      l_tmp2 += dist(m[j][i], m[j+1][i]);
    }

    if (l_diag <= l_tmp1 || l_diag <= l_tmp2)
      reg = 0;
  }

  return reg;
}