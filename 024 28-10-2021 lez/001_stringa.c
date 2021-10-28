#include <stdio.h>
#define DIM 50

/*
  Non è un testo da file.
  Acquisiamo una stringa e ne calcoliamo la lunghezza in vari modi.
*/

int main() {
  char str[DIM+1];
  int len1, len2, len3;
  char *p2, *p3;

  scanf("%s", str);

  for (len1 = 0; str[len1] != '\0'; len1++);

  for (p2 = str, len2 = 0; *(p2+len2) != '\0'; len2++);

  for (p3 = str; *p3 != '\0'; p3++);
  len3 = p3 - str;

  printf("%d %d %d\n", len1, len2, len3);

  return 0;
}