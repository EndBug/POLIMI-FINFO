#include <stdio.h>
#include <stdlib.h>

/*
  Dichiarare un nuovo tipo di dato di tipo basato sul modello della
  lista concatenata per memorizzare una sequenza di lunghezza
  indefinita di numeri interi.
  Scrivere un programma che svolge le seguenti elaborazioni:
  - chiede all'utente una sequenza di lunghezza indefinita di numeri
  interi positivi terminata da un valore non valido e la salva in una
  lista utilizzando un inserimento in testa (cioè ogni nuovo numero
  viene inserito in testa alla lista)
  - visualizza il contenuto della lista
  - libera la memoria allocata dinamicamente per la lista.
*/

/*
  Non possiamo utilizzare direttamente nodo_t perché è dichiarato
  successivamente, quindi utilizziamo un secondo simbolo per definire la stessa
  struttura.
*/
typedef struct nodo_ {
  int num;
  struct nodo_ *next;
} nodo_t;

int main() {
  nodo_t *h, *tmp;
  int n;

  h = NULL;

  scanf("%d", &n);
  while (n > 0) {
    tmp = malloc(sizeof(nodo_t));
    if (tmp) {
      tmp->num = n;
      tmp->next = h;
      h = tmp;
    } else
      printf("Errore allocazione.\n");
    scanf("%d", &n);
  }

  for (tmp = h; tmp; tmp = tmp->next)
    printf("%d ", tmp->num);
  printf("\n");

  while (h) {
    tmp = h;
    h = h->next;
    free(tmp);
  }

  return 0;
}
