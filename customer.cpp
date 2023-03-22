#include "customer.h"

/*
This is the customer class that handles the operation of customers.
*/

// output operator
ostream &operator<<(ostream &out, const Customer &customer) {
  out << customer.getId() << " " << customer.getName();
  return out;
}

// constructors and destructors
Customer::Customer() {}

Customer::Customer(int id, string firstName, string lastName) {
  this->customerId = id;
  this->firstName = firstName;
  this->lastName = lastName;
}

Customer::~Customer() {}

// getters
int Customer::getId() const { return this->customerId; }

string Customer::getName() const { return firstName + " " + lastName; }

// STORES RETURN TRANSACTION IF CORRESTONDING BORROW TRANSACTION IS FOUND
bool Customer::findBorrow(Movie *m, Trans *tran) {
  for (int i = 0; i < history.size(); i++) {
    Trans *curr = history[i];
    // if it is a borrow object, and it has not been nullified
    if (curr->getTranType() == 'B' && !curr->checkRecovered()) {
      if (*m == *curr->getMoviePointer()) {
        curr->getMoviePointer()->returnMovie();
        curr->nullify();
        tran->setMoviePointer(curr->getMoviePointer());
        history.push_back(tran);
        return true;
      }
    }
  }
  cout << "RETURN TRANSACTION FAILED: Movie not found in " << getId()
       << " History" << endl;
  return false;
}

void Customer::addTrans(Trans *tran) { history.push_back(tran); }

void Customer::getHistory() {
  cout << firstName + " " + lastName;
  cout << " Transaction history: " << endl;
  for (int i = history.size() - 1; i >= 0; i--) {
    cout << *history[i] << endl;
  }
  cout << "----------------------------------" << endl;
}

Customer *Customer::nextCust() { return next; }

void Customer::setCust(Customer *newCust) { next = newCust; }

void Customer::setId(int id) { this->customerId = id; }
