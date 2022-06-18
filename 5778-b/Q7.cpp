/**
 * @file Q7.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. 
 */

#include "RunningAverage.h"
#include <iostream>
using namespace std;
int main() {
    RunningAverage a; 
    a += 8; 
    a += 7; 
    cout << a << endl; // 7.5 (average of 7 and 8) 
    (a += 6.5) += 6.5; 
    cout << a << endl; // 7 (average of 7, 8, 6.5 and 6.5)
    a = a + 9 + 9 + 9 + 9; // 8 (average of the above and 9,9,9,9)
    return 0;
}