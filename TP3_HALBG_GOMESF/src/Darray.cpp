/*!
 * \file Darray.cpp
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


Darray::Darray () 
{
  dim = 0;
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

int Darray::size() 
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


Darray Darray::operator+ (double d)
{
  Darray A(dim);
  for (int i = 0; i < dim; i++) 
    {
      A.coord[i] = this->coord[i] + d;
    }

  return A;
}

Darray Darray::operator- (double d)
{
  Darray A(dim);
  for (int i = 0; i < dim; i++) 
    {
      A.coord[i] = this->coord[i] - d;
    }
  return A;
}

Darray Darray::operator* (double d)
{
  Darray A(dim);
  for (int i = 0; i < dim; i++) 
    {
      A.coord[i] = this->coord[i] * d;
    }
  return A;
}

Darray Darray::operator/ (double d)
{
  if (d == 0)
    {
      cout<<"Division par 0 !"<<endl;
      exit(-1);
    }
  else 
    {
      Darray A(dim);
      for (int i = 0; i < dim; i++) 
	{
	  A.coord[i] = this->coord[i] / d;
	}
      return A;
    }
}

Darray Darray::operator+ (Darray B)
{
  Darray A(dim);
  for (int i = 0; i < dim; i++) 
    {
      A.coord[i] = this->coord[i] + B.coord[i];
    }
  return A;
}

Darray Darray::operator- (Darray B)
{
  Darray A(dim);
  for (int i = 0; i < dim; i++) 
    {
      A.coord[i] = this->coord[i] - B.coord[i];
    }
  return A;
}

Darray Darray::operator- ()
{
  Darray A(dim);
  for (int i = 0; i < dim; i++) 
    {
      A.coord[i] = -this->coord[i];
    }
  return A;
}


