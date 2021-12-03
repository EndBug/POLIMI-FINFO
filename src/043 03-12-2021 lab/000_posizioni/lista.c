#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

/* Inserisce un nuovo numero in coda alla lista */
nodo_t *inserisciInCoda(nodo_t *lista, int num) {
  nodo_t *prec;
  nodo_t *tmp;
  tmp = malloc(sizeof(nodo_t));
  if (tmp != NULL) {
    tmp->next = NULL;
    tmp->num = num;
    if (lista == NULL)
      lista = tmp;
    else {
      for (prec = lista; prec->next != NULL; prec = prec->next)
        ;
      prec->next = tmp;
    }
  } else
    printf("Memoria esaurita!\n");
  return lista;
}

/* Inserisce un nuovo numero in testa alla lista */
nodo_t *inserisciInTesta(nodo_t *lista, int num) {
  nodo_t *tmp;
  tmp = malloc(sizeof(nodo_t));
  if (tmp != NULL) {
    tmp->num = num;
    tmp->next = lista;
    lista = tmp;
  } else
    printf("Memoria esaurita!\n");
  return lista;
}

/*
  Inserisce un numero nella lista rispettando un ordine crescente
  (affinchè l'ordine crescente sia preservato durante l'inserimenti, si assume
  che la lista di partenza sia ordinata in tale ordine)
*/
nodo_t *inserisciInOrdine(nodo_t *lista, int num) {
  nodo_t *tmp, *prec, *curr;
  tmp = malloc(sizeof(nodo_t));
  if (tmp) {
    tmp->num = num;
    tmp->next = NULL;
    if (lista && num > lista->num) {
      for (prec = lista, curr = lista->next; curr && num > curr->num;
           curr = curr->next, prec = prec->next)
        ;
      tmp->next = curr;
      prec->next = tmp;
      /*
        CODICE EQUIVALENTE CON UN SOLO PUNTATORE
        for (prec = lista; prec->next && num > prec->next->num;
             prec = prec->next)
          ;
        tmp->next = prec->next;
        prec->next = tmp;
      */
    } else { /* Caso lista vuota o il primo elemento è maggiore del nuovo */
      tmp->next = lista;
      lista = tmp;
    }
  } else
    printf("Memoria esaurita!\n");
  return lista;
}

/*
  Rimuove dalla lista la prima occorrenza di un numero specificato come
  parametro, se presente
*/
nodo_t *rimuovi(nodo_t *lista, int num) {
  nodo_t *curr, *prec;
  curr = lista;
  prec = NULL;
  while (curr && curr->num != num) {
    prec = curr;
    curr = curr->next;
  }
  if (curr) {
    if (prec != NULL)
      prec->next = curr->next;
    else
      lista = curr->next;
    free(curr);
  }
  return lista;
}

/*
  Rimuove dalla lista tutte le occorrenze di un numero specificato come
  parametro, se presente
*/
nodo_t *rimuoviTutti(nodo_t *lista, int num) {
  nodo_t *curr, *prec, *canc;

  curr = lista;
  prec = NULL;
  while (curr) {
    if (curr->num == num) {
      canc = curr;
      curr = curr->next;
      if (prec != NULL)
        prec->next = curr;
      else
        lista = curr;
      free(canc);
    } else {
      prec = curr;
      curr = curr->next;
    }
  }
  return lista;
}

/* Libera la memoria allocata per una lista */
nodo_t *distruggi(nodo_t *lista) {
  nodo_t *tmp;
  while (lista != NULL) {
    tmp = lista;
    lista = lista->next;
    free(tmp);
  }
  return NULL;
}

/* Visualizza i numeri contenuti nella lista */
void visualizza(nodo_t *lista) {
  printf("Elementi nella lista: ");
  while (lista != NULL) {
    printf("%d ", lista->num);
    lista = lista->next;
  }
  printf("\n");
}

/* Restituisce 1 se un dato numero è presente nella lista altrimenti 0 */
int esisteElemento(nodo_t *lista, int num) {
  for (; lista && lista->num != num; lista = lista->next)
    ;
  return (lista != NULL);
}

/*
  Restituisce il puntatore al primo nodo contenente il
  numero specificato come parametro, altrimenti NULL
*/
nodo_t *cercaElemento(nodo_t *lista, int num) {
  for (; lista && lista->num != num; lista = lista->next)
    ;
  return lista;
}

/* Calcola e restituisce la lunghezza della lista */
int lunghezza(nodo_t *lista) {
  int i;
  for (i = 0; lista; i++, lista = lista->next)
    ;
  return i;
}
