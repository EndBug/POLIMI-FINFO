#include <stdio.h>

/*
  Definire un tipo di dato intervallo_t per descrivere un intervallo
  su un asse temporale in termini di inizio e fine (due numeri
  interi).
  Scrivere un sottoprogramma che chiede i dati di un intervallo. Se
  l'utente specifica un valore di inizio maggiore del valore di fine,
  il sottoprogramma inverte i due valori per salvarli correttamente in
  una variabile di tipo intervallo_t che restituisce al chiamante.
  Scrivere un sottoprogramma che riceve come parametri due intervalli
  ed un parametro formale intero, detto "sovrapposti", passato per
  indirizzo. Il sottoprogramma verifica se i due intervalli sono
  sovrapposti ed in caso affermativo assegna 1 a sovrapposti e calcola
  e restituisce l'intervallo sovrapposto; in alternativa assegna 0 a
  sovrapposti e restituisce l'intervallo di estremi 0, 0.
  Scrivere un sottoprogramma che riceve come parametro un intervallo e
  restituisce la sua lunghezza
  Scrivere un sottoprogramma che riceve come parametro un intervallo e
  lo stampa a video.
  Scrivere un programma che mediante l'ausilio dei tre sottoprogramma
  definiti acquisisce due intervalli e valuta se sono sovrapposti; in
  caso affermativo visualizza l'intervallo sovrapposto e la sua
  lunghezza. In alternativa mostra un messaggio "non sovrapposti".
  Esempio: se l'utente inserisce gli intervalli -2 5 e 1 10,
  l'intersezione sarà 1 5 ed avrà lunghezza 4.
*/

typedef struct {
  int start, end;
} intervallo_t;

intervallo_t getInterval();
intervallo_t checkIntersection(intervallo_t, intervallo_t, int *);
int checkLength(intervallo_t);
void print(intervallo_t);

int main() {
  intervallo_t a, b, sov;
  int s, len;

  a = getInterval();
  b = getInterval();

  s = 0;
  sov = checkIntersection(a, b, &s);

  if (s) {
    len = checkLength(sov);
    print(sov);
    printf("%d\n", len);
  } else {
    printf("Non sovrapposti.\n");
  }

  return 0;
}

intervallo_t getInterval() {
  int tmp;
  intervallo_t res;

  scanf("%d %d", &res.start, &res.end);

  if (res.start > res.end) {
    tmp = res.start;
    res.start = res.end;
    res.end = tmp;
  }

  return res;
}

intervallo_t checkIntersection(intervallo_t a, intervallo_t b,
                               int *sovrapposti) {
  intervallo_t res;

  if ((a.start > b.start && a.start < b.end) ||
      b.start > a.start && b.start < a.end) {
    *sovrapposti = 1;

    if (a.start > b.start)
      res.start = a.start;
    else
      res.start = b.start;

    if (a.end < b.end)
      res.end = a.end;
    else
      res.end = b.end;

  } else {
    *sovrapposti = 0;
    res.start = 0;
    res.end = 0;
  }

  return res;
}

int checkLength(intervallo_t a) { return a.end - a.start; }

void print(intervallo_t a) { printf("%d -> %d\n", a.start, a.end); }
