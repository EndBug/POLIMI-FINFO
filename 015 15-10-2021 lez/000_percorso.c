#include <stdio.h>
/* ! Includendo math.h dobbiamo aggiungere -lm al comando di gcc. */
#include <math.h>

#define MAXS 30
#define MAXA 50

/* Associo alle operazioni dei numeri, in modo da potervi far riferimento più comodamente */
#define INSERISCI 1
#define AGGIUNGI 2
#define CANCELLA 3
#define VISUALIZZA 4
#define LUNGHEZZA 5
#define COPPIAMAX 6
#define USCITA 7

/*
  Si vuole realizzare un programma "interattivo" che permette di
  gestire un percorso su uno spazio bidimensionale composto da una
  lista di località.
  Dichiarare un tipo di dato per rappresentare una località su una
  cartina in termini di coordinate x e y (due interi) ed un nome (una
  stringa di al max 30 caratteri). Scrivere un programma in grado di
  gestire un massimo di 50 località. All'avvio il programma visualizza
  un menù con le seguenti funzionalità e chiede all'utente di
  selezionarne una:
  1 - Inserire in coda una nuova località
  2 - Inserire in una specificata posizione una nuova località
  3 - Cancellare una località nella lista
  4 - Visualizzare l'intero percorso
  5 - Visualizzare la lunghezza complessiva dell'itinerario
  6 - Visualizza la coppia di località (anche non consecutive nel
  percorso) la cui distanza è maggiore di qualsiasi altra coppia.
  7 - Uscita
  Implementare le funzionalità specificate come segue:
  1 - L'inserimento in coda può avvenire solo se c'è ancora spazio
  disponibile nella struttura dati, altrimenti viene visualizzato un
  messaggio di errore. In caso positivo il programma chiede all'utente
  i dati di una località e la aggiunge in fondo al percorso già
  memorizzato.
  2 - Anche l'inserimento in mezzo può avvenire solo se c'è ancora
  spazio disponibile nella struttura dati, altrimenti viene
  visualizzato un messaggio di errore. In caso positivo il programma
  chiede all'utente prima l'indice in cui inserire la nuova località e
  poi i dati della nuova località; il programma sposta in avanti tutte
  le località presenti dall'indice specificato in modo tale da creare
  spazio per i nuovi dati. Nel caso l'utente inserisca un indice non
  valido il programma visualizza un messaggio di errore e non procede
  con la richiesta dei dati e l'inserimento.
  3 - Il programma chiede all'utente l'indice della località da
  cancellare. Se l'indice è valido rimuove i dati relativi altrimenti
  visualizza un messaggio di errore.
  4 - Il programma stampa a video il percorso inserito dall'utente
  5 - Il programma calcola la distanza del percorso. La distanza tra
  due località consecutive nell'elenco è calcolata mediante il teorema
  di Pitagora. Per il calcolo della radice quadrata utilizzare la
  funzione sqrt() presente nella libreria math.h. Si noti che per
  compilare il programma quando si una la libreria matematica bisogna
  aggiungere alla fine del comando di compilazione l'argomento "-lm".
  Quindi si compilerà come "gcc distanze.c -o distante -lm"
  6 - Il programma identifica e visualizza la coppia di località
  (anche non consecutive nel percorso) la cui distanza è massima. Il
  calcolo è eseguibile solo se ci sono almeno due località inserite.
  Se ci fossero più coppie a pari distanza massima, il programma ne
  stampa una sola (VARIANTE: stampare tutte le coppie).
  Se l'utente inserisce un valore sbagliato, il programma visualizza
  un messaggio di errore e poi nuovamente il menù.
*/

/* E' un problema complesso, quindi cerchiamo di occuparci di un sottoproblema alla volta */

typedef struct {
  int x, y;
  char nome[MAXS+1];
} localita_t;

/*
  Al posto di dichiarare due variabili per salvare il numero di località e le
  località stesse, definiamo una nuova struttura che contenga entrambi.
*/
typedef struct {
  localita_t loc[MAXA];
  int dim;
} percorso_t;

