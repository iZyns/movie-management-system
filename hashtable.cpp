#include "hashtable.h"

/*
This is the hashtable class that stores the customers information.
*/

// constructor and destructors
HashTable::HashTable() {
  for (int i = 0; i < 11; i++) {
    dataCust[i] = nullptr;
  }
}

HashTable::~HashTable() {
  for (int i = 0; i < 11; i++) {

    Customer *cust = dataCust[i];
    for (;;) {
      if (cust == nullptr) {
        break;
      }
      Customer *temp = cust;
      cust = cust->nextCust();
      delete temp;
    }
    dataCust[i] = nullptr;
  }
  delete *dataCust;
}

// generates the key using a simple %11
// IF WE NEED TO CHANGE THE KEY, CHANGE HERE
int HashTable::keyGen(int custId) { return custId % 11; }

// insert function to insert a new customer to the table
void HashTable::insert(Customer *cust) {
  int key = keyGen(cust->getId());
  if (dataCust[key] == nullptr) {
    dataCust[key] = cust;
    return;
  }

  Customer *placer = dataCust[key];
  for (;;) {
    if (placer->nextCust() != nullptr) {
      placer = placer->nextCust();
    } else {
      placer->setCust(cust);
      break;
    }
  }
}

// retrieve function to retrieve a customer from the table.
bool HashTable::retrieve(int custId, Customer *&output) {
  Customer *throwAway; // Will be deleted as part of this function scope
  bool fin = find(custId, output, throwAway);
  return fin;
}

// remove function to remove a customer from the table
bool HashTable::remove(int custId, Customer *&output) {
  Customer *previous; // Will be deleted as part of this function scope
  bool fin = find(custId, output, previous);
  if (previous != nullptr && fin) {
    previous->setCust(output->nextCust());
    output->setCust(nullptr);
  } else if (fin) {
    // This covers cases where the first node on the shelf is the node being
    // removed which would make previous nullptr
    int key = keyGen(custId);
    dataCust[key] = output->nextCust();
    output->setCust(nullptr);
  }
  return fin;
}

// Searching function that finds the desired Customer object by Id
bool HashTable::find(int custId, Customer *&output, Customer *&prev) {
  int key = keyGen(custId);
  Customer *placer = dataCust[key];
  for (;;) {
    if (placer == nullptr) {
      return false;
    } else if (placer->getId() == custId) {
      output = placer;
      return true;
    } else {
      prev = placer;
      placer = placer->nextCust();
    }
  }
}
