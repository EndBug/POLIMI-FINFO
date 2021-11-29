#include <stdio.h>

/*
  Compiliamo con gcc -g 000_fact.c -o fact.out
  Avvio GDB con gdb --args ./fact.out
  Comandi:
  - list: mostra le righe del programma
  - b <n>: aggiunge un breakpoint alla riga <n>
  - run: fa partire il programma
  - print <var>: mostra il valore di una variabile <var>
  - display <var>: esegue print <var> ad ogni step
  - n: va alla riga successiva (premendo invio esegue il comando precedente)
  - bt: esegue il backtrace dell'errore
  - quit: esce da gdb
*/

int main() {
  int n, f, i;
  int *a;

  scanf("%d", &n);
  /* Il bug sta nel fatto che dovrebbe essere i <= n */
  for (i = 2, f = 1; i < n; i++)
    f *= i;

  a = 10;
  /*
    Qua ci aspettiamo una segmentation fault: gdb ci mostra il valore del
    puntatore che ha causato il crash.
  */
  *a = 30;

  printf("%d! = %d\n", n, f);
  return 0;
}
