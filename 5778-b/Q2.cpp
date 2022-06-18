/**
 * @file Q2.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. At the end of each 'for loop' iteration we lose the pointer to values[rows*cols] of the last Matrix we used in that iteration. So we need to free the memory used by that pointer. 
 * b. To free the memory add a destructor in class Matrix (implemented below)
 */

template<typename T>
class Matrix {
    T* values;
    int rows, cols;
    public: 
    Matrix(int rows, int cols): rows (rows), cols(cols), values (new T[rows*cols]) {}
    ~Matrix() { delete[] values; }
};
int main() { 
    for (int i=0; i<10000; ++i) 
        Matrix<int> m1 (1000, 1000); 
return 0;
}