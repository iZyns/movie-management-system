#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H
#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include "movie.h"

class MovieFactory {
public:
  MovieFactory();
  ~MovieFactory();
  Movie *
  factoryForMovies(char genre,
                   stringstream &ss); // produces the appropriate child object
};
#endif
