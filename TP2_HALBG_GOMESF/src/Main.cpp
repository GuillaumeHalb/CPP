/*!
 * \file main.cpp
 * \brief fichier main testant les fonctions demandées
 * \author Halb Guillaume, Gomes Filipe
 */

#include "Dvector.h"
#include <iostream>
#include <cstdlib>

int main() {
  Dvector v1(1);
  v1(0) = 0.0;
  const Dvector v2(1);
  double val = v2(0);
  std::cout << val<<std::endl;
}

