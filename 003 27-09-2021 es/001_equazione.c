#include <stdio.h>

int main() {
  float a, b, risultato;

  scanf("%f %f", &a, &b);

  if (a != 0) {
    risultato = -b/a;
    printf("x = %f", risultato);
  } else {
    if (b == 0) printf("Indeterminata.\n");
    else printf("Impossibile.\n");
  }

  return 0;
}