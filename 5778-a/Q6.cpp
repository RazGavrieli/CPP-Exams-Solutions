/**
 * @file Q6.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. Create a destructor for @class PositiveMatrix that delete[] vals. 
 * b. Add copy constructor
 * c. add copy assignment operator
 * d. Create a new class (proxy design pattern) that present a double& with 
 */

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class PositiveMatrix {
    class double_reference {
        double& curr; 
        public:
        double_reference(double& newt) : curr(newt) {}
        double& operator=(const double& newt) {
            if (newt<0) {
                throw runtime_error("positive matrix can't hold negatives");
            }
            curr = newt;
            return curr;
        }

        friend ostream& operator<<(ostream& out, const double_reference& self) {
            out << self.curr;
            return out;
        }
    };
    double* vals;
    int rows, cols;

    public:
    PositiveMatrix(int rows, int cols) : rows(rows),cols(cols), vals(new double[rows*cols]) {
        for (size_t i = 0; i < rows*cols; i++)
            vals[i] = 0.0;
    }
    PositiveMatrix(const PositiveMatrix& other) : rows(other.rows),cols(other.cols), vals(new double[other.rows*other.cols]) {
        for (size_t i = 0; i < rows*cols; i++)
            vals[i] = other.vals[i];        
    }
    ~PositiveMatrix() {delete[] vals;}
    PositiveMatrix& operator=(const PositiveMatrix& other) {
        delete[] vals;
        this->cols = other.cols;
        this->rows = other.rows;
        this->vals = new double[rows*cols];
        for (size_t i = 0; i < rows*cols; i++)
            vals[i] = other.vals[i];
        return *this;
    }
    double operator() (int x, int y) const {
        return vals[x*cols+y];
    }

    double_reference operator() (int x, int y) {
        return vals[x*cols+y];
    }    

};


int main() {
    PositiveMatrix m1(10,4);
    cout << m1(1,2) << endl; // prints 0 (OK)
    m1(1,2) = 3.0;
    cout << m1(1,2) << endl; // prints 3 (OK)
    PositiveMatrix m2{m1};
    m2(1,2) = 5;
    cout << m1(1,2) << endl; // prints 5 (should print 3)
    m1 = m2;
    m1(1,2) = 7;
    cout << m2(1,2) << endl; // prints 7 (should print 5)
    m1(1,2) = -5.0; // should throw an exception "illegal value"
}