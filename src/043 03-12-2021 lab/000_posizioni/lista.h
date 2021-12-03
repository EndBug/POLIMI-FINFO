#ifndef LISTA_H
#define LISTA_H

/* Definizione della struttura per la lista concatenata */
typedef struct nodo_ {
  int num;
  struct nodo_ *next;
} nodo_t;

/* Prototipi delle funzioni */
nodo_t *inserisciInCoda(nodo_t *, int);
nodo_t *inserisciInTesta(nodo_t *, int);
nodo_t *inserisciInOrdine(nodo_t *testa, int n);
nodo_t *rimuovi(nodo_t *, int);
nodo_t *rimuoviTutti(nodo_t *, int);
nodo_t *distruggi(nodo_t *);
void visualizza(nodo_t *);
int esisteElemento(nodo_t *, int);
nodo_t *cercaElemento(nodo_t *, int);
int lunghezza(nodo_t *);

#endif
