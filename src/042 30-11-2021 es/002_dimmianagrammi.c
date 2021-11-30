/*
  Da esame del 18-02-2019 della prof.ssa Cristiana Bolchini
  https://bolchini.faculty.polimi.it/exams/20190218.pdf
  -> Quesito 4
*/
#define FN "dizionario.txt"
#define MAXS 25
#define BASE 10

int anagramma(char s1[], char s2[]);
int dimmianagrammi(char word[]);
int dimmianagrammiInt(int n);

int dimmianagrammi(char word[]) {
  FILE *fp;
  int count;
  char curr[MAXS + 1];

  fp = fopen(FN, "r");

  if (fp) {
    count = 0;
    fscanf(fp, "%s", curr);

    while (!feof(fp)) {
      count += anagramma(word, curr);
      fscanf(fp, "%s", curr);
    }

    fclose(fp);
  } else
    count = -1;

  return count;
}

int dimmianagrammiInt(int n) {
  /*
    La dimensione della stringa è sufficiente a contenere qualsiasi intero,
    perché 2^64 ha 20 cifre.
  */
  char word[MAXS + 1];
  int c, l;

  for (l = 0; n > 0; l++, n /= BASE) {
    c = n % BASE;
    word[l] = '0' + c;
  }
  word[l] = '\0';

  return dimmianagrammi(word);
}
