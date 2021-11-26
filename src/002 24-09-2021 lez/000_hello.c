#include <stdio.h>

/*
  Da es. 24-09-2021
  Scrivere un programma che acquisisce un carattere da tastiera
  (diverso da un a capo) e lo visualizza. In seguito il programma
  chiede un altro carattere (diverso da un a capo) e lo visualizza.
*/

int main() {
  char c;
  scanf("%c", &c);
  printf("-> %c <-\n", c);

  /*
    Teoricamente i commenti con // non sono ammessi in C89
    La seconda volta bisogna scartare il primo valore, perché il secondo è un
    invio.
  */
  scanf(" %c", &c);
  printf("-> %c <-\n", c);

  return 0;
}
