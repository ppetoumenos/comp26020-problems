The program [move.cpp](move.cpp) implements a very basic String class.
Currently it handles default initialisation, initialisation with a
string\_view, accessing a character with [], and printing to an ostream.
The main program creates one String, which is then copied and moved to
another two Strings. Because String has no copy and move constructors, this
program does not do what it's supposed to.

Can you add copy and move constructors to fix its functionality? If fixed, the
output should be:

```shell
./move
invalid
HElloWorld
heLloWorld
```

Check the correctness of your program with this command:
```shell
check50 -l --ansi-log ppetoumenos/comp26020-problems/2024-2025/CPP_W3-CPP11/02-move
```
