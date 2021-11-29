/*
  "Se non è definito il simbolo LISTA_H mantieni questo testo, altrimenti
  ignoralo." Questo permette al compilatore di evitare di importare la stessa
  libreria più volte, perché dopo la prima volta esiste già il simbolo LISTA_H.
  Il nome del simbolo è arbitrario, basta che sia unico.
*/
#ifndef LISTA_H
#define LISTA_H

/*
  Gli header contengono solamente le definizioni di strutture, tipi, prototipi
  etc., senza le implementazioni.
*/

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
