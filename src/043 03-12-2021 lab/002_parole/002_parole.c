#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXS 20

/*
  ES3.
  Definire un tipo di dato per una lista dinamica di parole, dove ciascuna
  parola è lunga al massimo 20 caratteri. Realizzare i sottoprogrammi standard
  per la gestione di una lista di parole, in particolare per l'inserimento in
  coda di un nuovo elemento, la visualizzazione del contenuto della lista, il
  calcolo della lunghezza della lista e la sua distruzione. Scrivere un
  programma che riceve come argomenti i nomi di due file di testo, ciascuno
  contenente una sequenza di lunghezza indefinita di parole di al massimo 20
  caratteri. Il programma carica le due sequenze in due liste dinamiche s1 e s2.
  In seguito, il sottoprogramma verifica se s1 è sottosequenza di s2 o,
  viceversa se s2 è sottosequenza di s1, e stampa a video i risultati dei test
  (1 o 0); si noti che se almeno una delle due liste è vuota l'esito è negativo.
  Prima di terminare il programma libera tutta la memoria allocata. Visualizzare
  opportuni messaggi nel caso di errore (es: argomenti mancanti, memoria non
  allocata correttamente, file non aperto, ...). Si consiglia di suddividere
  opportunamente il programma in sottoprogrammi.
*/

typedef struct nodo_ {
  char str[MAXS + 1];
  struct nodo_ *next;
} nodo_t;

nodo_t *inserisciInCoda(nodo_t *h, char *str);
void visualizza(nodo_t *h);
int lunghezza(nodo_t *h);
nodo_t *distruggi(nodo_t *h);
nodo_t *acquisisci(FILE *fp);
int verificaSubSeq(nodo_t *h, nodo_t *sub);

int main(int argc, char **argv) {
  FILE *fp1, *fp2;
  nodo_t *s1, *s2;
  int tmp;

  if (argc == 3) {
    fp1 = fopen(argv[1], "r");

    if (fp1) {
      fp2 = fopen(argv[2], "r");

      if (fp2) {
        s1 = acquisisci(fp1);
        s2 = acquisisci(fp2);

        printf("s1: ");
        visualizza(s1);
        printf("s2: ");
        visualizza(s2);

        tmp = verificaSubSeq(s1, s2);
        printf("s2 subseq di s1: %d\n", tmp);
        tmp = verificaSubSeq(s2, s1);
        printf("s1 subseq di s2: %d\n", tmp);

        s1 = distruggi(s1);
        s2 = distruggi(s2);

        fclose(fp2);
      } else
        printf("Errore apertura file 2.\n");

      fclose(fp1);
    } else
      printf("Errore apertura file 1.\n");
  } else
    printf("Errore argomenti.\n");

  return 0;
}

nodo_t *inserisciInCoda(nodo_t *h, char *str) {
  nodo_t *tmp, *last;

  tmp = malloc(sizeof(nodo_t));

  if (tmp) {
    strcpy(tmp->str, str);
    tmp->next = NULL;

    if (h) {
      for (last = h; last && last->next; last = last->next)
        ;
      last->next = tmp;
    } else
      h = tmp;
  } else
    printf("Errore allocazione.\n");

  return h;
}

void visualizza(nodo_t *h) {
  for (; h; h = h->next)
    printf("%s ", h->str);
  printf("\n");
}

int lunghezza(nodo_t *h) {
  int count;

  for (count = 0; h; h = h->next)
    count++;

  return count;
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

nodo_t *acquisisci(FILE *fp) {
  nodo_t *h;
  char str[MAXS + 1];

  h = NULL;

  fscanf(fp, "%s", str);
  while (!feof(fp)) {
    h = inserisciInCoda(h, str);
    fscanf(fp, "%s", str);
  }

  return h;
}

int verificaSubSeq(nodo_t *h, nodo_t *sub) {
  int valid, res, oneIsEmpty;
  nodo_t *tmpH, *tmpSub;

  oneIsEmpty = !(lunghezza(h) && lunghezza(sub));

  for (res = 0; h && !res && !oneIsEmpty; h = h->next) {
    for (valid = 1, tmpH = h, tmpSub = sub; valid && tmpH && tmpSub;
         tmpH = tmpH->next, tmpSub = tmpSub->next) {
      if (strcmp(tmpH->str, tmpSub->str))
        valid = 0;
    }

    if (valid && !tmpSub)
      res = 1;
  }

  return res;
}
