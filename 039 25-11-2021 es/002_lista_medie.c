#include <stdio.h>
#include <stdlib.h>

/*
  Utilizzando la definizione di tipo lista e i sottoprogrammi visti a
  lezione, scrivere un sottoprogramma listaMedie() che riceve in
  ingresso una lista l1 di numeri interi. Il sottoprogramma costruisce
  una nuova lista l2 in cui ogni elemento è calcolato come la media
  tra un valore di l1 ed il suo successivo. L'ultimo elemento della
  lista, per cui non esiste un elemento successivo, viene ricopiato
  nella nuova lista. Infine il sottoprogramma restituisce la nuova
  lista.
  Esempio: se l1 = 8 5 16 7 allora la nuova lista sarà: 6 10 11 7
*/

typedef struct node_ {
  int num;
  struct node_ *next;
} node_t;

void display(node_t *h);
node_t* push(node_t *h, int n);
node_t* destroy(node_t *h);

node_t* listaMedie(node_t *l1);

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

  l2 = listaMedie(l1);
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

node_t* listaMedie(node_t *l1) {
  node_t *l2, *prev, *curr;

  l2 = NULL;

  if (l1) {
    for (prev = l1, curr = l1->next; curr; prev = curr, curr = curr->next) {
      l2 = push(l2, (prev->num + curr->num)/2);
    }
    l2 = push(l2, prev->num);
  }

  return l2;
}
