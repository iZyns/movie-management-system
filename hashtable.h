#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "customer.h"
#include <iostream>
#include <string>

using namespace std;

class HashTable {
public:
  // constructor
  HashTable();
  // destructor
  ~HashTable();

  // generates the key using a simple %7
  int keyGen(int custId);
  // insert function to insert the customer to the table
  void insert(Customer *cust);
  // search function to search for a customer, returns true if found
  bool retrieve(int custId, Customer *&output);
  // remove function to remove customer from the table
  bool remove(int custId, Customer *&output);

private:
  // a searching function used by remove and retrieve
  bool find(int custId, Customer *&output, Customer *&prev);

  // OLD VERSION:
  // HashNode* dataCust[SIZE];

  // NEW:
  Customer *dataCust[11];
};
#endif