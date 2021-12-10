#include <stdio.h>

/*
  ES2. Si considerino le seguenti strutture dati che permettono di rappresentare
  un componente di un mobile Ikea (per esempio: vite, pannello, anta, ...), un
  magazzino di componenti e le istruzioni per costruire un mobile (per esempio:
  cucina, armadio, ...).

  a) Scrivere un sottoprogramma che riceve come parametri un magazzino di
  componenti MAG, un manuale di istruzioni MAN ed un numero intero X. Il
  sottoprogramma verifica se è possibile costruire X mobili relativi al manuale
  MAN ricevuto come parametro e prelevando i componenti dal magazzino MAG; in
  caso affermativo il sottoprogramma restituisce 1 altrimenti 0.

  b) Scrivere un sottoprogramma che riceve come parametri il nome di un file
  binario ed un magazzino di componenti (passato per indirizzo). Il
  sottoprogramma legge le informazioni del magazzino contenute nel file e le
  salva nel parametro passato per indirizzo. Nel caso di errore di accesso al
  file il sottoprogramma inizializza il magazzino con un numero di componenti
  pari a zero e visualizza un messaggio di errore.

  c) Scrivere un sottoprogramma che riceve come parametri il nome di un file
  binario ed un manuale di istruzioni (passato per indirizzo). Il sottoprogramma
  legge le informazioni del manuale contenute nel file e le salva nel parametro
  passato per indirizzo. Nel caso di errore di accesso al file il sottoprogramma
  inizializza il manuale con un numero di componenti richiesti pari a zero e
  visualizza un messaggio di errore.

  d) Scrivere un sottoprogramma che riceve come parametri il nome di un file di
  testo e un magazzino. Il sottoprogramma salva nel file di testo un report con
  il contenuto del magazzino. Nel caso di errore di accesso al file il
  sottoprogramma stampa un messaggio di errore.

  e) Scrivere un sottoprogramma che riceve come parametri il nome di un file di
  testo e un manuale di istruzioni. Il sottoprogramma salva nel file di testo un
  report con il contenuto del manuale di istruzioni. Nel caso di errore di
  accesso al file il sottoprogramma stampa un messaggio di errore.

  d) Scrivere un programma che riceve come argomenti i nomi di due file binari,
  contenenti rispettivamente i dati di un libretto di istruzioni (una variabile
  di tipo istruzioni_t) e di un magazzino (una variabile di tipo magazzino_t),
  un numero N ed i nomi di due file di testo da creare. Mediante l'ausilio dei
  sottoprogrammi sopra definiti, il programma legge dai file i dati salvandoli
  in due variabili di tipo istruzioni_t e magazzino_t, verifica se con i mezzi
  contenuti nel magazzino è possibile è possibile costruire N mobili seguendo le
  istruzioni fornite e visualizza il risultato a video. Infine, il programma
  salva in due file di testo il contenuto del magazzino e del manuale di
  istruzioni.

  Come test, forniamo i file istrN.bin, magN.bin, con N=1,2,3. Qui di seguito
  mostriamo gli output a video del programma (oltre alla creazione dei due
  report di testo che viene omessa).

  ./ikea istr1.bin mag1.bin 1 istr.txt mag.txt
  Output: 1
  ./ikea istr1.bin mag1.bin 2 istr.txt mag.txt
  Output: 0
  ./ikea istr2.bin mag2.bin 0 istr.txt mag.txt
  Output: 1
  ./ikea istr2.bin mag2.bin 1 istr.txt mag.txt
  Output: 0
  ./ikea istr3.bin mag3.bin 3 istr.txt mag.txt
  Output: 1
  ./ikea istr3.bin mag3.bin 4 istr.txt mag.txt
  Output: 0
  ./ikea istr2.bin mag3.bin 0 istr.txt mag.txt
  Output: 0*

  * Il testo in realtà non dà indicazioni specifiche su come trattare il caso
  N=0. Io ho assumo che la funzione verifica ritorni 1 quando si vogliono
  construire 0 mobili, anche quando magazzini e istruzioni non sono compatibili
  (dato che nella realtà ogni magazzino contiene almeno 0 unità di qualsiasi
  componente esistente).
*/

#define MAXS 100
#define MAXC 200

typedef struct {
  int codice;
  char nome[MAXS + 1];
  int quantita;
} componente_t;

typedef struct {
  char nome[MAXS + 1];
  char indirizzo[MAXS + 1];
  componente_t componenti[MAXC];
  int n_componenti;
} magazzino_t;

typedef struct {
  int codice;
  char descrizione[MAXS + 1];
  float costo;
  componente_t componenti[MAXC];
  int n_componenti;
} istruzioni_t;

int verifica(magazzino_t MAG, istruzioni_t MAN, int X);
void caricaMagazzino(char *fn, magazzino_t *mag);
void caricaManuale(char *fn, istruzioni_t *man);
void reportMagazzino(char *fn, magazzino_t mag);
void reportManuale(char *fn, istruzioni_t man);

int main(int argc, char *argv[]) {
  magazzino_t mag;
  istruzioni_t man;

  if (argc == 6) {
    caricaManuale(argv[1], &man);
    caricaMagazzino(argv[2], &mag);

    printf("%d\n", verifica(mag, man, atoi(argv[3])));

    reportManuale(argv[4], man);
    reportMagazzino(argv[5], mag);
  } else
    printf("Errore argomenti.\n");

  return 0;
}

int verifica(magazzino_t MAG, istruzioni_t MAN, int X) {
  int res, i, j, found;

  for (i = 0, res = 1; i < MAN.n_componenti && res; i++) {
    for (j = 0, found = 0; j < MAG.n_componenti && !found; j++) {
      if (MAG.componenti[j].codice == MAN.componenti[i].codice) {
        found = 1;
        if (MAG.componenti[j].quantita < MAN.componenti[i].quantita * X)
          res = 0;
      }
    }
  }

  return res;
}

void caricaMagazzino(char *fn, magazzino_t *mag) {
  FILE *fp;

  fp = fopen(fn, "rb");

  if (fp) {
    fread(mag, sizeof(magazzino_t), 1, fp);
    fclose(fp);
  } else {
    mag->n_componenti = 0;
    printf("Errore lettura magazzino.\n");
  }
}

void caricaManuale(char *fn, istruzioni_t *man) {
  FILE *fp;

  fp = fopen(fn, "rb");

  if (fp) {
    fread(man, sizeof(istruzioni_t), 1, fp);
    fclose(fp);
  } else {
    man->n_componenti = 0;
    printf("Errore lettura manuale.\n");
  }
}

void reportMagazzino(char *fn, magazzino_t mag) {
  FILE *fp;
  int i;

  fp = fopen(fn, "w");

  if (fp) {
    for (i = 0; i < mag.n_componenti; i++) {
      fprintf(fp, "- Codice: %d\n  Nome: %s\n  Quantità: %d\n",
              mag.componenti[i].codice, mag.componenti[i].nome,
              mag.componenti[i].quantita);
    }

    fclose(fp);
  } else
    printf("Errore scrittura magazzino.\n");
}

void reportManuale(char *fn, istruzioni_t man) {
  FILE *fp;
  int i;

  fp = fopen(fn, "w");

  if (fp) {
    for (i = 0; i < man.n_componenti; i++) {
      fprintf(fp, "- Codice: %d\n  Nome: %s\n  Quantità: %d\n",
              man.componenti[i].codice, man.componenti[i].nome,
              man.componenti[i].quantita);
    }

    fclose(fp);
  } else
    printf("Errore scrittura manuale.\n");
}
