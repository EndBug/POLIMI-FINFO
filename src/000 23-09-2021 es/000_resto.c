#include <stdio.h>
#define TAGLIO 5
#define MONETA2 2

/*
  Scrivere un programma che chiede all'utente un valore intero
  positivo o nullo che rappresenta l'importo che un cassiere deve
  restituire al cliente. Assumendo che l'utente abbia solo banconote
  da 5 euro e monete da 1 euro, il programma stabilisce e visualizza
  quante banconote da 5 euro deve restituire ed eventualmente quante
  monete da 1 euro.
*/

int main() {
  int resto, n_banconote, n_monete2, n_monete1;

  printf("Resto da dare: ");
  scanf("%d", &resto);

  n_banconote = resto / TAGLIO;
  n_monete2 = resto / MONETA2;
  n_monete1 = resto % MONETA2;

  printf("%d %d %d\n", n_banconote, n_monete2, n_monete1);

  return 0;
}
