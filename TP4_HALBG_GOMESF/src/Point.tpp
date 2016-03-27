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
void Point<T>::affiche(std::ostream &out) const
{
  out << "(x = " << abs << ", y = " << ord << ")"<< std::endl;
}

template<typename T>
void Point<T>::transformer(T m11, T m12, T m21, T m22)
{
	T x1 = (*this).x();
	T y1 = (*this).y();
	abs = m11*x1 + m21*y1;
	ord = m12*x1 + m22*y1;
}


template<typename T>
void Point<T>::deplacer(T dx, T dy)
{
	T x1 = (*this).x();
	T y1 = (*this).y();
	abs = x1 + dx;
	ord = y1 + dy;
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