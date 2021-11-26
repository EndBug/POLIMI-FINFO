#include <stdio.h>
#define MAX 8

/*
  Scrivere un programma in C che calcola il prodotto tra due polinomi
  di grado massimo 8. Il programma chiede prima il grado (e nel caso
  di valore non valido lo richiede) ed i coefficienti di ciascuno dei
  due polinomi (i coefficienti sono valori interi). In seguito esegue
  il prodotto polinomiale e visualizza i coefficienti del polinomio
  risultato.
*/

int main() {
  int a[MAX+1], b[MAX+1], r[MAX*2+1], gradoA, gradoB, i, j;

  do 
    scanf("%d", &gradoA);
  while (gradoA < 0 || gradoA > MAX);
  for (i = 0; i <= gradoA; i++)
    scanf("%d", &a[i]);

  do 
    scanf("%d", &gradoB);
  while (gradoB < 0 || gradoB > MAX);  
  for (i = 0; i <= gradoB; i++)
    scanf("%d", &b[i]);

  for (i = 0; i <= gradoA+gradoB; i++)
    r[i] = 0;

  for (i = 0; i <= gradoA; i++) {
    for (j = 0; j <= gradoB; j++) {
      r[i+j] += a[i]*b[j];
    }
  }

  for (i = 0; i <= gradoA+gradoB; i++)
    printf("%d ", r[i]);
  printf("\n");

  return 0;
}