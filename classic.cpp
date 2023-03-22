#include "classic.h"

/*
This is the classic class which inherits from movie class. It handles the
operation for classic movies.
*/

// constructors and destructors
Classic::Classic() { genre_ = 'C'; }
Classic::~Classic() {}
Classic::Classic(char genre, int stock, string director, string title,
                 string majorActor, int month, int year) {
  genre_ = 'C';
  stock_ = stock;
  director_ = director;
  title_ = title;
  majorActor_ = majorActor;
  month_ = month;
  year_ = year;
}

// operator overloads
bool Classic::operator<(const Movie &movie) const {
  const Classic &classic = static_cast<const Classic &>(movie);
  if (getYear() < classic.getYear()) {
    return true;
  } else if (getYear() == classic.getYear() &&
             getMonth() < classic.getMonth()) {
    return true;
  } else if (getYear() == classic.getYear() &&
             getMonth() == classic.getMonth() &&
             getActor() < classic.getActor()) {
    return true;
  }
  return false;
}
bool Classic::operator>(const Movie &movie) const { return !(*this < movie); }

bool Classic::operator==(const Movie &movie) const {
  if (getYear() == movie.getYear() && getMonth() == movie.getMonth()) {
    return true;
  }
  return false;
}
bool Classic::operator!=(const Movie &movie) const { return !(*this == movie); }
