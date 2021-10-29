#include <stdio.h>
#include <string.h>
#define MAXS 30
#define DIM 10

/*
  ES3 - Definire un tipo di dato parola_t che rappresenta una parola nella lingua 
  italiana e la sua traduzione inglese (due stringhe ciascuna di al massimo 30 
  caratteri). Scrivere un programma che chiede all'utente 10 parole italiane e 
  la loro traduzione in inglese. Il programma esegue le seguenti elaborazioni: 
  * Il programma cerca e stampa a video quei termini italiani che sono presenti 
    anche nella lingua inglese (anche se con un altro significato).
  * Il programma cerca e stampa a video quei termini italiani che hanno più 
    traduzioni in inglese.

  Come esempio si consideri la seguente lista di parole:
    scope brooms
    scopo scope
    case houses
    scatola case
    goal goal
    ciao hello
    ciao hi
    ballo ball
    palla ball
    ciao bye
  Per il primo punto il programma stamperà a video:
    scope brooms * scopo scope
    case houses * scatola case
  Per il secondo punto il programma stamperà a video:
    ciao hello
    ciao hi
    ciao bye
*/

typedef struct {
  char it[MAXS], en[MAXS];
} parola_t;

int main() {
  parola_t diz[DIM];
  int i, j, stampata;

  for (i = 0; i < DIM; i++)
    scanf("%s %s", diz[i].it, diz[i].en);

  printf("Falsi amici:\n");
  for (i = 0; i < DIM; i++) {
    for (j = 0; j < DIM && strcmp(diz[i].it, diz[i].en); j++) {
      if (!strcmp(diz[i].it, diz[j].en))
        printf("- %s %s * %s %s\n", diz[i].it, diz[i].en, diz[j].it, diz[j].en);
    }
  }

  printf("\nPiù traduzioni:\n");
  for (i = 0; i < DIM; i++) {
    for (j = 0, stampata = 0; j < DIM && !stampata; j++) {
      if (!strcmp(diz[i].it, diz[j].it) && j != i) {
        printf("- %s %s\n", diz[i].it, diz[i].en);
        stampata = 1;
      }
    }
  }

  return 0;
}