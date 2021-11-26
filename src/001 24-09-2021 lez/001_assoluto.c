#include <stdio.h>

int main() {
  int n, a;

  scanf("%d", &n);

  /*
  int n, a;
  if (n < 0) {
    a = -n;
  } else {
    a = n;
  }
  printf("%d\n", a);
  */

  // Questa versione è più elegante <3
  if (n < 0) n = -n
  printf("%d\n", n);

  return 0;
}