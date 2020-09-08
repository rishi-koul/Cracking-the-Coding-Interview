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

// Function to reverse the list and copy it to a new list
linkedList::Node *reverseAndClone(linkedList::Node *head){
  linkedList::Node *temp = head;
  linkedList list2;
  while(temp != NULL){
    list2.insertStart(temp->data);
    temp = temp->next;
  }
  return list2.head;
}

// check if each element of list 1 is equal to respective element in list2
bool isEqual(linkedList::Node *head1,linkedList::Node *head2){
  linkedList::Node *temp1 = head1;
  linkedList::Node *temp2 = head2;

  while(temp1 != NULL && temp2!= NULL){
    if (temp1->data != temp2->data){
      return false;
    }
    temp1 = temp1->next;
    temp2 = temp2->next;
  }
  return temp1 == NULL && temp2 == NULL;
}

// first reverse the list and check if both are equal
bool isPalindrome(linkedList::Node *temp){
  linkedList reversed;
  reversed.head = reverseAndClone(temp);
  return isEqual(temp, reversed.head);
}


int main() {
  // Creating a linked list
  linkedList list;
  list.insertStart(1);
  list.insertStart(2);
  list.insertStart(1);

  // cout<<list.head->data;
  list.display();
  cout<<endl;
  
  if(isPalindrome(list.head)){
    cout<<"Is Palindrome";
  }
  else{
    cout<<"Isn't Palindrome";
  }


}
