/**
 * @file Q7.cpp
 * @author Raz Gavrieli
 * @brief 
 * The following code is the solution for the .cpp file. You can find the hpp solution at Q7.hpp. 
 * 
 */
#include <iostream>
#include "Q7.hpp"
using namespace ariel;
ariel::Money::Money(float amount, std::string type) : type(type) {
    if (type=="ILS") {
        amountInILS = amount;
    } else if (type=="USD") {
        amountInILS = amount*usdR;
    } else if (type=="EUR") {
        amountInILS = amount*eurR;
    } else {
        throw std::runtime_error("no such coin");
    }
}

ariel::Money ariel::Money::operator+(const Money& other) {
    Money sum(other.amountInILS+this->amountInILS, "ILS");
    sum.type = this->type;
    return sum;
}
ariel::Money ariel::Money::operator+=(const Money& other) {
    float newAmountInILS = other.amountInILS+this->amountInILS; 
    this->amountInILS = newAmountInILS;
    return *this;
}

namespace ariel {
    std::ostream& operator<<(std::ostream& out, const Money& self) {
        if (self.type=="ILS") {
            out << self.amountInILS << " " << self.type << "\n";
        } else if (self.type=="USD") {
            out << self.amountInILS/usdR << " " << self.type << "\n";
        } else if (self.type=="EUR") {
            out << self.amountInILS/eurR << " " << self.type << "\n";
        }
        return out;
    }
}

void ariel::Money::set_rate(std::string type, float rate) {
    if (type=="ILS") {
        ilsR = rate;
    } else if (type=="USD") {
        usdR = rate;
    } else if (type=="EUR") {
        eurR = rate;
    } else {
        throw std::runtime_error("no such coin");
    }
}

 using namespace std; 
//  #include "Money.hpp" 
 using ariel::Money;
int main() {
    // Set the exchange rates in shekels: 
    Money::set_rate ("ILS", 1);
    Money::set_rate ("USD", 4);
    Money::set_rate ("EUR", 6);
    // Define amounts and do calculations: 
    Money shekell(1, "ILS"); 
    Money dollar3 (3, "USD");
    Money sum = shekell + dollar3; 
    cout << sum << endl;// 13 ILS 
    cout << (dollar3 + Money (1, "EUR")) << endl; // 4.5 USD
    (sum += Money (2, "EUR")) += Money (0.5, "ILS"); 
    cout << sum << endl; // 25.5 ILS 
    // Money (1, "XXX"); // throws an exception
}