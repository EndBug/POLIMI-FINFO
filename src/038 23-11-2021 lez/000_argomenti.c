#include <stdio.h>

/*
  Scrivere un programma che riceve da riga di comando un qualsivoglia
  numero di argomenti. Il sottoprogramma visualizza su una singola
  riga ciascun argomento ricevuto.
*/

/*
  Questo programma stampa tutti gli argomenti che vengono forniti.
  !! Questi includono anche il nome del programma, dato che fa parte del
  comando.
*/
int main(int argc, char *argv[]) {
  int i;

  for (i = 0; i < argc; i++)
    printf("%s\n", argv[i]);

  return 0;
}
