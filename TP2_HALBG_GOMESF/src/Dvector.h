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

class Dvector 
{
private :
  int dim; /*! dimension du vecteur */
  double *coord; /*! Tableau listant les coordonnées du vecteur, de taille dim */

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

  /**
 * \fn void Dvector::display (std::ostream &str)
 * \brief Fonction d'affichage du vecteur courant
 *  Affichage de la dimension du vecteur puis des coordonnées en colonne
 *
 * \param str flux servant à l'affichage, ne peut être NULL.
 */
  void display (std::ostream &str) const;

  /**
 * \fn int Dvector::size()
 * \brief Fonction retournant la dimension du vecteur
 *
 * \return entier correspondant à la taille (ou dimension) du vecteur.
 */
  int size() const;

/**
 * \fn int Dvector::fillRandomly()
 * \brief Fonction remplissant un vecteur déjà alloué
 *  Il n'y pas d'allocation mémoire, on écrase les cases existantes par 
 *  un flottant aléatoire compris entre 0 et 1.
 */
  int fillRandomly();

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

  // Accesseur à l'élément i
  double& operator()(const int i) const;
  double& operator()(const int i);
    
  // Surcharges d'opérateur
  Dvector operator+ (const double d) const;
  Dvector operator- (const double d) const;
  Dvector operator* (const double d) const;
  Dvector operator/ (const double d) const;
  Dvector operator+ (const Dvector B) const;
  Dvector operator- (const Dvector B) const;
  Dvector operator- () const;
 
  Dvector& operator += (const double d);
  Dvector& operator -= (const double d);
  Dvector& operator *= (const double d);
  Dvector& operator /= (const double d);
  Dvector& operator += (const Dvector A);
  Dvector& operator -= (const Dvector A);

  void operator =(const Dvector &D);

  bool operator==(const Dvector &D) const;

  void resize(const int d, const double v);
};
std::ostream& operator<< (std::ostream &Out, const Dvector &A);
std::istream& operator>> (std::istream &In, const Dvector &A);




#endif /* DVECTOR_H_ */
