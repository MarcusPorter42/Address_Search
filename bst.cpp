#include "bst.h"

//-----------------------------------------------------------
// Constructor
//-----------------------------------------------------------
BST::BST()
{
   Root = NULL;
   Size = 33129;
}


//-----------------------------------------------------------
// Destructor
//-----------------------------------------------------------
BST::~BST()
{
}

//-----------------------------------------------------------
// Insert method
//-----------------------------------------------------------
void BST::Insert(Address place)
{
   return (insertHelper(place, Root));
}

void BST::insertHelper(Address place, Node * &tree)
{
   if (tree == NULL)
   {
      tree = new Node;
      tree->address = place;
      tree->Left = NULL;
      tree->Right = NULL;
      return;
   }

   Address compare;
   int x = compare.compareKey(tree->address.getKey(), place.getKey());

   // Data address already inserted
   if (x == 0)
      return;     

   // Recursively search for insertion position
   else if (x == 1)
      return (insertHelper(place, tree->Left));
   else if (x == -1)
      return (insertHelper(place, tree->Right));
}

//-----------------------------------------------------------
// Search method
//-----------------------------------------------------------
bool BST::Search(Address &result, string key)
{
   return (searchHelper(result, key, Root));
}

bool BST::searchHelper(Address &result, string key, Node * tree)
{
   Address compare;
   int x = compare.compareKey(tree->address.getKey(), key);

   // Data address not found 
   if (tree == NULL)
      return false;

   // Data address found 
   else if (x == 0)
   {
      result = Address(tree->address);
      return true;
   }

   // Recursively search for data address
   else if (x == 1)
      return (searchHelper(result, key, tree->Left));
   else if (x == -1)
      return (searchHelper(result, key, tree->Right));
}

//-----------------------------------------------------------
// Print function for debugging
//-----------------------------------------------------------
void BST::Print()
{
   printHelper(Root);
   cout << endl;
   //cout << total;
}

void BST::printHelper(Node * tree)
{
   if (tree != NULL)
   {
      // Print left subtree
      printHelper(tree->Left);

      // Print node value
      tree->address.print();
      cout << endl;

      // Print right subtree
      printHelper(tree->Right);
   }
}