#include <stdio.h>
#define MAXS 30

/*
  Scrivere un programma che apre un file di testo il cui nome di al
  massimo 30 caratteri va chiesto all'utente e che contiene una
  sequenza di lunghezza indefinita (0 o più) di numeri interi. Per
  ciascun numero letto, il programma stabilisce se è il doppio del
  suo precedente; in tal caso stampa a video la coppia di numeri.
  Esempio: se il contenuto del file è "1 2 5 2 4 8 5 4 5", il
  programma stampa a video:
  1 2
  2 4
  4 8
*/

int main() {
  char fn[MAXS+1];
  int curr, prev;
  FILE *fp;

  printf("Nome del file: ");
  scanf("%s", fn);

  fp = fopen(fn, "r");

  if (fp) {
    fscanf(fp, "%d", &prev);
    while (!feof(fp)) {
      fscanf(fp, "%d", &curr);
      if (curr == 2*prev)
        printf("%d %d\n", prev, curr);
      prev = curr;
    }
    fclose(fp);
  } else {
    printf("Errore\n");
  }

  return 0;
}