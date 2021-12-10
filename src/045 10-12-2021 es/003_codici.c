/*
  Da esame del 01/09/2020 della prof.ssa Cristiana Bolchini
  https://bolchini.faculty.polimi.it/exams/20200120.pdf
  -> Quesito 5
*/

typedef struct elem_ {
  int n;
  struct elem_ *next;
} elem_t;

elem_t *trovaMancanti(elem_t *h) {
  int min, max, i;
  elem_t *mancanti, *tmp;

  mancanti = NULL;

  if (h) {
    for (tmp = h->next, min = h->n, max = h->n; tmp; tmp = tmp->next) {
      if (max < h->n)
        max = h->n;
      else if (min > h->n)
        min = h->n;
    }

    for (i = min + 1; i < max; i++) {
      if (!exists(h, i))
        /*
          Potremmo utilizzare inserisci_inc, però sarebbero dei calcoli in più,
          perché noi stiamo già iterando in ordine crescente.
        */
        mancanti = append(mancanti, i);
    }
  }

  return mancanti;
}
