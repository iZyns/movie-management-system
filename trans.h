#ifndef TRANS_H
#define TRANS_H
#include "inventory.h"
#include "movie.h"
#include <iostream>
#include <string>

using namespace std;

class Inventory;
class Movie;

class Trans {
  friend ostream &operator<<(ostream &out, const Trans &trans);

public:
  Trans();          // constructor
  virtual ~Trans(); // destructor

  // Access Identifiers:
  virtual char getMovieType() const = 0;
  virtual char getMediaType() const = 0;
  virtual int getYear() const = 0;
  virtual int getMonth() const = 0;
  virtual string getDirector() const = 0;
  virtual string getTitle() const = 0;
  virtual string getActor() const = 0;
  virtual bool checkRecovered() const = 0; // checks whether a borrow object has been returned
  virtual void nullify() = 0; // nullifies a borrow object

  // LOOK INTO
  // THIS-------------------------------------------------------------------------------//
  // virtual void identifierOne() const;
  // virtual void identifierTwo() const;

  virtual Movie *getMoviePointer() const = 0;
  virtual void setMoviePointer(Movie *m) = 0;

  // Access Identifiers for all Transactions:
  char getTranType() const;
  int getcustId() const;

protected:
  // Identifiers for all Transactions:
  char tranType;
  int custID;
};
#endif
