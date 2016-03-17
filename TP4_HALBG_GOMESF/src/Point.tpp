#include "Point.h"
#include <iostream>

Point::Point(double abs, double ord) 
{
	x=abs;
	y=ord;
}

double& Point::x()
{
  return x;
}

double& Point::y()
{
  return y;
}