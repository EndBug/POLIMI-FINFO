#include <stdio.h>
#define MAXS 30

/*
  Scrivere un programma che chiede all'utente il nome di due file di
  testo (due stringhe di al massimo 30 caratteri ciascuna). Il
  programma apre i due file e verifica se il loro contenuto è
  identico; in caso affermativo il programma stampa a video 1
  altrimenti 0. Segnalare a video eventuali casi di errore.
*/

int main() {
  char fn1[MAXS+1], fn2[MAXS+1];
  FILE *fp1, *fp2;
  char c1, c2;
  int uguali;

  scanf("%s %s", fn1, fn2);

  /* Utilizziamo la modalità binaria perché funziona anche per file non di testo. */
  fp1 = fopen(fn1, "rb");

  if (fp1) {
    /* Qua è importante utilizzare la stessa modalità usata prima. */
    fp2 = fopen(fn2, "rb");

    if (fp2) {
      /* 
        Dato che stiamo andando byte a byte, possiamo anche utilizzare questa 
        fscanf al posto di fread.
      */
      fscanf(fp1, "%c", &c1);
      fscanf(fp2, "%c", &c2);

      uguali = 1;
      while (!feof(fp1) && !feof(fp2) && uguali) {
        if (c1 != c2)
          uguali = 0;
        else {
          fscanf(fp1, "%c", &c1);
          fscanf(fp2, "%c", &c2);
        }
      }

      printf("%d\n", uguali && feof(fp1) == feof(fp2));

      fclose(fp2);
    } else {
      printf("Errore apertura secondo file.\n");
    }

    fclose(fp1);
  } else {
    printf("Errore apertura primo file.\n");
  }

  return 0;
}