#include <stdio.h>
#include <string.h>
#define MAXS 15
#define MINSTR 4

/*
  ES1. Scrivere un programma C che apre un file di testo il cui nome è passato
  come argomento da riga di comando e contenente parole ciascuna di al massimo
  15 caratteri, separate da spazi. Il programma trova tutte le parole più lunghe
  di 4 caratteri e ripetute due volte di seguito nel testo e le stampa a video.
  Gestire opportunamente tutti gli eventuali errori. Ad esempio, se il file
  "testo.txt" contiene il testo: bisogna studiare passo passo e adagio adagio
  per ottenere un voto alto alto Il programma visualizzerà in output:

  passo adagio

  Come test, forniamo i file testo1.txt, testo2.txt, testo3.txt, i cui output
  corrispondenti sono qui elencati:

  testo1.txt -> passo adagio
  testo2.txt -> quando occupato
  testo3.txt -> quattro cinque sette
*/

int main(int argc, char *argv[]) {
  FILE *fp;
  char prev[MAXS], curr[MAXS];

  if (argc == 2) {
    fp = fopen(argv[1], "r");

    if (fp) {
      fscanf(fp, "%s %s", prev, curr);

      while (!feof(fp)) {
        if (!strcmp(prev, curr) && strlen(curr) > MINSTR)
          printf("%s ", curr);

        strcpy(prev, curr);
        fscanf(fp, "%s", curr);
      }
      printf("\n");

      fclose(fp);
    } else
      printf("Errore file.\n");
  } else
    printf("Errore argomenti.\n");

  return 0;
}
