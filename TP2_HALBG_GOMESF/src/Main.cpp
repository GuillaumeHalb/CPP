/*!
 * \file main.cpp
 * \brief fichier main testant les fonctions demandées
 * \author Halb Guillaume, Gomes Filipe
 */

#include "Dvector.h"
#include <iostream>
#include <cstdlib>

int main() {
  Dvector v(3,4);  
  Dvector v1(3,4);  
  Dvector res(2);

  /* Test de l'operateur d'accession */
  std::cout << "ACCESSION :" << std::endl; 
  for (int i = 0; i < v.size(); i++)
    std::cout << "v(" << i << ") = " << v(i) << std::endl;
  for (int i = 0; i < v.size(); i++)
    {
      v(i) = i;
      std::cout << "v(" << i << ") = " << v(i) << std::endl;
    }
  // Cas limite (3 > dim ) 
  // std::cout << "v(3) = " << v(3) << std::endl;


  std::cout << "OPERATEURS STANDARDS" << std::endl; 
  std::cout << "CAS REEL" << std::endl;

  std::cout << "ADDITION : v + 2.5" << std::endl;
  res = v + 2.5;
  res.display(std::cout);
  std::cout << "SOUSTRACTION : v - 2.0" << std::endl;
  res = v - 2.0;
  res.display(std::cout);
  std::cout << "MULTIPLICATION : v * 2" << std::endl;
  res = v*2;
  res.display(std::cout);
  std::cout << "DIVISION : v / 2.0" << std::endl;
  res = v/2.0;
  res.display(std::cout);

  std::cout << "CAS VECTORIEL" << std::endl;

  std::cout << "ADDITION : v + v1" << std::endl;
  res = v + v1;
  res.display(std::cout);
  std::cout << "SOUSTRACTION : v - v1" << std::endl;
  res = v - v1;
  res.display(std::cout);
  std::cout << "UNAIRE - : -v" << std::endl;
  res = -v;
  res.display(std::cout);


  std::cout << "OPERATEUR <<" << std::endl;
  std::cout << v;

  std::cout << "OPERATEUR >>" << std::endl;
  std::cin >> res;
  res.display(std::cout);

  std::cout << "OPERATEUR +=" << std::endl;
  std::cout << "res += 5" << std::endl;
  res += 5;
  std::cout << res;
  std::cout << "res += res" << std::endl;
  res += res;
  std::cout << res;
  std::cout << "OPERATEUR -=" << std::endl;
  std::cout << "res -= res" << std::endl;
  res -= res;
  std::cout << res;
  std::cout << "res -= 5.3" << std::endl;
  res -= 5.3;
  std::cout << res;
  std::cout << "OPERATEUR *=" << std::endl;
  std::cout << "res *= 2" << std::endl;
  res *= 2;
  std::cout << res;
  std::cout << "OPERATEUR /=" << std::endl;
  std::cout << "res /= 2" << std::endl;
  res /= 2;
  std::cout << res;
  
  std::cout << "OPERATEUR ==" << std::endl;
  if (res == res)
    std::cout << "res == res" << std::endl;
  if (res != v1)
    std::cout << "res != v1" << std::endl;

  std::cout << "resize()" << std::endl;
  std::cout << "Avant resize, res = " << std::endl << res;
  res.resize(res.size() - 1, 20);
  std::cout << "Après 1er resize, res = " << std::endl << res;
  res.resize(res.size(), 103);
  std::cout << "Après 2e resize, res = " << std::endl << res;
  res.resize(res.size() + 1, 5);
  std::cout << "Après 3e resize, res = " << std::endl << res;

  //Dvector v(1000000,5);
  //Dvector v1;
  
  //v1 = v;

}

