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
    
  //  Helper func to find parent of a node
  Tree* findParent(Tree *root, Tree *node);

  // find depth of a node
  int getDepth(Tree *node);

  // find the common ancestor of two nodes
  Tree *commonAncestor(Tree *node, Tree*node2);

};

Tree::Tree(){
  right = NULL;
  left = NULL;
  parent = NULL;
  data = 0;
}

// Parameterized Constructor definition.
Tree :: Tree(int value)
{
    data = value;
    left = right = parent  = NULL;
}

Tree* Tree::findParent(Tree *root, Tree *node){
  
  stack<Tree *> s;
    Tree *curr = root;
  
    while (curr != NULL || s.empty() == false)
    {
        while (curr !=  NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
  
        curr = s.top();
        s.pop();
  
        if(curr->left != NULL && curr->left->data == node->data){
          return curr;
        }
        if(curr->right != NULL && curr->right->data == node->data){
          return curr;
        }
        curr = curr->right;
  
    }
    return curr;
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
// Assumption:Dont have access to root node, but each node has info to its parent
int Tree::getDepth(Tree *node){
  int height = 0;

  while(node != NULL){
    height++;
    node = node->parent;
  }
  return height;
}

Tree *Tree::commonAncestor(Tree *node1, Tree*node2){
  int diff = getDepth(node1) - getDepth(node2);

  Tree* higherNode = (diff > 0) ? node2 : node1;
  Tree* lowerNode = (diff > 0) ? node1 : node2;

  while(diff != 0){
    lowerNode = lowerNode->parent;
    diff--;
  }

  while(lowerNode != higherNode && higherNode != NULL && lowerNode != NULL){
    lowerNode = lowerNode->parent;
    higherNode = higherNode->parent;
  }
  return higherNode == NULL || lowerNode == NULL ? NULL: higherNode;
}


int main() {
     
//    Manually creating a binary tree
    Tree tree, *root = NULL;
    root = tree.insert(root, 50);
    root->parent = NULL;
    root->left = new Tree(30);
    root->left->parent = tree.findParent(root, root->left);

    root->left->right = new Tree(35);
    root->left->right->parent = tree.findParent(root, root->left->right);

    root->left->left = new Tree(20);
    root->left->left->parent = tree.findParent(root, root->left->left);

    root->left->left->left = new Tree(10);
    root->left->left->left->parent = tree.findParent(root, root->left->left->left);

    root->left->left->right = new Tree(25);
    root->left->left->right->parent = tree.findParent(root, root->left->left->right);

    root->right = new Tree(60);
    root->right->parent = tree.findParent(root, root->right);

    root->right->left = new Tree(55);
    root->right->left->parent = tree.findParent(root, root->right->left);

    root->right->right = new Tree(80);
    root->right->right->parent = tree.findParent(root, root->right->right);

    root->right->right->left = new Tree(70);
    root->right->right->left->parent = tree.findParent(root, root->right->right->left);

    root->right->right->right = new Tree(90);
    root->right->right->right->parent = tree.findParent(root, root->right->right->right);

    root->right->right->right->right = new Tree(100);
    root->right->right->right->right->parent = tree.findParent(root, root->right->right->right->right);

    cout<<"My tree is :"<<endl;
    tree.preOrder(root);
    cout<<endl;

    int i = tree.commonAncestor(root->left->left->right, root->right->right->left)->data;
    cout<<"Common ancestor is: "<<i<<endl;
    
}



