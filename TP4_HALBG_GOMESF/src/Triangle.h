#ifndef DMATRIX_H_
#define DMATRIX_H_

#include <iostream>
#include "Point.h"

class Triangle {
 private :

  Point p1; 
  Point p2;
  Point p3;

 public :
  
  Triangle(Point pt1, Point pt2, Point pt3);
  
  Point p1() const;
  Point p2() const;
  Point p3() const;
}; 

#endif /* DMATRIX_H_ */
