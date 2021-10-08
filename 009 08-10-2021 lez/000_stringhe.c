#include <stdio.h>
#define LUNGHEZZA 8

int main() {
  /* 
    Le stringhe in C sono definite come array di caratteri, che 
    sovradimensioniamo al caso pessimo del nostro problema.
    Devo lasciare spazio per il carattere terminatore, per convenzione \0
  */
  char str[LUNGHEZZA+1];

  /* Qua c'è un'eccezione alla regola: non si usa &str, ma solo str */
  scanf("%s", str);


  printf("%s", str);

  return 0;
}