#include <iostream>
#include "vector.h"

int main(int argc, char** argv) {
  Vector<int> v(10);
  std::cout << "The size of the vector should be 10 and it's " << v.size() << "\n\n";

  std::cout << "Position 6 had the value " << v[6] << "\n";
  v[6] = 5;
  std::cout << "Position 6 now has the value " << v[6] << "\n";

  int num = 24;
  v.push_back(num);
  std::cout << "The vector should have 11 elements now and it has " << v.size() << "\n";

  for (int i = 0; i < 30000; ++i)
    v.push_back(i);
  std::cout << "The vector should have 30011 elements now and it has " << v.size() << "\n";

  Vector<int> v2{v};

  v2[6] = 15;
  std::cout << "Position 6 in v has the value  " << v[6] << "\n";
  std::cout << "Position 6 in v2 has the value " << v2[6] << "\n";

  Vector<Vector<int>> v3;
  Vector<int> subv1(1);
  Vector<int> subv2(5);
  Vector<int> subv3(15);
  v3.push_back(subv1);
  v3.push_back(subv2);
  v3.push_back(subv3);

  std::cout << "Vector of vectors v3 has " << v3.size() << " subvectors with sizes " << v3[0].size() << ", " << v3[1].size() << ", and " << v3[2].size() << "\n";

  int total_size = 0;
  for (auto& subvector: v3) 
    total_size += subvector.size();
  std::cout << "The sum of the subvector sizes is " total_size << "\n";

  return 0;
}
