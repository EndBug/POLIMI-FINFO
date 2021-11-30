#include <stdio.h>

/*
  Scrivere un sottoprogramma che riceve come parametro un numero
  intero non negativo e calcola e restituisce il suo fattoriale.
  Scrivere in seguito un sottoprogramma che riceve come parametri due
  numeri interi non negativi e calcola il coefficiente binomiale
  (utilizzare il sottoprogramma precedentemente definita per calcolare
  il fattoriale)
  Scrivere un programma che chiede all'utente due numeri interi non
  negativi e utilizza il sottoprogramma sopra definito per calcolarne
  il coefficiente binomiale mostrando a video il risultato.
*/

/*
  Ci sono due tipi di sottoprogrammi: funzioni e procedure.
  Le funzioni prendono degli argomenti e ritornano un risultato (es. sqrt(...))
  Le procedure invece eseguono delle operazioni ma non ritornano alucn
  risultato.

  In C c'è una sintassi unica per funzioni e sottoprogrammi, ma in altri
  linguaggi si utilizzano sintassi diverse.
*/

/*
  Per ogni sottoprogramma/funzione dobbiamo prima dichiarare il prototipo.
  Il prototipo serve al compilatore per sapere com'è strutturata la funzione,
  e ci permette di utilizzarla anche se l'implementazione è scritta dopo.
  Per ora utilizziamo solamente parametri numerici (non array o strutture).
*/
int fattoriale(int);
float coeffbin(int, int);

/*
  Ogni chiamata si aggiunge al call stack in memoria, che segue il principio
  LIFO (Last In First Out):
  - Ogni nuova chiamata alloca della memoria in coda (push)
  - Ogni volta che una funzione ritorna la memoria in coda viene disallocata
  (pop)
*/

int main() {
  int num1, num2;
  float coeff;

  scanf("%d %d", &num1, &num2);

  /*
    num1 è un "parametro attuale" (actual, effettivo ma non sapevano l'inglese)
  */
  coeff = coeffbin(num1, num2);

  printf("%f", coeff);

  return 0;
}

/*
  Per ogni header che dichiariamo dobbiamo poi dichiarare anche
  l'implementazione della funzione/sottoprogramma.
*/
int fattoriale(int n) {
  /* n è il "parametro formale" */

  int f;
  f = 1;

  while (n > 1) {
    f *= n;
    n--;
  }

  /*
    In questo modo andiamo a restituire il valore che abbiamo calcolato come
    valore della funzione.
  */
  return f;
}

float coeffbin(int n1, int n2) {
  return (float)fattoriale(n1) / (float)(fattoriale(n2) * fattoriale(n1 - n2));
}
