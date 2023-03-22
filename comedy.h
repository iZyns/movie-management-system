#ifndef COMEDY_H
#define COMEDY_H
#include "movie.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

class Comedy : public Movie {
public:
  // functions and variables
  Comedy(); // constructor
  Comedy(char genre, int stock, string director, string title, int year);
  ~Comedy(); // destructor

  // operator overload
  bool operator<(const Movie &movie) const;
  bool operator>(const Movie &movie) const;
  bool operator!=(const Movie &movie) const;
  bool operator==(const Movie &movie) const;
};
#endif