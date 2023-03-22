#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "movie.h"
#include "trans.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Customer {
  friend ostream &operator<<(ostream &out, const Customer &customer);

public:
  // functions and variables
  Customer(); // constructor
  Customer(int id, string firstName, string lastName);
  ~Customer(); // destructor

  int getId() const;
  void setId(int id);
  string getName() const;

  bool findBorrow(Movie *m,
                  Trans *tran); // looks for corresponding un-nullified borrow
  void addTrans(Trans *tran);   // adds transaction to transaction history
  void getHistory();

  Customer *nextCust();
  void setCust(Customer *newCust);

private:
  int customerId;
  string firstName, lastName;
  vector<Trans *> history;
  Customer *next;
};
#endif
