#include <stdio.h>
#define BASE2 2
#define BASE10 10

/*
  Scrivere un programma che chiede all'utente un numero intero
  positivo. Il programma converte il numero in binario naturale
  mediante il metodo dei resti mostrando il risultato dall'ultima
  cifra alla prima.
  VARIANTE: stampare il numero binario correttamente da sinistra verso
  destra.
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
