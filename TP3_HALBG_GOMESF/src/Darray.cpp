/*!
 * \file Darray.cpp
 * \brief vecteur de dimension n ainsi que ses n coordoonnées
 * \author Halb Guillaume, Gomes Filipe
 */


#include <iostream>
#include "Darray.h"
#include <cstdlib> // bibliothèque pour rand()
#include <fstream>
#include <string>
#include <stdexcept>
#include <memory.h>

using namespace std;
using std::ifstream; 


Darray::Darray () 
{
  dim = 2;
  coord = new double[dim];
  for (int i = 0; i < dim; i++) 
    {
      coord[i] = 0.0;
    }
  cout << "Utilisation du constructeur par défaut" << std::endl;
}

Darray::Darray (int d, double val)
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
Darray::~Darray() {
  delete [] coord;
  cout << "Utilisation du destructeur" << std::endl;
}

// Affiche le Dvector
void Darray::display (std::ostream &str) 
{
  for (int i = 0; i < dim; i++) 
    {
      str<<coord[i]<<std::endl;
    }
}

int Darray::size() const
{
  return dim;
}


Darray::Darray(const Darray & D) 
{
  dim = D.dim;
  coord = new double[dim];
  for (int i=0; i<dim; i++)
    coord[i]=D.coord[i];
    cout << "Utilisation du constructeur par copie" << std::endl;

}

Darray::Darray(std::string s)
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

double& Darray::operator() (int i) const
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


double& Darray::operator() (int i)
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

Darray operator+ (const double d, const Darray &D)
{
  Darray A(D);
  for (int i = 0; i < D.size(); i++) 
    A(i) = D(i) + d;
  return A;
}

Darray operator+ (const Darray &D, const double d) 
{
  return d + D;
}

Darray operator- (const Darray &D, const double d)
{
  return D + (-d);
}

Darray operator* (const double d, const Darray &D)
{
  Darray A(D.size());
  for (int i = 0; i < D.size(); i++) 
    {
      A(i) = D(i) * d;
    }
  return A;
}

Darray operator* (const Darray &D, const double d)
{
  return d*D;
}

Darray operator/ (const Darray &D, const double d)
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

Darray operator+ (const Darray &B, const Darray &D)
{
  Darray A(B.size());
  for (int i = 0; i < B.size(); i++) 
    {
      A(i) = B(i) + D(i);
    }
  return A;
}

Darray operator- (const Darray &B,  const Darray &D)
{
  return B + (-D);
}

Darray operator- (const Darray &D)
{
  Darray A(D.size());
  for (int i = 0; i < D.size(); i++) 
    {
      A(i) = -D(i);
    }
  return A;
}



Darray& Darray::operator += (const double d)
{
  Darray& D = *this;

  for (int i = 0; i < D.size(); i++) {
    D.coord[i] += d;
  }
  return D;
}

Darray& Darray::operator -= (const double d)
{
  Darray& D = *this;
  return D += (-d);
}

Darray& Darray::operator *= (const double d)
{
  Darray& D = *this;

  for (int i = 0; i < D.size(); i++) {
    D.coord[i] *= d;
  }
  return D;
}

Darray& Darray::operator /= (const double d)
{
  if (d == 0.0) {
    throw invalid_argument("Division par 0");
  }
  else {
    Darray& D = *this;
    return D *= (1/d);
  }
}


Darray& Darray::operator += (const Darray A)
{
  if (A.size() != this->dim) 
    {
      throw invalid_argument("taille incompatible");
    }
  else 
    {
      Darray& D = *this; 
      for (int i = 0; i < dim; i++) 
	{
	  D.coord[i] += A(i);
	}
      return D;
    }
}

Darray& Darray::operator -= (const Darray A)
{
  Darray& D = *this;
  return D += (-A);
}

Darray& Darray::operator=(const Darray &D)
{
  // Changement de dim possible de this => on fait un resize
  if (&D != this) {
    if (D.size() != size()) 
      resize(D.size(), 0); // initialisation inutile car on modifie après
    
    memcpy(coord, D.coord, dim * sizeof(double));
  }
  return *this;
}


void Darray::resize(const int d, const double v)
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
