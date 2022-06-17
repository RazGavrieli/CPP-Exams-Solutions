/**
 * @file Q6.cpp
 * @author Raz Gavrieli
 * @brief 
 * Implementation as follows
 */
#include <iostream>
template<typename T>
class Fraction {
    private:
    T nom, den;
    public:
    Fraction(T nn, T dn=1) : nom(nn), den(dn) {}
    T Nom() const {
        return nom;
    }
    T Den() const {
        return den;
    }

    Fraction<T> operator+(const Fraction<T>& other) {
        T nn = nom * other.den + den * other.nom;
        T dd = den * other.den;
        Fraction<T> newfrac (nn, dd);
        return newfrac;
    }
};

int main(int argc, char const *argv[])
{
    Fraction<short> T(3, 2);
    Fraction<short> T2(4,5);
    std::cout << (T+T2).Nom() << "/" << (T+T2).Den() << std::endl;
    return 0;
}
