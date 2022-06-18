/**
 * @file Q7.cpp
 * @author Raz Gavrieli
 * @brief 
 * 
 */

#include "minmax.h" 
#include <forward_list>
#include <iostream> 
#include <vector> 
using namespace std; 
int main() {
forward_list <int> list1 ({1,-2,3,-4,5}); 
vector<int> vec1 ({-1,2,-3,4,-5}); 
minmax(list1.begin(), list1.end(), vec1.begin(), vec1.end()); 
for (int i: list1) 
    cout << i << " "; 
cout << endl; //-1 -2 -3 -4 -5 
for (int i: vec1) 
    cout << i << " "; 
cout << endl; // 1 2 3 4 5 
int arr1[] = {8,6,4,2,0}; 
minmax(vec1.begin(), vec1.end(), arr1, arr1+5); 
for (int i: vec1) 
    cout << i << " "; 
cout << endl; // 1 2 3 2 0 
for (int i: arr1) 
    cout << i << " "; 
cout << endl; // 8 6 4 4 5

minmax(vec1.begin(), vec1.end(), arr1, arr1+4);
// exception: "sequence 1 is longer" 
minmax(vec1.begin(), vec1.end(), arr1, arr1+6);
// exception: "sequence 2 is longer"
}