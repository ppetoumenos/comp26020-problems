The program [algorithms.cpp](algorithms.cpp) is the solution for the rangefor
exercise from last week. It randomly initialises one vector and then copies
its odd numbers into another vector. 

Rewrite this program to implement the same functionality using std algorithms.
Your program should:

- Have no loops
- As a stretch target, can you use only a single vector? Going even further, can you avoid using resize()? To achieve the last bit you will need a special output iterator that appends elements to a vector when written.

An example of expected output is:
```shell
./algorithms
16258
```

Check the correctness of your program with this command:
```shell
check50 -l --ansi-log ppetoumenos/comp26020-problems/2023-2024/CPP_W3-CPP11/01-algorithms
```
