#ifndef CAPSA_H
#define CAPSA_H

#include <iostream>
#include "Punt.h"
#include "Interseccio.h"
using namespace std;

class Capsa;

struct Dimensio {
  float width, height;
};

class Capsa {

  /*

  Model: dades
  Descripció: Una capsa està formada per dos punts cartesians
  en 2D, té un punt inicial i un punt final, aquest últim es
  calcula fent servir el witdth i el height.

      -------------------- * pmax
      |                    |
      |                    |
      |                    |
      * --------------------
    pmin

  */

private:
  Punt pmin, pmax;
  Dimensio dimensio;

  void _init(const Punt &pmin, const Punt &pmax);
  /* Pre: cert */
  /* Post: crea la capça */

  void _actualitza_dimensions();
  /* Pre: cert */
  /* Post: Actualitza la dimensió */

  void _actualitza_punts();
  /* Pre: cert */
  /* Post: Si el pmin es més gran que el pmax els canviarà, si no els deixarà com estan */

public:

  ///Constructors
  Capsa();
  /* Pre: cert */
  /* Post: Crea una capsa amb les 4 coordenades a l'origen (0,0) */

  Capsa(Punt pmin, Punt pmax);
  /* Pre: El primer punt ja serà el punt mínim i el segon el màxim */
  /* Post: Crea una capsa a partir de 2 punts Pmin i Pmax */

  Capsa(const Capsa &c);
  /* Pre: cert */
  /* Post: Crea una capsa amb les coordenades de c */

  ///Destructor
  ~Capsa();
  /* Post: esborra automaticament els objectes locals en sortir d'un ambit
   de visibilitat */

   ///Setters
   void set_pmin(Punt min);
   /* Pre: En nou punt min serà més petit que el màxim actual, es recomana
   primer canviar el mínim, i després el màxim, si s'introdueixen unes coordenades
   incorrectes (pmin > pmax...) la capça no serà vàlida per treballar.*/
   /* Post: El pmin de p.i. agafa el valor de  min */

   void set_pmax(Punt max);
   /* Pre: En nou punt max serà més gran que el mínim actual, es recomana
   primer canviar el mínim, i després el màxim, si s'introdueixen unes coordenades
   incorrectes (pmin > pmax...) la capça no serà vàlida per treballar.*/
   /* Post: El pmax de p.i. gafa el valor de max */

   ///Getters
   Punt get_pmin() const;
   /* Pre: cert */
   /* Post: Retorna el pmin */

   Punt get_pmax() const;
   /* Pre: cert */
   /* Post: Retorna el pax */

   Dimensio dimensions() const;
   /* Pre: cert */
   /* Post: Retorna les dimensions de la capsa */

   bool esta_dins(const Punt &p) const;
   /* Pre: cert */
   /* Post: Retorna si el punt p està dins de la capsa */

   Interseccio<Capsa> interseccio(const Capsa &c) const;
   /* Pre: cert */
   /* Post: Si hi ha intersecció, existeix_interseccio val true i retorna una
            capça amb les coordenades de l'intersecció, si no, existeix_interseccio
            val false i retorna una capça amb punts a l'origen. */


   ///Lectura i escriptura
   friend ostream& operator<<(ostream &os, const Capsa &c);
   /* Pre: cert (completem els detalls de format quan coneguem la
      implementacio) */
   /* Post: s'han escrit els atributs del canal c al canal estandard de
      sortida */

    friend istream& operator>>(istream &is, Capsa &c);
    /* Pre: cert */
    /* Post: La capsa c passa a tenir els dos punts introduits pel canal
    d'entrada */

};
#endif
