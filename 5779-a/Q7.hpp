
/**
 * @brief hpp file as requested in the exam.
 * 
 */
#include <iostream>
namespace ariel {
            static float ilsR;
            static float eurR;
            static float usdR;
        class Money {

            float amountInILS; 
            std::string type; 

            public:

            static void set_rate(std::string type, float rate);
            Money(float amount, std::string type);
            Money operator+(const Money& other); 
            friend std::ostream& operator<<(std::ostream& out, const Money& self);
            Money operator+=(const Money& other);
        };
}