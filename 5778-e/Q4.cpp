/**
 * @file Q4.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. Run time error. Trying to free a pointer that already been freed. 
 * b. In line 20 we change the POINTER of this to point to the same address that newBuffer's pointer is pointing at. 
 * Firstly we lost the address of the original address of this.
 * Secondly, in line 21 the pointer of newBuffer gets deleted in the destructor. Then, when this will be deleted in the destructor, the program will attempt to free the same address.
 * c. The function 'fill' does not need to create a new instance of Buffer. 
 *    We need to iterate through this.doubles[i] and assign 'd' to every address. Implementation below: 
 */

#include <iostream>
using namespace std;
class Buffer {
double* doubles;
int size; 
public:
Buffer(int size): size(size), doubles (new double[size]) { 
for (int i=0; i<size; ++i) 
    doubles[i] = 0.0;
}
~Buffer() {
    delete[] doubles;
}

// void fill(double d) { // The buggy implementation in the exam
//     Buffer newBuffer(size);
//     for(int i=0; i<size; ++i) newBuffer.doubles[i] = d;
//     this->doubles = newBuffer.doubles;
// }

void fill(double d) {
    for(int i=0; i<size; ++i) doubles[i] = d;
}

void print() const {
for (int i=0; i<size; ++i) cout<< doubles[i] << " ";
cout << endl;
}
};

int main() {
    Buffer b1(5); b1. print();
    Buffer b2(5); b2.fill(12.34); b2.print();
}

