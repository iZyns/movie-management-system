#include "inventory.h"
#include <iostream>

/*
This is the inventory class that handles the movie inventory.
*/

// constructor and destructors
Inventory::Inventory() = default;

Inventory::~Inventory() {
  classic.makeEmpty();
  drama.makeEmpty();
  comedy.makeEmpty();
}

// add function to add a movie to the tree depending on the genre
bool Inventory::add(Movie *movie) {
  if (movie == nullptr) {
    return false;
  }
  switch (movie->getGenre()) {
  case 'C':
    return classic.insert(movie);
  case 'D':
    return drama.insert(movie);
  case 'F':
    return comedy.insert(movie);
  }
  return false;
}

// retrieve function to retrieve a movie from the correct tree based on the
// genre
bool Inventory::retrieve(Movie *movie, Movie *&find) {
  BSTree *tree;
  switch (movie->getGenre()) {
  case 'C':
    tree = &classic;
    return tree->retrieve(movie, find);
  case 'D':
    tree = &drama;
    return tree->retrieve(movie, find);
  case 'F':
    tree = &comedy;
    return tree->retrieve(movie, find);
  }
  return false;
}

// prints all the available movie
void Inventory::printMovie() {
  cout << "Comedy:" << endl;
  cout << " Year: #: Title:      Director:" << endl;
  cout << comedy << endl;
  cout << "Drama:" << endl;
  cout << " Year: #: Title:      Director:" << endl;
  cout << drama << endl;
  cout << "Classic:" << endl;
  cout << " Date: #: Title:      Director:      Major Actor: " << endl;
  cout << classic << endl;
  cout << "----------------------------------" << endl << endl;
}
