/*
  Da esame del 20/01/2020 della prof.ssa Cristiana Bolchini
  https://bolchini.faculty.polimi.it/exams/20200120.pdf
  -> Quesito 4
*/

/*
  Possiamo definire altri sottoprogrammi, se li riteniamo utili.
  Potremmo anche usare la funzione che esiste già in string.h, ma
  l'implementazione è così facile che non conviene.
*/
char toLow(char c);
void minmaxstr(char str[], char *min, char *max);

/* Variante 1 */
void minmaxstr(char str[], char *min, char *max) {
  int i;

  *min = str[0];
  *max = str[0];

  if (str[0] != '\0') {
    for (i = 1; str[i] != '\0'; i++) {
      if (*min > str[i])
        *min = str[i];
      else if (*max < str[i])
        *max = str[i];
    }
  }
}

/* Variante 2, con la gestione delle lettere maiuscole */
char toLow(char c) {
  if (c >= 'A' && c <= 'Z')
    c = c - 'A' + 'a';
  return c;
}

void minmaxstr(char str[], char *min, char *max) {
  int i;

  /*
    Se non utilizzassimo una variabile in più rischieremmo di modificare la
    stringa, e non possiamo farlo => dobbiamo usare una variabile di appoggio.
  */
  char c;
  c = toLow(str[0]);

  *min = c;
  *max = c;

  if (str[0] != '\0') {
    for (i = 1; str[i] != '\0'; i++) {
      c = toLow(str[i]);

      if (*min > str[i])
        *min = str[i];
      else if (*max < str[i])
        *max = str[i];
    }
  }
}

int main(int argc, char *argv[]) {
  char min, max, *str;

  if (argc == 2) {
    str = argv[1];
    minmaxstr(str, &min, &max);
    printf("%c %c\n", min, max);
  } else
    printf("Errore argomenti.\n");

  return 0;
}
