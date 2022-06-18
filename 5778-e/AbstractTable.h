#pragma once
#include <iostream>

class AbstractTable {
    static int size;

    public: 
    AbstractTable() {
        size++;
    };
    AbstractTable(int) {
        size++;
    };
    virtual ~AbstractTable(){ AbstractTable::size--;}
    virtual void print() = 0;
    static int count() { return size; }
};
