#include "bstree.h"

/*
This is the Binary Seach Tree class that handles the storing system for the
different types of movie.
*/

// output operator
ostream &operator<<(ostream &out, const BSTree &tree) {
  if (tree.root == nullptr) {
    return out;
  }
  tree.displayRec(out, tree.root);
  out << endl;
  return out;
}
// recursive helper function for output operator
void BSTree::displayRec(ostream &out, Node *curr) const {
  if (curr == nullptr) {
    return;
  } else {
    displayRec(out, curr->left);
    out << *curr->data << " ";
    displayRec(out, curr->right);
  }
}

// constructor and destructor
BSTree::BSTree() { this->root = NULL; }

BSTree::~BSTree() {
  this->root = NULL;
  this->makeEmpty();
}

// check if the tree is empty
bool BSTree::isEmpty() const { return this->root == NULL; }

// delete all the object inside the tree
void BSTree::makeEmpty() {
  makeEmptyRecursive(this->root);
  this->root = NULL;
}

// recursive helper function for makeEmpty
void BSTree::makeEmptyRecursive(Node *&curr) {
  if (curr == NULL) {
    return;
  } else {
    makeEmptyRecursive(curr->left);
    makeEmptyRecursive(curr->right);
  }
  if (curr->data != NULL) {
    delete curr->data;
    curr->data = NULL;
  }
  delete curr;
  curr = NULL;
}

// insert function for inserting to the tree
bool BSTree::insert(Movie *movie) { return insertRecursive(this->root, movie); }

// recursive helper function for insert
bool BSTree::insertRecursive(Node *&curr, Movie *movie) {
  if (curr == NULL) {
    curr = new Node;
    curr->data = movie;
    curr->right = NULL;
    curr->left = NULL;
  } else if (*movie < *curr->data) {
    insertRecursive(curr->left, movie);
  } else if (*movie > *curr->data) {
    insertRecursive(curr->right, movie);
  } else if (*movie == *curr->data) {
    return false;
  } else {
    return false;
  }
  return true;
}

// retrieve function to retrieve a movie from the tree
bool BSTree::retrieve(Movie *movie, Movie *&found) const {
  Node *current = root;
  found = nullptr;
  while (current != nullptr) {
    if (*current->data == *movie) {
      found = current->data;
      return true;
    } else if (*movie < *current->data) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return false;
}
