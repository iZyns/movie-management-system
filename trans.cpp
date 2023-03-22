#include "trans.h"

/*
This is the transaction class. It's a parent class
*/

// constructors and destructors
Trans::Trans() {}
Trans::~Trans() {}

// output operator
ostream &operator<<(ostream &out, const Trans &trans) {
  if (trans.tranType == 'B') {
    out << "    Borrowed " << trans.getMoviePointer()->getTitle() << " by "
        << trans.getMoviePointer()->getDirector();
  } else if (trans.tranType == 'R') {
    out << "    Returned " << trans.getMoviePointer()->getTitle() << " by "
        << trans.getMoviePointer()->getDirector();
  }
  return out;
}

// TRANS GETTERS/SETTER:
char Trans::getTranType() const { return tranType; }
int Trans::getcustId() const { return custID; }
