#include "stack.h"
#include <cstddef>
#include <iostream>
#include <new>

using namespace std;

Stack::Stack() { structure = NULL; }

Stack::~Stack() {
  NodeType *tempPtr;
  while (structure != NULL) {
    tempPtr = structure;
    structure = structure->next;
    delete tempPtr;
  }
}

bool Stack::isEmpty() const { return (structure == NULL); }

bool Stack::isFull() const {
  NodeType *location;
  try {
    location = new NodeType;
    delete location;
    return false;
  } catch (std::bad_alloc exception) {
    return true;
  }
}

void Stack::push(ItemType item) {
  if (isFull()) {
    throw "A pilha está cheia.";
  } else {
    NodeType *location;
    location = new NodeType;
    location->info = item;
    location->next = structure;
    structure = location;
  }
}

ItemType Stack::pop() {
  if (isEmpty()) {
    throw "A pilha está vazia.";
  } else {
    NodeType *tempPtr;
    tempPtr = structure;
    ItemType item = structure->info;
    structure = structure->next;
    delete tempPtr;
    return item;
  }
}

void Stack::print() const {
  NodeType *tempPtr = structure;
  while (tempPtr != NULL) {
    cout << tempPtr->info;
    tempPtr = tempPtr->next;
  }
  cout << endl;
}