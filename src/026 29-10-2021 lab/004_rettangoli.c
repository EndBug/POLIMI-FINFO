#include <stdio.h>

/*
  ES5 - Si vuole realizzare un programma che permetta di effettuare alcune
  operazioni geometriche su rettangoli.
  Dichiarare un tipo di dato per rappresentare un rettangolo. Un rettangolo
  è descritto dal vertice inferiore sinistro e da quella del vertice superiore
  destro (due punti).
  Un punto è definito in termini di coordinate x e y (due interi) su uno spazio
  cartesiano bidimensionale.

  Scrivere un programma che esegua le seguenti elaborazioni in sequenza:
  1 - Acquisisce da tastiera i dati di due rettangoli, verificandone la correttezza 
      delle coordinate (la prima coordinata è effettivamente in basso a sinistra rispetto 
      alla seconda) e se non valide le richiede.
  2 - Calcola e visualizza l'area di ciascun rettangolo.
  3 - Verifica se i due rettangoli sono intersecati e visualizza l'esito del test.
  3 - Se sono intersecati, costruisce in una nuova variabile il rettangolo intersezione 
      (prestare attenzione a tutte le casistiche legate alla posizione di un rettangolo 
      rispetto all'altro) e ne visualizza le coordinate a schermo.
  4 - Se sono intersecati, calcola e visualizza l'intersezione sull'unione, ovvero la 
      frazione (quindi un valore in virgola mobile) tra l'area dell'intersezione tra i 
      due rettangoli e l'area totale della forma geometrica generata dai due rettangoli sovrapposti.
*/

typedef struct {
  int x1, y1, x2, y2;
} rettangolo_t;

int main() {
  rettangolo_t A, B, I;
  int areaA, areaB, intersecati, areaI, areaU;
  float iu;

  do {
    printf("Dati rettangolo A: ");
    scanf("%d %d %d %d", &A.x1, &A.y1, &A.x2, &A.y2);
  } while (A.x1 >= A.x2 || A.y1 >= A.y2);
  do {
    printf("Dati rettangolo B: ");
    scanf("%d %d %d %d", &B.x1, &B.y1, &B.x2, &B.y2);
  } while (B.x1 >= B.x2 || B.y1 >= B.y2);

  areaA = (A.x2 - A.x1) * (A.y2 - A.y1);
  areaB = (B.x2 - B.x1) * (B.y2 - B.y1);
  printf("\nArea di A: %d\nArea di B: %d\n", areaA, areaB);

  /* Controllo il negativo di "non si intersecano" */
  intersecati = !(A.x2 < B.x1 || A.y2 < B.y1 || A.x1 > B.x2 || A.y1 > B.y2);
  printf("Intersecati: %d\n", intersecati);

  if (intersecati) {
    /* Vorrei usare min() e max() ma non si può... */
    if (A.x1 > B.x1)
      I.x1 = A.x1;
    else
      I.x1 = B.x1;

    if (A.y1 > B.y1)
      I.y1 = A.y1;
    else
      I.y1 = B.y1;

    if (A.x2 < B.x2)
      I.x2 = A.x2;
    else
      I.x2 = B.x2;

    if (A.y2 < B.y2)
      I.y2 = A.y2;
    else
      I.y2 = B.y2;

    printf("Rettangolo intersezione: (%d, %d) -> (%d, %d)\n", I.x1, I.y1, I.x2,
           I.y2);

    areaI = (I.x2 - I.x1) * (I.y2 - I.y1);
    areaU = areaA + areaB - areaI;
    iu = (float)areaI / (float)areaU;
    printf("IU: %f\n", iu);
  }

  return 0;
}
