/**
 * @file Q5.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. We could either create public getters for _re and _im, or - more CPP style way of doing it is move 'operator<<' function from line 26 into the class and declaring it as a friend function. 
 * This way it won't get a third paramter (this) AND will be able to access private members of the class.
 * b. This is a compilation error. The student did not add the 'friend' keyword so the function gets 'this' as a parameter. adding to the 2 parametrs that are already in the arguments of the functions.
 */
#include <iostream>
using namespace std;
class Complex {
    double _re, _im;

    public:
    Complex (double re= 0.0, double im= 0.0): _re(re), _im(im) {}

    const Complex operator-() const {
        return Complex(-_re, -_im); 
    }
    const Complex operator+(const Complex& other) const {
        return Complex (_re + other._re, _im + other._im);
    }
    Complex& operator+=(const Complex& other) {
        _re+= other._re;
        _im+= other._im; 
        return *this;
    }
    friend ostream& operator<< (ostream& os, const Complex& c) {
        return (os << c._re << "+" << c._im << 'i');
    }
};

int main() {
    Complex c1(1,2);
    Complex c2(2,3);
    cout << c1 + c2 << endl; 
    return 0;
}