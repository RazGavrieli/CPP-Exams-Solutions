/**
 * @file Q4.cpp
 * @author Raz Gavrieli
 * @brief 
 * 
 *  
 */


#include <iostream>
#include <fstream> 
#include <iterator>
#include <algorithm>
using namespace std;
int main() { // a demo program
    ifstream input("input.txt"); 
    ofstream positive("positive.txt");
    ofstream negative("negative.txt");
    partition_copy(istream_iterator<int>(input), istream_iterator<int>(), ostream_iterator<int>(positive), ostream_iterator<int>(negative), [](int i){return i>=0;}); // COMPLETE THIS LINE
}