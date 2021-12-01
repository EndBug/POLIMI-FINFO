#include <stdio.h>
#define MAXS 30

/*
  Scrivere un sottoprogramma ricorsivo che riceve come parametri due
  stringhe e verifica se sono uguali o meno. In caso affermativo il
  sottoprogramma restituisce 1 altrimenti 0.
  Scrivere un programma che chiede all'utente due stringhe di al
  massimo 30 caratteri, invoca il sottoprogramma definito e visualizza
  il risultato.
*/

int streq(char *, char *);

int main() {
  char a[MAXS + 1], b[MAXS + 1];
  int eq;

  scanf("%s %s", a, b);
  eq = streq(a, b);
  printf("%d\n", eq);

  return 0;
}

int streq(char *a, char *b) {
  if (*a == '\0')
    return *a == *b;
  else
    return *a == *b && streq(a + 1, b + 1);
}
