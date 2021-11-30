#include <stdio.h>
#include <string.h>
#define MAXS 50

/*
  ES2. Scrivere un programma in C che acquisisce una stringa s1 di
  massimo 50 caratteri e un numero intero n. Il programma controlla se
  n è maggiore di zero e minore della lunghezza della stringa. Se le
  condizioni non sono verificate, continua a richiedere il valore. In
  seguito il programma crea una nuova stringa s2 che contiene la
  rotazione verso destra di s1 di n posizioni e la visualizza.
  Esempio: s1="alfabeto" e n=2 -> s2="toalfabe".
*/

int main() {
  char s1[MAXS + 1], s2[MAXS + 1];
  int n, len, i;

  scanf("%s", s1);
  len = strlen(s1);

  do
    scanf("%d", &n);
  while (!(n > 0 && n < len));

  for (i = 0; i < len; i++)
    s2[(i + n) % len] = s1[i];
  s2[len] = '\0';

  printf("%s\n", s2);

  return 0;
}
