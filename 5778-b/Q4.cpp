/**
 * @file Q4.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. Linking Error. It happens due to multiple #includes of the same file (XX.h). The linker finds two implementations of the same functions and raise an error.
 * b. Move the implementation of the function to XX.cpp. Therfore it will only be implemented once. 
 * Note the using #pragma once to compile XX.h only once, won't work. #pragma once instructs the compiler and not the linker. 
 */
/*FOR IMPLEMENTATION SEE XX.h and XX.cpp*/

#include "XX.h"

int main() {
    XX oxx(5);
    std::cout << oxx << std::endl; // should print 5;
    return 0;
}