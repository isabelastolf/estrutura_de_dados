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

  void pop() {
    if (length == 0)
      return;
    Node *temp = head;
    if (length == 1) {
      head = nullptr;
      tail == nullptr;
    } else {
      Node *pre = head;
      while (temp->next != nullptr) {
        pre = temp;
        temp = temp->next;
      }
      tail = pre;
      tail->next = nullptr;
    }
    delete temp;
    length--;
  }

  void prepend(int value) {
    Node *newNode = new Node(value);
    if (length == 0) {
      head = newNode;
      tail = newNode;
    } else {
      newNode->next = head;
      head = newNode;
    }
    length++;
  }

  void deleteFirst() {
    if (head == nullptr) {
      return;
    }

    Node *temp = head;
    if (length == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      head = head->next;
    }
    delete temp;
    length--;
  }

  Node *get(int index) {
    if (index < 0 || index >= length) {
      return nullptr;
    }
    Node *temp = head;
    for (int i = 0; i < index; i++) {
      temp = temp->next;
    }
    return temp;
  }

  bool set(int index, int value) {
    Node *temp = get(index);
    if (temp) {
      temp->value = value;
      return true;
    }
    return false;
  }

  bool insert(int index, int value) {
    if (index < 0 || index > length) {
      return false;
    }
    if (index == 0) {
      prepend(value);
      return true;
    }
    if (index == length) {
      append(value);
      return true;
    }
    Node *newNode = new Node(value);
    Node *temp = get(index - 1);
    newNode->next = temp->next;
    temp->next = newNode;
    length++;
    return true;
  }

  void deleteNode(int index) {
    if (index < 0 || index >= length)
      return;
    if (index == 0)
      return deleteFirst();
    if (index == length - 1)
      return pop();

    Node *prev = get(index - 1);
    Node *temp = prev->next;
    prev->next = temp->next;
    delete temp;
    length--;
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
};

int main() {
  LinkedList *myLinkedList = new LinkedList(1);
  myLinkedList->append(2);
  myLinkedList->append(3);
  myLinkedList->append(4);
  myLinkedList->append(5);
  myLinkedList->append(6);

  cout << "---- Current List ----" << endl;
  myLinkedList->printList();

  // cout << "---- Delete First ----" << endl;
  // myLinkedList->deleteFirst();

  // cout << "---- Pop ----" << endl;
  // myLinkedList->pop();

  // cout << "---- Prepend ----" << endl;
  // myLinkedList->prepend(6);

  // cout << "---- Get index 3 ----" << endl;
  // myLinkedList->get(3);

  cout << "---- Delete Node 2 ----" << endl;
  myLinkedList->deleteNode(2);
  cout << "---- Current List ----" << endl;
  myLinkedList->printList();

  cout << "---- Delete Node 0 ----" << endl;
  myLinkedList->deleteNode(0);
  cout << "---- Current List ----" << endl;
  myLinkedList->printList();

  cout << "---- Delete Node 3 ----" << endl;
  myLinkedList->deleteNode(3);
  cout << "---- Current List ----" << endl;
  myLinkedList->printList();

  // cout << "---- Set on index 1 an element equals to 8 ----" << endl;
  // myLinkedList->set(1, 8);

  // cout << "---- Insert on index 1 an element that equals to 5 ----" << endl;
  // myLinkedList->insert(1, 5);

  // cout << "---- Current List ----" << endl;
  // myLinkedList->printList();
}