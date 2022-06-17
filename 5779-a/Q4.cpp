/**
 * @file Q4.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. The error is of a compiler type. In lines 1-2 we include iostream and string which both include class string in their dependencies. 
 * This additional class string is inside namespace std which is used in line 3. 
 * 
 * b. We could delete both lines 1 and 2, but the correct way of doing this is delete only line 3 and not use the namespace std. 
 * 
 * c. It won't create a problem because the pointer's address is never allocated to an address in the heap. (never used the 'new' keyword). 
 */

#include <iostream> 
#include <string>
//  using namespace std; << deleted line
class string {
    const char* p; 
    public:
    string(const char* p) {
        this->p = p;
    } 
    // void print() {
    //     std::cout << p; // NOT IMPLEMENTED IN THE ORIGINAL QUESTION\SOLUTION
    // }
};
int main() { // a demo program
    string s = "abc";
    // s.print(); // NOT IMPLEMENTED IN THE ORIGINAL QUESTION\SOLUTION
}