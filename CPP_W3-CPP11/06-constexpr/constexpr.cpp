#include <array>
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <iostream>

#define SIZE (64 * 1024)

std::array<int, SIZE> init_vector() {
  std::array<int, SIZE> arr{};
  arr[0] = 2023;
  for (int i = 1; i < SIZE; ++i) {
    uint64_t num = arr[i - 1];
    arr[i] = (1103515245 * num + 12345) % (1 << 31);
  }
  return arr;
}

std::array<int, SIZE> copy_odds(std::array<int, SIZE>& a)
{
  std::array<int, SIZE> b{};
  for (int i = 0, j = 0; i < SIZE; ++i) 
    if (a[i] % 2 == 1)
      b[j++] = a[i];

  return b;
}

int get_size(std::array<int, SIZE>& arr) {
  for (int i = 0; i < SIZE; ++i)
    if (arr[i] == 0)
      return i;

  return SIZE;
}

int main(int argc, char **argv)
{
  auto start = std::chrono::system_clock::now();

  std::array<int, SIZE> a = init_vector();
  std::array<int, SIZE> b = copy_odds(a);
  int array_sz = get_size(b);

  auto end = std::chrono::system_clock::now();
  auto elapsed =
    std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  std::cout << "Array size is: " << array_sz << ". Program ran for " << elapsed.count() << " microseconds\n";

  return 0;
}
