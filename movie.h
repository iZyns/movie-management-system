#ifndef MOVIE_H
#define MOVIE_H
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Movie {
  friend ostream &operator<<(ostream &out, const Movie &movie);

public:
  Movie(); // constructor
  Movie(const Movie &other);
  virtual ~Movie(); // destructor

  // Movie* pointers that contain child objects wont use these default functions
  virtual bool operator<(const Movie &movie) const = 0;
  virtual bool operator>(const Movie &movie) const = 0;
  virtual bool operator!=(const Movie &movie) const = 0;
  virtual bool operator==(const Movie &movie) const = 0;

  // RETURNING AND BORROWING:
  bool borrowMovie();
  void returnMovie();

  // GETTERS/SETTERS:
  char getGenre() const; // get the genre of the movie
  void setGenre(char genre);
  string getDirector() const; // get the movie director
  void setDirector(string director);
  string getTitle() const; // get the movie title
  void setTitle(string title);
  int getYear() const; // get the released year for the movie
  void setYear(int year);
  int getStock() const; // get the amount of movie

  // set data

  // CLASSIC GETTERS/SETTERS:
  string getActor() const;
  void setActor(string actor);
  int getMonth() const;
  void setMonth(int month);


protected:
  char genre_;
  int stock_;
  string director_;
  string title_;
  int year_;
  string majorActor_;
  int month_;
};

#endif
