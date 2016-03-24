#include "Point.h"
#include "Triangle.h"
#include "Maillage.h"

#include <list>

int main() {
  Point<float> p(2,3);
  p.affiche(std::cout);

  Point<float> p1(0,0);
  p1.affiche(std::cout);
  Point<float> p2(2,2);
  p2.affiche(std::cout);
  Point<float> p3(1,4);
  p3.affiche(std::cout);

  Triangle<float> t(p1, p2, p3);
  t.affiche(std::cout);


  Maillage<float, std::list> m(5, 6, p);

  return 0;
}
