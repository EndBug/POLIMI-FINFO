#include <stdio.h>

/*
  ES4. Scrivere un programma che riceve in ingresso un numero positivo
  pari n;
  il programma continuerà a richiedere il numero n finché la
  condizione
  non sarà soddisfatta. In seguito, il programma disegna a video un
  triangolo con
  base n utilizzando il carattere * come mostrato nel seguente
  esempio.
  Esempio: Sia n=10, il disegno da mostrare è
      **
     ****
    ******
   ********
  **********
*/

int main() {
  int n, i, j;

  do
    scanf("%d", &n);
  while (n <= 0 || n % 2);

  for (i = (n - 2) / 2; i >= 0; i--) {
    for (j = 0; j < i; j++)
      printf(" ");
    for (j = 0; j < n - (2 * i); j++)
      printf("*");
    for (j = 0; j < i; j++)
      printf(" ");
    printf("\n");
  }

  return 0;
}
