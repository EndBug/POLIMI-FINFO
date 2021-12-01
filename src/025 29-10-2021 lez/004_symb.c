#include <stdio.h>
#define MAXS 20
#define N 8
#define NL 5
#define SYMB "%:;-+"

/*
  Un dato sistema informatico richiede che ciascun username sia una
  stringa composta da almeno N caratteri, di cui almeno NL lettere
  dell'alfabeto maiuscolo o minuscolo e non contenga alcun carattere
  speciale appartenente ad una stringa di controllo SYMB (per esempio
  "%:;-+").
  Scrivere un sottoprogramma che riceve come parametri una stringa
  rappresentante un username, gli interi N ed NL e la stringa SYMB; il
  sottoprogramma restituisce 1 se la stringa rappresenta un username
  valida, altrimenti 0.
  Esempio: con N=8, NL=5 e SYMB="%:;-+", "Domani.898" è un username
  valida, mentre "domani:898" e "do.898" non lo sono.
  Scrivere un programma che chiede all'utente una stringa di al
  massimo 20 caratteri ed invoca il sottoprogramma sopra definito
  specificando i seguenti valori per i parametri: N=8, NL=5 e
  SYMB="%:;-+". Il sottoprogramma visualizza il risultato restituito
  dal sottoprogramma.
*/

int isUsername(char[], int, int, char[]);

int main() {
  int valido;
  char str[MAXS + 1];

  scanf("%s", str);

  valido = isUsername(str, N, NL, SYMB);

  printf("%d\n", valido);

  return 0;
}

int isUsername(char usr[], int n, int nl, char symb[]) {
  int i, j, cl, noSymb;

  for (i = 0, cl = 0, noSymb = 1; usr[i] != '\0' && noSymb; i++) {
    if ((usr[i] >= 'a' && usr[i] <= 'z') || (usr[i] >= 'A' && usr[i] <= 'Z'))
      cl++;

    for (j = 0; symb[j] != '\0' && noSymb; j++)
      if (usr[i] == symb[j])
        noSymb = 0;
  }

  return i >= n && cl >= nl && noSymb;
}
