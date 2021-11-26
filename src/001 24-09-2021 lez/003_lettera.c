#include <stdio.h>

/*
  Scrivere un programma che chiede all'utente un carattere. Il
  programma verifica se il carattere sia una lettera dell'alfabeto. In
  caso positivo, se la lettera è minuscola, il programma la converte
  nella corrispondente maiuscola, altrimenti la converte nella
  corrispondente minuscola, visualizzando infine il risultato. In caso
  il carattere non sia una lettera il programma visualizza un apposito
  messaggio di errore.
*/

int main() {
  char cin, cout;

  scanf("%c", &cin);

  if ((cin >= 'a' && cin <= 'z') || (cin >= 'A' && cin <= 'Z')) {

    if (cin >= 'a' && cin <= 'z')
      cout = cin - 'a' + 'A';
    else
      cout = cin - 'A' + 'a';

    printf("%c\n", cout);
  } else
    printf("Errore.\n");
}
