/**
 * @file Q5.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. Compliation error. When calling sizeOfVector on v the compiler can't find a function for it because the function in line 09 is not marked as const. 
 * b. Add const to line 09. as follows:
 */

#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class TwoVectors {
    vector<T> theVectors[2];
public: 
    int sizeofVector(int i) const { // << const keyword was added here
        return theVectors[i].size();
    }

};
template <typename T> ostream& operator<< (ostream& out, const TwoVectors<T>& v) {
    out << "first vector has size " << v.sizeofVector(0) << endl; 
    out << "2nd vector has size" << v.sizeofVector(1) << endl; return out;
}
int main() {
    TwoVectors <int> V;
    cout << V << endl;
    return 0;
}