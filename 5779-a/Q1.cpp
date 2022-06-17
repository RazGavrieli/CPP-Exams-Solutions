/**
 * @file Q3.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. Output of the program is:
 * A(0)
 * B(0)
 * A(0)
 * B(1)
 * b. Output of the program is:
 * A(0)
 * B(0)
 * A(1)
 * 
 * c. Output of the program is:
 * A(0)
 * B(0)
 * A(0)
 * B(1)
 */

#include <iostream>
using namespace std;
class A
{
public:
    A() { cout << "A (0)" << endl; }
    A(const A &a) { cout << "A (1)" << endl; } // << comment this for c
};

class B
{
public:
    B() : a() { cout << "B (0)" << endl; }
    B(const B &b) { cout << "B (1)" << endl; } // << comment this for b

private:
    A a;
};

int main()
{
    B objectl;
    B object2 = objectl;
    return 0;
}