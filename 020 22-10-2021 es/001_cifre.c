#include <stdio.h>

#define MAXS 30
#define TEMPMIN MAXS+2

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
  char str[MAXS+1];
  int i, count, max, min, counting;

  scanf("%s", str);

  max = 0;
  min = TEMPMIN;
  count = 0;
  counting = 0;

  /* ! Quando non abbiamo bisogno di riutilizzare la lunghezza della stringa, non serve calcolarla prima. */
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      counting = 1;
      count++;
    } else if (counting) {
      counting = 0;

      if (max < count)
        max = count;
      if (min > count)
        min = count;

      count = 0;
    }
  }

  if (counting) {
    if (max < count)
      max = count;
    if (min > count)
      min = count;
  }

  if (min == TEMPMIN)
    min = 0;

  printf("%d %d\n", max, min);

  return 0;
}