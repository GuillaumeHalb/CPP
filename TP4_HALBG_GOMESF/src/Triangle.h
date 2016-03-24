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
  
  Triangle(Point<T> pt1, Point<T> pt2, Point<T> pt3);
  
  Point<T> p1() const;
  Point<T> p2() const;
  Point<T> p3() const;

  void affiche(std::ostream &out) const;
}; 

#include "Triangle.tpp"

#endif /* DMATRIX_H_ */
