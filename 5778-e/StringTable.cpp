#include "StringTable.h"
#include <iostream>
void StringTable::print() {
    std::cout << "String table with values: ";
    for (size_t i = 0; i <ssize; i++)
        std::cout << list[i] << " ";

    std::cout << std::endl;    
}