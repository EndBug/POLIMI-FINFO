# include <stdio.h>

int int main() {
  float n, decimale;
  int intera;

  scanf("%f", &n);

  // In questo assegnamento stiamo facendo il caso di float su int, perdendo la parte decimale
  intera = n;
  decimale = n - intera;

  printf("%f = %d + %f\n", n, intera, decimale);

  return 0;
}