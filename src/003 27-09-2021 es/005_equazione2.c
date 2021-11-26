#include <stdio.h>

int main() {
  float a, b, c, det;

  scanf("%f %f %f", &a, &b, &c);

  if (a != 0) {
    det = b * b - 4 * a * c;

    if (det > 0)
      printf("Reali e distinte.\n");
    else if (det == 0)
      printf("Reali e coincidenti.\n");
    else
      printf("Complesse coniugate.\n"); 
  } else
    printf("Errore.\n");

  return 0;
}