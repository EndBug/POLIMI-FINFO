/*
  Da esame del 20/01/2020 della prof.ssa Cristiana Bolchini
  https://bolchini.faculty.polimi.it/exams/20200120.pdf
  -> Quesito 3
*/

int analizza(int v[], int dim, int da, int a);

/* Variante 1 */
int analizza(int v[], int dim, int da, int a) {
  int i, j, ok, conto;

  for (i = da, ok = 1; i <= a && ok; i++) {
    for (j = 0, conto = 0; j < dim && conto <= 1; j++) {
      if (v[j] == i)
        conto++;
    }

    if (conto != 1)
      ok = 0;
  }

  return ok;
}

/* Variante 2 */
int analizza(int v[], int dim, int da, int a) {
  int i, j, ok, found;

  ok = (dim == a - da + 1);

  if (ok) {
    for (i = da; i <= a && ok; i++) {
      for (j = 0, found = 0; j < dim && !found; j++) {
        if (v[j] == i)
          found = 1;
      }

      if (!found)
        ok = 0;
    }
  }

  return ok;
}
