/*
  Da esame del 01/09/2020 della prof.ssa Cristiana Bolchini
  https://bolchini.faculty.polimi.it/exams/20200120.pdf
  -> Quesito 3
*/

#include <math.h>
#include <stdio.h>
#define BASE 10

void trovanarcisisti(int numero[], int tipo[], int dim, int x) {
  int i, n, acc;

  for (i = 0; i < dim; i++) {
    n = numero[i];
    acc = 0;

    while (n) {
      acc += pow(n % BASE, x);
      n /= BASE;
    }

    tipo[i] = acc == numero[i];
  }
}
