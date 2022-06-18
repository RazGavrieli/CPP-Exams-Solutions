/**
 * @file Q1.cpp
 * @author Raz Gavrieli
 * @brief 
 * This file replaces 'hello.cpp' file from the exam
 * a. The file run.sh does not have permissions to be excecuted. 
 * b. write in the cmd 'chmod +x run.sh'. 
 * Then you can run ./run.sh hello.cpp
 * c. The run.sh file should look like this:
 * clang++-9 -std=c++2a $1
 * ./a.out < string.txt
 * 
 */

#include <iostream>
using namespace std;
int main() {
    cout << "Enter a string: ";
    string s;
    cin >> s;
    cout << endl << "The string you entered is :" << s << endl;
}