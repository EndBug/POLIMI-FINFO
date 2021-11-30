#include <stdio.h>

/*
  Scrivere un sottoprogramma che riceve in ingresso due numeri interi
  e restituisce (mediante parametri passati per indirizzo) sia il
  massimo che il minimo tra i due.
  Scrivere un programma che chiede all'utente due numeri e mediante
  l'utilizzo del sottoprogramma sopra definito, visualizza il minimo
  ed il massimo.
*/

void minmax(int, int, int *, int *);

int main() {
  int a, b, min, max;

  scanf("%d %d", &a, &b);

  minmax(a, b, &min, &max);

  printf("%d %d\n", min, max);

  return 0;
}

void minmax(int a, int b, int *min, int *max) {
  if (a > b) {
    *max = a;
    *min = b;
  } else {
    *max = b;
    *min = a;
  }
}
