#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Scrivere un sottoprogramma rep che riceve in ingresso una stringa s e un
  intero n (senz'altro non negativo). Il sottoprogramma restituisce una nuova
  stringa ottenuta concatenando n copie di s. Ad esempio, se il sottoprogramma
  riceve in ingresso "esempio" e 3 restituisce la nuova "esempioesempioesempio",
  se riceve "esempio" e 0 restituisce una stringa vuota. Non è consentito l'uso
  dei sottoprogrammi di libreria quali strcat(), strcpy() e simili. Scrivere il
  programma che acquisisce da riga di comando la stringa s e l'intero n, invoca
  il sottoprogramma sopra definito e visualizza il risultato.
*/

char *rep(char *str, int n);

int main(int argc, char *argv[]) {
  char *res;

  if (argc == 3) {
    res = rep(argv[1], atoi(argv[2]));

    printf("%s\n", res);

    free(res);
  } else
    printf("Errore argomenti.\n");

  return 0;
}

char *rep(char *str, int n) {
  int i, l;
  char *res;

  res = malloc(sizeof(char) * (strlen(str) * n + 1));

  if (res) {
    l = 0;
    for (; n; n--) {
      for (i = 0; str[i] != '\0'; i++) {
        res[l] = str[i];
        l++;
      }
    }
    res[l] = '\0';
  } else
    printf("Errore allocazione.\n");

  return res;
}
