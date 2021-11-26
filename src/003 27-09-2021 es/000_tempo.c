#include <stdio.h>
#define ORE 24
#define MIN 60
#define SEC 60

/*
  Scrivere un programma che chiede all'utente un valore intero
  positivo o nullo che rappresenta una durata di tempo in secondi. Il
  programma converte e visualizza la durata in termini di: N di
  giorni, N di ore, N di minuti, N di secondi. Per esempio, se
  l'utente inserisce il valore 76, il programma visualizzerà "0
  giorni, 0 ore, 1 minuti, 16 secondi".
*/

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

  printf("%d giorni, %d ore, %d minuti, %d secondi\n", giorni, ore, minuti,
         secondi);

  return 0;
}
