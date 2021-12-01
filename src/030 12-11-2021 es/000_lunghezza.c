#include <stdio.h>
#define MAXS 30

/*
  Scrivere un sottoprogramma ricorsivo che riceve come parametro una
  stringa e ne calcola e restituisce la lunghezza.
  Scrivere un programma che chiede all'utente una stringa di al
  massimo 30 caratteri, invoca il sottoprogramma definito e visualizza
  il risultato.
*/

int length(char *);

int main() {
  char str[MAXS + 1];
  int len;

  scanf("%s", str);
  len = length(str);
  printf("%d\n", len);

  return 0;
}

int length(char *str) {
  if (*str == '\0')
    return 0;
  else
    return 1 + length(str + 1);
}
