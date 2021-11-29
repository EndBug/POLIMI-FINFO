#include <stdio.h>
#define VMIN 18
#define VMAX 30

/*
  Scrivere un programma per calcolare la media, il massimo e il minimo
  di una sequenza di voti, valori interi in trentesimi, inseriti
  dall'utente. L'inserimento dei voti prosegue fino a quando l'utente
  non immette un valore non valido, cioè minore di 18 o maggiore di 30
  (valore di "fine inserimento", che non fa parte della sequenza).
  Quando viene immesso il valore di fine inserimento, vengono
  visualizzati media, massimo, minimo e il numero di voti inseriti.
  Qualora il primo valore inserito fosse quello di fine inserimento,
  dovrà essere visualizzato un messaggio di errore.
*/

int main() {
  int n, max, min, tot;
  float media;

  tot = 0;
  scanf("%d", &n);
  while (n >= VMIN && n <= VMAX) {
    if (tot) {
      if (max < n)
        max = n;
      if (min > n)
        min = n;
      media = ((media * tot) + n) / (tot + 1);
      tot++;
    } else {
      max = n;
      min = n;
      media = n;
      tot = 1;
    }
    scanf("%d", &n);
  }

  printf("Media: %f\tMax: %d\tMin: %d\tTot: %d\n", media, max, min, tot);

  return 0;
}
