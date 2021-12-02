#include <stdio.h>
#include <stdlib.h>
#define N 2

/*
  Scrivere un programma che esegue due volte le seguenti elaborazioni.
  Il programma chiede all'utente il numero di valori interi da
  acquisire. Il programma alloca dinamicamente un array della
  dimensione specificata e lo popola con i valori acquisiti da
  tastiera. In seguito il programma visualizza la sequenza di valori
  acquisiti al rovescio e libera la memoria allocata dinamicamente.
  Visualizzare un errore nel caso si verifichi un errore di
  allocazione della memoria.
*/

int main() {
  int dim, i, j, *p;

  for (j = 0; j < N; j++) {
    scanf("%d", &dim);

    /*
      malloc ic permette di allocare lo spazio nella memoria di una dimensione
      definita in runtime.
      malloc ritorna void* (puntatore a byte), quindi il compilatore fa un cast
      implicito (nel nostro caso a int*).
    */
    p = (int *)malloc(dim * sizeof(int)); /* (void*) */

    if (p) {
      for (i = 0; i < dim; i++)
        scanf("%d", p + i);

      for (i = dim - 1; i >= 0; i--)
        printf("%d ", *(p + i));
      printf("\n");

      /*
        Dopo aver utilizzato la memoria la dobbiamo liberare, altrimenti
        abbiamo una memory leak.
      */
      free(p);
    } else
      printf("Errore allocazione.\n");
  }

  return 0;
}
