/**
 * @file Q6.cpp
 * @author Raz Gavrieli
 * @brief 
 * 
 */
#include <iostream>
template<typename func>
double integral(func f, double x) {
    double res = 0; 
    for (double i = 0; i < x; i+=0.001)
    {
        res += f(i)*0.001;
    }
    return res; 
}

using namespace std;
double twice(double x) { return 2*x; }
struct fourtimes {
double operator () (double x) {return 4*x;}
};

int main() {
cout << integral(twice, 10) << endl; // -100 (x^2 from 0 to 10) 
cout << integral(fourtimes{}, 10) << endl; // -200 (2*x^2 0 to 10) 
cout << integral([](double x){return 6*x;}, 10) << endl; // -300
cout << integral(twice, 20) << endl; // -400 (x^2 from 0 to 20) 
cout << integral(fourtimes{}, 20) << endl; // -800 (2*x^2 0 to 20) 
cout << integral([](double x){return 6*x;}, 20) << endl; // -1200
return 0;
}
