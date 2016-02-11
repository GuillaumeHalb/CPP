/*!
 * \file main.cpp
 * \brief fichier main testant les fonctions demandées
 * \author Halb Guillaume, Gomes Filipe
 */

#include "Dvector.h"
#include <iostream>
#include <cstdlib>

int main() {
  /*! Teste la création des vecteurs avec leur affichage */
  Dvector a; 
  a.display(std::cout);

  Dvector *p = new Dvector(3,2.0);
  p->display(std::cout);

  /*! Teste le renvoit de la dimension */
  int d = p->size();
  std::cout << "dimension = "<<d<<std::endl;

  /*! Teste le remplissage aléatoire du vecteur */
  p->fillRandomly();
  p->display(std::cout);

  /*! Teste le constructeur par copie */
  Dvector *q(p);
  q->display(std::cout);

  /*! Teste par lecture du fichier*/
  Dvector *r = new Dvector("essai.txt");
  r->display(std::cout); 

  /*! Désalloue la mémoire utilisee */
  delete p;
  delete r;

  Dvector x = Dvector(3,1.);  
}
