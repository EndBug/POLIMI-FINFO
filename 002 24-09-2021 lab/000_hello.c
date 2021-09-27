#include <stdio.h>

int main() {
  char c;
  scanf("%c", &c);
  printf("-> %c <-\n", c);

  /* Teoricamente i commenti con // non sono ammessi in C89 */
  // La seconda volta bisogna scartare il primo valore, perché il secondo è un invio.
  scanf(" %c", &c);
  printf("-> %c <-\n", c);

  return 0;
}