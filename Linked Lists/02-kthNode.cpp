#include <iostream>
using namespace std;

class linkedList{

  private:

  // Define a node
  struct Node{
  int data;
  Node *next;
  };

  public:

  // Some basic implentation of Linked linkedList
  // Create new Node
  Node *head = NULL;
  Node *tail = NULL;

  Node* createNode(int value){
  Node *temp = new Node;
  temp->data = value;
  temp->next = NULL;

  if(head == NULL){
    head = temp;
    tail = temp;
    temp = NULL;
  }

  else{
    tail->next = temp;
    tail = temp;
  }
  return temp;
  };

  // Display a Linked List
  void display(){
    Node *temp = head;

    while(temp != NULL){
      cout<<temp->data<<" -> ";
      temp = temp->next;
    }
  }


  // Insert a node at start of Linked List
  void insertStart(int value){
    Node *temp = createNode(value);
    temp = head;
  }

  // Delete a Node
  void deleteNode(int value){

    Node *curr = head;
    Node *pre = new Node;

    while(curr->data != value){
      pre = curr;
      curr = curr->next;
    }

    if(curr == head){
      Node *temp = head;
      head = head->next;
      delete temp;
    }
    else if(curr->next == NULL){
      pre->next = NULL;
      delete curr;
    }
    else{
      pre->next = curr->next;
      delete curr;
    }
  }

  // ------------------------------------------------------
  // Actual Work

  Node *kthNode(Node *node, int k, int &i){
    if(node == NULL){
      return NULL;
    }

    Node *nd = kthNode(node->next, k, i);
    i = i + 1;
    if(i == k){
      return node;
    }
    return nd;
  }
    Node *kthNode(Node *node, int k){
    int i = 0;
    return kthNode(node, k, i);
  }

};


int main() {
  // Creating a linked list
  linkedList node;
  node.insertStart(1);
  node.insertStart(2);
  node.insertStart(3);
  node.insertStart(4);
  node.insertStart(5);
  node.insertStart(6);
  node.insertStart(7);
  node.insertStart(8);
  node.insertStart(9);
  node.display();
  cout<<endl;


  // Finding the kth Node
  cout<< node.kthNode(node.head, 4)->data;

}
