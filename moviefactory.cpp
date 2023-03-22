#include "moviefactory.h"

/*
Factory class for movie.
*/

MovieFactory::MovieFactory() {}

MovieFactory::~MovieFactory() {}

Movie *MovieFactory::factoryForMovies(char genre, stringstream &ss) {
  if (genre == 'D') {
    string word; // used to parse stringstream
    string director, title;
    int stock, year;
    ss.ignore(1, ',');
    ss >> stock;
    ss.ignore(1, ',');
    ss.ignore(1, ' ');
    getline(ss, word, ',');
    director = word; // append the word to the first part string
    ss.ignore(1, ' ');
    getline(ss, word, ',');
    title = word;
    getline(ss, word, '\n');
    year = stoi(word);
    return new Drama(genre, stock, director, title, year);
  } else if (genre == 'F') {
    string word; // used to parse stringstream
    string director, title;
    int stock, year;
    ss.ignore(1, ',');
    ss >> stock;
    ss.ignore(1, ',');
    ss.ignore(1, ' ');
    getline(ss, word, ',');
    director = word; // append the word to the first part string
    ss.ignore(1, ' ');
    getline(ss, word, ',');
    title += word;
    getline(ss, word, '\n');
    year = stoi(word);
    return new Comedy(genre, stock, director, title, year);
  } else if (genre == 'C') {
    string word; // used to parse stringstream
    string director, majorActor, title;
    int stock, month, year;
    ss.ignore(1, ',');
    ss >> stock;
    ss.ignore(1, ',');
    ss.ignore(1, ' ');
    getline(ss, word, ',');
    director = word;
    ss.ignore(1, ' ');
    getline(ss, word, ',');
    title = word;
    ss.ignore(1, ' '); //
    getline(ss, word, ' ');
    majorActor = word;
    majorActor += " ";
    getline(ss, word, ' ');
    majorActor += word;
    getline(ss, word, ' ');
    month = stoi(word);
    getline(ss, word, '\n');
    year = stoi(word);
    return new Classic(genre, stock, director, title, majorActor, month, year);
  } else {
    return nullptr;
  }
}