#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

template <typename T>
class Array8 {
    T arr[8];

public: 
    void set (int idx, T value) {
        arr[idx] = value;
    }
    T& get (int idx) {
        return arr[idx];
    }
    T* get_storage() {
        return arr;
    }
};

int main(int argc, char **argv)
{
    Array8<bool> x;
    x.set(0, false);
    x.set(1, false);
    x.set(2, false);
    x.set(3, true);
    x.set(4, false);
    x.set(5, true);
    x.set(6, false);
    x.set(7, true);

    // This is not good C++
    // We are forcing x into a char
    unsigned char *c = (unsigned char *) (x.get_storage());
    std::cout << (int) *c << "\n";
    return 0;
}
