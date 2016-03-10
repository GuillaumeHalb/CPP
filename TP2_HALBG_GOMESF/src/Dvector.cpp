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
#include <memory.h>
#include <stdexcept>

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
void Dvector::display (std::ostream &str) const 
{
  for (int i = 0; i < dim; i++) 
      str<<coord[i]<<std::endl;
}

int Dvector::size() const
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


Dvector::Dvector(const Dvector &D) 
{
  if (D.size() == 0) 
    {
      dim = 0;
    }
  else 
    {
      dim = D.dim;
      coord = new double[dim];
      for (int i=0; i<dim; i++)
	coord[i]=D.coord[i];
      cout << "Utilisation du constructeur par copie" << std::endl;
    }
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

double& Dvector::operator() (const int i) const
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

double& Dvector::operator() (const int i)
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


Dvector operator+ (const double d, const Dvector &D)
{
  Dvector A(D);
  for (int i = 0; i < D.size(); i++) 
    A(i) = D(i) + d;
  return A;
}

Dvector operator+ (const Dvector &D, const double d) 
{
  return d + D;
}

Dvector operator- (const Dvector &D, const double d)
{
  return D + (-d);
}

Dvector operator* (const double d, const Dvector &D)
{
  Dvector A(D.size());
  for (int i = 0; i < D.size(); i++) 
    {
      A(i) = D(i) * d;
    }
  return A;
}

Dvector operator* (const Dvector &D, const double d)
{
  return d*D;
}

Dvector operator/ (const Dvector &D, const double d)
{
  if (d == 0)
    {
      throw invalid_argument("Division par 0");
    }
  else 
    {
      return (1/d)*D;
    }
}

Dvector operator+ (const Dvector &B, const Dvector &D)
{
  Dvector A(B.size());
  for (int i = 0; i < B.size(); i++) 
    {
      A(i) = B(i) + D(i);
    }
  return A;
}

Dvector operator- (const Dvector &B,  const Dvector &D)
{
  return B + (-D);
}

Dvector operator- (const Dvector &D)
{
  Dvector A(D.size());
  for (int i = 0; i < D.size(); i++) 
    {
      A(i) = -D(i);
    }
  return A;
}

ostream & operator <<(ostream &Out, const Dvector &A)
{
  A.display(Out);
  return Out;
}

istream& operator>> (std::istream &In, const Dvector &A)
{
  for (int i = 0; i < A.size(); i++) 
    In >> A(i);
  return In;
}

Dvector& Dvector::operator += (const double d)
{
  Dvector& D = *this;

  for (int i = 0; i < D.size(); i++) {
    D.coord[i] += d;
  }
  return D;
}

Dvector& Dvector::operator -= (const double d)
{
  Dvector& D = *this;
  return D += (-d);
}

Dvector& Dvector::operator *= (const double d)
{
  Dvector& D = *this;

  for (int i = 0; i < D.size(); i++) {
    D.coord[i] *= d;
  }
  return D;
}

Dvector& Dvector::operator /= (const double d)
{
  if (d == 0.0) {
    throw invalid_argument("Division par 0");
  }
  else {
    Dvector& D = *this;
    return D *= (1/d);
  }
}

Dvector& Dvector::operator += (const Dvector A)
{
  if (A.size() != this->dim) 
    {
      throw invalid_argument("taille incompatible");
    }
  else 
    {
      Dvector& D = *this; 
      for (int i = 0; i < dim; i++) 
	{
	  D.coord[i] += A(i);
	}
      return D;
    }
}

Dvector& Dvector::operator -= (const Dvector A)
{
  Dvector& D = *this;
  return D += (-A);
}

Dvector& Dvector::operator=(const Dvector &D)
{
  // Changement de dim possible de this => on fait un resize
  if (&D != this) {
    if (D.size() != size()) 
      resize(D.size(), 0); // initialisation inutile car on modifie après
    
    memcpy(coord, D.coord, dim * sizeof(double));
  }
  return *this;
}

/*
Dvector& Dvector::operator=(const Dvector &D)
{
  if (&D != this) {
    dim = D.size();
    coord = new double[dim];
    for (int i = 0; i < dim; i++)
      coord[i] = D(i);
  }
  return *this;
}
*/

bool Dvector::operator==(const Dvector &D) const
{
  if (dim != D.size())
    return false;
  else
    {
      for (int i = 0; i < dim; i++) 
	{
	  if (coord[i] != D(i))
	    return false;
	}
    }
  return true;
}

bool Dvector::operator!=(const Dvector &D) const
{
  return !(*this == D);
}

void Dvector::resize(const int d, const double v)
{
  if (d < dim)
      dim = d;
  if (d > dim) 
    {
      // On fait une allocation
      double *c = new double[d];
      // On initialise les coordonnees
      for (int i = 0; i < d; i++) 
	{
	  if (i < dim)
	    c[i] = coord[i];
	  else
	    c[i] = v;
	}
      // On libère l'ancien
      delete [] coord;
      // Et on fait pointer le nouveau sur l'ancien     
      coord = c;
      dim = d;
    } 
}
