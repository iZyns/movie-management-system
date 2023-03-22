#ifndef INVENTORY_H
#define INVENTORY_H

#include "bstree.h"
#include "movie.h"
#include <string>

using namespace std;
class Movie;

class Inventory {
public:
  Inventory();
  ~Inventory();

  bool add(Movie *);
  bool retrieve(Movie *movie, Movie *&m);
  void printMovie();

private:
  BSTree classic;
  BSTree drama;
  BSTree comedy;
};

#endif
