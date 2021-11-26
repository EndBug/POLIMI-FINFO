/*
  Da esame del 20/01/2020 della prof.ssa Cristiana Bolchini
  https://bolchini.faculty.polimi.it/exams/20200120.pdf
  -> Quesito 2
*/

/*
  In esame non è necessario mettere gli #include, aggiungere il main, o dare un 
  valore esplicito alle #define, a meno che non venga chiesto dal testo.
*/

#define NR /* <int> */
#define NC /* <int> */

int analizza(int m[][NC] int nr, int nc);

int analizza(int m[][NC] int nr, int nc) {
  int i, j, h, k, ndom, domina;

  for (i = 0, ndom = 0; i < nr-1; i++){
    for (j = 0; j < nc-1; j++) {

      for (h = i+1, domina = 1; h < nr && domina; h++) {
        for (k = j+1, k < nc && domina; k++) {
          if (m[i][j] <= m[h][k])
            domina = 0;
        }
      }

      if (domina)
        ndom++;
    }
  }

  return ndom;
}