/* 
 * File:   Maillage.tpp
 * Author: gomesf
 * 
 * Created on 24 mars 2016, 11:48
 */

#include <iostream>
#include <fstream>

template<typename T, template <typename, typename> class Container>
Maillage<T, Container>::Maillage(int m, int n, const Point<T>& orig)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			Point<T> p0(i,j);
			Point<T> p1((i+1),j);
			Point<T> p2(i,(j+1));
			Point<T> p3((i+1),(j+1));
			Triangle<T> trgInf = Triangle<T>(p0,p1,p2);
			Triangle<T> trgSup = Triangle<T>(p1,p2,p3);
			
			(*this).maillage.push_back(trgInf);
			(*this).maillage.push_back(trgSup);
		}
	}
}




template<typename T, template <typename, typename> class Container>
typename Container <Triangle<T>, std::allocator<Triangle<T> > > ::const_iterator Maillage<T, Container>::beginiter() const
{
	return (*this).maillage.begin();
}




template<typename T, template <typename, typename> class Container>
typename Container <Triangle<T>, std::allocator<Triangle<T> > > ::const_iterator Maillage<T, Container>::enditer() const
{
	return (*this).maillage.end();
}





template<typename T, template <typename, typename> class Container>
std::ostream & operator <<(std::ostream &Out, const Maillage<T,Container> &maille)
{
	typename Container <Triangle<T>, std::allocator<Triangle<T> > > ::const_iterator it;
			
	for(it = maille.beginiter();  it != maille.enditer(); it++)
	{
		Out<<(*it).p1().x()<<" "<<(*it).p1().y()<<std::endl;
		Out<<(*it).p2().x()<<" "<<(*it).p2().y()<<std::endl;
		Out<<(*it).p3().x()<<" "<<(*it).p3().y()<<std::endl;
		Out<<(*it).p1().x()<<" "<<(*it).p1().y()<<std::endl;
		Out<<std::endl;
	}
	return Out;
}


template<typename T, template <typename, typename> class Container>
void Maillage<T, Container>::transformer(T m11, T m12, T m21, T m22)
{
	typename Container <Triangle<T>, std::allocator<Triangle<T> > > ::iterator it;
			
	for(it = (*this).maillage.begin();  it != (*this).maillage.end(); it++)
	{
		(*it).transformer(m11,m12,m21,m22);
	}
}

template<typename T, template <typename, typename> class Container>
void Maillage<T, Container>::deplacer(T dx, T dy) 
{
	typename Container <Triangle<T>, std::allocator<Triangle<T> > > ::iterator it;
		
	for(it = (*this).maillage.begin();  it != (*this).maillage.end(); it++)
	{
		(*it).deplacer(dx, dy);
	}
}

template<typename T, template <typename, typename> class Container>
void Maillage<T, Container>::tourner(double angle, const Point<T>& pt) 
{
	typename Container <Triangle<T>, std::allocator<Triangle<T> > > ::iterator it;

	for(it = (*this).maillage.begin();  it != (*this).maillage.end(); it++)
	{
		(*it).tourner(angle, pt);
	}
}

template<typename T, template <typename, typename> class Container>
Maillage<T,Container>::Maillage(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4, int m, int n)
{
	//cas invalides
	if (m==0 || n==0) {
		throw std::invalid_argument("Il faut que m ou n soit supérieur à 1");
	}
	if (p1.dist(p2) != p3.dist(p4) || p1.dist(p4) != p2.dist(p3)) {
		throw std::invalid_argument("L'objet consideré n'est pas un rectangle");
	}

	//Création du maillage initial à partir de p(0.0,0.0)
	Point<T> p(0.0,0.0);
	Maillage<T, Container> mailleInit(m, n, p);

	//Redimensionnement à la bonne échelle
	mailleInit.transformer(p1.dist(p2)/m, 0, 0, p3.dist(p1)/n); 

	//Translation de l'origine à p1
	mailleInit.deplacer(p1.x(),p1.y());

	//Dernière étape: positionner le rectangle (avec une rotation si besoin)
	if (!(p2.y() == p1.y())) {
		mailleInit.tourner(atan((p2.y()-p1.y())/(p2.x()-p1.x())), p1);
	}

	(*this).maillage = mailleInit.getMaillage();
}

template<typename T, template <typename, typename> class Container>
Container <Triangle<T>, std::allocator<Triangle<T> > > Maillage<T,Container>::getMaillage()
{
	return (*this).maillage;
}