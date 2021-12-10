#include <stdio.h>
#include <string.h>

/*
  Scrivere un sottoprogramma che riceve come parametri una stringa str
  ed un numero n sicuramente compreso tra 1 e 10 estremi inclusi.
  Assumendo che la stringa sia composta da cifre (caratteri!) comprese
  tra '0' e la cifra corrispondente al valore intero n-1 il
  sottoprogramma converte in intero, base dieci, il valore
  rappresentato dalla stringa
  in base n e restituisce il risultato. Nel caso la stringa contenga
  un carattere
  non ammissibile, il sottoprogramma restituisce -1.
  Esempi:
  Per str = '100', n = 2, il sottoprogramma restituisce il valore 4 (=
  1*2^2)
  Per str = '210', n = 3, il sottoprogramma restituisce il valore 21
  (= 2*3^2 + 1*3^1)
*/

int converti(char *str, int n) {
  int i, len, pot, res;

  len = strlen(str);

  for (i = len - 1, pot = 1, res = 0; i >= 0 && res != -1; i--, pot *= n) {
    if (str[i] >= '0' && str[i] <= '0' + n - 1)
      res += pot * (str[i] - '0');
    else
      res = -1;
  }

  return res;
}
