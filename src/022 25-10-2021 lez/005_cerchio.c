#include <stdio.h>
#define PI 3.14

/*
  Scrivere un sottoprogramma che calcola l'area e il perimetro di un
  cerchio di un dato raggio. Il sottoprogramma riceve come parametri
  un numero in virgola mobile che rappresenta il raggio del cerchio e
  altri due parametri, sempre in virgola mobile, in cui verranno
  salvati i due risultati richiesti.
  Scrivere un programma che chiede all'utente la lunghezza del raggio
  del cerchio, calcola mediante la funzione sopra e visualizza il
  perimetro e l'area del cerchio. In seguito il programma chiede
  all'utente se vuoi continuare o meno (0 per continuare, qualsiasi
  altro valore per terminare).
*/

void calc(float r, float *a, float *p);

int main() {
  float r, a, p;
  char choice;

  choice = '0';
  while (choice == '0') {
    printf("Raggio: ");
    scanf("%f", &r);

    calc(r, &a, &p);
    printf("A: %f\tP: %f\n", a, p);

    printf("Inserisci 0 per continuare: ");
    scanf(" %c", &choice);
  }

  return 0;
}

void calc(float r, float *a, float *p) {
  *a = PI * r * r;
  *p = PI * 2 * r;
}
