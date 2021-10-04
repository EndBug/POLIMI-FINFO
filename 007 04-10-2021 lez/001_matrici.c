#include <stdio.h>
#define NR 2
#define NC 3

int int main() {
  float m[NR][NC];

  /*
    In memoria la matrice viene linearizzata mettendo in fila tutte le righe.
    Se si vuole calcolare lo scostamento: [i][j] = i*NC + j
    Se si sbaglia ad inserire gli indici si rischia di sporcare la memoria del 
    processo oppure di farlo crashare.
  */

  return 0;
}