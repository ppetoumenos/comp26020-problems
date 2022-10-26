Consider the program [encapsulation.cpp](encapsulation.cpp):

```cxx
#include <iostream>

class Rectangle {
public:
    float length;
    float width;
};

class Circle {
public:
    float radius;
};

float rectangle_perimeter(Rectangle *r) {
    return 2.0 * (r->length + r->width);
}

float circle_circumference(Circle *c) {
    return 2.0 * 3.14 * c->radius;
}

int main(int argc, char **argv) {
    Rectangle r;
    Circle c;

    r.length = 10;
    r.width = 20;

    c.radius = 1;

    std::cout << "Rectangle l: " << r.length << ", w: " << r.width;
    std::cout << ", perimeter: " << rectangle_perimeter(&r) << "\n";

    std::cout << "Circle r: " << c.radius;
    std::cout << ", circumference: " << circle_circumference(&c) << "\n";
    return 0;
}
```

All variable members of both classes `Rectangle` and `Circle` are public and
can be read/written from outside, as it is the case in `main`,
`rectangle_perimeter` and `circle_circumference`. Apply the principles of
encapsulation and rewrite this program to implement:

- `private` visibility for all class member variables
- constructors
- the transformation of both perimeter/circumference computing functions into
  member methods named `perimeter` for the rectangle and `circumference` for
  the circle
- getter functions for class member variables, named `get_length`,
  `get_radius`, etc.

The expected output is:
```shell
./encapsulation
Rectangle l: 10.000000, w: 20.000000, perimeter: 60.000000
Circle r: 1.000000, circumference: 6.280000
```

To check the correctness of your program, use the department VM image with check50 installed or alternatively CS50 [sandbox](sandbox.cs50.io)
or [IDE](ide.cs50.io) and write it in a file named `encapsulation.cpp`. In a
terminal, with that file in the local directory, check with this command:
```shell
check50 -l --ansi-log ppetoumenos/comp26020-problems/2022-2023/week4-c++/02-encapsulation
```
