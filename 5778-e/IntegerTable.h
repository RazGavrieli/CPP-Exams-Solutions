#pragma once

#include "AbstractTable.h"

class IntegerTable : public AbstractTable {
    int* list;
    int isize;
public:
    IntegerTable(int s) : isize(s), list(new int[s]) { 
       
    }
    ~IntegerTable() {
        delete[] list; 
    } 
    void print() override;
};