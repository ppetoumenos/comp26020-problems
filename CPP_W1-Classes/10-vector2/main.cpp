#include <iostream>
#include "vector.h"

int main(int argc, char** argv) {
  Vector v(10);
  std::cout << "The size of the vector should be 10 and it's " << v.size() << "\n";

  v[5] = 6;
  std::cout << "Element 5 should be 6 and it's " << v[5] << "\n\n";

  v.push_back(24);
  std::cout << "The vector should have 11 elements now and it has " << v.size() << "\n";
  std::cout << "The eleventh element should be 24 and it's " << v[10] << "\n\n";

  for (int i = 0; i < 30000; ++i)
    v.push_back(i);
  std::cout << "The vector should have 30011 elements now and it has " << v.size() << "\n";
  std::cout << "The last element should be 29999 and it's " << v[30010] << "\n\n";

  return 0;
}
