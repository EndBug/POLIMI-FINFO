#include <stdio.h>
#include <stdlib.h>
#define USERIC 0

/*
  Dopo aver definito un nuovo tipo di dato per memorizzare una lista
  dinamica di valori interi, realizzare i seguenti sottoprogrammi
  nelle versioni sia iterativa che ricorsiva.
  * Scrivere un sottoprogramma che riceve una testa di una lista
  dinamica di interi e ne visualizza il contenuto.
  * Scrivere un sottoprogramma che riceve una testa di una lista
  dinamica di interi e ne restituisce la lunghezza.
  * Scrivere un sottoprogramma che riceve una testa di una lista
  dinamica di interi ed un intero. Il sottoprogramma restituisce 1 se
  il numero è presente nella lista altrimenti 0.
  * Scrivere un sottoprogramma che riceve una testa di una lista
  dinamica di interi ed un intero. Il sottoprogramma restituisce il
  puntatore al primo nodo della lista avente valore pari al numero
  ricevuto come parametro; se il numero non è presente restituisce
  NULL.
  * Scrivere un sottoprogramma che riceve una testa di una lista
  dinamica di interi ed un intero. Il sottoprogramma inserisce in
  testa il numero ricevuto come parametro e restituisce la nuova testa
  della lista.
  * Scrivere un sottoprogramma che riceve una testa di una lista
  dinamica di interi ed un intero. Il sottoprogramma inserisce in coda
  il numero ricevuto come parametro e restituisce la testa della
  lista.
  * Scrivere un sottoprogramma che riceve una testa di una lista
  dinamica di interi. Il sottoprogramma cancella dalla lista il primo
  nodo, se presente, e restituisce la nuova testa della lista.
  * Scrivere un sottoprogramma che riceve una testa di una lista
  dinamica di interi. Il sottoprogramma cancella dalla lista l'ultimo
  nodo, se presente, e restituisce la nuova testa della lista.
  * Scrivere un sottoprogramma che riceve una testa di una lista
  dinamica di interi ed un intero. Il sottoprogramma cancella dalla
  lista la prima istanza del numero intero ricevuto come parametro, se
  presente, e restituisce la testa della lista.
  * Scrivere un sottoprogramma che riceve una testa di una lista
  dinamica e cancella tutti gli elementi presenti.

  Supponendo di avere a disposizione una struttura dati per liste
  dinamiche e una serie di funzioni standard di manipolazione delle
  liste (come quelle definite sopra), scrivere un programma che
  acquisisce da tastiera due sequenze di lunghezza indefinita di
  numeri interi ciascuna terminata da uno 0 (che non fa parte della
  sequenza); ciascuna sequenza va memorizzata in una lista. Il
  programma calcola l'intersezione delle due sequenze rimuovendo
  eventuali duplicati, salvando il risultato in una terza lista e
  visualizzandolo. Il programma libera tutta la memoria allocata prima
  di terminare.
*/

typedef struct nodo_ {
  int num;
  struct nodo_ *next;
} nodo_t;

int main_it();
int main_ric();

void visualizza_ric(nodo_t *h);
void visualizza_it(nodo_t *h);
int lunghezza_ric(nodo_t *h);
int lunghezza_it(nodo_t *h);
int incluso_ric(nodo_t *h, int n);
int incluso_it(nodo_t *h, int n);
nodo_t *inserisciTesta(nodo_t *h, int n);
nodo_t *inserisciCoda_ric(nodo_t *h, int n);
nodo_t *inserisciCoda_it(nodo_t *h, int n);
nodo_t *rimuovi_ric(nodo_t *h, int n);
nodo_t *rimuovi_it(nodo_t *h, int n);
nodo_t *distruggi_ric(nodo_t *h);
nodo_t *distruggi_it(nodo_t *h);
nodo_t *rimuoviTutti_it(nodo_t *h, int n);

int main() {
  if (USERIC)
    return main_ric();
  return main_it();
}

int main_it() {
  nodo_t *h1, *h2, *h3, *curr;
  int n;

  h1 = NULL;
  h2 = NULL;
  h3 = NULL;

  scanf("%d", &n);
  while (n) {
    h1 = inserisciCoda_it(h1, n);
    scanf("%d", &n);
  }
  scanf("%d", &n);
  while (n) {
    h2 = inserisciCoda_it(h2, n);
    scanf("%d", &n);
  }

  for (curr = h1; curr; curr = curr->next) {
    if (!incluso_it(h3, curr->num) && incluso_it(h2, curr->num))
      h3 = inserisciCoda_it(h3, curr->num);
  }

  visualizza_it(h3);
  h1 = distruggi_it(h1);
  h2 = distruggi_it(h2);
  h3 = distruggi_it(h3);

  return 0;
}

