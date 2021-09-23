#include <stdio.h>
#define PASSO 1

int main() {
  char c_in, c_out;

  scanf("%c", &c_in);

  c_out = (c_in - 'a' + PASSO) % ('z' - 'a' + 1) + 'a';

  printf("%c\n", c_out);

  return 0
}