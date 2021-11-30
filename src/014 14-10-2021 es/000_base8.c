#include <stdio.h>
#include <string.h>
#define BASE 8
#define MAXS 10
#define ERRORE -1

/*
  Scrivere un programma in C che chiede all'utente una stringa di al
  massimo 10 caratteri che rappresenta un numero intero positivo in
  base 8 (cioè composta soltanto dai caratteri dallo '0' al '7'). Il
  programma calcola e visualizza il valore intero rappresentante lo
  stesso numero in base 10. Nel caso la stringa contenga un carattere
  non valido, il programma visualizza il valore -1.
  Esempio 1: Se l'utente inserisce la stringa "24", il programma
  visualizza il valore intero 20 (infatti 2 x 81 + 4 x 80 = 20).
  Esempio 2: Se l'utente inserisce la stringa "95", il programma
  visualizza il valore intero -1 (infatti '9' non è un carattere tra
  '0' e '7'). Stessa cosa se il programma legge la stringa "h5".
*/

int main() {
  char str[MAXS + 1];
  int res, i, len, potBase;

  scanf("%s", str);

  len = strlen(str);

  for (i = 0, potBase = 1, res = 0; i < len && res != ERRORE;
       i++, potBase *= BASE) {
    if (str[i] >= '0' && str[i] < BASE + '0')
      res += potBase * (str[len - 1 - i] - '0');
    else
      res = ERRORE;
  }

  printf("%d\n", res);

  return 0;
}
