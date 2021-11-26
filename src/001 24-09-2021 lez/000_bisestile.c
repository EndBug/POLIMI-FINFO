#include <stdio.h>

/*
  Scrivere un programma che chiede all'utente di inserire un numero
  intero che corrisponde ad un anno e visualizza 1 se l'anno è
  bisestile, 0 altrimenti. NOTA: un anno è bisestile se è divisibile
  per 4 ma non per 100 o se è divisibile per 400.
*/

int main() {
  /*
    Non esiste il tipo bool in C, quindi utilizziamo un int in cui salveremo 0
    o 1. Gli operatori relazionali e quelli logici ritornano sempre o 0 o 1.
  */
  int anno, bisestile;

  scanf("%d", &anno);

  /*
    L'ordine delle operazione è sempre definito dalla tabella delle priorità.
  */
  bisestile = (anno % 4 == 0 && !(anno % 100 == 0)) || anno % 400 == 0;

  printf("%d\n", bisestile);

  return 0;
}
