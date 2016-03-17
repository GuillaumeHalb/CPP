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
Point<T>::~Point()
{}