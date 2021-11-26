#include <stdio.h>

/*
  Scrivere un sottoprogramma che riceve come parametri due numeri
  interi e restituisce la loro media (un numero float).
  Scrivere un programma che chiede all'utente due coppie di interi e
  calcola e visualizza la media di ciascuna di esse.
*/

float media(int, int);

int main() {
  int a1, a2, b1, b2;
  float mA, mB;

  scanf("%d %d %d %d", &a1, &a2, &b1, &b2);

  mA = media(a1, a2);
  mB = media(b1, b2);

  printf("%f %f\n", mA, mB);

  return 0;
}

float media(int a, int b) {
  return (a+b)/2.0;
}