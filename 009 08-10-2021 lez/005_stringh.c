#include <stdio.h>

/* La libreria string.h contiene una serie di funzioni utility per le stringhe */
#include <string.h>

#define MAXS 30

/*
  Scrivere un programma in C che acquisisce due stringhe di al più 30
  caratteri e verifica se sono uguali visualizzando un apposito
  messaggio con il responso (1: uguali, 0: diverse).
*/

int main() {
  char s1[MAXS+1], s2[MAXS+1];
  int i, uguali;

  /* 
    scanf può anche utilizzare il regex, in questo caso per acquisire una
    stringa fino al primo a capo.
  */
  scanf("%[^\n]", s1);
  scanf("%[^\n]", s2);

  /* strlen permette di calcolare la lunghezza di una stringa */
  i = strlen(s1);

  /*
    Bisogna però stare attenti ad utilizzare queste funzioni solo quando servono.
    Ad esempio, se vogliamo sapere la lunghezza nel for mettiamo una variabile, non la funzione:

    len = strlent(s1)
    for (i = 0; i < len; i++);
    Questo ciclo ha una sola dimensione, è un problema lineare.

    for (i = 0; i < strlen(s1); i++);
    Questo problema è diventato quadratico, quando poteva essere semplicemente lineare.
  */

  /* strcmp (string compare) permette di confrontare due stringhe */
  uguali = !(strcmp(s1, s2));

  return 0;
}