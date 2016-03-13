#ifndef INTERSECCIO_H
#define INTERSECCIO_H
#include <iostream>

template<class T>
struct Interseccio {
  //Si exiteix_interseccio es false, objecte_interseccio es la clase que li pasarem
  //a l'hora de crearla amb el constructor per defecte.
  //Per tant haurem de contemplar que existeixi per no agafar una capça erronia.
  bool existeix_interseccio;
  T objecte_interseccio;
};

#endif
