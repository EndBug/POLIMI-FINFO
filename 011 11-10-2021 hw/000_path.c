#include <stdio.h>
#include <string.h>
#define MAX 50
#define SEP '/'

/*
  Esercizio svolto da solo l'11-10-2021, trattato in es il 18-10-2021
  Scrivere un programma in C che chiede all'utente una stringa di
  massimo 50 caratteri che rappresenta il percorso completo di un
  file. Il programma salva in una nuova stringa il solo nome del file
  specificato nel percorso e lo visualizza.
  Esempio: dal path "/home/antonio/ciao.c" il programma stampa a video
  "ciao.c"
*/

int main() {
  char path[MAX+1], file[MAX+1];
  int i, len, last;

  /* scanf("%s", path); */
  /* Utilizziamo questo RegEx perché così possiamo avere anche anche spazi etc... */
  scanf("% [^\n]", path);

  len = strlen(path);

  /* Assumo che la stringa contenga almeno uno /, dato che è una path assoluta */
  for (i = 0; i < len; i++)
    if (path[i] == SEP) last = i;

  for (i = 0; i < len-(last+1); i++)
    file[i] = path[i+last+1];
  file[i] = '\0';

  printf("%s\n", file);

  return 0;
}