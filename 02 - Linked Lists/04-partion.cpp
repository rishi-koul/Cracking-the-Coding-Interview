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

  // ------------------------------------------------------
  // Actual Work

  void partition(int value){
    // Iterate over the list
    int length = 0;
    Node *tail = head;
    while(tail->next != NULL){
      length++;
      tail = tail->next;
    }

    Node *temp = head;
    Node *pre = NULL;
    while(length != 0){
      // If temp->data < value do nothing
      if(temp->data < value){
      pre = temp;
      temp = temp->next;
      length--;
      }
      // Else store the data of node, delete it and insert at the end of the list
      else{
        int var = temp->data;
        Node *newNode = createNode(var);
        tail->next = newNode;
        tail = tail->next;

        Node *curr = temp;
        temp = temp->next;
        if(curr == head){
          head = temp;
          delete curr;
        }
        else if(curr->next == NULL){
          pre->next = NULL;
          delete curr;
        }
        else{
         pre->next = temp;
         delete curr;
        }
        length--;
      }
    }

  }
};


int main() {
  // Creating a linked list
  linkedList list;
  list.insertStart(3);
  list.insertStart(5);
  list.insertStart(8);
  list.insertStart(5);
  list.insertStart(10);
  list.insertStart(2);
  list.insertStart(1);
  list.display();
  cout<<endl;
  
  // Creating a partition
  list.partition(5);
  list.display();
  


}
