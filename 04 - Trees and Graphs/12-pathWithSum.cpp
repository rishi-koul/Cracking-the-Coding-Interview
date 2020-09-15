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

    Tree(); // Constructor
    Tree(int value);
    // Func to display the tree
    void preOrder(Tree* root);

    // Func to insert nodes in tree
    Tree* insert(Tree *root, int value);

    int countPathsFromOneNode(Tree *node, int target, int sum);

    int countPathFromAllNodes(Tree *root, int target);
};

Tree::Tree(){
  right = NULL;
  left = NULL;
  data = 0;
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

  if(root == NULL){
    Tree *temp = new Tree();
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
  }

  if(value <= root->data)
    root->left = insert(root->left, value);
  else
    root->right = insert(root->right, value);
  return root;
}

// ---------------------------------------------------------
int Tree::countPathFromAllNodes(Tree *root, int target){
  if(root == NULL)return 0;

  int totalPaths = countPathsFromOneNode(root, target, 0);

  int leftPath = countPathFromAllNodes(root->left, target);
  int rightPath = countPathFromAllNodes(root->right, target);

  return (totalPaths + leftPath + rightPath);
}


int Tree::countPathsFromOneNode(Tree *node, int target, int sum){
  if(node == NULL)return 0;

  sum = sum + node->data;
  int totalPaths = 0;
  if(sum == target){
    totalPaths++;
  }
  totalPaths += countPathsFromOneNode(node->left, target, sum);
  totalPaths += countPathsFromOneNode(node->right, target, sum);
  return totalPaths;
}

int main() {
     
   // Create a tree
    Tree tree, *root = NULL;

    root = tree.insert(root, 10);
    root->right = new Tree(-3);
    root->right->right = new Tree(11);
    root->left = new Tree(5);
    root->left->right = new Tree(2);
    root->left->right->right = new Tree(1);
    root->left->left = new Tree(3);
    root->left->left->right = new Tree(-2);
    root->left->left->left = new Tree(3);
    
    cout<<"The tree is"<<endl;
    tree.preOrder(root);
    cout<<endl;

    cout<<"Ans is : "<<tree.countPathFromAllNodes(root, 8);
}




