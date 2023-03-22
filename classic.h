#ifndef CLASSIC_H
#define CLASSIC_H
#include "movie.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Classic : public Movie {
public:
  Classic(); // constructor
  Classic(char genre, int stock, string director, string title,
          string majorActor, int month, int year);
  ~Classic(); // destructor

  // operator overload
  bool operator<(const Movie &movie) const;
  bool operator>(const Movie &movie) const;
  bool operator!=(const Movie &movie) const;
  bool operator==(const Movie &movie) const;
};

#endif