#include <stdio.h> 
#define MAXS 30

/*
  Scrivere un programma in C che acquisisce una stringa di al più 30
  caratteri e calcola e visualizza la sua lunghezza.
*/

int main() {
  char str[MAXS+1];
  int i;

  /* 
    Il programma non sa quanti sono i caratteri da acquisire, quindi se sono
    più della dimensione dell'array va a sporcare la memoria.
    Noi assumeremo che la stringa sia di una lunghezza accettabile.
  */
  scanf("%s", str);

  /*
    Per trovare la lunghezza della stringa scorriamo tutto l'array fino a
    trovare il terminatore. La lunghezza sarà l'indice che terminatore.
  */
  for (i = 0; str[i]!='\0'; i++);

  printf("%d\n", i);

  return 0;
}