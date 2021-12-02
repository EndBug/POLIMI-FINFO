#include <stdio.h>
#define FN "ciao.bin"
#define DIM 10

int main() {
  FILE *fp;
  int a[DIM], i;

  for (i = 0; i < DIM; i++)
    scanf("%d", &a[i]);

  fp = fopen(FN, "wb");
  if (fp) {
    fwrite(a, sizeof(int), DIM, fp);
    fclose(fp);
  } else
    printf("Errore\n");

  return 0;
}
