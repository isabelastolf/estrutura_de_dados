#include "itemType.h"

const int MAX_ITEMS = 100;

class Stack {
public:
  Stack();  // construtor
  ~Stack(); // destrutor

  bool isEmpty() const;
  bool isFull() const;
  void print() const;

  void push(ItemType);
  ItemType pop();

private:
  int length;
  ItemType *structure;
};