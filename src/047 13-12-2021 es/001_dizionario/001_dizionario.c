#include <stdio.h>
#define FN "dizionario.txt"
#define MAXS 35

/*
  Scrivere un programma che trova e visualizza tutti i vocaboli di un dizionario
  (file di testo ASCII dizionario.txt) in cui tutte le vocali presenti compaiono
  in ordine lessicografico crescente. Non è necessario che compaiano tutte le
  vocali e la stessa vocale può comparire più volte. Nel file, ogni vocabolo
  compare su una riga nuova, ed ogni vocabolo è al più lungo 35 caratteri (e
  ovviamente contiene almeno una vocale). I caratteri sono tutti minuscoli e non
  accentati. Per esempio, i vocaboli alta, arte vengono visualizzati, il
  vocabolo idea no.
*/

int eVocale(char c);

int main() {
  FILE *fp;
  char parola[MAXS + 1], vocalePrec;
  int i, ok;

  fp = fopen(FN, "r");

  if (fp) {
    fscanf(fp, "%s", parola);

    while (!feof(fp)) {
      for (i = 0, ok = 1, vocalePrec = 'a'; parola[i] != '\0' && ok; i++) {
        if (eVocale(parola[i])) {
          if (vocalePrec > parola[i])
            ok = 0;
          else
            vocalePrec = parola[i];
        }
      }

      if (ok)
        printf("%s\n", parola);

      fscanf(fp, "%s", parola);
    }

    fclose(fp);
  } else
    printf("Errore file.\n");

  return 0;
}

int eVocale(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
