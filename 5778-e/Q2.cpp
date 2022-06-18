/**
 * @file Q2.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. Compilation error. 
 * b. Inside the function 'operator>>', c is being pass as a const reference (const Complex& c). 
 * This is wrong because the operator>> should change c.
 * In line 20 c.re() is calling the function in line 15 which returns a double as an rvalue. 
 * The c.re() funcion in line 12 that returns a double reference is what we want, but it is not accissable because c is const.
 * c. In line 19 remove the 'const' keyword from 'const Complex& c'. 
 * Adding const to line 15 is technically not correct, as these functions should modify c. 
 */

#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;

class Complex {
double _re, _im; 
public:
Complex (double _re, double _im): _re(_re), _im(_im) { }
double& re() { return _re; } 
double& im() { return _im; }
double re() const { return _re; } 
double im() const { return _im; }
};
istream& operator>>(istream& in,  Complex& c) { // << deleted 'const' keyword from here
    in >> c.re(); 
    char plus; 
    in >> plus; 
    if (plus !='+')
        throw "Wrong format - missing plus sign after real part!"; 
    in >> c.im();
    char i; 
    in >> i; 
    if (i!='i')
        throw "Wrong format - missing i after imaginary part!"; 
    return in;
}
void test() {
    istringstream input("5+7i");
    Complex c(0,0); 
    input >> c; 
    assert(c.re() == 5);
    assert(c.im() == 7);
}
int main() {
test();
}