int main() {
  /*
    l
    > .loc
      > [0, ..., 49]
        > .x
        > .y
        > .nome
    > .dim
  */
  percorso_t l;
  int scelta, i, j, lung_quadrato;
  float lung;

  l.dim = 0;


  do {
    printf(
      "\nMENU\n- %d: inserisci\n- %d: aggiungi\n- %d: cancella\n- %d: visualizza\n- %d: lunghezza\n- %d: distanza massima\n- %d: uscita\nCosa vuoi fare? ",
      INSERISCI,
      AGGIUNGI,
      CANCELLA,
      VISUALIZZA,
      LUNGHEZZA,
      COPPIAMAX, 
      USCITA
    );
    scanf("%d", &scelta);

    /* Qui ha usato una catena di if-elseif, ma si poteva fare con lo switch ;*/
    if (scelta == INSERISCI) {
      /* La prima cosa che dobbiamo fare è verificare che ci sia spazio. */
      if (l.dim < MAXA) {
        printf("Inserisci i dati: ");

        /* La prima posizione disponibile è [l.dim] */
        scanf("%d %d %s", &l.loc[l.dim].x, 
                          &l.loc[l.dim].y, 
                          l.loc[l.dim].nome);
        /* Dopo aver aggiunto un elemento incrementiamo l.dim */
        l.dim++;
      } else
        printf("Memoria terminata.\n");
    } else if (scelta == AGGIUNGI) {
      /* Anche qua prima controlliamo se c'è spazio.  */
      if (l.dim < MAXA) {
        /* Ora chiediamo all'utente in che indice vuole inserire il nuovo dato. */
        printf("Inserisci indice: ");
        scanf("%d", &i);

        /*
          Verifichiamo se l'indice è valido (escludiamo il caso i == l.dim, che
          corrisponde alla funzionalità "inserisci").
        */
        if (i >= 0 && i < l.dim) {
          /* Prima spostiamo tutto in avanti, poi chiediamo i nuovi dati. */
          for (j = l.dim-1; j >= i; j--)
            /* Asseganzione byte a byte */
            l.loc[j+i] = l.loc[j];

          printf("Inserisci i dati: ");
          scanf("%d %d %s", &l.loc[i].x,
                            &l.loc[i].y,
                            l.loc[i].nome);

          /* Finito tutto incrementiamo l.dim. */
          l.dim++;
        } else
          printf("Indice non valido.\n");
      } else
        printf("Memoria terminata.\n");
    } else if (scelta == CANCELLA) {
      printf("Inserisci indice: ");
      scanf("%d", &i);

      if (i >= 0 && i < l.dim) {
        /* Si può anceh già utilizzare direttamente la i al posto di j */
        for (j = i; j < l.dim-1; j++)
          l.loc[j] = l.loc[j+i];
        l.dim--;
      } else
        printf("Indice non valido.\n");      
    } else if (scelta == VISUALIZZA) {
      printf("Percorso:\n");
      for (i = 0; i < l.dim; i++)
        /* Stampiamo anche l'indice che è comodo. */
        printf("%d: %d %d %s\n", i, l.loc[i].x, 
                                    l.loc[i].y,
                                    l.loc[i].nome);
    } else if (scelta == LUNGHEZZA) {
      for (i = 0, lung = 0; i < l.dim-1; i++) {
        /* 
          Abbiamo comunque incluso math.h, però la usiamo solo per sqrt, non
          utilizziamo pow perché siamo particolarmente masochisti.
        */
        lung_quadrato = (l.loc[i].x - l.loc[i+1].x)*(l.loc[i].x - l.loc[i+1].x) 
                        + (l.loc[i].y - l.loc[i+1].y)*(l.loc[i].y - l.loc[i+1].y);
        lung += sqrt(lung_quadrato);
      }
      printf("Lunghezza: %f\n", lung);
    } else if (scelta == COPPIAMAX) {
      printf("TODO\n");
    } else if (scelta != USCITA) {
      /* 
        Se scelta == USCITA ci pensa il while a uscire, ma se non è uguale a
        nessuno dei casi validi mostriamo un errore
      */
      printf("Scelta non valida!\n");
    }
  } while (scelta != USCITA);


  return 0;
}