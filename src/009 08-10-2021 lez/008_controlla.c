#include <stdio.h>
#define MAXS 30

/*
  Scrivere un programma che acquisisce una stringa s di al massimo 30
  caratteri e verifica se è composta soltanto da lettere dell'alfabeto
  minuscolo e da spazi.
*/

int main() {
  char s[MAXS + 1];
  int i, ok;

  scanf("%[^\n]", s);

  for (i = 0, ok = 1; s[i] != '\0' && ok; i++) {
    if ((s[i] < 'a' || s[i] > 'z') && s[i] != ' ')
      ok = 0;
  }

  printf("OK: %d\n", ok);

  return 0;
}
