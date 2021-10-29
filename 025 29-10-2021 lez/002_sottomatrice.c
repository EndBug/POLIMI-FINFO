#include <stdio.h>
#define NR 10
#define NC 10

/*
  Scrivere un sottoprogramma che riceve come parametro una matrice di
  interi dichiarata nel chiamante con NC=10 colonne, e le dimensioni
  di tale matrice. Il sottoprogramma chiede all'utente i dati per
  popolare tale matrice.
  Scrivere un sottoprogramma che riceve come parametro una matrice di
  interi dichiarata nel chiamante con NC=10 colonne, e le dimensioni
  di tale matrice. Il sottoprogramma visualizza sullo schermo il
  contenuto della matrice.
  Scrivere un programma che dichiara una matrice 10x10 di interi. Il
  programma utilizza i due sottoprogrammi sopra definiti per acquisire
  i dati dell'intera matrice e la visualizza. In seguito il programma
  chiede all'utente le dimensioni di una sottomatrice della matrice
  sopra dichiarata (si assuma che l'utente inserisca i due valori
  correttamente). Il programma popola e visualizza la sottomatrice
  mediante i due sottoprogrammi sopra definiti.
*/

/*
  Dobbiamo dichiarare il numero di colonne, altrimenti il compilatore non sa
  come linealizzare la matrice per accedere alla memoria.
*/
void acquisisci(int[][NC], int, int);
void visualizza(int[][NC], int, int);

int main() {
  int m[NR][NC], sub_nr, sub_nc;

  /*
    int *p;
    p = m;
    (*p)[1] = 0 <=> m[0][1] = 0
    p++
    (*p)[1] = 0 <=> m[1][1] = 0
  */

  acquisisci(m, NR, NC);
  visualizza(m, NR, NC);

  scanf("%d %d", &sub_nr, &sub_nc);
  acquisisci(m, sub_nr, sub_nc);
  visualizza(m, sub_nr, sub_nc);

  return 0;
}

void acquisisci(int m[][NC], int nr, int nc) {
  int i, j;

  for (i = 0; i < nr; i++)
    for (j = 0; j < nc; j++)
      scanf("%d", &m[i][j]);
}

void visualizza(int m[][NC], int nr, int nc) {
  int i, j;

  for (i = 0; i < nr; i++){
    for (j = 0; j < nc; j++)
      printf("%2d ", m[i][j]);
    printf("\n");
  }  
}