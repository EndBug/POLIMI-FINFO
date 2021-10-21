#include <stdio.h>

/*
  Definire un tipo di dato struct per rappresentare una frazione in
  termini di numeratore e denominatore (due numeri interi).
  Scrivere un sottoprogramma che chiede all'utente una frazione valida
  (denominatore diverso da zero) e la restituisce al chiamate; nel
  caso la condizione non sia soddisfatta il sottoprogramma richiede di
  nuovo all'utente di inserire dei valori validi.
  Scrivere un sottoprogramma che riceve come parametro una frazione e
  la semplifica spostando l'eventuale segno meno al numeratore.
  Scrivere un sottoprogramma che riceve come parametri due frazioni,
  ne esegue la somma, semplifica il risultato (mediante la funzione
  precedentemente definita) e restituisce il risultato.
  Scrivere un sottoprogramma che riceve come parametri due frazioni,
  ne esegue la moltiplicazione, semplifica il risultato (mediante la
  funzione precedentemente definita) e restituisce il risultato.
  Scrivere un sottoprogramma che riceve come parametro una frazione e
  la stampa a video.
  Scrivere un programma che mediante l'ausilio dei sottoprogrammi
  sopra definiti, chiede all'utente due frazioni le somma e le
  moltiplica e visualizza i due risultati.
*/

typedef struct {
  int n, d;
} frac_t;

frac_t acquisici();
frac_t semplifica(frac_t);
frac_t somma(frac_t, frac_t);
frac_t moltiplica(frac_t, frac_t);
/* Utilizziamo void per indicare che la funzione non ritorna => è una procedura. */
void stampa(frac_t);

int main() {
  frac_t a, b;

  a = acquisici();
  b = acquisici();

  stampa(somma(a, b));
  stampa(moltiplica(a, b));

  return 0;
}

frac_t acquisici() {
  frac_t f;

  do 
    scanf("%d %d", &f.n, &f.d);
  while (f.d == 0);

  return f;
}

frac_t semplifica(frac_t f) {
  int meno, mcd;

  if (f.n < 0) {
    meno = 1;
    f.n *= -1;
  } else
    meno = 0;

  if (f.d < 0) {
    meno *= -1;
    f.d *= -1;
  }

  if (f.n < f.d)
    mcd = f.n;
  else
    mcd = f.d;

  while (f.n % mcd || f.d % mcd)
    mcd--;

  f.n /= mcd;
  f.d /= mcd;

  if (meno)
    f.n *= -1;

  return f;
}

frac_t somma(frac_t a, frac_t b) {
  frac_t s;

  s.n = a.n*b.d + b.n*a.d;
  s.d = a.d * b.d;

  return semplifica(s);
}

frac_t moltiplica(frac_t a, frac_t b) {
  frac_t m;

  m.n = a.n * b.n;
  m.d = a.d * b.d;

  return semplifica(m);
}

void stampa(frac_t f) {
  printf("%d/%d\n", f.n, f.d);

  /* Se proprio vogliamo possiamo mettere anche una return di questo tipo: */
  return;
  /* che però di fatto non fa niente, e può essere omessa. */
}