#include <math.h>
#include <stdio.h>
#include <string.h>
/* Aggiungere -lm al comando gcc */

#define MAXS 30
#define MAXA 50

/*
  ES2 - Modificare il programma 2021-10-15-codice.c (gestione di un percorso)
  visto in aula aggiungendovi le seguenti due nuove funzionalità:
  7 - Ricerca di una località dato il nome. La funzionalità chiede all'utente il
    nome di una località (una stringa di al massimo 30 caratteri) e stampa a
    video i dati di tutte le località con quel dato nome. Si ricordi che per
    confrontare le stringhe si può usare la funzione strcmp() contenuta in
    string.h che riceve come parametri due stringhe e restituisce 0 se sono
    uguali.
  8 - Calcola cornice del percorso. La funzionalità calcola la cornice
    rettangolare sulla cartina che racchiude tutto il percorso e ne visualizza
    le coordinate dei due vertici in basso a sinistra ed in alto a destra.
    Visualizzare un apposito messaggio di errore nel caso il percorso sia vuoto.
    Rinumerare opportunamente l'opzione di uscita (che diventerà 9).
*/

#define INSERISCI 1
#define AGGIUNGI 2
#define CANCELLA 3
#define VISUALIZZA 4
#define LUNGHEZZA 5
#define COPPIAMAX 6
#define CERCA 7
#define CORNICE 8
#define USCITA 9

typedef struct {
  int x, y;
  char nome[MAXS + 1];
} localita_t;

typedef struct {
  localita_t loc[MAXA];
  int dim;
} percorso_t;

int main() {
  percorso_t l;
  int scelta, i, j, lung_quadrato;
  int i_cmax[MAXA][2], n_cmax;
  int minX, minY, maxX, maxY;
  float lung, tmp_lung;
  char ricerca[MAXS + 1];

  l.dim = 0;

  do {
    printf("\nMENU\n- %d: inserisci\n- %d: aggiungi\n- %d: cancella\n- %d: "
           "visualizza\n- %d: lunghezza\n- %d: distanza massima\n- %d: "
           "cerca\n- %d: cornice\n- %d: uscita\nCosa vuoi fare? ",
           INSERISCI, AGGIUNGI, CANCELLA, VISUALIZZA, LUNGHEZZA, COPPIAMAX,
           CERCA, CORNICE, USCITA);
    scanf("%d", &scelta);

    if (scelta == INSERISCI) {
      if (l.dim < MAXA) {
        printf("Inserisci i dati: ");

        scanf("%d %d %s", &l.loc[l.dim].x, &l.loc[l.dim].y, l.loc[l.dim].nome);
        l.dim++;
      } else
        printf("Memoria terminata.\n");
    } else if (scelta == AGGIUNGI) {
      if (l.dim < MAXA) {
        printf("Inserisci indice: ");
        scanf("%d", &i);

        if (i >= 0 && i < l.dim) {
          for (j = l.dim - 1; j >= i; j--)
            l.loc[j + i] = l.loc[j];

          printf("Inserisci i dati: ");
          scanf("%d %d %s", &l.loc[i].x, &l.loc[i].y, l.loc[i].nome);

          l.dim++;
        } else
          printf("Indice non valido.\n");
      } else
        printf("Memoria terminata.\n");
    } else if (scelta == CANCELLA) {
      printf("Inserisci indice: ");
      scanf("%d", &i);

      if (i >= 0 && i < l.dim) {
        for (; i < l.dim - 1; i++)
          l.loc[i] = l.loc[i + 1];
        l.dim--;
      } else
        printf("Indice non valido.\n");
    } else if (scelta == VISUALIZZA) {
      printf("Percorso:\n");
      for (i = 0; i < l.dim; i++)
        printf("%d: %d %d %s\n", i, l.loc[i].x, l.loc[i].y, l.loc[i].nome);
    } else if (scelta == LUNGHEZZA) {
      for (i = 0, lung = 0; i < l.dim - 1; i++) {
        lung_quadrato =
            (l.loc[i].x - l.loc[i + 1].x) * (l.loc[i].x - l.loc[i + 1].x) +
            (l.loc[i].y - l.loc[i + 1].y) * (l.loc[i].y - l.loc[i + 1].y);
        lung += sqrt(lung_quadrato);
      }
      printf("Lunghezza: %f\n", lung);
    } else if (scelta == COPPIAMAX) {
      lung = 0;
      n_cmax = 0;

      for (i = 0; i < l.dim; i++) {
        for (j = i + 1; j < l.dim; j++) {
          tmp_lung = (l.loc[i].x - l.loc[j].x) * (l.loc[i].x - l.loc[j].x) +
                     (l.loc[i].y - l.loc[j].y) * (l.loc[i].y - l.loc[j].y);
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
        printf("- %s <-> %s\n", l.loc[i_cmax[i][0]].nome,
               l.loc[i_cmax[i][1]].nome);
    } else if (scelta == CERCA) {
      printf("Nome da cercare: ");
      scanf("%s", ricerca);
      printf("Risultati:");
      for (i = 0, j = 0; i < l.dim; i++) {
        if (!strcmp(l.loc[i].nome, ricerca)) {
          printf("\n- %s (%d, %d)", l.loc[i].nome, l.loc[i].x, l.loc[i].y);
          j++;
        }
      }
      if (!j)
        printf(" nessun risultato.");
      printf("\n");
    } else if (scelta == CORNICE) {
      if (l.dim) {
        minX = l.loc[0].x;
        maxX = l.loc[0].x;
        minY = l.loc[0].y;
        maxY = l.loc[0].y;

        for (i = 1; i < l.dim; i++) {
          if (l.loc[i].x < minX)
            minX = l.loc[i].x;
          else if (l.loc[i].x > maxX)
            maxX = l.loc[i].x;

          if (l.loc[i].y < minY)
            minY = l.loc[i].y;
          else if (l.loc[i].y > maxY)
            maxY = l.loc[i].y;
        }

        printf("Cornice: (%d, %d) -> (%d, %d)", minX, minY, maxX, maxY);
      } else
        printf("Il percorso è vuoto.\n");
    } else if (scelta != USCITA) {
      printf("Scelta non valida!\n");
    }
  } while (scelta != USCITA);

  return 0;
}
