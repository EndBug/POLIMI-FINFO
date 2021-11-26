#include <stdio.h>

/*
  Scrivere un programma in C che chiede all'utente un valore intero e
  lo stampa a video. Si utilizzino i sottoprogrammi fprintf e fscanf
  sugli stream stdin e stdout
*/

int main () {
  int n;

  scanf("%d", &n);
  printf("%d", n);
  /* è equivalente a: */
  fscanf(stdin,"%d", &n);
  fprintf(stout,"%d", n);
  /* stderr è il buffer per gli errori */

  /* Tastiera e schermo sono due file */

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
  scanf("%d", &n);
  printf("%d", n);

  return 0;
}
