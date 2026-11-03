#include <cassert>
#include <cstddef>

template <typename T>
class VIterator {
  T* ptr;
public:
  // Basic initialisation
  VIterator(T* ptr) : ptr{ptr} {}

  // Copy constructor and copy assignment operator
  VIterator(const VIterator& other) = default;
  VIterator& operator=(const VIterator& other) = default;

  T& operator*() {
    return *ptr;
  }

  // Point to the next element
  void operator++() {
    ++ptr;
  }

  // Iterators are unequal if they point to the different element
  bool operator!=(const VIterator& other) {
    return ptr != other.ptr;
  }
};

template <typename T>
class Vector {
  T* data{nullptr};
  size_t sz{0};
  size_t capacity{0};
public:
  Vector() = default;

  /**
   * Start with allocating twice as many array elements relative to what the user asked for
   * sz is not guaranteed to be positive
   */
  Vector(size_t sz) : sz{sz}, capacity{2*sz} {
    assert(sz > 0);
    data = new T[capacity];
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
   * Vector(const Vector& other) : data{new T[2 * other.sz]}, sz{other.sz}, capacity{other.capacity} {...}
   * 
   * Delegating does some unnecessary work (checking whether other.sz is positive, which it's guaranteed to be),
   * but makes the code more concise.
   */
   Vector(const Vector& other): Vector(other.sz) {
     // We have this loop copying C arrays in at least three different places
     // Perhaps someone should separate this functionality in a new statically-sized array object
     for (size_t i = 0; i < sz; ++i) {
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
       data = new T[capacity];
     }
     sz = other.sz;
     for (size_t i = 0; i < sz; ++i) {
       data[i] = other.data[i];
     }
     // necessary to return a reference to this object
     return *this;
   }

  ~Vector() {
    delete[] data;
  }

  T push_back(T item) {
    if (sz == capacity) {
      capacity = 2 * (sz + 1);
      T* data_new = new T[capacity];
      for (size_t i = 0; i < sz; ++i)
        data_new[i] = data[i];
      delete[] data;
      data = data_new;
    }
    data[sz++] = item;
    return item;
  }

  size_t size() {
    return sz;
  }

  T& operator[](size_t idx) {
    return data[idx];
  }

  T& at(size_t idx) {
    assert(idx >= 0);
    assert(idx < sz);
    return data[idx];
  }

  VIterator<T> begin() {
    return VIterator(data);
  }

  VIterator<T> end() {
    return VIterator(data+sz);
  }
};
