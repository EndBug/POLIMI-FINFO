#include "lista.h"
#include <stdio.h>
#define FN "serie.txt"

/* Consegna trascritta nel file consegna.txt */

nodo_t *estrai(nodo_t *l1, int dispari);
int uguali(nodo_t *l1, nodo_t *l2);
int conta(nodo_t *l, int n);
int stessoContenuto(nodo_t *l1, nodo_t *l2);
nodo_t *unisci(nodo_t *l1, nodo_t *l2);

int main() {
  FILE *fp;
  nodo_t *lf, *lp, *ld, *u;
  int tmp;

  fp = fopen(FN, "r");

  if (fp) {
    fscanf(fp, "%d", &tmp);

    lf = NULL;
    while (!feof(fp)) {
      lf = inserisciInCoda(lf, tmp);
      fscanf(fp, "%d", &tmp);
    }

    lp = estrai(lf, 0);
    ld = estrai(lf, 1);

    tmp = uguali(lp, ld);
    if (!tmp) {
      tmp = stessoContenuto(lp, ld);
      if (tmp)
        printf("lp e ld hanno lo stesso contenuto, in ordine diverso.\n");
      else
        printf("lp e ld hanno contenuti diversi.\n");
    } else
      printf("lp e ld sono uguali per contenuto e ordine.\n");

    u = unisci(lp, ld);

    printf("\n");
    visualizza(lf);
    visualizza(lp);
    visualizza(ld);
    visualizza(u);

    lf = distruggi(lf);
    lp = distruggi(lp);
    ld = distruggi(ld);
    u = distruggi(u);

    fclose(fp);
  } else
    printf("Errore apertura file.\n");

  return 0;
}

nodo_t *estrai(nodo_t *l1, int dispari) {
  nodo_t *l2;
  int i;

  l2 = NULL;
  for (i = 0; l1; l1 = l1->next, i++) {
    if (i % 2 == dispari)
      l2 = inserisciInCoda(l2, l1->num);
  }

  return l2;
}

int uguali(nodo_t *l1, nodo_t *l2) {
  int res;

  for (res = 1; l1 && l2 && res; l1 = l1->next, l2 = l2->next) {
    if (l1->num != l2->num)
      res = 0;
  }
  res = res && l1 == l2;

  return res;
}

int conta(nodo_t *l, int n) {
  int count;

  for (count = 0; l; l = l->next) {
    if (l->num == n)
      count++;
  }

  return count;
}

int stessoContenuto(nodo_t *l1, nodo_t *l2) {
  int res;
  nodo_t *curr;

  res = lunghezza(l1) == lunghezza(l2);

  for (curr = l1; res && curr; curr = curr->next) {
    if (conta(l1, curr->num) != conta(l2, curr->num))
      res = 0;
  }

  return res;
}

nodo_t *unisci(nodo_t *l1, nodo_t *l2) {
  nodo_t *u;

  u = NULL;

  for (; l1; l1 = l1->next) {
    u = inserisciInCoda(u, l1->num);
  }
  for (; l2; l2 = l2->next) {
    u = inserisciInCoda(u, l2->num);
  }

  return u;
}
