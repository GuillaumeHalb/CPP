#include "Point.h"
#include "Triangle.h"
#include "Maillage.h"

#include <list>

int main() {
  Point<float> p(0.0,0.0);
  //p.affiche(std::cout);
  
  std::cout<<"test transformation(1.0,1.0,1.0,1.0) -> ";
  p.transformer(1.0,1.0,1.0,1.0);
  p.affiche(std::cout);
  std::cout<<std::endl;

  //std::cout<<"test deplacer(4.2,6.8) -> ";
  //p.deplacer(4.2,6.8);
  //p.affiche(std::cout);
  std::cout<<std::endl;

  Point<float> p1(1.0,2.0);
  //p1.affiche(std::cout);
  Point<float> p2(-2.0,1.0);
  //p2.affiche(std::cout);
  Point<float> p3(-1.0,3.0);
  //p3.affiche(std::cout);

  /*
  std::cout<<"test transformation(1.0,1.0,1.0,1.0) -> ";
  Triangle<float> t(p1, p2, p3);
  t.affiche(std::cout);
  t.transformer(2.0,0.0,-10.0,9.0);
  t.affiche(std::cout);
  std::cout<<std::endl;
  std::cout<<"test deplacer(4.2,6.8) -> ";
  t.deplacer(1.5,1.5);
  t.affiche(std::cout);
  std::cout<<std::endl;
  */

  Maillage<float, std::list> m(1, 2, p);
  std::cout<<m;
  m.transformer(2.0,1.0,1.0,1.0);
  std::cout<<m;
  m.deplacer(4.0,16.0);
  std::cout<<m;

  Maillage<float, std::list> maille(p,p1,p2,p3,2,3);
  std::cout<<maille;

  return 0;
}
