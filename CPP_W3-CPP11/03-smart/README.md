The program [smart.cpp](smart.cpp) has a simple class hierarchy:
Base contains one number, Derived1 derives from Base and adds another number,
Derived2 derives from Derived1 and adds a third number. The classes implement
a get\_sum() method that returns the sum of the integers contained in the
object. A function randomly generates a vector of Base pointers pointing to
heap allocated objects of type Base, Derived1, or Derived2. 

While mostly correct, this implementation does not release the heap allocated
objects when they go out of scope. Can you use smart pointers to handle this
automatically?

```shell
./smart
4468
```

Check the correctness of your program (but not whether you have used smart pointers properly) with this command:
```shell
check50 -l --ansi-log ppetoumenos/comp26020-problems/2023-2024/CPP_W3-CPP11/03-smart
```
