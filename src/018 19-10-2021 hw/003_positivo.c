#include <stdio.h>

/*
  Scrivere un sottoprogramma che chiede all'utente un numero intero
  non negativo; se il valore acquisito non è valido il sottoprogramma
  visualizza un apposito messaggio di errore e ripete la richiesta.
  Una volta acquisito un valore valido, il sottoprogramma restituisce
  il numero al chiamante.
  Scrivere un programma che acquisisce due numeri positivi mediante
  l'apposito sottoprogramma definito sopra e li stampa a video.
  Estendere il programma dell'esercizio precedente sul calcolo del
  coefficiente binominale, in modo tale da effettuare un'acquisizione
  di due valori positivi.
*/

int positivo();

int main() {
  int n, m;

  n = positivo();
  m = positivo();

  printf("%d %d\n", n, m);

  return 0;
}

int positivo() {
  /* Lo scope di questa n è limitato a questa funzione. */
  int n;

  scanf("%d", &n);

  while (n < 0) {
    printf("Errore.\n");
    scanf("%d", &n);
  }

  return n;
}
