#include <stdio.h>
#include <string.h>
#define MAX 100

/*
  Scrivere un programma in C che chiede all'utente di inserire una
  stringa di massimo 100 caratteri. Il programma deve cercare tutte le
  sottostringhe palindrome contenute all'interno della stringa di
  lunghezza l che varia da 2 a n (dove n è la lunghezza della stringa
  stessa). Per ogni diversa lunghezza l, stampare le stringhe
  palindrome trovate ed il loro numero.
*/

int main() {
  char str[MAX + 1];
  int n, l, pal, i, j, pal_count;

  scanf("%s", str);

  n = strlen(str);
  for (l = 2; l < n; l++) {
    printf("l: %d -> ", l);

    for (i = 0, pal_count = 0; i <= n - l; i++) {
      for (j = 0, pal = 1; j < l / 2 && pal; j++) {
        if (str[i + j] != str[i + l - 1 - j])
          pal = 0;
      }

      if (pal) {
        for (j = i; j < i + l; j++)
          printf("%c", str[j]);

        printf(" ");
        pal_count++;
      }
    }

    printf("(%d)\n", pal_count);
  }

  return 0;
}
