/**
 * @file Q6.cpp
 * @author Raz Gavrieli
 * @brief 
 * The following Matrix class implementes the main function provided in the exam. 
 * The implementation is at it's simplest form, as to be expected from writing a class with pen and paper. 
 */
#include <vector>
#include <iostream>
template<typename T> 
class Matrix {
    std::vector<std::vector<T>> mat;
    int k, m;

public:
    Matrix(const std::vector<std::vector<T>>& V) {
        mat = std::move(V);
        k = V.size();
        m = V.at(0).size();
    }

    friend std::ostream& operator<<(std::ostream& output, const Matrix& self) {
        for (size_t i = 0; i < self.k; i++)
        {
            for (size_t j = 0; j < self.m; j++)
            {
                output << self.mat.at(i).at(j) << " ";
            }
            output << "\n";
        }
        return output;
    }

    Matrix operator+(const Matrix& other) {
        if (k!=other.k && m!=other.m) {
            throw std::runtime_error("sizes don't fit");
        } 
        Matrix<T> newMat(this->mat);
        for (size_t i = 0; i < k; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                newMat.mat.at(i).at(j) += other.mat.at(i).at(j);
            }
        }
        return newMat;
    }

    Matrix<T> operator*(const std::vector<T>& V) {
        if (this->m!=V.size()) {
            throw std::runtime_error("sizes don't fit");
        }
        std::vector<std::vector<T>> newvec; 
        for (size_t i = 0; i < this->k; i++)
        {
            T currValue = 0;
            for (size_t j = 0; j < this->m; j++)
            {
                currValue += this->mat.at(i).at(j)*V.at(j);
            }
            std::vector<T> currvec = {currValue};
            newvec.push_back(currvec);
        }
        
        Matrix<T> newmatrix(newvec);
        return newmatrix;
    }
};


int main(){
    std::vector <std::vector <int> > Mat {{1,2,3},{4,5,6},{7,8,9}};
    Matrix<int> a (Mat); // constructs a matrix from vector of vectors 
    Matrix<int> b ({
    {4, 5, 6}, {9, 0, 1},
    {7, 8, 7} }); 
    std::cout << "a: \n" << a;
    std::cout << "b: \n" << b;
    std::cout << "a + b: \n" << a+b; 

    Matrix<int> d ({
                    {1, 2}, 
                    {4, 5},
                    {7, 8}});
    std::vector<int> d_vector = {1, 2};
    std::cout << "d * d_vector: \n" << d * d_vector; 

return 0;
}