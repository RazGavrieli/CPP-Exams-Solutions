/**
 * @file Q6.cpp
 * @author Raz Gavrieli
 * @brief 
 * 
 */

#include <iostream>
#include "AbstractTable.h"
#include "IntegerTable.h"
#include "StringTable.h"
int AbstractTable::size = 0;

using namespace std;
int main() {
cout << AbstractTable::count() << endl; // 0 
AbstractTable* tables[3]; 
cout << AbstractTable::count() << endl; // 0 
//tables[0] = new AbstractTable(5); /* This line should create a compilation error:
//"allocating an object of abstract class type 'Abstract Table'" */
tables[0] = new IntegerTable(5); 
cout << AbstractTable::count() << endl; // 1 
tables[1] = new StringTable(5); 
tables[2] = new IntegerTable(7); 
cout << AbstractTable::count() << endl; // 3 
for (AbstractTable* t: tables)
    t->print(); 
/* Should print (for example):
Integer table with values: 0 674657 1 141 - 14341 String table with values: .... Integer table with values: 989 0 0 0 13241 1513554 454
*/
delete tables[2]; 
cout << AbstractTable::count() << endl; // 2 
delete tables[1]; 
delete tables[0]; 
cout << AbstractTable::count() << endl; // 0
}