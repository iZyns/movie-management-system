#ifndef TRANFACTORY_H
#define TRANFACTORY_H
#include "borrow.h"
#include "return.h"
#include "trans.h"

class TranFactory {
public:
  TranFactory();
  ~TranFactory();

  Trans *factoryForTransactions(char action, stringstream &ss);
  Trans *readBorrow(char mediaType, char movieType, int custId, stringstream &ss);
  Trans *readReturn(char mediaType, char movieType, int custId, stringstream &ss);
};
#endif