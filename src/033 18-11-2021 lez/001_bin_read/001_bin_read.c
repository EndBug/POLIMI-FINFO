#include <stdio.h>
#define FN "ciao.bin"

int main() {
  FILE *fp;
  int n, i;

  /* "rb" sta per read-binary */
  fp = fopen(FN, "rb");

  if (fp) {
    /*  In questo caso utilizziamo fread al posto che fprintf. */
    fread(&n, sizeof(int), 1, fp);
    printf("%d\n", n);

    fclose(fp);
  } else {
    printf("Errore apertura.\n");
  }

  return 0;
}
