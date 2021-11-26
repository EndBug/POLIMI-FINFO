#include <stdio.h>
#define MAXS 30

/*
  Scrivere un programma che chiede all'utente una stringa di al
  massimo 30 caratteri che rappresenta il nome di un file binario. Il
  programma apre il file e verifica se è vuoto o meno stampando a
  video il responso. Visualizzare un messaggio per eventuali errori di
  apertura del file.
*/

int main() {
  char fn[MAXS+1], c;
  FILE *fp;

  scanf("%s", fn);

  fp = fopen(fn, "rb");
  if (fp) {
    fscanf(fp, "%c", &c);

    if (feof(fp))
      printf("Vuoto.\n");
    else
      printf("Non vuoto.\n");

    fclose(fp);
  } else
    printf("Errore di apertura.\n");

  return 0;
}