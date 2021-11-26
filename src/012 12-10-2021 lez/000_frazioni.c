#include <stdio.h>

/*
  Definire un tipo di dato strutturato in C per rappresentare una
  frazione in termini di numeratore e denominatore (due numeri
  interi). Scrivere un programma in C che acquisisce due frazioni ed
  esegue la somma. Il programma deve in seguito semplificare il
  risultato dell'operazione rappresentando l'eventuale segno meno nel
  numeratore.
*/

typedef struct {
  int n, d;
} frazione_t;

/*
  Si può anche dichiarare:
  struct nome {...};
  
  Ma poi le variabili vanno dichiarate come:
  struct nome a, b;

  Inoltre typedef e struct sono due keyword separate, e potremmo dare il nome
  allo struct invece che al typedef:
  typedef struct nome {...};

  struct può essere anche utilizzato in forma anonima, ma poi se va riutilizzato
  va riscritto da capo => :(
*/

int main() {
  frazione_t a, b, somma;
  int meno, mcd;

  do
    scanf("%d %d", &a.n, &a.d);
  while (a.d == 0);

  do
    scanf("%d %d", &b.n, &b.d);
  while (b.d == 0);

  somma.d = a.d * b.d;
  somma.n = a.n*b.d + b.n*a.d;

  if (somma.n < 0) {
    somma.n *= -1;
    meno = 1;
  } else 
    meno = 0;
  if (somma.d < 0) {
    somma.d *= -1;
    meno = !meno;
  }

  if (somma.n < somma.d)
    mcd = somma.n;
  else
    mcd = somma.d;

  while (somma.n%mcd || somma.d%mcd)
    mcd--;

  somma.n /= mcd;
  somma.d /= mcd;

  if (meno)
    somma.n *= -1;

  printf("%d/%d\n", somma.n, somma.d);

  return 0;
}