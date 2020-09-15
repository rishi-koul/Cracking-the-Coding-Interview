#include <iostream>
#include <list>
#include <vector>
using namespace std;

// Making a Tree
class Tree{


    public:

      int data;
      Tree *left;
      Tree* right;
       int size;

    Tree(); // Constructor
    Tree(int value);
    // Func to display the tree
    void preOrder(Tree* root);

    // Func to insert nodes in tree, IMP: modified for this ques, to keep a record of size of each subtree in the root of that subtree
    Tree* insert(Tree *root, int value);

    // Func to return random nodes in the tree
    Tree* returnRandom(Tree *root);
};

Tree::Tree(){
  right = NULL;
  left = NULL;
  data = 0;
  size = 1;
}

Tree :: Tree(int value)
{
    data = value;
    left = right = NULL;
}


void Tree::preOrder(Tree *root){
  if(root == NULL)return;

  cout<<root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

Tree *Tree::insert(Tree *root, int value){
  if(root != NULL) root->size = 1 + root->size;

  if(root == NULL){
    Tree *temp = new Tree();
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    temp->size = 1;
    return temp;
  }

  if(value <= root->data)
    root->left = insert(root->left, value);
  else
    root->right = insert(root->right, value);
  return root;
}

// ---------------------------------------------------------


Tree *Tree::returnRandom(Tree *root){

  // Now as each node has information of no.of nodes it has(thanks to modified insert). Lets use this
  srand((unsigned) time(0));
  // we will generate a no with prob 1/N
  int result = 1 + (rand() % (root->size));
  // check no.of nodes in left leftSide
  // return a random number with prob 1/N' (size of left side)
  // we do this step to ensure that if left side has greater np.of nodes than right side there is a higher chance that the tree goes to left
  // doing a 50-50 would not be fair, as then each node will not have prob of 1/N
  int leftSide = (root->left == NULL) ? 0 : (1 + (rand() % (root->left->size)));

  if(result == leftSide + 1){
    return root;
  }
  else if(result > leftSide){
    return returnRandom(root->right);
  }
  else{
    return returnRandom(root->left);
  }
}

int main() {
     
   // Create a tree
    Tree tree, *root = NULL;

    root = tree.insert(root, 50);
    root = tree.insert(root, 30);
    root = tree.insert(root, 35);
    root = tree.insert(root, 60);
    root = tree.insert(root, 20);
    root = tree.insert(root, 25);
    root = tree.insert(root, 10);
    root = tree.insert(root, 80);
    root = tree.insert(root, 70);
    root = tree.insert(root, 90);
    root = tree.insert(root, 100);

    cout<<"The tree is"<<endl;
    tree.preOrder(root);
    cout<<endl;

    // Get a random node
    int i = tree.returnRandom(root)->data;
    cout<<"Random Node value is : "<<i<<endl;
}




