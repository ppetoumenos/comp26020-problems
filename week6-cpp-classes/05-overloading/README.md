The program [overloading.cpp](overloading.cpp) declares a `Complex` class
representing complex numbers. In its `main`, it calls a function named
`add_and_print` that can take complex numbers but also integers and doubles
as parameters,

```cxx
#include <iostream>

class Complex {
private:
    int real{0};
    int imag{0};

public:
    Complex() = default;
    Complex(int real_part, int imaginary_part);
    int get_real_part();
    int get_imaginary_part();
};

Complex::Complex(int real_part, int imaginary_part) 
    : real{real_part}, imag{imaginary_part} {};

int Complex::get_real_part() {
    return real;
}

int Complex::get_imaginary_part() {
    return imag;
}

/* implement add_and_print here */

int main(int argc, char **argv) {
    Complex c1(4, 5);
    Complex c2(9, 11);
    int i1 = 4, i2 = 9;
    double d1 = 5.8, d2 = 11.2;

    add_and_print(c1, c2); // should print "(4+5i) + (9+11i) = (13+16i)"
    add_and_print(i1, i2); // should print "4 + 9 = 13"
    add_and_print(d1, d2); // should print "5.800000 + 11.200000 = 17.000000"

    return 0;
}
```

Implement the function `add_and_print`, using overloading to have it support
several types as parameters. The expected output is:
```shell
./overloading
(4+5i) + (9+11i) = (13+16i)
4 + 9 = 13
5.800000 + 11.200000 = 17.000000
```

To check the correctness of your program, use the department VM image with check50 installed or alternatively CS50 [sandbox](sandbox.cs50.io)
or [IDE](ide.cs50.io) and write it in a file named `overloading.cpp`. In a
terminal, with that file in the local directory, check with this command:
```shell
check50 -l --ansi-log ppetoumenos/comp26020-problems/2022-2023/week6-cpp-classes/05-overloading
```
