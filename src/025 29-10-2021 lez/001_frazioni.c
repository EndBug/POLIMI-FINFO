#include <stdio.h>

/*
  Definire un tipo di dato strutturato per rappresentare una frazione
  in termini di numeratore e denominatore (due numeri interi).
  Scrivere un sottoprogramma che riceve come parametro passato per
  indirizzo una frazione e la visualizza sullo schermo.
  Scrivere un sottoprogramma che riceve come parametro passato per
  indirizzo una variabile frazione, chiede all'utente numeratore e
  denominatore (verificando la correttezza di quest'ultimo e nel caso
  richiedendone il valore) e salva i due valori nella variabile
  ricevuta come parametro.
  Scrivere un sottoprogramma che riceve come parametro passato per
  indirizzo una frazione e la semplifica.
  Scrivere un programma che chiede mediante i sottoprogrammi sopra
  definiti chiede all'utente una frazione, la semplifica e mostra il
  risultato a video.
*/

typedef struct {
  int n, d;
} frazione_t;

void visualizza(frazione_t*);
void acquisisci(frazione_t*);
void semplifica(frazione_t*);

int main() {
  frazione_t f;

  acquisisci(&f);
  semplifica(&f);
  visualizza(&f);

  return 0;
}

/* Utilizziamo un nuovo operatore: a->b equivalente a (*a).b */
void visualizza(frazione_t *f) {
  printf("%d/%d\n", f->n, f->d);
}

void acquisisci(frazione_t *f) {
  scanf("%d %d", &f->n, &f->d);
  while (f->d == 0)
    scanf("%d", &f->d);
}

void semplifica(frazione_t *f) {
  int meno, mcd;

  if (f->n < 0) {
    meno = 1;
    f->n *= -1;
  } else
    meno = 0;

  if (f->d < 0) {
    meno *= -1;
    f->d *= -1;
  }

  if (f->n < f->d)
    mcd = f->n;
  else
    mcd = f->d;

  while (f->n % mcd || f->d % mcd)
    mcd--;

  f->n /= mcd;
  f->d /= mcd;

  if (meno)
    f->n *= -1;
}