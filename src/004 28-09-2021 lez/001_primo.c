#include <stdio.h>

/*
  Scrivere un programma in C che acquisisce un numero maggiore di 1;
  nel caso il valore inserito sia sbagliato, il programma stampa un
  apposito messaggio di errore e richiede l'inserimento di un nuovo
  valore. Il programma stabilisce se il numero è primo o meno e
  visualizza un apposito messaggio con il risultato (1:"primo" o
  0:"non primo").
*/

int main() {
  int n, i, primo;

  scanf("%d", &n);
  while (n < 2) {
    printf("Errore\n");
    scanf("%d", &n);
  }

  i = 2;
  primo = 1;

  /* Sarebbe i<=sqrt(n), ma dato che noi non usiamo le librerie facciamo il discorso contrario*/
  while (i*i <= n && primo) {
    if (!(n % i)) 
      primo = 0;

    /* Si può anche scrivere primo = (n%i)!=0 */

    /* i++ è consentito anche in c89 */
    i++;
  }

  printf("%d\n", primo);

  return 0;
}