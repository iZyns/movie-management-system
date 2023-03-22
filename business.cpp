#include "business.h"

/*
This is the business class that handles the operation.

*/

//business constructor and destructor
Business::Business() {}
Business::~Business() {}

//buildMovie function to load the movies
void Business::buildMovie(string filename) {
  ifstream infile(filename);
  if (!infile) {
    cout << "File could not be opened." << endl;
    return;
  }
  string line;
  MovieFactory *movieCreator = new MovieFactory();
  while (getline(infile, line)) {
    char type;
    stringstream ss(line);
    ss >> type;
    Movie *newMovie =
        movieCreator->factoryForMovies(type, ss);
    inventory.add(newMovie);
  }
  delete movieCreator;
  infile.close();
}

//build customer function to load the customers
void Business::buildCustomer(string filename) {
  ifstream infile(filename);
  if (!infile) {
    cout << "File could not be opened." << endl;
    return;
  }
  string line;
  while (getline(infile, line)) {
    int id;
    string firstName, lastName;
    stringstream ss(line);
    ss >> id >> firstName >> lastName;
    Customer *cust = new Customer(id, firstName, lastName);
    customers.insert(cust);
  }
  infile.close();
}

//processTrans function to load the transaction and process them
void Business::processTrans(string filename) {
  ifstream infile(filename);
  if (!infile) {
    cout << "File could not be opened." << endl;
    return;
  }
  string line;
  TranFactory *transCreator = new TranFactory();
  while (getline(infile, line)) {
    stringstream ss(line);
    char action;
    ss >> action;

    if (action == 'I') {
      inventory.printMovie();
    } else if (action == 'H') {
      int id;
      ss >> id;
      Customer *findCustomer;
      bool custFound = customers.retrieve(id, findCustomer);
      if (!custFound) {
        cout << "Customer ID not found within inventory. Transaction not recorded" << endl;
      }
      findCustomer->getHistory();
    } else {
      Trans *transact = transCreator->factoryForTransactions(action, ss);
      if (transact == nullptr) {
        cout << "Error in transaction input. Transaction not recorded." << endl;
      } else {
        char tranType = transact->getTranType();
        Customer *findCustomer;
        bool custFound = customers.retrieve(transact->getcustId(), findCustomer);
        if (!custFound) {
          cout << "Customer ID not found within inventory. Transaction not recorded." << endl;
          delete transact;
        } else if (tranType == 'R' || tranType == 'B') {
          // create a temporary movie object with key identifiers
          // this is to search existing data for the movie
          Movie *c;
          if (transact->getMovieType() == 'C') {
            c = new Classic();
            c->setMonth(transact->getMonth());
            c->setYear(transact->getYear());
            c->setActor(transact->getActor());
          } else if (transact->getMovieType() == 'F') {
            c = new Comedy();
            c->setYear(transact->getYear());
            c->setTitle(transact->getTitle());
          } else if (transact->getMovieType() == 'D') {
            c = new Drama();
            c->setDirector(transact->getDirector());
            c->setTitle(transact->getTitle());
          }
          if (tranType == 'B') {
            // BORROW
            Movie *findMovie;
            // search for movie in inventory
            bool movieFound = inventory.retrieve(c, findMovie);
            // borrows movie if it exists and is in stock
            if (movieFound && findMovie->borrowMovie()) {
              // save a pointer to the movie within the transaction
              transact->setMoviePointer(findMovie);
              // record the transaction in the customer's history
              findCustomer->addTrans(transact);
            } else {
              cout << "Error: Movie " << c->getTitle() << " not found. Transaction not recorded." << endl;
              delete transact;
            }
          } else {
            // RETURN
            if (!findCustomer->findBorrow(c, transact)) {
              delete transact;
            }
          }
          delete c; // no need for temporary movie object
        }
      }
    }
  }
  delete transCreator;
  infile.close();
}