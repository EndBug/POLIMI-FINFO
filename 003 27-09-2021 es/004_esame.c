#include <stdio.h>
#define SUFF 18
#define MINVOTO 0
#define MAXVOTO 30

int main() {
  int a, b, media;

  scanf("%d %d", &a, &b);

  if (a >= MINVOTO && a <= MAXVOTO && b >= MINVOTO && b <= MAXVOTO) {
    if (a >= SUFF && b >= SUFF) 
      media = (a+b)/2;
      printf("Promosso: %d\n", media);
    else
      printf("Bocciato.\n");
  } else {
    printf("Errore.\n");
  }

  return 0;
}