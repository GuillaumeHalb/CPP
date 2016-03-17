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
  Point(T x, T y);
  ~Point();
  T x() const;
  T y() const;
  void affiche(std::ostream &out) const;
};

#include "Point.tpp"

#endif /*POINT_H_*/

