#include <stdio.h>
#define BASE2 2
#define BASE10 10

/*
  Modifica di 003_stampacifre per gestire la base 2 ?
*/

int main() {
  int n, cifra, ris, pot10;

  scanf("%d", &n);

  ris = 0;
  pot10 = 1;

  while (n > 0) {
    cifra = n % BASE2;
    n = n / BASE2;
    ris = ris + cifra * pot10;
    pot10 = pot10 * BASE10;
  }
  printf("%d\n", ris);

  return 0;
}