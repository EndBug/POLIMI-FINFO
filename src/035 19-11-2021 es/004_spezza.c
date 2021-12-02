#include <stdio.h>
#include <stdlib.h>
#define MAXS 50

/*
  Scrivere un sottoprogramma che riceve in ingresso una stringa e due
  doppi puntatori a char. Il sottoprogramma divide la stringa in
  esattamente due parti di lunghezza uguale (se il numero di caratteri
  è dispari lascia il carattere in eccesso nella seconda sottostringa)
  e le salva in due array allocati dinamicamente da restituire al
  chiamante tramite i due parametri doppio puntatore a char. I due
  array vanno allocati esattamente delle dimensioni strettamente
  necessarie per contenere i dati. Infine nel caso di errore di
  allocazione della memoria il sottoprogramma dovrà restituire due
  NULL (deallocando l'eventuale memoria allocata correttamente).
  Scrivere un programma che chiede all'utente una stringa di al
  massimo 50 caratteri, invoca il sottoprogramma sopra definito
  passandogli la stringa acquisita e visualizza il risultato. Il
  sottoprogramma dealloca la memoria prima di terminare.
*/

void spezza(char *str, char **ss1, char **ss2);

int main() {
  char str[MAXS + 1], *s1, *s2;

  scanf("%[^\n]", str);

  spezza(str, &s1, &s2);

  if (s1 && s2) {
    printf("%s\n%s\n", s1, s2);
    free(s1);
    free(s2);
  }

  return 0;
}

void spezza(char *str, char **ss1, char **ss2) {
  int len, i;

  for (len = 0; *(str + len) != '\0'; len++)
    ;

  *ss1 = malloc((len / 2 + 1) * sizeof(char));
  *ss2 = malloc(((len - len / 2) + 1) * sizeof(char));

  if (*ss1 && *ss2) {
    for (i = 0; i < len / 2; i++)
      *(*ss1 + i) = *(str + i);
    *(*ss1 + i) = '\0';

    for (i = 0; i < len - len / 2; i++)
      *(*ss2 + i) = *(str + len / 2 + i);
    *(*ss2 + i) = '\0';
  } else if (*ss1)
    free(*ss1);
  else if (*ss2)
    free(*ss2);
}
