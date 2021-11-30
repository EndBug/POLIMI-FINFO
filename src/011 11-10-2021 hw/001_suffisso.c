#include <stdio.h>
#include <string.h>
#define MAX 30

/*
  Scrivere un programma in C che acquisisce una stringa di al massimo
  30 caratteri ed un numero n. Il programma estrae il suffisso della
  stringa di lunghezza n salvandolo in un nuovo array e visualizza il
  risultato. Se n è maggiore della lunghezza della stringa, il
  suffisso sarà rappresentato dalla stringa stessa.
*/

int main() {
  char str[MAX + 1], res[MAX + 1];
  int n, len, i;

  scanf("%s %d", str, &n);

  len = strlen(str);
  if (len < n)
    n = len;

  for (i = 0; i < n; i++)
    res[i] = str[len - n + i];

  res[i] = '\0';

  printf("%s\n", res);

  return 0;
}
