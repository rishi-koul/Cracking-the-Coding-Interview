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
linkedList::Node *add(linkedList::Node *l1, linkedList::Node *l2, int carry){

  if(l1 == NULL && l2 == NULL && carry == 0){
    return NULL;
  }

  linkedList resultList;
  int value = carry;
  if(l1 != NULL) value += l1->data;
  if(l2 != NULL) value += l2->data;

  linkedList::Node *result = resultList.createNode(value % 10);
  
  if(l1 != NULL || l2 != NULL){
    linkedList::Node *more = add(l1 == NULL ? NULL : l1->next, l2 == NULL ? NULL :l2->next,  value >= 10 ? 1 : 0);
    result->next = more;
  }
  return result;
}


int main() {
  // Creating a linked list
  linkedList list;
  list.insertStart(1);
  list.insertStart(2);
  list.insertStart(8);

  list.display();

  cout<<endl;

  linkedList list2;
  list2.insertStart(8);
  list2.insertStart(7);
  list2.insertStart(5);

  list2.display();
  cout<<endl;
    
//  Note as I am adding nodes in the head and not the tail the additions are going to take place in reverse i.e. left to right
  linkedList l3;
  l3.head = add(list.head, list2.head, 0);
  l3.display();
  


}
