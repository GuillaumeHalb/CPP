template<typename T>
Triangle<T>::Triangle(Point<T> pt1, Point<T> pt2, Point<T> pt3) :
   point1( pt1 )
{
 
  point2 = pt2;
  point3 = pt3;
}

template<typename T>
Point<T> Triangle<T>::p1() const
{
  return point1;
}

template<typename T>
Point<T> Triangle<T>::p2() const
{
  return point2;
}

template<typename T>
Point<T> Triangle<T>::p3() const
{
  return point3;
}

template<typename T>
Point<T> Triangle<T>::p1() 
{
  return point1;
}

template<typename T>
Point<T> Triangle<T>::p2() 
{
  return point2;
}

template<typename T>
Point<T> Triangle<T>::p3() 
{
  return point3;
}
template<typename T>
void Triangle<T>::affiche(std::ostream &out) const
{
   out << "Affichage du triangle" << std::endl;
   out << "point1 :" << std::endl;
   point1.affiche(out);
   out << "point2 :" << std::endl;
   point2.affiche(out);
   out << "point3 :" << std::endl;
   point3.affiche(out);
}


template<typename T>
void Triangle<T>::transformer(T m11, T m12, T m21, T m22) 
{
  point1.transformer(m11,m12,m21,m22);
  point2.transformer(m11,m12,m21,m22);
  point3.transformer(m11,m12,m21,m22);
}

template<typename T>
void Triangle<T>::deplacer(T dx, T dy)
{
  point1.deplacer(dx, dy);
  point2.deplacer(dx, dy);
  point3.deplacer(dx, dy);
}

template<typename T>
void Triangle<T>::tourner(double angle, const Point<T>& pt)
{
  point1.tourner(angle, pt);
  point2.tourner(angle, pt);
  point3.tourner(angle, pt);
}