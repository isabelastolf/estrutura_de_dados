#include "queue.h"
#include <iostream>

using namespace std;

Queue::Queue() {
  front = 0;
  back = 0;
  structure = new ItemType[MAX_ITEMS];
}

Queue::~Queue() { delete[] structure; }

bool Queue::isEmpty() const { return (front == back); }

bool Queue::isFull() const { return (back - front == MAX_ITEMS); }

void Queue::enqueue(ItemType item) {
  if (isFull()) {
    throw "Fila cheia!";
  } else {
    structure[back % MAX_ITEMS] = item;
    back++;
  }
}

ItemType Queue::dequeue() {
  if (isEmpty()) {
    throw "Fila vazia!";
  } else {
    front++;
    return structure[(front - 1) % MAX_ITEMS];
  }
}

void Queue::print() const {
  cout << "Fila = ";
  for (int i = front; i < back; i++) {
    cout << structure[i % MAX_ITEMS];
  }
  cout << endl;
}
