/**
 * @file Q3.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. draw() function in Shape class is defined virtual and with = 0 it means that it is not implemented on purpose and serves as an "interface" for derived classes. 
 * We may have passed to drawTheShape a circle, but it was not passed as reference so a new object was created that is a Shape type. 
 * 
 * b. void drawTheShape( Shape& s) {
 * This fix will ensure that the function will recieve the object itself and won't create a new one. 
 * The type of the passed object will be a Shape but "under the hood" it has information about it being a Circle (or other derived classes). 
 * The vtable will take care of using the correct draw() function. 
 * 
 * c. Output of the program:
 *  Circle::draw()
 *  ~Circle()
 *  ~Shape()
 */

#include <iostream>
using namespace std;
class Shape { 
    public:
    virtual void draw () = 0; 
    virtual ~Shape () { cout << "~Shape()" << endl; }
};
class Circle : public Shape
{
public:
    void draw()  { cout << "Circle::draw ()" << endl; }
    ~Circle() { cout << "~Circle()" << endl; }
};
void drawTheShape( Shape& s) { // << fixed line
    s.draw();
 }
int main() {
    Circle c;
    drawTheShape(c);
    return 0;
}