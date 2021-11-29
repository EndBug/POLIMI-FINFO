/*
  Da esame del 18-02-2019 della prof.ssa Cristiana Bolchini
  https://bolchini.faculty.polimi.it/exams/20190218.pdf
  -> Quesito 5
*/

#include <stdio.h>
#include <stdlib.h>
#define BASE 10

typedef struct nodo_ {
  int num;
  struct nodo_ *next;
} nodo_t;

void visualizza(nodo_t *h) {
  /* 
    Dato che ogni modifica al parametro non influisce sul valore nel chiamante, 
    possiamo direttamente utilizzare il parametro senza dichiarare una variabile tmp.
  */
  for (; h; h = h->next)
    printf("%d ", h->num);
  printf("\n");
}
nodo_t* inserisciTesta(nodo_t *h, int n) {
  nodo_t *tmp;
  tmp = malloc(sizeof(nodo_t));

  if (tmp) {
    tmp->num = n;
    tmp->next = h;
    h = tmp;
  } else 
    printf("Errore allocazione.\n");

  return h;
}
nodo_t* inserisciCoda(nodo_t *h, int n) {
  nodo_t *tmp;

  if (h == NULL)
    return inserisciTesta(h, n);

  h->next = inserisciCoda(h->next, n);
  return h;
}
nodo_t* distruggi(nodo_t *h) {
  nodo_t *tmp;

  while (h) {
    tmp = h;
    h = h->next;
    free(tmp);
  }

  /* Sarà sempre NULL */
  return h;
}

nodo_t* int2list(int n);

int main(int argc, char* argv[]) {
  int n;
  nodo_t *res;

  if (argc == 2) {
    n = atoi(argv[1]);
    res = int2list(n);
    visualizza(res);
    distruggi(res);
  } else
    printf("Errore argomenti.\n");
}

nodo_t* int2list(int n) {
  nodo_t *h;
  int i, c, neg;

  h = NULL;

  neg = n < 0;
  if (neg)
    n = -n;

  while (n) {
    c = n % BASE;
    n /= BASE;

    for (i = 0; i < c; i++) {
      if (neg)
        h = inserisciCoda(h, c);
      else
        h = inserisciTesta(h, c);
    }
  }

  return h;
}