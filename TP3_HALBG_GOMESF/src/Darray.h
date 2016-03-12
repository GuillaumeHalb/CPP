/*!
 * \file Darray.h
 * \brief vecteur de dimension n ainsi que ses n coordoonnées
 * \author Halb Guillaume, Gomes Filipe
 */

#ifndef DARRAY_H_
#define DARRAY_H_

#include <iostream>

/*! \class Darray
   * \brief classe representant le vecteur
   *
   *  La classe gère un vecteur de dimension n
   *
   */

class Darray
{
protected :
  int dim; /*! dimension du array */
  double *coord; /*! Tableau listant les coordonnées du array, de taille dim */

public :
  /*!
     *  \brief Constructeur par défaut
     *
     *  Constructeur par défaut de la classe Dvector. 
     *  La dimension est initialisée à 2.
     *  Toutes les coordonnées sont initialisées à 0.0
     */
  Darray ();
  
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
  Darray (int d, double val= 1.0);

  /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Dvector
     */
  ~Darray();

  /**
 * \fn void Dvector::display (std::ostream &str)
 * \brief Fonction d'affichage du vecteur courant
 *  Affichage de la dimension du vecteur puis des coordonnées en colonne
 *
 * \param str flux servant à l'affichage, ne peut être NULL.
 */
  void display (std::ostream &str);

  /**
 * \fn int Dvector::size()
 * \brief Fonction retournant la dimension du vecteur
 *
 * \return entier correspondant à la taille (ou dimension) du vecteur.
 */
  int size() const;

  /*!
     *  \brief Constructeur par copie
     *
     *  Constructeur par recopie de la classe Dvector. 
     *  Recopie les attributs dim et coord dans le vecteur courant.
     *  \param D instance de la classe Dvector
     */
  Darray (const Darray & D);

  /*!
     *  \brief Constructeur d'un vecteur depuis un fichier de données.
     *
     *  Constructeur de la classe Dvector. 
     *  Il remplit les coordoonées du vecteur avec les données du fichier passé
     *  en argument. La dimension sera le nombre de lignes du fichier.
     *  \param s : string contenant le nom du fichier contenant les données.
     */
  Darray(std::string s);

  // Accesseur à l'élément i
  double& operator()(int i) const;
  double& operator()(int i);

  Darray& operator += (const double d);
  Darray& operator -= (const double d);
  Darray& operator *= (const double d);
  Darray& operator /= (const double d);
  Darray& operator += (const Darray A);
  Darray& operator -= (const Darray A);

  Darray& operator =(const Darray &D);

  void resize(const int d, const double v);
};

Darray operator+ (const double d, const Darray &D);
Darray operator- (const Darray &D, const double d);
Darray operator* (const double d, const Darray &D);
Darray operator/ (const Darray &D, const double d);

Darray operator+ (const Darray &D, const double d);
Darray operator* (const Darray &D, const double d);

Darray operator+ (const Darray &B, const Darray &D);
Darray operator- (const Darray &B, const Darray &D);
Darray operator- (const Darray &D);

#endif /* DARRAY_H_ */
