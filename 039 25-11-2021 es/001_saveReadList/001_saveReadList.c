#include <stdio.h>
#include <stdlib.h>
#define MAXS 50

/*
  Scrivere un sottoprogramma che riceve come parametri una lista di
  interi ed una stringa che rappresenta il nome di un file. Il
  sottoprogramma apre in scrittura il file binario il cui nome è stato
  ricevuto come parametro e vi salva il contenuto della lista.

  Scrivere un sottoprogramma che riceve come parametro una stringa che
  rappresenta il nome di un file che contiene una sequenza di
  lunghezza indefinita di numeri interi. Il sottoprogramma apre in
  lettura il file binario e crea una nuova lista dinamica popolandola
  con il contenuto del file. Il sottoprogramma restituisce infine la
  testa della nuova lista creata.
*/

typedef struct node_ {
  int num;
  struct node_ *next;
} node_t;

void display(node_t *h);
node_t* push(node_t *h, int n);
node_t* destroy(node_t *h);

void saveList(node_t *h, char fn[]);
node_t* readList(char fn[]);

int main() {
  node_t *h, *res;
  char fn[MAXS+1];
  int n;

  h = NULL;

  printf("Lista: ");
  scanf("%d", &n);
  while (n > 0) {
    h = push(h, n);
    scanf("%d", &n);
  }

  printf("Nome file: ");
  scanf("%s", fn);

  saveList(h, fn);
  res = readList(fn);

  display(h);
  display(res);

  h = destroy(h);
  res = destroy(res);

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

void saveList(node_t *h, char fn[]) {
  FILE *fp;

  fp = fopen(fn, "wb");
  if (fp) {
    for (; h; h = h->next) {
      fwrite(&(h->num), sizeof(int), 1, fp);
    }

    fclose(fp);
  } else
    printf("Errore apertura.\n");
}

node_t* readList(char fn[]) {
  FILE *fp;
  node_t *h;
  int tmp;

  h = NULL;
  fp = fopen(fn, "rb");

  if (fp) {
    fread(&tmp, sizeof(int), 1, fp);

    while (!feof(fp)) {
      h = push(h, tmp);
      fread(&tmp, sizeof(int), 1, fp);
    }

    fclose(fp);
  } else
    printf("Errore apertura.\n");

  return h;
}