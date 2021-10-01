#include <stdio.h>

int main() {
  int i;

  /* Ciclo for */
  for (i = 0 /*, ...*/; i < 5; i++ /*, ...*/) {
    /* corpo */
  }

  /*
    INCREMENTI
    i++ ritorna i, poi esegue i = i+1;
    ++i esegue i = i+1, poi ritorna i;
    Mai usarli in espressioni complesse, per evitare problemi.
  */
  return 0;
}
