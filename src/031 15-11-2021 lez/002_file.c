#include <stdio.h>

/*
  Scrivere un programma in C che chiede all'utente un valore intero e
  lo stampa a video. Si utilizzino i sottoprogrammi fprintf e fscanf
  sugli stream stdin e stdout
*/

int main() {
  int n;

  fscanf(stdin, "%d", &n);
  fprintf(stdout, "%d\n", n);

  /*
    E' equivalente a:
      scanf("%d", &n);
      printf("%d", n);
    stdin e stdout rappresentano rispettivamente tastiera e schermo, e si
    comportano come due puntatori a file in questo caso
    Esiste anche stderr, il buffer per gli errori.
  */

  /*
    REDIRIZIONAMENTO DELL'INPUT E OUTPUT
    Se sul terminale scrivo:
      ./a.out < prova.txt
    chiedo al sistema operativo di utilizzare un file al posto della tastiera
    allo stesso modo.
      ./a.out > prova.txt
    chiede al sistema operativo di utilizzare il file come output
    non abbiamo aperto o scritto dei file.
    Lo stdin e stdout vengono utilizzati
  */

  return 0;
}
