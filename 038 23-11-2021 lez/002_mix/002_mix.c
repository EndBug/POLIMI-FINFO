#include <stdio.h>
#include <stdlib.h>

/*
  Scrivere un programma che riceve come argomenti da riga di comando
  il nome di un file di testo contenente una sequenza di lunghezza
  indefinita di numeri interi ed un valore intero n. Il programma
  legge dal file di testo i valori e stampa a video in ordine inverso
  solo i valori inferiori ad n. Gestire opportunamente tutti i casi di
  errore. Se necessario si supponga di avere a disposizione della
  struttura dati e dei sottoprogrammi per la gestione delle liste
  dinamiche.
*/

typedef struct nodo_ {
  int num;
  struct nodo_ *next;
} nodo_t;

nodo_t* inserisciTesta(nodo_t *h, int n);
nodo_t* distruggi(nodo_t *h);
void visualizza(nodo_t *h);

int main(int argc, char *argv[]) {
  FILE *fp;
  int n, tmp;
  nodo_t *h;

  if (argc == 3) {
    n = atoi(argv[2]);

    fp = fopen(argv[1], "r");

    if (fp) {
      h = NULL;

      fscanf(fp, "%d", &tmp);
      while (!feof(fp)) {
        if (tmp < n)
          h = inserisciTesta(h, tmp);
        fscanf(fp, "%d", &tmp);
      }
      fclose(fp);

      visualizza(h);

      h = distruggi(h);
    } else 
      printf("Errore apertura.\n");
  } else
    printf("Errore argomenti.\n");

  return 0;
}

nodo_t* inserisciTesta(nodo_t *h, int n) {
  nodo_t *tmp;
  tmp = malloc(sizeof(nodo_t));

  if (tmp) {
    tmp->num = n;
    tmp->next = h;
    h = tmp;
  } else 
    printf("Errore allocazione.\n");

  return h;
}

nodo_t* distruggi(nodo_t *h) {
  nodo_t *tmp;

  while (h) {
    tmp = h;
    h = h->next;
    free(tmp);
  }

  return h;
}

void visualizza(nodo_t *h) {
  for (; h; h = h->next)
    printf("%d ", h->num);
  printf("\n");
}