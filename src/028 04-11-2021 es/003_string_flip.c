#include <stdio.h>
#include <string.h>
#define MAXS 100

/*
  Scrivere un sottoprogramma che riceve come parametri due array di
  caratteri, il primo contenente una stringa ed il secondo vuoto.
  Assumendo che la stringa sia composta da una sequenza di parole
  separate da spazi, il sottoprogramma inverte di ordine le parole
  della stringa e salva il risultato nel secondo array.
  Esempio: Se il programma riceve come stringa "ciao come stai", il
  sottoprogramma restituisce "stai come ciao".
  Scrivere un programma che acquisisce una stringa di al massimo 100
  caratteri contenente anche spazi, invoca il sottoprogramma sopra
  definito e visualizza il risultato.
*/

void stringFlip(char in[], char out[]);

int main() {
  char str[MAXS+1], flipped[MAXS+1];

  scanf("%[^\n]", str);

  stringFlip(str, flipped);

  printf("%s\n", flipped);

  return 0;
}

void stringFlip(char in[], char out[]) {
  int i, j, len, lastSpace;

  len = strlen(in);
  lastSpace = -1;

  for (i = 0; i <= len; i++) {
    if (in[i] == ' ' || in[i] == '\0') {
      for (j = 0; j < i-lastSpace-1; j++) {
        out[len-i+j] = in[lastSpace+1+j];
      }

      if (in[i] == ' ') {
        out[len-i-1] = in[i]; /* ' ' */
        lastSpace = i;
      }
    }
  }

  out[len] = '\0';
}