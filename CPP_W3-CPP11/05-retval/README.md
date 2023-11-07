The program [retval.cpp](retval.cpp) implements function my\_clock\_gettime()
which is meant to provide functionality similar to the C standard library
function clock\_gettime(). That function is the main way to find out the
current point in time, using one of a number of available clocks, and is
useful for measuring time durations, e.g. when benchmarking functions.

my\_clock\_gettime() uses C++ standard library utilities to get the current
time, but a) it returns it as struct timespec, i.e. the same type as
clock\_gettime() and b) it accepts the same clock IDs as clock\_gettime().
The interface of our function roughly mimics the one of clock\_gettime()
but we are free to change it.

As is, that interface is a very C-like and uses the antipattern of returning
some of the result via the return value and the rest through pointer arguments.
Can you change the interface of the function, its implementation, and how it
is used in main() to avoid passing output values as arguments?

Do not attempt to change or understand any other function beyond
my\_clock\_gettime() and main().

As a follow up, main() is using an index-based for loop to iterate over two 
arrays concurrently, the clocks and the clock\_names arrays. Index-based loops
are dangerous, so can you change that loop into a range-for one that iterates
over a single array? One way to achieve this would be to change how the clocks
array and the corresponding names are defined.

Every time the program is executed, the result will be slightly different but
it should look something like the following:
```shell
./retval
CLOCK_MONOTONIC: 1970-01-01T04:07:07.110110634
CLOCK_REALTIME: 2023-11-07T12:59:23.367741561
CLOCK_TAI: ERROR!
```

The realtime clock line should be close to the current time, while the monotonic
clock line will either be the current time or some time in January 1970,
depending on your system.

It's hard to check that you have implemented the right solution using the
check50 framework, but you should be able to, at least, check the correctness
of your program with this command:
```shell
check50 -l --ansi-log ppetoumenos/comp26020-problems/2023-2024/CPP_W3-CPP11/05-retval
```

clock\_gettime() info: [https://man7.org/linux/man-pages/man2/clock\_gettime.2.html](https://man7.org/linux/man-pages/man2/clock_gettime.2.html)
