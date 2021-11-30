#include <stdio.h>
#define MAXS 30

/*
  Scrivere un programma in C che acquisisce una stringa di al più 30
  caratteri, la copia al rovescio in un secondo array e visualizza il
  risultato.
*/

int main() {
  char s1[MAXS + 1], s2[MAXS + 1];
  int i, len;

  scanf("%s", s1);

  for (len = 0; s1[len] != '\0'; len++)
    ;

  for (i = 0; i < len; i++)
    s2[len - i - 1] = s1[i];

  /*
    Se non mettiamo \0 printf stamperà finché non trova un terminatore a caso
    all'interno della nostra memoria (non rispetta neanche MAXS, non sa quanto
    è lungo l'array).
  */
  s2[len] = '\0';

  printf("%s\n", s2);

  return 0;
}
