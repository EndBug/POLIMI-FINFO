#include <stdio.h>

int main() {
  float a, b, c;

  scanf("%f %f %f", &a, &b, &c);

  /* Separare i due errori è meglio perché sono di tipo diverso. */
  if (a > 0 && b > 0 && c > 0) {
    if (a + b > c && b + c > a && a + c > b) {
      if (a == b && b == c)
        printf("Triangolo equilatero.\n");
      else if (a == b || b == c || a == c)
        printf("Triangolo isoscele.\n");
      else
        printf("Triangolo scaleno.\n");
    } else {
      printf("Non è un triangolo.\n");
    }
  } else {
    printf("Errore.\n");
  }
  return 0;
}