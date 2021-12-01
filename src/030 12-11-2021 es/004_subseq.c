#include <stdio.h>
#define MAXDIM 30

/*
  Scrivere un sottoprogramma che, ricevuto in ingresso un array
  monodimensionale di interi e qualsiasi parametro ritenuto
  strettamente necessario, individua la sottosequenza più lunga di
  valori tutti uguali tra di loro e trasmette al chiamante il valore e
  la lunghezza.
  Nel caso ci fosse più di una sottosequenza di pari lunghezza
  massima, il sottoprogramma restituisce la prima
  Esempio:
  Ingresso = 1 2 8 3 3 7 4 6 6 6 6 3 2 2 8 8 8 8 8 3 3
  Uscita: valore = 8, lunghezza = 5
*/

void subseq(int[], int, int *, int *);

int main() {
  int dim, arr[MAXDIM], i, val, len;

  scanf("%d", &dim);
  for (i = 0; i < dim; i++)
    scanf("%d", &arr[i]);

  subseq(arr, dim, &val, &len);

  printf("valore = %d, lunghezza = %d\n", val, len);
}

void subseq(int arr[], int dim, int *val, int *len) {
  int i, tmpVal, tmpLen;

  tmpVal = arr[0];
  tmpLen = 1;
  *val = arr[0];
  *len = 1;

  for (i = 1; i < dim; i++) {
    if (arr[i] == tmpVal) {
      tmpLen++;

      if (tmpLen > *len) {
        *val = tmpVal;
        *len = tmpLen;
      }
    } else {
      tmpVal = arr[i];
      tmpLen = 1;
    }
  }
}
