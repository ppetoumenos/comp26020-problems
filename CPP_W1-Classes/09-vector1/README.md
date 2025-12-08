The program [main.cpp](main.cpp) uses a dynamically sized array for integers called Vector which is defined in [vector.cpp](vector.h) and [vector.h](vector.h).
The vector encapsulates (hides) an underlying integer array which holds the actual data. When the vector needs to grow, a new larger array is allocated and the data are moved to the new array.
This logic is similar to `ArrayList<Integer>` in Java and `list` in Python. The implementation of Vector is currently incomplete:
- It declares `data`, a pointer to int member variable that will hold the underlying array
- It declares `sz`, an integer holding the current size of the array
- It declares, but does not define:
  - a default constructor: `Vector()`,
  - a constructor that allocates directly `sz` elements in the newly constructed vector: `Vector(int)`
  - a member function that adds to the back of the vector a new number, similarly to `append` in Python: `push_back(int)`
  - a member function that returns the current size of the array: `size()`

The underlying data array should be allocated on the heap with `new int[sz]`. When the vector needs to grow, the code should allocate a new larger data array, copy the numbers from the old to the new data array, and then insert the new items.

For this simple implementation, the code does not need to deal with removing elements from the vector.

Can you implement these four member functions correctly so that when the code in `main()` is executed it produces the following output:
```shell
./vector
The size of the vector should be 10 and it's 10
The vector should have 11 elements now and it has 11
The vector should have 30011 elements now and it has 30011
```

Check the correctness of your program with this command:
```shell
check50 -l --ansi-log ppetoumenos/comp26020-problems/main/CPP_W1-Classes/09-vector1
```
