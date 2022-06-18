/**
 * @file Q3.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. 8 for one pointer (on the stack)
 *    (4*3)*10 for 10 structs of date.
 *    120. 
 * b. 120. The pointer itself gets realsed from the stack in line 15. The 10 structs of date are still on the heap and lost. 
 * c. Not in the syllabus 
 * d. Still 120.
 */

#include <iostream>
using namespace std;
struct Date {
int _year; 
int _month;
int _day; 
};
int main() { 
    Date* dates = new Date[10];
    cout << dates[0]._year;
}