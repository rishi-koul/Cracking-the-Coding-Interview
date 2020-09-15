#include <iostream>
using namespace std;

class linkedList{

  public:
  // Define a node
  struct Node{
  int data;
  Node *next;
  };

  // Some basic implentation of Linked linkedList
  // Create new Node
  Node *head = NULL;

  Node* createNode(int value){
  Node *temp = new Node;
  temp->data = value;
  temp->next = NULL;

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
    if(head == NULL){
      head = temp;
    }
    else{
      temp->next = head;
      head = temp;
    }
    
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

};

// -----------------------------------------------
// Main function

linkedList::Node *findStart(linkedList::Node *head){
  linkedList::Node *slow;
  linkedList::Node *fast;

  while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast){
      break;
    }
  }

  if(fast == NULL || fast->next ==NULL){
    return NULL;
  }
  else{
    slow = head;
    while(slow != fast){
      slow= slow->next;
      fast = fast->next;
    }

    return fast;
  }
}

int main() {
  // Creating a linked list
}
