#include <stdio.h>
#include <stdlib.h>

/*
  Utilizzando la definizione di tipo lista e i sottoprogrammi visti a
  lezione, scrivere un sottoprogramma che riceve una lista dinamica di
  numeri l1 e da questa costruisce una nuova lista l2 come segue: gli
  elementi di l1 vengono presi a coppie e viene inserito prima il
  secondo elemento della coppia e poi il primo. Nel caso la lista l1
  contenga un numero dispari di elementi, l'ultimo elemento viene
  semplicemente copiato alla fine di l2. Esempio:
  l1 = 1 2 3 4 5 6 7
  l2 = 2 1 4 3 6 5 7
*/

typedef struct node_ {
  int num;
  struct node_ *next;
} node_t;

void display(node_t *h);
node_t* push(node_t *h, int n);
node_t* destroy(node_t *h);

node_t* invertiCoppie(node_t *l1);

int main() {
  node_t *l1, *l2;
  int n;

  l1 = NULL;

  printf("Lista: ");
  scanf("%d", &n);
  while (n > 0) {
    l1 = push(l1, n);
    scanf("%d", &n);
  }

  l2 = invertiCoppie(l1);
  display(l1);
  display(l2);

  l1 = destroy(l1);
  l2 = destroy(l2);

  return 0;
}

void display(node_t *h) {
  for (; h; h = h->next)
    printf("%d ", h->num);
  printf("\n");
}
node_t* push(node_t *h, int n) {
  node_t *tmp, *last;

  for (last = h; last && last->next; last = last->next);

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
node_t* destroy(node_t *h) {
  node_t *tmp;

  while (h) {
    tmp = h;
    h = h->next;
    free(tmp);
  }

  return h; /* Always NULL */
}

node_t* invertiCoppie(node_t *l1) {
  node_t *l2, *e1, *e2;

  l2 = NULL;
  e1 = NULL;
  e2 = NULL;

  e1 = l1;
  if (l1) {
    l1 = l1->next;
    e2 = l1;
  }

  while (e1 && e2) {
    l2 = push(l2, e2->num);
    l2 = push(l2, e1->num);

    l1 = l1->next;
    e1 = l1;
    if (l1) {
      l1 = l1->next;
      e2 = l1;
    }
  }

  if (e1)
    l2 = push(l2, e1->num);

  return l2;
}
