The program [constructor.cpp](constructor.cpp) defines a class `Pair` with
2 variable members:

```cxx
#include <iostream>

class Pair {
public:
    int x;
    int y;
};

int main(int argc, char **argv) {
    Pair p;

    p.x = 10;
    p.y = 20;

	std::cout << "p.x is " << p.x << ", p.y is " << p.y << "\n";

    return 0;
}
```

Rewrite the class Pair definition to properly encapsulate its data: public
constructor with private data, rather than public data initialised manually
in the main function. The expected output should be:

```shell
./constructor
p.x is 10, p.y is 20
```

To check the correctness of your program, use the department VM image with check50 installed or alternatively CS50 [sandbox](sandbox.cs50.io)
or [IDE](ide.cs50.io) and write it in a file named `constructor.cpp`. In a
terminal, with that file in the local directory, check with this command:
```shell
check50 -l --ansi-log ppetoumenos/comp26020-problems/2022-2023/week6-cpp-classes/01-constructor
```
