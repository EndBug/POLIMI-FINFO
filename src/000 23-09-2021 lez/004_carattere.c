#include <stdio.h>
#define PASSO 1

/*
  Scrivere un programma che chiede all'utente un carattere
  dell'alfabeto minuscolo (assumiamo che l'utente non inserisca un
  carattere non valido). Il programma calcola e visualizza il
  carattere successivo a quello inserito ('a' ->'b', 'b' -> 'c', ...,
  'z' -> 'a').
*/

int main() {
  char c_in, c_out;

  scanf("%c", &c_in);

  c_out = (c_in - 'a' + PASSO) % ('z' - 'a' + 1) + 'a';

  printf("%c\n", c_out);

  return 0;
}
