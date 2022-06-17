/**
 * @file Q3.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. ip = nullptr, j = 0;
 *     There are no errors, void change() gets a pointer reference and and an int. 
 *      Inside the function change we increment the pointer forward. 
 *      The change to ip is saved because we passed a reference. The change to j won't happen outside of change()'s scope.
 * 
 * b. The output of the program: 
 *      ip = 0 address plus one byte and j = 0.
 *      ip = 0 address plus one byte plus sizeof(int) bytes. j = 1 because we incremented it in the main.  
 */

#include <iostream>
 using namespace std;
void change (int*& ip, int j) {
ip = (int *)(++j);
}
int main() {
int* ip = 0, j=0;
 change(ip,j);
  cout << "ip = " << ip << " j="<< (j++) << endl;
  cout << "ip = " << ip << " j ="<< j <<endl;
}
