/**
 * @file Q1.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. The errors are:
 *    The operator= functions  (lines 10 and 23) return a reference. 
 *    But the line "return this;" attempts to return a pointer. (this is a pointer).
 *    To fix, dereference this: "return *this;".
 * 
 * b. The output of the program is:
 *      I am base 
 * 
 * c. In the line d=b; in the main the compiler will look for an operator function in Derived that gets a "const Base &".
 *    To fix the problem simply change line 23 to get "const base &".
 * 
 * d. The output of the program:
 *     I am base
 *     I am derived
 */

#include <iostream> 
using namespace std;
class Base { 
    public:
     Base () {} void Print (){
    cout <<" I am base "<<endl;
     }
Base& operator= (const Base & b) {
return *this;
}
};
class Derived : public Base { 
    public: 
    Derived () :Base () {}
void Print() {
cout <<" I am derived "<<endl;
}
Derived& operator=(const Base &) {
return *this;
}
};

int main() {
    Derived d;
    Base b;
    b=d;
    b.Print();
    d=b;
    d.Print();
    return 0;
}