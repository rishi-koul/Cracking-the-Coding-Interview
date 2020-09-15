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

  // find smallest value in a tree
  int findSmallest(Tree *root, int root_value);
  // finds largest value in a tree
  int findLargest(Tree *root, int root_value);
  // checks if a tree is a BST or not
  bool checkBST(Tree *root);
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

int Tree::findSmallest(Tree *root, int root_value){
  if(root == NULL)return root_value;
  int left_value = findSmallest(root->left, root_value);
  int right_value = findSmallest(root->right, root_value);
  return min(min(left_value, right_value), root->data);
}

int Tree::findLargest(Tree *root, int root_value){
  if(root == NULL)return root_value;
  int left_value = findLargest(root->left, root_value);
  int right_value = findLargest(root->right, root_value);
  return max(max(left_value, right_value), root->data);
}

bool Tree::checkBST(Tree *root){

  if(root == NULL) return true;

  bool leftTree = checkBST(root->left);
  int largest = findLargest(root->left, root->left == NULL ? root->data : root->left->data);
  if(largest > root->data){
    cout<<"1.Nodes: "<<root->data<<endl;
    return false;
  }

  bool rightTree = checkBST(root->right);
  int smallest = findSmallest(root->right, root->right == NULL ? root->data : root->right->data);
  if(smallest <= root->data && root->right != NULL) {
    cout<<"2.Nodes: "<<root->data<<endl;
    cout<<"2.Smallest: "<<smallest<<endl;
    return false;
  }

  cout<<"3.Nodes: "<<root->data<<endl;
  return (leftTree && rightTree);
}

int main() {
     
//    Creating a tree
    Tree tree, *root = NULL;
    root = tree.insert(root, 50);
    root->left = new Tree(30);
    
     // comment or uncomment next two line to make it a BST or not make it a BST
    root->left->right = new Tree(33);
    root->left->right->left = new Tree(29);
    root = tree.insert(root, 35);
    root = tree.insert(root, 60);
    root = tree.insert(root, 55);
    root = tree.insert(root, 20);
    root = tree.insert(root, 10);
    root = tree.insert(root, 25);
    root = tree.insert(root, 80);
    root = tree.insert(root, 70);
    // comment or uncomment next line to make it a BST or not make it a BST
    root->right->right->left->right = new Tree(95);
    root = tree.insert(root, 90);
    root = tree.insert(root, 100);
    cout<<"My tree is :"<<endl;
    tree.preOrder(root);
    cout<<endl;
    
    bool i = tree.checkBST(root);
    i == 1 ? cout << "Is a BST"<< endl : cout << "Not a BST"<<endl;
}


