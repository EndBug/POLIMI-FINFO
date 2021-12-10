#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

/*
  ES3. Considerando la struttura dati ed i sottoprogrammi contenuti nei file
  lista.c e lista.h, implementare un sottoprogramma che riceve come parametri
  una lista dinamica di interi l1 ed un array di interi sel. Assumendo che sel
  contenga solo valori 0 e 1 e che sia di dimensione pari a l1, il
  sottoprogramma costruisce e restituisce una nuova lista l2 che contiene solo
  gli elementi di l1 che si trovano nella lista in una posizione corrispondente
  agli 1 del vettore sel. Esempio: se il sottoprogramma riceve in ingresso

  l1 = 3 -> 5 -> 8 -> 9 -> 12
  vet = [0, 1, 0, 1, 1]

  dovrà ritornare la lista

  l2 = 5 -> 9 -> 12

  Scrivere un programma che chiede all'utente una sequenza di lunghezza
  indefinita di numeri interi chiesta all'utente e terminata dal valore 0 (che
  non fa parte della sequenza) per popolare una lista dinamica. In seguito il
  programma chiede all'utente un array di valori interi 0 e 1 di lunghezza pari
  a quella della lista (array da allocare dinamicamente!). Il programma invoca
  il sottoprogramma sopra definito, visualizza la lista restituita e libera
  tutta la memoria allocata. Gestire opportunamente tutti gli eventuali errori.
*/

nodo_t *seleziona(nodo_t *l1, int sel[]);
int lunghezza(nodo_t *h);

int main() {
  int tmp, *sel, dim, i;
  nodo_t *l1, *l2;

  scanf("%d", &tmp);
  while (tmp) {
    l1 = inserisciInCoda(l1, tmp);
    scanf("%d", &tmp);
  }

  dim = lunghezza(l1);
  sel = malloc(sizeof(int) * dim);

  if (sel) {
    for (i = 0; i < dim; i++)
      scanf("%d", &sel[i]);

    l2 = seleziona(l1, sel);
    visualizza(l2);

    distruggiLista(l1);
    distruggiLista(l2);
    free(sel);
  } else
    printf("Errore allocazione.\n");

  return 0;
}

nodo_t *seleziona(nodo_t *l1, int sel[]) {
  int dim, i;
  nodo_t *l2;

  dim = lunghezza(l1);
  l2 = NULL;

  for (i = 0; l1; l1 = l1->next, i++) {
    if (sel[i])
      l2 = inserisciInCoda(l2, l1->num);
  }

  return l2;
}

int lunghezza(nodo_t *h) {
  int l;
  for (l = 0; h; h = h->next, l++)
    ;
  return l;
}
