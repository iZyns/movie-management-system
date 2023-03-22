#include "business.h"
#include <iostream>
using namespace std;

/*
This is the main class where it creates the new business and loads in the file
*/

int main() {
  Business business;
  business.buildMovie("data4movies.txt");
  business.buildCustomer("data4customers.txt");
  business.processTrans("data4commands.txt");
  return 0;
}