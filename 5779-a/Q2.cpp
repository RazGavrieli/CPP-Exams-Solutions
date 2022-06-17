/**
 * @file Q3.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. In line 21 there is an implicit conversion to create (B arg) from (A a). 
 * It would work if B's constructor wouldn't be explicit.
 * 
 * b. Create a new instance of B inside of the function's arguments. new line 21:
 *      printit(B(a));
 *    Casting won't work because none of the classes inherit from the other. 
 * 
 * c. Output of the program:
 *    A()
 *    B (A)
 *    B (A)
 */

#include <iostream> 
using namespace std;

class A;

class B { 
    public:
    explicit B (A& o) { cout << "B (A)" << endl; }
};

class A { 
    public:
    A() { cout << "A()" << endl; }
};

void printit(B arg) {}


int main() {
    A a;
    B b(a); 
    printit(B(a)); // << fixed line
    return 0;
}