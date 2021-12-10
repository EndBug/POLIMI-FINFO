#include "lista.h"
#include <stdio.h>

/*
  ES4. Considerando la struttura dati ed i sottoprogrammi contenuti nei file
  lista.c e lista.h, implementare un sottoprogramma che riceve come parametro
  una lista dinamica di interi l. Il sottoprogramma crea e restituisce una nuova
  lista contenente soltanto quegli elementi di l strettamente minori di tutti i
  relativi precedenti in l (il primo elemento se esiste va comunque aggiunto
  alla nuova lista poiché non ha precedenti). Esempio: se il sottoprogramma
  riceve in ingresso

  l1 = 8 -> 5 -> 8 -> 2 -> 12 -> 3 -> 2 -> 1

  dovrà ritornare la lista

  l2 = 8 -> 5 -> 2 -> 1

  Scrivere un programma che chiede all'utente una lista di interi terminata dal
  valore 0, che non fa parte della lista. Il programma invoca il sottoprogramma
  sopra definito e visualizza il risultato. Gestire opportunamente il rilascio
  di tutte le risorse allocate.
*/

nodo_t *decrescente(nodo_t *l1);

int main() {
  int tmp;
  nodo_t *l1, *l2;

  l1 = NULL;
  scanf("%d", &tmp);
  while (tmp) {
    l1 = inserisciInCoda(l1, tmp);
    scanf("%d", &tmp);
  }

  l2 = decrescente(l1);
  visualizza(l2);

  distruggiLista(l1);
  distruggiLista(l2);

  return 0;
}

nodo_t *decrescente(nodo_t *l1) {
  nodo_t *l2, *tmp;
  int valid;

  l2 = NULL;

  if (l1) {
    l2 = inserisciInCoda(l2, l1->num);
    l1 = l1->next;

    for (; l1; l1 = l1->next) {
      for (valid = 1, tmp = l2; tmp && valid; tmp = tmp->next) {
        if (tmp->num <= l1->num)
          valid = 0;
      }
      if (valid)
        l2 = inserisciInCoda(l2, l1->num);
    }
  }

  return l2;
}
