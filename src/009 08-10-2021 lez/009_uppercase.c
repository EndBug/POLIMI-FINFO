#include <stdio.h>
#define MAXS 30

/*
  Scrivere un programma che acquisisce una stringa s1 di al massimo 30
  caratteri dell'alfabeto minuscolo e segni di interpunzione o spazi
  (si assuma che l'utente non commetta alcun errore di inserimento) e
  costruisce una nuova stringa s2 che contiene la stesso testo
  convertendo i caratteri dell'alfabeto minuscolo in maiuscolo.
  Esempio: s1="ciao amico." -> s2="CIAO AMICO.".
*/

int main() {
  char s1[MAXS + 1], s2[MAXS + 1];
  int i;

  scanf("%[^\n]", s1);

  for (i = 0; s1[i] != '\0'; i++) {
    if (s1[i] >= 'a' && s1[i] <= 'z')
      s2[i] = s1[i] - 'a' + 'A';
    else
      s2[i] = s1[i];
  }
  s2[i] = '\0';

  printf("%s\n", s2);

  return 0;
}
