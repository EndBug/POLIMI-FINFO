#include <stdio.h>
#define MAXS 30

/*
  Scrivere un programma in C che acquisisce due stringhe di al più 30
  caratteri e le concatena in un terzo array e visualizza il
  risultato.
*/

int main() {
  char s1[MAXS + 1], s2[MAXS + 1], s3[2 * MAXS + 1];
  int i, n;

  scanf("%s %s", s1, s2);

  for (n = 0; s1[n] != '\0'; n++)
    s3[n] = s1[n];

  for (i = 0; s2[i] != '\0'; i++, n++)
    s3[n] = s2[i];

  s3[n] = '\0';

  printf("%s\n", s3);

  return 0;
}
