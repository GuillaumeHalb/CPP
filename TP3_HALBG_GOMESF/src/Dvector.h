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
  /*!
   *  \brief Constructeur par défaut
   *
   *  Constructeur par défaut de la classe Dvector. 
   *  La dimension est initialisée à 2.
   *  Toutes les coordonnées sont initialisées à 0.0
   */
  Dvector();
  
  /*!
   *  \brief Constructeur 
   *
   *  Constructeur classique de la classe Dvector. 
   *  Initialise la dimension et toutes les coordonnées du vecteur à une 
   *  seule et même valeur.
   *  Cet argument peut être optionnel et sera remplacé par 1.0 dans ce cas. 
   *  \param d : dimension donnée du vecteur
   *  \param val : flottant désignant la valeur des coordonnées
   */
  Dvector(int d, double val = 1.0);

  /*!
   *  \brief Destructeur
   *
   *  Destructeur de la classe Dvector
   */
  ~Dvector();

  /*!
     *  \brief Constructeur par copie
     *
     *  Constructeur par recopie de la classe Dvector. 
     *  Recopie les attributs dim et coord dans le vecteur courant.
     *  \param A instance de la classe Darray
     */
  Dvector(const Darray &A);

  /**
   * \fn void Dvector::display (std::ostream &str)
   * \brief Fonction d'affichage du vecteur courant
   *  Affichage de la dimension du vecteur puis des coordonnées en colonne
   *
   * \param str flux servant à l'affichage, ne peut être NULL.
   */
  Dvector(std::string s);
  
  void display(std::ostream &str) const;

};
std::ostream& operator<< (std::ostream &Out, const Dvector &A);

double operator* (const Dvector &V1, const Dvector &V2);

#endif /* DVECTOR_H_ */
