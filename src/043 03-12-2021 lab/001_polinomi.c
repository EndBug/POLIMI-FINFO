#include <stdio.h>
#include <stdlib.h>

/*
  ES2.
  Definire un nuovo tipo di dato per una lista concatenata che permetta di
  memorizzare un polinomio; ciascun nodo della lista memorizzerà un monomio in
  termini di due interi che rappresentano il grado e il coefficiente di un dato
  monomio.
  Scrivere un programma che chiede all'utente i dati di due polinomi.
  L'acquisizione di ciascun polinomio termina quando l'utente inserisce i dati 0
  0 (che non andrà aggiunta alla lista) ed inoltre va prestata attenzione al
  fatto che una lista non può contenere due monomi con stesso grado; il
  programma deve prevenire tale inserimento errato nella lista visualizzando
  anche un apposito messaggio di errore. Si consiglia di organizzare ciascuna
  lista ordinando i monomi in ordine decrescente del grado. In seguito il
  programma esegue il prodotto e la somma tra i due polinomi salvando il
  risultato in due nuove liste. Attenzione al fatto che il prodotto tra due
  monomi può generare un monomio di grado già presente nella lista risultato (e
  quindi ne va soltanto aggiornato il coefficiente) o un nuovo monomio (che va
  quindi aggiunto alla lista). Il programma visualizza infine le quattro liste
  e, prima di terminare, rilascia tutta la memoria allocata. Si consiglia di
  strutturare il programma in vari sottoprogrammi.
*/

typedef struct nodo_ {
  int grado, coeff;
  struct nodo_ *next;
} nodo_t;

nodo_t *acquisisci();
int esisteGrado(nodo_t *h, int grado);
nodo_t *aggiungiInOrdine(nodo_t *h, int coeff, int grado);
nodo_t *sommaPolinomi(nodo_t *p1, nodo_t *p2);
nodo_t *sommaMonomio(nodo_t *h, int coeff, int grado);
nodo_t *moltiplicaPolinomi(nodo_t *p1, nodo_t *p2);
void visualizza(nodo_t *h);
nodo_t *distruggi(nodo_t *h);

int main() {
  nodo_t *a, *b, *somma, *prodotto;

  a = acquisisci();
  b = acquisisci();

  visualizza(a);
  visualizza(b);

  somma = sommaPolinomi(a, b);
  prodotto = moltiplicaPolinomi(a, b);

  visualizza(somma);
  visualizza(prodotto);

  a = distruggi(a);
  b = distruggi(b);
  somma = distruggi(somma);
  prodotto = distruggi(prodotto);

  return 0;
}

nodo_t *acquisisci() {
  nodo_t *h;
  int c, g;

  h = NULL;

  scanf("%d %d", &c, &g);

  while (c || g) {
    h = aggiungiInOrdine(h, c, g);
    scanf("%d %d", &c, &g);
  }

  return h;
}

int esisteGrado(nodo_t *h, int grado) {
  int res;
  for (res = 0; h && !res; h = h->next) {
    if (h->grado == grado)
      res = 1;
  }
  return res;
}

nodo_t *aggiungiInOrdine(nodo_t *h, int coeff, int grado) {
  nodo_t *tmp, *curr;

  if (!esisteGrado(h, grado)) {
    tmp = malloc(sizeof(nodo_t));

    if (tmp) {
      for (curr = h; curr && curr->next && curr->next->grado > grado;
           curr = curr->next)
        ;

      tmp->coeff = coeff;
      tmp->grado = grado;

      if (h) {
        tmp->next = curr->next;
        curr->next = tmp;
      } else {
        tmp->next = NULL;
        h = tmp;
      }
    } else
      printf("Errore allocazione.\n");
  } else
    printf("Errore: esiste già un monomio con questo grado.\n");

  return h;
}

nodo_t *sommaPolinomi(nodo_t *p1, nodo_t *p2) {
  nodo_t *res;

  res = NULL;
  for (; p1; p1 = p1->next)
    res = sommaMonomio(res, p1->coeff, p1->grado);
  for (; p2; p2 = p2->next)
    res = sommaMonomio(res, p2->coeff, p2->grado);

  return res;
}

nodo_t *sommaMonomio(nodo_t *h, int coeff, int grado) {
  nodo_t *tmp;

  if (esisteGrado(h, grado)) {
    for (tmp = h; tmp && tmp->grado != grado; tmp = tmp->next)
      ;

    (tmp->coeff) += coeff;
  } else
    h = aggiungiInOrdine(h, coeff, grado);

  return h;
}

nodo_t *moltiplicaPolinomi(nodo_t *p1, nodo_t *p2) {
  nodo_t *res, *tmp;

  res = NULL;
  for (; p1; p1 = p1->next) {
    for (tmp = p2; tmp; tmp = tmp->next)
      res = sommaMonomio(res, (p1->coeff) * (tmp->coeff),
                         (p1->grado) + (tmp->grado));
  }

  return res;
}

void visualizza(nodo_t *h) {
  for (; h; h = h->next)
    printf("%dx^%d ", h->coeff, h->grado);
  printf("\n");
}

nodo_t *distruggi(nodo_t *h) {
  nodo_t *tmp;

  while (h) {
    tmp = h;
    h = h->next;
    free(tmp);
  }

  return NULL;
}
