#include <stdio.h>
#define N 10
#define FN "ciao.txt" /* Costante per il filename */

/*
  Scrivere un programma che apre in scrittura un file di testo
  "ciao.txt" e vi scrive le cifre da '0' a '9'
  Scrivere un programma apre in lettura un file "ciao.txt". Il
  programma legge la sequenza di caratteri salvati nel file (la cui
  lunghezza non è nota a priori) e la visualizza.
*/

/*
  Esistono due tipi di file:
  - Testuale -> stesso algoritmo della scanf e printf, l'interfaccia non è con
    l'utente ma con il disco.
    Esempio: file gestiti dall'IDE, main.c, ...
  - Binario -> Informazioni riversate direttamente sul disco, file binario, è
    necessario conoscere come sono stati scritti i dati.
    Esempio: .docx
*/

/*
  Lui non ha scritto dei sottoprogrammi ha messo tutto orribilmente nel main,
  ha diviso in due file scrivi e leggi, io gli passo come parametro il percorso.
*/
void scrivi(char path[]);
void leggi(char path[]);

int main() {
  scrivi(FN);
  leggi(FN);
  return 0;
}

void scrivi(char path[]) {
  /*
    fp sigla per file pointer, la gestione della struttura FILE e i metodi
    utili li troviamo nella libreria stdio.h
  */
  FILE *fp;
  char c;

  /*
    Utilizzo il sottoprogramma per aprire un flusso di scrittura con il file.
    Parametri: il nome del file e la modalità
  */
  fp = fopen(path, "w");
  /*
    Sistema operativo tiene traccia dei programmi aperti.
    La "w" come modalità crea da 0 un file, se esiste già lo sovrascrive.
    L'operazione di apertura di un file non va sempre a buon fine, fopen
    restituisce NULL se l'operazione fallisce.
  */
  if (fp != NULL) { /* <=> if (fp) */
    for (c = '0'; c <= '9'; c++)
      /*
        Stessa filosofia della printf, ha solo in più come primo parametro
        per il puntatore al file.
        Volendo si può utilizzare per scrivere direttamente a video, sullo
        stout.
      */
      fprintf(fp, "%c ", c);

    /*
      I file si chiudono!!!! anche se vengono già chiusi dal sistema operativo.
    */
    fclose(fp);
  } else {
    printf("Errore di apertura del file\n");
  }
}

void leggi(char path[]) {
  FILE *fp;
  int i;
  char c;

  fp = fopen(path, "r"); /* Apro in lettura. */

  if (fp) {
    /*
      La sequenza è di tipo indefinito, dobbiamo leggere i caratteri uno alla
      volta fino alla lettura di una sequenza non valda.
      Esiste un metodo feof (found end of file) che restituisce 1 quando si
      supera la fine del file, leggo finchè non raggiungo la fine del file.
      Prima però devo leggere almeno una volta il file.
      Fondamentale leggere il file prima di utilizzare la feof (altrimenti il
      valore restituito sarà probabilmente vero e se il file è vuoto è un
      assurdo), leggo, verifico, stampo.
    */
    fscanf(fp, "%c ", &c);

    /*
      La feof restituisce un valore accurato solo se viene eseguita dopo la
      fscanf, cioè dopo la prima lettura, continuo ad eseguire finchè non
      raggiungo la fine del file.
    */
    while (!feof(fp)) {
      /*
        Il sistema operativo tiene nella tabella in cui vengono gestiti i file
        la posizione all'interno del file, il puntatore è solo un riferimento,
        a noi della gestione del file non interessa la feof.
      */
      printf("%c ", c);
      /* Attenzione alla doppia scanf, errore comune in esame. */
      fscanf(fp, "%c ", &c);
    }
    printf("%c \n", c);
    fclose(fp); /* Chiudo il file */
  } else {
    printf("Errore di apertura del file\n");
  }
}
