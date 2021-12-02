#include <stdio.h>
#include <stdlib.h>

/*
  Utilizzando la definizione di tipo lista e i sottoprogrammi visti a
  lezione, scrivere un sottoprogramma che riceve come parametro una
  lista l1 contenente una serie di numeri interi e due puntatori a
  lista lp e ln passati per indirizzo e che non puntano ad alcun
  indirizzo valido. Il sottoprogramma costruisce due nuove liste,
  assegnandole a lp e ln, la prima contenente i soli elementi positivi
  di l1 e la seconda i restanti elementi neutri o negativi. La
  funzione restituisce entrambe le liste al chiamante.
*/

typedef struct node_ {
  int num;
  struct node_ *next;
} node_t;

void display(node_t *h);
node_t *push(node_t *h, int n);
node_t *destroy(node_t *h);

void creaListe(node_t *l1, node_t **lp, node_t **ln);

int main() {
  node_t *l1, *lp, *ln;
  int n;

  l1 = NULL;

  printf("Lista: ");
  scanf("%d", &n);
  while (n) {
    l1 = push(l1, n);
    scanf("%d", &n);
  }
  l1 = push(l1, 0);

  creaListe(l1, &lp, &ln);
  display(l1);
  display(lp);
  display(ln);

  l1 = destroy(l1);
  lp = destroy(lp);
  ln = destroy(ln);

  return 0;
}

void display(node_t *h) {
  for (; h; h = h->next)
    printf("%d ", h->num);
  printf("\n");
}
node_t *push(node_t *h, int n) {
  node_t *tmp, *last;

  for (last = h; last && last->next; last = last->next)
    ;

  tmp = malloc(sizeof(node_t));
  if (tmp) {
    tmp->num = n;
    tmp->next = NULL; /* Always NULL */
    if (last)
      last->next = tmp;
    else
      h = tmp;
  } else
    printf("Errore allocazione.\n");

  return h;
}
node_t *destroy(node_t *h) {
  node_t *tmp;

  while (h) {
    tmp = h;
    h = h->next;
    free(tmp);
  }

  return h; /* Always NULL */
}

void creaListe(node_t *l1, node_t **lp, node_t **ln) {
  *lp = NULL;
  *ln = NULL;

  for (; l1; l1 = l1->next) {
    if (l1->num > 0)
      *lp = push(*lp, l1->num);
    else
      *ln = push(*ln, l1->num);
  }
}
