#include <iostream>
#include "address.h"

using namespace std;

class Node
{
   public:
   Address address;
   Node *Left;
   Node *Right;
};

class BST
{
public:

   BST();
   ~BST();

   void Insert(Address place);
   bool Search(Address &result, string key);
   void Print();

private:
   void insertHelper(Address place, Node * &tree);
   bool searchHelper(Address &result, string key, Node * tree);
   void printHelper(Node * Tree);

   int Size;
   Node * Root;

};