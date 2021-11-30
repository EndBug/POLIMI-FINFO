#include <stdio.h>
#define MAXS 30

/*
  Scrivere un sottoprogramma che chiede all'utente una stringa e conta
  quante vocali sono contenute, restituendo il risultato. Scrivere un
  programma che chiede all'utente una stringa di al massimo 30
  caratteri che può contenere anche degli spazi, invoca su di essa la
  funzione sopra definita e visualizza il risultato.
*/

int contaVocali(char *str);

int main() {
  char str[MAXS + 1];
  int res;

  scanf("%[^\n]", str);
  res = contaVocali(str);
  printf("%d\n", res);

  return 0;
}

int contaVocali(char *str) {
  int i, count;

  for (i = 0, count = 0; *(str + i) != '\0'; i++) {
    switch (str[i]) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
      count++;
      break;

    default:
      break;
    }
  }

  return count;
}
