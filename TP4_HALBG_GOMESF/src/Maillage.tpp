/* 
 * File:   Maillage.tpp
 * Author: gomesf
 * 
 * Created on 24 mars 2016, 11:48
 */


template<typename T, typename U>
Maillage<T,U>::Maillage(int m, int n, const Point<T>& orig) {
    longueur = m;
    hauteur = n;
    origine = orig;
}

