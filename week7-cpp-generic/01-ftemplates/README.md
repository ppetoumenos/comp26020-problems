The program [ftemplates.cpp](ftemplates.cpp) is the solution for the
overloading exercise from last week. It implements the `+` operation for
`Complex` numbers, it defines `<<` for output streams and `Complex`, and it
defines three overloaded versions of `add_and_print`: one for `Complex`, one
for `int`, one for `double`. The main function then calls the three different
versions of `add_and_print`.

Rewrite this program to use a single templated implementation of
`add_and_print`. Your program should:

- Define `add_and_print` only once
- Declare `add_and_print` to be a template


An example of expected output is:
```shell
./ftemplates     
(4+5i) + (9+11i) = (13+16i)
4 + 9 = 13
5.800000 + 11.200000 = 17.000000
```

To check the correctness of your program, use the department VM image with check50 installed or alternatively CS50 [sandbox](sandbox.cs50.io)
or [IDE](ide.cs50.io) and write it in a file named `ftemplates.cpp`. In a
terminal, with that file in the local directory, check with this command:
```shell
check50 -l --ansi-log ppetoumenos/comp26020-problems/2022-2023/week7-cpp-generic/01-ftemplates
```
