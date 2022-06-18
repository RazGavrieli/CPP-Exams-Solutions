/**
 * @file Q6.cpp
 * @author Raz Gavrieli
 * @brief 
*/

#include <iostream>
using namespace std;
class A
{
    public:
    virtual void f(const int i) { cout << "A::f" << endl; } 
    void g(const int i) { cout << "A::g" << endl; } 
    void h(const int i) { cout << "A::h" << endl; }
    virtual void i(const int i) { cout << "A::i" << endl; } 
};

class B : public A {
    public:
    void f() { cout << "B::f" << endl; } 
    void g() { cout << "B::g" << endl; }
};
class C : public B {
public:
    void f(const int i) { cout << "C::f" << endl; }
    void i(const int i) { cout << "C::i" << endl; } 
};

class D : public C {
    public: 
    void f(const int i) { cout << "D::f" << endl; }
    void g(const int i) { cout << "D::f" << endl; }
    void h(const int i) { cout << "D::h" << endl; }
    void i() { cout << "D::i" << endl; }
};

int main() { // compilation errors are commented
    
    D d;
    A* pa = &d;
    B* pb = &d;
    C* pc = &d;
    D* pd = &d;

    pa->f(1);
    //pb->f(1);
    pc->f(1);
    //pc->f(); 
    pd->f(1);

    pa->g(1); 
    //pb->g(1); 
    //pc->g(1); 
    pd->g(1);

    pa->h(1); 
    pb->h(1); 
    pc->h(1); 
    pd->h(1);

    pa->i(1); 
    //pd->i(1);

    A a, *p = &a; 
    p->f(1);
    


    
}