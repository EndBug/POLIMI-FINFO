/*
  Da esame del 01/09/2020 della prof.ssa Cristiana Bolchini
  https://bolchini.faculty.polimi.it/exams/20200120.pdf
  -> Quesito 4
*/

#define DIM ('z' - 'a' + 1)

int pangramma(char *str);
int minuscola(char c);

int pangramma(char *str) {
  int presente[DIM], i, res;

  for (i = 0; i < DIM; i++)
    presente[i] = 0;

  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] != ' ')
      presente[minuscola(str[i]) - 'a'] = 1;
  }

  for (i = 0, res = 1; i < DIM; i++) {
    if (!presente[i])
      res = 0;
  }

  return res;
}

int minuscola(char c) {
  if (c >= 'A' && c <= 'Z')
    return c - 'A' + 'a';
  else
    return c;
}
