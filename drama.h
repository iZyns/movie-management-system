#ifndef DRAMA_H
#define DRAMA_H
#include "movie.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

class Movie;

class Drama : public Movie {
public:
  // functions and variables
  Drama(); // constructor
  Drama(char genre, int stock, string director, string title, int year);
  ~Drama(); // destructor

  // operator overload
  bool operator<(const Movie &movie) const;
  bool operator>(const Movie &movie) const;
  bool operator!=(const Movie &movie) const;
  bool operator==(const Movie &movie) const;
};
#endif
