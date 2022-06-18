/**
 * @file Q1.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. Compilation Error. The Frog(string name) constructor is private. b. We need to add 'public:' at Line 19. 
 */

#include <iostream>
using namespace std;
class WaterCreature {
string name; 
public:
    WaterCreature(string name): name (name) {} 
    string getName() { return name; } 
    void swim() { cout << "I swim! "; }
};

class EarthCreature {
string name; 
public:
    EarthCreature(string name): name (name) {} 
    string getName() { return name; } 
    void run() { cout << "I run! "; }
};

class Frog: public WaterCreature, public EarthCreature {
    public: // << fix
    Frog(string name) : WaterCreature(name), EarthCreature(name) {}
};
int main() {
    Frog f("froggy");
    return 0;
}