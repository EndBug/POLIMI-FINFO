#include <stdio.h>

/*
  Scrivere un sottoprogramma che riceve in ingresso due valori in
  virgola mobile, calcola e restituisce il maggiore tra i due.
  Scrivere un programma che chiede all'utente tre numeri in virgola
  mobile e stabilisce, mediante il sottoprogramma definito prima,
  quale dei tre è più grande visualizzandolo a video.
*/

float max(float, float);

int main() {
  float a, b, c, m;

  scanf("%f %f %f", &a, &b, &c);

  m = max(max(a, b), c);

  printf("%f\n", m);

  return 0;
}

float max(float a, float b) {
  /*
    Dichiariamo comunque una variabile di supporto, anche se potremmo farne a
    meno in questo caso. E' una questione di metodo.
  */
  float res;

  if (a > b)
    res = a;
  else
    res = b;

  return res;
}
