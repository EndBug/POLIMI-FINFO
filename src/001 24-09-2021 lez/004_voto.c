#include <stdio.h>
#define MIN 0
#define I 10
#define S 18
#define O 25
#define MAX 30

/*
  Scrivere un programma che acquisisce un intero che rappresenta un
  voto e stampa «grav. insuff.» se il voto è minore 10, «insuff.» se
  il voto è compreso tra 10 e 17 estremi inclusi, «suff.» se è
  compreso tra 18 e 24 estremi inclusi, «ottimo» se maggiore di 24.
  Estendere il programma in modo tale che verifichi che il numero
  inserito rappresenti un voto valido (un intero tra 0 e 30 estremi
  inclusi); in caso affermativo procede con l'analisi altrimenti
  visualizza un messaggio di errore.
*/

int main() {
  int voto;

  scanf("%d", &voto);

  if (voto >= MIN && voto <= MAX) {
    if (voto < I)
      printf("grav. insuff.\n");
    else if (voto < S)
      printf("insuff.\n");
    else if (voto < O)
      printf("suff.\n");
    else
      printf("ottimo\n");
  } else
    printf("Errore.\n");

  return 0;
}
