#include <stdio.h>

int main() {
  int n;

  scanf("%d", &n);

  if (n >= 0) {
    if (n > 0)
      printf("POSITIVO\n");
    else
      printf("NULLO\n");
  } else {
      printf("NEGATIVO\n");
  }

  return 0;
}