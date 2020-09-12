#include <iostream>
#include <stack>
using namespace std;


class Tree{
  
    public:
    int data;
    Tree *left;
    Tree *right;
    Tree *parent;
  
  Tree(); // Constructor

  Tree(int value);
  // Func to display the tree
  void preOrder(Tree* root);

  Tree *insert(Tree *root, int value);

  bool areIdentical(Tree* n1, Tree *n2);

  bool isSubtree(Tree *n1, Tree *n2);
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
    left = right  = NULL;
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

bool Tree::areIdentical(Tree* n1, Tree *n2){

  if(n1 == NULL && n2 == NULL) return true;
  else if(n1 == NULL || n2 == NULL) return false;
  else if(n1->data != n2->data)return false;

  else return areIdentical(n1->left, n2->left) && areIdentical(n1->right, n2->right);
}

bool Tree::isSubtree(Tree *n1, Tree *n2){
  if(n1 == NULL)return false;
  if(n2 == NULL)return true;
  bool i = isSubtree(n1->left, n2);
  bool j = isSubtree(n1->right, n2);
  
  if(n1->data == n2->data) return areIdentical(n1, n2);
  return (i || j);
}


int main() {
     
//    Manually creating a binary tree
    Tree tree, *root = NULL;
    root = tree.insert(root, 50);
    root->left = new Tree(30);
    root->left->right = new Tree(35);
    root->left->left = new Tree(20);
    root->left->left->left = new Tree(10);
    root->left->left->right = new Tree(25);
    root->right = new Tree(60);
    root->right->left = new Tree(55);
    root->right->right = new Tree(80);
    root->right->right->left = new Tree(70);
    root->right->right->right = new Tree(90);
    root->right->right->right->right = new Tree(100);

    Tree *root2 = NULL;
    root2 = new Tree(80);
    root2->left = new Tree(70);
    root2->right = new Tree(90);
    root2->right->right = new Tree(100);


    cout<<"My tree is :"<<endl;
    tree.preOrder(root);
    cout<<endl;

    cout<<tree.isSubtree(root, root2);
    
}




