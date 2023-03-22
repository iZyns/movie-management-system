#include "movie.h"

/*
This is the movie class. It's a parent class.
*/

// output operator
ostream &operator<<(ostream &out, const Movie &movie) {
  if (movie.getGenre() == 'F') {
    out << movie.year_ << " " << movie.stock_ << " " << movie.title_ << ", "
        << movie.director_ << endl;
  } else if (movie.getGenre() == 'D') {
    out << movie.year_ << " " << movie.stock_ << " " << movie.title_ << ", "
        << movie.director_ << endl;
  } else if (movie.getGenre() == 'C') {
    out << movie.month_ << " " << movie.year_ << " " << movie.stock_ << " "
        << movie.title_ << ", " << movie.director_ << ", " << movie.majorActor_
        << endl;
  }
  return out;
}

// DEFAULT CONSTRUCTORS:
Movie::Movie() {}
Movie::Movie(const Movie &other) { *this = other; }
Movie::~Movie() {}

// BORROW AND RETURN
bool Movie::borrowMovie() {
  if (stock_ > 0) {
    this->stock_--;
    return true;
  } else {
    cout << "BORROW TRANSACTION FAILED: " << getTitle() << " is out of stock." << endl;
    return false;
  }
}
void Movie::returnMovie() { stock_++; }

// MOVIE GETTERS/SETTERS:
char Movie::getGenre() const { return genre_; }
void Movie::setGenre(char genre) { genre_ = genre; }
string Movie::getDirector() const { return director_; }
void Movie::setDirector(string director) { director_ = director; }
string Movie::getTitle() const { return title_; }
void Movie::setTitle(string title) { title_ = title; }
int Movie::getYear() const { return year_; }
void Movie::setYear(int year) { year_ = year; }
int Movie::getStock() const { return stock_; }
string Movie::getActor() const { return majorActor_; }
void Movie::setActor(string actor) { majorActor_ = actor; }
void Movie::setMonth(int month) { month_ = month; }
int Movie::getMonth() const { return month_; }
