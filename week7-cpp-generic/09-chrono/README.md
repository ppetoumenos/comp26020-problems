The program [chrono.cpp](chrono.cpp) is the solution for the vector and the
array exercises, plus a C-array solution for array sizes that are known at
compile time. The three different versions are called one after the other one
in `main()`. Add time measurements around the code of each version and print
out the time it took to run each one. Which one do you think will do better?

An example of expected output is:
```shell
./chrono     
elapsed time: 0.000882946s
elapsed time: 0.000882946s
elapsed time: 0.000882946s
600000
```

To check the correctness of your program, use the department VM image with check50 installed or alternatively CS50 [sandbox](sandbox.cs50.io)
or [IDE](ide.cs50.io) and write it in a file named `chrono.cpp`. In a
terminal, with that file in the local directory, check with this command:
```shell
check50 -l --ansi-log ppetoumenos/comp26020-problems/2022-2023/week7-cpp-generic/09-chrono
```
