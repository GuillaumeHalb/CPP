template<typename T>
Point<T>::Point(T x, T y) 
{
	abs = x;
	ord = y;
}

template<typename T>
T Point<T>::x() const
{
  return abs;
}

template<typename T>
T Point<T>::y() const
{
  return ord;
}
template<typename T>
T Point<T>::y() 
{
  return ord;
}
template<typename T>
T Point<T>::x() 
{
  return abs;
}

template<typename T>
void Point<T>::affiche(std::ostream &out) const
{
  out << "(x = " << abs << ", y = " << ord << ")"<< std::endl;
}


template<typename T>
T Point<T>::dist(const Point<T> & p1) const
{
  return sqrt(pow((p1.x()-(*this).x()),2) + pow((p1.y()-(*this).y()),2));
}



template<typename T>
void Point<T>::transformer(T m11, T m12, T m21, T m22)
{
	T x1 = ((*this).x())*m11 +m21*((*this).y()) ;
	T y1 = ((*this).x())*m12 +m22*((*this).y()) ;
	abs = x1;
	ord= y1;
}


template<typename T>
void Point<T>::deplacer(T dx, T dy)
{
	T x1 = ((*this).x())+dx;
	T y1 = ((*this).y()) + dy;
	abs = x1;
	ord = y1;
}

template<typename T>
void Point<T>::tourner(double angle, const Point<T>& pt)
{
	T x = (*this).x();
	T y = (*this).y();
	abs = pt.x() + (x - pt.x())*cos(angle) - sin(angle)*(y - pt.y());
	ord = pt.y() + (y - pt.y())*cos(angle) + sin(angle)*(x - pt.x());
}

template<typename T>
Point<T> & Point<T>::operator = (const Point<T> & P) 
{
	abs = P.x();
	ord = P.y();
	return *this;
}

template<typename T>
Point<T>::~Point()
{}