#include <stdio.h>
#define BASE 10

/*
  Scrivere una funzione ricorsiva che riceve come parametro un numero
  intero positivo o nullo e ne visualizza le cifre al contrario (da
  destra verso sinistra). Per esempio se la funzione riceve il numero
  123456 visualizzerà il messaggio 654321. Scrivere un programma che
  chiede all'utente un intero ed invoca la funzione sopra definita.
*/

void invertiNumero(int);

int main() {
  int n;

  scanf("%d", &n);
  invertiNumero(n);

  return 0;
}

void invertiNumero(int n) {
  if (n != 0) {
    printf("%d", n % BASE);
    invertiNumero(n / BASE);
  } else
    printf("\n");
}
