#ifndef BUSINESS_H
#define BUSINESS_H

#include "borrow.h"
#include "bstree.h"
#include "classic.h"
#include "comedy.h"
#include "customer.h"
#include "drama.h"
#include "hashtable.h"
#include "inventory.h"
#include "movie.h"
#include "moviefactory.h"
#include "return.h"
#include "tranfactory.h"
#include "trans.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Business {
public:
  Business();
  ~Business();
  void buildMovie(string filename);
  void buildCustomer(string filename); // params and return type not finished
  void processTrans(string filename);  // params and return type not finished

  Movie *factoryForMovies(ifstream infile); //

private:
  Inventory inventory;
  HashTable customers;
};

#endif