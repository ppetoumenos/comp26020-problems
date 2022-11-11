The program [specialization.cpp](specialization.cpp) defines and uses Array8,
a fixed array class that holds 8 items. The type of the items is a template
parameter. While it works for all types, it's inefficient for booleans: 8
booleans can be stored in a byte but the current implementation uses 8 bytes.

Write a template specialisation for boolean that stores all 8 booleans in a
single byte.

An example of expected output is:
```shell
./specialization
168
```

To check the correctness of your program, use the department VM image with check50 installed or alternatively CS50 [sandbox](sandbox.cs50.io)
or [IDE](ide.cs50.io) and write it in a file named `specialization.cpp`. In a
terminal, with that file in the local directory, check with this command:
```shell
check50 -l --ansi-log ppetoumenos/comp26020-problems/2022-2023/week7-cpp-generic/05-specialization
```
