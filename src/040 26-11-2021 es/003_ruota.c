/*
  Da esame del 20/01/2020 della prof.ssa Cristiana Bolchini
  https://bolchini.faculty.polimi.it/exams/20200120.pdf
  -> Quesito 5
*/

typedef struct nodo_ {
  int num;
  struct nodo_ *next;
} nodo_t;

nodo_t *ruotasx(nodo_t *h);
nodo_t *ruotadx(nodo_t *h);
nodo_t *ruota(nodo_t *h, int dir);

nodo_t *ruota(nodo_t *h, int dir) {
  if (dir)
    h = ruotadx(h);
  else
    h = ruotasx(h);
  return h;
}

nodo_t *ruotadx(nodo_t *h) {
  nodo_t *curr, *tmp;

  if (h && h->next) {
    for (curr = h; curr->next->next; curr = curr->next)
      ;
    tmp = curr->next;

    curr->next = NULL;
    tmp->next = h;
    h = tmp;
  }

  return h;
}

nodo_t *routasx(nodo_t *h) {
  nodo_t *curr, *tmp;

  if (h && h->next) {
    tmp = h;
    h = h->next;
    tmp->next = NULL;

    for (curr = h; curr->next; curr = curr->next)
      ;
    curr->next = tmp;
  }

  return h;
}
