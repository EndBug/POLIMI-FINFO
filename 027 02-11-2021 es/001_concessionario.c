#include <stdio.h>
#define MAX_S 30
#define MAX_TARGA 7
#define MAX_AUTOMOBILI 50
#define N_CONC 3

/*
Definire le strutture dati per rappresentare un concessionario di
automobili. Il concessionario è descritto in termini di un codice
numerico, i dati di un gestore ed una lista di massimo 50
automobili. Il gestore è a sua volta descritto in termini di una
partita IVA, un nome ed un cognome, tre stringhe di al massimo 30
caratteri ciascuna. L'automobile infine è descritta in termini di un
modello (una stringa di al massimo 30 caratteri), una targa (una
stringa di al massimo 7 caratteri) e mese ed anno di
immatricolazione (due interi).

Realizzare un sottoprogramma che riceve come parametro un array di
tipo concessionario, un intero AA che rappresenta un anno, e
qualsiasi altro parametro ritenuto strettamente necessario. Per ogni
concessionario il sottoprogramma stampa a video modello, targa e
mese (in numero) delle auto immatricolate nell'anno AA. Il report
mostrato dovrà avere il seguente formato:

Conc. 0, codice 12345: gestore Paolo Rossi
Immatricolazioni 2015:
* mese 9: Punto, MI80980
* mese 6: Marea, TO12567

Conc. 1, codice 23456: gestore Luca Bianchi
Immatricolazioni 2015:
* mese 2: Panda, VE85980

Conc. 2, codice 23556: gestore Franco Verdi
Immatricolazioni 2015:
NESSUNA

Scrivere un programma che chiede all'utente i dati di 10
concessionari ed invoca la funzione sopra definita per stampare la
reportistica.
*/

typedef struct {
  char modello[MAX_S+1], targa[MAX_TARGA+1];
  int mese, anno;
} automobile_t;

typedef struct {
  char IVA[MAX_S+1], nome[MAX_S+1], cognome[MAX_S+1];
} gestore_t;

typedef struct {
  int codice;
  gestore_t gestore;
  automobile_t automobili[MAX_AUTOMOBILI];
  int nAuto;
} concessionario_t;

void stampaAA(concessionario_t[], int, int);

int main() {
  int i, j, AA;
  concessionario_t concessionari[N_CONC];

  for (i = 0; i < N_CONC; i++) {
    printf("Concessionario %d.\nCodice, numero di automobili: ", i);
    scanf(
      "%d %d", 
      &concessionari[i].codice, 
      &concessionari[i].nAuto
    );

    printf("Gestore (nome, cognome, IVA): ");
    scanf(
      "%s %s %s",
      concessionari[i].gestore.nome, 
      concessionari[i].gestore.cognome, 
      concessionari[i].gestore.IVA
    );

    for (j = 0; j < concessionari[i].nAuto; j++) {
      printf("Auto %d (modello, targa, mese, anno): ", j);
      scanf(
        "%s %s %d %d",
        concessionari[i].automobili[j].modello,
        concessionari[i].automobili[j].targa,
        &concessionari[i].automobili[j].mese,
        &concessionari[i].automobili[j].anno
      );
    }

    printf("\n");
  }

  printf("Anno da visualizzare: ");
  scanf("%d", &AA);

  stampaAA(concessionari, N_CONC, AA);



  return 0;
}

void stampaAA(concessionario_t concessionari[], int nConcessionari, int AA) {
  int i, j, almenoUna;

  for (i = 0; i < nConcessionari; i++) {
    almenoUna = 0;

    printf(
      "Conc. %d, codice %d: gestore %s %s\n", 
      i, 
      concessionari[i].codice, 
      concessionari[i].gestore.nome, 
      concessionari[i].gestore.cognome
    );
    printf("Immatricolazioni %d:\n", AA);

    for (j = 0; j < concessionari[i].nAuto; j++) {
      if (concessionari[i].automobili[j].anno == AA) {
        almenoUna = 1;
        printf(
          "* mese %d: %s, %s\n", 
          concessionari[i].automobili[j].mese, 
          concessionari[i].automobili[j].modello, 
          concessionari[i].automobili[j].targa
        );
      }
    }

    if (!almenoUna)
      printf("NESSUNA\n");
    printf("\n");
  }
}