/*!
 * \file Dvector.h
 * \brief vecteur de dimension n ainsi que ses n coordoonnées
 * \author Halb Guillaume, Gomes Filipe
 */

#ifndef DVECTOR_H_
#define DVECTOR_H_

#include <iostream>

/*! \class Dvector
   * \brief classe representant le vecteur
   *
   *  La classe gère un vecteur de dimension n
   *
   */

class Dvector:public Darray
{
public :
  /*!
     *  \brief Constructeur par défaut
     *
     *  Constructeur par défaut de la classe Dvector. 
     *  La dimension est initialisée à 2.
     *  Toutes les coordonnées sont initialisées à 0.0
     */
  Dvector ();
  
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
  Dvector (int d, double val= 1.0);

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
     *  \param D instance de la classe Dvector
     */
  Dvector (const Dvector & D);

  /*!
     *  \brief Constructeur d'un vecteur depuis un fichier de données.
     *
     *  Constructeur de la classe Dvector. 
     *  Il remplit les coordoonées du vecteur avec les données du fichier passé
     *  en argument. La dimension sera le nombre de lignes du fichier.
     *  \param s : string contenant le nom du fichier contenant les données.
     */
  Dvector(std::string s);
};
double Dvector::operator *(Dvector &A, Dvector &B); 

#endif /* DVECTOR_H_ */
