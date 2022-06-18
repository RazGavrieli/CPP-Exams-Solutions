// #pragma once << Won't work because this is a linking error, and #pragma once instruct the compiler and NOT the linker.
#include <iostream>

class XX {
    int myval; 
public:
    XX(int newval): myval(newval) {} 
    int val() const; 
    friend std::ostream& operator<<(std::ostream&, const XX&);
};
// FOLLOWING FUNCTION MOVED TO XX.cpp
// std::ostream& operator<< (std::ostream& out, const XX& xx) {
//     out << xx.myval;
//     return out;
// }