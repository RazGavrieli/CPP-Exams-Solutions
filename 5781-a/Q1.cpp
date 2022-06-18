/**
 * @file Q1.cpp
 * @author Raz Gavrieli
 * @brief 
 */

#include <iostream>

class Box {
    int length, breadth, height;
    public:
    Box(int l, int b, int h) : length(l), breadth(b), height(h) {}

    bool operator<(const Box& other) {
        if (length!=other.length) {
            return length<other.length;
        } 
        if (breadth!=other.breadth) {
            return breadth<other.breadth;
        }
        return height<other.height;
    }
    
};


using namespace std;
int main() {
Box b1(1, 2, 4); // A box with length 1, breadth 2, height 4 
Box b2(2, 1, 4); // A box with length 2, breadth 1, height 4 
Box b3(2, 2, 3); // A box with length 2, breadth 2, height 3 
cout << boolalpha << (b1 < b2) << endl;
// prints "true" since the length of b1 is smaller, 
cout << boolalpha << (b2 < b3) << endl;
// prints "true" since
// the length is equal, but the breadth of b2 is smaller. 
cout << boolalpha << (b3 < b1) << endl;
// prints "false" since the length of b3 is larger. 
cout << boolalpha << (b3 < b3) << endl;
// prints "false"
}