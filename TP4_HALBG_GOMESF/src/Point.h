#ifndef POINT_H_
#define POINT_H_

#include <iostream>

class Point
{
 private :
  double x,y;

 public :
  Point(double abs, double ord);
  ~Point;
  double& x();
  double& y();
};

 #endif /*POINT_H_*/
