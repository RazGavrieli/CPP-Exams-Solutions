/**
 * @file Q5.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. Run time error. 
 * b. In the copy constructor we did not copy the 'size' parameter. So when the function fill is called on b2(that was copied). It doesn't have a correct value for size. 
 * c. Add to the copy constructor the line: 'size = other.size'. 
 */

#include <iostream>
using namespace std; class Board {
int size;
char* data;
public:
Board(int size) { this->size = size; data = new char[size]; } 
Board(const Board& other) {
    data = new char[other.size];
    size = other.size;
    for (int i = 0; i < other.size; ++i)
        data[i] = other.data[i];
    }

void fill(char c) {
    for (int i=0; i<size; ++i) {
        data[i] = c;
    }
}
};
int main() {
Board b1(10); 
b1.fill('x'); 
Board b2 = b1; 
b2.fill('.');
}