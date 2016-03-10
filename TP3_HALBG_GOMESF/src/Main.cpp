/*!
 * \file main.cpp
 * \brief fichier main testant les fonctions demandées
 * \author Halb Guillaume, Gomes Filipe
 */

#include "Darray.h"
#include <iostream>
#include <cstdlib>

int main() {
  Darray v1(1);
  v1(0) = 0.0;
  const Darray v2(1);
  double val = v2(0);
  std::cout << val <<std::endl;
  
  /* Test opérateurs binaires */
  Darray vect1(3, 6);
  Darray vect2(3, 2);
  Darray res(3);
  double scal = 2.0;
  
  std::cout << "test de: + "<<std::endl;
  vect1.display(std::cout);
  res = vect1 + scal;
  res.display(std::cout);
}

