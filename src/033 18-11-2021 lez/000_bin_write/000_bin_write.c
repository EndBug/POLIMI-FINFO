#include <stdio.h>
#define FN "ciao.bin"

int main() {
  FILE *fp;
  int n;

  /* "wb" sta per write-binary */
  fp = fopen(FN, "wb");

  if (fp) {
    scanf("%d", &n);

    /* 
      sizeof() è un operatore, e ci dice quanti bit occupa un tipo oppure 
      il tipo di una variabile. 
      In questo caso utilizziamo fwrite al posto che fprintf.
    */
    fwrite(&n, sizeof(int), 1, fp);
    
    fclose(fp);
  } else {
    printf("Errore apertura.\n");
  }

  return 0;
}