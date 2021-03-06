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
  dim = 2;
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

void Dvector::fillRandomly() {
  static bool init = false;
  if (!init) 
  {
    init= true;
    srand(time(0));
  }
  for (int i = 0; i < dim; i++) {
    coord[i] = (double) rand()/RAND_MAX;
  }
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
      cout<<"Utilisation du constructeur par lecture de fichier"<<std::endl;

}
