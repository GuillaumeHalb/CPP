#ifndef POINT_H_
#define POINT_H_

class Point
{
 private :
  double abs;
  double ord;

 public :
  Point(double x, double y);
  ~Point();
  double x() const;
  double y() const;
};

#include "Point.tpp"

#endif /*POINT_H_*/

