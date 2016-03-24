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