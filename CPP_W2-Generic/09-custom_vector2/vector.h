#include <cassert>
class Vector {
	int* data{nullptr};
	int sz{0};
  int capacity{0};
public:
  Vector() = default;

  /**
   * Start with allocating twice as many array elements relative to what the user asked for
   * sz is not guaranteed to be positive
   */
  Vector(int sz) : sz{sz}, capacity{2*sz} {
    assert(sz > 0);
    data = new int[capacity];
  }

  /**
   * Copy Constructor:
   * The argument is another vector (which is not meant to be modified)
   * so this is meant to be called when writing something like:
   * Vector v2 = v1;
   *
   * The copy constructor should create a new vector whose state is the same as the original one
   * but without sharing any information. This is what one expects when copying something.
   *
   * The constructor could initialise the member variables in the initialisation list or delegate to the normal constructor.
   * Initialising the variables separately would look like:
   * Vector(const Vector& other) : data{new int[2 * other.sz]}, sz{other.sz}, capacity{other.capacity} {...}
   * 
   * Delegating does some unnecessary work (checking whether other.sz is positive, which it's guaranteed to be),
   * but makes the code more concise.
   */
   Vector(const Vector& other): Vector(other.sz) {
     // We have this loop copying C arrays in at least three different places
     // Perhaps someone should separate this functionality in a new statically-sized array object
     for (int i = 0; i < sz; ++i) {
       data[i] = other.data[i];
     }
   }

  /**
   * Similar logic for the copy assignment
   */
   Vector& operator=(const Vector& other) {
     if (capacity < other.sz) {
       delete[] data;
       capacity = 2 * other.sz;
       data = new int[capacity];
     }
     sz = other.sz;
     for (int i = 0; i < sz; ++i) {
       data[i] = other.data[i];
     }
     // necessary to return a reference to this object
     return *this;
   }

  ~Vector() {
    delete[] data;
  }

  int push_back(int item) {
    if (sz == capacity) {
      capacity = 2 * (sz + 1);
      int* data_new = new int[capacity];
      for (int i = 0; i < sz; ++i)
        data_new[i] = data[i];
      delete[] data;
      data = data_new;
    }
    data[sz++] = item;
    return item;
  }

  int size() {
    return sz;
  }

  int& operator[](int idx) {
    return data[idx];
  }

  int& at(int idx) {
    assert(idx >= 0);
    assert(idx < sz);
    return data[idx];
  }
};
