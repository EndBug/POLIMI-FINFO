#include <stdio.h>

/*
  Scrivere un programma che acquisisce un carattere da tastiera
  (diverso da un a capo) e lo visualizza. In seguito il programma
  chiede un altro carattere (diverso da un a capo) e lo visualizza.
*/

int main() {
  char c;

  scanf("%c", &c);
  printf("%c\n", c);

  /* Usiamo lo spazio per scartare il primo valore (che sarebbe un \n) */
  scanf(" %c", &c);
  printf("%c\n", c);

  return 0;
}
