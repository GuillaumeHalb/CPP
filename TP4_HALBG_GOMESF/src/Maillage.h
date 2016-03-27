/* 
 * File:   Maillage.h
 * Author: gomesf
 *
 * Created on 24 mars 2016, 11:48
 */
#include "Point.h"
#include "Triangle.h"
#include <math.h>

#ifndef MAILLAGE_H
#define	MAILLAGE_H

template<typename T, template <typename, typename> class Container>
class Maillage {
public:
  Maillage(int m, int n, const Point<T>& orig);
  // ~Maillage();
  typename Container <Triangle<T>, std::allocator<Triangle<T> > > ::const_iterator beginiter() const;
  typename Container <Triangle<T>, std::allocator<Triangle<T> > > ::const_iterator enditer() const;
  void transformer(T m11, T m12, T m21, T m22);
  void deplacer(T dx, T dy);
  void tourner(double angle, const Point<T>& pt);
private:
  Container <Triangle<T>, std::allocator<Triangle<T> > > maillage;
};

#include "Maillage.tpp"
#endif	/* MAILLAGE_H */

