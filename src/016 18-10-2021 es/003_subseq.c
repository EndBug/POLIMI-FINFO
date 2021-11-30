#include <stdio.h>
#define MAXS 30

/*
  Scrivere un programma che chiede all'utente una stringa di al
  massimo 30 caratteri. Il programma identifica nella stringa tutte le
  sotto-sequenze di sole cifre in posizioni consecutive, e visualizza
  le lunghezze della sotto-sequenza più lunga e di quella più corta.
  Se per esempio la stringa di ingresso è "a1245b645c7de45", il
  programma visualizza i valori 4 e 1 (avendo individuato le sottosequenze
  "1245" e "7"). Nel caso la stringa non contenga alcuna
  cifra, il programma visualizza il messaggio "0 0".
*/

int main() {
  char str[MAXS + 1];
  int max, min, count, i;

  scanf("%s", str);

  max = min = count = 0;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      count++;
    } else if (count) {
      if (max) {
        if (count > max)
          max = count;
        if (count < min)
          min = count;
      } else {
        max = count;
        min = count;
      }
      count = 0;
    }
  }
  if (count) {
    if (max) {
      if (count > max)
        max = count;
      if (count < min)
        min = count;
    } else {
      max = count;
      min = count;
    }
  }

  printf("%d %d", max, min);

  return 0;
}
