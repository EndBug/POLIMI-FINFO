#include <stdio.h>

/*
  Scrivere un sottoprogramma che riceve due numeri interi positivi e
  calcola l'elevamento a potenza del primo rispetto al secondo,
  restituendo il risultato.
  Scrivere un sottoprogramma che calcola il logaritmo in base 2 intero
  di un numero intero positivo. Il sottoprogramma riceve come
  parametri il numero ed una variabile passata per indirizzo in cui
  memorizzare il risultato. Il sottoprogramma restituisce 1 se il
  logaritmo intero è preciso, in alternativa 0.
  Scrivere un programma che utilizza tale sottoprogramma per calcolare
  il logaritmo in base 2 di un numero chiesto all'utente, e ne
  visualizza il risultato.
  VARIANTE: estendere questo programma per il calcolo del logaritmo in
  base N, richiesto all'utente.
*/

int potenza(int, int);
int logN(int, int, int *);

int main() {
  int n, base, log;

  scanf("%d %d", &n, &base);

  logN(n, base, &log);

  printf("%d\n", log);

  return 0;
}

int potenza(int base, int esponente) {
  int i, res;

  for (i = 0, res = 1; i < esponente; i++)
    res *= base;

  return res;
}

int logN(int argomento, int base, int *res) {
  *res = 0;

  while (potenza(base, *res) < argomento) {
    (*res)++;
  }

  return (potenza(base, *res) == argomento);
}
