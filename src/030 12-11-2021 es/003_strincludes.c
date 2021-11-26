#include <stdio.h>
#define MAXS 30

/*
  Scrivere un sottoprogramma ricorsivo che riceve come parametri due
  stringhe a e b; il sottoprogramma verifica se in b sono presenti
  tutti i caratteri presenti in a, nello stesso ordine, più
  eventualmente qualche altro carattere. In caso affermativo il
  sottoprogramma restituisce 1 altrimenti 0.
  Esempio:
  Per a="acca" b="baracca" il sottoprogramma restituisce 1.
  Per a="acca" b="racchetta" il sottoprogramma restituisce 1.
  Per a="acca" b="amaca" il sottoprogramma restituisce 0.
  Scrivere un programma che chiede all'utente due stringhe di al più
  50 caratteri, invoca il sottoprogramma definito e visualizza il
  risultato.
  VARIANTE: Scrivere la versione iterativa del sottoprogramma appena
  realizzato.
*/

int strIncludesRec(char*, char*);
int strIncludesIt(char*, char*);

int main() {
  char a[MAXS+1], b[MAXS+1];
  int resRec, resIt;

  scanf("%s %s", a, b);
  resRec = strIncludesRec(a, b);
  resIt = strIncludesIt(a, b);
  printf("Rec: %d  It: %d\n", resRec, resIt);

  return 0;
}

int strIncludesRec(char *a, char *b) {
  if (*a == '\0')
    return 1;
  if (*b == '\0')
    return 0;

  if (*a == *b)
    return strIncludesRec(a+1, b+1);
  else
    return strIncludesRec(a, b+1);
}

int strIncludesIt(char *a, char *b) {
  int i, j;

  for (i = 0, j = 0; b[i] != '\0' && a[j] != '\0'; i++) {
    if (b[i] == a[j])
      j++;
  }

  return a[j] == '\0';
}