#include <stdio.h>

/*
  Scrivere un programma che acquisisce tre numeri in virgola mobile e
  verifica se la terna può rappresentare le dimensioni dei lati di un
  triangolo: devono essere valori positivi; inoltre la somma di due
  numeri deve essere maggiore del terzo. Se il controllo è stato
  superato con successo, il programma stabilisce che tipo di triangolo
  è isoscele, equilatero o scaleno e stampa un apposito messaggio a
  video. Altrimenti, il programma deve stampare un apposito messaggio
  di errore.
*/

int main() {
  float a, b, c;

  scanf("%f %f %f", &a, &b, &c);

  /* Separare i due errori è meglio perché sono di tipo diverso. */
  if (a > 0 && b > 0 && c > 0) {
    if (a + b > c && b + c > a && a + c > b) {
      if (a == b && b == c)
        printf("Triangolo equilatero.\n");
      else if (a == b || b == c || a == c)
        printf("Triangolo isoscele.\n");
      else
        printf("Triangolo scaleno.\n");
    } else {
      printf("Non è un triangolo.\n");
    }
  } else {
    printf("Errore.\n");
  }
  return 0;
}
