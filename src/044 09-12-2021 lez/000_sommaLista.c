/*
  Scrivere un sottoprogramma ricorsivo che riceve come parametro la
  testa di una lista di interi e la modifica sommando a ogni elemento
  il valore di tutti gli elementi ad esso successivi (l'ultimo
  elemento resta invariato), e restituisca la somma di tutti i valori
  nella lista.
  Es: Data la lista
  l: 1->2->10->3->6
  il sottoprogramma la modifica in
  l: 22->21->19->9->6
  e restituisce il valore 22
*/

typedef struct nodo_ {
  int num;
  struct nodo_ *next;
} nodo_t;

int sommaLista(nodo_t *h);

int sommaLista(nodo_t *h) {
  if (!h)
    return 0;

  h->num += sommaLista(h->next);
  return h->num;
}
