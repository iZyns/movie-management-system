#include "drama.h"

/*
This is the drama class that which inherits from movie class. This holds the
operation for drama genre.
*/

// constructors and destructors
Drama::Drama() { genre_ = 'D'; }

Drama::Drama(char genre, int stock, string director, string title, int year) {
  genre_ = 'D';
  stock_ = stock;
  director_ = director;
  title_ = title;
  year_ = year;
}

Drama::~Drama() {}

// operator overloads
bool Drama::operator<(const Movie &movie) const {
  if (getTitle() < movie.getTitle()) {
    return true;
  } else if (getTitle() == movie.getTitle() &&
             getDirector() < movie.getDirector()) {
    return true;
  }
  return false;
}
bool Drama::operator>(const Movie &movie) const { return !(*this < movie); }

bool Drama::operator==(const Movie &movie) const {
  if (getTitle() == movie.getTitle() && getDirector() == movie.getDirector()) {
    return true;
  }
  return false;
}
bool Drama::operator!=(const Movie &movie) const { return !(*this == movie); }
