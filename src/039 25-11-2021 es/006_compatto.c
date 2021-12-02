#include <stdio.h>
#include <stdlib.h>

/*
  Definire un nuovo tipo di dato per lista dinamica chiamata
  nodo_compatto_t e contenente, oltre al puntatore next, due campi
  chiamati n e volte; il primo campo indica l'effettivo valore
  memorizzato nel nodo mentre il secondo quante volte compare quel
  valore.
  Scrivere un sottoprogramma che riceve come parametro una classica
  lista dinamica di interi e costruisce la corrispondente lista
  compatta.
  Se per esempio la lista in ingresso è: 4 2 3 2 2 4, la lista
  compatta sarà: (4,2) (2, 3) (3, 1). Infatti il valore 4 compare due
  volte nella lista di partenza, il valore 2 tre volte e il valore 3
  una volta.
*/

typedef struct node_ {
  int num;
  struct node_ *next;
} node_t;

typedef struct nodo_compatto_ {
  int n, volte;
  struct nodo_compatto_ *next;
} nodo_compatto_t;

void display(node_t *h);
node_t *push(node_t *h, int n);
node_t *destroy(node_t *h);

void displayCom(nodo_compatto_t *h);
nodo_compatto_t *pushCom(nodo_compatto_t *h, int n);
nodo_compatto_t *destroyCom(nodo_compatto_t *h);

nodo_compatto_t *compatto(node_t *l);

int main() {
  node_t *li;
  nodo_compatto_t *lc;
  int n;

  li = NULL;
  lc = NULL;

  printf("Lista: ");
  scanf("%d", &n);
  while (n) {
    li = push(li, n);
    scanf("%d", &n);
  }

  lc = compatto(li);
  display(li);
  displayCom(lc);

  li = destroy(li);
  lc = destroyCom(lc);

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

void displayCom(nodo_compatto_t *h) {
  for (; h; h = h->next)
    printf("(%d, %d) ", h->n, h->volte);
  printf("\n");
}
nodo_compatto_t *pushCom(nodo_compatto_t *h, int n) {
  nodo_compatto_t *tmp, *last;

  for (last = h; last && last->next; last = last->next)
    ;

  tmp = malloc(sizeof(nodo_compatto_t));
  if (tmp) {
    tmp->n = n;
    tmp->volte = 1;
    tmp->next = NULL; /* Always NULL */
    if (last)
      last->next = tmp;
    else
      h = tmp;
  } else
    printf("Errore allocazione.\n");

  return h;
}
nodo_compatto_t *destroyCom(nodo_compatto_t *h) {
  nodo_compatto_t *tmp;

  while (h) {
    tmp = h;
    h = h->next;
    free(tmp);
  }

  return h; /* Always NULL */
}

nodo_compatto_t *compatto(node_t *l) {
  nodo_compatto_t *h, *found;

  h = NULL;

  for (; l; l = l->next) {
    for (found = h; found && found->n != l->num; found = found->next)
      ;

    if (found)
      (found->volte)++;
    else
      h = pushCom(h, l->num);
  }

  return h;
}
