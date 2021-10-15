#include <stdio.h>
#define MAXN 10
#define HH 24
#define MM 60
#define SS 60

/*
  Definire un nuovo tipo di dato per memorizzare una durata temporale
  in termini di numero di giorni, ore, minuti e secondi. Scrivere un
  programma che riceve da tastiera i dati sulla durata di una serie di
  10 intervalli di tempo. Ciascun intervallo di tempo è della durata
  massima di 23 ore, 59 minuti e 59 secondi. Il programma deve
  assicurarsi che i dati di ciascun intervallo inserito siano validi.
  Successivamente, il programma calcola la somma di tutti gli
  intervalli e la stampa a video nel formato: giorni, ore, minuti,
  secondi (massimo 23 ore, massimo 59 minuti, massimo 59 secondi.
  Nessun limite al numero di giorni).
  Esempio: per le seguenti durate di due (e non 10 per brevità)
  intervalli di tempo (ore, minuti, secondi):
  - 20 50 15
  - 7 20 30
  il risultato che dovrà essere stampato sarà:
  1 giorno/i, 4 ora/e, 10 minuto/i e 45 secondo/i.
  VARIANTE: modificare il programma in modo tale che chieda all'utente
  il numero di intervalli (massimo 10) di cui misurare la durata
  complessiva (e ne caso il valore sia sbagliato lo richiede).
*/

typedef struct {
  int h, m, s;
} intervallo_t;

int main() {
  int n, i, errore, accSec;
  intervallo_t tmp, arr[MAXN];

  do
    scanf("%d", &n);
  while (n < 1 || n > MAXN);

  for (i = 0, errore = 0; i < n && !errore; i++) {
    scanf("%d %d %d", &tmp.h, &tmp.m, &tmp.s);
    if (
      tmp.h >= 0 
      && tmp.h < HH 
      && tmp.m >= 0 
      && tmp.m < MM 
      && tmp.s >= 0 
      && tmp.s < SS
    ) {
      arr[i] = tmp;
    } else {
      errore = 1;
    }
  }

  if (!errore) {
    for (i = 0, accSec = 0; i < n; i++)
      accSec += (arr[i].h * MM + arr[i].m) * SS + arr[i].s;

    printf(
      "%d giorno/i, %d ora/e, %d minuto/i, %d secondo/i\n",
      accSec / (HH*MM*SS),
      (accSec % (HH*MM*SS)) / (MM*SS),
      (accSec % (MM*SS)) / SS,
      accSec % SS
    );
  } else 
    printf("Errore.");

  return 0;
}