#include <stdio.h>
#define MAXPATH 30

/*
  Scrivere un programma che apre in scrittura un file di testo il cui
  nome, di al massimo 30 caratteri, è chiesto all'utente. In seguito,
  il programma chiede all'utente quanti valori interi vuole acquisire
  da tastiera, e poi procede con l'acquisizione da tastiera della
  serie di numeri ed il loro salvataggio nel file
*/

/*
  Variante particolare
  Anche qui lui ha messo tutto orribilmente nel main e ha diviso leggi e scrivi in due file
*/

void getNumELements(int *n);
void getFileName(char path[]);
void scrivi(char file[], int n);
void leggi(char file[]);
void leggi2(char file[], int n);

int main () {
  int n; /* # di valori da acquisire */
  char path[MAXPATH+1]; /* lui l'ha chiamato fn (sta per filename) */

  getFileName(path);
  getNumELements(&n);
  scrivi(path, n);
  leggi(path);
  leggi2(path, n);

  return 0;
}

void getFileName(char path[]) {
  printf("Inserire il nome del file: ");
  scanf("%s", path);
}

void getNumELements(int *n) {
  printf("Inserire il numero di elementi: ");
  scanf("%d", n);
}

void scrivi(char file[], int n) {
  FILE *fp;
  int i, a;

  fp = fopen(file, "w");

  if (fp) {
    for (i = 0; i < n; i++) { /* so quanti valori scrivere */
      scanf("%d", &a);
      fprintf(fp, "%d ", a);
    }
    fclose(fp);
  } else {
    printf("file non trovato\n");
  }
}

void leggi(char file[]) {
  FILE *fp;
  int i;
  int a;

  fp = fopen(file, "r");

  if (fp) {
    fscanf(fp, "%d", &a);

    while (!feof(fp)) {
      printf("%d ", a);
      fscanf(fp, "%d", &a);
    }
    printf("\n");
    fclose(fp);
    /*
      Ogni volta che leggo/scrivo un char, leggo o e scrivo un byte. Se scrivo o 
      leggo un intero quando leggo/scrivo avviene un'interpretazione, lo spazio 
      funge da separatore.
      IMPORTANTE: abbiamo inserito uno spazio anche dopo l'ultimo caratttere che 
      abbiamo scritto (vedere riga 40), se lo togliessimo l'ultimo carattere non 
      verrebbe stampato l'ultimo spazio.
      Durante la fscanf viene scartato ogni spazio e ci si ferma prima del prossimo 
      spazio. Se non c'è lo spazio leggo lo spazio prima dell'ultimo numero inserito, 
      il numero viene inserito in a, ma siccome viene settata la feof = 1 poichè 
      non trovo uno spazio allora non viene stampato.
    */
  } else {
    printf("Errore di apertura del file\n");
  }
}

/*
  Se non mi appoggio alla feof, per completezza, Miele utilizza la feof e si 
  assume che il file sia ben formato.
*/
void leggi2(char file[], int n) {
  FILE *fp;
  int i;
  int a, res;

  fp = fopen(file, "r");

  if (fp) {
    res = fscanf(fp, "%d", &a);
    while (res > 0) {
      printf("%d ", a);
      res = fscanf(fp, "%d", &a); /* restituisce -1 se viene quando siamo alla EOF. */
    }
    printf("\n");
    fclose(fp);
  } else {
    printf("Errore di apertura del file\n");
  }
}




