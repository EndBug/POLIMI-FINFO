/*
  Da esame del 01/09/2020 della prof.ssa Cristiana Bolchini
  https://bolchini.faculty.polimi.it/exams/20200120.pdf
  -> Quesito 2
*/

#include <stdio.h>
#define MAX 200

int compattaarray(int arr[], int dim);
int primo(int n);

int main() {
  int dim, arr[MAX], i;

  do {
    printf("N. elementi: ");
    scanf("%d", &dim);
  } while (dim <= 0 || dim > MAX);

  printf("Elementi:\n");
  for (i = 0; i < dim; i++)
    scanf("%d", &arr[i]);

  dim = compattaarray(arr, dim);

  for (i = 0; i < dim; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}

int compattaarray(int arr[], int dim) {
  int i, j;

  for (i = 0, j = 0; i < dim; i++) {
    if (primo(arr[i])) {
      arr[j] = arr[i];
      j++;
    }
  }

  return j;
}

int primo(int n) {
  int i, res;

  for (i = 2, res = 1; i * i <= n && res; i++)
    if (n % i == 0)
      res = 0;

  return n != 1 && res;
}
