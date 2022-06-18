/**
 * @file Q6.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. The supposed image is a red background. We can see that in line 19 where every RGB is 255 on red and 0 on blue and green. 
 * b. The image is not red because on line 23 we send &image as the stream of bytes we want to print. BUT image itself is a pointer. So writing &image actually means the address of a pointer. 
 * We should remove the & from line 23. 
 */


#include <iostream> 
#include <fstream> 
using namespace std;
struct RGB {
uint8_t red, green, blue; 
public:
RGB(): red(), green(), blue(0) {} 
RGB(uint8_t r, uint8_t g, uint8_t b): red(r), green(g), blue(b) {}
};
int main() {
const int dimx = 800, dimy = 800; 
ofstream imageFile("image.ppm", ios::out | ios::binary); 
imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
RGB* image[dimx*dimy];
for (int j = 0; j < dimy; ++j) { // row 
    for (int i = 0; i < dimx; ++i) { // column
        image[dimx*j+i] = new RGB{255,0,0};
    }
}
imageFile.write(reinterpret_cast<char*>(image), 3*dimx*dimy); 
imageFile.close();
for (int j = 0; j < dimy; ++j) { // row 
    for (int i = 0; i < dimx; ++i) { // column
    delete image[dimx*j+i];
    }
}
return 0;
}