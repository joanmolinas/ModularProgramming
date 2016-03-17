#include "Capsa.h"

///Constructors
Capsa::Capsa()
/* Pre: cert */
/* Post: Crea una capsa amb les 4 coordenades a l'origen (0,0) */
{
  this->_init(Punt(),Punt(0,0));
}

Capsa::Capsa(Punt pmin, Punt pmax)
/* Pre: El primer punt ja serà el punt mínim i el segon el màxim */
/* Post: Crea una capsa a partir de 2 punts Pmin i Pmax */
{
  this->_init(pmin, pmax);
}

Capsa::Capsa(const Capsa &c)
/* Pre: cert */
/* Post: Crea una capsa amb les coordenades de c */
{
  this->_init(c.get_pmin(), c.get_pmax());
}

///Destructor
Capsa::~Capsa()
/* Post: esborra automaticament els objectes locals en sortir d'un ambit
 de visibilitat */
{
}

///PUBLIC API
///Setters
 void Capsa::set_pmin(Punt min)
 /* Pre: En nou punt min serà més petit que el màxim actual, es recomana
 primer canviar el mínim, i després el màxim, si s'introdueixen unes coordenades
 incorrectes (pmin > pmax...) la capça no serà vàlida per treballar.*/
 /* Post: El pmin de p.i. agafa el valor de  min */
 {
   this->pmin = min;
   this->_actualitza_dimensions();
 }

 void Capsa::set_pmax(Punt max)
 /* Pre: En nou punt max serà més gran que el mínim actual, es recomana
 primer canviar el mínim, i després el màxim, si s'introdueixen unes coordenades
 incorrectes (pmin > pmax...) la capça no serà vàlida per treballar.*/
 /* Post: El pmax de p.i. gafa el valor de max */
 {
   this->pmax = max;
   this->_actualitza_dimensions();
 }

 //Getters
 Punt Capsa::get_pmin() const
 /* Pre: cert */
 /* Post: Retorna el pmin */
 {
   return this->pmin;
 }

 Punt Capsa::get_pmax() const
 /* Pre: cert */
 /* Post: Retorna el pax */
 {
   return this->pmax;
 }

 Dimensio Capsa::dimensions() const
 /* Pre: cert */
 /* Post: Retorna les dimensions de la capsa */
 {
   return this->dimensio;
 }
 bool Capsa::esta_dins(const Punt &p) const
 /* Pre: cert */
 /* Post: Retorna si el punt p està dins de la capsa */
 {
   bool dins_vertical = pmin.coordenadax() <= p.coordenadax() &&
   pmax.coordenadax() >= p.coordenadax();
   bool dins_horitzontal = pmin.coordenaday() <= p.coordenaday() &&
   pmax.coordenaday() >= p.coordenaday();

   return dins_vertical && dins_horitzontal;
 }

 Interseccio<Capsa> Capsa::interseccio(const Capsa &c) const
 /* Pre: cert */
 /* Post: Si hi ha intersecció, existeix_interseccio val true i retorna una
          capça amb les coordenades de l'intersecció, si no, existeix_interseccio
          val false i retorna una capça amb punts a l'origen. */

 {
   Interseccio<Capsa> interseccio;

   float x_inicial = max(pmin.coordenadax(), c.get_pmin().coordenadax());
   float y_inicial = max(pmin.coordenaday(), c.get_pmin().coordenaday());
   float x_final = min(pmax.coordenadax(), c.get_pmax().coordenadax());
   float y_final = min(pmax.coordenaday(), c.get_pmax().coordenaday());
   Punt inici(x_inicial, y_inicial);
   Punt final(x_final, y_final);
   Capsa inter(inici, final);

   bool x_dins_pi = this->esta_dins(inici);
   bool y_dins_pi = this->esta_dins(final);
   bool x_dins_par = c.esta_dins(inici);
   bool y_dins_par = c.esta_dins(final);


   interseccio.existeix_interseccio = x_dins_pi && y_dins_pi && x_dins_par && y_dins_par;
   interseccio.objecte_interseccio = inter;

   return interseccio;
 }

 ///Lectura i escriptura
 ostream& operator<<(ostream &os, const Capsa &c)
 /* Pre: cert*/
 /* Post: s'han escrit els atributs del canal c al canal estandard de
    sortida */
  {
    os<<c.get_pmin()<<" "<<c.get_pmax();
    return os;
  }

  istream& operator>>(istream &is, Capsa &c)
  /* Pre: cert */
  /* Post: La capsa c passa a tenir els dos punts introduits pel canal
  d'entrada */
  {
    Punt min;
    Punt max;
    is>>min>>max;
    c.set_pmin(min);
    c.set_pmax(max);
    return is;
  }

 ///PRIVATE API
 void Capsa::_init(const Punt &pmin, const Punt &pmax)
 /* Pre: cert */
 /* Post: crea la capça */
 {
   this->pmin = pmin;
   this->pmax = pmax;
   this->_actualitza_dimensions();
 }


 void Capsa::_actualitza_dimensions()
 /* Pre: cert */
 /* Post: Actualitza la dimensió */
 {

   this->dimensio.width = pmax.coordenadax() - pmin.coordenadax();
   this->dimensio.height = pmax.coordenaday() - pmin.coordenaday();
 }
