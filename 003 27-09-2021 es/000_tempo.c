#include <stdio.h>
#define ORE 24
#define MIN 60
#define SEC 60

int main() {
  int tempo, tempoRimanente;
  int giorni, ore, minuti, secondi;

  scanf("%d", &tempo);

  giorni = tempo / (ORE * MIN * SEC);
  tempoRimanente = tempo % (ORE * MIN * SEC);
  ore = tempoRimanente / (MIN * SEC);
  tempoRimanente = tempoRimanente % (MIN * SEC);
  minuti = tempoRimanente / SEC;
  secondi = tempoRimanente % SEC;

  printf("%d giorni, %d ore, %d minuti, %d secondi\n", giorni, ore, minuti, secondi);

  return 0;
}