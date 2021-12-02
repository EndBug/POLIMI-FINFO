#include <stdio.h>
#include <stdlib.h>

/*
  Utilizzando la definizione di tipo lista e i sottoprogrammi visti a
  lezione, scrivere un sottoprogramma che ricevute in ingresso due
  liste, ne restituisce una nuova creata alternando gli elementi delle
  due liste, e poi mettendo in coda tutti quelli della lista più
  lunga. Ad esempio, se le liste in ingresso sono fatte come segue,
  1 3 5 7 9 11
  2 4 6 8
  la lista creata sarà fatta come segue
  1 2 3 4 5 6 7 8 9 11
*/

typedef struct node_ {
  int num;
  struct node_ *next;
} node_t;

void display(node_t *h);
node_t *push(node_t *h, int n);
node_t *destroy(node_t *h);

node_t *unisci(node_t *l1, node_t *l2);

int main() {
  node_t *l1, *l2, *lu;
  int n;

  l1 = NULL;
  l2 = NULL;

  printf("Lista 1: ");
  scanf("%d", &n);
  while (n) {
    l1 = push(l1, n);
    scanf("%d", &n);
  }
  printf("Lista 2: ");
  scanf("%d", &n);
  while (n) {
    l2 = push(l2, n);
    scanf("%d", &n);
  }

  lu = unisci(l1, l2);
  display(l1);
  display(l2);
  display(lu);

  l1 = destroy(l1);
  l2 = destroy(l2);
  lu = destroy(lu);

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

node_t *unisci(node_t *l1, node_t *l2) {
  node_t *res;

  res = NULL;

  while (l1 || l2) {
    if (l1) {
      res = push(res, l1->num);
      l1 = l1->next;
    }
    if (l2) {
      res = push(res, l2->num);
      l2 = l2->next;
    }
  }

  return res;
}
