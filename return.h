#ifndef RETURN_H
#define RETURN_H
#include "trans.h"
#include <iostream>
using namespace std;

class Trans;

class Return : public Trans {
public:
  Return(); // constructor
  Return(char mediaType, char movieType, int custId, int month, int year,
         string majorActor);
  Return(char mediaType, char movieType, int custId, int year, string title);
  Return(char mediaType, char movieType, int custId, string director,
         string title);
  ~Return(); // destructor

  // getters and setters
  char getMovieType() const;
  char getMediaType() const;
  int getYear() const;
  int getMonth() const;
  string getDirector() const;
  string getTitle() const;
  string getActor() const;
  Movie *getMoviePointer() const;
  void setMoviePointer(Movie *);

  bool checkRecovered() const;
  void nullify();

private:
  // Identifiers:
  char mediaType;
  char movieType;
  int year, month;
  string director, title, majorActor;

  Movie *moviePointer; // stores a pointer to the movie that the transaction
                       // deals with
};
#endif