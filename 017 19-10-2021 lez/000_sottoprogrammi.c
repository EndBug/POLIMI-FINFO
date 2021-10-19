#include <stdio.h>

/*
  Ci sono due tipi di sottoprogrammi: funzioni e procedure.
  Le funzioni prendono degli argomenti e ritornano un risultato (es. sqrt(...))
  Le procedure invece eseguono delle operazioni ma non ritornano alucn risultato.

  In C c'è una sintassi unica per funzioni e sottoprogrammi, ma in altri linguaggi
  si utilizzano sintassi diverse.
*/

/*
  Per ogni sottoprogramma/funzione dobbiamo prima dichiarare il prototipo.
  Il prototipo serve al compilatore per sapere com'è strutturata la funzione,
  e ci permette di utilizzarla anche se l'implementazione è scritta dopo.
  Per ora utilizziamo solamente parametri numerici (non array o strutture).
*/
int fattoriale(int);
int coeffbin(int, int);

/*
  Ogni chiamata si aggiunge al call stack in memoria, che segue il principio LIFO
  (Last In First Out):
  - Ogni nuova chiamata alloca della memoria in coda (push)
  - Ogni volta che una funzione ritorna la memoria in coda viene disallocata (pop)
*/

int main() {
  int num1, num2, coeff;

  scanf("%d %d", &num1, &num2);

  /* num1 è un "parametro attuale" (actual, effettivo ma non sapevano l'inglese) */
  coeff = coeffbin(num1, num2);

  printf("%d", coeff);

  return 0;
}

/* 
  Per ogni header che dichiariamo dobbiamo poi dichiarare anche l'implementazione
  della funzione/sottoprogramma.
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

int coeffbin(int n1, int n2) {
  return fattoriale(n1)/(fattoriale(n2)*fattoriale(n1-n2));
}