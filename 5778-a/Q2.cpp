/**
 * @file Q2.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. Line 14 gets LargeMatrix m, which initiate a new instance of LargeMatrix just for this scope. The uneccesery copy costs resources that slows the program. 
 * b. Change line 14 to 'int sum_of_values(const LargeMatrix& m) { (The 'const' keyword makes sure that we can also pass rvalues. i.e: sum_of_values(LargeMatrix(5,5))). 
 */

#include <iostream>
using namespace std;
class LargeMatrix {
        public: // ...
    LargeMatrix(int width, int height) {
        cout << "standard ctor" << endl; // ...
    }
    LargeMatrix(const LargeMatrix& other) {
        cout << "copy ctor" << endl; // ...
    }
};
int sum_of_values(const LargeMatrix& m) {
    cout << "sum_of_values" << endl; int result = 0; // do calculation ... 
    return result;
}
int main() {
LargeMatrix m1 (1000, 1000);
cout << sum_of_values(m1) << endl;
//cout << sum_of_values(LargeMatrix(5,5)) << endl; - Example that uses rvalues and requires 'const' keyword in sum_of_values arguments. 
}

