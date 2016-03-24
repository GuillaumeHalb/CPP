/* 
 * File:   Maillage.h
 * Author: gomesf
 *
 * Created on 24 mars 2016, 11:48
 */
#include "Point.h"

#ifndef MAILLAGE_H
#define	MAILLAGE_H

template<typename T, typename U>
class Maillage {
public:
    Maillage(int m, int n, const Point<T>& orig);
    ~Maillage();
    beginiter();
    enditer();
private:
    int longueur;
    int hauteur;
    Point<T> origine;
};

#include "Maillage.tpp"
#endif	/* MAILLAGE_H */

