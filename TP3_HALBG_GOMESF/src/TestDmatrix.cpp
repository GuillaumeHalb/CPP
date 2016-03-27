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


  M3(1,1) = 2;
  M3(0, 1) = 3;
  std::cout << "M3 :"<< std::endl << M3 << std::endl;
  

  Dvector C;
  C = M3.column(0);
  std::cout << "Colonne 0 :" << std::endl << C << std::endl;

  C = M3.column(1);
  std::cout << "Colonne 1 :" << std::endl << C << std::endl;

  C = M3.line(0);
  std::cout << "Ligne 0 :" << std::endl << C << std::endl;

  C = M3.line(1);
  std::cout << "Ligne 1 :" << std::endl << C << std::endl;

  C(0) = 1;
  C(1) = 1;
  std::cout << "C :"<< std::endl << C << std::endl;

  Dvector Res;
  Res = C*M1;
  std::cout << "Res :" << std::endl << Res << std::endl;

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      M1(i,j) = 2*i + j;
  std::cout << "M1 :"<< std::endl << M1 << std::endl;
  Res = M1*C;
  std::cout << "Res :" << std::endl << Res << std::endl;

  M3 = M1*M1;
  std::cout << "M3 :"<< std::endl << M3 << std::endl;

  M3.transpose();
  std::cout << "M3 :"<< std::endl << M3 << std::endl;

  Dmatrix L(3,3, 0);
  L(0,0) = 1;
  L(1,0) = 2;
  L(2,0) = 3;
  L(1,1) = 4;
  L(2,1) = 5;
  L(2,2) = 6;
  std::cout << "L :"<< std::endl << L << std::endl;
  

  Dmatrix LT (3,3, 0); 
  LT = L.transpose();
  L.transpose();
  std::cout << "LT :"<< std::endl << LT << std::endl;
  
  Dmatrix A(3,3, 0);
  A = L*LT;
  std::cout << "A :"<< std::endl << A << std::endl;

  L = A.cholesky();
  std::cout << "Cholesky :"<< std::endl << L << std::endl;

}
