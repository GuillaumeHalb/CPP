/*!
 * \file Dmatrix.cpp
 * \brief matrice de dimension l*c ainsi que ses coordoonnées
 * \author Halb Guillaume, Gomes Filipe
 */


#include <iostream>
#include "Dmatrix.h"
#include <cstdlib> // bibliothèque pour rand()
#include <fstream>
#include <string.h>
#include <stdexcept>
#include <stdlib.h>
#include <cmath>



using namespace std;
using std::ifstream; 

Dmatrix::Dmatrix() : Darray::Darray(),
		     l(1), c(2)		     
{
}
  
Dmatrix::Dmatrix(int ligne, int column, double val): Darray::Darray(ligne*column, val),
						     l(ligne), c(column)
{
}

Dmatrix::~Dmatrix() 
{
}

Dmatrix::Dmatrix(const Dmatrix &M):  Darray::Darray(M),
				     l(M.lines()), c(M.columns())
{
}

int Dmatrix::lines() const
{
return l;
}

int Dmatrix::columns() const
{
return c;
}

double Dmatrix::operator()(int line, int column) const 
{
if (line < 0 || line > l || column < 0 || column > c)
  throw invalid_argument("Argument(s) invalide(s)");
 else
   return coord[line*c + column];
}

double &Dmatrix::operator()(int line, int column) 
{
if (line < 0 || line > l || column < 0 || column > c)
  throw invalid_argument("Argument(s) invalide(s)");
 else
   return coord[line*c + column];
}

Dmatrix& Dmatrix::operator = (const Dmatrix &M)
{
if (this != &M) 
  {
if (l != M.lines() || c != M.columns())
  throw invalid_argument("Nombre de lignes ou de colonnes non égaux");
 else
   memcpy(this->coord, M.coord,  c*l*sizeof(double));
}
return (*this);
}

Dvector Dmatrix::line(int line) const
{
if (line < 0 || line >= l)
  throw invalid_argument("Argument invalide");
Dvector V(c);
for (int j = 0; j < c; j++)
  V(j) = (*this)(line, j);
return V;
}

Dvector Dmatrix::column(int column) const
{
if (column < 0 || column >= c)
  throw invalid_argument("Argument invalide");
Dvector V(l);
for (int i = 0; i < l; i++)
  V(i) = (*this)(i, column);
return V;
}

Dvector operator * (const Dvector &V, const Dmatrix &M)
{
if (M.lines() != V.size()) 
  throw invalid_argument("Argument invalide");
Dvector Res(M.columns(), 0);
for (int i = 0; i < M.lines(); i++)
  for (int j = 0; j < M.columns(); j++)
    Res(i) += M(i,j) * V(j);
return Res;
}

Dvector operator * (const Dmatrix &M, const Dvector &V)
{
if (M.columns() != V.size()) 
  throw invalid_argument("Argument invalide");
Dvector Res(M.lines(), 0);
for (int i = 0; i < M.lines(); i++)
  for (int j = 0; j < M.columns(); j++)
    Res(i) += M(i,j) * V(i);
return Res;
}

Dmatrix operator * (const Dmatrix &M1, const Dmatrix &M2)
{
if (M1.columns() != M2.lines())
  throw invalid_argument("Argument invalide");

Dmatrix Res(M1.lines(), M2.columns(), 0);

// Res(i,j) = sum(k=1..N) M1(i,k)*M2(k,j)

for (int i = 0; i < Res.lines(); i++)
  for (int j = 0; j < Res.columns(); j++)
    for (int k = 0; k < M1.columns(); k++)
      Res(i,j) += M1(i,k)*M2(k,j);
return Res;
}

Dmatrix& Dmatrix::transpose()
{
Dmatrix Res(c,l);
for (int i = 0; i < Res.lines(); i++)
  for (int j = 0; j < Res.columns(); j++)
    Res(i,j) = (*this)(j,i);

*this = Res;
return (*this);
}

ostream & operator <<(ostream &Out, const Dmatrix &M)
{
M.display(Out);
return Out;
}

void Dmatrix::display (std::ostream &str) const 
{
for (int i = 0; i < l; i++) 
  {
for (int j = 0; j < c; j++)
  str << coord[c*i + j] << "    ";
str << endl;
}
}

Dmatrix Dmatrix::cholesky() {
  
if (l != c)
  throw invalid_argument("Matrice non carrée");

Dmatrix L(l,l, 0);
  
for (int k = 0; k < l; k++) 
  {
double somme = 0;
for (int s = 0; s < k; s++) {
somme += L(k,s)*L(k,s);
}
double soustraction = (*this)(k,k) - somme;
L(k,k) = sqrt(soustraction);

for (int i = k + 1; i < l; i++) 
  {
for (int s = 0; s < k; s++) {
somme += L(i,s)*L(k,s);
}
soustraction = (*this)(i,k) - somme;
L(i,k) = soustraction / L(k,k);
}
}
return L;
}
