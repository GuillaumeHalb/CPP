#ifndef DMATRIX_H_
#define DMATRIX_H_

#include <iostream>
#include "Point.h"

template <typename T>
class Triangle {
 private :

  Point<T> point1; 
  Point<T> point2;
  Point<T> point3;

 public :
  /**
   * \brief Constructeur de la classe triangle
   * 
   * Construit le triangle de sommets p1, p2, p3
   * \param p1 premier point
   * \param p2 second point
   * \param p3 troisieme point
   */
  Triangle(Point<T> pt1, Point<T> pt2, Point<T> pt3);
  
  /**
   * \fn Point<T> p1() const
   * \return le point 1 du triangle
   */
  Point<T> p1() const;
   /**
   * \fn Point<T> p2() const
   * \return le point 2 du triangle
   */
  Point<T> p2() const;
   /**
   * \fn Point<T> p3() const
   * \return le point 3 du triangle
   */
  Point<T> p3() const;
  /**
   * \fn Point<T> p1() 
   * \return le point 1 du triangle
   */
  Point<T> p1();
  /**
   * \fn Point<T> p2() 
   * \return le point 2 du triangle
   */
  Point<T> p2();
  /**
   * \fn Point<T> p3() 
   * \return le point 3 du triangle
   */
  Point<T> p3();
  /**
   * \fn affiche(std::ostream &out) const
   * Affichage du triangle
   */
  void affiche(std::ostream &out) const;
  /**
   * \fn transformer(T m11, T m12, T m21, T m22)
   * Transformation affine de chaque point du triangle
   */
  void transformer(T m11, T m12, T m21, T m22) ;
  /**
   * \fn deplacer(T dx, T dy)
   * Translation de chaque point du triangle de (dx,dy)
   */
  void deplacer(T dx, T dy);
  /**
   * \fn tourner(double angle, const Point<T>& pt)
   * Rotation d'angle angle du triangle autour du point pt
   */
  void tourner(double angle, const Point<T>& pt);
}; 

#include "Triangle.tpp"

#endif /* DMATRIX_H_ */
