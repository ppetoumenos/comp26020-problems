The program [constexpr.cpp](constexpr.cpp) is a variation of the rangefor
exercise from last week: it uses arrays instead of vectors and has a custom
random number generator. It also includes some time measuring code that 
you don't have to worry about.

The output of the program (apart from the timings) is the same every time the
program runs and is knowable at compile time, but the program needs to
do all calculations each time it runs. This is inefficient, so could you
rewrite the program to calculate the result at compile time.

- Your program should produce the same result
- But run much much faster (ideally zero microseconds)

You could use godbolt to check the kind of assembly produced by the program
and see how much of the program has been pre-computed at compile-time.

Compilation time might increase significantly, in which case check50 will
return a timeout error. I have not figured out how to convince check50 to
wait a bit longer, so if this happens, compile and run your program manually
with the following two commands:

```shell
g++ constexpr.cpp -o constexpr -std=c++17 -ggdb -lm -O2
./constexpr
```


An example of expected output is:
```shell
./constexpr
Array size is: 16378. Program ran for 360 microseconds
```

# Extension
This exercise uses arrays and regular loops, instead of the vectors used in the
rangefor exercise and the std algorithms of the 01-algorithms exercise because
constexpr in C++ 17 does not work well with algorithms and vectors. If your
compiler supports C++ 20, can you produce the same result using algorithms
and/or vectors?


Check the correctness of your program with this command:
```shell
check50 -l --ansi-log ppetoumenos/comp26020-problems/2024-2025/CPP_W3-CPP11/06-constexpr
```
