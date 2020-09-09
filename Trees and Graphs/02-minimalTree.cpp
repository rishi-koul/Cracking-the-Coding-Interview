#include <iostream>
#include <list>
using namespace std;


class Tree{
  
    int data;
    Tree *left;
    Tree *right;
  
  public:
  Tree(); // Constructor

  Tree(int value);
  // Func to display the tree
  void preOrder(Tree* root);

  // Func to create minimal BST from an array in asceding order
  Tree* createMinimalBST(int arr[], int start, int end);
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

Tree *Tree::createMinimalBST(int arr[], int start, int end){

  if(end < start)
    return NULL;

  // find mid of the array
  int mid = (start+end) / 2;

  // create a node with value equal to middle value of aray
  Tree *tree = new Tree(arr[mid]);
  // the array on left of mid [0:mid-1] goes to left of tree
  tree->left = createMinimalBST(arr, start, mid-1);
  // the array on right of mid [mid+1:end] goes to right of tree
  tree->right = createMinimalBST(arr, mid+1, end);
  return tree;
}

int main() {
     
    int arr[] = {2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    Tree tree, *root = NULL;

    cout<<endl;
    // as in c++ there is no way to find size of int array in another func thus it is imp to pass size here
    int size = sizeof(arr)/sizeof(arr[0]) - 1;
    root = tree.createMinimalBST(arr, 0, size);

    cout<<"The tree is"<<endl;
    tree.preOrder(root);
}
