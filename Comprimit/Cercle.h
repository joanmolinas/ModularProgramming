#ifndef CERCLE_H
#define CERCLE_H

#include <iostream>
#include "Punt.h"
#include "Capsa.h"
using namespace std;

class Cercle {
  /*

  Model: dades
  Descripció: Un cercle està format per un punt central i un radi.

                  o  o
               o        o
              o  center  o
              o     .    o
              o  rad|    o
               o    |   o
                  o  o

  */


private:
  Punt centre;
  float radi, longitud, area;
  void _init(const Punt &p, const float &radi);
  /* Pre: cert */
  /* Post: crea el cercle */

  void _actualitzar();
  /* Pre: cert */
  /* Post: Actualitza l'area i la longitud */

public:

  ///Constructors
  Cercle();
  /* Pre: cert */
  /* Post: Crea un cercle amb el centre a l'origen i radi 0 */

  Cercle(Punt center, float radi);
  /* Pre: cert */
  /* Post: Crea un cercle amb el centre i radi passats com a paràmetres */
  Cercle(const Cercle &c);
  /* Pre: cert */
  /* Post: Crea un cercle amb el centre i radi de c*/

  ///Destructor
  ~Cercle();
  /* Post: esborra automaticament els objectes locals en sortir d'un ambit
   de visibilitat */

  ///Setters
  void set_center(Punt center);
  /* Pre: cert */
  /* Post: El center de p.i. passa a ser el paràmetre center */

  void set_radi(float radi);
  /* Pre: radi > 0 */
  /* Post: El radi de p.i. passa a el paràmetre radi */

  ///Getters
  Punt get_center() const;
  /* Pre: cert */
  /* Post: Retorna el centre */

  float get_radi() const;
  /* Pre: cert */
  /* Post: Retorna el radi */

  float get_longitud() const;
  /* Pre: cert */
  /* Post: Retorna la longitud */

  float get_area() const;
  /* Pre: cert */
  /* Post: retorna l'àrea */

  bool esta_dins(const Punt &p) const;
  /* Pre: cert */
  /* Post: Retorna si el punt p està dins del cercle */

  bool cercle_interseccio(const Cercle &c) const;
  /* Pre: cert */
  /* Post: Retorna si entre els p.i. i c formen una intersecció. */

  Capsa capsa_minima() const;
  /* Pre: cert */
  /* Post:
          o  o
       o ______ o
      o |      | o
      o |      | o
       o|______|o
          o  o


  */
  Capsa capsa_maxima() const;
  /* Pre: cert */
  /* Post:
      _____________
     |    o  o    |
     | o        o |
     |o          o|
     |o          o|
     | o        o |
     |    o  o    |
      _____________
  */

  ///Lectura i escriptura
  friend ostream& operator<<(ostream &os, const Cercle &c);
  /* Pre: cert (completem els detalls de format quan coneguem la
     implementacio) */
  /* Post: s'han escrit els atributs del canal c al canal estandard de
     sortida */

   friend istream& operator>>(istream &is, Cercle &c);
   /* Pre: cert */
   /* Post: El cercle passa a tenir els dos punts introduits pel canal
   d'entrada */

};

#endif
