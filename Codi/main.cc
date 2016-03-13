#include <iostream>
#include "Capsa.h"
#include "Cercle.h"

void capsa_tests() {
  cout<<"///////////////////// CAPSA /////////////////////"<<endl;
  cout<<"\n----- Creant Capsa amb punts a l'origen -----"<<endl;
  Capsa c;
  cout<<"c = "<<c<<endl;

  cout<<"\n----- Creant capça mitjançant 2 punts -----"<<endl;
  Capsa c2(Punt(1,1), Punt(4,4));
  cout<<"c2 = "<<c2<<endl;

  cout<<"\n----- Creant per còpia -----"<<endl;
  Capsa c3(c2);
  cout<<"c3 = "<<c3<<endl;

  cout<<"\n----- Modificant minim c -----"<<endl;
  c.set_pmin(Punt(1,2));
  cout<<"c = "<<c<<endl;

  cout<<"\n----- Modificant màxim c -----"<<endl;
  c.set_pmax(Punt(3,3));
  cout<<"c = "<<c<<endl;

  cout<<"\n----- Consultant minim de c -----"<<endl;
  cout<<c.get_pmin()<<endl;

  cout<<"\n----- Consultant màxim de c -----"<<endl;
  cout<<c.get_pmax()<<endl;

  cout<<"\n----- Consultant dimensions de c ----- "<<endl;
  cout<<"width = "<<c.dimensions().width<<" height = "<<c.dimensions().height<<endl;

  cout<<"\n----- Consultant si un punt està dins la capsa c2 ----- "<<endl;
  Punt p(3,3);
  if (c.esta_dins(p)) {
    cout<<"El punt "<<p<<" està dins de "<<c2<<" "<<endl;
  } else {
    cout<<"El punt "<<p<<" no està dins de "<<c2<<endl;
  }

  cout<<"\n----- Mirant si c1 i c2 creant interseccio -----"<<endl;
  Interseccio<Capsa> interseccio = c2.interseccio(c);
  cout<<interseccio.objecte_interseccio<<endl;
  //TODO
}

void cercle_tests() {
  cout<<"///////////////////// Cercle /////////////////////"<<endl;
  cout<<"\n----- Creant cercle amb punts a l'origen -----"<<endl;
  Cercle c;
  cout<<"c = "<<c<<endl;

  cout<<"\n----- Creant cercle mitjançant centre i radi -----"<<endl;
  Cercle c2(Punt(2,2), 0.495);
  cout<<"c2 = "<<c2<<endl;

  cout<<"\n----- Creant per còpia -----"<<endl;
  Cercle c3(c2);
  cout<<"c3 = "<<c3<<endl;

  cout<<"\n----- Modificant centre de c -----"<<endl;
  c.set_center(Punt(0.5,0.5));
  cout<<"c = "<<c<<endl;

  cout<<"\n----- Modificant radi de c -----"<<endl;
  c.set_radi(0.75);
  cout<<"c = "<<c<<endl;

  cout<<"\n----- Consultant centre de c -----"<<endl;
  cout<<"c = "<<c.get_center()<<endl;

  cout<<"\n----- Consultant radi de c -----"<<endl;
  cout<<"c = "<<c.get_radi()<<endl;

  cout<<"\n----- Consultant si un punt està dins el cercle -----"<<endl;
  Punt p(2,2.5);
  if (c.esta_dins(p)) {
    cout<<"El punt "<<p<<" està dins de "<<c2<<" "<<endl;
  } else {
    cout<<"El punt "<<p<<" no està dins de "<<c2<<endl;
  }

  cout<<"\n----- Consultant si dos cercles s'intersecten -----"<<endl;
  if (c2.cercle_interseccio(c)) {
    cout<<"Existeix interseccio"<<endl;
  } else {
    cout<<"No existeix interseccio"<<endl;
  }

  cout<<"\n----- Capça mínima -----"<<endl;
  cout<<c2.capsa_minima()<<endl;

  cout<<"\n----- Capça màxima -----"<<endl;
  cout<<c2.capsa_maxima()<<endl;

}

int main() {

  capsa_tests();
  cercle_tests();
  return 0;
}
