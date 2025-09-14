#include "stack.h"
#include <cstddef>
#include <iostream>

using namespace std;

int main() {
  ItemType character;
  ItemType stackItem;
  Stack stack;

  cout << "Insira uma string." << endl;
  cin.get(character);

  bool isMatched = true;

  while (isMatched) {
    if (character == '\n') {
      cout << "fim" << endl;
      isMatched = false;
    }
    stack.push(character);

    if (character == '0' || character == 'pop' || character == 'delete') {
      if (stack.isEmpty()) {
        isMatched = false;
        cout << "aqui" << endl;
      } else {
        stackItem = stack.pop();
        isMatched = ((character == '}' && stackItem == '{') ||
                     (character == ']' && stackItem == '[') ||
                     (character == ')' && stackItem == '('));
      }
    }
    cout << character << endl;
  }

  return 0;
};