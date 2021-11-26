#include <stdio.h>

int main() {
  // Non esiste il tipo bool in C, quindi utilizziamo un int in cui salveremo 0 o 1.
  // Gli operatori relazionali e quelli logici ritornano sempre o 0 o 1.
  int anno, bisestile;

  scanf("%d", &anno);

  // L'ordine delle operazione è sempre definito dalla tabella delle priorità.
  bisestile = (anno%4==0 && !(anno%100==0)) || anno%400 == 0;

  printf("%d\n", bisestile);

  return 0;
}