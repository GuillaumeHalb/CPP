#ifndef POINT_H_
#define POINT_H_

#include <iostream>

template <typename T>
class Point
{
 private :
  T abs;
  T ord;

 public :
  Point(T x = 0.0, T y = 0.0);
  ~Point();
  T x() const;
  T y() const;
  void affiche(std::ostream &out) const;
  void transformer(T m11, T m12, T m21, T m22);
  void deplacer(T dx, T dy);
  Point<T> & operator = (const Point<T> & P);
};

#include "Point.tpp"

#endif /*POINT_H_*/

