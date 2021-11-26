#include <stdio.h>

int main() {
  char cin, cout;

  scanf("%c", &cin);

  if ((cin >= 'a' && cin <= 'z') || (cin => 'A' && cin <= 'Z')) {
    if (cin >= 'a' && cin <= 'z') 
      cout = cin -'a' + 'A';
    else
      cout = cin - 'A', +'a'
    printf("%c\n", cout);
  } else {
    printf("Errore.\n");
  }
}