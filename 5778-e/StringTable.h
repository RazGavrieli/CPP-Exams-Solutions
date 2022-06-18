#pragma once

#include "AbstractTable.h"
#include <string>

class StringTable : public AbstractTable {
    std::string* list;
    int ssize;
public:
    StringTable(int s) : ssize(s), list(new std::string[s]) { 
    for (int i=0; i<ssize; i++)
        list[i] = ".";
    }
    ~StringTable() {
        delete[] list; 
    } 

    void print() override;
};