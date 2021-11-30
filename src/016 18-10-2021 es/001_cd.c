#include <stdio.h>
#include <string.h>
#define MAX_CD 100
#define MAX_S 30

/*
  Si vuole realizzare un programma per la gestione di un archivio di
  CD musicali (al massimo 100). Ogni CD è caratterizzato da un titolo
  ed un autore (entrambe stringhe di al massimo 30 caratteri), un anno
  di pubblicazione, il numero di tracce, la durata complessiva (in
  termini di ore, minuti, secondi); inoltre si vuole memorizzare anche
  il prezzo del cd (un valore float). Definire un tipo di dato per
  rappresentare l'archivio di CD. In seguito scrivere un programma che
  chiede all'utente prima il numero di CD da inserire e poi i dati di
  ciascun CD (assumendo che l'utente inserisca correttamente i dati).
  Il programma visualizza i dati del cd di durata massima; se sono
  presenti più cd di stessa durata massima il programma visualizzerà i
  dati del primo di essi. VARIANTE: il programma visualizza i dati di
  tutti i CD di durata massima, se ne sono stati trovati più di uno.
  Il programma chiede in seguito il nome di un autore e visualizza i
  titoli di tutti i CD pubblicati da questo. Infine il programma
  visualizza l'autore che ha pubblicato più CD (se più di con lo
  stesso numero massimo di CD, si visualizzi il primo).
*/

typedef struct {
  int h, m, s;
} durata_t;

typedef struct {
  char titolo[MAX_S], autore[MAX_S];
  int anno, tracce;
  float prezzo;
  durata_t durata;
} cd_t;

typedef struct {
  cd_t cd[MAX_CD];
  int len;
} archivio_t;

typedef struct {
  char autore[MAX_S];
  int n;
} el_class_t;

typedef struct {
  el_class_t autori[MAX_CD];
  int len;
} classifica_t;

int main() {
  int i, j, tmpA, tmpB;
  archivio_t archivio, max_durata;
  char aut[MAX_S];
  classifica_t classifica;

  printf("Numero di CD: ");
  scanf("%d", &archivio.len);

  for (i = 0; i < archivio.len; i++) {
    printf("%d) Titolo: ", i + 1);
    scanf(" %[^\n]", archivio.cd[i].titolo);

    printf("   Autore: ");
    scanf(" %[^\n]", archivio.cd[i].autore);

    printf("   Anno: ");
    scanf("%d", &archivio.cd[i].anno);

    printf("   Tracce: ");
    scanf("%d", &archivio.cd[i].tracce);

    printf("   Durata (h m s): ");
    scanf("%d %d %d", &archivio.cd[i].durata.h, &archivio.cd[i].durata.m,
          &archivio.cd[i].durata.s);

    printf("   Prezzo: ");
    scanf("%f", &archivio.cd[i].prezzo);
  }

  max_durata.cd[0] = archivio.cd[0];
  max_durata.len = 1;
  for (i = 1; i < archivio.len; i++) {
    tmpA = (archivio.cd[i].durata.h * 60 + archivio.cd[i].durata.m) * 60 +
           archivio.cd[i].durata.s;
    tmpB = (max_durata.cd[0].durata.h * 60 + max_durata.cd[0].durata.m) * 60 +
           max_durata.cd[0].durata.s;

    if (tmpA > tmpB) {
      max_durata.cd[0] = archivio.cd[i];
      max_durata.len = 1;
    } else if (tmpA == tmpB) {
      max_durata.cd[max_durata.len] = archivio.cd[i];
      max_durata.len++;
    }
  }

  printf("\nCD di durata massima (%d:%d:%d)\n", max_durata.cd[0].durata.h,
         max_durata.cd[0].durata.m, max_durata.cd[0].durata.s);
  for (i = 0; i < max_durata.len; i++)
    printf("- %s - %s,  %d, %d tracce, %d:%d:%d\n", max_durata.cd[i].titolo,
           max_durata.cd[i].autore, max_durata.cd[i].anno,
           max_durata.cd[i].tracce, max_durata.cd[i].durata.h,
           max_durata.cd[i].durata.m, max_durata.cd[i].durata.s);

  printf("\nAutore da visualizzare: ");
  scanf(" %[^\n]", aut);
  for (i = 0; i < archivio.len; i++) {
    if (!strcmp(archivio.cd[i].autore, aut))
      printf("- %s\n", archivio.cd[i].titolo);
  }

  for (i = 0; i < archivio.len; i++) {
    /* tmpA <=> ho trovato l'autore*/
    for (j = 0, tmpA = 0; j < classifica.len && !tmpA; j++) {
      if (!strcmp(classifica.autori[j].autore, archivio.cd[i].autore)) {
        classifica.autori[j].n++;
        tmpA = 1;
      }
    }

    if (!tmpA) {
      strcpy(classifica.autori[classifica.len].autore, archivio.cd[i].autore);
      classifica.autori[classifica.len].n = 0;
      classifica.len++;
    }
  }

  /* tmpA <=> numero massimo di cd per autore */
  for (i = 0, tmpA = 0; i < classifica.len; i++) {
    if (tmpA < classifica.autori[i].n)
      tmpA = classifica.autori[i].n;
  }
  /* tmpB <=> ho trovato il primo autore con il max n° di cd */
  for (i = 0, tmpB = 0; i < classifica.len && !tmpB; i++) {
    if (classifica.autori[i].n == tmpA) {
      printf("\nAutore con il max n° di cd: %s\n", classifica.autori[i].autore);
      tmpB = 1;
    }
  }

  return 0;
}
