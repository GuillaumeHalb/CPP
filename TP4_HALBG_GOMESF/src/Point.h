#ifndef POINT_H_
#define POINT_H_

#include <iostream>
#include <math.h>

template <typename T>
class Point
{
 private :
  T abs;
  T ord;

 public :
  /**
   * \brief Constructeur paramétré
   * Construit le point (x,y), par défaut (0.0,0.0)
   * \param x abscisse
   * \param y ordonnée
   */
  Point(T x = 0.0, T y = 0.0);

  /**
   * \brief Destructeur de la classe Point
   */
  ~Point();

  /**
   * \fn T x() const
   * \return l'abscise du point 
   */
  T x() const;
  /**
   * \fn T y() const
   * \return l'ordonnée du point 
   */
  T y() const;
/**
   * \fn T x()
   * \return l'abscise du point 
   */
  T x();
  /**
   * \fn T y()
   * \return l'ordonnée du point 
   */
  T y();
  /**
   * \fn affiche(std::ostream &out) const
   * Affichage du point 
   */
  void affiche(std::ostream &out) const;
  /**
   * \fn T dist(const Point<T> & p1) const
   * \return la distance euclidienne entre le point actuel et p1
   */
  T dist(const Point<T> & p1) const;
  /**
   * \fn transformer(T m11, T m12, T m21, T m22)
   * Transformation affine du point
   */
  void transformer(T m11, T m12, T m21, T m22);
  /**
   * \fn deplacer(T dx, T dy)
   * Translation du point de (dx,dy)
   */
  void deplacer(T dx, T dy) ;

  /**
   * \fn tourner(double angle, const Point<T>& pt)
   * Rotation d'angle angle d'un point autour du point pt
   */
  void tourner(double angle, const Point<T>& pt);
  /**
   * \brief Redefinition de l'operateur d'affectation
   */
  Point<T> & operator = (const Point<T> & P);
};

#include "Point.tpp"

#endif /*POINT_H_*/

