#include <stdio.h>
#define MAX 10

/*
  ES4 - Scrivere un programma che chiede all'utente la dimensione m di due
  matrici quadrate di interi A e B (un valore intero compreso tra 1 e 10 e nel
  caso non sia valido va richiesto) e poi i dati per popolare le due matrici.
  Per ogni valore n compreso tra 2 e m (estremi inclusi), il programma calcola
  e stampa le coordinate (i,j) dell'angolo in alto a sinistra di tutte le
  sottomatrici quadrate nxn di A e B che soddisfano entrambe le seguenti
  condizioni:
  - hanno la stessa posizione (i,j) in entrambe le matrici A e B
  - la sottomatrice definita su A e la sottomatrice definita su B sono uguali
    (contengono gli stessi elementi, posizione per posizione)

  Esempio:
  Date le matrici
  A:          B:
  5 3 7 1 8   0 3 7 0 1
  3 9 2 7 1   0 9 2 7 0
  3 9 7 5 6   3 9 7 5 1
  4 5 7 1 3   4 5 7 1 0
  8 6 2 9 9   1 0 0 9 1
  L'output del programma sarà
  N=2
  (0, 1) (1, 1) (1, 2) (2, 0) (2, 1) (2, 2)
  N=3
  (1, 1)
  N=4
  Nessuna sottomatrice soddisfa le condizioni
  N=5
  Nessuna sottomatrice soddisfa le condizioni
*/

int main() {
  int m, i, j, n, almenoUna, valida, ii, jj;
  int A[MAX][MAX], B[MAX][MAX];

  do {
    printf("Dimensione: ");
    scanf("%d", &m);
  } while (m < 1 || m > MAX);

  printf("\nDati A:\n");
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++)
      scanf("%d", &A[i][j]);

  printf("\nDati B:\n");
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++)
      scanf("%d", &B[i][j]);

  for (n = 2; n <= m; n++) {
    printf("\nN = %d\n", n);

    almenoUna = 0;
    for (i = 0; i <= m - n; i++) {
      for (j = 0; j <= m - n; j++) {
        valida = 1;

        for (ii = 0; ii < n && valida; ii++)
          for (jj = 0; jj < n && valida; jj++)
            if (A[i + ii][j + jj] != B[i + ii][j + jj])
              valida = 0;

        if (valida) {
          printf("(%d, %d) ", i, j);
          almenoUna = 1;
        }
      }
    }

    if (!almenoUna)
      printf("Nessuna sottomatrice soddisfa le condizioni");
    printf("\n\n");
  }

  return 0;
}
