/*!
 * \file Dmatrix.cpp
 * \brief vecteur de dimension n ainsi que ses n coordoonnées
 * \author Halb Guillaume, Gomes Filipe
 */


#include <iostream>
#include "Dmatrix.h"
#include <cstdlib> // bibliothèque pour rand()
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;
using std::ifstream; 

Dmatrix::Dmatrix() 
{
  l = 2;
  c = 2;
  coord = new double[l*c];
  for (int i = 0; i < l; i++)
    for (int j = 0; i < c; j++)
      coord[c*i + j] = 0.0;
  cout << "Utilisation du constructeur par défaut" << std::endl;
}
  
Dmatrix::Dmatrix(int l, int c, double val) 
{
  l = l;
  c = c;
  coord = new double[l*c];
  for (int i = 0; i < l; i++)
    for (int j = 0; i < c; j++)
      coord[c*i + j] = val;
  cout << "Utilisation du constructeur avec arguments" << std::endl; 
}

Dmatrix::~Dmatrix() 
{
  delete [] coord;
  cout << "Utilisation du destructeur" << std::endl;
}

Dmatrix::Dmatrix(const Dmatrix &M) 
{
  l = M.l;
  c = M.c;
  coord = new double[l*c];
  for (int i = 0; i < l; i++)
    for (int j = 0; i < c; j++)
      coord[c*i + j] = M.coord[c*i + j];
  cout << "Utilisation du constructeur par copie" << std::endl;
}

int Dmatrix::lines() const
{
  return l;
}

int Dmatrix::columns() const
{
  return c;
}

double& operator()(int line, int column) const 
{
  if (line < 0 || line > l || column < 0 || column > c)
    throw invalid_argument("Argument(s) invalide(s)");
  else
    return coord[line*c + column];
}

double& operator()(int line, int column) 
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
	memcpy(coord, M.coord,  c*l*sizeof(double));
    }
  return *this;
}

Dvector Dmatrix::line(int line) const
{
  if (line < 0 || line >= l)
    throw invalid_argument("Argument invalide");
  Dvector V(c);
  for (int j = 0; j < c; j++)
    V(j) = coord[line*c + j];
  return V;
}

Dvector Dmatrix::column(int column) const
{
  if (column < 0 || column >= c)
    throw invalid_argument("Argument invalide");
  Dvector V(l);
  for (int i = 0; i < l; i++)
    V(i) = coord[i*c + column];
  return V;
}

Dvector operator * (const Dvector &V, const Dmatrix &M)
{
  if (M.lines() != V.size()) 
    throw invalid_argument("Argument invalide");
  Dvector Res(M.columns(), 0);
  for (int i = 0; i < M.lines(); i++)
    for (int j = 0; j < M.columns(); j++)
      Res(i) += M(j*M.columns + i) * V(j);
  return Res;
}

Dvector operator * (const Dmatrix &M, const Dvector &V)
{
  if (M.columns() != V.size()) 
    throw invalid_argument("Argument invalide");
  Dvector Res(M.lines(), 0);
  for (int i = 0; i < M.lines(); i++)
    for (int j = 0; j < M.columns(); j++)
      Res(i) += M(i*M.columns +j) * V(j);
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
	Res(i,j) = M1(i,k)*M2(k,j);
  return Res;
}

Dmatrix& Dmatrix::transpose()
{
  Dmatrix Res(c,l);
  for (int i = 0; i < Res.lines(); i++)
    for (int j = 0; j < Res.columns(); j++)
      Res(i,j) = coord[j,i];
  return Res;
}
