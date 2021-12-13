#include <stdio.h>
#include <string.h>
#define MAXS 100

/*
  Scrivere un programma per il calcolo di statistiche sui caratteri presenti in
  un file di testo il cui nome è specificato come argomento da riga di comando.
  Il programma considera tutti i caratteri ad eccezione degli spazi e fornisce
  in uscita le seguenti statistiche:
  - il numero di righe presenti nel file (ogni riga è al più di 100 caratteri)
  - il numero totale di caratteri (esclusi quelli di spaziatura)
  - il numero massimo e medio di caratteri di riga
  - la riga più lunga presente nel file

  Dato il file con il seguente testo:

  Prova di contenuto di file
  per avere un esempio.
  Non e' importante quello che c'e' scritto
  presente.

  il programma visualizza:
  4
  84
  35 21
  Non e' importante quello che c'e' scritto
*/

int main(int argc, char *argv[]) {
  FILE *fp;
  char curr, maxLine[MAXS + 1], currLine[MAXS + 1];
  int nLines, nChars, maxLen, maxLenWithoutSpaces, avgLen, currLen,
      currLenWithoutSpaces;

  if (argc == 2) {
    fp = fopen(argv[1], "r");

    if (fp) {
      nChars = 0;
      currLen = 0;
      currLenWithoutSpaces = 0;
      nLines = 0;
      maxLen = -1;
      avgLen = 0;
      fscanf(fp, "%c", &curr);
      /* Volendo si può anche fare la scansione riga per riga, con fgets */

      while (!feof(fp)) {
        if (curr == '\n') {
          nLines++;
          currLine[currLen] = '\0';

          avgLen += currLenWithoutSpaces;

          if (currLen > maxLen) {
            strcpy(maxLine, currLine);
            maxLen = currLen;
            maxLenWithoutSpaces = currLenWithoutSpaces;
          }

          currLen = 0;
          currLenWithoutSpaces = 0;
        } else {
          if (curr != ' ') {
            nChars++;
            currLenWithoutSpaces++;
          }
          currLine[currLen] = curr;
          currLen++;
        }

        fscanf(fp, "%c", &curr);
      }

      avgLen /= nLines;

      printf("%d\n%d\n%d %d\n%s\n", nLines, nChars, maxLenWithoutSpaces, avgLen,
             maxLine);

      fclose(fp);
    } else
      printf("Errore file.\n");
  } else
    printf("Errore argomenti.\n");

  return 0;
}
