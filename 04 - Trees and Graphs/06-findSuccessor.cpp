#include <iostream>
#include <list>
using namespace std;

int Tree::findSmallest(Tree *root, int root_value){
  if(root == NULL)return root_value;
  int left_value = findSmallest(root->left, root_value);
  int right_value = findSmallest(root->right, root_value);
  return min(min(left_value, right_value), root->data);
}

int Tree::findSuccessor(Tree *node, int answer){

  if(node->right != NULL){
    return findSmallest(node->right, node->right == NULL ? node->data : node->right->data);
  }
  else{
    Tree *q = node;
    Tree *x = q->parent;
    while( x!= NULL && x->left != q){
      q = x;
      x = x->parent;
    }
    return x->data;
  }
}

int main() {
     
}


