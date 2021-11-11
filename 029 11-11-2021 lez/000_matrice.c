#include <stdio.h>
#define NC 5
#define NR 5

/*
  Esercizio 1:
  Realizzare un sottoprogramma che riceve come parametro una matrice
  bidimensionale di interi dichiarata nel chiamate con un numero di
  colonne pari a 5, e qualsiasi altro parametro ritenuto strettamente
  necessario. Il sottoprogramma visualizza il contenuto della matrice.
  Scrivere un programma che dichiara una matrice di interi 5x5, chiede
  all'utente quanti dati si vuole inserire nella matrice (numero di
  righe e colonne - che si assume vengano inseriti correttamente
  dall'utente) ed i dati per popolare la matrice; il programma invoca
  il sottoprogramma sopra definito.
*/

/*
  Esercizio 2:
  Realizzare un sottoprogramma che riceve come parametri il puntatore
  alla prima cella di una matrice bidimensionale di interi e qualsiasi
  altro parametro ritenuto strettamente necessario. Il sottoprogramma
  visualizza il contenuto della matrice.
  Scrivere un programma che dichiara una matrice di interi 5x5, chiede
  all'utente quanti dati si vuole inserire nella matrice (numero di
  righe e colonne - che si assume vengano inseriti correttamente
  dall'utente) ed i dati per popolare la matrice; il programma invoca
  il sottoprogramma sopra definito.
*/

void stampa1(int[][NC], int, int);
void stampa2(int*, int, int, int);

int main() {
  int m[NR][NC];
  int nr, nc, i, j;

  scanf("%d %d", &nr, &nc);
  for (i = 0; i < nr; i++)
    for (j = 0; j < nc; j++)
      scanf("%d", &m[i][j]);

  stampa1(m, nr, nc);
  stampa1(&m[0][0], NC, nr, nc);

  return 0;
}

void stampa1(int m[][NC], int nr, int nc) {
  int i, j;
  for (i = 0; i < nr; i++) {
    for (j = 0; j < nc; j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
}

void stampa2(int *p, int nc_dic, int nr_eff, int nc_eff) {
  int i, j;
  for (i = 0; i < nr_eff; i++) {
    for (j = 0; j < nc_eff; j++) {
      printf("%d ", *(p + i+nc_dic + j));
    }
    printf("\n");
  }
}