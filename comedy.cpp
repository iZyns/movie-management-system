#include "comedy.h"

/*
This is the comedy class which inherits from movie class. It holds the operation
for the comedy genre.
*/

Comedy::Comedy() { genre_ = 'F'; }
Comedy::~Comedy() {}
Comedy::Comedy(char genre, int stock, string director, string title, int year) {
  genre_ = 'F';
  stock_ = stock;
  director_ = director;
  title_ = title;
  year_ = year;
}

// operator overloads
bool Comedy::operator<(const Movie &movie) const {
  if (getYear() < movie.getYear()) {
    return true;
  } else if (getYear() == movie.getYear() && getTitle() < movie.getTitle()) {
    return true;
  }
  return false;
}
bool Comedy::operator>(const Movie &movie) const { return !(*this < movie); }
bool Comedy::operator==(const Movie &movie) const {
  if (getYear() == movie.getYear() && getTitle() == movie.getTitle()) {
    return true;
  }
  return false;
}

bool Comedy::operator!=(const Movie &movie) const { return !(*this == movie); }
