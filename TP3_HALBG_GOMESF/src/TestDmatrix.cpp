#include "Darray.h"
#include "Dvector.h"
#include "Dmatrix.h"
#include <iostream>
#include <cstdlib>


int main() {

  Dmatrix M1(2, 2, 1);
  std::cout << "M1 :"<< std::endl << M1 << std::endl;
  
  Dmatrix M2;
  std::cout << "M2 :"<< std::endl << M2 << std::endl;

  Dmatrix M3(M1);
  std::cout << "M3 :"<< std::endl << M3 << std::endl;
  
}
