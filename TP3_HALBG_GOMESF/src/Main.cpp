/*!
 * \file main.cpp
 * \brief fichier main testant les fonctions demandées
 * \author Halb Guillaume, Gomes Filipe
 */

#include "Darray.h"
#include <iostream>
#include <cstdlib>
#include "Dvector.h"

int main() {
  // refaire les tests de Darray

  // Test de Dvector par héritage

  Dvector V1(5, 3.0);
  std::cout << "V1" << std::endl;
  V1.display(std::cout);
  Dvector V2(V1);
  std::cout << "V2" << std::endl;
  V2.display(std::cout);
  Dvector V3(5);
  std::cout << "V3" << std::endl;
  V3.display(std::cout);
  Dvector V4;
  std::cout << "V4" << std::endl;
  V4.display(std::cout);

  double d = V1*V3;
  std::cout << "d = " << d << std::endl;
}

