#include <stdio.h>

/*
  Scrivere un programma che acquisisce due numeri interi positivi a e
  b (se i numeri non sono validi li richiede), calcola MCD ed mcm, e
  li visualizza.
*/

int main() {
  int a, b, mcd, mcm;

  do
    scanf("%d", &a);
  while (a <= 0);
  do
    scanf("%d", &b);
  while (b <= 0);

  if (a < b) {
    mcd = a;
    mcm = b;
  } else {
    mcd = b;
    mcm = a;
  }
  while (a % mcd || b % mcd) {
    if (a % mcd || b % mcd)
      mcd--;
  }

  while (mcm % a || mcm % b)
    mcm++;

  printf("MCD: %d\tmcm: %d\n", mcd, mcm);

  return 0;
}
