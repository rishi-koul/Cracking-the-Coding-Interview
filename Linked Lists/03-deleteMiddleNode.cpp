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

  Node *findNode(int value){
    Node *temp = head;
    while(temp != NULL && temp->data != value ){
      // if(temp->data == value){
      //   return temp;
      // }
      temp = temp->next;
    }
    if(temp != NULL) return temp;
    else return NULL;
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
  // Given: You do not have access to the head pointer

  void deleteMiddleNode(Node *node){
    // Copy the content of next node in curent code
    node->data = node->next->data;
    // Delete the next node instead
    Node *curr = node->next;
    node->next = curr->next;
    delete curr;
  }

};


int main() {
  // Creating a linked list
  linkedList list;
  list.insertStart(1);
  list.insertStart(2);
  list.insertStart(3);
  list.insertStart(4);
  list.insertStart(5);
  list.insertStart(6);
  list.insertStart(7);
  list.insertStart(8);
  list.insertStart(9);
  list.display();
  cout<<endl;

  //  Delete the node without information of head
  list.deleteMiddleNode(list.findNode(6));
  list.display();
  


}
