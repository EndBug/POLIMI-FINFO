#include <stdio.h>
#define MAX_N 100
#define MAX_H 8
#define TEMP 22

/*
  Realizzare un programma in C per la gestione di una serie di
  rilevazioni di temperature sui piani di un edificio. Ciascun
  rilevazione specifica il numero del piano, l'ora della misura (una
  stringa di al massimo 8 caratteri) e la temperatura letta (un numero
  intero).
  Definire un tipo di dato strutturato per rappresentare ciascuna
  rilevazione.
  In seguito, scrivere un programma per la gestione delle rilevazioni.
  Il programma dovrà chiedere all'utente di specificare il numero di
  rilevazioni da inserire (massimo 100 e nel caso l'utente non
  inserisca un valore valido il programma lo richiede) e poi inserire
  le rilevazioni (si assume che i dati siano inseriti correttamente in
  base all'ora). In seguito il programma dovrà chiedere all'utente il
  numero di un piano. Il programma visualizzerà gli intervalli di
  tempo per cui la temperatura di quel piano è stata inferiore ai 22
  gradi. Si noti che è necessario stampare solo l'ora relativa alla
  prima e all'ultima rilevazione di ciascun intervallo.

  ESEMPIO:
  Numero di rilevazioni: 8

  Rilevazioni:
  1 10:30:00 23
  2 10:35:00 21
  2 11:00:00 20
  1 11:20:00 23
  2 11:34:00 21
  2 12:30:00 24
  1 12:40:00 23
  2 14:30:00 21

  Piano da analizzare: 2
  Risultato:
  10:35:00 -> 11:34:00
  14:30:00 -> 14:30:00
*/

typedef struct {
  int piano, temperatura;
  char ora[MAX_H+1];
} rilevazione_t;

int main() {
  int n, i, target, int_aperto;
  rilevazione_t rilevazioni[MAX_N], last;

  printf("Numero di rilevazioni: ");
  do
    scanf("%d", &n);
  while (n < 0 || n > MAX_N);

  printf("\nRilevazioni:\n");
  for (i = 0; i < n; i++)
    scanf("%d %s %d", &rilevazioni[i].piano, rilevazioni[i].ora, &rilevazioni[i].temperatura);

  printf("\nPiano da analizzare: ");
  scanf("%d", &target);

  printf("\nRisultato:\n");
  for (i = 0, int_aperto = 0; i < n; i++) {
    if (rilevazioni[i].piano == target) {
      if (rilevazioni[i].temperatura < TEMP && !int_aperto) {
        /* Apro l'intervallo orario in cui siamo sotto il limite */
        printf("%s -> ", rilevazioni[i].ora);
        int_aperto = 1;
      } else if (rilevazioni[i].temperatura >= TEMP && int_aperto) {
        /* Chiudo l'intervallo */
        printf("%s\n", last.ora);
        int_aperto = 0;
      }
      last = rilevazioni[i];
    }
  }
  if (int_aperto) {
    /* Mi assicuro che l'ultimo intervallo sia chiuso */
    printf("%s\n", last.ora);
  }

  return 0;
}