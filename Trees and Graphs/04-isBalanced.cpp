#include <iostream>
#include <list>
using namespace std;


class Tree{
  
    public:
    int data;
    Tree *left;
    Tree *right;
  
  Tree(); // Constructor

  Tree(int value);
  // Func to display the tree
  void preOrder(Tree* root);

  Tree *insert(Tree *root, int value);
    
//  Helper func to find height of a tree
  int getHeight(Tree *node, int height);

//  Main func to check if a tree is balanced or not
  bool isBalanced(Tree *node);
};

Tree::Tree(){
  right = NULL;
  left = NULL;
  data = 0;
}

// Parameterized Constructor definition.
Tree :: Tree(int value)
{
    data = value;
    left = right = NULL;
}


void Tree::preOrder(Tree *root){
  if(root == NULL)return;

  cout<<root->data<<" ";
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

//---------------------------------------------------------
// Actual Work

int Tree::getHeight(Tree *node, int height){
  if(node == NULL) return height;
  height++;

  return max(getHeight(node->left, height), getHeight(node->right, height));
}


bool Tree::isBalanced(Tree *node){
//    an empty is always balanced so return true
  if(node == NULL) return true;

//    iterate the entire tree
  bool left_side = isBalanced(node->left);
  bool right_side = isBalanced(node->right);

//    get the heights of sub tress using helper func
  int height_left = getHeight(node->left, 0);
  int height_right = getHeight(node->right, 0);
  int diff = height_left - height_right;
//    if these heights dont satisfy conditions of being balaced return false
  if(height_left != height_right && diff != 1 && diff != -1){
    return false;
  }
//    the subtree might be balaced but its subtrees might not be, so it this subtree is balaced return the result received from its subsequent subtrees
  else{
    return (left_side && right_side);
  }
}

int main() {
     
//    Creating a tree
//    for ease used a BST, will work for a normal binary tree too
    Tree tree, *root = NULL;
    root = tree.insert(root, 50);
    root = tree.insert(root, 30);
    root = tree.insert(root, 35);
    root = tree.insert(root, 60);
    root = tree.insert(root, 55);
    root = tree.insert(root, 20);
    root = tree.insert(root, 10);
    root = tree.insert(root, 25);
    root = tree.insert(root, 80);
    root = tree.insert(root, 70);
    root = tree.insert(root, 90);
    // root = tree.insert(root, 100);
    cout<<"My tree is :"<<endl;
    tree.preOrder(root);
    cout<<endl;
    
//    getting the result if balanced and printing it out
    bool i = tree.isBalanced(root);
    i == 1 ? cout<<"Balanced"<<endl : cout<<"Not Balanced"<<endl;
}

