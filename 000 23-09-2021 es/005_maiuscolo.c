#include <stdio.h>

int main() {
  char mai, min;

  scanf("%c", &min);

  // Dobbiamo passare da minuscolo a maiuscolo, quindi possiamo aggiungere la differenza, 
  // anche senza sapere quali sono i codici ASCII.
  //        - partenza + arrivo
  mai = min - 'a' + 'A';

  printf("%c\n", mai);

  return 0;
}