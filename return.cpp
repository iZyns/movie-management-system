#include "return.h"

/*
This is the return class that inherits from transaction. It handles the
operation for returning a movie.
*/

Return::Return() { tranType = 'R'; }

// CONSTRUCTORS FOR RETURN:
Return::Return(char mediaType, char movieType, int custId, int month, int year,
               string majorActor)
    : mediaType(mediaType), movieType(movieType), month(month), year(year),
      majorActor(majorActor) {
  custID = custId;
  tranType = 'R';
}
Return::Return(char mediaType, char movieType, int custId, int year,
               string title)
    : mediaType(mediaType), movieType(movieType), year(year), title(title) {
  custID = custId;
  tranType = 'R';
}
Return::Return(char mediaType, char movieType, int custId, string director,
               string title)
    : mediaType(mediaType), movieType(movieType), director(director),
      title(title) {
  custID = custId;
  tranType = 'R';
}

Return::~Return() {}

// RETURN GETTERS/SETTERS:
char Return::getMovieType() const { return movieType; }
char Return::getMediaType() const { return mediaType; }
int Return::getYear() const { return year; }
int Return::getMonth() const { return month; }
string Return::getDirector() const { return director; }
string Return::getTitle() const { return title; }
string Return::getActor() const { return majorActor; }
Movie *Return::getMoviePointer() const { return moviePointer; }
void Return::setMoviePointer(Movie *m) { moviePointer = m; }

bool Return::checkRecovered() const { return true; }
void Return::nullify() {}