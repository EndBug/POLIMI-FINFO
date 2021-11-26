#include <stdio.h>
#define DIMS 30

/*
  Scrivere un sottoprogramma che chiede all'utente una stringa e conta
  e restituisce quante vocali contiene. Scrivere un programma che
  chiede all'utente una stringa di al massimo 30 caratteri che può
  contenere anche degli spazi, invoca su di essa il sottoprogramma
  sopra definito e visualizza il risultato.
*/

/* Con le stringhe non abbiamo bisogno di passare la lugnhezza, c'è \0 */
int contavocali(char*);

int main() {
  char str[DIMS+1];
  int c;

  scanf("%[^\n]", str);

  c = contavocali(str);

  printf("%d\n", c);

  return 0;
}

int contavocali(char *str) {
  int conto;

  for (conto = 0; *str != '\0'; str++) {
    switch (*str) {
      case 'a':
      case 'A':
      case 'e':
      case 'E':
      case 'i':
      case 'I':
      case 'o':
      case 'O':
      case 'u':
      case 'U':
        conto++;
    }
  }
  return conto;
}