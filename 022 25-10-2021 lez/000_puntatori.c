#include <stdio.h>


int main() {
  /*
    Ogni riga della memoria ha un indirizzo, e i puntatori ci permettono di ottenerlo.
    *p è un puntatore a variabile intera: contiene l'indirizzo di una cella che contiene un intero.
    I puntatori hanno un tipo perché dobbiamo accedere a una variabile con un tipo fisso.
  */
  int a, b, *p, *q;

  /* 
    Introduciamo due nuovi operatori:
    - & ("address of"): restituisce l'indirizzo della variabile.
    - * ("dereferenziazione"): permette di accedere alla variabile che il puntatore sta indicando.
  */
  p = &a;
  *p = 2;

  /* ! Operatore unario con la stessa priorità degli altri => le parentesi sono importanti. */
  (*p)++; /* <=> a++, */

  /*
    Un puntatore non inizializzato contiene un valore a caso => punta a una cella
    a caso. Se lo utilizziamo o andiamo al di fuori della memoria assegnata 
    (=> crash, segmentation fault) o andiamo a sporcare la memoria del processo.
    Per questo motivo lo possiamo inizializzare a NULL, che è una macro per l'indirizzo
    0, che nessun programma può utilizzare.
  */
  q = NULL;

  /* La lunghezza del puntatore dipende dall'architettura della macchina: 64 bit <-> indirizzi a 64 bit */

  return 0;
}