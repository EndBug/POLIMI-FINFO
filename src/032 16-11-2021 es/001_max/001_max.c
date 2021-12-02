#include <stdio.h>
#define FN "TEST.txt"

/*
  Scrivere un programma che apre un file di testo il cui nome è
  TEST.txt contenente un sequenza di lunghezza indefinita (0 o più) di
  numeri interi. Il programma calcola e stampa a video il valore
  massimo e quante volte tale valore si è presentato nel file.
*/

int main() {
  FILE *fp;
  int max, tmp, count;

  fp = fopen(FN, "r");

  if (fp) {
    fscanf(fp, "%d", &max);
    count = 1;

    while (!feof(fp)) {
      fscanf(fp, "%d", &tmp);
      if (tmp > max) {
        max = tmp;
        count = 1;
      } else if (tmp == max)
        count++;
    }

    printf("max: %d, count: %d\n", max, count);

    fclose(fp);
  } else
    printf("Errore\n");

  return 0;
}
