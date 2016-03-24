/* 
 * File:   Maillage.h
 * Author: gomesf
 *
 * Created on 24 mars 2016, 11:48
 */
#include "Point.h"

#ifndef MAILLAGE_H
#define	MAILLAGE_H

template<typename T, template <typename, typename> class Container>
class Maillage {
public:
  Maillage(int m, int n, const Point<T>& orig);
  // ~Maillage();
    //beginiter();
    // enditer();
private:
  Container <Triangle<T>, std::allocator<Triangle<T> > > maillage;
};

#include "Maillage.tpp"
#endif	/* MAILLAGE_H */

