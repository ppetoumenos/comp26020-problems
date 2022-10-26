The program [inheritance.cpp](inheritance.cpp) creates a few objects from classes `Vehicle`,
`Car` and `Motorbike`:
```cxx
#include <iostream>

/* Class definition and member function implementation here */

int main(int argc, char **argv) {
    Vehicle v(20000);  // a Vehicle with mileage = 20000 miles
    Car c1(10000, 2);  // a Car with mileage = 10000 miles and 2 steering wheels
    Car c2(5000, 4);   // a Car with mileage = 5000 miles and 4 steering wheels
    Motorbike m(50000, 500); // a Motorbike with mileage = 50000 miles and class 500cc

    std::cout << "v's mileage is: " << v.get_mileage() << "\n";
    
    std::cout << "c1's mileage is: " << c1.get_mileage();
    std::cout << ", steering wheels: " << c1.get_steering_wheels << "\n";

    std::cout << "c2's mileage is: " << c2.get_mileage();
    std::cout << ", steering wheels: " << c2.get_steering_wheels << "\n";
    
    std::cout << "m's mileage is:  " << m.get_mileage();
    std::cout << ", cc class: " << m.get_cc_class() << "\n";

    return 0;
}
```

Edit the file to include the definition of the classes as well as the
implementation of constructors and relevant member functions knowing that:

- `Vehicle` has a member variable `_mileage`
- `Car` inheritates from `Vehicle` and has a member variable `_steering_wheels`
- `Motorbike` inheritates from `Vehicle` and has a member variable `_cc_class`

Expected output:
```shell
./inheritance
v's mileage is: 20000
c1's mileage is: 10000, steering wheels: 2
c2's mileage is: 5000, steering wheels: 4
m's mileage is:  50000, cc class: 500
```

To check the correctness of your program, use the department VM image with check50 installed or alternatively CS50 [sandbox](sandbox.cs50.io)
or [IDE](ide.cs50.io) and write it in a file named `inheritance.cpp`. In a
terminal, with that file in the local directory, check with this command:
```shell
check50 -l --ansi-log ppetoumenos/comp26020-problems/2022-2023/week4-c++/04-inheritance
```
