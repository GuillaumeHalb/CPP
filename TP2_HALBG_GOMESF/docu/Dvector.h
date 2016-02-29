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

   /*!
     * \fn double& operator()(const int i) const;
     *  \brief Accesseur à la coordonnée i d'un vecteur.
     *
     *  Accesseur de la classe Dvector. 
     *  Etant donné un entier i, on vérifie avant d'accèder à la coordonnée i
     *  du vecteur si 0<i<dim(vecteur), puis on renvoie la dite coordonnée.
     *  \param i : entier (const) correspondant à l'indice de la coordonnée.
     */
  double& operator()(const int i) const;
  double& operator()(const int i);
    
  /*!
     * \fn Dvector operator + (const double d) const;
     *  \brief Surcharge d'opérateur +.
     *
     *  Opérateur entre un vecteur et un scalaire.
     *  \param d : scalaire utilisé lors de l'opération nouvellement définie.
     */
  Dvector operator+ (const double d) const;
  /*!
     * \fn Dvector operator - (const double d) const;
     *  \brief Surcharge d'opérateur -.
     *
     *  Opérateur entre un vecteur et un scalaire.
     *  \param d : scalaire utilisé lors de l'opération nouvellement définie.
     */
  Dvector operator- (const double d) const;
  /*!
     * \fn Dvector operator * (const double d) const;      
     *  \brief Surcharge d'opérateur *.
     *
     *  Opérateur entre un vecteur et un scalaire.
     *  \param d : scalaire utilisé lors de l'opération nouvellement définie.
     */
  Dvector operator* (const double d) const;
  /*!
     * \fn Dvector operator / (const double d) const;
     *  \brief Surcharge d'opérateur /.
     *
     *  Opérateur entre un vecteur et un scalaire.
     *  \param d : scalaire utilisé lors de l'opération nouvellement définie.
     */
  Dvector operator/ (const double d) const;

  /*!
     *  \fn Dvector operator+ (const Dvector B) const
     *  \brief Surcharge d'opérateur +.
     *
     *  Opérateur entre deux vecteurs.
     *  \param B : vecteur utilisé lors de l'opération nouvellement définie.
     */
  Dvector operator+ (const Dvector B) const;
  /*!
     *  \fn Dvector operator- (const Dvector B) const
     *  \brief Surcharge d'opérateur -.
     *
     *  Opérateur entre deux vecteurs.
     *  \param B : vecteur utilisé lors de l'opération nouvellement définie.
     */
  Dvector operator- (const Dvector B) const;
  /*!
     *  \fn Dvector operator - () const
     *  \brief Surcharge de l'opérateur unaire.
     *
     *  Opération ne nécessitant qu'un seul vecteur, celui de la classe.
     */
  Dvector operator- () const;
 
  /*!
     *  \fn Dvector operator += (const double d) 
     *  \brief Surcharge d'opérateur +=.
     *
     *  Opérateur entre un vecteur et scalaire.
     *  \param d : scalaire utilisé lors de l'opération nouvellement définie.
     */
  Dvector& operator += (const double d);
  /*!
     *  \fn Dvector operator -= (const double d) 
     *  \brief Surcharge d'opérateur -=.
     *
     *  Opérateur entre un vecteur et scalaire.
     *  \param d : scalaire utilisé lors de l'opération nouvellement définie.
     */
  Dvector& operator -= (const double d);
  /*!
     *  \fn Dvector operator *= (const double d) 
     *  \brief Surcharge d'opérateur *=.
     *
     *  Opérateur entre un vecteur et un scalaire.
     *  \param d : scalaire utilisé lors de l'opération nouvellement définie.
     */
  Dvector& operator *= (const double d);
  /*!
     *  \fn Dvector operator /= (const double d) 
     *  \brief Surcharge d'opérateur /=.
     *
     *  Opérateur entre un vecteur et un scalaire.
     *  \param d : scalaire utilisé lors de l'opération nouvellement définie.
     */
  Dvector& operator /= (const double d);
  /*!
     *  \fn Dvector operator += (const Dvector A)
     *  \brief Surcharge d'opérateur +=.
     *
     *  Opérateur entre deux vecteurs.
     *  \param A : vecteur utilisé lors de l'opération nouvellement définie.
     */
  Dvector& operator += (const Dvector A);
  /*!
     *  \fn Dvector operator -= (const Dvector A) 
     *  \brief Surcharge d'opérateur -=.
     *
     *  Opérateur entre deux vecteurs.
     *  \param A : vecteur utilisé lors de l'opération nouvellement définie.
     */
  Dvector& operator -= (const Dvector A);
  /*!
     *  \fn void operator = (const Dvector &D) 
     *  \brief Surcharge de l'opérateur d'affectation.
     *
     *  Il y a deux versions, celle-ci utilise la fonctionc memcpy.
     *  On vérifie d'abord la compatibilité entre les deux vecteurs:
     *  si la dimension n'est pas cohérente, on effectue un resize.
     *  \param D : vecteur (const) à affecter.
     */
  void operator =(const Dvector &D);
  /*!
     *  \fn Dvector operator == (const Dvector &D) const
     *  \brief Surcharge de l'opérateur de test d'égalité.
     *
     *  On vérifie d'abord la compatibilité entre les deux vecteurs:
     *  si la dimension n'est pas cohérente, on renvoie false;
     *  autrement on compare les vecteurs terme à terme.
     *  \param D : vecteur (const) à affecter.
     */
  bool operator==(const Dvector &D) const;
  /*!
     *  \fn void resize(const int d, const double v)
     *  \brief Fonction resize.
     *
     *  On vérifie d'abord la compatibilité entre les deux dimensions.
     *  Ensuite on alloue un nouveau tableau, que l'on remplit avec les 
     *  anciennes valeurs (jusqu'à l'indice dim) et les nouvelles: v.
     *  \param d : dimension du nouveau vecteur.
     *  \param v : valeur des nouvelles composantes du vecteur.
     */
  void resize(const int d, const double v);
};
std::ostream& operator<< (std::ostream &Out, const Dvector &A);
std::istream& operator>> (std::istream &In, const Dvector &A);




#endif /* DVECTOR_H_ */
