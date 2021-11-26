#include <stdio.h>
#define SS 60
#define GG 360

/*
  Scrivere un programma che chieda all'utente di inserire da tastiera
  due angoli in formato gradi, primi e secondi (valori interi positivi
  o nulli - si assuma che l'utente non inserisca valori negativi). Il
  programma deve normalizzare gli angoli inseriti, farne la somma e
  stampare a video i due angoli inseriti (in formato normale) e la
  loro somma, anch'essa normalizzata.
*/

int main() {
  int a0, a1, a2, b0, b1, b2, s0, s1, s2;

  scanf("%d %d %d %d %d %d", &a0, &a1, &a2, &b0, &b1, &b2);

  a1 += a2 / SS;
  a2 %= SS;
  a0 += a1 / SS;
  a1 %= SS;
  a0 %= GG;

  b1 += b2 / SS;
  b2 %= SS;
  b0 += b1 / SS;
  b1 %= SS;
  b0 %= GG;

  s0 = a0 + b0;
  s1 = a1 + b1;
  s2 = a2 + b2;

  s1 += s2 / SS;
  s2 %= SS;
  s0 += s1 / SS;
  s1 %= SS;
  s0 %= GG;

  printf("%d° %d' %d''\n", a0, a1, a2);
  printf("%d° %d' %d''\n", b0, b1, b2);
  printf("%d° %d' %d''\n", s0, s1, s2);

  return 0;
}
