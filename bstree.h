#ifndef BSTREE_H
#define BSTREE_H
#include "movie.h"
#include <iostream>
#include <vector>

using namespace std;

class BSTree {

  friend ostream &operator<<(ostream &, const BSTree &);

public:
  BSTree();             // constructor
  ~BSTree();            // destructor, calls makeEmpty
  bool isEmpty() const; // true if tree is empty, otherwise false
  void makeEmpty();     // make the tree empty so isEmpty returns true
  bool insert(Movie *); // insert movie into the appropriate
                        // BSTree based on category
  bool retrieve(Movie *, Movie *&found) const;

private:
  struct Node {
    Movie *data; // pointer to data object
    Node *left;  // left subtree pointer
    Node *right; // right subtree pointer
  };
  Node *root;
  void makeEmptyRecursive(Node *&); // recursive function for makeEmpty
  bool insertRecursive(Node *&,
                       Movie *); // recursive function for insert
  void displayRec(ostream &out, Node *curr) const;
  void traverseInOrder(Node *node, vector<Movie *> &movies);
};

#endif
