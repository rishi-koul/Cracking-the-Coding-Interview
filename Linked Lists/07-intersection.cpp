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

linkedList::Node *intersectingNode(linkedList::Node *head1, linkedList::Node *head2){

  linkedList::Node *temp1 = head1;
  linkedList::Node *temp2 = head2;
  int len1, len2, diff;

  // Iterate to the end of linked lists and check if both have same tail(interesecting Linked lists must have same tail)
  // also find the length
  while(temp1->next != NULL){
    temp1 = temp1->next;
    len1++;
  }
  len1++;
  while(temp2->next != NULL){
    temp2 = temp2->next;
    len2++;
  }
  len2++;

  // if tails are not same not itersecting, else they will be interesecting
  if(temp1 != temp2) return NULL;

  temp1 = head1;
  temp2 = head2;

  // if len2 > len1
  if(len2 > len1){
    diff = len2 - len1;
    // iterate 'diff' times on list2
    while(diff != 0)
    {
      temp2 = temp2->next;
      diff--;
    }
  }
  // if len1 > len 2
  else if(len1 > len2){
    // iterate 'diff' times on list1
    diff = len1 - len2;
    while(diff != 0)
    {
      temp1 = temp1->next;
      diff--;
    }
  }

  // now as linked lists will be of same length
  // iterate simultaneouly on both and find the interesecting point
  while(temp1 != temp2){
    temp1 = temp1->next;
    temp2 = temp2->next;
  }

  // return the intersecting point
  return temp1;
}

int main() {
  // Creating a linked list
}
