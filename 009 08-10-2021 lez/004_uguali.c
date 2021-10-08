#include <stdio.h>
#define MAXS 30

/*
  Scrivere un programma in C che acquisisce due stringhe di al più 30
  caratteri e verifica se sono uguali visualizzando un apposito
  messaggio con il responso (1: uguali, 0: diverse).
*/

int main() {
  char s1[MAXS+1], s2[MAXS+1];
  int i, uguali;

  scanf("%s %s", s1, s2);

  for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++);

  uguali = s1[i] == '\0' && s2[i] == '\0';

  printf("%d\n", uguali);

  return 0;
}