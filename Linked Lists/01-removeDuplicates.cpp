//Task: Solve the question without using temporary buffers

#include <iostream>
using namespace std;

class linkedList{

  private:

  // Define a node
  struct Node{
  int data;
  Node *next;
  };
  Node *head = NULL;
  Node *tail = NULL;

  public:

  // Some basic implentation of Linked linkedList
  // Create new Node
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

  // --------------------------------------------------------------------------------
    
  // Actual Work
  void removeAllDuplicates(){
    Node *curr = head;

    // Iterate over the Linked List
    while(curr != NULL){
      Node *inner_curr = curr->next;
      Node *inner_pre = curr;

      // Iterate over the Linked List starting after the curr node
      while(inner_curr != NULL){
        // If a node with same value as curr node is found, delete
        if(inner_curr->data == curr->data){
          Node *temp = inner_curr;
          inner_curr = inner_curr->next;
          inner_pre->next = temp->next;
          delete temp;
        }
        // Else keep iterating
       else{
          inner_pre = inner_curr;
          inner_curr = inner_curr->next;
        }
      }
      curr = curr->next;
    }
  }

};


int main() {
  // Creating a linked list
  linkedList node;
  node.insertStart(5);
  node.insertStart(6);
  node.insertStart(5);
  node.insertStart(8);
  node.insertStart(5);
  node.insertStart(5);
  node.insertStart(8);
  node.insertStart(10);
  node.insertStart(13);
  node.insertStart(15);
  node.insertStart(7);
  node.insertStart(6);
  node.insertStart(12);
  node.display();
  cout<<endl;

  // Removing all duplicates
  node.removeAllDuplicates();
  node.display();
}
