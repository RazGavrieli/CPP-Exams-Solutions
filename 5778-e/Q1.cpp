/**
 * @file Q1.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. Run time error
 * b. Out of bounds in line 65. 
 * c. Implemented an 'at(int index)' function that returns a char& (reference so you can edit the return value). 
 * 
 */

#include <iostream>
#include <fstream>
using namespace std;
class Picture {
char* pixels; // grayscale image - each pixel is one byte.
int width, length; 
public:
    Picture(int width, int length): width(width), length(length), pixels(new char[width*length]) {}
    void setBackground() { 
        for (size_t i = 0; i < width; i++)
        {
            for (size_t j = 0; j < length; j++)
            {
                at(i+j) = 65;
            }
        }
        
    }

    char& at(int index) {
        if (index>width*length) {
            throw out_of_range("index out of bounds");
        }
        return pixels[index];
    }

    void write(ostream& file) {
        file.write(pixels, width*length);
    }

    void print() {
        for (size_t i = 0; i < width; i++)
        {
            for (size_t j = 0; j < length; j++)
            {
                std::cout << at(i+j);
            }
            std::cout << "\n";
        }
    }
};
int main() {
Picture pic1(5, 10); 
pic1.setBackground(); 
pic1.print();
ofstream outfile("test.bin"); 
pic1.write(outfile); 
Picture pic2(100,500); 
pic2.setBackground();
}