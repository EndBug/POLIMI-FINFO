#include <stdio.h>
#define VUOTO 0
#define CELL 3
#define N 9
#define MINVAL 1
#define MAXVAL 9
#define MAXFN 50
#define INVALID -1

/*
  ES3 - Si vuole realizzare un programma che verifica se una griglia
  di un Sudoku (https://it.wikipedia.org/wiki/Sudoku), anche
  parzialmente riempita, sia valida o meno. In breve una griglia di un
  Sudoku è una matrice 9x9 di interi e ciascuna posizione può
  contenere un valore da 1 a 9 o esser vuota se la griglia non è stata
  ancora completata. Una griglia, anche parzialmente, è valida se si
  verificano tutte le seguenti condizioni:
  * in ciascuna riga della matrice non si presenta alcuna ripetizione
  dei numeri validi (da 1 a 9)
  * in ciascuna colonna della matrice non si presenta alcuna
  ripetizione dei numeri validi (da 1 a 9)
  * dividendo la matrice 9x9 in 9 sottomatrici 3x3 non sovrapposte,
  ciascuna sottomatrice non contiene alcuna ripetizione dei numeri
  validi (da 1 a 9).
  Realizzare il programma come segue:
  - definire una costante VUOTO contenente il valore 0.
  - definire un sottoprogramma "stampa_sudoku" che riceva come
  argomento una matrice definita con 9 colonne e la stampi a video. Si
  utilizzi uno spazio per indicare le celle vuote; opzionale:
  disegnare le righe orizzontali e verticali che contornano l'intera
  griglia e le 9 sottogriglie come da esempio:
  +-------+-------+-------+
  |   9   |       | 4     |
  | 8   5 |     4 | 1     |
  |     4 | 6 8 1 | 5 3 9 |
  +-------+-------+-------+
  |     8 |   4 9 | 7   3 |
  |   7   |     6 |   4 8 |
  | 4 1   | 8 3   | 6     |
  +-------+-------+-------+
  | 3 5   | 4     | 2 9 1 |
  | 9   2 | 1   3 |   7 6 |
  | 1     |   6   |   5 4 |
  +-------+-------+-------+
  - definire un sottoprogramma "leggi" che riceve come argomento il
  nome di un file di testo e una matrice di interi dichiarata con 9
  colonne. Il sottoprogramma apre il file di testo, contenente 9x9
  valori interi, e popola la matrice con i dati letti da file. Il
  sottoprogramma restituisce 1 se l'operazione è andata a buon fine
  altrimenti 0. Si noti che si potrebbe verificare un errore di
  apertura del file o il numero di valori letti potrebbe essere
  erroneamente minore di 81 o un dato valore potrebbe essere al di
  fuori dell'intervallo [1,9] o diversa da VUOTO. Il sottoprogramma
  prima di ritornare stampa a video la causa dell'eventuale errore
  riscontrato.
  - definire un sottoprogramma "verifica_sudoku" che riceva come
  argomento una matrice di interi dichiarata con 9 colonne e verifichi
  che il sudoku associato sia valido. Il sottoprogramma restituisce 1
  in caso affermativo; in alternativa stampa a video un messaggio per
  ciascun errore riscontrato (cioè indici di riga o colonna o
  quadrante che violano le regole) e restituisce 0.
  - Scrivere un programma chiede all'utente il nome del file (una
  stringa di al massimo 50 caratteri). Mediante l'ausilio dei
  sottoprogrammi sopra definiti, il programma legge la matrice dal
  file, la stampa a video e verifica se la griglia è valida, stampando
  a video il responso. Gestire opportunamente gli eventuali errori.
*/

void stampa_sudoku(int m[][N], int dim);
void stampa_sep_riga(int dim);
int leggi(char fn[], int m[][N], int dim);
int verifica_sudoku(int m[][N], int dim);

int main() {
  char fn[MAXFN];
  int m[N][N], ok;

  scanf("%s", fn);

  ok = leggi(fn, m, N);
  if (ok) {
    stampa_sudoku(m, N);
    ok = verifica_sudoku(m, N);

    printf("Valido: %d\n", ok);
  }

  return 0;
}

void stampa_sudoku(int m[][N], int dim) {
  int i, j, k;

  for (i = 0; i < dim; i++) {
    if (i%CELL == 0)
      stampa_sep_riga(dim);

    for (j = 0; j < dim; j++) {
      if (j%CELL == 0)
        printf("| ");
      if (m[i][j] == VUOTO)
        printf("  ");
      else
        printf("%d ", m[i][j]);
    }
    printf("|\n");
  }
  stampa_sep_riga(dim);
}

void stampa_sep_riga(int dim) {
  int i;

  for (i = 0; i < dim; i++) {
    if (i%CELL == 0)
      printf("+-");
    printf("--");
  }
  printf("+\n");
}

int leggi(char fn[], int m[][N], int dim) {
  FILE *fp;
  int ok, i, j;

  ok = 1;
  fp = fopen(fn, "r");

  if (fp) {
    for (i = 0; i < dim && ok; i++) {
      for (j = 0; j < dim && ok; j++) {
        m[i][j] = INVALID;
        fscanf(fp, "%d", &m[i][j]);

        if ((feof(fp) && !(i == dim-1 && j == dim-1)) || m[i][j] == INVALID) {
          printf("Errore: il file contiene meno elementi di quelli attesi.\n");
          ok = 0;
        } else if (!((m[i][j] >= MINVAL && m[i][j] <= MAXVAL) || m[i][j] == VUOTO)) {
          printf("Errore: il valore [%d][%d] non è valido.\n", i, j);
          ok = 0;
        }
      }
    }

    fclose(fp);
  } else {
    printf("Errore di apertura del file.\n");
    ok = 0;
  }

  return ok;
}

int verifica_sudoku(int m[][N], int dim) {
  int valido, n, i, j, count, ii, jj;

  valido = 1;

  for (i = 0; i < dim && valido; i++) {
    for (n = MINVAL; n <= MAXVAL && valido; n++) {
      count = 0;
      for (j = 0; j < dim; j++) {
        if (m[i][j] == n)
          count++;
      }
      if (count > 1) {
        printf("Riga %d: il numero %d appare %d volte.\n", i, n, count);
        valido = 0;
      }
    }
  }

  for (i = 0; i < dim && valido; i++) {
    for (n = MINVAL; n <=MAXVAL && valido; n++) {
      count = 0;
      for (j = 0; j < dim; j++) {
        if (m[j][i] == n)
          count++;
      }
      if (count > 1) {
        printf("Colonna %d: il numero %d appare %d volte.\n", i, n, count);
        valido = 0;
      }
    }
  }

  for (i = 0; i < dim && valido; i += CELL) {
    for (j = 0; j < dim && valido; j += CELL) {
      for (n = MINVAL; n <= MAXVAL && valido; n++) {
        count = 0;
        for (ii = 0; ii < CELL; ii++) {
          for (jj = 0; jj < CELL; jj++) {
            if (m[i+ii][j+jj] == n)
              count++;
          }
        }
        if (count > 1) {
          printf("Cella [%d][%d]: il numero %d appare %d volte\n", i/CELL, j/CELL, n, count);
          valido = 0;
        }
      }
    }
  }

  return valido;
}