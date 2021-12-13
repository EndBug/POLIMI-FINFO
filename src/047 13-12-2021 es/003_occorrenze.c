#include <stdio.h>

/*
  Definire un nuovo tipo di dato per la gestione di una lista dinamica di
  interi, list_t. Scrivere due sottoprogrammi kcon e knocon che ricevuta in
  ingresso una lista del tipo definito ed un intero k, si comportino come
  specificato di seguito:

  - kcon: restituisce 1 se la lista contiene almeno due occorrenze consecutive
    di k, 0 altrimenti
  - knocon: restituisce 1 se la lista contiene almeno due occorrenze non
    consecutive di k, 0 altrimenti.

  Provare a realizzare le versioni sia iterative che ricorsive dei due
  sottoprogrammi; per le versioni ricorsive è possibile definire ulteriori
  sottoprogrammi ausiliari.

  Esempi (tutti con k=5)

  Con la lista: 1 -> 5 -> 5 -> 3 -> 2
  kcon: 1
  knoncon: 0

  Con la lista: 1 -> 5 -> 5 -> 5 -> 2
  kcon: 1
  knoncon: 1

  Con la lista: 1 -> 5 -> 3 -> 5 -> 2
  kcon: 0
  knoncon: 1
*/

typedef struct lista_ {
  int n;
  struct lista_ *next;
} lista_t;

int kcon_it(lista_t *l, int k);
int kcon_rec(lista_t *l, int k);
int knocon_it(lista_t *l, int k);
int knocon_rec(lista_t *l, int k);

int kcon_it(lista_t *l, int k) {
  int res;

  for (res = 0; !res && l && l->next; l = l->next) {
    if (l->n == k && l->next->n == k)
      res = 1;
  }

  return res;
}

int kcon_rec(lista_t *l, int k) {
  if (!l || !l->next)
    return 0;

  if (l->n == k && l->next->n == k)
    return 1;

  return kcon_rec(l->next, k);
}

int knocon_it(lista_t *l, int k) {
  int res;

  for (res = 0; l && l->next && l->next->next; l = l->next) {
    if (l->n == k && l->next->next->n == k)
      res = 1;
  }

  return res;
}

int knocon_rec(lista_t *l, int k) {
  if (!l || !l->next || !l->next->next)
    return 0;

  if (l->n == k && l->next->next->n == k)
    return 1;

  return knocon(l->next, k);
}
