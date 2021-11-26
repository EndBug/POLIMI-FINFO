#include <stdio.h>
#define MAXS 250

/*
  ES1 - Realizzare un sottoprogramma che riceve come parametro una
  stringa di testo composta da parole in caratteri minuscoli ciascuna
  di lunghezza indefinita e separate da singoli spazi. Il
  sottoprogramma modifica la stringa secondo la procedura qui sotto
  riportata e poi ne stampa all'utente la nuova versione.
  Procedura: ogni parola all'interno della stringa di testo viene
  invertita, l'ultima lettera diventa la prima e viceversa.
  Esempio
  Input: ciao come stai
  Output: oaic emoc iats
  Scrivere un programma che chiede all'utente una stringa di al
  massimo 250 caratteri, invoca su di essa il sottoprogramma sopra
  definito e stampa a video il risultato.
*/

void inverti(char *str);

int main() {
  char str[MAXS+1];

  scanf("%[^\n]", str);
  inverti(str);
  printf("%s\n", str);

  return 0;
}

void inverti(char *str) {
  char tmp;
  int start, end, i, stop;

  for (start = 0, end = 0, stop = 0; !stop; end++) {
    if (str[end] == ' ' || str[end] == '\0') {
      for (i = 0; (float)i < (end-start)/2.0; i++) {
        tmp = str[start+i];
        str[start+i] = str[end-1-i];
        str[end-1-i] = tmp;
      }
      start = end+1;
    }

    if (str[end] == '\0')
      stop = 1;
  }
}