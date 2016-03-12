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
#include "Darray.h"

using namespace std;
using std::ifstream; 


Dvector::Dvector():Darray::Darray() 
{}

Dvector::Dvector(int d, double val):Darray::Darray(d, val)
{}

Dvector::~Dvector() 
{}

Dvector::Dvector(const Darray & A):Darray::Darray(A)
{}

Dvector::Dvector(std::string s):Darray::Darray(s)
{}

double operator *(const Dvector &A, const Dvector &B )
{
  if (A.size() != B.size()) 
    throw invalid_argument("Dimensions non compatibles");
  
  double sum = 0;
  for (int i = 0; i < A.size(); i++) 
    sum += A(i)*B(i);
  
  return sum;
}

void Dvector::display (std::ostream &str) const 
{
  for (int i = 0; i < dim; i++) 
      str<<coord[i]<<std::endl;
}

ostream & operator <<(ostream &Out, const Dvector &A)
{
  A.display(Out);
  return Out;
}
