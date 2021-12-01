#include <stdio.h>
#define DIM 10

/*
  Non su file consegne
  Come massimo ma trasmette al chiamante sia massimo che minimo dell'array.
*/

void maxMin(int[], int, int *, int *);

int main() {
  int arr[DIM], i, max, min;

  for (i = 0; i < DIM; i++)
    scanf("%d", &arr[i]);

  maxMin(arr, DIM, &max, &min);

  printf("%d %d\n", max, min);

  return 0;
}

void maxMin(int a[], int dim, int *max, int *min) {
  int maxAltri, minAltri;

  if (dim == 1) {
    *max = a[0];
    *min = a[0];
  } else {
    maxMin(a + 1, dim - 1, &maxAltri, &minAltri);
    if (maxAltri > *a)
      *max = maxAltri;
    else
      *max = *a;

    if (minAltri < *a)
      *min = minAltri;
    else
      *min = *a;
  }
}