int main_ric() {
  nodo_t *h1, *h2, *h3, *curr;
  int n;

  h1 = NULL;
  h2 = NULL;
  h3 = NULL;

  scanf("%d", &n);
  while (n) {
    h1 = inserisciCoda_it(h1, n);
    scanf("%d", &n);
  }
  scanf("%d", &n);
  while (n) {
    h2 = inserisciCoda_it(h2, n);
    scanf("%d", &n);
  }

  for (curr = h1; curr; curr = curr->next) {
    if (!incluso_it(h3, curr->num) && incluso_it(h2, curr->num))
      h3 = inserisciCoda_it(h3, curr->num);
  }

  visualizza_it(h3);
  h1 = distruggi_it(h1);
  h2 = distruggi_it(h2);
  h3 = distruggi_it(h3);

  return 0;
}

void visualizza_ric(nodo_t *h) {
  if (h) {
    printf("%d ", h->num);
    visualizza_ric(h->next);
  } else {
    printf("\n");
  }
}
void visualizza_it(nodo_t *h) {
  /*
    Dato che ogni modifica al parametro non influisce sul valore nel chiamante,
    possiamo direttamente utilizzare il parametro senza dichiarare una variabile
    tmp.
  */
  for (; h; h = h->next)
    printf("%d ", h->num);
  printf("\n");
}

int lunghezza_ric(nodo_t *h) {
  if (h == NULL)
    return 0;

  return 1 + lunghezza_ric(h->next);
}
int lunghezza_it(nodo_t *h) {
  int count;
  for (count = 0; h; h = h->next)
    count++;
  return count;
}

int incluso_ric(nodo_t *h, int n) {
  if (!h || h->num == n)
    return h != NULL;

  return incluso_ric(h->next, n);
}
int incluso_it(nodo_t *h, int n) {
  for (; h && h->num != n; h = h->next)
    ;

  return h != NULL;
}

/* Non esiste la versione ricorsiva perché non andiamo ad iterare sulla lista.
 */
nodo_t *inserisciTesta(nodo_t *h, int n) {
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

nodo_t *inserisciCoda_ric(nodo_t *h, int n) {
  nodo_t *tmp;

  if (h == NULL)
    return inserisciTesta(h, n);

  h->next = inserisciCoda_ric(h->next, n);
  return h;
}
nodo_t *inserisciCoda_it(nodo_t *h, int n) {
  nodo_t *tmp, *prec;

  tmp = malloc(sizeof(nodo_t));

  if (tmp) {
    tmp->num = n;
    tmp->next = NULL;
    if (h == NULL) {
      h = tmp;
    } else {
      /* Qua non posso usare h perché poi devo ritornarlo. */
      for (prec = h; prec->next != NULL; prec = prec->next)
        ;
      prec->next = tmp;
    }
  } else
    printf("Errore allocazione.\n");

  return h;
}

nodo_t *rimuovi_ric(nodo_t *h, int n) {
  nodo_t *tmp;

  if (!h)
    return NULL;
  if (h->num == n) {
    tmp = h;
    h = h->next;
    free(tmp);
    return h;
  }

  h->next = rimuovi_ric(h->next, n);
  return h;
}
nodo_t *rimuovi_it(nodo_t *h, int n) {
  nodo_t *curr, *prec;

  curr = h;
  prec = NULL;

  while (curr && curr->num != n) {
    prec = curr;
    curr = curr->next;
  }

  if (curr) {
    if (prec)
      prec->next = curr->next;
    else
      h = curr->next;
    free(curr);
  }

  return h;
}

nodo_t *distruggi_ric(nodo_t *h) {
  if (!h)
    return NULL;

  distruggi_ric(h->next);
  free(h);
  return NULL;
}
nodo_t *distruggi_it(nodo_t *h) {
  nodo_t *tmp;

  while (h) {
    tmp = h;
    h = h->next;
    free(tmp);
  }

  /* Sarà sempre NULL */
  return h;
}

nodo_t *rimuoviTutti_it(nodo_t *h, int n) {
  nodo_t *curr, *prec, *canc;

  curr = h;
  prec = NULL;

  while (curr) {
    if (curr->num == n) {
      canc = curr;
      curr = curr->next;
      if (!prec)
        h = curr;
      else
        prec->next = curr;
      free(canc);
    } else {
      prec = curr;
      curr = curr->next;
    }
  }

  return h;
}
