#include <stdio.h>
/* ! Includendo math.h dobbiamo aggiungere -lm al comando di gcc. */
#include <math.h>

#define MAXS 30
#define MAXA 50

/*
  Ristrutturare il programma interattivo che gestisce un percorso su
  uno spazio bidimensionale (2021-10-15.c) in una serie di
  sottoprogrammi, una per ciascuna funzionalità presentata nel menù.
  Ciascun sottoprogramma riceve come parametro passato per indirizzo
  la struttura dati che contiene la lista di località ed esegue le
  elaborazioni richieste dalla data funzionalità.
*/

#define INSERISCI 1
#define AGGIUNGI 2
#define CANCELLA 3
#define VISUALIZZA 4
#define LUNGHEZZA 5
#define COPPIAMAX 6
#define USCITA 7

typedef struct {
  int x, y;
  char nome[MAXS + 1];
} localita_t;

typedef struct {
  localita_t loc[MAXA];
  int dim;
} percorso_t;

void inserisci(percorso_t *l);
void aggiungi(percorso_t *l);
void cancella(percorso_t *l);
void visualizza(percorso_t *l);
void lunghezza(percorso_t *l);
void coppiaMax(percorso_t *l);

int main() {
  percorso_t l;
  int scelta;

  l.dim = 0;

  do {
    printf("\nMENU\n- %d: inserisci\n- %d: aggiungi\n- %d: cancella\n- %d: "
           "visualizza\n- %d: lunghezza\n- %d: distanza massima\n- %d: "
           "uscita\nCosa vuoi fare? ",
           INSERISCI, AGGIUNGI, CANCELLA, VISUALIZZA, LUNGHEZZA, COPPIAMAX,
           USCITA);
    scanf("%d", &scelta);

    switch (scelta) {
    case INSERISCI:
      inserisci(&l);
      break;

    case AGGIUNGI:
      aggiungi(&l);
      break;

    case CANCELLA:
      cancella(&l);
      break;

    case VISUALIZZA:
      visualizza(&l);
      break;

    case LUNGHEZZA:
      lunghezza(&l);
      break;

    case COPPIAMAX:
      coppiaMax(&l);
      break;

    default:
      if (scelta != USCITA)
        printf("Scelta non valida!\n");
      break;
    }
  } while (scelta != USCITA);

  return 0;
}

void inserisci(percorso_t *l) {
  if (l->dim < MAXA) {
    printf("Inserisci i dati: ");

    scanf("%d %d %s", &l->loc[l->dim].x, &l->loc[l->dim].y,
          l->loc[l->dim].nome);
    (l->dim)++;
  } else
    printf("Memoria terminata.\n");
}

void aggiungi(percorso_t *l) {
  int i, j;

  if (l->dim < MAXA) {
    printf("Inserisci indice: ");
    scanf("%d", &i);

    if (i >= 0 && i < l->dim) {
      for (j = l->dim - 1; j >= i; j--)
        l->loc[j + 1] = l->loc[j];

      printf("Inserisci i dati: ");
      scanf("%d %d %s", &l->loc[i].x, &l->loc[i].y, l->loc[i].nome);

      (l->dim)++;
    } else
      printf("Indice non valido.\n");
  } else
    printf("Memoria terminata.\n");
}

void cancella(percorso_t *l) {
  int i, j;

  printf("Inserisci indice: ");
  scanf("%d", &i);

  if (i >= 0 && i < l->dim) {
    for (j = i; j < l->dim - 1; j++)
      l->loc[j] = l->loc[j + i];
    (l->dim)--;
  } else
    printf("Indice non valido.\n");
}

void visualizza(percorso_t *l) {
  int i;

  printf("Percorso:\n");
  for (i = 0; i < l->dim; i++)
    printf("%d: %d %d %s\n", i, l->loc[i].x, l->loc[i].y, l->loc[i].nome);
}

void lunghezza(percorso_t *l) {
  int i, lung_quadrato;
  float lung;

  for (i = 0, lung = 0; i < l->dim - 1; i++) {
    lung_quadrato =
        (l->loc[i].x - l->loc[i + 1].x) * (l->loc[i].x - l->loc[i + 1].x) +
        (l->loc[i].y - l->loc[i + 1].y) * (l->loc[i].y - l->loc[i + 1].y);
    lung += sqrt(lung_quadrato);
  }
  printf("Lunghezza: %f\n", lung);
}

void coppiaMax(percorso_t *l) {
  int lung, i, j, n_cmax, i_cmax[MAXA][2];
  float tmp_lung;

  lung = 0;
  n_cmax = 0;

  for (i = 0; i < l->dim; i++) {
    for (j = i + 1; j < l->dim; j++) {
      tmp_lung = (l->loc[i].x - l->loc[j].x) * (l->loc[i].x - l->loc[j].x) +
                 (l->loc[i].y - l->loc[j].y) * (l->loc[i].y - l->loc[j].y);
      tmp_lung = sqrt(tmp_lung);

      if (tmp_lung > lung) {
        lung = tmp_lung;
        i_cmax[0][0] = i;
        i_cmax[0][1] = j;
        n_cmax = 1;
      } else if (tmp_lung == lung) {
        i_cmax[n_cmax][0] = i;
        i_cmax[n_cmax][1] = j;
        n_cmax++;
      }
    }
  }

  printf("Lunghezza massima: %f\nCoppie:\n", lung);
  for (i = 0; i < n_cmax; i++)
    printf("- %s <-> %s\n", l->loc[i_cmax[i][0]].nome,
           l->loc[i_cmax[i][1]].nome);
}
