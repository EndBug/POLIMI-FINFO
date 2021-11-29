#include <stdio.h>
#define MAX 1024
#define BASE10 10
#define BASE2 2
#define NBIT 10

/*
  Scrivere un programma che chiede all'utente un numero intero
  positivo minore di 1024 e se il valore non è valido stampa un
  messaggio di errore e lo richiede. Il programma converte in binario
  naturale su 10 bit il valore acquisito mediante il metodo dei resti
  e visualizza il risultato.
*/

int main() {
  int n10, i;
  int n2[NBIT];

  scanf("%d", &n10);
  while (n10 <= 0 || n10 >= MAX) {
    printf("Valore non valido.\n");
    scanf("%d", &n10);
  }

  for (i = 0; i < NBIT; i++)
    n2[i] = 0;

  for (i = NBIT - 1; n10 > 0 && i >= 0; n10 /= BASE2, i--) {
    n2[i] = n10 % BASE2;
  }

  for (i = 0; i < NBIT; i++)
    printf("%d", n2[i]);
  printf("\n");

  return 0;
}
