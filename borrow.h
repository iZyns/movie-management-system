#ifndef BORROW_H
#define BORROW_H
#include "movie.h"
#include "trans.h"
#include <iostream>
using namespace std;

class Borrow : public Trans {
public:
  Borrow(); // constructor
  Borrow(char mediaType, char movieType, int custId, int month, int year,
         string majorActor);
  Borrow(char mediaType, char movieType, int custId, int year, string title);
  Borrow(char mediaType, char movieType, int custId, string director,
         string title);

  ~Borrow(); // destructor

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
  char movieType;
  char mediaType;
  int year, month;
  string director, title, majorActor;

  bool recovered;      // tracks whether this particular borrow object hass been
                       // nullified by a return object
  Movie *moviePointer; // stores a pointer to the movie that the transaction
                       // deals with
};

/*
  virtual char getMovieType() const;
  virtual char getMediaType() const;
  virtual int getYear() const;
  virtual int getMonth() const;
  virtual string getDirector() const;
  virtual string getTitle() const;
  virtual string getActor() const;
  virtual bool checkRecovered() const; // checks whether a borrow object has
  been returned virtual void nullify(); // nullifies a borrow object

  // LOOK INTO
  //
  THIS-------------------------------------------------------------------------------//
  virtual void identifierOne() const;
  virtual void identifierTwo() const;

  virtual Movie *getMoviePointer() const;
  virtual void setMoviePointer(Movie *m);
*/
#endif