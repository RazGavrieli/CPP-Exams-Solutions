/**
 * @file Q2.cpp
 * @author Raz Gavrieli
 * @brief 
 *
 * a. Logical error. The problem is that game() function gets Pointer to player. So the arguments sent at line 34 are converted to Player.
 * b. Holding a vtable (which is a table of function pointers) will solve the problem. Add the 'virtual' keyword at line 07. 
 *    This will add a vtable to all Player instances that will take care of recognizing the correct type of the object and calling the right function.
 * c. Smart Move
 *    Simple Move
 *    x5 times
 */

#include <iostream>
#include <string>
using namespace std;
class Player { 
    public:
    virtual void play() {
        cout << "Error: Player.play is not defined" << endl;
     }
};
class SmartPlayer: public Player {
     public:
      void play() {
        cout << "Smart Move" << endl;
    }
};
class SimplePlayer: public Player {
     public: 
     void play() {
        cout << "Simple Move" << endl;
     }
};
void game (Player* player1, Player* player2, int turns) {
     for (int i=0; i<turns; ++i) {
         player1->play();
     player2->play();
     }
}
int main() { // a demo program
game (new SmartPlayer(), new SimplePlayer(), 5);
}

