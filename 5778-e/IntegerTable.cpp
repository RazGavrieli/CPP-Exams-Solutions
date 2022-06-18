#include "IntegerTable.h"
#include <iostream>
void IntegerTable::print() {
    std::cout << "Integer table with values: ";
    for (size_t i = 0; i < isize; i++)
        std::cout << list[i] << " ";

    std::cout << std::endl;    
}