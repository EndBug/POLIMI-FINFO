#include <stdio.h>
#include <string.h>

#define MAX 30

/*
  Da es. 08-10-2021
  Scrivere un programma in C che chiede all'utente due stringhe s e t
  di al massimo 30 caratteri. Il programma conta quante volte la
  stringa t compare come sottostringa all'interno della stringa s e
  stampa a video il risultato.
*/

int main() {
  char s[MAX + 1], t[MAX + 1];
  int i, j, res, ls, lt;

  scanf("%s %s", s, t);

  ls = strlen(s);
  lt = strlen(t);

  res = 0;
  for (i = 0; i <= ls - lt; i++) {
    /*
      Si può fare anche utilizzando uan flag, ma non è necessario.
      for (j = 0, contenuta = 1; j < lt && contenuta; j++)
        if (s[i+j] != t[j])
          contenuta = 0;

      if (contenuta)
        res++;
    */

    for (j = 0; j < lt && s[i + j] == t[j]; j++)
      ;
    if (j == lt)
      res++;
  }

  printf("%d\n", res);

  return 0;
}
