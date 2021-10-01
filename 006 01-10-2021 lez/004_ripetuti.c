#include <stdio.h>
#define DIM 20

/*
  Scrivere un programma in C che chiede all'utente una sequenza di 20
  numeri interi salvandoli in un array. Il programma salva in un
  secondo array tutti e soli i valori distinti della sequenza 
  acquisita (ovvero omettere i duplicati). Infine il programma
  visualizza il contenuto del secondo array e la sua lunghezza.
*/

int main()
{
  /*
    L'array lo creiamo della dimensione del caso pessimo
    => array sovradimensionato e sottoutilizzato
    Se il caso pessimo non esiste, perché la sequenza è indefinita, non si 
    possono utilizzare gli array.
  */
  int a1[DIM], a2[DIM], i, j, k, unico;

  for (i = 0; i < DIM; i++)
    scanf("%d", &a1[i]);

  k = 0;
  for (i = 0, unico = 1; i < DIM; i++)
  {
    for (j = 0; j < i && unico; j++)
      if (a1[i] == a1[j])
        unico = 0;

    if (unico)
    {
      a2[k] = a1[i];
      k++;
    }
  }

  for (i = 0; i < k; i++)
    printf("%d ", a2[i]);
  printf("\n%d\n", k);

  return 0;
}
