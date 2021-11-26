#include <stdio.h>

/*
  Scrivere un programma che realizza le funzionalità base di una
  calcolatrice. Il programma chiede all'utente due numeri in virgola
  mobile ed un carattere che rappresenta l'operazione che si vuole
  eseguire (+ - * /). Il programma esegue l'operazione richiesta e
  visualizza il risultato. Nel caso l'utente inserisce un carattere
  che non rappresenta alcuna operazione ammissibile, il programma
  visualizza un messaggio di errore.
*/

int main() {
  float a, b, res;
  int err;
  char op;

  scanf("%f %f %c", &a, &b, &op);

  err = 0;

  if (op == '+')
    res = a + b;
  else if (op == '-')
    res = a - b;
  else if (op == '*')
    res = a * b;
  else if (op == '/')
    res = a / b;
  else
    err = 1;

  if (!err)
    printf("Risultato %f\n", res);
  else
    printf("Operazione non valida.\n");

  return 0;
}
