/*!
 * \file Dvector.cpp
 * \brief vecteur de dimension n ainsi que ses n coordoonnées
 * \author Halb Guillaume, Gomes Filipe
 */


#include <iostream>
#include "Dvector.h"
#include <cstdlib> // bibliothèque pour rand()
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;
using std::ifstream; 

/*
Dvector::Dvector() : Darray() 
{}

Dvector::Dvector(int d, double val) : Darray(int d, double val)
{}

Dvector::~Dvector() {
}

int Dvector::fillRandomly() {
  static bool init = false;
  if (!init) 
  {
    init= true;
    srand(time(0));
  }
  for (int i = 0; i < dim; i++) {
    coord[i] = (double) rand()/RAND_MAX;
  }
  return 1;
}


Dvector::Dvector(const Dvector & D) : Darray(const Dvector & D)
{}

Dvector::Dvector(std::string s) : Darray(std::string s)
{}
*/
/*
double Dvector::operator *(Dvector &A, Dvector &B )
{
  if (A.dim != B.dim) 
    throw invalid_argument("Dimensions non compatibles");
  
  double sum=0;
  for (int i=0; i<A.dim; i++) 
    sum += A.coord(i) * B.coord(i);
  
  return sum;
}
*/
