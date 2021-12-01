#include <stdio.h>
#define N_OGGETTI 100
#define MAX_STR 100
#define PESO_CONTAINER 100
#define DIM 10

/*
  Si considerino le seguenti strutture dati che rappresentano delle
  scatole da spedire. Si noti che una scatola può contenere un numero
  variabile di oggetti e per ogni oggetto si specifica il peso per
  unità ed il numero di unità contenute nella scatola.
    #define N_OGGETTI 100
    #define MAX_STR 100
    #define PESO_CONTAINER 100
    typedef struct{
      char descrizione[MAX_STR+1];
      float peso_per_unita;
      int quanti;
      int codice;
    } oggetto_t;
    typedef struct{
      oggetto_t oggetti[N_OGGETTI];
      int n_oggetti;
      char descrizione[MAX_STR+1];
      int codice;
    } scatola_t;
  a) Realizzare un sottoprogramma che riceve come parametri un array
  di scatole sc, un valore in virgola mobile che rappresenta un peso,
  e qualsiasi altro parametro ritenuto strettamente necessario.
  Analizzando le scatole nell'ordine in cui si trovano nell'array, il
  sottoprogramma valuta e restituisce il numero di scatole che può
  essere immagazzinato in un container avente una capienza pari al
  peso ricevuto come ultimo parametro.
  b) Scrivere un programma che chiede all'utente i dati contenuti in
  dieci scatole; per ciascuna scatola il programma chiede prima quanti
  oggetti sono contenuti e poi i dati di ciascun oggetto. In seguito
  il programma invoca il sottoprogramma sopra definito specificando il
  valore 100.0 come capienza del container e visualizza il risultato a
  video.
*/

typedef struct {
  char descrizione[MAX_STR + 1];
  float peso_per_unita;
  int quanti;
  int codice;
} oggetto_t;

typedef struct {
  oggetto_t oggetti[N_OGGETTI];
  int n_oggetti;
  char descrizione[MAX_STR + 1];
  int codice;
} scatola_t;

int controllaPeso(scatola_t[], int, float);

int main() {
  scatola_t sc[DIM];
  int i, j, res;

  for (i = 0; i < DIM; i++) {
    printf("Scatola %d:\n- Codice: ", i);
    scanf("%d", &sc[i].codice);
    printf("- Descrizione: ");
    scanf("%s", sc[i].descrizione);
    printf("- Numero di oggetti: ");
    scanf("%d", &sc[i].n_oggetti);
    for (j = 0; j < sc[i].n_oggetti; j++) {
      printf("  Oggetto %d:\n  - Codice: ", j);
      scanf("%d", &sc[i].oggetti[j].codice);
      printf("  - Descrizione: ");
      scanf("%s", sc[i].oggetti[j].descrizione);
      printf("  - Peso per unità: ");
      scanf("%f", &sc[i].oggetti[j].peso_per_unita);
      printf("  - Quantità: ");
      scanf("%d", &sc[i].oggetti[j].quanti);
    }
  }

  res = controllaPeso(sc, DIM, PESO_CONTAINER);

  printf("\nScatole che può trasportare: %d\n", res);

  return 0;
}

int controllaPeso(scatola_t sc[], int n, float peso) {
  int i, j, res;
  float acc;

  for (i = 0, acc = 0, res = -1; i < n && res < 0; i++) {
    for (j = 0; j < sc[i].n_oggetti && acc <= peso; j++) {
      acc += sc[i].oggetti[j].peso_per_unita * sc[i].oggetti[j].quanti;
    }
    if (acc > peso)
      res = i;
  }

  if (res < 0)
    return n;
  else
    return res;
}
