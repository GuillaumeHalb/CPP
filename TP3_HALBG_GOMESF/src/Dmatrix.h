#ifndef DMATRIX_H_
#define DMATRIX_H_

#include <iostream>
#include "Darray.h"
#include "Dvector.h"

class Dmatrix : public Darray {
 private :
  int l; /* nombre de lignes */
  int c; /* nombre de colonnes */

 public :

  /* ------------------- Constructeurs / Destructeurs -------------------- */

    /*!
     *  \brief Constructeur par défaut
     *
     *  Constructeur par défaut de la classe Dmatrix. 
     *  La dimension est initialisée à 2x2.
     *  Toutes les coordonnées sont initialisées à 0.0
     */
  Dmatrix();

  /*!
     *  \brief Constructeur 
     *
     *  Constructeur classique de la classe Dmatrix. 
     *  Initialise la dimension et toutes les coordonnées du vecteur à une 
     *  seule et même valeur.
     *  Cet argument peut être optionnel et sera remplacé par 1.0 dans ce cas. 
     *  \param l, c : dimension donnée du vecteur
     *  \param val : double désignant la valeur des coordonnées
     */
  Dmatrix (int l, int c, double val= 1.0);

  /*!
   *  \brief Destructeur
   *
   *  Destructeur de la classe Dmatrix
   */
  ~Dmatrix();

    /*!
     *  \brief Constructeur par copie
     *
     *  Constructeur par recopie de la classe Dmatrix. 
     *  Recopie les attributs m, n et coord dans le vecteur courant.
     *  \param D instance de la classe Dvector
     */
  Dmatrix (const Dmatrix & M);

  /* ------------------------ Accesseurs --------------------------- */

  int lines() const;
  int columns() const;

  double operator()(int line, int column) const;
  double &operator()(int line, int column);

  /* -------------------------- Autres ----------------------------- */

  Dmatrix& operator = (const Dmatrix &M);

  Dvector line (int line) const;
  
  Dvector column (int column) const;

  Dmatrix& transpose();

  void display (std::ostream &str) const;

  Dmatrix cholesky();
}; 
std::ostream& operator<< (std::ostream &Out, const Dmatrix &M);

Dvector operator * (const Dvector &V, const Dmatrix &M);
Dvector operator * (const Dmatrix &M, const Dvector &V);

Dmatrix operator * (const Dmatrix &M1, const Dmatrix &M2);

#endif /* DMATRIX_H_ */
