#include "tranfactory.h"

/*
This is the factory class for transaction.
*/

TranFactory::TranFactory() {}

TranFactory::~TranFactory() {}

// FACTORY METHOD FOR TRANSACTIONS
Trans *TranFactory::factoryForTransactions(char action, stringstream &ss) {
  char mediaType, movieType;
  int custId;
  switch (action) {
  case 'B':
    ss >> custId >> mediaType >> movieType;
    // returns a borrow object
    return readBorrow(mediaType, movieType, custId, ss);
  case 'R':
    ss >> custId >> mediaType >> movieType;
    // returns a return object
    return readReturn(mediaType, movieType, custId, ss);
  default: // if it is an invalid transaction
    cerr << action << " is not a valid command." << endl;
    return nullptr;
  }
}

// ASSISTANT FOR FACTORY METHOD
Trans *TranFactory::readBorrow(char mediaType, char movieType, int custId,
                               stringstream &ss) {
  string word;
  if (movieType == 'C') {
    int month, year;
    string majorActor;
    ss.ignore(1, ' ');
    getline(ss, word, ' ');
    month = stoi(word);
    getline(ss, word, ' ');
    year = stoi(word);
    getline(ss, word, ' ');
    majorActor = word;
    majorActor += " ";
    getline(ss, word, '\n');
    majorActor += word;
    return new Borrow(mediaType, movieType, custId, month, year, majorActor);
  } else if (movieType == 'F') {
    int year;
    string title;
    ss.ignore(1, ' ');
    getline(ss, word, ',');
    title = word;
    getline(ss, word, '\n');
    year = stoi(word);
    return new Borrow(mediaType, movieType, custId, year, title);
  } else if (movieType == 'D') {
    string director, title;
    ss.ignore(1, ' ');
    getline(ss, word, ',');
    director = word;
    ss.ignore(1, ' ');
    getline(ss, word, ',');
    title = word;
    return new Borrow(mediaType, movieType, custId, director, title);
  } else {
    cout << "Error: " << movieType << " is not a valid movie type." << endl;
    return nullptr;
  }
}

// ASSISTANT FOR FACTORY METHOD:
Trans *TranFactory::readReturn(char mediaType, char movieType, int custId,
                               stringstream &ss) {
  string word;
  switch (movieType) {
  case 'C': {
    int month, year;
    string majorActor;
    ss.ignore(1, ' ');
    getline(ss, word, ' ');
    month = stoi(word);
    getline(ss, word, ' ');
    year = stoi(word);
    getline(ss, word, ' ');
    majorActor = word;
    majorActor += " ";
    getline(ss, word, '\n');
    majorActor += word;
    return new Return(mediaType, movieType, custId, month, year, majorActor);
  }
  case 'F': {
    int year;
    string title;
    ss.ignore(1, ' ');
    getline(ss, word, ',');
    title += word;
    getline(ss, word, '\n');
    year = stoi(word);
    return new Return(mediaType, movieType, custId, year, title);
  }
  case 'D': {
    string director, title;
    getline(ss, word, ',');
    director = word;
    ss.ignore(1, ' ');
    getline(ss, word, '\n');
    title += word;
    return new Return(mediaType, movieType, custId, director, title);
  }
  default:
    cout << "Error: " << movieType << " is not a valid movie type." << endl;
    return nullptr;
  }
}
