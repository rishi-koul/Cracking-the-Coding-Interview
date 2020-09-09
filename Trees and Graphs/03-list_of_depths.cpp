#include <iostream>
#include <list>
#include <vector>
using namespace std;

// Making a linked list acc to the ques
class LinkedList{
  public:
  int data;
  LinkedList *next;

  
    LinkedList();

  // create nodes
  LinkedList(int value);

  // print linked list
  void print(LinkedList *head);

  // create and insert
  LinkedList * insert(LinkedList *head, int value);
};

LinkedList::LinkedList(){
  data = 0;
  next = NULL;
}

void LinkedList::print(LinkedList *head){
  LinkedList *temp = new LinkedList();
  temp = head;
  while(temp != NULL)
  {
    cout<<temp->data<<"->";
    temp = temp->next;
  }
  cout<<endl;
}

LinkedList *LinkedList::insert(LinkedList *head, int value){
  LinkedList *temp = new LinkedList();
  if(head == NULL){
    temp->data = value;
    temp->next = NULL;
    return temp;
  }
  temp->data = value;
  temp->next = head;
  // head->next = temp;
  head = temp;
  return head;
}

// Making a Tree
class Tree{
  public:
    int data;
    Tree *left;
    Tree *right;
  
  
  Tree(); // Constructor

  Tree(int value);
  // Func to display the tree
  void preOrder(Tree* root, int depth);

  // Func to insert nodes in tree
  Tree* insert(Tree *root, int value);

  // Creates a linked lists contaning all nodes at each lvl of a BST
  list<LinkedList *> list_of_depths(Tree* root);

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


void Tree::preOrder(Tree *root, int depth){
  if(root == NULL)return;

  depth++;
  preOrder(root->left, depth);
  cout<<root->data<<", at depth: "<<depth<< endl;
  preOrder(root->right, depth);
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
// Actual Work

// Func returning a list of linked list each containing all nodes at each lvl of a binary tree

list<LinkedList *> Tree::list_of_depths(Tree* root)
{
    vector<list<Tree*>> result;
    list<Tree*> current_depth;

    if (root != NULL)
        current_depth.push_back(root);

    while (!current_depth.empty())
    {
        list<Tree*> next_depth;
        for (Tree* node : current_depth)
        {
            if (node->left != NULL)
                next_depth.push_back(node->left);
            if (node->right != NULL)
                next_depth.push_back(node->right);
        }
        result.push_back(current_depth);
        current_depth = next_depth;
    }

  list<LinkedList *> ll_list;

  for (size_t i = 0; i < result.size(); ++i) {
      LinkedList l, *head = NULL;
      list<Tree *>::iterator it;
    for (it = result[i].begin(); it != result[i].end(); ++it){
      head = l.insert(head, (*it)->data);
    }
    ll_list.push_back(head);
    }
    return ll_list;
}

int main() {
     
   // Create a tree
    Tree tree, *root = NULL;

    root = tree.insert(root, 50);
    root = tree.insert(root, 30);
    root = tree.insert(root, 60);
    root = tree.insert(root, 20);
    root = tree.insert(root, 25);
    root = tree.insert(root, 10);
    root = tree.insert(root, 80);
    root = tree.insert(root, 70);
    root = tree.insert(root, 90);
    root = tree.insert(root, 100);

    cout<<"The tree is"<<endl;
    tree.preOrder(root, -1);

    cout<<endl;
    LinkedList l;
    list<LinkedList *> v;
    // Getting the list of linked list
    v = tree.list_of_depths(root);

    // printing the result
    list<LinkedList *>::iterator it;
    for (it = v.begin(); it != v.end(); ++it){
      l.print(*it);
    }
}



