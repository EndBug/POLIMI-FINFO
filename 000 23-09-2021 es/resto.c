#include <stdio.h>
#define TAGLIO 5
#define MONETA2 2

int main() {
  int resto, n_banconote, n_monete2, n_monete1;

  scanf("%d", &resto);

  n_banconote = resto / TAGLIO;
  n_monete2 = resto / MONETA2;
  n_monete1 = resto % MONETA2

  printf("%d %d %d\n", n_banconote, TAGLIO, n_monete2, n_monete1);
  
  return 0;
}