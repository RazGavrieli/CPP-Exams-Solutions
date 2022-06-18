/**
 * @file Q3.cpp
 * @author Raz Gavrieli
 * @brief 
 * The change happens using an assignment operator on char& that is referencing a char within the class Board. 
 * To check the assignments made outside the class, we will have to return a 'proxy class' (design pattern). This class will contain a char& as our char and will overload the assignment operator to check assignments. 
 *  
 */

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

class char_reference {
    char& curr;

    public:
    char_reference(char& v) : curr(v) {}
    char_reference operator=(const char newchar) {
        if (newchar=='.'||newchar=='X') {
            curr = newchar;
            return *this;
        } else {
            throw string("illegal char");
        }
        
    }
    friend ostream& operator<<(ostream& out, const char_reference& self) {
        out << self.curr;
        return out;
    }
    // operator char(){ 
    //     return curr;
    // }
};

class Board {
    vector<vector<char>> board;

    public:
    Board() : board(3, vector<char>(3, '.')) {}

    char operator[](pair<int,int> rowcol) const {
        return board[rowcol.first][rowcol.second];
    }

    char_reference operator[](pair<int,int> rowcol) {
        return board[rowcol.first][rowcol.second];
    }

};

int main() {
Board b; 
cout << b[{1,1}] << endl; // should print "." 
b[{1,1}] = 'X'; 
cout << b[{1,1}] << endl; // should print "X" 
try {
b[{1,1}] = 'R'; // should throw an exception 
} catch (string message) {
cout << message << endl; // should print "illegal char"
}
cout << b[{1,1}] << endl; // should print "X"
}