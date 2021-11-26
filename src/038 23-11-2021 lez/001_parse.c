#include <stdio.h>
#include <stdlib.h>

/*
  Scrivere un programma che riceve come argomenti da riga di comando
  due numeri interi. Il programma visualizza la somma dei due valori.
  Nel caso l'utente abbia specificato in modo errato il numero di
  argomenti richiesto il programma visualizza un messaggio di errore.
*/

int main(int argc, char *argv[]) {
  int num1, num2, somma;

  if (argc == 3) {
    /*
      atoi converte la (prima parte della) stringa passata come 
      argomento a un intero
    */
    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);
    somma = num1 + num2;
    printf("%d\n", somma);
  } else
    printf("Errore argomenti.\n");

  return 0;
}