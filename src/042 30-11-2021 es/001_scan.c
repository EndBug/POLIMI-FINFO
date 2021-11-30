/*
  Da esame del 18-02-2019 della prof.ssa Cristiana Bolchini
  https://bolchini.faculty.polimi.it/exams/20190218.pdf
  -> Quesito 3
*/

#define NCOL 10

void scan(int mat[][NCOL], int nRows, int nCols, int val, int *iRes, int *jRes);

void scan(int mat[][NCOL], int nRows, int nCols, int val, int *iRes,
          int *jRes) {
  int i, j, acc;

  *iRes = -1;
  *jRes = -1;

  for (i = 0, acc = 0; i < nRows && *iRes < 0; i++) {
    for (j = 0; j < nCols && *iRes < 0; j++) {
      acc += mat[i][j];
      if (acc > val) {
        *iRes = i;
        *jRes = j;
      }
    }
  }
}
