#include <iostream>
#include <string>

using namespace std;

class Node {
public:
  int value;
  Node *next;

  Node(int value) {
    this->value = value;
    next = nullptr;
  }
  // at some point:
  // setValue(int value)
  // setNext(int value)
  // getValue(int value)
  // getNext(int value)
};

class LinkedList {
private:
  Node *head;
  Node *tail;
  int length;

public:
  LinkedList(int value) { // Constructor
    Node *newNode = new Node(value);
    // create a shiny first node. variable that can point to a node
    // = new keyword witch will run the constructor to know a node
    head = newNode; // points the head to the node newNode
    tail = newNode;
    // points tail to the node newNode bcuz we only have
    // this one node in the list.
    length = 1;
  }

  ~LinkedList() {
    Node *temp = head;
    while (head) {
      head = head->next;
      delete temp;
      temp = head;
    }
  }

  void append(int value) {
    // create new node
    // add node to the end
    Node *newNode = new Node(value);
    if (length == 0) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    length++;
  }

  void printList() {
    Node *temp = head;
    while (temp != nullptr) {
      cout << temp->value << endl;
      temp = temp->next;
    }
  }

  void getHead() { cout << "Head: " << head->value << endl; }

  void getTail() { cout << "Tail: " << tail->value << endl; }

  void getLength() { cout << "Length: " << length << endl; }

  // void prepend(int value) { ... }
  // create new node
  // add node to the beggining

  // bool insert(int index, int value) { ... }
  // create new node
  // insert node
};

int main() {

  LinkedList *myLinkedList = new LinkedList(4);

  myLinkedList->getHead();
  cout << "----" << endl;
  for (int i = 0; i < 9; i++) {
    myLinkedList->getLength();

    myLinkedList->append(i);
    cout << "----" << endl;
  }
  myLinkedList->printList();
  cout << "----" << endl;
  myLinkedList->getTail();
}