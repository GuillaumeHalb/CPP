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
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
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
	typename Container <Triangle<T>, std::allocator<Triangle<T> > > ::const_iterator it;
			
	for(it = beginiter();  it != enditer(); it++)
	{
		it->affiche;
		//.transformer(m11,m12,m21,m22);
	}
}

template<typename T, template <typename, typename> class Container>
void Maillage<T, Container>::deplacer(T dx, T dy)
{
	typename Container <Triangle<T>, std::allocator<Triangle<T> > > ::const_iterator it;
			
	for(it = (*this).beginiter();  it != (*this).enditer(); it++)
	{
		(*it).deplacer(dx, dy);
	}
}

template<typename T, template <typename, typename> class Container>
void Maillage<T, Container>::tourner(double angle, const Point<T>& pt)
{
	typename Container <Triangle<T>, std::allocator<Triangle<T> > > ::const_iterator it;
			
	for(it = (*this).beginiter();  it != (*this).enditer(); it++)
	{
		(*it).p1().x() = pt.x() + ((*it).p1().x() - pt.x())*cos(angle) - sin(angle)*((*it).p1().y() - pt.y());
		(*it).p1().y() = pt.y() + ((*it).p1().y() - pt.y())*cos(angle) + sin(angle)*((*it).p1().x() - pt.x());

		(*it).p2().x() = pt.x() + ((*it).p2().x() - pt.x())*cos(angle) - sin(angle)*((*it).p2().y() - pt.y());
		(*it).p2().y() = pt.y() + ((*it).p2().y() - pt.y())*cos(angle) + sin(angle)*((*it).p2().x() - pt.x());

		(*it).p3().x() = pt.x() + ((*it).p3().x() - pt.x())*cos(angle) - sin(angle)*((*it).p3().y() - pt.y());
		(*it).p3().y() = pt.y() + ((*it).p3().y() - pt.y())*cos(angle) + sin(angle)*((*it).p3().x() - pt.x());
	}
}