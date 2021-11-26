#include <stdio.h>

/*
  Scrivere un programma che chiede all'utente un carattere
  dell'alfabeto minuscolo (assumiamo che l'utente non inserisca un
  carattere non valido). Il programma calcola e visualizza il
  corrispondente carattere maiuscolo.
*/

int main() {
  char mai, min;

  scanf("%c", &min);

  /*
    Dobbiamo passare da minuscolo a maiuscolo, quindi possiamo aggiungere la
    differenza, anche senza sapere quali sono i codici ASCII.
  */
  mai = min - 'a' + 'A';

  printf("%c\n", mai);

  return 0;
}
