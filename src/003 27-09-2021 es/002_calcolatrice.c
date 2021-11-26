#include <stdio.h>

int main() {
  float a, b, res;
  int err;
  char op;

  scanf("%f %f %c", &a, &b, &op);

  err = 0;

  if (op == '+') res = a+b;
  else if (op == '-') res = a-b;
  else if (op == '*') res = a*b;
  else if (op == '/') res = a/b;
  else err = 1;

  if (!err) printf("Risultato %f\n", res);
  else printf("Operazione non valida.\n");

  return 0;
}