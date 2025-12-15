This exercise extends the previous vector exercise, so start by copying over your code for vector.h and vector.cpp.

In this part, [main.cpp](main.cpp) expects that vector implements one more member function: `operator[](int)`. Member functions whose name starts with operator and is followed by some operator symbol implement the functionality of the corresponding operator. So `operator[](int)` specifies what happens when we say something like `v[5]`, when `v` is a `Vector`.

Can you come up with a correct function signature that will allow the code in main.cpp to compile. Can you then implement the operator[] functionality in a correct way? If successful, you should see something like this:

```shell
./vector
The size of the vector should be 10 and it's 10
Element 5 should be 6 and it's 6

The vector should have 11 elements now and it has 11
The eleventh element should be 24 and it's 24

The vector should have 30011 elements now and it has 30011
The last element should be 29999 and it's 29999

The vector of vectors has three vectors with sizes 1, 5, and 10

```

As an **extension** can you make:
- your code follow good practices and eliminate memory errors?
- implement a copy constructor and the assignment operator for this class?
- can you modify the code to a) decouple the logical size of the vector from the actual size of the underlying array, and b) reduce the number of times you resize the underlying array?

Check the correctness of your program with this command:
```shell
check50 -l --ansi-log ppetoumenos/comp26020-problems/main/CPP_W1-Classes/10-vector2
```
