#include <stdio.h>
#include <stdlib.h>
#define USEREC 1

/*
  Scrivere un sottoprogramma che riceve come parametri una lista
  dinamica di interi ordinata in ordine crescente ed un valore intero.
  Il sottoprogramma inserisce il nuovo elemento nella lista
  preservando l'ordine crescente e restituisce la testa della lista al
  chiamante. Realizzare sia la versione iterativa che ricorsiva del
  sottoprogramma.
*/

typedef struct node_ {
  int num;
  struct node_ *next;
} node_t;

void display(node_t *h);
node_t* push(node_t *h, int n);
node_t* destroy(node_t *h);

node_t* addIncreasing_it(node_t *h, int n);
node_t* addIncreasing_rec(node_t *h, int n);

int main() {
  node_t *h;
  int n;

  h = NULL;

  printf("Lista: ");
  scanf("%d", &n);
  while (n > 0) {
    h = push(h, n);
    scanf("%d", &n);
  }

  printf("Numero: ");
  scanf("%d", &n);

  if (USEREC)
    h = addIncreasing_rec(h, n);
  else
    h = addIncreasing_it(h, n);

  display(h);

  h = destroy(h);

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

node_t* addIncreasing_it(node_t *h, int n) {
  node_t *curr, *prev, *tmp;

  for (
    curr = h, prev = NULL; 
    curr && !((!prev || n >= prev->num) && n <= curr->num); 
    prev = curr, curr = curr->next
  );

  tmp = malloc(sizeof(node_t));
  if (tmp) {
    tmp->num = n;
    tmp->next = curr;

    if (prev)
      prev->next = tmp;
    else
      h = tmp;
  } else
    printf("Errore allocazione.\n");

  return h;
}

node_t* addIncreasing_rec(node_t *h, int n) {
  node_t *tmp;

  if (!h || h->num > n) {
    tmp = malloc(sizeof(node_t));
    if (tmp) {
      tmp->num = n;
      tmp->next = h;
      h = tmp;
    } else 
      printf("Errore allocazione.\n");
  } else
    h->next = addIncreasing_rec(h->next, n);

  return h;
}