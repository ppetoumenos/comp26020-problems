#include <iostream>
#include "vector.h"

int main(int argc, char** argv) {
  Vector v(10);
  std::cout << "The size of the vector should be 10 and it's " << v.size() << "\n\n";

  v.push_back(24);
  std::cout << "The vector should have 11 elements now and it has " << v.size() << "\n";

  for (int i = 0; i < 30000; ++i)
    v.push_back(i);
  std::cout << "The vector should have 30011 elements now and it has " << v.size() << "\n";

  return 0;
}
