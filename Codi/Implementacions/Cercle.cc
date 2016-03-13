#include "Cercle.h"
#include <math.h>

///Constructors
Cercle::Cercle()
/* Pre: cert */
/* Post: Crea un cercle amb el centre a l'origen i radi 0 */
{
  this->_init(Punt(0,0), 0);
}

Cercle::Cercle(Punt center, float radi)
/* Pre: cert */
/* Post: Crea un cercle amb el centre i radi passats com a paràmetres */
{
  this->_init(center, radi);
}
Cercle::Cercle(const Cercle &c)
/* Pre: cert */
/* Post: Crea un cercle amb el centre i radi de c*/
{
  this->_init(c.get_center(), c.get_radi());
}

///Destructor
Cercle::~Cercle()
/* Post: esborra automaticament els objectes locals en sortir d'un ambit
 de visibilitat */
 {

 }

///Setters
void Cercle::set_center(Punt center)
/* Pre: cert */
/* Post: El center de p.i. passa a ser el paràmetre center */
{
  this->centre = center;
  this->_actualitzar();
}

void Cercle::set_radi(float radi)
/* Pre: radi > 0 */
/* Post: El radi de p.i. passa a el paràmetre radi */
{
  if (radi < 0) { return; }
  this->radi = radi;
  this->_actualitzar();
}

///Getters
Punt Cercle::get_center() const
/* Pre: cert */
/* Post: Retorna el centre */
{
  return this->centre;
}

float Cercle::get_radi() const
/* Pre: cert */
/* Post: Retorna el radi */
{
  return this->radi;
}

float Cercle::get_longitud() const
/* Pre: cert */
/* Post: Retorna la longitud */
{
  return this->longitud;
}

float Cercle::get_area() const
/* Pre: cert */
/* Post: retorna l'àrea */
{
  return 0;
}

bool Cercle::esta_dins(const Punt &p) const
/* Pre: cert */
/* Post: Retorna si el punt p està dins del cercle */
{
  bool dins = false;
  if (centre.distancia(p) <= radi) {
    dins = true;
  }
  return dins;
}

bool Cercle::cercle_interseccio(const Cercle &c) const
/* Pre: cert */
/* Post: Retorna si entre els p.i. i c formen una intersecció. */
{
  bool intersecta = false;
  float distancia_entre_centres = centre.distancia(c.get_center());
  if (distancia_entre_centres < radi+c.get_radi()) {
    intersecta = true;
  }
  return intersecta;
}

Capsa Cercle::capsa_minima() const
/* Pre: cert */
/* Post:
        o  o
     o ______ o
    o |      | o
    o |      | o
     o|______|o
        o  o
*/
{
  float catet = sqrt(radi);
  float x = centre.coordenadax();
  float y = centre.coordenaday();
  float x_inicial = x-catet;
  float y_inicial = y-catet;
  float x_final = x+catet;
  float y_final = y+catet;

  Punt inicial(x_inicial, y_inicial);
  Punt final(x_final, y_final);

  Capsa minima(inicial, final);
  return minima;
}
Capsa Cercle::capsa_maxima() const
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
{

  float costat_quadrat = radi*2;
  float x = centre.coordenadax();
  float y = centre.coordenaday();
  float x_inicial = x-costat_quadrat;
  float y_inicial = y-costat_quadrat;
  float x_final = x+costat_quadrat;
  float y_final = y+costat_quadrat;

  Punt inicial(x_inicial, y_inicial);
  Punt final(x_final, y_final);

  Capsa maxima(inicial, final);
  return maxima;
  return Capsa();
}

///Lectura i escriptura
ostream& operator<<(ostream &os, const Cercle &c)
/* Pre: cert (completem els detalls de format quan coneguem la
   implementacio) */
/* Post: s'han escrit els atributs del canal c al canal estandard de
   sortida */
{
  os<<c.get_center()<<" "<<"("<<c.get_radi()<<")"<<endl;
  return os;
}

 istream& operator>>(istream &is, Cercle &c)
 /* Pre: cert */
 /* Post: El cercle passa a tenir els dos punts introduits pel canal
 d'entrada */
{
  Punt centre;
  float radi;
  is>>centre>>radi;
  c.set_center(centre);
  c.set_radi(radi);
  return is;
}

///Private API
void Cercle::_init(const Punt &p, const float &radi)
/* Pre: cert */
/* Post: crea el cercle */
{
  this->centre = p;
  this->radi = radi;
  this->_actualitzar();
}

void Cercle::_actualitzar()
/* Pre: cert */
/* Post: Actualitza l'area i la longitud */
{
  this->longitud = radi*2;
  this->area = pow(radi,2)*M_PI;
}
