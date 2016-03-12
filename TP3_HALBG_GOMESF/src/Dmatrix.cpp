/*!
 * \file Dmatrix.cpp
 * \brief vecteur de dimension n ainsi que ses n coordoonnées
 * \author Halb Guillaume, Gomes Filipe
 */


#include <iostream>
#include "Dmatrix.h"
#include <cstdlib> // bibliothèque pour rand()
#include <fstream>
#include <string.h>
#include <stdexcept>
#include <stdlib.h>


using namespace std;
using std::ifstream; 

Dmatrix::Dmatrix() : Darray::Darray()
{
  l = 1;
  c = 2;
}
  
Dmatrix::Dmatrix(int l, int c, double val) : Darray(l*c, val)
{
  l = l;
  c = c;
}

Dmatrix::~Dmatrix() 
{
}

Dmatrix::Dmatrix(const Dmatrix &M) : Darray(M)
{
  l = M.lines();
  c = M.columns();
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
