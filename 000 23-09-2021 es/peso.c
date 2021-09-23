#include <stdio.h>

// Nel testo manca il fatto che il peso debba essere una valore float
int main() {
  int n_oggetti;
  float peso_oggetto, peso_totale;

  // => operazione fra tipi eterogenei

  scanf("%d %f", &n_oggetti, &peso_oggetto);

  // in questo caso avviene un cast di tipo implicito:
  /* 
    In questo caso avviene un cast di tipo implicito: il compilatore converte automaticamente
    i valori secondo il seguente ordine
      char < int < float < double
    => nel nostro caso n_oggetti (int) viene convertito in float

    Nel passaggio fra int e float può esserci una perdita di informazione, perché andiamo a 
    troncare il valore nel passaggio a virgola fissa.

    Se invece forziamo la conversione ad andare nell'altro verso, si ha un troncamento:
    Esempio:
      int a;
      float b;
      a = b;
    b viene convertito in int
  */
  peso_totale = n_oggetti * peso_oggetto;

  printf("%f\n", peso_totale);

  return 0;
}