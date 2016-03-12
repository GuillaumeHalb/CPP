/*!
 * \file Dvector.h
 * \brief vecteur de dimension n ainsi que ses n coordoonnées
 * \author Halb Guillaume, Gomes Filipe
 */

#ifndef DVECTOR_H_
#define DVECTOR_H_

#include <iostream>
#include "Darray.h"

/*! \class Dvector
 * \brief classe representant le vecteur
 *
 *  La classe gère un vecteur de dimension n
 *
 */

class Dvector : public Darray
{
 public :

  Dvector();
  
  Dvector(int d, double val = 1.0);

  ~Dvector();

  Dvector(const Darray &A);

  Dvector(std::string s);
  
  void display(std::ostream &str) const;

};
std::ostream& operator<< (std::ostream &Out, const Dvector &A);

double operator* (const Dvector &V1, const Dvector &V2);

#endif /* DVECTOR_H_ */
