/**
 * @file Q5.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. Compilation error - The linker can't find the operator< for struct XX. 
 * b. Implement in struct XX operator<.  
 */
#include <iostream>
#include <set>
using namespace std;
struct XX {
    int x;
    XX(int x): x(x) {}
    bool operator<(const XX& other) const {
        return other.x<x;
    }
};

int main() { // the program should print "100"
    multiset<XX> myset;
    myset.emplace(1);
    myset.emplace(0);
    myset.emplace(0); 
    for (auto y: myset)
    cout << y.x;
}