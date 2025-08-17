#include "time.h"
#include <iostream>

using namespace std;

int main() {
  Time t1(12, 30, 44);
  t1.print();
  t1.nextSecond();
  t1.print();
  t1.nextSecond();
  t1.print();
  t1.nextSecond();
  t1.print();
}
