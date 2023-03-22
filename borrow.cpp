#include "borrow.h"

/*
This is the borrow class that inherits from transaction class. It handles the
borrow transaction.
*/

Borrow::Borrow() { tranType = 'B'; }

// CONSTRUCTORS FOR BORROW:
Borrow::Borrow(char mediaType, char movieType, int custId, int month, int year,
               string majorActor)
    : mediaType(mediaType), movieType(movieType), month(month), year(year),
      majorActor(majorActor) {
  custID = custId;
  tranType = 'B';
  recovered = false;
}
Borrow::Borrow(char mediaType, char movieType, int custId, int year,
               string title)
    : mediaType(mediaType), movieType(movieType), year(year), title(title) {
  custID = custId;
  tranType = 'B';
  recovered = false;
}
Borrow::Borrow(char mediaType, char movieType, int custId, string director,
               string title)
    : mediaType(mediaType), movieType(movieType), director(director),
      title(title) {
  custID = custId;
  tranType = 'B';
  recovered = false;
}

Borrow::~Borrow() {}

// BORROW GETTERS/SETTERS:
char Borrow::getMovieType() const { return movieType; }
char Borrow::getMediaType() const { return mediaType; }
int Borrow::getYear() const { return year; }
int Borrow::getMonth() const { return month; }
string Borrow::getDirector() const { return director; }
string Borrow::getTitle() const { return title; }
string Borrow::getActor() const { return majorActor; }
Movie *Borrow::getMoviePointer() const { return moviePointer; }
void Borrow::setMoviePointer(Movie *m) { moviePointer = m; }
bool Borrow::checkRecovered() const { return recovered; }
void Borrow::nullify() { recovered = true; }