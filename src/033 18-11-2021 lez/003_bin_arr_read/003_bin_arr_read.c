#include <stdio.h>
#define FN "ciao.bin"
#define DIM 10

/*
  Da es 15-11-2021
  Scrivere un programma apre in lettura un file di testo "ciao.bin"
  che contiene 10 valori interi. Il programma legge i valori e
  verifica che siano stati letti tutti correttamente. In caso
  affermativo li visualizza altrimenti segnala l'errore.
*/

int main() {
  FILE *fp;
  int a[DIM], i, quanti;

  fp = fopen(FN, "rb");
  if (fp) {
    quanti = fread(a, sizeof(int), DIM, fp);
    if (quanti == DIM) {
      for (i = 0; i < DIM; i++)
        printf("%d ", a[i]);
      printf("\n");
    } else
      printf("Errore lettura.\n");
  } else
    printf("Errore apertura.\n");

  return 0;
}
