/**
 * @file Q1.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. Run time error caused by NULL return value from the function operator<<(ostream, triplet).
 * b. In line 13 add: 'return out;'.
 */

#include <iostream>
using namespace std;
class triplet {
double x,y,z; 
public:
triplet(double x, double y, double z): x(x), y(y), z(z) {} 
friend ostream& operator<< (ostream& out, const triplet& t);
};
ostream& operator<< (ostream& out, const triplet& t) {
out << "(" << t. x << "," << t.y << "," << t.z << ")";
return out; // << fix
}
int main() {
triplet t(1,2,3); 
cout << t << endl;
}
