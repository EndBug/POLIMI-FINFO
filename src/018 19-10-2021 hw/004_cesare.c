#include <stdio.h>
#include <string.h>
#define OFFSET 3
#define MAXS 20

/*
  Il cifrario di Cesare è uno dei più antichi algoritmi crittografici
  di cui si abbia traccia storica. È un cifrario a sostituzione
  monoalfabetica in cui ogni lettera del testo in chiaro è sostituita
  nel testo cifrato dalla lettera che si trova un certo numero di
  posizioni dopo nell'alfabeto. Cesare utilizzava uno spostamento di 3
  posizioni:
  Cifratura: A->D, B->E, ..., X->A, Y->B, Z->C
  Decifratura: D->A, E->B, ...,
  Scrivere un sottoprogramma cifra() che riceve come parametro un
  carattere minuscolo dell'alfabeto inglese e restituisce il carattere
  minuscolo cifrato.
  Scrivere un sottoprogramma decifra() che riceve come parametro un
  carattere minuscolo dell'alfabeto inglese già cifrato e restituisce
  il corrispondente carattere minuscolo non cifrato.
  Scrivere un sottoprogramma verificalettera() che riceve come
  parametro un carattere e restituisce 1 se tale carattere è una
  lettera dell'alfabeto minuscolo, altrimenti 0.
  Scrivere un programma che acquisisce una stringa di testo di al
  massimo 20 caratteri, che si assume contenga soltanto lettere
  minuscole dell'alfabeto, cifre ed altri segni di interpunzione e non
  lettere maiuscole. Mediante l'ausilio dei sottoprogrammi sopra
  definiti, il programma cifra il messaggio salvandolo in un secondo
  array e lo stampa a video; in seguito, il programma decifra il
  messaggio cifrato, lo stampa a video e verifica che effettivamente è
  uguale al messaggio originale, visualizzando l'esito del confronto.
  NOTA: nella cifratura/decifratura vanno cifrate/decifrate soltanto
  le lettere dell'alfabeto mentre il resto dei caratteri rimangono
  immutati.
*/

char cifra(char c);
char decifra(char c);
int verificaLettera(char c);

int main() {
  char s1[MAXS + 1], s2[MAXS + 1];
  int i;

  scanf("%[^\n]", s1);

  for (i = 0; s1[i] != '\0'; i++) {
    if (verificaLettera(s1[i]))
      s2[i] = cifra(s1[i]);
    else
      s2[i] = s1[i];
  }
  s2[i] = '\0';
  printf("%s\n", s2);

  for (i = 0; s2[i] != '\0'; i++) {
    if (verificaLettera(s2[i]))
      s2[i] = decifra(s2[i]);
  }
  printf("%s\n", s2);

  printf("Uguali: %d\n", !strcmp(s1, s2));

  return 0;
}

char cifra(char c) {
  c += OFFSET;

  /* Considero entrambi i casi, in modo da consentire anche OFFSET < 0 */
  if (c > 'z')
    c -= 'z' - 'a';
  else if (c < 'a')
    c += 'a' - 'z';
  return c;
}

char decifra(char c) {
  c -= OFFSET;

  if (c > 'z')
    c -= 'z' - 'a';
  else if (c < 'a')
    c += 'a' - 'z';

  return c;
}

int verificaLettera(char c) { return (c >= 'a' && c <= 'z'); }
