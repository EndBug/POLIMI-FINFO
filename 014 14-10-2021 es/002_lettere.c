#include <stdio.h>
#include <string.h>
#define MAXS 15

/*
  Scrivere un programma in C che chiede all'utente una stringa di al
  massimo 15 caratteri contenente soltanto lettere dell'alfabeto
  minuscolo (si assuma che l'utente non commetta errori
  nell'inserimento).
  Il programma identifica e visualizza qual è la prima lettera
  nell'ordinamento alfabetico che compare nella stringa e quante volte
  vi compare.
  Esempio
  Se l'utente inserisce "cocci" il programma stampa "c 3"
  Se l'utente inserisce "bacco" il programma stampa "a 1"
  Se l'utente inserisce "tiene" il programma stampa "e 2"
*/

int main() {
  int count, i, len;
  char first, str[MAXS+1];

  scanf("%s", str);
  len = strlen(str);

  for (i = 0, count = 0, first = 'z'; i < len; i++) {
    if (str[i] < first) {
      first = str[i];
      count = 1;
    } else if (str[i] == first)
      count++;
  }

  printf("%c %d\n", first, count);

  return 0;
}