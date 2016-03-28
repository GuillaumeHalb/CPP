/* 
 * File:   Maillage.h
 * Author: gomesf
 *
 * Created on 24 mars 2016, 11:48
 */
#include "Point.h"
#include "Triangle.h"
#include <math.h>
#include <stdexcept>
#include <string>

#ifndef MAILLAGE_H
#define	MAILLAGE_H

template<typename T, template <typename, typename> class Container>
class Maillage {
public:
	/**
   * \brief Constructeur paramétré de la classe Maillage
   * 
   * Construit le maillage de taille (m,n) à partir du point orig
   * \param m longueur du maillage
   * \param n largeur du maillage
   * \param orig point originant le maillage (coin gauche)
   */
  Maillage(int m, int n, const Point<T>& orig);

  // ~Maillage();
  /**
   * \fn const_iterator beginiter() const
   * \return un itérateur constant partant du 1er élément du conteneur utilisé
   */
  typename Container <Triangle<T>, std::allocator<Triangle<T> > > ::const_iterator beginiter() const;
  /**
   * \fn const_iterator enditer() const
   * \return un itérateur constant partant du dernier élément du conteneur utilisé
   */
  typename Container <Triangle<T>, std::allocator<Triangle<T> > > ::const_iterator enditer() const;
  /**
   * \fn transformer(T m11, T m12, T m21, T m22)
   * Transformation affine de chaque triangle du conteneur utilisé
   */
  void transformer(T m11, T m12, T m21, T m22);
  /**
   * \fn deplacer(T dx, T dy)
   * Translation de chaque triangle du conteneur utilisé
   */
  void deplacer(T dx, T dy);
  /**
   * \fn tourner(double angle, const Point<T>& pt)
   * Rotation d'angle angle du maillage autour du point pt
   */
  void tourner(double angle, const Point<T>& pt);
  /**
   * \brief Constructeur paramétré de la classe Maillage
   * 
   * Construit le maillage du rectangle(p1,p2,p3,p4)
   *
   * \param p1 point gauche-bas du maillage
   * \param p2 point droit-bas du maillage
   * \param p3 point droit-haut du maillage
   * \param p4 point gauche-haut du maillage
   * \param m longueur du maillage
   * \param n largeur du maillage
   */
  Maillage(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4, int m, int n);
  Container <Triangle<T>, std::allocator<Triangle<T> > > getMaillage();
private:
  Container <Triangle<T>, std::allocator<Triangle<T> > > maillage;
};

#include "Maillage.tpp"
#endif	/* MAILLAGE_H */

