#include <stdio.h>
#define MINLENEX 5
#define MINNUM 2
#define MINOTH 1
#define FNIN "testo.txt"
#define FNOUT "risultato.txt"
#define MAXS 15

/*
  a) Scrivere una funzione analizzastringa (ed il relativo prototipo)
  che riceve come parametro una stringa. La funzione restituisce 1 se
  la stringa è lunga più di 5 caratteri e contiene almeno 2 cifre
  numeriche ed un carattere che non sia una cifra; in caso negativo la
  funzione restituisce 0.
  b) Scrivere un programma che apre in lettura un file di testo
  testo.txt contenente una serie di lunghezza indefinita di parole
  ciascuna lunga al massimo 15 caratteri ed in scrittura un secondo
  file risultato.txt. Il programma legge ciascuna parola contenuta in
  testo.txt e la scrive in risultato.txt soltanto se l'invocazione
  della funzione analizzastringa su di essa porta ad un risultato
  positivo (la funzione restituisce 1).
  Ad esempio, se il file contiene il seguente testo:
  Ciao45 baubau 2345678 esame2020 trallallero1 bimbumbam345 a234
  Il programma salverà in risultato.txt il seguente testo:
  Ciao45
  esame2020
  bimbumbam345
*/

int analizzastringa(char[]);

int main() {
  FILE *fpin, *fpout;
  char str[MAXS+1];

  fpin = fopen(FNIN, "r");
  fpout = fopen(FNOUT, "w");

  if (fpin && fpout) {
    fscanf(fpin, "%s", str);
    if (analizzastringa(str))
      fprintf(fpout, "%s\n", str);

    while (!feof(fpin)) {
      fscanf(fpin, "%s", str);
      if (analizzastringa(str))
        fprintf(fpout, "%s\n", str);
    }

    fclose(fpin);
    fclose(fpout);
  } else if (!fpin) {
    printf("Errore lettura.\n");
  } else if (!fpout) {
    printf("Errore scrittura.\n");
  }

  return 0;
}

int analizzastringa(char str[]) {
  int i, numbers;

  numbers = 0;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] >= '0' && str[i] <= '9')
      numbers++;
  }

  return i > MINLENEX 
    && numbers >= MINNUM 
    && (i-numbers) >= MINOTH;
}