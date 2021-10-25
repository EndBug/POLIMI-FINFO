#include <stdio.h>

int main() {
  int a, b;
  int *c, *d, *e;

  a = 2;
  b = 3;
  c = &a; // c -> a

  b = *c + 4; // b = 6;
  d = c; // d = &a;
  *d = 7; // a = 7;
  // b = c; // NO!
  // c = a; // NO! Permesso ma crash alla riga dopo
  *c = 5; // a = 5;
  // *e = b; // NO!, e non inizializzato => segmentation fault
  e = &b; // e -> b
  *e = *c; // b = a;
  *d = *c; // a = a;
  scanf("%d", e); // b = %d
  e = NULL; // e -> 0x0
  if (e != NULL) // <=> (e)
    printf("%d\n", *e);

  return 0;
}