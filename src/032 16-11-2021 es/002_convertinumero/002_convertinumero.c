#include <stdio.h>
#define BASE 10
#define FN "testo.txt"
#define MAXS 15

/*
  a) Scrivere un sottoprogramma convertinumero che riceve come
  parametro una stringa str e due parametri interi num e valido
  passati per indirizzo in cui salvare i risultati. Se str è composta
  soltanto da cifre (char da '0' a '9'), il sottoprogramma converte la
  stringa in un numero, la salva in num ed assegna 1 al parametro
  valido. Altrimenti il sottoprogramma assegna 0 a valido e non
  modifica num. NOTA: è vietato l'utilizzo di funzioni di conversione
  quali atoi o sscanf.
  b) Scrivere un programma che apre un file di testo testo.txt
  contenente una serie di lunghezza indefinita di parole ciascuna
  lunga al massimo 15 caratteri. Il programma legge ciascuna parola
  contenuta nel file e, mediante il sottoprogramma convertinumero,
  verifica se si tratta di una stringa composta solo da cifre e in
  caso affermativo la converte in un numero. Il programma somma tutti
  i numeri identificati e presenta a video il risultato finale.
  Ad esempio, se il file contiene il seguente testo:
  Ciao domani 120 10 alfa23 esame 5 informatica 34tre -34
  Il programma stamperà a video il seguente messaggio:
  135
*/

void convertinumero(char *str, int *num, int *valido);

int main() {
  FILE *fp;
  char word[MAXS+1];
  int num, valido, sum;

  fp = fopen(FN, "r");

  if (fp) {
    sum = 0;
    fscanf(fp, "%s", word);
    convertinumero(word, &num, &valido);
    if (valido)
      sum += num;

    while (!feof(fp)) {
      fscanf(fp, "%s", word);
      convertinumero(word, &num, &valido);
      if (valido)
        sum += num;
    }

    printf("%d\n", sum);

    fclose(fp);
  } else
    printf("Errore.\n");

  return 0;
}

void convertinumero(char *str, int *num, int *valido) {
  int i;

  *valido = 1;
  for (i = 0; *(str+i) != '\0' && *valido; i++)
    *valido = *(str+i) >= '0' && *(str+i) <= '9';

  if (*valido) {
    *num = 0;
    for (i = 0; *(str+i) != '\0'; i++) {
      *num = (*(str+i) - '0') + (*num * BASE);
    }
  }
}
