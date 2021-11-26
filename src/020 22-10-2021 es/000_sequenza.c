#include <stdio.h>
#include <string.h>
#define MAXS 30

/*
  Scrivere un programma in C che chiede all'utente una stringa di al
  massimo 30 caratteri. Il programma individua la sequenza più lunga
  di caratteri consecutivi tutti uguali e ne visualizza la lunghezza
  ed il carattere che si ripete.
  Nel caso ci siano più di una sequenza a pari lunghezza massima, il
  programma visualizza i dati (dimensione e valore ripetuto)
  dell'ultima sequenza individuata.
*/

int main() {
  char str[MAXS+1], rip, maxRip;
  int count, i, len, maxCount;

  scanf("%s", str);

  len = strlen(str);
  count = 1;
  rip = str[0];
  maxCount = 0;
  for (i = 0; i < len; i++) {
    if (str[i] == str[i+1]) {
      count++;
      rip = str[i];
      if (count >= maxCount) {
        maxCount = count;
        maxRip = rip;
      }
    } else {
      count = 1;
    }
  }

  printf("%d %c\n", maxCount, maxRip);

  return 0;
}