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

using namespace std;
using std::ifstream; 


Dvector::Dvector () 
{
  dim = 0;
  coord = new double[dim];
  for (int i = 0; i < dim; i++) 
    {
      coord[i] = 0.0;
    }
  cout << "Utilisation du constructeur par défaut" << std::endl;
}

Dvector::Dvector (int d, double val)
{
  dim = d;
  coord = new double[dim];
  for (int i = 0; i < dim; i++) 
    {
      coord[i] = val;
    }
    cout << "Utilisation du constructeur avec arguments" << std::endl;

}

/* Destructeur */
Dvector::~Dvector() {
  delete [] coord;
  cout << "Utilisation du destructeur" << std::endl;
}

// Affiche le Dvector
void Dvector::display (std::ostream &str) 
{
  for (int i = 0; i < dim; i++) 
    {
      str<<coord[i]<<std::endl;
    }
}

int Dvector::size() 
{
  return dim;
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


Dvector::Dvector(const Dvector & D) 
{
  dim = D.dim;
  if (dim == 0) return; //vecteur null
  coord = new double[dim];
  for (int i=0; i<dim; i++)
    coord[i]=D.coord[i];
    cout << "Utilisation du constructeur par copie" << std::endl;

}

Dvector::Dvector(std::string s)
{
  dim = 0;
  ifstream fichier(s.c_str(), std::ios::in);
    if (fichier)
      {
	string line1, line2;
	while (getline(fichier, line1)) 
	    dim++;
	
	// retour au début du fichier
	fichier.clear();
	fichier.seekg(0, ios::beg);
	coord = new double[dim];
	for (int i=0; i<dim; i++) 
	  fichier >> coord[i];

	fichier.close();
      }
    else
      { 
	coord = NULL;
      }
      cout<<"Utilisation du constructeur par lecture de fichier"<<endl;

}

double& Dvector::operator() (int i) const
{
  if (i >= dim || i < 0) 
    {
    cout<<"argument invalide"<<endl;
    exit(-1);
    }
  else 
    {
      return coord[i];
    }
}


double& Dvector::operator() (int i)
{
  if (i >= dim || i < 0) 
    {
    cout<<"argument invalide"<<endl;
    exit(-1);
    }
  else 
    {
      return coord[i];
    }
}


Dvector Dvector::operator+ (double d)
{
  Dvector A(dim);
  for (int i = 0; i < dim; i++) 
    {
      A.coord[i] = this->coord[i] + d;
    }
  return A;
}

Dvector Dvector::operator- (double d)
{
  Dvector A(dim);
  for (int i = 0; i < dim; i++) 
    {
      A.coord[i] = this->coord[i] - d;
    }
  return A;
}

Dvector Dvector::operator* (double d)
{
  Dvector A(dim);
  for (int i = 0; i < dim; i++) 
    {
      A.coord[i] = this->coord[i] * d;
    }
  return A;
}

Dvector Dvector::operator/ (double d)
{
  if (d == 0)
    {
      cout<<"Division par 0 !"<<endl;
      exit(-1);
    }
  else 
    {
      Dvector A(dim);
      for (int i = 0; i < dim; i++) 
	{
	  A.coord[i] = this->coord[i] / d;
	}
      return A;
    }
}

Dvector Dvector::operator+ (Dvector B)
{
  Dvector A(dim);
  for (int i = 0; i < dim; i++) 
    {
      A.coord[i] = this->coord[i] + B.coord[i];
    }
  return A;
}

Dvector Dvector::operator- (Dvector B)
{
  Dvector A(dim);
  for (int i = 0; i < dim; i++) 
    {
      A.coord[i] = this->coord[i] - B.coord[i];
    }
  return A;
}

Dvector Dvector::operator- ()
{
  Dvector A(dim);
  for (int i = 0; i < dim; i++) 
    {
      A.coord[i] = -this->coord[i];
    }
  return A;
}

/*
ostream & Dvector::operator <<(ostream &Out, const Dvector &A)
{
  A.display(Out);
  return Out;
}

istream& Dvector::operator>> (std::istream &In, const Dvector &A)
{
  In>>A.dim;
  for (int i = 0; i < A.size(); i++) 
    {
      In>>A.coord[i];
    }
  return In;
}
*/

std::ostream& Dvector::operator<< (std::ostream &Out)
{
  this->display(Out);
  return Out;
}

std::istream& Dvector::operator>> (std::istream &In)
{
  In>>dim;
  for (int i = 0; i < dim; i++) 
    {
      In>>coord[i];
    }
  return In;
}


Dvector& Dvector::operator += (double d)
{
  Dvector& D = *this;

  for (int i = 0; i < D.size(); i++) {
    D.coord[i] += d;
  }
  return D;
}

Dvector& Dvector::operator -= (double d)
{
  Dvector& D = *this;

  for (int i = 0; i < D.size(); i++) {
    D.coord[i] -= d;
  }
  return D;
}

Dvector& Dvector::operator *= (double d)
{
  Dvector& D = *this;

  for (int i = 0; i < D.size(); i++) {
    D.coord[i] *= d;
  }
  return D;
}

Dvector& Dvector::operator /= (double d)
{
  if (d == 0.0) {
    exit(-1); // division par 0
  }
  else {
    Dvector& D = *this;
    
    for (int i = 0; i < D.size(); i++) {
      D.coord[i] /= d;
    }
    return D;
  }
}

Dvector& Dvector::operator += (Dvector A)
{
  if (A.dim != this->dim) 
    {
      exit(-1); // dimensions incompatibles
    }
  else 
    {
      Dvector& D = *this; 
      for (int i = 0; i < dim; i++) 
	{
	  D.coord[i] += A.coord[i];
	}
      return D;
    }
}

Dvector& Dvector::operator -= (Dvector A)
{
  if (A.dim != this->dim) 
    {
      exit(-1); // dimensions incompatibles
    }
  else 
    {
      Dvector& D = *this; 
      for (int i = 0; i < dim; i++) 
	{
	  D.coord[i] += A.coord[i];
	}
      return D;
    }
}
